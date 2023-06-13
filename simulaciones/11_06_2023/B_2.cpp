#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a, ggdem=b; i<ggdem; ++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll NMAX = 1e5+10;

int cant[NMAX];


int main(void){FIN;
    int n,m; cin >> n >> m;
    vector<int> a(n);
    fore(i,0,n){
        cin>>a[i];
        if(a[i]<=n)cant[a[i]]++;
    }
    vector<pair<int,vector<int>>> as;
    vector<int> aux(n+1);
    fore(i,1,n+1){
        if(cant[i]>=i){
            aux[0]=0;
            fore(j,1,n+1){
                aux[j]=aux[j-1]+(a[j-1]==i);
            }
            as.pb({i,aux});
        }
    }
    while(m--){
        int l, r; cin >> l >> r; --l;
        int ans = 0;
        for(auto &is:as){
            if(is.second[r]-is.second[l]==is.first)++ans;
        }
       cout << ans << "\n";
    }
    return 0;
}