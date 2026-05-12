#include <cmath>
#include <iostream>
using namespace std;

class complx{
private://save re im
    double re;
    double im;
public:
    complx(double r, double i);
    double calculateMagnitude();
    complx add(complx c);
    complx sub(complx c);
    complx mul(complx c);
    complx div(complx c);
    void output();
};

complx::complx(double r, double i){
    re=r;
    im=i;
}
double complx::calculateMagnitude(){
    return sqrt(re*re+im*im);
}
complx complx::add(complx x){//add
    complx result(0,0);
    result.re=re+x.re;
    result.im=im+x.im;
    return result;
}
complx complx::sub(complx x){//subctract
    complx result(0,0);
    result.re=re-x.re;
    result.im=im-x.im;
    return result;
}
complx complx::mul(complx x){//multilpy
    complx result(0,0);
    result.re=re*x.re-im*x.im;
    result.im=re*x.im+im*x.re;
    return result;
}
complx complx::div(complx x){//divide
    complx result(0,0);
    double down;
    down=x.re*x.re+x.im*x.im;
    result.re=(re*x.re+im*x.im)/down;
    result.im=(im*x.re-re*x.im)/down;
    return result;
}
void complx::output(){
    cout<<re;
    if (im>=0){
        cout<<"+j"<<im<<endl;
    }
    else{
        cout<<"-j"<<-im<<endl;
    }
}

int main(){
    complx c1(7,4);
    complx c2(1,2);
    cout<<"c1: ";
    c1.output();
    cout<<"c2: ";
    c2.output();
    cout<<"c1+c2: ";
    c1.add(c2).output();
    cout<<"c1-c2: ";//c1-c2
    c1.sub(c2).output();
    cout<<"c2-c1: ";//c1-c2
    c2.sub(c1).output();
    cout<<"c1*c2: ";
    c1.mul(c2).output();
    cout<<"c1/c2: ";
    c1.div(c2).output();
    cout<<"c2/c1: ";
    c2.div(c1).output();
    
}