#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(int i=a,thxMat=b;i<thxMat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

vector<pair<ll,ll>> bs; 
ll cant_b;

ll dp[NMAX][2];

ll f(ll x, ll puedo){
    if(x==cant_b)return 0;
    ll &res = dp[x][puedo];
    if(res!=-1)return res;
    if(puedo){
        res = max(bs[x].fst+f(x+1,1),bs[x].snd+f(x+1,0));
    } else {
        res = bs[x].snd+f(x+1,0);
    }
    return res;
}


int main(){FIN;
    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        bs.clear();cant_b=0;
        ll cant_a=0;
        fore(i,0,SZ(s)){
            if(s[i]=='A'){
                ++cant_a;
            } else {
                if(cant_b>0){
                    bs.back().snd=cant_a;
                }
                ++cant_b;
                bs.pb({cant_a,0});
                cant_a=0;
            }
        }
        if(cant_b>0) bs.back().snd=cant_a;
        fore(i,0,cant_b)fore(j,0,2)dp[i][j]=-1;
        ll res = f(0,1);
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/