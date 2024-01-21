from typing import List
from icecream import ic
from collections import deque, defaultdict


# Floyd Warshall
# considering weight is given for each edge 
# now doing it for DG 
# def floyd_warshall(N, edges):
#     ic(edges)
#     INF = 10**10
#     adj_matrix = [[INF]*N for _ in range(N)]
#     for u,v,w in edges:
#         adj_matrix[u][v] = w
#     # dist. of a node from itself = 0
#     for i in range(N):
#         adj_matrix[i][i] = 0

#     ic(adj_matrix)
    
#     for k in range(N):
#         for i in range(N):
#             for j in range(N):
#                 if(adj_matrix[i][j] > adj_matrix[i][k] + adj_matrix[k][j] and  (adj_matrix[i][k] < INF and adj_matrix[k][j] < INF)):
#                     adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j]

#     ic(adj_matrix)
#     return adj_matrix

# edges = [(0,1,2), (1,0,1), (1,2,3), (3,0,3), (3,1,5), (3,2,4)]
# floyd_warshall(4,edges)



# https://leetcode.com/contest/weekly-contest-381/problems/count-the-number-of-houses-at-a-certain-distance-i/
def countOfPairs(N: int, x: int, y: int) -> List[int]:
    INF = 10**10
    
    adj_matrix = [[INF]*(N+1) for _ in range(N+1)]
    
    for node in range(1,N):
        adj_matrix[node][node + 1] = 1
        adj_matrix[node + 1][node] = 1
    adj_matrix[x][y] = 1
    adj_matrix[y][x] = 1

    # dist. of a node from itself = 0
    for i in range(N + 1):
        adj_matrix[i][i] = 0


    ans = [0]*N
    for k in range(1,N+1):
        for i in range(1, N+1):
            for j in range(1,N + 1):
                if(adj_matrix[i][j] > adj_matrix[i][k] + adj_matrix[k][j] and  (adj_matrix[i][k] < INF and adj_matrix[k][j] < INF)):
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j]

    # ic(adj_matrix)
    for i in range(1, N+1):
        for j in range(1,N + 1):
            if(adj_matrix[i][j] != INF and adj_matrix[i][j] != 0):
                ans[adj_matrix[i][j] - 1] += 1
    
    # ic(ans)
    return ans

n = 5
x = 2
y = 4
ic(countOfPairs(n, x, y))