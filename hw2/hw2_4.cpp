#include <iostream>
#include <cstdlib>  // rand
using namespace std;
bool check(int arr[],int count,int num);
bool check(int arr[],int count,int num){   //function to check:Make sure not to pick the same finalist more than once
    bool result = false;
    for (int i=0;i<count;i++){  
        if (arr[i] == num){
            result = true;
        }
    }
    return result;
}

int main(){
    int count = 0;
    const int prize = 4;// have 4 identical prizes
    const int total = 25;//a pool of 25 finalists.
    int winners[prize];
    
    while (count < prize){
        int pick = rand() % 25 + 1;//random pick 1-25
        bool checknum = check(winners, count, pick);
        if (checknum == false){
            winners[count] = pick;
            count = count + 1;
        }
    }
    cout << "winners: " << endl;
    for (int i = 0; i < prize; i++){
        cout << winners[i] << endl;
    }
    return 0;
}
