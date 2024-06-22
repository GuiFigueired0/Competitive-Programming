n = int(input())
for i in range(n):
    a, b = [ int(x) for x in input().split() ]
    x = (a+b)//2
    y = a-x
    if y < 0 or x-y != b: 
        print('impossible')
    else:
        print(x, y)