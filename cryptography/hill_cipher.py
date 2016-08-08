p = raw_input("Plaintext: ")
x = input("Input key matrix rows")
x = int(x)

key = []

for i in range(x):
	temp = [int(i) for i in raw_input("Row(" + str(i) +")").split()]
