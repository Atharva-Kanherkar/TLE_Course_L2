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
   ll n, q;
    cin >> n >> q;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> prefix(n, vector<int>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j <n; j++){
            if(a[i][j]=='*')
             prefix[i][j] =  1;
             else
             prefix[i][j] = 0;
            if (i > 0) prefix[i][j] += prefix[i - 1][j];
             if (j > 0) prefix[i][j] += prefix[i][j - 1];
          if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
       
        }
    }
    while(q--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;
        c1--;
        r2--;
        c2--;
        int sum = prefix[r2][c2];
   if (r1 > 0) sum -= prefix[r1 - 1][c2];
      if (c1 > 0) sum -= prefix[r2][c1 - 1];
      if (r1 > 0 && c1 > 0) sum += prefix[r1 - 1][c1 - 1];
     cout<<sum<<endl;

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