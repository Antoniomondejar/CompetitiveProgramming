#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
#define str string
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
    ll L, N1, N2, el, tim;
    cin >> L >> N1 >> N2;
    ll a[2][L];
    ll last = 0;
    fore(i,0,N1){
        cin >> el >> tim;
        fore(j,last,last+tim) a[0][j] = el;
        last += tim;
    }
    last = 0;
    fore(i,0,N2){
        cin >> el >> tim;
        fore(j,last,last+tim) a[1][j] = el;
        last += tim;
    }
    ll count = 0;
    fore(i,0,L){
        count += (a[0][i] == a[1][i]);
    }
    cout << count << "\n";
    return 0;
}