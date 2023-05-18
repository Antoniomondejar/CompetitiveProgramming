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
    ll n,q; cin >> n >> q;
    vector<ll> a(n);
    ll sum = 0;
    fore(i,0,n)cin >> a[i],sum+=a[i];
    sort(ALL(a));
    while(q--){
        ll k; cin >> k;
        auto a_aux(a); ll sum_aux = sum;
        ll s_s = min(k,n-(n%2!=k%2));
        fore(i,0,s_s){
            a_aux[i]+= k-i;
            sum_aux+=k-i;
        }
        k = (k-s_s)/2;
        ll min_a = a_aux[0];
        fore(i,1,n)min_a = min(min_a,a_aux[i]);
        k-=(sum_aux-n*min_a);
        if(k>0)
            cout << min_a-(k+n-1)/n << " ";
        else
            cout << min_a << " ";
    }
    cout << "\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/