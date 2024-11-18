#include <iostream> 
using namespace std;

int main(){
    int n; int counter = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        if(p == 42) {counter += 1;}
    }
    cout << counter << endl;
    return 0;
}