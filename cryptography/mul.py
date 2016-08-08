# Multiplcative cipher 

import string
import math

a = string.ascii_lowercase
a = list(a)

p = raw_input("Mutiplicative cipher: \nEnter plaintext: ")
p = p.replace(" ","")
key = int(raw_input("Key: "))
c = ""

for i in p:
	pos = ( a.index(i) * key ) % 26
	c += a[pos]
	# print i + " " + str(pos)  + " " + a[pos]

print "Cipher text:  " + c

p = ""

key_inverse = 0

r1 = 26
r2 = key
r = q = t = 0
t1 = 0
t2 = 1
q = 0

while True:
	q = int(math.floor(r1/r2))
	r = (r1%r2)
	t = t1 - (q * t2)

	r1,r2 = r2,r
	t1,t2 = t2,t

	if (r1 == 1):
		if t1 > 0:
			t1 = t1 % 26
		elif t1 < 0 and math.fabs(t1) < 26:
			t1 = t1 + 26
		else:
			print "Unexpeected condition"
		break

	pass



for i in c:
	pos = ( a.index(i) * t1) % 26
	p += a[pos]
	# print i + " " + str(pos)  + " " + a[pos]

print "Reverse plaintext:  " + p