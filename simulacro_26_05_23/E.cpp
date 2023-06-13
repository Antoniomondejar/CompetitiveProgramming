// 1 0 0
// 1 1 0
// 1 1 1
// 1 0 1
// 1 1 1
// 1 1 0

// -> 1 1 0 0
// 0 1 1 0
// 0 0 1 1
// 1 0 0 1 
// 0 0 1 1
// 0 0 x x
// 1 0 0
// 0 1 0

// 0 0 0 x
// 1 1 1 0
// 0 0 0 1

// 1 -1 -1
// -1 1 1
// 1

// 1 1 0 1
// 0 1 1 0
// 1 0 0 1
// 0 0 1 0



// 0 0 0

// 1 1 1

// 1 0 0
// 0 1 0
// 0 0 1

// 0 0 1 1
// 0 0 1 1

// 1 1 0
// 0 0 x

#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void){FIN;
    ll n,k;cin>>n>>k;
    set<vector<ll>> ls;
    fore(i,0,n){
        vector<ll> aux;
        fore(j,0,k){
            ll x; cin >> x; aux.pb(x);
        }
        ls.insert(aux);
    }
    bool p = true;
    for(auto e:ls){
        for(auto j:ls){
            p=true;
            fore(i,0,SZ(e)){
                if(e[i]==1) {
                    p=p&&(j[i]==0);
                }
            }
            if(p)break;
        }
        if(p)break;
    }
    if(p) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}







/*




*/

