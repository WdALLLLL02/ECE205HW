#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double gravforce(double m1kg,double m2kg, double d ){
    const double G=6.673E-8;
    double m1g=m1kg*1000.0;
    double m2g=m2kg*1000.0;
    double F=(G*m1g*m2g)/pow(d,2);
    return F;
}

int  main(){

    char choice='Y';
    while(choice=='y'||choice =='Y')
    {
        double m1, m2, d;
        cout << "mass 1(kg): ";
        cin >> m1;
        cout << "mass 2(kg): ";
        cin >> m2;
        cout << "distance(cm): ";
        cin >> d;
        double force = gravforce(m1, m2, d);
        cout << "Gravitational Force = " << force << " dynes" << endl;
        cout << "Repeat? (yes/no): ";
        cin >> choice;
    }

    return 0;
}
