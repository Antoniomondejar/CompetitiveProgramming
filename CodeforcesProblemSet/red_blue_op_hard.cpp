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
    vector<ll> a_aux(n),min_p(n);
    fore(i,0,n) a_aux[i] = a[i]-i;
    min_p[0] = a_aux[0];
    fore(i,1,n) min_p[i] = min(a_aux[i],min_p[i-1]); //prefix_min
    while(q--){
        ll k; cin >> k;
        ll sum_aux = sum;
        ll s_s = min(k,n-(n%2!=k%2));
        sum_aux += s_s*k-(s_s*(s_s-1)/2);
        ll min_a;
        if(s_s<n)
            min_a = min(min_p[s_s-1]+k,a[s_s]);
        else
            min_a = min_p[s_s-1]+k;
        k = (k-s_s)/2;
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