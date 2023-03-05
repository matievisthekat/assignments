from math import pi as PI


class Frac:
    def __init__(self, top, bot=None):  # 'bot' short for 'bottom'
        self.top = top
        self.bot = bot if bot != None else 1
        self.dec = self.top / self.bot

    def __str__(self):
        (top, bot) = simplify_frac(self.top, self.bot)
        bot = f"/{bot}" if bot != 1 else ""
        return f"{top}{bot}"

    def __abs__(self):
        return abs(self.dec)

    def __float__(self):
        return self.dec

    def __add__(self, other):
        top1 = self.top * (other.bot if isinstance(other, Frac) else 1)
        top2 = (other.top if isinstance(other, Frac) else other) * self.bot
        bot = self.bot * (other.bot if isinstance(other, Frac) else 1)

        top = top1 + top2

        return Frac(top, bot)

    def __sub__(self, other):
        top1 = self.top * (other.bot if isinstance(other, Frac) else 1)
        top2 = (other.top if isinstance(other, Frac) else other) * self.bot
        bot = self.bot * (other.bot if isinstance(other, Frac) else 1)

        top = top1 - top2
        
        return Frac(top, bot)

    def __mul__(self, other):
        #(top, bot) = dec_to_frac(self.dec * (other.dec if isinstance(other, Frac) else other))
        top = self.top * (other.top if isinstance(other, Frac) else other)
        bot = self.bot * (other.bot if isinstance(other, Frac) else 1)
        return Frac(top, bot)

    def __floordiv__(self, other):
        top = self.top * (other.bot if isinstance(other, Frac) else 1)
        bot = self.bot * (other.top if isinstance(other, Frac) else other)
        return Frac(top, bot)

    def __eq__(self, other):
        res = self.dec == (other.dec if isinstance(other, Frac) else other)
        return res



def simplify_frac(num, den):
    # Determine the sign of the resulting fraction
    sign = -1 if num * den < 0 else 1
    num, den = abs(num), abs(den)
    
    # Calculate the greatest common divisor (GCD) of the numerator and denominator
    gcd = 1
    for i in range(1, min(num, den) + 1):
        if num % i == 0 and den % i == 0:
            gcd = i
    
    # Simplify the fraction
    num //= gcd
    den //= gcd
    
    # Return the simplified fraction with the correct sign
    return (sign * num, den)



def dec_to_frac(decimal):
    # Determine sign
    sign = "-" if decimal < 0 else ""
    decimal = abs(decimal)

    # Multiply by 10 until no decimals remain
    count = 0
    while decimal % 1 != 0:
        decimal *= 10
        count += 1

    # Calculate GCD
    numerator = int(decimal)
    denominator = 10 ** count
    gcd = 1
    for i in range(1, min(numerator, denominator) + 1):
        if numerator % i == 0 and denominator % i == 0:
            gcd = i

    # Simplify fraction
    numerator //= gcd
    denominator //= gcd

    return (int(f"{sign}{numerator}"), denominator)


def frac_input(q):
    res = None
    while res == None:
        ans = input(q)
        args = ans.split("/")
        if len(args) != 2 or args[1] == "" or args[0] == "":
            res = Frac(int(ans))
        else:
            try:
                top = int(args[0])
                bot = int(args[1])
                res = Frac(top, bot)
            except:
                print(f"Invalid fraction or integer: '{ans}'")
            

    return res


def demo(a, b):
    print('\nDEMO:   a =', a, '   b =', b)
    print('a+b =', a+b)
    print('a-b =', a-b)
    print('a*b =', a*b)
    print('a/b =', a//b)
    print('b/a =', b//a)
    print('a+5 =', a+5)
    print('b-1 =', b-1)
    print('a*2 =', a*2)
    print('a/5 =', a//5)
    print('float(a//(b*66)) =', float(a//(b*66)))
    print()


def main():
    print("\nDemonstrate Frac(tions) Class and Approximate PI")

    # Demonstrate Frac 1/2, 1/4
    a, b = Frac(1, 2), Frac(1, 4)
    demo(a, b)

    # Repeated demonstrate Frac until an input is zero
    while True:
        a = frac_input("Value for a (as #/#): ")
        if a == 0:
            break
        b = frac_input("Value for b (as #/#): ")
        if b == 0:
            break
        demo(a, b)

    # Begin approximation of PI calculation
    print('\nApproximate PI to Within 1e-14\n')

    pi = Frac(3)
    epsilon = Frac(1, int(1e15))
    print(" Iter'ns         Approximation    \t   Error")
    n = 1
    while True:
        delta = (4 / (n+n * (n+n+1) * (n+n+2))) if n % 2 != 0 else (-4 / (n+n * (n+n+1) * (n+n+2)))
        if n < 10:
            print(f"(4 / ({n+n} * {n+n+1} * {n+n+2}))" if n % 2 != 0 else f"(-4 / ({n+n} * {n+n+1} * {n+n+2}))")
        pi = pi + delta

        n += 1
        if n % 5000 == 0:
            print(f"{n:7,}:    pi ~ {float(pi):.16}  \t{float(abs(delta)):.6}")

        if abs(delta) < float(epsilon):
            break

    print()
    print(f'{n:7,}:    pi ~ {float(pi):.16}\t{abs(PI-float(pi)):.6}')
    print(f'            PI ~ {float(PI):.16}')

    print('\nDone')


if __name__ == "__main__":
    main()
