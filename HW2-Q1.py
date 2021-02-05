from random import randint, choice

TOTALLEN = 20
SHORTLEN = 10

#Generate test numbers for directed.txt

test_cases = []
f = open("directed.txt", "w")
# Clear the file
f.truncate(0)

for i in range(SHORTLEN):
	ranges = choice( [(-1000, -500), (99500,100000)] )

	num = randint(*ranges)
	if i != SHORTLEN-1:
		f.write(str(num) + ", ")
	else:
		f.write(str(num))

f.close()





g = open("directed.txt", "r")
edge_cases = g.read()
g.close()
#print(edge_cases)
edge_cases = edge_cases.split(", ")

for i in range(SHORTLEN):
	# Assuming 100 edge cases numbers are in a python list
	# print(i)
	test_cases.append(int(edge_cases[i]))

# append remaining values

for i in range(TOTALLEN-SHORTLEN):
	test_cases.append(randint(-1000, 100000))

# See that it works
print(test_cases)

# Write test_cases to other file

h = open("text.txt", "w")
for i in range(TOTALLEN):
	if i != TOTALLEN-1:
		h.write(str(test_cases[i]) + ", ")
	else:
		h.write(str(test_cases[i]))
h.close()