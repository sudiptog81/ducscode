#include <cstring>
#include <iostream>

using namespace std;

class Person
{
private:
    int age;
    char gender;
    char name[255];

public:
    Person();
    Person(char *, int, char);
    Person(Person &);

    ~Person() {}

    int getAge();
    char *getName();
    char getGender();

    void setAge(int);
    void setName(char *);
    void setGender(char);
};

int getNumbers();
void makeArray(Person *, int);
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

Person::Person(Person &a)
{
    strcpy(name, a.name);
    age = a.age;
    gender = a.gender;
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

        a[i] = Person(name, age, gender);

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
