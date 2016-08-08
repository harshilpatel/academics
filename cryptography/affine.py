# Multiplcative cipher 

import string
import math

a = string.ascii_lowercase
a = list(a)

p = raw_input("Mutiplicative cipher: \nEnter plaintext: ")
p = p.replace(" ","")
key = int(raw_input("Key 1: "))
key2 = int(raw_input("Key 2 : "))
c = ""

# MUL
for i in p:
	pos = ( a.index(i) * key ) % 26
	c += a[pos]
	# print i + " " + str(pos)  + " " + a[pos]

print "Cipher text [MUL]:  " + c

# ADD
c2 = ""
for i in c:
	pos = ( a.index(i) + key2 ) % 26
	c2 += a[pos]
	# print i + " " + str(pos)  + " " + a[pos]

print "Cipher text [MUL]:  " + c2

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
			print "Unexpected condition"
		break

	pass

# SUB
p1 = ""
for i in c2:
	pos = ( a.index(i) - key2 ) % 26
	p1 += a[pos]
	# print i + " " + str(pos)  + " " + a[pos]

print "Plain text [SUB]:  " + p1

#MUL INVERSe
p2 = ""
for i in p1:
	pos = ( a.index(i) * t1 ) % 26
	p2 += a[pos]
	# print i + " " + str(pos)  + " " + a[pos]

print "Plain text [MUL INVERSE]:  " + p2