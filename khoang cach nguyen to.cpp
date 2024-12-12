#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e7 + 1;
bool isPrime[maxn];
const int n = 1e7;
vector<int> snt;

void Era(){
    snt.push_back(0);
    for(int i = 0; i <= n; i++){
        isPrime[i] = 1;
    }
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(isPrime[i]){
            for(int j = i * i; j <= n; j += i){
                isPrime[j] = 0;
            }
        }
    }
    for(int i = 0; i <= n; i++){
        if(isPrime[i]){
            snt.push_back(i);
        }
    }
}

int main(){
    Era();
    int m, x; cin >> m >> x;
    for(int i = 0; i <= m ; i++){
        x += snt[i];
        cout << x << " ";

    }
}