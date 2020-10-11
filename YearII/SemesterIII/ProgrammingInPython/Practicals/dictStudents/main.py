"""
Use dictionary to store marks of the students in 4 subjects. 
Write a function to find the name of the student securing the
highest percentage.

Written by Sudipto Ghosh for the University of Delhi
"""


def highestPercentage(students, maxMarks=100):
    '''
    Returns the name of the student with the
    highest percentage.

    Accepts:
      students {dict} -- a dictionary of students
    Returns:
      name {str} -- name of the student
    '''

    # calculate percentages
    for student in students:
        s = 0
        for marks in students[student]['marks']:
            s += marks
        students[student]['percentage'] = s / \
            (len(students[student]['marks']) * maxMarks)

    name = ''
    for student in students:
        if not name:
            name = student
            continue
        if students[student]['percentage'] > \
                students[name]['percentage']:
            name = student

    return name


def main():
    name = ''
    marks = 0
    students = dict()
    n = int(input('Enter Number of Students: '))
    maxMarks = int(input('Enter Maximum Marks Possible: '))

    for i in range(1, n + 1, 1):
        print(f'''
Student {i}
============''')
        name = input('Enter Name: ')
        students[name] = dict()
        students[name]['marks'] = []
        for j in range(1, 5, 1):
            marks = int(input(f'Enter Marks in Subject {j}: '))
            students[name]['marks'].append(marks)
        print()

    name = highestPercentage(students, maxMarks)
    print(f'{name} secured the highest percentage.')


if __name__ == '__main__':
    main()
