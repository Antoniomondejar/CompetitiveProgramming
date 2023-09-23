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
typedef vector<ll> vvl;

#define MOD ull(1e9 + 7)

/*
                                                        f1
                                               f2
                                      f3
f4  = c**(2*4-6) * f3*f2*f1 = c**2  * f3     * f2     * f1
f5  = c**(2*5-6) * f4*f3*f2 = c**6  * f3**2  * f2**2  * f1
f6  = c**6 * f5*f4*f3       = c**12 * f3**4  * f2**3  * f1**2
f7  = c**8 * f6*f5*f4       = c**20 * f3**7  * f2**6  * f1**4
f8  = c**10 * f7*f6*f5      = c**30 * f3**13 * f2**11 * f1**7
f9  = c**12 * f8*f7*f6      = c**42 * f3**24 * f2**20 * f1**13
f10 = c**14 * f9*f8*f7      = c**56 * f3**44 * f2**37 * f1**24


*/


int main(){FIN;

    ull n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;




    return 0;
}