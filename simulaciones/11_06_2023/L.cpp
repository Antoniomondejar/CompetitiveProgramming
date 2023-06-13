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

string solve(string s) {
  ull n = s.size();
  /*
  vector<char> ans(n);

  if (n % 2 == 0) {
    fore(i, 0, n) {
      if (i % 2 == 0) {
        ans[n/2 - i/2] = s[i];
      } else {
        ans[n/2 + i/2 + 1] = s[i];
      }
    }
  } else {
    fore(i, 0, n) {
      if (i % 2 == 0) {
        ans[n/2 + 1 + i/2] = s[i];
      } else {
        ans[n/2 + 1 - i/2 - 1] = s[i];
      }
    }
  } */

  string ans;

  if (n % 2 == 0) {
    fore(i, 0, n) {
      if (i % 2 == 0) {
        ans = s[i] + ans;
      } else {
        ans += s[i];
      }
    }
  } else {
    fore(i, 0, n) {
      if (i % 2 == 0) {
        ans += s[i];
      } else {
        ans = s[i] + ans;
      }
    }
  }

  return ans;
}

int main(void) {
  FIN;
  ull n;
  cin >> n;

  string s;
  cin >> s;

  cout << solve(s);

  return 0;
}