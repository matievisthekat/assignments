def reverse_split(lst):
    if len(lst) % 3 != 0:
        return "Invalid List"
    else:
        parts = [lst[i:i+3] for i in range(0, len(lst), 3)]
        for i in range(3):
            parts[i].reverse()
        return parts

while True:
    lst = input("Enter a list of numbers or strings: ")
    if lst == "":
        break
    lst = lst.split()
    result = reverse_split(lst)
    if result == "Invalid List":
        print("Please enter a list of a length that is a multiple of 3")
    else:
        print(result)
