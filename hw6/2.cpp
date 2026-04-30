#include <iostream>
#include <vector>
using namespace std;

void deleterepeated(vector<char>& yvector){
    for (int i=0;i<yvector.size();i++){
        for (int j=i+1;j<yvector.size();j++){
            if (yvector[i]==yvector[j]){
                for (int k=j;k<yvector.size()-1;k++){
                    yvector[k] = yvector[k + 1];
                }
                yvector.resize(yvector.size() - 1);
                j--;
            }
        }
    }
}

void selectionsort(vector<char>& yvector){
    for (int i=0;i<yvector.size()-1;i++){
        int maxindex=i;
        for (int j=i+1;j<yvector.size();j++){
            if (yvector[j] > yvector[maxindex]){
                maxindex=j;
            }
        }
        char temp=yvector[i];
        yvector[i]=yvector[maxindex];
        yvector[maxindex] = temp;
    }
}

int main(){
    vector<char> yvector;
    char input;
    cout<<"please enter a char,enter 0 to quit: "<<endl;
    cin>>input;
    while (input!='0'){
        yvector.push_back(input);
        cout<<"please enter a char, enter 0 to quit: "<<endl;
        cin>>input;
    }
    deleterepeated(yvector);
    selectionsort(yvector);
    cout<<"array with repeated char's removed and sorted from z to a:"<<endl;
    for (int i=0;i<yvector.size();i++){
        cout<<yvector[i]<<endl;
    }
    return 0;
}