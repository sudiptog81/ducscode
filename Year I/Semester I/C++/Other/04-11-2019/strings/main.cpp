#include <string>
#include <iostream>

using namespace std;

int main(void)
{
    /**
     *  Demonstrating Constructors
     */

    string s1;
    cout << s1 << endl;

    string s2("alpha");
    cout << s2 << endl;

    string s3(5, 'a');
    cout << s3 << endl;

    string s4("hello", 2);
    cout << s4 << endl;

    string s5(s2);
    cout << s5 << endl;

    string s6("hello", 2, 25);
    cout << s6 << endl;

    /**
     *  Input
     */

    getline(cin, s1);
    cout << s1 << endl;

    cin >> s2;
    cout << s2 << endl;

    /**
     *  Assignment
     */

    s1 = s3;
    cout << s1 << endl;

    s1 = "alpha";
    cout << s1 << endl;

    string s[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> s[i];
        cout << i << ": " << s[i] << endl;
    }

    /**
     *  Length
     */

    cout << s1.size() << endl;
    cout << s2.length() << endl;

    /**
     *  Comparison
     */

    cout << (s1 == s2) << endl;
    cout << (s1 > s2) << endl;
    cout << (s1 < s3) << endl;

    cout << s1.compare(s2) << endl;
    cout << s2.compare(1, 3, s4) << endl;
    cout << s3.compare(1, 3, s6, 1, 3) << endl;

    /**
     *  Concatenation
     */

    s3 = s1 + s2;
    cout << s3 << endl;

    s4 += s5;
    cout << s4 << endl;

    s1.append(s2);
    cout << s1 << endl;

    s5.append(s6, 1, 3);
    cout << s5 << endl;

    /**
     *  Substring
     */

    string sub1 = s1.substr();
    cout << sub1 << endl;

    string sub2 = s1.substr(2);
    cout << sub2 << endl;

    string sub3 = s1.substr(1, 5);
    cout << sub3 << endl;

    /**
     *  Searching a Substring
     */

    int where1 = s1.find(s2, 0);
    cout << where1 << endl;

    int where2 = s1.find("teen");
    cout << where2 << endl;

    int where3 = s1.rfind(s2, 2);
    cout << where3 << endl;

    /**
     *  Erasing & Clearing
     */

    s2.clear();
    cout << s2 << endl;

    s1.erase(1, 3);
    cout << s1 << endl;

    /**
     *  Swap
     */

    s3.swap(s4);
    cout << s3 << " | " << s4 << endl;

    /**
     *  Replace
     */

    s3.replace(0, 2, s6);
    cout << s3 << endl;

    /**
     *  Insert
     */

    s4.insert(3, s5);
    cout << s4 << endl;

    s4.insert(1, s6, 1, 4);
    cout << s4 << endl;

    s5.insert(0, 2, 'a');
    cout << s5 << endl;

    /**
     *  Character Search Fwd/Bwd
     */

    string s7("ABC Inc");
    string s8("ABC Company");

    int where4 = s8.find_first_of(s7);
    cout << where4 << endl;

    int where5 = s8.find_first_of(s7, 1);
    cout << where5 << endl;

    int where6 = s8.find_first_not_of(s7);
    cout << where6 << endl;

    int where7 = s8.find_last_of(s7);
    cout << where7 << endl;

    int where8 = s8.find_last_not_of(s7);
    cout << where8 << endl;

    return 0;
}