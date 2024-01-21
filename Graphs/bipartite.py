from header import *


class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        
        N = len(graph)
        color = [-1] * N  # -1 no color, 0 red, 1 bluen  # initially use - red(0)

        def solve(node):  
            q = deque()
            q.append(node)
            color[node] = 0  
            while len(q) > 0:
                sz = len(q)
                for _ in range(sz):
                    cur_node = q.popleft()
                    for nbr in graph[cur_node]:
                        if(color[nbr] == -1):
                            color[nbr] = color[cur_node] ^ 1
                            q.append(nbr)
                        elif(color[nbr] == color[cur_node]):
                            return False
            return True
        for node in range(N):
            if color[node] == -1:
                if not solve(node):
                    return False
        return True

