"""
Write a function that takes a number (>=10) 
as an input and return the digits of the number 
as a set.
"""

n = 0

def setOfDigits(n):
  assert n >= 10
  s = set()
  for i in str(n):
    s.add(int(i))
  return s

n = int(input('Enter a Number: '))
print('Set of Digits:', setOfDigits(n))