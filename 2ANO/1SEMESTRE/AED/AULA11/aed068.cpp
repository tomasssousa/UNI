#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
  int k;
  cin >> k;
  string s;
  cin >> s;
  unordered_map<string, int> motifs;
  for(int i = 0; i <= s.length() - k; i++){
    string prev = s.substr(i, k);
    motifs[prev]++;
  }
  int maxValue = 0;
  string maxKey;
  int repetitions = 0;
  for (const auto &pair : motifs) {
      if (pair.second > maxValue) {
          maxValue = pair.second;
          maxKey = pair.first;
          repetitions = 1;
      }
      else if (pair.second == maxValue) {
          repetitions++;
      }
  }
  cout << maxValue << endl;
  if (repetitions > 1) {
    cout << repetitions << endl;
  }
  else {
    cout << maxKey << endl;
  }
  return 0;
}