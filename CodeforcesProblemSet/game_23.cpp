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

int main(){FIN;
    ll n,m;cin>>n>>m;
    ll cant_2_n = 0, cant_2_m = 0,cant_3_n=0, cant_3_m=0;
    ll n_aux = n, m_aux = m;
    while(n_aux%2==0){
        cant_2_n++;
        n_aux/=2;
    }
    while(n_aux%3==0){
        cant_3_n++;
        n_aux/=3;
    }
    while(m_aux%2==0){
        cant_2_m++;
        m_aux/=2;
    }
    while(m_aux%3==0){
        cant_3_m++;
        m_aux/=3;
    }
    if(cant_2_n>cant_2_m || cant_3_n>cant_3_m){cout << "-1\n";return 0;}
    fore(i,0,cant_2_m-cant_2_n){
        n*=2;
    }
    fore(i,0,cant_3_m-cant_3_n){
        n*=3;
    }
    if(n==m)cout << cant_3_m-cant_3_n+cant_2_m-cant_2_n << "\n";
    else cout << "-1\n";
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/