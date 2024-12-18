#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> prefix(n, vector<int>(m));
 for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        prefix[i][j] = grid[i][j];
        if (i > 0) prefix[i][j] += prefix[i - 1][j];
        if (j > 0) prefix[i][j] += prefix[i][j - 1];
        if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
    }
 }

int q;
cin>>q;
while(q--){
  int r1,c1,r2,c2;
  cin>>r1>>c1>>r2>>c2;
  int number = (r2-r1 + 1) * (c2-c1+1);
  r1--;
  c1--;
  r2--;
  c2--;
  int sum = prefix[r2][c2];
if (r1 > 0) sum -= prefix[r1 - 1][c2];
if (c1 > 0) sum -= prefix[r2][c1 - 1];
if (r1 > 0 && c1 > 0) sum += prefix[r1 - 1][c1 - 1];
 if(sum == number){
    cout<<1<<endl;
 }
 else{
    cout<<0<<endl;
 }
}
         
}

int main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}