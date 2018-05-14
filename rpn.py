# reverse polish notation algorithm
# implemented for a challenge on codela.com

import operator
ops = {"+": operator.add, "-": operator.sub, "*": operator.mul, "/": operator.floordiv }

def solution(expr):
    stack = []
    while len(expr) != 0:
        if expr[0] == "+" or expr[0] == "-" or expr[0] == "*" or expr[0] == "/":
            o2 = stack.pop()
            o1 = stack.pop()
            a = ops[expr[0]](o1, o2)
            stack.append(a)
        else:
            stack.append(int(expr[0]))
        expr = expr[1:]

    if len(stack) > 0:
        return stack.pop()
    else:
        return 0
print("RPN(EX1): ")
print( solution(["5", "2", "1", "-", "+", "6", "*"]) )

print("RPN(EX2): ")
print( solution(["3", "4", "*", "1", "2", "+", "-"]) )

print("RPN(EX3): ")
print( solution([]))
