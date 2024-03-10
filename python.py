import sys
import time

# Load data

file_name = sys.argv[1]
try:
    file = open(file_name, "r")
except:
    print("Cannot open file {file_name}...")
    sys.exit()

data = file.read().splitlines()

file.close()

mode = int(data[0])
data_type = data[1]

first_matrix_dimensions = [int(x) for x in data[2].split('x')]
first_matrix = []

for x in range(3, 3 + first_matrix_dimensions[0]):
    first_matrix.append([int(y) for y in data[x].split()])

second_matrix_dimensions = [int(x) for x in data[3 + first_matrix_dimensions[0]].split('x')]
second_matrix = []

for x in range(3 + first_matrix_dimensions[0] + 1, 3 + first_matrix_dimensions[0] + 1 + second_matrix_dimensions[0]):
    second_matrix.append([int(y) for y in data[x].split()])


# Generating Result Matrix

result_matrix = []

for x in range(0, first_matrix_dimensions[0]):
    result_matrix.append([])
    for y in range(0, second_matrix_dimensions[1]):
        result_matrix[x].append(0)

# -------------------------------------------- Performing calculations --------------------------------------------

start_time = time.time()

for row in range(0, first_matrix_dimensions[0]):
    for col in range(0, second_matrix_dimensions[1]):
        for iter in range(0, second_matrix_dimensions[0]):
            result_matrix[row][col] += first_matrix[row][iter] * second_matrix[iter][col]

end_time = time.time() - start_time

result = open("result.txt", "w")
result.write(data_type + '\n')
result.write(str(first_matrix_dimensions[0]) + 'x' + str(second_matrix_dimensions[1]) + '\n')
for x in result_matrix:
    for y in x:
        result.write(str(y) + '\t')
    result.write('\n')

result.close()

print("Results Written.")
print("Time taken: %s seconds." % end_time)