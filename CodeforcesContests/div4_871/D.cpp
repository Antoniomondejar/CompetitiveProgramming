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
        ll n,m; cin >> n >> m;
        if(m>n){cout << "NO\n";continue;}
        if(n==m) {cout << "YES\n";continue;}
        if(n%3!=0){cout << "NO\n"; continue;}
        queue<ll> l;
        l.push(n);
        bool p = false;
        while(SZ(l)){
            auto c = l.front();
            l.pop();
            if(c%3!=0) continue;
            if(2*c/3 == m || c/3 == m){
                cout << "YES\n";
                p = true;
                break;
            }
            l.push(2*c/3);l.push(c/3);
        }
        if(!p) cout << "NO\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/