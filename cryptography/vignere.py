# Vignere cipher

import string, math

a = list(string.ascii_lowercase)
ref = []

for i in range(26):
	temp = []
	for j in range(26):
		temp.append(a[(j+i)%26])
	ref.append(temp)

p = raw_input("Plaintext:  ")
p = p.replace(" ","")
p = p.lower()
key = raw_input("KEY: ")
key = key.lower()

c = ""
key2 = ""

for i in range(len(p)):
	key2 += key[i%len(key)]

for i in range(len(p)):
	y = a.index(p[i])
	x = a.index(key2[i])
	c += ref[y][x]

print "Ciphertext: " + c

# decryption
p = ""

for i in range(len(c)):
	pos = ref[ a.index(key2[i]) ].index( c[i] )
	p += a[pos]

print "Plaintext Recovery: " + p