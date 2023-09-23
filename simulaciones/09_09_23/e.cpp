#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(int i=a,gmat=b;i<gmat;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll sum_d(ll x){
    ll res = 0;
    while(x>0){
        res+=(x%10);
        x/=10;
    }
    return res;
}

int main(){FIN;
    ll act = 14456;ll it = 50;
    while(act>0){
        cout << act << "\n";
        cout << sum_d(act) << "\n";
        act-=sum_d(act);
        // if(it)
        --it;
        if(act<10)break;
    }
    return 0;
}