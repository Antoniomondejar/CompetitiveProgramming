#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define fore(i, a, b) for (ll i = a; i < b; i++)


vector<ll> solve(ll h, ll widht, vector<ll> ws) {
  ll n = ws.size();
  
  vector<ll> ws_sort(ws);
  sort(ws_sort.begin(), ws_sort.end());
  ll i_ws_sort = 0;

  vector<bool> ws_used(n);
  ll i_ws = 0;

  vector<ll> ans(n, -1);

  fore(row, 0, h) {
    // Fill a row
    ll filed = 0;
    for (ll j = i_ws; j < n && widht - filed >= ws_sort[i_ws_sort]; j++) {
      if (ws_used[j] || ws[j] > widht - filed) {
        if(ws[j] > widht){
          ws_used[j] = true;
        }
        continue;
      }

      ans[j] = row;
      filed += ws[j];
      ws_used[j] = true;
      if (ws_sort[i_ws_sort] == ws[j]) {
        i_ws_sort++;
      }
    }

    // Update i_ws
    while (i_ws < n && ws_used[i_ws]) {
      i_ws++;
    }

    if (i_ws == n) {
      return ans;
    }
  }

  return ans;
}

int main(void) {

  freopen("billboard.in", "r", stdin);

  ll h, w, n;

  cin >> h >> w >> n;
  
  vector<ll> ws(n);
  fore(i, 0, n) {
    cin >> ws[i];
  }

  freopen("billboard.out", "w", stdout);

  vector<ll> ans = solve(h, w, ws);

  for(ll a : ans) {
    cout << (a == -1 ? a : a+1) << '\n';
  }

  return EXIT_SUCCESS;
}


