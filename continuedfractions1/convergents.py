from decimal import *

getcontext().prec = 125

convergents = [1, 98, 1, 48, 1, 3, 1, 3, 5, 45, 1, 5, 1, 17, 1, 1, 5, 3, 2, 6, 3, 4, 17, 1, 6, 1, 2, 7, 1, 1, 5, 1, 1, 1, 2, 1, 12, 2, 9, 7, 1, 1, 5, 4, 2, 11, 2, 1, 1, 2, 1, 7, 2, 1, 111, 2, 2, 1, 11, 2, 1, 9, 3, 3, 1, 7, 9, 3, 1384, 15, 3, 2, 4, 1, 3, 2, 3, 1, 9, 1, 2, 7, 1, 3, 73, 1, 1, 7, 1, 1, 6, 13, 1, 1, 1, 12, 1, 3, 1, 6, 18, 1, 21, 1, 2, 4, 2]
nums = len(convergents)

def convergeCalc (i):
    convergent = Decimal(convergents[i])
    if (i == nums - 1):
        return (1 / convergent)
    else:
        return (1 / (convergent + convergeCalc(i + 1)))

print(convergeCalc(0))