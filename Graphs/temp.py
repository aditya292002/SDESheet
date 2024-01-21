from typing import List
from collections import deque, defaultdict
from icecream import ic

def countOfPairs(n: int, x: int, y: int) -> List[int]:
    graph = defaultdict(list)
    for node in range(1, n):
        graph[node].append(node+1)
        graph[node + 1].append(node)
    graph[x].append(y)
    graph[y].append(x)

    def bfs(node, k):
        ic("bfs")
        ic(node,k)
        q = deque()
        q.append(node)
        dis = 0
        ans = []
        while(len(q) > 0):
            sz = len(q)
            if(dis == k):
                for i in range(sz):
                    cur_node = q.popleft()
                    ans.append(cur_node)
            else:
                for i in range(sz):
                    cur_node = q.popleft()
                    for nbr in graph[cur_node]:
                        q.append(nbr)
            dis += 1
        return ans
    
    distinct = set()
    ans = []
    for k in range(1, n + 1):
        cnt = 0
        for node in range(1, n + 1):
            bfs_ans = bfs(node, k)
            for i in bfs_ans:
                if(i != node):
                    if((node,i) not in distinct):
                        cnt += 1
                        distinct.add((node, i))
        ans.append(cnt)

    return ans
    
n = 50
x = 1
y = 2
ic(countOfPairs(n,x,y))
