#solution for GO GOA GONE
def money(contri, enemity, sum, mark ,idx):
    if idx == 8:
        return sum
    if (mark[idx] == 0):
        return money(contri,enemity,sum,mark,idx+1)
    import copy
    mark_c = copy.copy(mark)
    for enemies in enemity:
        if enemies[0] == idx:
            mark_c[enemies[1]] = 0
        elif enemies[1] == idx:
            mark_c[enemies[0]] = 0
    return max(money(contri,enemity,sum+contri[idx],mark_c,idx+1),money(contri,enemity,sum,mark,idx+1))

contri = input()
contri = list(map(int,contri.split()))
enemity = []
mark  = [1 for i in range(8)]
e = int(input())
for i in range(e):
    enemies = list(map(int,input().split()))
    enemies[0]-=1
    enemies[1]-=1
    enemity.append(enemies)
print(money(contri,enemity,0,mark,0))