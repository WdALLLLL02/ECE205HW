#include <iostream>
using namespace std;
void input(int arr[],int size)
{
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}
void histogram(int arr[], int size, int bins[]);
void histogram(int arr[], int size, int bins[]){
    for(int i=0;i<size;i++){
        int index=arr[i]/10;
        bins[index]++;
    }
}
void output(int bins[]);
void output(int bins[]){
    for(int i=0;i<10;i++){
        cout<<"bin "<<i<<": "<< bins[i]<<endl;
    }
}
int main(){
    int size;
    cin>>size;
    int arr[100];
    input(arr,size);
    int bins[10]={0};
    histogram(arr, size, bins);
    output(bins);
    return 0;
}
