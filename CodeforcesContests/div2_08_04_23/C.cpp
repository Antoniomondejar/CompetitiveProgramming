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
        ll n, m, d, dant; cin >> n >> m;
        cout << "? 1 1" << endl;
        cin >> d; if(!d){cout << "! 1 1" << endl;continue;}
        bool r = d+1>n;
        pair<ll,ll> p = {min(n,1+d), min(m,1+d)};
        cout << "? " << p.fst << " " << p.snd << endl;
        cin >> d; if(!d){cout << "! " << p.fst << " " << p.snd << endl; continue;}
        if(!r){
            p.fst -= d;
            dant = d;
            cout << "? " << p.fst << " " << p.snd << endl;
            cin >> d;
            if(!d) cout << "! " << p.fst << " " << p.snd << endl;
            else cout << "! " << p.fst+dant << " " << p.snd-dant << endl;
        } else {
            p.snd -= d;
            dant = d;
            cout << "? " << p.fst << " " << p.snd << endl;
            cin >> d;
            if(!d) cout << "! " << p.fst << " " << p.snd << endl;
            else cout << "! " << p.fst-dant << " " << p.snd+dant << endl;
        }
    }
    return 0;
}