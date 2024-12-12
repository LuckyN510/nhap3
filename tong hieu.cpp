#include<bits/stdc++.h>

using namespace std;

string add(string a, string b){
   string res = "";
   int nho = 0;
   while(a.size() < b.size()) a = "0" + a;
   while(a.size() > b.size()) b = "0" + b;
   int len = a.size() - 1;
   for(int i = len; i >= 0; i--){
        int so = int(a[i] - '0') + int(b[i] - '0') + nho;
        res = char(so % 10 + '0') + res;
        nho = so / 10;
   }
   if(nho > 0) res = char(nho +'0') + res;
   return res;
}

string diff(string a, string b) {
    string res = "";
    int nho = 0;
    while (a.size() > b.size()) b = "0" + b;
    while (a.size() < b.size()) a = "0" + a;
    bool ok = false;
    if (a < b) {
        a.swap(b);
        ok = true;
    }
    int len = a.size() - 1;
    for (int i = len; i >= 0; i--) {
        int so = int(a[i] - '0') - int(b[i] - '0') - nho;
        if (so < 0) {
            res = char(so + 10 + '0') + res;
            nho = 1;
        } else {
            res = char(so + '0') + res;
            nho = 0;
        }
    }
    while(res[0] == '0') res.erase(res.begin());
    if(ok == true)  res = "-" + res;
    return res;
}


int main(){
    string a; cin >> a;
   
   cout << a.substr(6) + a.substr(3, 2)+ a.substr(0, 2);
}