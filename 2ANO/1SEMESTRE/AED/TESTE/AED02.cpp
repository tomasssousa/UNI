#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int kadane(const vector<int>& s){
    int sum = 0;
    int max_sum = INT_MIN;
    int k = s.size();
    for(int i = 0; i < k; i++){
        int x = s[i];
        sum = max(x, sum + x);
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

int main(){
    int n;
    cin >>n;
    vector<int> s;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        s.push_back(p);
    }
    int result = kadane(s);
    cout << result << endl;
    return 0;
}