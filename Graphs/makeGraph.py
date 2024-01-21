from header import * 

def count_nodes(graph):
    nodes = []
    for node in graph:
        for nbr in graph[node]:
            nodes.append(nbr)
    return len(set(nodes))

def count_nodes_from_edges(edges):
    nodes = []
    for edge in edges:
        for node in edge:
            nodes.append(node)
    return len(set(nodes))


def make_UD_graph(edges):
    N = count_nodes_from_edges(edges)
    graph = defaultdict(list)
    if len(edges) > 0:
        if len(edges[0]) == 2:
            for e in edges:
                graph[e[0]].append(e[1])
                graph[e[1]].append(e[0])
        elif len(edges[0]) == 3:
            for e in edges:
                graph[e[0]].append((e[1], e[2]))
                graph[e[1]].append((e[0], e[2]))
    
    for i in range(N + 1):
        if(i not in graph):
            graph[i] = []
    
    return graph

def make_D_graph(edges):
    # ic(edges)
    graph = defaultdict(list)
    if len(edges) > 0:
        if len(edges[0]) == 2:
            for e in edges:
                graph[e[0]].append(e[1])
        elif len(edges[0]) == 3:
            for e in edges:
                graph[e[0]].append((e[1], e[2]))
    # ic(graph)

    return graph

# sample edges
sample_edges_wt = [
    (1, 2, 3),
    (2, 3, 4),
    (3, 4, 5),
    (4, 1, 6),
    (1, 5, 2),
    (5, 6, 7),
    (6, 2, 8),
    (3, 7, 9),
    (7, 8, 10),
    (8, 4, 11)
]

sample_edges_no_wt = [
    (1, 2),
    (2, 3),
    (3, 4),
    (4, 1),
    (5, 6),
    (6, 7),
    (7, 8),
    (8, 5),
    (9, 10),
    (10, 11),
    (11, 9)
]

sample_edges_no_cycle = [
    (1, 2),
    (2, 3),
    (3, 4),
    (4, 1),
    (5, 6),
    (6, 7),
    (7, 8),
    (8, 5),
    (9, 10),
    (10, 11)
]

sample_edges_cycle = [
    (1, 2),
    (2, 3),
    (3, 4),
    (4, 1),
    (5, 6),
    (6, 7),
    (7, 8),
    (8, 5),
    (9, 10),
    (10, 11),
    (11, 9),
    (3, 8)
]

# sample UD graph
sample_UD_no_wt = make_UD_graph(sample_edges_no_wt)
sample_UD_wt = make_UD_graph(sample_edges_wt)

# sample D graph
sample_D_no_wt = make_D_graph(sample_edges_no_wt)
sample_D_wt = make_D_graph(sample_edges_wt)
