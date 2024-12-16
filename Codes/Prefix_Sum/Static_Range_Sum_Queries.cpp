 #include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define vll vector<long long>

int main() {
    fastio;

    long long n, q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

 
    vll prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {   
        prefix[i] = prefix[i - 1] + a[i];
    }

 
    while (q--) {
        long long l, r;
        cin >> l >> r;
        r--;
        l--;
         if (l == 0) 
            cout << prefix[r] << endl;
        else 
            cout << prefix[r] - prefix[l - 1] << endl;
    }

    return 0;
}
