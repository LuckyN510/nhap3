#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int r = 0;
    for (char c : s){
        r = (r * 2 + (c - '0')) % 5;
    }
    if(r == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
