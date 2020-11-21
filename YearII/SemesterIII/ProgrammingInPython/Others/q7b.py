class Student:
    def __init__(self, name='', rollNo=0, course='', department=''):
        self.name = name
        self.rollNo = rollNo
        self.course = course
        self.department = department

    def __str__(self):
        return f'''
{self.name}
===============
Roll No.: {self.rollNo}
Course: {self.course}
Deptt.: {self.department}'''


if __name__ == "__main__":
    students = []
    while True:
        print('''
          MENU
===========================
 (1) Add Student Record
 (2) Read Student Record
 (3) Delete Student Record
 (0) Exit
        ''')
        ch = int(input('Enter Choice: '))
        if ch == 1:
            try:
                s = Student()
                s.name = input('Enter Name: ')
                s.rollNo = int(input('Enter Roll No.: '))
                s.course = input('Enter Course: ')
                s.department = input('Enter Department: ')
                for t in students:
                    if t.rollNo == s.rollNo:
                        raise KeyError()
                students.append(s)
            except KeyError as e:
                print('Student Already Exists. Not Added.')
            except Exception as e:
                print('Invalid Input. Try Again.')
        elif ch == 2:
            flag = False
            rollNo = int(input('Enter Roll No. to Search: '))
            for s in students:
                if s.rollNo == rollNo:
                    print(s)
                    flag = True
            if not flag:
                print('\nStudent Not Found.')
        elif ch == 3:
            flag = False
            rollNo = int(input('Enter Roll No. to Delete: '))
            for s in students:
                if s.rollNo == rollNo:
                    print(f'Deleting Record for {s.rollNo}.')
                    students.remove(s)
                    flag = True
            if not flag:
                print('\nStudent Not Found.')
        elif ch == 0:
            break
        input('\nPress Enter to Continue...')
