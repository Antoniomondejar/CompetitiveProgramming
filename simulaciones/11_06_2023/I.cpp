#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a, ggdem=b; i<ggdem; ++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void){FIN;
    ll n,k; cin >> n >> k;
    map<ll,vector<ll>> nms;
    fore(i,0,n){
        ll inp; cin >> inp;
        nms[inp].pb(i);
    }
    vector<ll> posi(n,-1);
    ll res = 0;
    for(auto i:nms){
        vector<ll> pos = i.second;
        if(SZ(pos)<k)continue;
        sort(ALL(pos));
        ll aux = SZ(pos)-k+1;
        fore(i,0,aux){
            ll f_pos = pos[k+i-1];
            res += n-f_pos;
            posi[pos[i]] = f_pos;
        }
    }
    bool f = false; ll l_po = n;
    for(int i = n-1; i>=0; --i){
        if(posi[i]>=0){
            if(l_po<posi[i]){
                res += posi[i]-l_po;
            }
            l_po = min(l_po,posi[i]);
            f = true;
        } else if(f && posi[i]<0){
            res += n-l_po;
        }
    }
    cout << res << "\n";
    return 0;
}