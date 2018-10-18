import json
import sys
Matrixfile = open("compareMatrices.txt", "r+")
matrices = []
for line in Matrixfile:
	matrix = json.loads(line)
	matrices.append(matrix)
maxnum = 0
length = len(matrices)
for i in range(length):
	print(str(i)+": ")
	for j in range(len(matrices[i])):
		print(sys.stdout.write(str(matrices[i][j])))
	if(len(matrices[i]) > maxnum):
		maxnum = len(matrices[i])
	print()
print(maxnum)
