#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int ) x.size())
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mst(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll cua(ll x){
    return x*x;
}


int main(){FIN;
    ll n;cin>>n;
    ll w,l,xt,yt;cin>>w>>l>>xt>>yt;
    set<pair<ll,ll>> dis;
    fore(i,0,n){
        ll x,y;cin>>x>>y;
        ll dist = abs(xt-x)*abs(xt-x)+abs(yt-y)*abs(yt-y);
        dis.insert({cua(dist),0});
    }
    fore(i,0,n){
        ll x,y;cin>>x>>y;
        ll dist = abs(xt-x)*abs(xt-x)+abs(yt-y)*abs(yt-y);
        dis.insert({cua(dist),1});
    }
    ll res = 0;
    ll quien = -1;
    for(auto i:dis){
        if(quien ==-1){
            quien = i.snd;
        }
        if(i.snd != quien)break;
        res++;
    }
    if(quien){
        cout << 'R' << " " << res << "\n";
    } else {
        cout << 'A' << " " << res << "\n";
    }
    return 0;       
}