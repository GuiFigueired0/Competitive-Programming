import heapq

while True:
    n = int(input())
    graph = [ [] for i in range(n+1) ]
    total = 0
    for i in range(n-1):
        a, b, c = [ int(x) for x in input().split() ]
        total += c 
        c *= -1
        heapq.heappush(graph[a], c) 
        heapq.heappush(graph[b], c)
    print(total)
    k = int(input())
    for i in range(k):
        a, b, c = [ int(x) for x in input().split() ]
        c *= -1
        if graph[a][0] > graph[b][0]:
            a, b = b, a
        if graph[a][0] < c:
            value = heapq.heappop(graph[a])
            heapq.heappush(graph[a], c)
            total -= c - value
    k = int(input())
    for i in range(k):
        _ = input()
    print(total)
    try:
        line = input()
        print()
    except EOFError:
        break
