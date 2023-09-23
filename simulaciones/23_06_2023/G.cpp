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
typedef vector<int> vvl;

int main(){FIN;
    int n,m; cin >> n >> m;
    vector<int> p(n);
    fore(i,0,n)cin>>p[i];
    while(m--){
        int l,r,x; cin >> l >> r >> x;--l;
        int elem=p[x-1];int cant_m = 0;
        fore(i,l,r){
            if(elem>p[i])++cant_m;
        }
        if(cant_m==(x-l-1))cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}