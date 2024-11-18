#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int n){
    for(int m = 2; m <= sqrt(n); m++){
        if(n != m && n%m == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    vector<int> s;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        s.push_back(p);
    }
    for(int j = 0; j < n; j++){
        int k = s[j];
        bool y = isPrime(k);
        if(y){
            cout << k << " is prime" << endl;
        }
        else{
            cout << k << " is composite" << endl;
        }
    }
    return 0;
}