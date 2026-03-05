#include <iostream>
using namespace std;
void convert12hr(int t, int& hour, int& min, char& period);
void convert12hr(int t, int& hour, int& min, char& period){
    hour = t/100;
    min = t%100;

    if(hour>=12)
        period='P';
    else
        period='A';

    if(hour==0)
        hour=12;

    if(hour>12)
        hour=hour-12;
    if (min>60)
    {
        cout<<"error"<< endl;
    }
    
}
void print(int hour, int min, char period);
void print(int hour, int min, char period){
    cout<<hour <<":"<<min<<period << "m" << endl;
}
int main(){
    int t;
    int hour, min;
    char period;
    cout << "enter time in 24hr format: ";
    cin >> t;
    convert12hr(t, hour, min, period);
    print(hour, min, period);
    return 0;
}