import torch
import torch.nn as nn
import torch.nn.functional as F
from typing import List


class char_tokenizer:
    """
    a very simple char-based tokenizer. the tokenizer turns a string into a list of integers.
    """

    def __init__(self, corpus: List[str]):
        self.corpus = corpus
        # TODO: calculate the vocab size and create a dictionary that maps each character to a unique integer
        self.vocab_size = len(corpus)
        self.char2int = {char: i for i, char in enumerate(corpus)}

    def encode(self, string: str):
        # TODO: convert a string into a list of integers and return, using the dictionary you created above
        return [self.char2int[char] for char in string]

    def decode(self, codes: List[int]):
        # TODO: convert a list of integers into a string and return, using the dictionary you created above
        return ''.join([self.corpus[code] for code in codes])


class Head(nn.Module):
    """single head of self-attention"""

    def __init__(self, head_size):
        super().__init__()
        # TODO: create three linear layers, Key, Query, and Value, each of which maps from n_embd to head_size
        self.Key = nn.Linear(head_size, head_size)
        self.Query = nn.Linear(head_size, head_size)
        self.Value = nn.Linear(head_size, head_size)

        self.register_buffer("tril", torch.tril(
            torch.ones(block_size, block_size)))

    def forward(self, inputs):
        # TODO: implement the forward function of the head
        # the input is a tensor of shape (batch, time, n_embd)
        # the output should be a tensor of shape (batch, time, head_size)
        # you may use the tril buffer defined above to mask out the upper triangular part of the affinity matrix

        batch_size, time, n_embd = inputs.size()

        # Compute keys, queries, and values
        keys = self.Key(inputs)
        queries = self.Query(inputs)
        values = self.Value(inputs)

        # Compute attention scores
        scores = torch.matmul(queries, keys.transpose(1, 2))
        scores = scores.masked_fill(
            self.tril[:time, :time] == 0, float('-inf'))

        # Normalize attention scores
        attention_weights = F.softmax(scores, dim=-1)

        # Apply attention weights to values
        out = torch.matmul(attention_weights, values)

        return out


class MultiHeadAttention(nn.Module):
    def __init__(self, n_heads, head_size):
        super().__init__()
        # TODO: implement heads and projection
        self.heads = nn.ModuleList([Head(head_size) for _ in range(n_heads)])
        self.projection = nn.Linear(n_heads * head_size, head_size)

    def forward(self, inputs):
        # TODO: implement the forward function of the multi-head attention
        head_outputs = [head(inputs) for head in self.heads]
        out = torch.cat(head_outputs, dim=-1)
        return self.projection(out)


class FeedForward(nn.Module):
    def __init__(self, n_embd):
        super().__init__()
        # TODO: implement the feed-forward network
        self.net = nn.Sequential(
            nn.Linear(n_embd, 4 * n_embd),
            nn.ReLU(),
            nn.Linear(4 * n_embd, n_embd)
        )

    def forward(self, inputs):
        return self.net(inputs)


class Block(nn.Module):
    def __init__(self, n_embd, n_heads):
        super().__init__()
        # TODO: implement the block of transformer using the MultiHeadAttention and FeedForward modules,
        # along with the layer normalization layers
        self.attention = MultiHeadAttention(n_heads, n_embd)
        self.norm1 = nn.LayerNorm(n_embd)
        self.ffn = FeedForward(n_embd)
        self.norm2 = nn.LayerNorm(n_embd)

    def forward(self, inputs):
        # TODO: implement the forward function of the block, you may refer to the docs of this experiment
        attention_output = self.attention(inputs)
        attention_output = self.norm1(inputs + attention_output)

        ffn_output = self.ffn(attention_output)
        out = self.norm2(attention_output + ffn_output)
        return out


