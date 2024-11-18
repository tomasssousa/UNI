#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, q;
    vector<int> s;
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        s.push_back(p);
    }

    sort(s.begin(), s.end());

    for(int j = 0; j < q; j++){
        cout << s[n-1-j] << endl;
    }
    return 0;
}