#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
 // 1. define how many seconds in one min and one hour
    const int secpermin=60;
    const int secperhour=3600;
    // int total seconds;
    int totaltime;
    cin >> totaltime; //read input from the console


    // int hours, minutes, seconds;
    int hours = totaltime/secperhour;
    int remainingtime=totaltime % secperhour;
    int min = remainingtime/secpermin;
    int sec= remainingtime % secpermin;
    double outhours = totaltime / 3600.0;
    double outminutes = totaltime / 60.0;

    // Output
    cout << hours << " hours, " << min << " minutes, " << sec << " seconds" << endl;
    cout << fixed << setprecision(4);
    cout << outhours << " hours" << endl;
    cout << outminutes << " min" << endl;

    return 0;

    
}
    