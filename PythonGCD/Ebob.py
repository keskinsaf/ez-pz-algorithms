class Ebob:
    """docstring for Ebob.
       EBOB means "Greatest Common Divisor" in Turkish.
       This code is written just for fun by Safa Keskin.
    """
    arg = 0

    def __init__(self, arg):
        self.arg = arg

    def calculate_ebob(self, a, b):
        while a != b:
            if a < b:
                b = b - a
            else:
                a = a - b
        self.arg = a
        return a

ebob = Ebob(0)

n1 = int(raw_input("Enter number 1: "))
n2 = int(raw_input("Enter number 2: "))

print "EBOB of 2 numbers is: " + str(ebob.calculate_ebob(n1, n2))
