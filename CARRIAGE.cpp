#include<bits/stdc++.h>
using namespace std;
long long n, m, k, a[100001], b[30], x[30], res = 1e9, s[100001];
int bin (long long val) {
  int l = 1, r = n + 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (s[mid] == val) {
      return mid;
    }
    else if (s[mid] > val) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return ans;
}
void solve () {
  long long sum = 0;
  int so = 0;
  for (int i = 1; i <= m; ++ i) {
    if (x[i] == 1) {
      sum += b[i];
      ++ so;
    }
  }
  //if (sum < k) return;
  int tmp = bin ((sum - (k - s[1])));
  if (tmp != -1) {
    so += n - tmp + 1;
    if (res > so) {
      res = so;
    }
  }
}
void bt (int i) {
  for (int j = 0; j <= 1; ++ j) {
    x[i] = j;
    if (i == m) {
      solve ();
    }
    else {
      bt (i + 1);
    }
  }
}
int main () {
  if (fopen ("test.inp", "r")) {
    freopen ("test.inp", "r", stdin);
  }
  else {
    freopen("CARRIAGE.inp", "r", stdin);
    freopen("CARRIAGE.out", "w", stdout);
  }
  ios_base :: sync_with_stdio (0);
  cin.tie (nullptr);
  cout.tie (nullptr);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++ i) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; ++ i) {
    cin >> b[i];
  }
  s[n + 1] = 0;
  for (int i = n; i >= 1; -- i) {
    s[i] = s[i + 1] + a[i];
  }
  bt (1);
  cout << res;
}
