from random import *
import csv

LEN = 5
RANGE = 5

# Generating my own sample file for testing
# The variables are generated in random order and there may be 0-3 variables per line

g = open("input2.csv", "w")

variables = ["a", "b", "c"]

for i in range(LEN):
	num = randint(0,3)
	
	if(num == 0):
		g.write("\n")
	else:
		var = sample(range(3), 3)
		for j in range(num):

			if(j == num-1):
				g.write(variables[var[j]] + ":" + str(uniform(-RANGE, RANGE)))
			else:
				g.write(variables[var[j]] + ":" + str(uniform(-RANGE, RANGE)) + ",")
		g.write("\n")

g.close()



a_ave = 0
b_ave = 0
c_ave = 0
a_count = 0
b_count = 0
c_count = 0
line_count = 0

f = open("input2.csv", "r")
# Clear the file
lines = f.read()

f.close()
lines = lines.split("\n")


for line in lines:
	if(line!= ""):
		line_count += 1
	x = line.split(",")

	
	for value in x:
		if (value != ""):
			
			if(value[0] == "a"):
				a_count+=1
				a_ave += float(value[2:])
			elif(value[0] == "b"):
				b_count+=1
				b_ave += float(value[2:])
			elif(value[0] == "c"):
				c_count+=1
				c_ave += float(value[2:])
	

#print(lines)
# print(line_count)
a_ave = a_ave/a_count
b_ave = b_ave/b_count
c_ave = c_ave/c_count

print("mean(a)=" + str(a_ave) + "," + "mean(b)=" + str(b_ave) + "," + "mean(c)=" + str(c_ave))








