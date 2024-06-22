from sys import stdin

notes = ['C', 'C#', 'D', 'D#','E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
scale = [2, 2, 1, 2, 2, 2, 1]

majorScales = dict()
for note in notes:
    sequence = [note]
    pos = 0
    for i, n in enumerate(notes):
        if n == note:
            pos = i
            break
    for i in scale:
        pos = (pos+i)%len(notes)
        sequence.append(notes[pos])
    majorScales[note] = sequence

for line in stdin:
    line = line.split()
    if line[0] == 'END':
        break
    s = set(line)
    possible_keys = []
    for note in notes:
        test = True
        for x in s:
            if x not in majorScales[note]:
                test = False
                break
        if test:
            possible_keys.append(note)
    print(*possible_keys)