class Transformer(nn.Module):
    def __init__(self):
        super().__init__()
        # TODO: create the embedding table, the stack of blocks, the layer normalization layer,
        # and the linear layers.
        self.embedding = nn.Embedding(tokenizer.vocab_size, n_embd)
        self.blocks = nn.ModuleList(
            [Block(n_embd, n_heads) for _ in range(n_layers)])
        self.norm = nn.LayerNorm(n_embd)
        self.linear = nn.Linear(n_embd, tokenizer.vocab_size)

    def forward(self, inputs, labels=None):
        # TODO: implement the forward function of the transformer

        # inputs:(batch, context)
        batch, context = inputs.shape

        # embedding:(batch, context, embedding)
        embedding_output = self.embedding(inputs)

        # attens:(batch, context, embedding)
        attens = embedding_output

        for block in self.blocks:
            attens = block(attens)

        # logits:(batch, context, attens)
        logits = self.linear(self.norm(attens))

        # compute the loss
        if labels is None:
            loss = None
        else:
            loss = F.cross_entropy(
                logits.view(-1, tokenizer.vocab_size), labels.view(-1))
        return logits, loss

    def generate(self, inputs, max_new_tokens):
        # TODO: generate new tokens from the transformer, using the inputs as the context,
        # and return the generated tokens with length of max_new_tokens

        for _ in range(max_new_tokens):
            output, _ = self(inputs[:, -block_size + 1:])
            predicted_token = output.argmax(dim=-1)[:, -1]
            inputs = torch.cat([inputs, predicted_token[:, None]], dim=-1)
        return inputs


def get_batch(split):
    data = train_data if split == "train" else val_data
    ix = torch.randint(len(data) - block_size, (batch_size,))
    x = torch.stack([data[i: i + block_size] for i in ix])
    y = torch.stack([data[i + 1: i + block_size + 1] for i in ix])
    x, y = x.to(device), y.to(device)
    return x, y


@torch.no_grad()
def estimate_loss(model):
    out = {}
    model.eval()
    for split in ["train", "val"]:
        losses = torch.zeros(eval_iters)
        for k in range(eval_iters):
            x, y = get_batch(split)
            logits, loss = model(x, y)
            losses[k] = loss.item()
        out[split] = losses.mean()
    return out


def generate(model):
    start_text = "To be, or not to be: that is the"
    start_tokens = tokenizer.encode(start_text)
    context = torch.tensor([start_tokens], device=device, dtype=torch.long)
    # context = torch.zeros((1, 1), device=device, dtype=torch.long)
    print(decode(model.generate(context, max_new_tokens=500)[0].tolist()))


def train(model):
    optimizer = torch.optim.AdamW(model.parameters(), lr=learning_rate)

    for iter in range(max_iters):

        if iter % eval_interval == 0:
            losses = estimate_loss(model)
            print(
                f"step {iter}: train loss {losses['train']:.4f}, val loss {losses['val']:.4f}"
            )

        inputs, labels = get_batch("train")

        logits, loss = model(inputs, labels)
        optimizer.zero_grad(set_to_none=True)
        loss.backward()
        optimizer.step()


# define the hyperparameters
batch_size = 16
block_size = 256
max_iters = 100  # set the number of training iterations as you like
eval_interval = 50
learning_rate = 1e-3
device = "cuda" if torch.cuda.is_available() else "cpu"
eval_iters = 200
n_embd = 64
n_heads = 8
n_layers = 6

# read the dataset
with open("C:\\Users\\voyage\\Desktop\\lab2\\part_2\\data\\input.txt", "r", encoding="utf-8") as f:
    text = f.read()
chars = sorted(list(set(text)))

# initialize the vocabulary
tokenizer = char_tokenizer(chars)
encode = tokenizer.encode
decode = tokenizer.decode
n_vocab = tokenizer.vocab_size

# separate the dataset into train and validation
train_data = torch.tensor(encode(text[: -len(text) // 10]), dtype=torch.long)
val_data = torch.tensor(encode(text[-len(text) // 10:]), dtype=torch.long)

# define the model
model = Transformer().to(device)
train(model)
generate(model)
