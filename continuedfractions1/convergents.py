# Solution without using SageMath

# Use the Decimal package to increase precision
from decimal import *

# Set the precision to an arbitrary number > ~125 (The length of the flag in ASCII)
getcontext().prec = 150

# Put all the numbers in a list, and store the list's length
convergents = [1, 98, 1, 48, 1, 3, 1, 3, 5, 45, 1, 5, 1, 17, 1, 1, 5, 3, 2, 6, 3, 4, 17, 1, 6, 1, 2, 7, 1, 1, 5, 1, 1, 1, 2, 1, 12, 2, 9, 7, 1, 1, 5, 4, 2, 11, 2, 1, 1, 2, 1, 7, 2, 1, 111, 2, 2, 1, 11, 2, 1, 9, 3, 3, 1, 7, 9, 3, 1384, 15, 3, 2, 4, 1, 3, 2, 3, 1, 9, 1, 2, 7, 1, 3, 73, 1, 1, 7, 1, 1, 6, 13, 1, 1, 1, 12, 1, 3, 1, 6, 18, 1, 21, 1, 2, 4, 1, 1, 8, 1, 6, 1, 1, 1, 1, 1, 12, 4, 7, 1, 1, 8, 5, 2, 1, 2, 3, 2, 1, 1, 5, 1, 21, 2, 2, 1, 6, 2, 208, 2, 7, 4, 2, 8, 1, 2, 2, 2, 5, 10, 5, 2, 5, 1, 5, 1, 7, 2, 1, 13, 2, 9, 4, 1, 2, 2, 5, 5, 1, 2, 20, 1, 2, 1, 2, 2, 7, 1, 6, 11, 2, 2, 2, 3, 1, 3, 1, 37, 1, 3074, 15, 5, 1, 2, 1, 2, 7, 2, 2, 2, 2, 1, 60, 1, 8, 2, 1, 4, 14, 1, 10, 1, 2]
nums = len(convergents)

# Convert this continued fraction into a decimal number
# There are many ways to do this
# This method uses an iterator and goes from front-to-back
# Other methods include going from back-to-front, or using software like SageMath
def convergeCalc (i):
    convergent = Decimal(convergents[i])
    if (i == nums - 1):
        return (1 / convergent)
    else:
        return (1 / (convergent + convergeCalc(i + 1)))

print(convergeCalc(0))

# After acquiring the decimal, notice that it looks like an ASCII string.
# Break it up and convert it into the flag.