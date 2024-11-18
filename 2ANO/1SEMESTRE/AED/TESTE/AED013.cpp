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
    vector<number> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i].value;
        s[i].bits = count_bits(s[i].value);
    }
    sort(s.begin(), s.end(), compareNumber);
    for(int j = 0; j < n; j++){
        cout << s[j].value << endl;
    }
    return 0;
}