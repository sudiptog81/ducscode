'''
Consider a tuple t1 = {1,2,5,7,9,2,4,6,8,10}.
Write a program to perform following operations:
  (a) Print another tuple whose values are even numbers in the given tuple.
  (b) Concatenate a tuple t2 = {11,13,15} with t1.
  (c) Return maximum and minimum value from this tuple.

Written by Sudipto Ghosh for the University of Delhi
'''


def main():
    # Given
    t1 = (1, 2, 5, 7, 9, 2, 4, 6, 8, 10)
    t2 = (11, 13, 15)

    even_tuple = ()
    concatenated_tuple = ()
    max_value = 0
    min_value = 0

    print('Original Tuple:', t1)

    # Another Tuple with Even Numbers in t1
    for i in t1:
        if i % 2 == 0:
            even_tuple += (i,)
    print('Even Tuple:', even_tuple)

    # Concatenate t2
    concatenated_tuple = t1 + t2
    print('Concatenated Table: ', concatenated_tuple)

    # Max and Min Values in concatenated tuple
    print('Max Value:', max(concatenated_tuple))
    print('Min Value:', min(concatenated_tuple))


if __name__ == '__main__':
    main()
