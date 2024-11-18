#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int kadane(vector<int> v){
    int best_sum = INT_MIN;
    int current_sum = 0;
    int k = v.size();
    for(int j = 0; j < k; j++){
        int x = v[j];
        current_sum = max(x, current_sum + x);
        best_sum = max(best_sum, current_sum);
    }
    return best_sum;
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
    cout << kadane(s) << endl;
    return 0;
}