"""
Write a menu driven program to perform the following on strings:
a) Find the length of string.
b) Return maximum of three strings.
c) Accept a string and replace all vowels with “#”
d) Find number of words in the given string.
e) Check whether the string is a palindrome or not.
"""

s = ''
s1 = ''
s2 = ''
s3 = ''
flag = 0

def findLength():
  s = input('Enter a String: ')
  # print('Length of String:', len(s))
  count = 0
  for i in s:
    count += 1
  print('Length of String:', count)

def maxOfStrings():
  s1 = input('Enter String 1: ')
  s2 = input('Enter String 2: ')
  s3 = input('Enter String 3: ')
  # print('Maximum of three strings:', max(s1, s2, s3))
  print('Maximum of three strings:', max(s1, s2, s3))

def replaceVowels():
  s = input('Enter a String: ')
  # for i in s:
  #   if i in 'aeiou':
  #     s = s.replace(i, '#')
  l = list(s)
  for i in range(0, len(l), 1):
    if l[i] in 'aeiou':
      l[i] = '#'
  s = ''.join(l)
  print('Modified String:', s)

def numberOfWords():
  s = input('Enter a String: ')
  # print('Number of Words:',  len(s.split(' ')))
  count = 0
  for i in s:
    if i == ' ':
      count += 1
  print('Number of Words:',  count + 1)

def isPalindrome():
  flag = 1
  s = input('Enter a String: ')
  for i in range(0, len(s) // 2):
    if s[i] != s[len(s) - i - 1]:
      flag = 0
      print('String is not a Palindrome')
      break
  if flag == 1:
      print('String is a Palindrome')

def main():
  while True:
    print(
  """

                      MENU
===================================================
(1) Find the length of string.
(2) Return maximum of three strings.
(3) Accept a string and replace all vowels with '#'
(4) Find number of words in the given string.
(5) Check whether the string is a palindrome or not.
  """
    )
    c = int(input('Enter Choice: '))
    if c == 1:
      findLength()
    elif c == 2:
      maxOfStrings()
    elif c == 3:
      replaceVowels()
    elif c == 4:
      numberOfWords()
    elif c == 5:
      isPalindrome()
    elif c == 0:
      break
    input('Press any key to continue...')

if __name__ == "__main__":
    main()