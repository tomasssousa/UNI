#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int points{0};
    int goals{0};
    string teams;
} league;

bool compareTeams(const league& p1, const league& p2){
    if(p1.points > p2.points) return true;
    if(p1.points < p2.points) return false;
    if(p1.goals > p2.goals) return true;
    if(p1.goals < p2.goals) return false;
    return p1.teams < p2.teams;
}

int main(){
    int n;
    cin >> n;
    vector<league> s(n);
    for(int i = 0; i < n; i++){
        int w, d, l, gs, ga;
        cin >> s[i].teams >> w >> d >> l >> gs >> ga;
        s[i].points = (3 * w) + d;
        s[i].goals = gs - ga;
    }
    sort(s.begin(), s.end(), compareTeams);
    for(int j = 0; j < n; j++){
        cout << s[j].teams << " " << s[j].points << " " << s[j].goals << endl;
    }
    return 0;
}