#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int ) x.size())
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mst(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){FIN;
    ll a1, p1;cin>>a1>>p1;
    ll a2,p2;cin>>a2>>p2;
    if(a1+a2>p1+p2){
        cout << "A\n";
        return 0;
    }
    if(p1+p2>a1+a2){
        cout << "P\n";
        return 0;
    }
    cout << "D\n";
    return 0;
}