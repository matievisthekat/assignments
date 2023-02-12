import numpy as np

def magic(matrix):
    rows, cols = matrix.shape
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
    squares = []
    with open("squaredata.txt", "r") as file:
        while True:
          sqr = []
          for line in file:
              if line.strip() == '':
                  break;
              sqr.append(list(map(int, line.split())))
          square = np.array(sqr)
          if (square.size == 0):
            break
          else:
            squares.append(square)

    for i, sqr in enumerate(squares):
      mag = magic(sqr)
      if mag == -1:
        print(f"Matrix {i + 1} is not a magic square")
      else:
        print(f"Matrix {i + 1} is a magic square: {mag}")

if __name__ == '__main__':
    main()
