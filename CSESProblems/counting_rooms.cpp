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

vector<pair<ll,ll>> g[NMAX][NMAX];
ll vis[NMAX][NMAX];
string b[NMAX];

void bfs(ll vx, ll vy){
    queue<pair<ll,ll>> b_q;
    b_q.push({vx,vy});
    vis[vx][vy] = 1;
    while(SZ(b_q)){
        auto cv = b_q.front();
        b_q.pop();
        fore(i,0,SZ(g[cv.fst][cv.snd])){
            auto n = g[cv.fst][cv.snd][i];
            if(vis[n.fst][n.snd] == 1) continue;
            vis[n.fst][n.snd] = 1; b_q.push(n);
        }
    }
}

int main(){
    ll n, m; cin >> n >> m;
    vector<pair<ll,ll>> p;
    fore(i,0,n) cin >> b[i];
    fore(i,0,n){
        fore(j,0,m){
            if(b[i][j] == '.'){
                if(i>0 && b[i-1][j] == '.') g[i][j].pb({i-1,j});
                if(i<n && b[i+1][j] == '.') g[i][j].pb({i+1,j});
                if(j>0 && b[i][j-1] == '.') g[i][j].pb({i,j-1});
                if(j<m && b[i][j+1] == '.') g[i][j].pb({i,j+1});
                p.pb({i,j});
            }
        }
    }
    ll cant = 0;
    fore(i,0,SZ(p)){
        if(!vis[p[i].fst][p[i].snd]){
            ++cant;
            bfs(p[i].fst, p[i].snd);
        }
    }
    cout << cant << "\n";
    return 0;
}