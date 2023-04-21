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
        string s; cin >> s;
        if(s[0]=='0') {cout << 0 << "\n";continue;}
        ll p = s[0]=='?'?9:1;
        fore(i,1,s.length())
            p *= (s[i]=='?'?10:1);
        cout << p << "\n";
    }
    return 0;
}