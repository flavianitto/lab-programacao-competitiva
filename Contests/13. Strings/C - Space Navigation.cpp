#include <bits/stdc++.h>
using namespace std;

bool verify(int val, int up, int down) {
  return val > 0
    ? (up >= val)
    : (down >= -val);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, x, y;
  int u, d, r, l;
  bool v, h;
  string s;
  cin >> t;
  while (t--) {
    cin >> x >> y >> s;
    u = r = d = l = 0;
    for (char c : s) {
      switch (c) {
        case 'R':
          r++;
          break;
        case 'L':
          l++;
          break;
        case 'U':
          u++;
          break;
        case 'D':
          d++;
          break;
      }
    }
    h = verify(x, r, l);
    v = verify(y, u, d);
    cout << (h && v ? "YES" : "NO") << '\n';
  }
  return 0;
}