# Collatz.py - Display the Collatz Sequence

def Collatz(n):
    """ Print the Collatz (3n+1) sequence from n,
        terminating when it reaches 1.

        The “computational rule” for creating the Collatz sequence
        is to start from some given n, and to generate the next term
        of the sequence from n, either by halving n, (whenever n is
        even), or else by multiplying it by three and adding 1.
        The sequence terminates when n reaches 1.
    """
    print('Collatz({0}): '.format(n), end='')
    while n > 1:
        print(n, end=", ")
        if n % 2 == 0:      # n is even
            n = n // 2
        else:               # n is odd
            n = n * 3 + 1
    print(n, end=".\n")

print('\nDisplay the first ten Collatz sequences\n')

for c in range(1, 11):
    Collatz(c)

print('\nDone!')
