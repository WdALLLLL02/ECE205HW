#include <iostream>
#include <iomanip>

using namespace std;
double hat(double weight, double height){
    double size=2.9*weight/height;
    return size;
}
double jacket(double weight, double height,int age){
    double size=height * weight / 288.0;
    if(age>30){
        int over30 = age - 30;
        int years10 = over30 / 10;
        double adjustment = years10 * (1.0 / 8.0);
        size += adjustment;
    }
    return size;
}

double waist(double weight, int age){
    double size = weight / 5.7;

    if(age > 28){
        int years2 = (age - 28) / 2;  // full 2-year period
        size += years2 * (1.0 / 10.0);
    }
    return size;
}
int main(){
    double height;
    double weight;
    int age;
    cout<<"enter your height(inches):";
    cin>>height;
    cout<<"enter weight (pounds): ";
    cin >>weight;

    cout<<"enter age (years): ";
    cin>>age;

    double hatsize=hat(weight,height);
    double jacketsize=jacket(weight,height,age);
    double waistsize=waist(weight,age);

    cout << fixed << setprecision(2);
    cout << "hat size =" << hatsize << endl;
    cout << "jacket size =" << jacketsize << endl;
    cout << "waist size =" << waistsize<< endl;

    return 0;
}

