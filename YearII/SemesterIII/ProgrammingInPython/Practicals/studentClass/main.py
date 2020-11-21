'''
Define a class Student to store his/her name and marks in three subjects.
Use a class variable to store the maximum average marks of the class. Use
constructor and destructor to initialize and destroy the objects.

Written by Sudipto Ghosh for the University of Delhi
'''


class Student:
    count = 0
    maxAverage = 0.0

    def __init__(self, name='', marks=[0, 0, 0]):
        self.name = name
        self.marks = marks[:4]

    def __del__(self):
        del self.name
        del self.marks
        del self

    def __str__(self):
        return f'''{self.name}
===========
Subject 1: {self.marks[0]}
Subject 2: {self.marks[1]}
Subject 3: {self.marks[2]}
Average Marks: {self.computeAverage():.2f}
        '''

    def computeAverage(self):
        acc = 0.0
        for i in self.marks:
            acc += i
        return acc / 3


if __name__ == '__main__':
    n = 0

    students = []

    n = int(input('Enter Number of Students: '))
    for i in range(1, n + 1, 1):
        m = 0
        s = ''
        marks = []

        print(f'Student {i}\n=========')
        s = input('Enter Name: ')
        for j in range(1, 4, 1):
            m = int(input(f'Enter Marks for Subject {j}: '))
            marks.append(m)
        print()

        student = Student(s, marks)

        Student.count += 1
        Student.maxAverage = max(
            Student.maxAverage,
            student.computeAverage()
        )

        students.append(student)

    for i in students:
        print(i)

    print(f'Max Average: {Student.maxAverage:.2f}')
