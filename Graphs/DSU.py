from collections import *
from icecream import ic
from heapq import *
from typing import List

# Disjoint set union 
class DisjointSet:
    def __init__(self, N: int):
        self.rank = [0] * (N+1)
        self.size = [1] * (N+1)
        self.parent = [i for i in range(N+1)]
        

    def findPar(self, node):
        if node == self.parent[node]:
            return node
        ultimate_parent = self.findPar(self.parent[node])
        self.parent[node] = ultimate_parent
        return ultimate_parent
    
    def union_by_size(self, u, v):
        ulp_v = self.findPar(v)
        ulp_u = self.findPar(u)
        if ulp_v == ulp_u: 
            return
        
        if(self.size[ulp_u] < self.size[ulp_v]):
            self.parent[ulp_u] = ulp_v
            self.size[ulp_v] += self.size[ulp_u]
        else:
            self.parent[ulp_v] = ulp_u
            self.size[ulp_u] += self.size[ulp_v] 


    def union_by_rank(self, u, v):
        ulp_v = self.findPar(u)
        ulp_u = self.findPar(v)
        if ulp_v == ulp_u: 
            return
        
        if self.rank[ulp_u] < self.rank[ulp_v]:
            self.parent[ulp_u] = ulp_v  
        elif self.rank[ulp_u] > self.rank[ulp_v]:
            self.parent[ulp_v] = ulp_u
        else:
            self.parent[ulp_v] = ulp_u
            self.rank[ulp_u] += 1


# ds = DisjointSs

# ds = DisjointSet(7)
# ds.union_by_rank(1, 2)
# ds.union_by_rank(2, 3)
# ds.union_by_rank(4, 5)
# ds.union_by_rank(6, 7)
# ds.union_by_rank(5, 6)

# # Check if 3 and 7 are in the same component or not 
# if ds.findPar(3) == ds.findPar(7):
#     print("Same")
# else:
#     print("Not same")

# ds.union_by_rank(3, 7)

# if ds.findPar(3) == ds.findPar(7):
#     print("Same")
# else:
#     print("Not same")