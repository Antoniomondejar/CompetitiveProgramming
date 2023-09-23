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

#define AMAX (1000001)

ull firstDivs[AMAX];

void sieve() {
    fore(i, 1, AMAX) {
        firstDivs[i] = i;
    }

    fore(i, 2, AMAX) {
        if (firstDivs[i] == i) {
            for(ull j = i*i; j < AMAX; j += i) {
                if (firstDivs[j] == j) {
                    firstDivs[j] = i;
                }
            }
        }
    }
}


int main(){FIN;

    ull n;
    cin >> n;
    vector<ull> as(n);


    return 0;
}