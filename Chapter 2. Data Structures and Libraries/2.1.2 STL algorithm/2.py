n = int(input())
for i in range(n):
    if i != 0:
        print()
    tournament_name = input()
    x = int(input())
    d = dict()
    for j in range(x):
        name = input()
        d[name] = dict()
        d[name]["name"] = name.lower()
        d[name]["n_games"] = 0
        d[name]["n_wins"] = 0
        d[name]["n_ties"] = 0
        d[name]["n_losses"] = 0
        d[name]["n_gols_scored"] = 0
        d[name]["n_gols_against"] = 0
        d[name]["n_gols_diff"] = 0
        d[name]["n_points"] = 0
    y = int(input())
    for j in range(y): 
        line = input().split('#')
        a, b = [ int(x) for x in line[1].split('@') ]

        d[line[0]]["n_games"] += 1
        d[line[2]]["n_games"] += 1

        d[line[0]]["n_gols_scored"] -= a
        d[line[2]]["n_gols_scored"] -= b

        d[line[0]]["n_gols_against"] -= b
        d[line[2]]["n_gols_against"] -= a

        d[line[0]]["n_gols_diff"] -= a-b
        d[line[2]]["n_gols_diff"] -= b-a

        if a == b:
            d[line[0]]["n_ties"] -= 1
            d[line[2]]["n_ties"] -= 1

            d[line[0]]["n_points"] -= 1
            d[line[2]]["n_points"] -= 1
        elif a > b:
            d[line[0]]["n_wins"] -= 1
            d[line[2]]["n_losses"] -= 1

            d[line[0]]["n_points"] -= 3
        else:
            d[line[2]]["n_wins"] -= 1
            d[line[0]]["n_losses"] -= 1

            d[line[2]]["n_points"] -= 3
    print(tournament_name)
    order = sorted(d.items(), key=lambda item: (item[1]['n_points'], item[1]['n_wins'], item[1]['n_gols_diff'], item[1]['n_gols_scored'], item[1]['n_games'], item[1]["name"]))
    for i, item in enumerate(order):
        print("{}) {} {}p, {}g ({}-{}-{}), {}gd ({}-{})".format(
            i+1,
            item[0],
            item[1]["n_points"] * (-1),
            item[1]["n_games"],
            item[1]["n_wins"] * (-1),
            item[1]["n_ties"] * (-1),
            item[1]["n_losses"] * (-1),
            item[1]["n_gols_diff"] * (-1),
            item[1]["n_gols_scored"] * (-1),
            item[1]["n_gols_against"] * (-1),
        ))