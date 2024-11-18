#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int points{0};
    int goals{0};
    string team;
} league;

bool compareTeams(const league & p1, const league & p2){
    if (p1.points < p2.points) return true;
    if (p1.points > p2.points) return false;
    if (p1.goals < p2.goals) return true;
    if (p1.goals > p2.goals) return false;
    return p1.team > p2.team;
}

int point_counter(int wins, int draws, int losses){
    return ((wins * 3) + draws);
}

int goal_counter(int goals_scored, int goals_against){
    return goals_scored - goals_against;
}

int main(){
    int n;
    cin >> n;
    vector<league> v(n);
    for(int i = 0; i < n; i++){
        int w, d, l, gs, ga;
        cin >> v[i].team >> w >> d >> l >> gs >> ga;
        v[i].points = point_counter(w, d, l);
        v[i].goals = goal_counter(gs, ga);
    }
    sort(v.begin(), v.end(), compareTeams);
    for(int j = 1; j <= n; j++){
        cout << v[n-j].team << " " << v[n-j].points << " " << v[n-j].goals << endl;
    }
    return 0;
}