from icecream import ic
import DSU

# kruskal algo 
#  without DSU 
# Time : E log E (for sorting) + E.N for getting mst and updating parent 
def kurskal_algo(N, edges):    
    edges_ = []
    for u,v,w in edges:
        edges_.append((w,u,v))
    edges_.sort()

    parent = [i for i in range(N+1)]
    mst = []
    cost = 0
    for w,u,v in edges_:
        if(parent[u] != parent[v]):
            cost += w
            mst.append((u,v,w))

            old_p = parent[v]
            new_p = parent[u]
            for i in range(N+1):
                if(parent[i] == old_p):
                    parent[i] = new_p

    ic(cost)
    ic(mst)
    return (cost, mst)


# using DSU 
# TC - (ElogE + E*(4alpha)) = ElogE + E = ElogE
def kruskal(N, edges):
    edges_ = []
    for u,v,w in edges:
        edges_.append((w,u,v))
    edges_.sort()

    parent = [i for i in range(N+1)]
    mst = []
    cost = 0

    d = DSU.DisjointSet(N)
    for w,u,v in edges_:
        if(d.findPar(u) != d.findPar(v)):
            cost += w
            mst.append((u,v,w))
            d.union_by_size(u,v)
    ic(cost)
    ic(mst)
    return (cost, mst)


edges = [(0, 1, 2), (0, 2, 1), (1, 2, 1), (2, 3, 2), (3, 4, 1), (4, 2, 2)]
kruskal(5, edges)