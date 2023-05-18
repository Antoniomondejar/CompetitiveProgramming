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
    ll n; cin >> n; ll b = 0;
    while(n){
        ++b;
        if(n>=100)n-=100;
        else if(n>=20)n-=20;
        else if(n>=10)n-=10;
        else if(n>=5)n-=5;
        else n-=1;
    }
    cout << b << "\n";
    return 0;
}