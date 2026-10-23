from collections import deque

class Solution:
    def lastVisitedCell(self, grid: list[list[str]]) -> list[int]:
        n = len(grid)
        m = len(grid[0])
        if(n==1 and m==1):return [0,0]
        visited = [[False for _ in range(m)] for _ in range(n)]
        moves = {"R":[0,1] , "L":[0,-1], "U":[-1,0], "D":[1,0]}
        
        isRunning = True
        i,j=0,0
        ans = []
        while isRunning:
            val = grid[i][j]
            move = moves[val]
            ni,nj = i+(move[0]) , j+(move[1])
            
            if((ni >= n or ni <0 or nj>=m or nj<0) or visited[ni][nj]):
                isRunning=False
                ans = [i , j]
                break
            
            else:
                visited[i][j]=True
                i = ni
                j = nj
        
        return ans
    
    def checkIfValidRoot(self , graph:list[list[bool]] , colors:str , node:int)->bool:
        q = deque()
        for _ in graph[node]:
            q.append(_)
        col = colors[node]
        colArr = []
        colArr.append(col)
        while q:
            node = q.popleft()
            n = len(q)
            
            next = [] # stores current elements so that we can use later to get their childrens
            for __ in range(n):
                _ = q.popleft()
                color = colors[_]
                if(len(colArr)==0):
                    colArr.append(color)
                elif(len(colArr)==1):
                    if(colArr[0]== color):
                        return False
                    colArr.append(color)
                elif(len(colArr)==2):
                    if(colArr[0]== color or colArr[1] == color):
                        return False
                    colArr.append(color)
                else:
                    if(colArr[len(colArr) - 3] != color):
                        return False
                    colArr.append(color)
                next.append(_)
            
        return True
    
    def findColoredRoot(self, edges: list[list[int]], colors: str) -> int:
        n = len(edges)+1
        graph = [[False for _ in range(n)] for _ in range(n)]
        for edge in edges:
            i,j = edge[0] , edge[1]
            graph[i][j] = True
            graph[j][i] = True
        
        for _ in range(n):
            if(self.checkIfValidRoot(graph , colors , _)):
                return _
        
        return -1
            
    