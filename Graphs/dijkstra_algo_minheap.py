from header import *
from typing import DefaultDict
from heapq import *


# Dijkstra algo 
def dijkstra(src, N, graph: DefaultDict[int, list]):
    INF = 10**9
    dist = [INF]*N 
    dist[src] = 0
    minHeap = [(0, src)]
    heapify(minHeap)
    
    
    while len(minHeap) > 0:
        top = heappop(minHeap)
        node = top[1]
        dis = top[0]
        ic(top)

        for nbr_node in graph[node]:
            nbr = nbr_node[0]
            wt = nbr_node[1]
            ic(nbr)
            if dist[nbr] > dis + wt:
                dist[nbr] = dis + wt
                heappush(minHeap, (dist[nbr], nbr))
        
    return dist


edges = [
    (0, 1, 1), (0, 2, 6), (1, 2, 3), (1, 0, 1), (2, 1, 3), (2, 0, 6)
]
graph = make_UD_graph(edges)
ic(dijkstra(2, 3, graph))

