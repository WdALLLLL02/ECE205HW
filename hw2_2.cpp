#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
double calaverage(double arr[], int size){
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum / size;
}
double standarddevi(double arr[],int size,double mean){
    double sum = 0;
    for(int i=0; i<size;i++){
        sum += pow(arr[i] - mean, 2);// sum of (x-mean)^2
    }
    double result= sqrt(sum/size);
    return result;
}
int main(){
    const int size=5;
    double score[size];
    ifstream infile;
    infile.open("score.txt");
    for(int i = 0; i < size; i++){
        infile >> score[i];
    }
    infile.close();
    double average= calaverage(score,size);
    double standevi= standarddevi(score,size,average);
    cout << fixed << setprecision(2);
    cout << "average = " << average << endl;
    cout << "standard deviation = "<<standevi << endl;
    ofstream outfile("output.txt");
    outfile << fixed << setprecision(2);
    outfile << "average = " << average << endl;
    outfile << "standard deviation = " << standarddevi << endl;
    outfile.close();
}

