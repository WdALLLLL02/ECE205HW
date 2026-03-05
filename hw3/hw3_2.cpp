#include <iostream>
#include <cmath>

using namespace std;
void triangle(double a, double b, double c, double& area, double& pr);
void triangle(double a, double b, double c, double& area, double& pr)
{
    if(a+b>c && a+c>b && b+c>a){
        pr = a+b+c;
        double s = pr/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
    }
    else{
        area = 0;
        pr = 0;
    }
}
int main(){
    double a,b,c,area, pr;
    cout<<"enter three sides: ";
    cin>>a>>b>>c;
    triangle(a,b,c,area,pr);
    cout<<"perimeter = "<<pr<<endl;
    cout<<"area = "<<area<<endl;
    return 0;
}