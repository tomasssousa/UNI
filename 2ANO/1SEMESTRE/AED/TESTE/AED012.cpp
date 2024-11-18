#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> s;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        s.push_back(p);
    }
    sort(s.begin(), s.end());
    for(int j = 1; j <= q; j++){
        cout << s[n - j] << endl;
    }
    return 0;
}