while True:
	s = input()
	s = s.split()
	if s[0] == '0' and s[1] == '0':
		break
	l = list(map(int,s))
	if l[1] + l[1] == l[0] + l[2]:
		d = l[1] - l[0]
		if d == 0:
			print('GP',l[0])
		print('AP',l[2]+d)
	else:
		if l[0] == 0:
			d = l[2]/l[1]
		else:
			d = l[1]/l[0]
		nex = l[2]*d
		if nex == int(nex):
			print('GP',int(nex))
		else:
			print('GP',nex)
