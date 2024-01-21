from collections import *
from icecream import ic
from heapq import *

# prim algo 
def prim_algo(N, edges):
    graph = defaultdict(list)
    for e in edges:
        graph[e[0]].append((e[1], e[2]))
        graph[e[1]].append((e[0], e[2]))
    
    sum = 0
    mst = []
    vis = [0]*N
    pq = [(0,0,-1)]
    heapify(pq)
    
    while len(pq) > 0:
        node_ = heappop(pq)
        node = node_[1]
        wt = node_[0]
        parent = node_[2]

        if(vis[node]):
            continue
            
        vis[node] = 1
        mst.append((parent, node))

        sum += wt
        for nbr_node in graph[node]:
            nbr = nbr_node[0]
            eWt = nbr_node[1]
            if not vis[nbr]:
                heappush(pq, (eWt, nbr, node))
    print(mst)
    return sum     


edges = [(0, 1, 2), (0, 2, 1), (1, 2, 1), (2, 3, 2), (3, 4, 1), (4, 2, 2)]
print(prim_algo(5, edges))