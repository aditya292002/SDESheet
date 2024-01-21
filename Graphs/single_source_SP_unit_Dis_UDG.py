from typing import List
from collections import deque, defaultdict


# UD Graph with unit weight
def shortestPath(n:int, edges: List[List[int]], src:int ) -> List[int]:
    # Write your code here
    graph = defaultdict(list)
    for e in edges:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])
    
    q = deque()
    q.append(src)
    dist = [1e9]*n
    dist[src] = 0

    while len(q) > 0:
        node = q.popleft()
        for nbr in graph[node]:
            if(dist[nbr] == 1e9):
                dist[nbr] = 1 + dist[node]
                q.append(nbr)
    for i in range(n):
        if(dist[i] == 1e9):
            dist[i] = -1
    return dist