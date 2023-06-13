#include <bits/stdc++.h>
#define pb push_back
#define fore(i, a, b) for (int i = a, ggdem = b; i < ggdem; ++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define FIN                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull solve(vector<pair<ll, ll>> xys) {
  ull n = xys.size();

  map<pair<ll, ll>, vector<pair<ull, ull>>> combs;

  fore(i, 0, n) {
    auto [x0, y0] = xys[i];

    fore(j, i + 1, n) {
      auto [x1, y1] = xys[j];

      ll x = x1 - x0;
      ll y = y1 - y0;

      ll GCD = gcd(x, y);

      ll sign = (x <= 0 && y < 0) || (x >= 0 && y < 0) ? -1 : 1;

      combs[{sign * x / GCD, sign * y / GCD}].push_back({i, j});
    }
  }

  ull ans = 0;

  for (auto [_, pairs] : combs) {
    ull k = pairs.size();

    fore(t, 0, k) {
      auto [i0, j0] = pairs[t];
      auto [x00, y00] = xys[i0];
      auto [x01, y01] = xys[j0];
      fore(r, t + 1, k) {
        auto [i1, j1] = pairs[r];

        auto [x10, y10] = xys[i1];
        auto [x11, y11] = xys[j1];

        ll x_0 = x00 - x10;
        ll y_0 = y00 - y10;

        ll x_1 = x01 - x11;
        ll y_1 = y01 - y11;

        ll gcd0 = gcd(x_0, y_0);
        ll gcd1 = gcd(x_1, y_1);

        ll sign0 = (x_0 <= 0 && y_0 < 0) || (x_0 >= 0 && y_0 < 0) ? -1 : 1;
        ll sign1 = (x_1 <= 0 && y_1 < 0) || (x_1 >= 1 && y_1 < 0) ? -1 : 1;

        x_0 = sign0 * x_0 / gcd0;
        y_0 = sign0 * y_0 / gcd0;

        x_1 = sign1 * x_1 / gcd1;
        y_1 = sign1 * y_1 / gcd1;

        if (x_0 == x_1 && y_0 == y_1) {
          ans += 1;
        }
      }
    }
  }

  return ans / 2;
}

int main(void) {
  FIN;

  ull n;
  cin >> n;

  vector<pair<ll, ll>> xys(n);
  fore(i, 0, n) {
    cin >> xys[i].first >> xys[i].second;
  }

  cout << solve(xys) << '\n';

  return 0;
}
