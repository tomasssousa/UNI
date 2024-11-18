#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int bits{0};
    int value{0};
} number;

bool compareNumber(const number & p1, const number & p2){
    if (p1.bits < p2.bits) return false;
    if (p1.bits > p2.bits) return true;
    return p1.value < p2.value;
}

int count_bits(int n){
    int num = 0;
    while(n){
        num += n & 1;
        n = n >> 1;
    }
    return num;
}

int main(){
    int n;
    cin >> n;
    vector<number> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].value;
        v[i].bits = count_bits(v[i].value);
    }
    sort(v.begin(), v.end(), compareNumber);
    for(int j = 1; j <= n; j++){
        cout << v[n-j].value << endl;
    }
    return 0;
}