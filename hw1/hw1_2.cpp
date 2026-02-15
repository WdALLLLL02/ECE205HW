#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double base_rate = 36.75;
    const double ot = 1.5;
    const double work_time_limit = 40.0;
    const double social_security = 0.06;
    const double federal_income = 0.15;
    const double state = 0.04;
    const double Bethlehem = 0.01;
    const double union_dues = 20.00;
    double health_insurance;
    
    //input
    double workedtime;
    cin>>workedtime;
    int dependents;
    cin>>dependents;
    if (dependents>=2){
        health_insurance=40.00;
    }
    else{
        health_insurance=0.00;
    }
    double grosspay;
    if(workedtime <= work_time_limit){
        grosspay=workedtime *base_rate;
    }
    else{
        double ot_hours= workedtime- work_time_limit;
        double base_pay=work_time_limit*base_rate;
        double ot_pay= ot_hours*ot*base_rate;
        grosspay=base_pay+ot_pay;
    }
    //with holdings
double federal= federal_income*grosspay;
double state_income= state*grosspay;
double Bethlehem_income= Bethlehem*grosspay;
double ss= social_security*grosspay;
double deductions= union_dues+ federal+state_income+
Bethlehem_income+health_insurance+ss;
double netpay= grosspay-deductions;

cout << fixed << setprecision(2);
cout << "worker gross pay: " << grosspay << endl;
cout << "net take-home pay for the week: " << netpay << endl; 
cout << "Social Security: " << ss << endl;
cout << "Federal income: " << federal << endl;
cout << "State tax: " << state_income << endl;
cout << "Bethlehem local: " << Bethlehem_income << endl;
cout << "Union dues: " << union_dues << endl;
cout << "Health insurance: " << health_insurance << endl;
   
return 0;


}
