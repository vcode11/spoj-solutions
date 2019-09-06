t = 0
while True:
    s = input()
    left, right, operations = 0,0,0
    if '-' in s:
        break
    for brace in s:
        if brace == '{':
            left+=1
        elif brace == '}':
            right+=1
        if right > left:
            operations+=1
            left+=1
            right-=1
    t+=1
    print(t,'.',' ',operations + (left-right)//2,sep ='')
