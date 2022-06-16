import re

f = open('1.txt', 'r', encoding='utf-8')
string = f.read()
f.close()

string = re.sub(r' ', lambda x: '&nbsp;', string)
string = re.sub(r'\n', lambda x: '\n\n', string)

print(string)
