#include <iostream>
#include <vector>
using namespace std;

void SieveOfEratosthenes(int n){
    vector<bool> primes(n,true);
    primes[0]=false;
    primes[1]=false;

    for (int i=2;i<n;i++){
        if (primes[i]==true){
            for (int j=i*2;j<n;j=j+i)
            {
                primes[j] = false;
            }
        }
    }
    cout << "prime numbers less than " << n << ":" << endl;
    for (int i = 2; i < n; i++){
        if (primes[i] == true){
            cout << i << " ";
        }
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"enter a number: ";
    cin>>n;
    SieveOfEratosthenes(n);
    return 0;
}