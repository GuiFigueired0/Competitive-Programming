from sys import stdin 

for line in stdin:
    h = int(line[:2])
    m = int(line[2:4])
    s = int(line[4:6])
    c = int(line[6:])
    m += 60*h
    s += m*60
    c += s*100
    conversao = int(c*10000000/8640000)
    lista = []
    for i in range(4):
        x = conversao%100
        conversao -= x
        conversao //= 100
        lista.append(x)
    lista.reverse()
    output = [ str(x).zfill(2) for x in lista ]
    output[0] = output[0][1]
    print(*output, sep='')