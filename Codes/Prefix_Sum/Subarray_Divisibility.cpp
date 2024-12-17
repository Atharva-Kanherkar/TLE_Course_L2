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
ll n;
cin>>n;
vll a(n);
for(int i = 0; i<n; i++){
    cin>>a[i];
}
vll prefix(n);
        prefix[0] = a[0];
        for (int i = 1; i < n; i++) {   
            prefix[i] = prefix[i - 1] + a[i];
        }
        ll ans = 0;
map<ll, ll> cnt;
        for (int i = 0; i < n; i++) {
            if (prefix[i] % n ==0) ans++;
             if (cnt.find( ((prefix[i] % n) + n) % n) != cnt.end()) {
               ans += cnt[((prefix[i] % n) + n) % n];
}
            cnt[ ((prefix[i] % n) + n) % n]++;
        }
        cout<<ans<<endl;
     










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