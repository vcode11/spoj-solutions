n = int(input())
while n != -1:
	l = []
	s = 0
	for i in range(n):
		x = int(input())
		l.append(x)
		s+=x
	val = s/n
	if val != int(val):
		print(-1)
	else:
		val = int(val)
		s = 0
		for i in range(n):
			s+=abs(l[i]-val)
		print(s//2)
	n = int(input())
