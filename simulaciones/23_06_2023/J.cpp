#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v)sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vvl;

int main(){FIN;
    ll n,m,k; cin >> n >> m>>k;
    map<ll,vector<ll>> pos;
    fore(i,0,n){
        ll inp; cin >> inp;
        pos[inp].pb(i);
    }
    ll res = 1;
    for(auto &i:pos){
        ll col = i.fst; vector<ll> &posi = i.snd;
        ll l = 0; ll tam_actual = 0; ll r = 1; bool cre = false;
        while(l<SZ(posi) && r<SZ(posi)){
            if(l==r)++r;
            if(tam_actual+posi[r]-posi[r-1]-1>k){
                if(cre)res = max(res,r-l);
                if(l+1<r)
                    tam_actual -= posi[l+1]-posi[l]-1;
                ++l;
                cre=false;
            } else {
                cre=true;
                tam_actual+=posi[r]-posi[r-1]-1;
                ++r;
            }
        }
        if(cre)res=max(res,r-l);
    }
    cout << res << "\n";
    return 0;
}