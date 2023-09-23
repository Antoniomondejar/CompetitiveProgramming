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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

ll dp[NMAX][5][2];
map<ll,ll> nms;
map<char,ll> con;
string s;

ll f(ll x, ll m_c, ll cambie){
    if(x==-1)return 0;
    if(dp[x][m_c][cambie] != 1e18) return dp[x][m_c][cambie];
    ll &res =  dp[x][m_c][cambie];
    res = 0;
    if(cambie && con[s[x]]>=m_c){
        res = nms[con[s[x]]]+f(x-1,con[s[x]],cambie);
    } else if (cambie && con[s[x]]<m_c){
        res = -nms[con[s[x]]]+f(x-1,m_c,cambie);
    } else if(con[s[x]]>=m_c){
        res = nms[con[s[x]]]+f(x-1,con[s[x]],cambie);
        fore(i,0,m_c){
            res = max(res, -nms[i]+f(x-1,m_c,1));
        }
        fore(i,m_c,5){
            if(i==con[s[x]])continue;
            res = max(res,nms[i]+f(x-1,i,1));
        }
    } else {
        res = -nms[con[s[x]]]+f(x-1,m_c,cambie);
        fore(i,0,m_c){
            if(i==con[s[x]])continue;
            res = max(res,-nms[i]+f(x-1,m_c,1));
        }
        fore(i,m_c,5){
            res = max(res,nms[i]+f(x-1,i,1));
        }
    }
    // cout << x << " " << m_c << " " << cambie << " " << res << "\n";
    return res;
}

int main(){FIN;
    nms[0]=1; nms[1]=10;nms[2]=100;nms[3]=1000;nms[4]=10000;
    con['A']=0;con['B']=1;con['C']=2;con['D']=3;con['E']=4;
    ll t; cin >> t;
    fore(i,0,NMAX)fore(j,0,5)fore(z,0,2)dp[i][j][z]=1e18;
    while(t--){
        cin>>s;
        if(SZ(s)==1){cout<<"10000\n";continue;}
        ll res = f(SZ(s)-1,0,0);
        cout << res << '\n';
        fore(i,0,SZ(s))fore(j,0,5)fore(z,0,2)dp[i][j][z]=1e18;
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/