n = int(input())
for k in range(n):
    _ = input()
    index = [ int(x) for x in input().split() ]
    num = [ x for x in input().split() ]
    d = dict()
    for i in range(len(index)):
        d[index[i]] = num[i]
    if k != 0:
        print()
    for i in range(len(index)):
        print(d[i+1])