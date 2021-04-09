n, s = map(int, input().split())
number = list(map(int, input().split()))
visited = [False] *n
stack = [] 
ans = 0
def dfs(num):
    if(len(stack) != 0):
        sum = 0
        for iter in stack:
            sum += iter
        if(sum == s):
            global ans
            ans += 1

    if(len(stack) !=n ):
        for i in range(num+1, n):
            if visited[i] is False:
                visited[i] = True
                stack.append(number[i])
                dfs(i)
                stack.pop()
                visited[i] = False
    else:
        return

dfs(-1)
print(ans)