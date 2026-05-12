#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book{
    private:
    int bookyear;
    string bookname;
    string author;
public:
    void setbookyear(int year){
        bookyear=year;
    }
    void setbookname(string name){
        bookname=name;
    }
    void setauthor(string author){
        author=author;
    }
    int getbookyear(){
        return bookyear;
    }
    string getbookname(){
        return bookname;
    }
    string getauthor(){
        return author;
    }
    void output(){
        cout<<author<<","<<bookname<<","<<bookyear<<","<<endl;
    }
};

void add(vector<Book>& books){
    Book b;
    string name;
    int year;
    string author;
    cout<<"enter title: "<<endl;
    cin>>name;
    cout<<"enter author: "<<endl;
    cin>>author;
    cout<<"enter year: "<<endl;
    cin>>year;
}

void print(vector<Book> books){
    for(int i=0;i<books.size();i++){
        books[i].output();
    }
}
void del(vector<Book> books){
    string name;
    cout<<"enter title to delete:"<<endl;
    cin>>name;
    for(int i=0;i<books.size();i++){
        if(books[i].getbookname()==name){
            books[i]=books[books.size()-1];
            books.pop_back();
            break;
        }
    }
}
int main(){
    vector<Book> books;
    int choice;
    while(true){
        cout<<"1.add new book"<<endl;
        cout<<"2.delete book"<<endl;
        cout<<"3.print listing sorted by author"<<endl;
        cout<<"4.quit"<<endl;
        cin>>choice;
        if(choice==1){
            add(books);
        }
        else if(choice==2){
            del(books);
        }
        else if(choice==3){
            print(books);
        }
        else if(choice==4){
            break;
        }
    }
}
    