"""
  IMPORTANT NOTE:
  This solution is inspired from the message written by "sourabhsingh" in discussion page of this problem and 
  explanation of the solution that is suggested by "sourabhsingh" is made by me as much a I understand. This is
  a good solution, I like it and implemented in Python.
"""

#!/bin/python

import sys

def powerSum(X, N, num):
    if num**N < X:
        """ 
            powerSum(X-num**N, N, num + 1)      -----      part1
            here we suppose that num^N is a number that can be in such a combination that X can be composed
            using this number(num^N). so we keep going through the other part of the X ( X - num^N) and try
            to find other numbers. 
            
            powerSum(X, N, num + 1)      -----      part2
            here we suppose that num^N is not a number that can be in such a combination that X can be composed
            using this number(num^N). so we keep going through the same number, X, and try to build X using other
            numbers.
        """
        return powerSum(X, N, num+1) + powerSum(X - num**N, N, num+1)
    elif num**N == X:
        return 1
    else:
        return 0

if __name__ == "__main__":
    X = int(raw_input().strip())
    N = int(raw_input().strip())
    result = powerSum(X, N, 1)
    print result
