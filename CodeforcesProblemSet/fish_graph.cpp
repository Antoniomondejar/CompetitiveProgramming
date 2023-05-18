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
const ll NMAX=2e3+10;

vector<ll> g[NMAX];
ll ag[NMAX];

pair<ll,ll> bfs(ll v, ll n){
    vector<ll> vis(n,0);
    vis[v] = 1;
    queue<pair<ll,ll>> b_q; b_q.push({v,0});
    while(SZ(b_q)){
        pair<ll,ll> cv = b_q.front();
        b_q.pop();
        for(auto i:g[cv.fst]){
            cout << i << " " << cv.fst << "\n";
            if(i == v && cv.snd > 1) return {1,i};
            if(vis[i]) continue;
            vis[i] = 1; ag[i] = cv.fst; b_q.push({i,cv.snd+1});
        }
    }
    return {0,0};
}



int main(){
    ll t; cin >> t;
    while(t--){
        ll n,m; cin >> n >> m;
        fore(i,0,m){
            ll x, y; cin >> x >> y; --x; --y;
            g[x].pb(y);
            g[y].pb(x);
        }
        pair<ll,ll> res = {0,0}; ll v;
        fore(i,0,n){
            if(SZ(g[i])>=4){
                res = bfs(i,n);
                if(res.fst == 1) {v = i;break;}
            }
        }
        if(res.fst == 0) {cout << "NO\n";continue;}
        vector<ll> v_vec(2); v_vec[0] = res.snd;
        vector<pair<ll,ll>> sg; sg.pb({v,res.snd});
        ll x_aux = res.snd, y_aux;
        while(x_aux != v){
            y_aux = ag[x_aux];
            sg.pb({x_aux,y_aux});
            if(y_aux == v) v_vec[1] = x_aux;
            x_aux = y_aux;
        }
        ll k = 0;
        fore(i,0,4){
            if(g[v][i] != v_vec[0] && g[v][i] != v_vec[1]){
                sg.pb({g[v][i],v});
                ++k;
            }
            if(k==2) break;
        }
        cout << "YES\n";
        for(auto i:sg){
            cout << i.fst+1 << " " << i.snd+1 << "\n";
        }
        cout << "\n";
    }
    return 0;
}