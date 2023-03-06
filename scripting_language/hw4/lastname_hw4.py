def kind(a, b, c):
    if a + b <= c or a + c <= b or b + c <= a:
        return 0
    elif a == b == c:
        return 1
    elif a == b or a == c or b == c:
        if a**2 + b**2 == c**2:
            return 3
        else:
            return 2
    elif a**2 + b**2 == c**2:
        return 3
    elif a**2 + b**2 < c**2:
        return 4
    else:
        return 5

def name(k):
    if k == 0:
        return "No triangle"
    elif k == 1:
        return "Equilateral"
    elif k == 2:
        return "Isosceles"
    elif k == 3:
        return "Right"
    elif k == 4:
        return "Acute"
    else:
        return "Obtuse"

while True:
    a = int(input("Enter the first length: "))
    b = int(input("Enter the second length: "))
    c = int(input("Enter the third length: "))
    if a < 1 or b < 1 or c < 1:
        break
    k = kind(a, b, c)
    print("The triangle is a", name(k))
