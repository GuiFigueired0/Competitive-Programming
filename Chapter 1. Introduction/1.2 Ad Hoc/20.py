from math import ceil

n = int(input())
for i in range(n):
    a, b = [ int(x)-2 for x in input().split() ]
    print(ceil(a/3)*ceil(b/3))