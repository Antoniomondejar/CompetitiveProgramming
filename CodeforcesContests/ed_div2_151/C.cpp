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
const ll NMAX = 3e5+10;
const ll MOD = 1e9+7;

int dp[NMAX][11][11];
vector<int> restr[11];
string s,l,r; 
ll m;

int f(ll x, ll cont, ll l_d){
    if(x==SZ(s))return 1;
    int &res = dp[x][cont][l_d];
    if(res!=-1)return res;
    res = 0;
    // cout << s[x] << "\n";
    if((s[x]-'0')!=l_d) res = f(x+1,cont,l_d);
    else if(cont==m-1){
        res = 0;
    } else {
        fore(i,0,SZ(restr[cont+1])){
            res = res||f(x+1,cont+1,restr[cont+1][i]);
        }
    }
    // cout << x << " " << cont << " " << l_d << " " << res << "\n";
    return res;
}


int main(){FIN;
    ll t; cin >> t;
    while(t--){
        cin >> s;
        cin>>m>>l>>r;
        fore(i,0,SZ(s))fore(j,0,11)fore(z,0,11)dp[i][j][z]=-1;
        fore(i,0,m)restr[i].clear();
        bool p = true;
        fore(i,0,m){
            ll li = l[i]-'0', ri = r[i]-'0';
            if(li>ri){cout << "NO\n";p=false;break;}
            fore(j,li,ri+1){
                restr[i].pb(j);
            }
        }
        if(!p){continue;}
        bool res = false;
        fore(i,0,SZ(restr[0])){
            res = res||f(0,0,restr[0][i]);
        }
        if(res)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/