#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> & s, int k){
    int low = 0;
    int high = s.size() - 1;
    int result = s.size();
    while(low <= high){
        int middle = low + (high - low)/2;
        if(k <= s[middle]) {result = middle; high = middle - 1;}
        else {low = middle + 1;}
    }
    return result;
}

int upperBound(vector<int> & s, int k){
    int low = 0;
    int high = s.size() - 1;
    int result = s.size();
    while(low <= high){
        int middle = low + (high - low)/2;
        if(k < s[middle]) {result = middle; high = middle - 1;}
        else {low = middle + 1;}
    }
    return result;
}

int main(){
    int n, q;
    vector<int> s;
    cin >> n;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        s.push_back(p);
    }
    cin >> q;
    for(int j = 0; j < q; j++){
        int k, l;
        cin >> k >> l;
        int low = lowerBound(s, k);
        int high = upperBound(s, l);
        int result = high - low;
        cout << result << endl;
    }
    return 0;
}