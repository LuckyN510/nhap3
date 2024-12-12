#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

int main(){
    int n; cin >> n;
    int a[n];
    ll M = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        M = (1ll * M * a[i]) % mod;
    }
    ll cnt = 0;
    for(ll i = 1; i <= sqrt(M); i++){
        if(M % i == 0){
            ++cnt;
            if(i != M / i){
                ++cnt;
            }
        }
    }
    cout << cnt << endl;

}