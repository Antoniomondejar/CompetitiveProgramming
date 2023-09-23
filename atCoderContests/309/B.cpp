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
const ll NMAX = 110;
const ll MOD = 1e9+7;

string a[NMAX];

int main(){
    ll n; cin >> n;
    fore(i,0,n){
        cin>>a[i];
    }
    fore(i,0,n){
        fore(j,0,n){
            if(i==0 && j == 0)cout << a[1][0];
            else if(i==0)cout << a[i][j-1];
            else if(j==n-1)cout << a[i-1][j];
            else if(i==n-1)cout << a[i][j+1];
            else if(j==0)cout << a[i+1][j];
            else cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}

/*
DIEGO VAGGIONE -> MEJOR PROFE DE FAMAF.
*/