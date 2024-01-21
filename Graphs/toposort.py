from header import *

# Note: Topological sort is only possible in DAGs

def topoSort_dfs(edges):
    graph = make_D_graph(edges)
    N = count_nodes_from_edges(edges)
    vis = [0] * (N + 1)

    toposort = []
    def solve(node):
        vis[node] = 1
        for nbr in graph[node]:
            if not vis[nbr]:
                solve(nbr)
        toposort.append(node)

    for node in range(1, N + 1):
        if not vis[node]:
            solve(node)
    
    return toposort

def topoSort_bfs(edges):
    graph = make_D_graph(edges)
    N = count_nodes_from_edges(edges)

    indegree = [0] * (N + 1)
    for e in edges:
        indegree[e[1]] += 1
    q = deque()
    for node in range(1, N + 1):
        if(indegree[node] == 0):
            q.append(node)

    toposort = []
    while len(q) > 0:
        cur_node = q.popleft()
        toposort.append(cur_node)
        for nbr in graph[cur_node]:
            indegree[nbr] -= 1
            if indegree[nbr] == 0:
                q.append(nbr)
    toposort.reverse()
    return toposort



DAG_edges = [
    # (1,2), (2,3), (3,4), (1,5)

    (5, 4),
    (0, 2),
    (1, 2),
    (3, 1),
    (0, 4)

]

print(topoSort_bfs(DAG_edges))
# print(topoSort_dfs(DAG_edges))


