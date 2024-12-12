#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n];
    int res = 1e9;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 0; i <= n - k ; i++){
        res = min(res, a[i + k - 1] - a[i]);
    }
    cout << res;
}