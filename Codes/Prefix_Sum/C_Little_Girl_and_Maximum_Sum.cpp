 #include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> diff(n + 1, 0);
    vector<pair<ll, ll>> queries;
    while (q--) {
        ll x, y;
        cin >> x >> y;
        queries.push_back({x, y});
        diff[x - 1] += 1;
        if (y < n) diff[y] -= 1;
    }
    for (ll i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
    }
    vector<pair<ll, ll>> p;
    for (ll i = 0; i < n; i++) {
        p.push_back({diff[i], i});
    }
    sort(p.rbegin(), p.rend());
    sort(a.rbegin(), a.rend());
    vector<ll> v(n, 0);
    for (ll i = 0; i < n; i++) {
        v[p[i].second] = a[i];
    }
    vector<ll> prefix(v.size(), 0);
    for (ll i = 0; i < v.size(); i++) {
        prefix[i] = (i == 0 ? v[i] : prefix[i - 1] + v[i]);
    }
    ll sum = 0;
    for (auto x : queries) {
        sum += prefix[x.second - 1] - (x.first > 1 ? prefix[x.first - 2] : 0);
    }
    cout << sum << endl;
}

int main() {
    fastio;
    ll t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
