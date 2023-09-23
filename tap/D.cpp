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



bool can(const vector<ull>& Cs, const vector<ull>& Ps, ull m) {
    ull K = Cs.size();
    ull extra = 0;
    fore(i, 0, K) {
        extra += Ps[i];
        if (extra < m*Cs[i]) {
            return false;
        }
        extra -= m*Cs[i];
    }

    return true;
}


ull solve(const vector<ull>& Cs, const vector<ull>& Ps) {
    ull lower = 0, upper = 1e16;
    while (lower + 1 < upper) {
        ull m = (lower + upper)/2;
        if (!can(Cs, Ps, m)) {
            upper = m;
        } else {
            lower = m;
        }
    }

    return upper - 1;
}

int main(){FIN;

    ull K;
    cin >> K;
    vector<ull> Cs(K), Ps(K);
    for(ull& C : Cs) {
        cin >> C;
    }
    for(ull& P : Ps) {
        cin >> P;
    }

    cout << solve(Cs, Ps) << '\n';


    return 0;
}