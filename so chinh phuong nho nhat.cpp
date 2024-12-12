#include<bits/stdc++.h>

using namespace std;
using ll = long long;

map<ll, ll> v;

ll check(ll n){
    ll sum = n;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            ll cnt = 0;
            while(n % i == 0){
                ++cnt;
                n /= i;
            }
            if(cnt % 2 != 0)
            sum *= i;
        }
    }
    if(n > 1) sum *= n;
    return sum;
}

int main() {
    ll n;
    cin >> n;
    cout << check(n);
    
}
