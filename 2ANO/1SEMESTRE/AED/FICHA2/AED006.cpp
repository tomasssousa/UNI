#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(const vector<int>& v, int key){
    int left = 0, right = v.size() - 1;
    int result = -1;  
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (v[mid] >= key) {
            result = mid;  
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main(){
    int n, q;
    cin >> n;
    vector<int> s;

    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        s.push_back(p);
    }

    cin >> q;

    for(int j = 1; j <= q; j++){
        int key;
        cin >> key;
        int result = lowerBound(s, key);
        cout << result << endl;
    }
    
    return 0;
}