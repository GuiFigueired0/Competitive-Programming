from sys import stdin

distance = 0.0
velocity = 0
timestamp = 0
for line in stdin:
    line = line.split()
    h = int(line[0][:2])
    m = int(line[0][3:5])
    s = int(line[0][6:])
    time = s+(m*60)+(h*3600)
    distance += (time - timestamp)*velocity
    timestamp = time
    if len(line) == 2:
        velocity = int(line[1])/3.6
    else:
        print('{} {:.2f} km'.format(line[0], distance/1000))
