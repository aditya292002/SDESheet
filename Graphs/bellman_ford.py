from typing import List
from collections import deque, defaultdict
from icecream import ic



# bellman ford
def bellman_ford(src, N, edges):
    INF = 1e9
    dist = [INF]*N
    dist[src] = 0

    for _ in range(N - 1):
        change = False
        for u,v,c in edges:
            if(dist[u] != INF and dist[v] > dist[u] + c):
                change = True
                dist[v] = dist[u] + c
        if not change:
            break
    
    change = False
    for u,v,c in edges:
        if(dist[u] != INF and dist[v] > dist[u] + c):
            dist[v] = dist[u] + c
            change = True
            break

    if(change):
        print("Graph contains negative edge cycle")
    
    ic(dist)


# Retrieving path
def bellman_ford_path(src, N, edges):
    INF = 1e9
    dist = [INF]*N
    parent = [None]*N
    dist[src] = 0

    parent[src] = -1

    for _ in range(N - 1):
        change = False
        for u,v,c in edges:
            if(dist[u] != INF and dist[v] > dist[u] + c):
                change = True
                dist[v] = dist[u] + c
                parent[v] = u
        if not change:
            break
    
    change = False
    for u,v,c in edges:
        if(dist[u] != INF and dist[v] > dist[u] + c):
            dist[v] = dist[u] + c
            change = True
            break

    if(change):
        print("Graph contains negative edge cycle")
    
    ic(dist)
    ic(parent)
    return parent



# Get path from src --> dest using retrieve path 
def getPath(src, dest, N, edges):
    parent_arr = bellman_ford_path(src, N, edges)
    parent = parent_arr[dest]
    while(parent != -1):
        print(parent)
        parent = parent_arr[parent]



# Shortest Path Faster Algorithm (SPFA)
INF = 1e9
def spfa(src, N, edges):
    graph = defaultdict(list)
    for e in edges:
        graph[e[0]].append((e[1], e[2]))
        graph[e[1]].append((e[0], e[2]))
    
    cnt = [0]*N
    inqueue = [False]*N
    q = deque()
    q.append(src)
    inqueue[src] = True
    dist = [INF]*N
    dist[src] = 0

    while len(q) > 0:
        v = q.popleft()
        inqueue[v] = False

        for nbr in graph[v]:
            to = nbr[0] 
            wt = nbr[1]

            if(dist[v] + wt < dist[to]):
                dist[to] = dist[v] + wt 
                if not inqueue[to]:
                    q.append(to)
                    inqueue[to] = .True
                    cnt[to]+=1
                    if(cnt[to] >= N):
                        return False

    ic(dist)
    return True

# edges = [[0, 1, 2], [0, 4, 1], [4, 5, 4], [4, 2, 2], [1, 2, 3], [2, 3, 6], [5, 3, 1]]
edges_ = [[0,1,1], [1,2,3], [0,3,2], [3,2,5], [2,4,2]]
spfa(0, 5, edges_)
# edges_ = [[0,1,1], [1,2,3], [3,0,2], [2,3,-7], [2,4,2]]  # -ve edge cycle
# bellman_ford(0, 5, edges_)