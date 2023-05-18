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
const ll NMAX=1e3+10;

ll a[NMAX][NMAX];
bool g[NMAX][NMAX][4]; 
ll vis[NMAX][NMAX];
vector<pair<ll,ll>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};

ll bfs(pair<ll,ll> v){
    queue<pair<ll,ll>> b_q;
    vis[v.fst][v.snd] = 1;
    b_q.push(v);
    ll res = a[v.fst][v.snd];
    while(SZ(b_q)){
        auto cv = b_q.front();
        b_q.pop();
        fore(i,0,4){
            if(!g[cv.fst][cv.snd][i]) continue;
            pair<ll,ll> n = {cv.fst+moves[i].fst, cv.snd+moves[i].snd};
            if(vis[n.fst][n.snd]) continue;
            vis[n.fst][n.snd] = 1;
            res += a[n.fst][n.snd]; b_q.push(n);
        }
    }
    return res;
}

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        fore(i,0,n) fore(j,0,m){
            cin >> a[i][j];
            vis[i][j] = 0; g[i][j][0] = 0;
            g[i][j][1] = 0; g[i][j][2] = 0;
            g[i][j][3] = 0;
        } 
        fore(i,0,n) fore(j,0,m) {
            if(a[i][j] == 0) continue;
            if(i>0 && a[i-1][j] != 0) g[i][j][0] = 1;
            if(i<n && a[i+1][j] != 0) g[i][j][1] = 1;
            if(j>0 && a[i][j-1] != 0) g[i][j][2] = 1;
            if(j<m && a[i][j+1] != 0) g[i][j][3] = 1; 
        }
        ll max_res = 0;
        fore(i,0,n) fore(j,0,m){
            if(!vis[i][j]){
                max_res = max(max_res, bfs({i,j}));
            }
        }
        cout << max_res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/