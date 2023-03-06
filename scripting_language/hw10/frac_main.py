# frac_main.py - Outline for main function for demonstrating the Fraction class
#
# You should base your main routine on this code
# You will need to add code to do the actual calculations of the terms for
# approximating Pi
#

from math import pi as PI

def main():
    print('\nDemonstrate Frac(tions) Class and Approximate PI')
    
    # Demonstrate Frac 1/2, 1/4
    a, b = Frac(1,2), Frac(1,4)
    demo(a, b)
    
    # Repeated demonstrate Frac until an input is zero
    while True:
        a = frac_input('Value for a (as #/#): ')
        if a == 0:
            break
        b = frac_input('Value for b (as #/#): ')
        if b == 0:
            break;
        demo(a, b)
    
    # Begin approximation of PI calculation
    print('\nApproximate PI to Within 1e-14\n')

    pi = Frac(3)
    epsilon = Frac(1, int(1e14))
    print(" Iter'ns         Approximation    \t   Error")
    print('--------    ----------------------\t-----------')
    for loop or while loop:
        delta = <next term in the sequence>
        pi = pi + delta
        Every 5,000 terms:
            print(f'{d:7,}:    pi ~ {float(pi):.16}  \t{float(abs(delta)):.6}')
        if abs(delta) < epsilon:
            break;
    print()
    print(f'{d:7,}:  pi ~ {float(pi):.16}\t  {abs(PI-float(pi)):.6}')
    print(f'          PI ~ {float(PI):.16}')

    print('\nDone')
