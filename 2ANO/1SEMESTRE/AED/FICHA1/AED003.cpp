#include <iostream>
#include <vector>
using namespace std;

int pipefish(int n, int k, int t, vector<int>& s){
    int required = (k + 1) / 2;  
    int valid_count = 0;
    int result = 0;              
    
    for (int i = 0; i < k; i++) {
        if (s[i] >= t) valid_count++;
    }

    if (valid_count >= required) result++;

    for (int i = k; i < n; i++) {
        if (s[i - k] >= t) valid_count--;
        if (s[i] >= t) valid_count++;
        if (valid_count >= required) result++;
    }
    
    return result;
}

int main(){
    int n, k, t;
    cin >> n >> k >> t;
    vector<int> s;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        s.push_back(p);
    }
    cout << pipefish(n, k, t, s) << endl;
    return 0;
}