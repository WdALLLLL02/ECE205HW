#include <iostream>
#include <vector>
using namespace std;

int maxi(vector<int> yvector){
    int max=0;
    for (int i=0; i<yvector.size(); i++){
        if (yvector[i] > max)
            max=yvector[i];
    }
    return max;
}

void mhistogram(vector<int> yvector, vector<int>& histogram){
    int bin;
    for (int i=0;i<yvector.size();i++){
        bin=yvector[i]/10;
        histogram[bin]++;
    }
}
void outhistogram(vector<int> histogram){
    cout<<endl;
    cout<<"Histogram:"<<endl;
    for (int i=0;i<histogram.size();i++){
        cout<<i*10<<"..."<<i*10+9<<":"<<histogram[i]<<endl;
    }
}

int main(){
    vector<int> yvector;
    int number;
    cout<<"enter a non negative integer,or negative integer to quit: " << endl;
    cin>>number;

    while (number >= 0){
        yvector.push_back(number);
        cout << "enter a nonnegative integer,or negative integer to quit: " << endl;
        cin >> number;
    }

    if (yvector.size() == 0){
        cout << "no data entered." << endl;
        return 0;
    }

    int max = maxi(yvector);
    vector<int> histogram(max/10+1,0);
    mhistogram(yvector, histogram);
    outhistogram(histogram);
    return 0;
}