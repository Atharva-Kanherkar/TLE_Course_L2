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
    for (int i = 0; i < n; i++) cin >> a[i];
    vll prefix(n);
    vll b = a;
    sort(b.begin(), b.end());
    vll prefixb(n);
    prefix[0] = a[0];
    prefixb[0] = b[0];
    for(int i = 1; i<n; i++){
        prefix[i] = prefix[i-1] + a[i];
    }
    for(int i = 1; i<n; i++){
        prefixb[i] = prefixb[i-1] + b[i];
    }
    ll m;
    cin>>m;
    while(m--){
        ll type, l, r;
        cin>>type>>l>>r;
        l--;
        r--;
      
        if(type==1){
              ll ans = 0;
            if(l==0){
              ans=prefix[r];
            }
            else{
                ans=prefix[r]- prefix[l-1];
            }
            cout<<ans<<endl;
        }
          else if(type==2){
            ll ans = 0;
            if(l==0){
              ans=prefixb[r];
            }
            else{
                ans=prefixb[r] - prefixb[l-1];
            }
                    cout<<ans<<endl;
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