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

vector<vector<ll>> g(2005);
vector<ll> d(2005,-1);
vector<ll> np(2005, 0);

queue<ll> bfs(ll v){
    queue<ll> res;
    if(d[v] == 0){res.push(v); return res;}
    else np[v] = 1;
    vector<ll> vis(2005,0);
    vis[v] = 1;
    queue<pair<ll,ll>> b_q;
    b_q.push({v,0});
    pair<ll,ll> n, c;
    while(SZ(b_q)){
        c = b_q.front();
        b_q.pop();
        fore(i,0,SZ(g[c.fst])){
            n = {g[c.fst][i], c.snd+1};
            if(vis[n.fst]) continue;
            vis[n.fst] = 1;
            if(n.snd < d[v]) {np[n.fst] = 1; b_q.push(n);}
            else if (n.snd == d[v]) res.push(n.fst);
        }
    }
    return res;
}

int main(){FIN;
    ll N, M, inp1, inp2, K; cin >> N >> M;
    fore(i,0,M){
        cin >> inp1 >> inp2; --inp1; --inp2;
        g[inp1].pb(inp2);
        g[inp2].pb(inp1);
    }
    cin >> K;
    vector<pair<queue<ll>,ll>> k_s(K);
    fore(i,0,K){
        cin >> inp1 >> inp2; --inp1;
        d[inp1] = inp2;
        k_s[i].snd = inp1;
    }
    bool p = false;
    fore(i,0,K){
        k_s[i].fst = bfs(k_s[i].snd);
    }
    set<ll> b_vs;
    fore(i,0,K){
        p = false;
        while(SZ(k_s[i].fst)){
            ll v = k_s[i].fst.front();
            k_s[i].fst.pop();
            if(!np[v]){
                b_vs.insert(v);
                p = true;
            }
        }
        if(!p){cout << "No\n"; return 0;}
    }
    if(K==0) b_vs.insert(0);
    cout << "Yes\n";
    fore(i,0,N){
        if(b_vs.count(i)){
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << "\n";
    return 0;
}