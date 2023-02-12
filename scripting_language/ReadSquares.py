# ReadSquares.py - Read a Collection of Square Matrices

import numpy as np


# Read the next matrix (possible magic square); returns a NumPy array
# Each matrix is ended with a single blank line
# A second blank line ends the collection of matrices
def next_matrix(fyl):
    sqr = []
    for line in fyl:
        if line.strip() == '':
            break;
        sqr.append(list(map(int, line.split())))
    return np.array(sqr)


# Main driver starts here
print('\nRead a Collection of Matrices')
FILE = 'squaredata.txt'

with open(FILE, 'r', encoding='UTF-8') as f:
    while True:
        square = next_matrix(f)
        if square.size == 0:
            break
        print('\n', square)

print('\nDone\n')
