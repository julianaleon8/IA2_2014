import sys
import random

def isInCircle(x, y):

	value = (x - 10)*(x - 10) + (y - 10)*(y - 10)

	if value > 49:
		return -1
	else:
		return 1

myfile = open('validation_data', 'w')

for i in range(101):
	for j in range(101):

		x = i*20/100

		y = j*20/100
		res = isInCircle(x, y)

		myfile.write(str(x) + ' ' + str(y) + ' ' + str(res) + '\n')

myfile.close()
