from sys import stdin

for line in stdin:
    output = [ x[::-1] for x in line.split() ]
    print(*output)