#!/bin/python3

import sys

def solve(n, p):
    if n % 2 == 0:
        n += 1
    if p % 2 == 0:
        p += 1
    a = int((p - 1) / 2)
    b = int((n - p) / 2)
    if a > b:
        return b
    else:
        return a

n = int(input().strip())
p = int(input().strip())
result = solve(n, p)
print(result)
