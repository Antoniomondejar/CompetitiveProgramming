#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 1e4+10;
const ll MOD = 1e9+7;

ll trie[NMAX][26];
ll term[NMAX];
ll last_n;
ll cuan[NMAX];
pair<ll,char> pa[NMAX];

void add(string s){
    ll last_vertex = 0;
    fore(i,0,SZ(s)){
        if(trie[last_vertex][s[i]-'a']>=0){
            last_vertex = trie[last_vertex][s[i]-'a'];
        } else {
            trie[last_vertex][s[i]-'a']=last_n;
            pa[last_n]={last_vertex,s[i]};
            last_vertex = last_n;
            ++last_n;
        }
    }
    term[last_vertex]++;
}

ll g[NMAX][26];
ll l[NMAX];

ll go(ll x, char c);

ll link(ll x){
    // cout << link(pa[x].fst) << "\n";
    if(x==0)return 0;
    if(pa[x].fst==0)return 0;
    if(l[x]>=0)return l[x];
    return l[x]=go(link(pa[x].fst),pa[x].snd);
}

ll go(ll x, char c){
    // cout << x << " " << c << "\n";
    if(trie[x][c-'a']>=0) return trie[x][c-'a'];
    if(x==0) return 0;
    if(g[x][c-'a']>=0)return g[x][c-'a'];
    return g[x][c-'a']=go(link(x),c);
}

ll solve(string s){
    ll last_vertex=0;
    ll res = cuan[0];
    fore(i,0,SZ(s)){
        last_vertex=go(last_vertex,s[i]);
        res += cuan[last_vertex];
    }
    return res;
}

void bfs(ll x){
    queue<ll> q;q.push(x);
    while(SZ(q)){
        auto cv = q.front();q.pop();
        cuan[cv]=term[cv]+cuan[link(cv)];
        fore(i,0,26){
            if(trie[cv][i]>=0){
                q.push(trie[cv][i]);
            }
        }
    }
}

int main(){FIN;
    last_n=1;
    ll n,m;cin>>n>>m;
    mset(trie,-1);mset(g,-1);mset(l,-1);
    fore(i,0,n){
        string s;cin>>s;
        add(s);
    }
    string s;cin>>s;
    cuan[0]=term[0];
    bfs(0);
    // fore(i,0,last_n) cout << cuan[i] << " ";
    // cout << "\n";
    ll ans = solve(s);
    cout << ans << "\n";
    while(m--){
        ll pos;char c;cin>>pos>>c;--pos;
        string aux="", aux2="";
        fore(i,max(pos-103,0LL),min(pos+105,SZ(s))){
            aux += s[i];
            if(i==pos)aux2 +=c;
            else aux2 += s[i];
        }
        ll aux_solve = solve(aux);
        ans = ans-aux_solve+solve(aux2);
        cout << ans << "\n";
        s[pos]=c;
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/