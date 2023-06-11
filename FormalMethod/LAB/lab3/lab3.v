Lemma ex1: forall A,~~~ A -> ~ A.
Proof.
    intros ???.
    apply H.
    intros ?.
    apply H1, H0.
Qed.

Lemma ex2: forall A B, A \/ B -> ~(~A /\ ~B).
Proof.
    intros. 
    intros (?&?). 
    destruct H.
    apply H0, H.
    apply H1, H.
Qed.

Lemma ex3: forall T (P:T -> Prop),
(~ exists x, P x) -> forall x, ~ P x.
Proof.
    intros ?????.
    apply H.
    exists x.
    apply H0.
Qed.