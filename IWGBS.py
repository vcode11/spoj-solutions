n = int(input())
a = 2
b = 3
f = 1
if n == 1:
	print(a)
	f = 0
if n == 2:
	print(b)
	f = 0
for i in range(n-2):
	t = b
	b+=a
	a = t
if f == 1:
	print(b)
