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

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> p(n);
        fore(i,0,n)cin>>p[i];
        if(n==1){cout << "1\n";continue;}
        ll fist = p[0]; ll pos_m = 0;
        if(fist == n){
            fore(i,1,n){
                if(p[i]==n-1){pos_m = i; break;}
            }
        } else {
            fore(i,1,n){
                if(p[i]==n){pos_m = i; break;}
            }
        }
        ll l, r;
        if(pos_m == n-1){
            r = n-1; l = n-1;
            fore(i,0,n-1){
                if(p[0]>p[n-2-i])break;
                else --l;
            }
            for(int i = n-1; i>=l; --i){
                cout << p[i] << " ";
            }
            fore(i,0,l) cout << p[i] << " ";
        } else {
            r = pos_m-1; l = pos_m-1;
            fore(i,0,r){
                if(p[0]>p[r-i-1])break;
                else --l;
            }
            fore(i,pos_m,n) cout << p[i] << " ";
            for(int i = r; i>=l; i--) cout << p[i] << " ";
            fore(i,0,l) cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/