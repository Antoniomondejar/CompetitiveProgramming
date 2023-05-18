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
pair<ll,ll> ag[NMAX][NMAX];

bool bfs(ll vx, ll vy){
    queue<pair<ll,ll>> b_q;
    b_q.push({vx,vy});
    vis[vx][vy] = 1;
    bool p = false;
    while(SZ(b_q)){
        auto cv = b_q.front();
        b_q.pop();
        fore(i,0,SZ(g[cv.fst][cv.snd])){
            auto n = g[cv.fst][cv.snd][i];
            if(vis[n.fst][n.snd] == 1) continue;
            ag[n.fst][n.snd] = cv;
            if(b[n.fst][n.snd] == 'B'){
                p = true;
                break;
            }
            vis[n.fst][n.snd] = 1; b_q.push(n);
        }
        if(p) break;
    }
    return p;
}

int main(){
    ll n, m; cin >> n >> m;
    ll x_a, y_a, x_b, y_b;
    fore(i,0,n) cin >> b[i];
    fore(i,0,n){
        fore(j,0,m){
            if(b[i][j] == '.' || b[i][j] == 'A' || b[i][j] == 'B'){
                if(i>0 && (b[i-1][j] == '.' || b[i-1][j] == 'A' || b[i-1][j] == 'B')) g[i][j].pb({i-1,j});
                if(i<n && (b[i+1][j] == '.' || b[i+1][j] == 'A' || b[i+1][j] == 'B')) g[i][j].pb({i+1,j});
                if(j>0 && (b[i][j-1] == '.' || b[i][j-1] == 'A' || b[i][j-1] == 'B')) g[i][j].pb({i,j-1});
                if(j<m && (b[i][j+1] == '.' || b[i][j+1] == 'A' || b[i][j+1] == 'B')) g[i][j].pb({i,j+1});
                if(b[i][j] == 'A') x_a = i, y_a = j;
                if(b[i][j] == 'B') x_b = i, y_b = j;
            }
        }
    }
    bool p = bfs(x_a, y_a);
    string res = "";
    if(!p){cout << "NO\n"; return 0;}
    ll x_i = x_b, y_i = y_b; ll l = 0;
    while(x_i != x_a || y_i != y_a){
        ++l;
        ll x_aux = ag[x_i][y_i].fst;
        ll y_aux = ag[x_i][y_i].snd;
        if(x_aux == x_i+1) res += 'U';
        else if(x_aux == x_i-1) res += 'D';
        else if(y_aux == y_i+1) res += 'L';
        else res += 'R';
        x_i = x_aux;
        y_i = y_aux;
    }
    cout << "YES\n" << l << "\n";
    fore(i,0,l){
        cout << res[l-1-i];
    }
    cout << "\n";
    return 0;
}