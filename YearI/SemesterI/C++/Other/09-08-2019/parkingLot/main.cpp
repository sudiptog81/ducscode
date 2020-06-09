#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    char vehicleType;
    int hrEnter, minEnter, hrLeft, minLeft;
    int duration, hrDuration, minDuration, allowedHours;
    float firstRate, secondRate, totalCharge;

    cout << setw(35) << left << "Type of vehicle? ";
    cin >> vehicleType;

    if (!(vehicleType == 'C' || vehicleType == 'T' || vehicleType == 'B'))
    {
        cout << "\nVehicle not allowed!\n\n";
        return 0;
    }

    cout << setw(35) << left << "Hour vehicle entered lot (0-24)? ";
    cin >> hrEnter;

    cout << setw(35) << left << "Minute vehicle entered lot (0-60)? ";
    cin >> minEnter;

    cout << setw(35) << left << "Hour vehicle left lot (0-24)? ";
    cin >> hrLeft;

    cout << setw(35) << left << "Minute vehicle left lot (0-60)? ";
    cin >> minLeft;

    if (hrEnter > hrLeft)
    {
        cout << "\nVehicle towed away!\n\n";
        return 0;
    }

    cout << endl;

    cout << setw(27) << right << "PARKING LOT CHARGE\n\n";

    cout << setw(23) << left << "Type of Vehicle: ";

    switch (vehicleType)
    {
    case 'C':
        cout << setw(9) << right << "Car\n";
        firstRate = 0.00f;
        secondRate = 1.50f;
        allowedHours = 3;
        break;
    case 'T':
        cout << setw(9) << right << "Truck\n";
        firstRate = 1.00f;
        secondRate = 2.30f;
        allowedHours = 2;
        break;
    case 'B':
        cout << setw(9) << right << "Bus\n";
        firstRate = 2.00f;
        secondRate = 3.70f;
        allowedHours = 1;
        break;
    }

    cout << endl;

    cout << setw(25) << setfill(' ') << left << "  TIME-IN";
    cout << setw(2) << setfill('0') << right << hrEnter;
    cout << ":";
    cout << setw(2) << setfill('0') << right << minEnter << endl;

    cout << setw(25) << setfill(' ') << left << "  TIME-OUT";
    cout << setw(2) << setfill('0') << right << hrLeft;
    cout << ":";
    cout << setw(2) << setfill('0') << right << minLeft << endl;

    cout << setw(24) << setfill(' ') << left << " ";
    cout << setw(8) << setfill('-') << right << " " << endl;

    if (minLeft < minEnter)
    {
        hrLeft--;
        minLeft += 60;
    }

    hrDuration = hrLeft - hrEnter;
    minDuration = minLeft - minEnter;

    cout << setw(25) << setfill(' ') << left << "  PARKING TIME";
    cout << setw(2) << setfill('0') << right << hrDuration;
    cout << ":";
    cout << setw(2) << setfill('0') << right << minDuration << endl;

    if (minDuration >= 30)
        hrDuration++;

    cout << setw(26) << setfill(' ') << left << "  ROUNDED TOTAL";
    cout << setw(2) << setfill(' ') << right << hrDuration << endl;

    cout << setw(24) << setfill(' ') << left << " ";
    cout << setw(8) << setfill('-') << right << " " << endl;

    if (hrDuration == 0)
        totalCharge = firstRate;
    else if (hrDuration <= allowedHours)
        totalCharge = firstRate * hrDuration;
    else
        totalCharge = (firstRate * allowedHours) + (secondRate * (hrDuration - allowedHours));

    cout << setw(24) << setfill(' ') << left << "  TOTAL CHARGE";
    cout << "$";
    cout << setw(6) << setfill(' ') << right << fixed << setprecision(2) << showpoint << totalCharge << endl;

    cout << endl;

    return 0;
}