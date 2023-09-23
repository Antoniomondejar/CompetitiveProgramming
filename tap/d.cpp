#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int ) x.size())
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll NMAX = 1e5+10;

ll k;
ll c[NMAX];
ll p[NMAX];

bool can(ll me) {
    ll extra = 0;

    fore(i, 0, k) {
        extra += p[i];
        if (c[i]*me > extra) {
            return false;
        }
        extra -= c[i]*me;
    }

    return true;
}



/*     vector<ll> cuan(k);
    fore(i,0,k){
        cuan[i]=c[i]*me;
    }
    priority_queue<ll> pq;
    for(int i=k-1;i>=0;--i){
        if(cuan[i]>0) pq.push(cuan[i]);
        ll aux = p[i];
        while(aux>0 && SZ(pq)){
            ll pri = pq.top();pq.pop();
            if(pri>aux){
                pri-=aux;
                pq.push(pri);
                aux=0; 
            } else {
                aux-=pri;
            }
        }
    }
    return SZ(pq)==0;
} */


int main(){FIN;
    cin>>k;
    fore(i,0,k) cin>>c[i];
    fore(i,0,k) cin>>p[i];
    ll lower = 0, upper = 1e16;
    while (lower + 1 < upper) {
        ll m = (lower + upper)/2;
        if(!can(m)) {
            upper = m;
        } else {
            lower = m;
        }
    }
    cout << upper - 1 << "\n";
    return 0;
}
