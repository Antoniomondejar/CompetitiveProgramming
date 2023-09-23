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

int main(){FIN;
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> a(n);
        map<ll,ll> cuan,cuan2;
        fore(i,0,n)cin>>a[i],cuan[a[i]]++;
        for(int i = n-1;i>=0;--i){
            if(i==n-1){
                cuan2[i+1]=a[i];
            } else {
                if(a[i+1]-a[i]==0)continue;
                cuan2[i+1]=a[i]-a[i+1];
            }
        }
        // fore(i,0,SZ(esp)) cout << esp[i] << " ";
        // cout << "\n";
        bool p = true;
        for(auto i:cuan){
            if(!cuan2.count(i.fst)){p=false;break;}
            if(cuan2[i.fst]!=i.snd){p=false;break;}
        }
        for(auto i:cuan2){
            if(!cuan.count(i.fst)){p=false;break;}
            if(cuan[i.fst]!=i.snd){p=false;break;}
        }
        if(p)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/