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
vector<pair<ll,ll>> v;

void bfs(vector<pair<ll,ll>> v){
    queue<pair<ll,ll>> b_q;
    fore(i,0,SZ(v)-1){
        b_q.push(v[i]);
        vis[v[i].fst][v[i].snd] = 1;
    }
    vis[v[SZ(v)-1].fst][v[SZ(v)-1].snd] = 2;
    b_q.push(v[SZ(v)-1]);
    while(SZ(b_q)){
        auto cv = b_q.front();
        b_q.pop();
        fore(i,0,SZ(g[cv.fst][cv.snd])){
            auto n = g[cv.fst][cv.snd][i];
            if(vis[n.fst][n.snd]) continue;
            vis[n.fst][n.snd] = (vis[cv.fst][cv.snd]==1)?1:2; b_q.push(n);
            ag[n.fst][n.snd] = cv;
        }
    }
}

int main(){
    ll n, m; cin >> n >> m;
    pair<ll,ll> a;
    fore(i,0,n) cin >> b[i];
    fore(i,0,n){
        fore(j,0,m){
            if(b[i][j] != '#'){
                if(i>0 && b[i-1][j] != '#') g[i][j].pb({i-1,j});
                if(i<n && b[i+1][j] != '#') g[i][j].pb({i+1,j});
                if(j>0 && b[i][j-1] != '#') g[i][j].pb({i,j-1});
                if(j<m && b[i][j+1] != '#') g[i][j].pb({i,j+1});
                if(b[i][j] == 'A') a = {i,j};
                else if(b[i][j] == 'M') v.pb({i,j});
            }
        }
    }
    v.pb(a);
    bfs(v);
    bool p = false; pair<ll,ll> f;
    fore(i,0,n) fore(j,0,m){
        if(i == 0 || j == 0 || j == m-1 || i == n-1){
            if(vis[i][j] == 2){
                p = true;
                f = {i,j};
                break;
            }
        }
    }
    if(!p){cout << "NO\n"; return 0;}
    string res = "";
    ll x_i = f.fst, y_i = f.snd; ll l = 0;
    while(x_i != a.fst || y_i != a.snd){
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

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/