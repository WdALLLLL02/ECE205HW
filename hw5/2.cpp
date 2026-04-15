#include <iostream>
using namespace std;

const int deepdish=1;
const int handtossed=2;
const int pan=3;
const int s=1;
const int m=2;
const int l=3;

class pizza{
private:
    int type;
    int size;
    int toppings;
public:
    void settype(int t);
    void setsize(int s);
    void settoppings(int top);
    int gettype();
    int getsize();
    int gettoppings();
    void outputdescription();
    double computeprice();
};
void pizza::settype(int t){
    type = t;
}
void pizza::setsize(int s){
    size = s;
}
void pizza::settoppings(int top){
    toppings = top;
}
int pizza::gettype(){
    return type;
}
int pizza::getsize(){
    return size;
}
int pizza::gettoppings(){
    return toppings;
}
void pizza::outputdescription(){
    cout<<"pizza description:"<<endl;
    cout<<"type: ";
    if (type == deepdish)
        cout<<"deep dish"<<endl;
    else if (type == handtossed)
        cout << "hand tossed"<<endl;
    else if (type == pan)
        cout << "pan"<<endl;
    cout<<"size: ";
    if (size==s)
        cout<<"small"<<endl;
    else if (size == m)
        cout<<"medium"<<endl;
    else if (size==l)
        cout<<"large"<<endl;
    cout<<"number of toppings: "<<toppings <<endl;
}

double pizza::computeprice(){
    double price=0.0;
    if (size==s)
        price=10+toppings*2;
    else if (size==m)
        price=14+toppings*2;
    else if (size==l)
        price=17+toppings*2;
    return price;
}

int main(){
    pizza pizza1, pizza2;
    pizza1.settype(deepdish);
    pizza1.setsize(s);
    pizza1.settoppings(2);
    pizza2.settype(pan);
    pizza2.setsize(l);
    pizza2.settoppings(3);
    pizza1.outputdescription();
    cout << "price: $" << pizza1.computeprice() << endl;
    cout << endl;
    pizza2.outputdescription();
    cout << "price: $" << pizza2.computeprice() << endl;
    return 0;
}