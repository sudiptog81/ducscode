#include <cstring>
#include <iostream>

using namespace std;

class Person
{
private:
    // data members

    // age of member
    int age;
    // gender of member
    char gender;
    // name of member
    char name[255];

public:
    // constructors

    // default constructor
    Person();
    // parameterized constructor
    Person(char *, int, char);
    // copy construcor
    Person(Person &);

    // destructor
    ~Person() {}

    // getters

    // get the age of member
    int getAge();
    // get the name of member
    char *getName();
    // get the gender of member
    char getGender();

    // setters

    // set the age of a member
    void setAge(int);
    // set the name of a member
    void setName(char *);
    void setGender(char);
};

// get number of guests
int getNumbers();
// construct array of guests
void makeArray(Person *, int);
// display list of the guests
void getDetails(Person *, int);

int main()
{
    int num = getNumbers();

    Person people[num];

    makeArray(people, num);
    getDetails(people, num);

    return 0;
}

Person::Person()
{
    age = 0;
    gender = 'M';
    strcpy(name, "");
}

Person::Person(char *a, int b, char c)
{
    strcpy(name, a);
    age = b;
    gender = c;
}

int Person::getAge()
{
    return age;
}
char *Person::getName()
{
    return name;
}
char Person::getGender()
{
    return gender;
}

void Person::setName(char *a)
{
    strcpy(name, a);
    return;
}

void Person::setAge(int a)
{
    age = a;
    return;
}

void Person::setGender(char a)
{
    gender = a;
    return;
}

void makeArray(Person *a, int b)
{
    int age;
    char gender, name[255];
    for (int i = 0; i < b; i++)
    {
        cout << "Person " << i + 1 << ":\n";

        cout << "\tName: ";
        cin >> name;
        cout << "\tAge: ";
        cin >> age;
        cout << "\tGender: ";
        cin >> gender;

        a[i].setAge(age);
        a[i].setName(name);
        a[i].setGender(gender);

        cout << endl;
    }

    return;
}

int getNumbers()
{
    int a;
    cout << "Number of People: ";
    cin >> a;
    cout << endl;
    return a;
}

void getDetails(Person *a, int b)
{
    cout << "Registered: " << b << "\n\n";
    cout << "\tName\t|\tAge\t|\tGender\n";
    cout << "-----------------------------------------------------\n";
    for (int i = 0; i < b; i++)
    {
        cout << "\t" << a[i].getName() << "\t|\t"
             << a[i].getAge() << "\t|\t"
             << a[i].getGender() << ""
             << endl;
    }
}
