#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

class PhanSo {
private:
    int tu, mau;
public:
    PhanSo(){

    }

    PhanSo(int tu, int mau){
        this->tu = tu;
        this->mau = mau;
    }

    friend istream& operator >> (istream& in, PhanSo& a){
        in >> a.tu >> a.mau;
        return in;
    }

    friend ostream& operator << (ostream& out, const PhanSo a){
        out << a.tu << "/" << a.mau << endl;
        return out;
    }

    void rutGon(){
        int g = gcd(abs(this->tu), abs(this->mau));
        this->tu /= g;
        this->mau /= g;
    }

    friend PhanSo operator + (const PhanSo a, const PhanSo b){
        PhanSo tong;
        ll mc = lcm(a.mau, b.mau);
        tong.tu = mc / a.mau * a.tu + mc / b.mau * b.tu;
        tong.mau = mc;
        tong.rutGon();
        return tong;
    }

    friend PhanSo operator * (const PhanSo a, const PhanSo b){
        PhanSo tich;
        tich.tu = a.tu * b.tu;
        tich.mau = a.mau * b.mau;
        tich.rutGon();
        return tich;
        
    }

};



int main(){
    PhanSo p(1, 1), q(1, 1);
    cin >> p >> q;
    cout << p <<  q;
    cout << p + q;
    cout << (p + q) * (p + q);
    return 0;
}