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
    ll N; cin >> N;
    vector<ll> a(N);
    fore(i,0,N) cin >> a[i];
    cout << a[0] << " ";
    fore(i,0,N-1){
        if(a[i] == a[i+1]+1 || a[i]==a[i+1]-1){
            cout << a[i+1] << " ";
            continue;
        }
        if(a[i+1]>a[i]){
            ll aux2 = a[i]+1;
            cout << aux2 << " ";
            while(aux2<a[i+1]){
                ++aux2;
                cout << aux2 << " ";
            }
        } else {
            ll aux2 = a[i]-1;
            cout << aux2 << " ";
            while(aux2>a[i+1]){
                --aux2;
                cout << aux2 << " ";
            }
        }
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/