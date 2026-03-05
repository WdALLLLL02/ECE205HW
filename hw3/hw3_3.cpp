#include <iostream>
#include <iomanip>
using namespace std;

int convertmin(int t);
int convertmin(int t){
    int hours= t/100;// 1122,get 11
    int min=t%100;//reminder
    int hm= hours*60;
    int totalmin= hm+min;
    return totalmin;
}
int difference(int start, int end);
int difference(int start, int end){
    int startinmin= convertmin(start);
    int endinmin=convertmin(end);
    int differ= endinmin-startinmin;
    if(differ<0){
        differ+=24*60;
    }
    return differ;

}
int main(){
    int starttime;
    int endtime;
    cout<<"put start time in 24 hour format: ";
    cin>>starttime;
    cout<<"end time in 24 hourformat: ";
    cin>>endtime;
    int d=difference(starttime,endtime);
    cout<<"Difference in minutes ="<<d<<" minutes"<<endl;
    return 0;
}