from collections import deque
from header import *


def dfs(graph, some_func):
    N = len(graph)
    # perform some op
    vis = [0] * (N + 1)

    def solve(node):
        q = deque()
        q.append(node)
        vis[node] = 1
        while len(q) > 0:
            cur_node = q.popleft()
            some_func(cur_node)
            for nbr in graph[cur_node]:
                if not vis[nbr]:
                    vis[nbr] = 1
                    q.append(nbr)

    for node in range(1, N + 1):
        if not vis[node]:
            solve(node) 


UD_graph = sample_UD_no_wt
print(UD_graph)
dfs(UD_graph, lambda x: print(x))
