#include <iostream>
using namespace std;

class Book{
private:
    string category;
    int year;
    int ISBN;
public:
    Book(string category1, int year1, int ISBN1);
    bool availability();
};

Book::Book(string category1, int year1, int ISBN1){
    category = category1;
    year = year1;
    ISBN = ISBN1;
}
bool Book::availability(){
    if ((year > 1950) && (category == "history")){
        return true;
    }
    else{
        return false;
    }
}
void display(Book book1);
void display(Book book1){
    if (book1.availability()){
        cout << "available" << endl;
    }
    else{
        cout << "not available" << endl;
    }
}

int main(){
    string category;
    int year;
    int ISBN;
    cout<<"category:" << endl;
    cin>>category;
    cout<<"publishing year:" << endl;
    cin>>year;
    cout<<"ISBN:" << endl;
    cin>>ISBN;
    Book book1(category, year, ISBN);
    display(book1);
    return 0;
}