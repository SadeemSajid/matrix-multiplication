import random
import sys

#   command order
#   1: operand, 2: data type, 3,4: dimension of first matrix, 5,6: dimension of second matrix

try:
    operand = int(sys.argv[1])
    data_type = (sys.argv[2]).upper()
    first_matrix_dimensions = [int(sys.argv[3]), int(sys.argv[4])]
    second_matrix_dimensions = [int(sys.argv[5]), int(sys.argv[6])]
except:
    print("Error in processing commands!")
    sys.exit(0)

if first_matrix_dimensions[1] != second_matrix_dimensions[0]:
    print("Matrix dimensions not suitable for multiplication.")
    sys.exit(0)

# Generate File

data = open("input.txt", "w")

data.write(str(operand) + "\n")             # Operand
data.write(data_type + "\n")                 # Matrix Data Type


data.write(str(first_matrix_dimensions[0]) + 'x' + str(first_matrix_dimensions[1]) + "\n")         # Dimensions of first row

for x in range(0, first_matrix_dimensions[0]):              # Data of first row
    for y in range(0, first_matrix_dimensions[1]):
        data.write(str(random.randint(0, 9)) + "\t")
    data.write("\n")

data.write(str(second_matrix_dimensions[0]) + 'x' + str(second_matrix_dimensions[1]) + "\n")         # Dimensions of second row

for x in range(0, second_matrix_dimensions[0]):              # Data of second row
    for y in range(0, second_matrix_dimensions[1]):
        data.write(str(random.randint(0, 9)) + "\t")
    data.write("\n")

data.close()

print("Data File Created.")
print("Exiting...")