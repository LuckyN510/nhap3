#include<bits/stdc++.h>

using namespace std;

string sinh(int n) {
    if(n == 0) return "{}";
    if(n == 1) return "{{}}";
    for(int i = 0; i < n; i++){
        
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int pos = -1;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+'){
                pos = i;
                break;
            }
        }
        int num1 = stoi(s.substr(0, pos));
        int num2 = stoi(s.substr(pos + 1));
        int res = num1 + num2;
        cout << sinh(num1) << "+" << sinh(num2) << "=" << sinh(res);
        cout << endl;
        
    }
}