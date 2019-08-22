#include<bits/stdc++.h>
using namespace std;
struct st {
  long long x, p;
};
st a[100101];
long long res = 0, n, m;
bool cmp (st a, st b) {
  return a.x > b.x;
}
int main () {
   if (fopen ("test.inp", "r")) {
    freopen ("test.inp", "r", stdin);
  }
  else {
    freopen("DELIVER.inp", "r", stdin);
    freopen("DELIVER.out", "w", stdout);
  }
  ios_base :: sync_with_stdio (0);
  cin.tie (nullptr);
  cout.tie (nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i].x >> a[i].p;
  }
  sort (a + 1, a + n + 1, cmp);
  long long cc = a[1].x;
  for (int i = 1; i <= n; ++ i) {
    //cout << res << " ";
    a[i].p += a[i - 1].p;
    if (a[i].p >= m) {
      res += cc * 2;
      a[i].p -= m;
      cc = a[i].x;
      res += (a[i].p / m) * 2 * cc;
      a[i].p %= m;
      if (a[i].p == 0) {
        cc = a[i + 1].x;
      }
    }
  }
  if (a[n].p > 0) {
    res += cc * 2;
  }
  cout << res;
}
