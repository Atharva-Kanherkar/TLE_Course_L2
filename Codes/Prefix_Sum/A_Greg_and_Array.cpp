 #include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

   
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    
    vector<tuple<int, int, ll>> operations(m);
    for (int i = 0; i < m; i++) {
        int l, r;
        ll d;
        cin >> l >> r >> d;
        operations[i] = {l - 1, r - 1, d};  
    }

    
    vector<ll> query_count(m + 1, 0); 
    while (k--) {
        int x, y;
        cin >> x >> y;
        query_count[x - 1] += 1;
        query_count[y] -= 1; 
    }

  
    for (int i = 1; i < m; i++) {
        query_count[i] += query_count[i - 1];
    }

     
    vector<ll> delta(n + 1, 0); 
    for (int i = 0; i < m; i++) {
        auto [l, r, d] = operations[i];
        ll times = query_count[i]; 
        delta[l] += times * d;
        if (r + 1 < n) delta[r + 1] -= times * d;
    }

    
    for (int i = 1; i < n; i++) {
        delta[i] += delta[i - 1];
    }
    for (int i = 0; i < n; i++) {
        a[i] += delta[i];
    }

   
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
