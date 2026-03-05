#include <iostream>
using namespace std;
void getWeight(double& lb, double& oz);
void getWeight(double& lb, double& oz){
    cout << "enter pounds: ";
    cin >> lb;
    cout << "enter ounces: ";
    cin >> oz;
}
void convert(double lb, double oz, double& kg);
void convert(double lb, double oz, double& kg){
    double tot_lb;
    double tot_kg;
    tot_lb=lb+oz/16.0;
    tot_kg=tot_lb/2.2046;
    kg=tot_kg;
   
}

void printResult(double kg);
void printResult(double kg){
    cout<<kg<<"kg"<< endl;
}
int main(){
    double lb, oz;
    double kg;
    char choice;
    do{
        getWeight(lb, oz);
        convert(lb, oz, kg);
        printResult(kg);
        cout << "again? (y/n): ";
        cin >> choice;
    } while(choice=='y' || choice=='Y');
    
}

