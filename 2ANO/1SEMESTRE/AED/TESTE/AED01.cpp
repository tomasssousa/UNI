#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0 && n != i) {return false;}
    }
    return true;
}

int main(){
    int n;
    cin >>  n;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        bool result = isPrime(p);
        if(result == true) {cout << p << " is prime" << endl;}
        else {cout << p << " is composite" << endl;}
    }
    return 0;
}