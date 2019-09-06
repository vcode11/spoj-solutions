t = int(input())
for i in range(t):
	s = input()
	a, b = s.split()
	a = a[::-1]
	b = b[::-1]
	c = str(int(a) + int(b))
	c = c[::-1]
	c = int(c)
	print(c)
