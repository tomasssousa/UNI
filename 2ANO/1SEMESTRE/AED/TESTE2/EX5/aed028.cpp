#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct {
  string name;
  int seconds;
} Process;

int main() {
  int t, n;
  cin >> t;
  cin >> n;
  queue<Process> q;
  for (int i = 0; i < n; i++) {
    Process p;
    cin >> p.name >> p.seconds;
    q.push(p);
  }
  int time_counter = 0;
  int process_counter = 0;
  while (q.size() > 0) {
    Process p = q.front();
    if (p.seconds <= t) {
      process_counter++;
      time_counter += p.seconds;
      cout << p.name << ' ' << time_counter << ' ' << process_counter << endl;
      q.pop();
    }
    else {
      p.seconds -= t;
      time_counter += t;
      process_counter++;
      q.push(p);
      q.pop();
    }
  }
}