#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define ford(i,a,b) for(int i=a,ggdem=b;i>=ggdem;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;

int main(){FIN;
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n], c[n];
        fore(i,0,n){
            cin >> a[i];
            c[i] = a[i];
        }
        fore(i,0,n-1){
            if(a[i]<a[i+1] && i < n-2){
                a[i+2] -= a[i+1]-a[i];
                a[i+1] = a[i];
            }
        }
        ford(i,n-1,1){
            if(c[i]>c[i-1] && i > 1){
                c[i-2] += c[i]-c[i-1];
                c[i-1] = c[i];
            }
        }
        bool b = true;
        fore(i,0,n-1){
            if(a[i]>a[i+1]){
                if(i==n-2){
                    b = false;
                    break;
                } else if(a[i+2]>=a[i+1]){
                    a[i+2] += a[i]-a[i+1];
                    a[i+1] = a[i];
                } else if(i<n-3){
                    a[i+3] -= a[i+1]-a[i+2];
                    a[i+2] = a[i];
                    a[i+1] = a[i];
                } else {
                    b = false;
                    break;
                }
            }
        }
        if(b) cout << "YES\n";
        else {
            b = true;
            ford(i,n-1,1){
                if(c[i-1]>c[i]){
                    if(i==1){
                        b = false;
                        break;
                    } else if(c[i-1]>=c[i-2]){
                        c[i-2] -= c[i-1]-c[i];
                        c[i-1] = c[i];
                    } else if(i>2){
                        c[i-3] += c[i-2]-c[i-1];
                        c[i-2] = c[i];
                        c[i-1] = c[i];
                    } else {
                        b = false;
                        break;
                    }
                }
            }
            if(b) cout << "YES\n";
            else cout << "NO\n";   
        }
    }
    return 0;
}