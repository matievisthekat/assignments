# Initialize data1 and data2
data1 = [12, 10, 32, 3, 66, 17, 42, 99, 20]
data2 = [14, 7, -12, 88, -17, 22, -5, 18]

# Perform calculations with data1
print("Data1:")
# Loop that prints each of the numbers on a single line separated with spaces
for num in data1:
    print(num, end = " ")
print()

# Loop that prints each number and its square on a new line
for num in data1:
    print(num, num ** 2)

# Loop that adds all the numbers from the list into a variable called total
total = 0
for num in data1:
    total += num

# Print the total value along with a “label.”
print("The total of the values is", total)

# Print the product of all the numbers in the list
product = 1
for num in data1:
    product *= num
print("The product of all the values is", product)

# Perform calculations with data2
print("Data2:")
# Loop that prints each of the numbers on a single line separated with spaces
for num in data2:
    print(num, end = " ")
print()

# Loop that prints each number and its square on a new line
for num in data2:
    print(num, num ** 2)

# Loop that adds all the numbers from the list into a variable called total
total = 0
for num in data2:
    total += num

# Print the total value along with a “label.”
print("The total of the values is", total)

# Print the product of all the numbers in the list
product = 1
for num in data2:
    product *= num
print("The product of all the values is", product)
