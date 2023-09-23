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

constexpr double EPS = 1e-8;

double solve(ull T, vector<double> Ps, vector<double> Ns) {
    double t = 0.0;
    while(SZ(Ps) > 0 || SZ(Ns) > 0) {
        double P_speed = (SZ(Ns) > 0) ? (double)T * 0.75 / ((double)SZ(Ps)) : (double)T / ((double)SZ(Ps));
        double N_speed = (SZ(Ps) > 0) ? (double)T * 0.25 / ((double)SZ(Ns)) : (double)T / ((double)SZ(Ns));

        double best_time = 1e30;
        for(double X : Ps) {
            best_time = min(best_time, X/P_speed);
        }
        for(double X : Ns) {
            best_time = min(best_time, X/N_speed);
        }

        for(double& X : Ps) {
            X -= P_speed * best_time;
        }
        for(double& X : Ns) {
            X -= N_speed * best_time;
        }

        vector<double> nPs, nNs;
        for(double X : Ps) {
            if (X > EPS) {
                nPs.pb(X);
            }
        }
        for(double X : Ns) {
            if (X > EPS) {
                nNs.pb(X);
            }
        }

        Ps = nPs, Ns = nNs;
        t += best_time;
    }

    return t;
}

int main(){FIN;

    ull N, T;
    cin >> N >> T;

    vector<double> Ps, Ns;
    fore(i, 0, N) {
        char c; double X;
        cin >> c >> X;
        if (c == 'P') {
            Ps.pb(X);
        } else {
            Ns.pb(X);
        }
    }

    cout << setprecision(8);
    cout << solve(T, Ps, Ns) << '\n';

    return 0;
}