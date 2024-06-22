n = int(input())
for i in range(n):
    name = input()
    a, b, c = [ int(x) for x in input().split() ]
    ingredients = dict()
    for j in range(a):
        ingredient, cost = [ x for x in input().split() ]
        ingredients[ingredient] = int(cost)
    recipes = []
    for j in range(b):
        total = 0
        recipe = input()
        m = int(input())
        for k in range(m):
            ingredient, size = [ x for x in input().split() ]
            total += ingredients[ingredient]*int(size)
        if total <= c:
            recipes.append((total, recipe))
    recipes.sort()
    print(name.upper())
    if len(recipes) == 0:
        print('Too expensive!')
    else:
        for recipe in recipes:
            print(recipe[1])
    print()