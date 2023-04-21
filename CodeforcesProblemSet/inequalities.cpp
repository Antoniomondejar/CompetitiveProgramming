#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
    ll N; cin >> N;
    string sgns = ""; char inp;
    fore(i,0,N){
        cin >> inp;
        sgns+=inp;
    }
    cout << sgns << "\n";
    pair<ll,ll> after[N+1]; set<ll> nmbs; fore(i,1,N+2) nmbs.insert(i);
    after[N] = {0,0};
    fore(i,0,N){
        after[N-1-i] = mp(after[N-i].fst+(sgns[N-1-i]=='>'?1:0), after[N-i].snd+(sgns[N-1-i]=='>'?0:1));
    }
    fore(i,0,N){
        ll prnt = (N+2)/2 - after[i].snd;
        cout << prnt << " ";
        nmbs.erase(prnt);
    }
    cout << *nmbs.begin() << "\n";
    return 0;
}