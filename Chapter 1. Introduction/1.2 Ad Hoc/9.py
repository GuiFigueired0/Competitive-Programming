from math import factorial

f = [ factorial(i) for i in range(1,20) ]

def n_th_permutation(s, n):
    ans = ''
    size = len(s)-2
    for i in range(size,-1,-1):
        pos = int(n//f[i])
        ans += s[pos] 
        del(s[pos])
        n %= f[i]
    return ans + s[0]

x = int(input())
for i in range(x):
    s = input()
    n = int(input())
    print(n_th_permutation(sorted(s), n))