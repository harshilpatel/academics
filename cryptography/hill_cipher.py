import string
a = list(string.ascii_lowercase)
p = raw_input("Plaintext: ")
p = p.replace(" ","")
x = input("Input key matrix rows:  ")
x = int(x)

key = []

for i in range(x):
	temp = [int(i) for i in raw_input("Row(" + str(i) +")").split()]
	key.append(temp)


if ( len(p)%x > 0):
	p += "X"*(len(p)%x)

p_split = []

j = 0
for i in range(x,len(p)+x,x):
	p_split.append( p[j:i] )
	j = i

result = ""

for i in range(len(p_split)):
	temp = [a.index(j) for j in  list(p_split[i]) ]
	result_temp = []
	
	for j in range(x):
		item = 0
		for k in range(len(key[j])):
			item += key[j][k] * temp[k]
		result += a[item%26]
		print p_split[i] + " " + str(item) + a[item%26]

print "Cipher:  " + result
print "p: " + str(len(p))
print "c: " + str(len(result))