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

int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n), a_s(n+1);
        cin >> a[0]; a_s[0] = 0; a_s[1] = a[0];
        fore(i,1,n){
            cin >> a[i];
            a_s[i+1] = a_s[i]+a[i];
        }
        ll l = 0; ll r = n-1; ll m;
        while(l<r){
            m = (l+r)/2;
            cout << "? " << m-l+1 << " ";
            fore(i,l,m+1){
                cout << i+1 << " ";
            }
            cout << endl;
            ll inp; cin >> inp;
            if(inp>a_s[m+1]-a_s[l]){
                r = m-1;
            } else {
                l = m+1;
            }
        }
        if(r==l && l<n-1)++l;
        cout << "? 1 " << l+1 << endl;
        ll inp; cin >> inp;
        if(inp > a[l]) {cout << "! " << l+1 << "\n"; continue;}
        cout << "? 1 " << r+1 << endl;
        cin >> inp;
        cout << "! " << r+1 << "\n";
    }
    return 0;
}