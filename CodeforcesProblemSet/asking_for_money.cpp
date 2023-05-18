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
const ll NMAX = 1e4+10;

ll p[NMAX];
ll g[NMAX][2];
ll sp[NMAX];

void bfs(ll v, ll N){
    queue<ll> b_q; vector<ll> vis(N,0);
    vis[v] = 1;
    b_q.push(v);
    while(SZ(b_q)){
        ll cv = b_q.front();
        b_q.pop();
        fore(i,0,2){
            ll n = g[cv][i];
            ++sp[n];
            if(vis[n]) continue;
            b_q.push(n); vis[n] = 1; 
        }
    }
}

int main(){FIN;
    ll N; cin >> N;
    fore(i,0,N){
        cin >> g[i][0]; --g[i][0];
        cin >> g[i][1]; --g[i][1];
    }
    fore(i,0,N){
        bfs(i,N);
        fore(i,0,N){
            if(sp[i]>=3) p[i] = 1;
            sp[i] = 0;
        }
    }
    fore(i,0,N){
        if(p[i]) cout << "Y";
        else cout << "N";
    }
    cout << "\n";
    return 0;
}