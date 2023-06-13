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
const ll NMAX = 1e5+10;
const ll MOD = 1e9+7;

ll add(ll x, ll y){
    return (x+y)%MOD;
}

string s;

struct Trie {
    bool esta;
    map<char,Trie> hijos;
    Trie(){
        esta = false;
    }
    void insertar(const string &inp, int i){
        if(i<SZ(inp)){
            hijos[inp[i]].insertar(inp,i+1);
        } else {
            esta = true;
        }
    }
};

Trie t;

ll dp[NMAX];

ll f(ll x){
    if(x == SZ(s)) return 1;
    if (dp[x]!=-1)return dp[x];
    ll res = 0;
    Trie t_aux = t;
    fore(i,x,SZ(s)){
        if(t_aux.hijos.count(s[i]) && t_aux.hijos[s[i]].esta){
            res = add(res, f(i+1));
            t_aux = t_aux.hijos[s[i]];
        } else if(t_aux.hijos.count(s[i])){
            t_aux = t_aux.hijos[s[i]];
        } else {
            break;
        }
    }
    dp[x]=res;
    return dp[x];
}

int main(){FIN;
    mset(dp,-1);
    cin >> s;
    ll n; cin >> n;
    fore(i,0,n){
        string aux; cin >> aux;
        t.insertar(aux,0);
    }
    cout << f(0) << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/