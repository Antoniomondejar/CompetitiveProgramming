#include <bits/stdc++.h>
using namespace std;
#define NMAX 50000

int comparator(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}


int main(void){
    int t;
    map<int,int> hola;
    cin >> t;
    pair<int,int> participants[NMAX+1];
    for(int i = 0; i <= NMAX; ++i)
        participants[i] = make_pair(0,NMAX+1);
    while(t--){
        int m, ni, participant;
        cin >> m;
        int winners[m];
        bool is_possible = true;
        for(int i = 1; i <= m; ++i){
            cin >> ni;
            for(int j = 0; j < ni; ++j){
                cin >> participant;
                participants[participant] = make_pair(participant,i);
            }
        }
        sort(participants, participants+NMAX+1, &comparator);
        int j = 0;
        for(int i = 1; i <= m; ++i){
            while(j < NMAX+1 && participants[j].second < i)
                ++j;
            if(j < NMAX+1 && participants[j].second == i){
                winners[i-1] = participants[j].first;
            } else {
                is_possible = false;
                break;
            }
        }
        if (is_possible){
            for(int i = 0; i < m; ++i){
                cout << winners[i] << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
        int i = 0;
        while(participants[i].second != NMAX+1){
            participants[i] = make_pair(0,NMAX+1);
            ++i;
        }
    }
    return 0;
}