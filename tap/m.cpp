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

#define EPS 1e-4

int main(){FIN;
    ll n,t;cin>>n>>t;
    vector<ll> ps;
    vector<ll> ns;
    fore(i,0,n){
        char ty;ll x;cin>>ty>>x;
        if(ty=='P'){
            ps.pb(x);
        } else {
            ns.pb(x);
        }
    }
    priority_queue<pair<double,ll>> pq;
    set<pair<double,ll>> pri, n_pri;
    fore(i,0,SZ(ps)){
        pri.insert({ps[i],i});
    }
    fore(i,0,SZ(ns)){
        n_pri.insert({ns[i],i});
    }
    ll as_p = 0, as_np = 0;
    ll it = 0;
    while(it < n){
        if(SZ(n_pri)>0 && SZ(pri)>0){
            as_p = t*3/(4*SZ(pri));
            as_np = t/(4*SZ(n_pri));
            for(auto i:pri){
                pq.push({-i.fst/as_p,i.snd});
            }
            for(auto j:n_pri){
                pq.push({-j.fst/as_np,j.snd});
            }
            auto t_m = pq.top();
            fore(i,0,SZ(ps)){
                
            }
        } else if(SZ(n_pri)>0){

        } else {

        }
    }
    return 0;
}