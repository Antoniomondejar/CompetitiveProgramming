#include <bits/stdc++.h>
#define pb push_back
#define fore(i,a,b) for(int i=a, ggdem=b; i<ggdem; ++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<int> z_function(string& s){
    int l=0, r=0,n=s.size();
    vector<int> z(s.size(),0);
    fore(i,1,n){
        if(i<=r)z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
        if(i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return z;
}


int main(void){FIN;
    ll n; cin >> n;
    string s; cin>>s;
    vector<int> z_a = z_function(s);
    ll res = n;
    fore(i,1,n){
        if(z_a[i]>=i && (i)*2<=n){
            res = min(res, i+1+(n-2*i));
        }
    }
    cout << res << "\n";
    return 0;
}