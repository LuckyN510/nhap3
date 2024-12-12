#include<bits/stdc++.h>

using namespace std;

struct SoPhuc {
    int thuc, ao;
};

void nhap(SoPhuc &A) {
    cin >> A.thuc >> A.ao;
}

void in(SoPhuc &A) {
    if(A.ao < 0){
        cout << A.thuc << " - " << (-A.ao) << "i";
    }
    else{
          cout << A.thuc << " + " << A.ao << "i";
    }
}

// Addition of two complex numbers
SoPhuc tong_hai_so(SoPhuc &A, SoPhuc &B) {
    SoPhuc res;
    res.thuc = A.thuc + B.thuc;
    res.ao = A.ao + B.ao;
    return res; 
}

// Multiplication of two complex numbers
SoPhuc tich_hai_so(SoPhuc &A, SoPhuc &B) {
    SoPhuc res;
    res.thuc = A.thuc * B.thuc - A.ao * B.ao;
    res.ao = A.thuc * B.ao + A.ao * B.thuc;
    return res; 
}

// Calculate C = (A + B) * A
SoPhuc tinh_C(SoPhuc &A, SoPhuc &B) {
    SoPhuc sum = tong_hai_so(A, B);
    return tich_hai_so(sum, A); // (A + B) * A
}

// Calculate D = (A + B)^2
SoPhuc tinh_D(SoPhuc &A, SoPhuc &B) {
    SoPhuc sum = tong_hai_so(A, B);
    return tich_hai_so(sum, sum); // (A + B) * (A + B)
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        SoPhuc A, B;
        nhap(A);
        nhap(B);
        SoPhuc C = tinh_C(A, B);
        in(C);
        cout << ", ";
        SoPhuc D = tinh_D(A, B);
        in(D);
        cout << endl;
    }
}
