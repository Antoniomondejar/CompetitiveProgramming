#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v)sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<ll> vvl;

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string s; cin >> s;
        bool h_p = false, h_i = false;
        fore(i,0,SZ(s)){
            if(i%2==0 && (s[i]-'0')&1)h_i = true;
            if(i&1 && (s[i]-'0')%2==0)h_p=true;
        }
        if(n&1 && h_i)cout << "1\n";
        else if(n&1)cout << "2\n";
        else if(n%2==0 && h_p) cout << "2\n";
        else cout << "1\n";
    }
    return 0;
}