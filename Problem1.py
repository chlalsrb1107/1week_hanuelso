n, m = map(int, input().split())

ice = []
for i in range(n):
    ice.append(list(map(int, input())))

def check(x, y):
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False

    if ice[x][y] == 0:
        ice[x][y] = 1
        
        check(x - 1, y) 
        check(x + 1, y) 
        check(x, y - 1) 
        check(x, y + 1) 
        return True
    
    return False

result = 0
for i in range(n):
    for j in range(m):
        if check(i, j) == True:
            result += 1

print(result)
