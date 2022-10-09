import math

# create an output file
outputFile = open("python_output.txt", 'w')

while True:
    # Store input numbers
    num = input('Please enter three sides: ').split()
    side1 = float(num[0])
    side2 = float(num[1])
    side3 = float(num[2])

    # print(side1)
    # print(side2)
    # print(side3)

    # Check the input data whether they are legal or not
    # Ilegal

    if side1 == -1 and side2 == -1 and side3 == -1:
        print("program terminated")
        break
    else:
        # Ilegal
        if side1 + side2 <= side3 or side1 + side3 <= side2 or side2 + side3 <= side1:
            outputFile.write('The input data is ilegal' + '\n')
        # Legal
        else:
            sum = (side1 + side2 + side3) / 2
            # print(sum)
            area = sum * (sum - side1) * (sum - side2) * (sum - side3)
            area = math.sqrt(area)
            outputFile.write("The area of the triangle is " + str(area) + "\n")

# close the file
outputFile.close()
