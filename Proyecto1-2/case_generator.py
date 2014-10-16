import sys
import random

def isInCircle(x, y):

	value = (x - 10)*(x - 10) + (y - 10)*(y - 10)

	if value > 49:
		return -1
	else:
		return 1

num_cases = None
if len(sys.argv) > 1:
	num_cases = sys.argv[1]

if num_cases == None:
	exit(0)

print(num_cases)

myfile = open('my_data' + num_cases, 'w')

for _ in range(int(num_cases)):
	x = random.uniform(0.0, 20.0)
	y = random.uniform(0.0, 20.0)
	res = isInCircle(x, y)

	myfile.write(str(x) + ' ' + str(y) + ' ' + str(res) + '\n')

myfile.close()
