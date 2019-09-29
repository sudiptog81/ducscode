/**
 *  Create the Person class. Create some objects of this
 *  class (by taking information from the user). Inherit
 *  the class Person to create two classes Teacher and 
 *  Student class. Maintain respective information in the
 *  classes and create, display and delete objects of these
 *  two classes. (Use Run Time Polymorphism).
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 28 - 09 - 2019
 */

#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    int age;
    char name[255];

public:
    Person();
    virtual ~Person();
    virtual void get();
    virtual void put();
};

Person::Person()
{
    cout << "Constructor of Person called...\n";
    strcpy(name, "");
    age = 0;
}

Person::~Person()
{
    cout << "Destructor of Person called...\n";
}

void Person::get()
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    return;
}

void Person::put()
{
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    return;
}

class Teacher : public Person
{
private:
    int facultyId;
    char department[255];

public:
    Teacher();
    ~Teacher();
    void get();
    void put();
};

Teacher::Teacher()
{
    cout << "Constructor of Teacher called...\n";
    facultyId = 0;
    strcpy(department, "");
}

Teacher::~Teacher()
{
    cout << "Destructor of Teacher called...\n";
}

void Teacher::get()
{
    Person::get();
    cout << "Enter faculty ID: ";
    cin >> facultyId;
    cout << "Enter department: ";
    cin >> department;
    return;
}

void Teacher::put()
{
    Person::put();
    cout << "Faculty ID: " << facultyId << "\n";
    cout << "Department: " << department << "\n";
    return;
}

class Student : public Person
{
private:
    int rollNo;
    float marks;

public:
    Student();
    ~Student();
    void get();
    void put();
};

Student::Student()
{
    cout << "Constructor of Student called...\n";
    rollNo = 0;
    marks = 0;
}

Student::~Student()
{
    cout << "Destructor of Student called...\n";
}

void Student::get()
{
    Person::get();
    cout << "Enter roll no: ";
    cin >> rollNo;
    cout << "Enter marks: ";
    cin >> marks;
    return;
}

void Student::put()
{
    Person::put();
    cout << "Roll No: " << rollNo << "\n";
    cout << "Marks: " << marks << "\n";
    return;
}

int main()
{
    Person *person1, *person2;

    cout << "Initializing two instances of Person...\n";
    person1 = new Person();
    person2 = new Person();
    cout << endl;

    cout << "Enter details for Person 1: \n";
    person1->get();
    cout << endl;

    cout << "Enter details for Person 2: \n";
    person2->get();
    cout << endl;

    cout << "Person 1\n--------\n";
    person1->put();
    cout << endl;

    cout << "Person 2\n--------\n";
    person2->put();
    cout << endl;

    cout << "Changing Person 1 to Teacher...\n";
    person1 = new Teacher();
    cout << "Person 1 is now a Teacher...\n";
    cout << "Enter new details for Person 1:\n";
    person1->get();
    cout << endl;

    cout << "Changing Person 2 to Student...\n";
    person2 = new Student();
    cout << "Person 2 is now a Student...\n";
    cout << "Enter new details for Person 2:\n";
    person2->get();
    cout << endl;

    cout << "Person 1\n--------\n";
    person1->put();
    cout << endl;

    cout << "Person 2\n--------\n";
    person2->put();
    cout << endl;

    cout << "Deleting Person 1...\n";
    delete person1;
    cout << endl;

    cout << "Deleting Person 2...\n";
    delete person2;
    cout << endl;

    return 0;
}
