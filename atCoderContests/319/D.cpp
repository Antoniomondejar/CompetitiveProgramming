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

ll ls[NMAX];
ll m,n;

bool can(ll me){
    ll cant = 1; ll cant_en_este = 0;
    fore(i,0,n){
        if(cant>m)return false;
        if(ls[i]>me)return false;
        if(ls[i]+cant_en_este>me){
            ++cant;
            cant_en_este = ls[i]+1;
        } else {
            cant_en_este += ls[i]+1;
        }
    }
    return cant <= m;
}


int main(){FIN;
    cin>>n>>m;
    fore(i,0,n)cin>>ls[i];
    ll l = 1, r = 1e15;
    while(l<=r){
        ll me=(l+r)/2;
        if(can(me)) r = me-1;
        else l = me+1;
    }
    cout << l << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/