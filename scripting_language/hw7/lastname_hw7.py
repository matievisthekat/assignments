import numpy as np

def magic(matrix):
    rows, cols = matrix.shape
    # If the matrix is not a square
    if rows != cols:
        return -1
    magic_number = np.sum(matrix[0,:])
    for i in range(rows):
        if magic_number != np.sum(matrix[i,:]):
            return -1
        if magic_number != np.sum(matrix[:,i]):
            return -1
    if magic_number != np.trace(matrix):
        return -1
    if magic_number != np.trace(np.fliplr(matrix)):
        return -1
    return magic_number

def main():
    print("Determine if a Matrix is a Magic Square")

    squares = []
    # Open the file in read mode
    with open("squaredata.txt", "r") as file:
        while True:
          sqr = []
          for line in file:
              if line.strip() == '':
                  break;
              # Append the new square to the list of squares  
              sqr.append(list(map(int, line.split())))
          square = np.array(sqr)
          if (square.size == 0):
            break
          else:
            squares.append(square)

    for sqr in squares:
        # Call the magic function
        mag = magic(sqr)

        rows, cols = sqr.shape

        print(f"Square ({rows} x {cols}):")
        print(sqr)

        if mag == -1:
            print(f"is not a magic square")
        else:
            print(f"is a magic square; the magic number is {mag}")

        print("\n")

if __name__ == '__main__':
    main()
