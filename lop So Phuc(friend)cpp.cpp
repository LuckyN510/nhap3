#include<bits/stdc++.h>

using namespace std;

class SoPhuc{
private:
    int ao, thuc;
public:

    SoPhuc(){

    }
    
    SoPhuc(int ao, int thuc){
        this->ao = ao;
        this->thuc = thuc;
    }

    friend SoPhuc operator * (SoPhuc &A, SoPhuc &B){
        SoPhuc res;
        res.thuc = A.thuc * B.thuc - A.ao * B.ao;
        res.ao = A.thuc * B.ao + A.ao * B.thuc;
        return res; 
    }
 
    friend SoPhuc operator + (SoPhuc &A, SoPhuc &B){
        SoPhuc res;
        res.thuc = A.thuc + B.thuc;
        res.ao = A.ao + B.ao;
        return res; 
    }

    friend istream& operator >> (istream &in, SoPhuc &A){
        return in >> A.thuc >> A.ao;
    }

    friend ostream& operator << (ostream &out, const SoPhuc &A){
        if(A.ao < 0){
            out << A.thuc << " - " << (-A.ao) << "i"; 
        }
        else{
            out << A.thuc << " + " << A.ao  << "i"; 
        }
        return out;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        SoPhuc A, B;
        cin >> A >> B;
        SoPhuc x = A + B;
        cout << x * A << ", " <<  x * x << endl;
    }
}