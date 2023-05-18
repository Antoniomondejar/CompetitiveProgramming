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

const ll MAXN = 1000+10;

bool p[MAXN][MAXN][4];
bool vis[MAXN][MAXN];
pair<ll,ll> g[MAXN][MAXN][4];

ll bfs(ll vx, ll vy){
    vis[vx][vy] = true;
    ll c = 1; queue<pair<ll,ll>> b_q;
    b_q.push({vx,vy});
    while(SZ(b_q)){
        auto v = b_q.front();
        b_q.pop();
        ll d = 4;
        fore(i,0,d){
            auto n = g[v.fst][v.snd][i];
            if(n.fst == -1 || vis[n.fst][n.snd]) continue;
            ++c; b_q.push(n);
            vis[n.fst][n.snd] = true;
        }
    }
    return c;
}

int main(){FIN;
    fore(i,0,MAXN)
        fore(j,0,MAXN) {
            p[i][j][0] = true; // {arriba, abajo, derecha, izq}
            p[i][j][1] = true; p[i][j][2] = true; p[i][j][3] = true;
            g[i][j][0] = {-1,-1}; g[i][j][1] = {-1,-1}; g[i][j][2] = {-1,-1}; g[i][j][3] = {-1,-1};
            vis[i][j] = false;
        }
    ll N, x0, y0, xi, yi; cin >> N >> x0 >> y0;
    fore(i,0,N){
        cin >> xi >> yi;
        if(yi == y0){
            ll m = min(x0,xi);
            fore(i,m,max(x0,xi)){
                p[i][y0][1] = false;
                p[i][y0-1][0] = false;
            }
        } else {
            ll m = min(y0, yi);
            fore(i,m,max(yi,y0)){
                p[x0][i][3] = false;
                p[x0-1][i][2] = false;
            }
        }
        x0 = xi;
        y0 = yi;
    }
    fore(i,0,MAXN-1){
        fore(j,0,MAXN-1){
            if(i>0 && p[i][j][3]) g[i][j][3] = {i-1,j};
            if(i<MAXN-1 && p[i][j][2]) g[i][j][2] = {i+1,j};
            if(j>0 && p[i][j][1]) g[i][j][1] = {i,j-1};
            if(j<MAXN-1 && p[i][j][0]) g[i][j][0] = {i,j+1};
        }
    }
    bfs(0,0);
    ll ma = 0;
    fore(i,0,MAXN){
        fore(j,0,MAXN){
            if(!vis[i][j]){
                ll res = bfs(i,j);
                ma = max(ma,res);
            }
        }
    }
    cout << ma << "\n";
    return 0;
}