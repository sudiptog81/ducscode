#include <iostream>

using namespace std;

class Location
{
private:
    int latitude;
    int longitude;

public:
    Location();
    Location(int, int);
    Location(Location &);

    Location operator+(Location &);

    void show()
    {
        cout << "Latitude: " << latitude << "\t";
        cout << "Longitude: " << longitude << endl;
    }
};

Location::Location()
{
    latitude = 0;
    longitude = 0;
}

Location::Location(int x, int y)
{
    latitude = x;
    longitude = y;
}

Location::Location(Location &ob)
{
    latitude = ob.latitude;
    longitude = ob.longitude;
}

Location Location::operator+(Location &ob)
{
    Location result(*this);
    result.longitude += ob.longitude;
    result.latitude += ob.latitude;
    return result;
}

int main()
{
    Location sum;
    Location loc1(1, 2), loc2(3, 4);

    cout << "Location 1\n-------------\n";
    loc1.show();
    cout << endl;

    cout << "Location 2\n-------------\n";
    loc2.show();
    cout << endl;

    cout << "Sum\n-------------\n";
    sum = loc1 + loc2;
    sum.show();

    return 0;
}