#include <iostream>
#include <vector>
using namespace std;

const int deepdish = 1;
const int handtossed = 2;
const int pan = 3;
const int small = 1;
const int medium = 2;
const int large = 3;

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
    cout << "type: ";
    if (type == deepdish)
        cout << "deep dish" << endl;
    else if (type == handtossed)
        cout << "hand tossed" << endl;
    else if (type == pan)
        cout <<"pan" << endl;
    cout<<"size: ";
    if (size == small)
        cout<<"small"<<endl;
    else if (size == medium)
        cout<<"medium"<<endl;
    else if (size == large)
        cout<<"large"<<endl;

    cout<<"toppings: "<<toppings<<endl;
}

double pizza::computeprice(){
    double price=0;
    if (size == small)
        price=10+toppings*2;
    else if (size==medium)
        price=14+toppings*2;
    else if (size==large)
        price=17+toppings*2;
    return price;
}
class order{
private:
    vector<pizza> pizzas;
public:
    void addpizza(pizza p);
    void outputorder();
    double gettotalprice();
};
void order::addpizza(pizza p){
    pizzas.push_back(p);
}
double order::gettotalprice(){
    double total=0;
    for (int i=0;i<pizzas.size();i++){
        total+=pizzas[i].computeprice();
    }
    return total;
}

void order::outputorder(){
    for (int i=0;i<pizzas.size();i++){
        cout<<"pizza "<<i + 1<<":"<< endl;
        pizzas[i].outputdescription();
        cout<<"price: $"<<pizzas[i].computeprice()<<endl;
        cout<<endl;
    }
    cout <<"total Price: $"<<gettotalprice()<<endl;
}
int main(){
    pizza p1, p2, p3;
    p1.settype(deepdish);
    p1.setsize(large);
    p1.settoppings(3);
    p2.settype(pan);
    p2.setsize(small);
    p2.settoppings(1);
    p3.settype(handtossed);
    p3.setsize(medium);
    p3.settoppings(2);
    order order1;
    order1.addpizza(p1);
    order1.addpizza(p2);
    order1.addpizza(p3);
    order1.outputorder();
    return 0;
}