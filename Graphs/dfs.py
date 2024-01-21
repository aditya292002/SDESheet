from header import *


def dfs(graph, some_func):
    N = len(graph)
    # perform some op
    vis = [0]*(N + 1)
    def solve(node):
        some_func(node)
        vis[node] = 1
        for child in graph[node]:
            if not vis[child]:
                solve(child)
    for node in range(1, N + 1):
        if not vis[node]:
            solve(node)
    


UD_graph = sample_UD_no_wt
dfs(UD_graph, lambda x: print(x))