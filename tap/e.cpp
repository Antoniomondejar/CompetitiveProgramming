#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int ) x.size())
#define fore(i,a,b) for(ill i=a,gmat=b;i<gmat;++i)
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mst(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t ill;

ll a,s,l,r;
ill bs(ill d, ill li){
    ill le = 1, ri = 1e5+10;
    while(le<=ri){
        ill me = (le+ri)/2;
        ill sum = me*li + d*(me-1)*me/2;
        if(sum>s){
            ri=me-1;
        } else if(sum<s) {
            le=me+1;
        } else {
            return me;
        }
    }
    return -1;
}


int main(){FIN;
    cin>>a>>s>>l>>r;
    ill n=r-l+1;
    ll res=0;
    fore(d,1,n+1){
        ll pri = (a-l)%d;
        pri += l;
	    for(ill i = pri; i<=a; i+=d){
			ill k_t = bs(d,i);
			if(k_t==-1)continue;
			if(i+d*k_t<a || i+d*k_t>r)continue;
			res++;
	    }
    }
    cout << res << "\n";
    return 0;
}
