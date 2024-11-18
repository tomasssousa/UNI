#include <iostream>
#include <vector>
using namespace std;

int lower_bound(const vector<int>& arr, int X) {
    int left = 0, right = arr.size() - 1;
    int result = arr.size();
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= X) {
            result = mid; 
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int upper_bound(const vector<int>& arr, int X) {
    int left = 0, right = arr.size() - 1;
    int result = arr.size();
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > X) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;

    vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;

        int low = lower_bound(sequence, A);
        int high = upper_bound(sequence, B);

        int result = high - low;
        
        cout << result << endl;
    }
    return 0;
}
