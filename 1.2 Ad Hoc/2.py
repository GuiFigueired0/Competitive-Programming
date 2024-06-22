from sys import stdin

cont = 0
for line in stdin:
    for c in line:
        if c == '"':
            if cont%2==0:
                print("``", end='')
            else:
                print("''", end='')
            cont += 1
        else:
            print(c, end='')