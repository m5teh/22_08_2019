


#include<bits/stdc++.h>
using namespace std;
long long n, k;
long long c[1000001], res = 0;
void inline read (long long &x) {
  char c = getchar ();
  while (c < '0' || c > '9') {
    c = getchar ();
  }
  while (c <= '9' && c >= '0') {
    x = x * 10 + c - '0';
    c = getchar ();
  }
}
int main () {
  if (fopen ("test.inp", "r")) {
    freopen ("test.inp", "r", stdin);
  }
  else {
    freopen("GAS.inp", "r", stdin);
    freopen("GAS.out", "w", stdout);
  }
  ios_base :: sync_with_stdio (0);
  cin.tie (nullptr);
  cout.tie (nullptr);
  cin >> n >> k;
  for (int i = 0; i < n; ++ i) {
    cin >> c[i];
  }
  deque <int> q;
  for (int i = 0; i <= n; ++ i) {
    while (q.size () && q.front () < i - k) {
      q.pop_front ();
    }
    if (q.size ()) {
      res += c[q.front ()];
    }
    while (q.size () && c[q.back ()] >= c[i]) {
      q.pop_back ();
    }
    q.push_back (i);
    //cout << res << "\n";
  }
  cout << res;
}

