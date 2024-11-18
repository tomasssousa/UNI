#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int>& s, int p){
    int low = 0;
    int high = s.size() - 1;
    int result = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(p <= s[mid]) {result = mid; high = mid - 1;}
        else if(p > s[mid]) {low = mid + 1;}
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> s;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        s.push_back(p);
    }
    int q;
    cin >> q;
    for(int j = 0; j < q; j++){
        int k;
        cin >> k;
        cout << lowerBound(s, k) << endl;
    }
    return 0;
}