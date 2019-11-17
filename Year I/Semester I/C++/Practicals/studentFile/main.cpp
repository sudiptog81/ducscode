/**
 *  Create a class Student containing fields for Roll No., 
 *  Name, Class, Year and Total Marks. Write a program to 
 *  store 5 objects of Student class in a file. Retrieve 
 *  these records from file and display them
 * 
 *  Written by: Sudipto Ghosh for University of Delhi
 *  Date: 16 - 08 - 2019
 */

#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <iostream>

using namespace std;

class Student
{
private:
    int _year;
    int _class;
    int _rollNo;
    char _name[255];
    int _totMarks;

public:
    Student(int a = 0, string b = "", int c = 0, int d = 0, int e = 0)
    {
        _rollNo = a;
        strcpy(_name, b.c_str());
        _year = c;
        _class = d;
        _totMarks = e;
    }
    void print()
    {
        cout << "|" << setw(8) << _rollNo
             << "\t|" << setw(10) << _name
             << "\t|" << setw(6) << _year
             << "\t|" << setw(6) << _class
             << "\t|" << setw(6) << _totMarks
             << "\t|" << endl;
    }
};

int main()
{
    string b;
    int a, c, d, e;
    Student f[5], g[1000];
    fstream fout, fin;

    cout << "Data Entry\n--------------\n\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << (i + 1) << endl;
        cout << "------------" << endl;
        cout << "Enter Roll No.: ";
        cin >> a;
        cout << "Enter Name: ";
        cin >> b;
        cout << "Enter Year: ";
        cin >> c;
        cout << "Enter Class: ";
        cin >> d;
        cout << "Enter Total Marks: ";
        cin >> e;
        f[i] = Student(a, b, c, d, e);
        cout << endl;
    }

    cout << "---------------------------------------------------------\n\n";

    cout << "Writing 5 Students to STUDENTS.DAT...\n";
    fout.open("STUDENTS.DAT", ios::app);
    if (!fout)
    {
        cerr << "Could not open STUDENTS.DAT for writing...\n";
        return -1;
    }
    for (int i = 0; i < 5; i++)
        fout.write((char *)(&f[i]), sizeof(Student));
    fout.close();
    cout << "Write successful...\n";

    cout << "\n---------------------------------------------------------\n\n";

    cout << "Reading 5 Students from STUDENTS.DAT...\n";
    int count = 0;
    fin.open("STUDENTS.DAT", ios::in);
    if (!fin)
    {
        cerr << "Could not open STUDENTS.DAT for reading...\n";
        return -1;
    }
    for (int i = 0; fin; i++)
    {
        fin.read((char *)&g[i], sizeof(Student));
        count++;
    }
    fin.close();
    cout << "Read successful...\n";

    cout << "\n---------------------------------------------------------\n\n";

    cout << "Data Viewer\n----------------\n\n";
    for (int i = 0; i < count - 1; i++)
        g[i].print();

    cout << "\n---------------------------------------------------------\n\n";

    return 0;
}