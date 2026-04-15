#include <iostream>
using namespace std;
bool isprime(int n){
    if (n<=1)
        return false;
    for (int i=2;i<n;i++){
        if (n%i==0)
            return false;
    }
    return true;
}

class primenumber{
private:
    int num;
public:
    primenumber();
    primenumber(int n);
    int getPrime();
    primenumber operator++();     
    primenumber operator++(int);  
    primenumber operator--();     
    primenumber operator--(int);  
};
primenumber::primenumber(){
    num=1;
}
primenumber::primenumber(int n){
    num=n;
}
int primenumber::getPrime(){
    return num;
}
primenumber primenumber::operator++(){
    num++;
    while (!isprime(num)){
        num++;
    }
    return *this;
}
primenumber primenumber::operator++(int){
    primenumber temp(num);
    num++;
    while (!isprime(num)){
        num++;
    }
    return temp;
}
primenumber primenumber::operator--(){
    num--;
    while (num>1&&!isprime(num)){
        num--;
    }
    return *this;
}
primenumber primenumber::operator--(int){
    primenumber temp(num);
    num--;
    while (num>1&&!isprime(num)){
        num--;
    }
    return temp;
}
int main(){
    primenumber p1;
    primenumber p2(13);
    cout<<"Default prime number: "<<p1.getPrime()<<endl;
    cout<<"Initial value of p2: "<<p2.getPrime()<<endl;
    ++p2;
    cout<<"After prefix ++, p2: "<<p2.getPrime()<<endl;
    p2++;
    cout<<"After postfix ++, p2: "<<p2.getPrime()<<endl;
    --p2;
    cout<<"After prefix --, p2: "<<p2.getPrime()<<endl;
    p2--;
    cout<<"After postfix --, p2: "<<p2.getPrime()<<endl;
    return 0;
}