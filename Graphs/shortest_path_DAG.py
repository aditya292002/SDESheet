from typing import List
from collections import deque, defaultdict
from icecream import ic

def shortestPathInDAG(n: int, m: int, edges: List[List[int]]) -> List[int]:
    graph = defaultdict(list)
    for e in edges:
        graph[e[0]].append((e[1], e[2]))
        graph[e[1]].append((e[0], e[2]))
    
    def topoSort():
        inDegree = [0]*n
        q = deque()
        for e in edges:
            inDegree[e[1]]+=1

        for node in range(n):
            if(inDegree[node] == 0):
                q.append(node)

        topo = deque()   
        while len(q) > 0:
            node = q.popleft()
            topo.append(node)
            for nbr_node in graph[node]:
                nbr = nbr_node[0]
                inDegree[nbr] -= 1
                if(inDegree[nbr] == 0):
                    q.append(nbr)

        return topo  
    
    
    topo = topoSort()
    dist = [1e9]*n
    dist[0] = 0
    ic(topo)
    while len(topo) > 0:
        node = topo.popleft()
        for nbr in graph[node]:
            v = nbr[0]
            wt = nbr[1]
            
            if(dist[v] > dist[node] + wt):
                dist[v] = wt + dist[node]

    return dist

edges = [[0, 1, 2], [0, 4, 1], [4, 5, 4], [4, 2, 2], [1, 2, 3], [2, 3, 6], [5, 3, 1]]
shortestPathInDAG(6,7,edges)