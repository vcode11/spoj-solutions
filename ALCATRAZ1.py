t = int(input())
for tc in range(t):
	s = input()
	t = len(s)
	val = 0
	for i in range(t):
		val+=int(s[i])
	print(val)
