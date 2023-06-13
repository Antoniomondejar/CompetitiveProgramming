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
const ll NMAX = 2e5+10;
const ll MOD = 1e9+7;

ll st[19][NMAX];
ll a[NMAX];
ll p2[19];


int main(){FIN;
    p2[0]=1;
    fore(i,1,19)p2[i]=p2[i-1]*2;
    ll n,q;cin>>n>>q;
    fore(i,0,n)cin>>a[i];
    fore(i,0,n)st[0][i]=a[i];
    fore(i,1,19){
        fore(j,0,n){
            if(j+(1<<(i-1))>=n)continue;
            st[i][j]=min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    ll q1,q2;
    while(q--){
        cin >> q1 >> q2; --q1; --q2;
        ll ma_k = 18; ll res = 1e10;
        if(q1==q2) {cout << a[q2] << "\n";continue;}
        while(ma_k >= 0 && q1<=q2){
            if(p2[ma_k]-1+q1>q2){
                ma_k--;
                continue;
            } else {
                res = min(res, st[ma_k][q1]);
                q1 = q1+p2[ma_k];
                --ma_k;
            }
        }
        cout << res << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/