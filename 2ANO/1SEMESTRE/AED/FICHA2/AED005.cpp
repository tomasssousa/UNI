#include <iostream>
#include <vector>
using namespace std;

int search(int key, vector<int>& v){
    int low = 0, high = (int)v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key < v[middle]) high = middle - 1;
        else if (key > v[middle]) low = middle + 1;
        else return middle;
    }   
    return -1;
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
        int result = search(key, s);
        cout << result << endl;
    }
    return 0;
}