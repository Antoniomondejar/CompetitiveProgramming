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

ll n;
ll a[NMAX], d[NMAX];

bool can(ll me){
    priority_queue<pair<ll,ll>> q;
    vector<vector<pair<ll,ll>>> inter(n);
    vector<ll> cuan(n);
    fore(i,0,n){
        if(a[i]==0)continue;
        inter[max(0LL,i-d[i])].pb({-min(n-1,i+d[i]),a[i]});
    }
    fore(i,0,n){
        fore(j,0,SZ(inter[i])){
            q.push(inter[i][j]);
        }
        while(SZ(q)>0 && cuan[i]<me){
            auto pri = q.top();q.pop();
            if(-(pri.fst)<i)return false;
            ll cua = pri.snd;
            if(cua>me-cuan[i]){
                cua -= me-cuan[i];
                cuan[i]=me;
                q.push({pri.fst,cua});
            } else {
                cuan[i]+=cua;
            }
        }
    }
    if(SZ(q)>0)return false;
    return true;
}

int main(){FIN;
    cin>>n;
    fore(i,0,n)cin>>a[i];
    fore(i,0,n)cin>>d[i];
    ll l=0,r=1e9+10;
    while(l<=r){
        ll me=(l+r)/2;
        if(can(me)) r=me-1;
        else l=me+1;
    }
    cout << l << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/