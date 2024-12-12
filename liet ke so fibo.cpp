#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> F(100);

void fibo(){;
    F[1] = 1;
    F[2] = 1;
    for(int i = 3; i < 93; i++){
        F[i] = F[i - 1] + F[i - 2];
    }
}

int main(){
    fibo();
    int t; cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        for(int i = a; i <= b; i++){
            cout << F[i] << " ";
        }
        cout << endl;
        F.clear();
    }
}