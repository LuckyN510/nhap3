#include<bits/stdc++.h>
using namespace std;
struct mua{
    string ma,ten,giostart,gioend;
    int tb;
    float tbc;
};
void nhap(mua &a){
    getline(cin,a.ten);
    cin>>a.giostart>>a.gioend>>a.tb;
    cin.ignore();
}

void in(mua a){
    cout<<a.ma<<" "<<a.ten<<" "<<fixed<<setprecision(2)<<a.tbc<<endl;
    
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    struct mua a[n];
    map<string,pair<int,int>>mp;
    vector<string>v;
    for(int i=0;i<n;i++){
        nhap(a[i]);
        int t1=stoi(a[i].giostart.substr(0,2));
        int t2=stoi(a[i].giostart.substr(3,2));
        int t3=stoi(a[i].gioend.substr(0,2));
        int t4=stoi(a[i].gioend.substr(3,2));
        int tong=t3*60+t4-t1*60-t2;
        if(mp.find(a[i].ten)==mp.end()){
            v.push_back(a[i].ten);
        }
        mp[a[i].ten].first+=tong;
        mp[a[i].ten].second+=a[i].tb;
    }
    int j=1;
    for(auto x:v){
        mua result;
        result.ma="T0"+to_string(j++);
        result.ten=x;
        int tongphut=mp[x].first;
        int tongmua=mp[x].second;
        result.tbc=1.0*60*tongmua/tongphut;
        in(result);

    }
    
}

