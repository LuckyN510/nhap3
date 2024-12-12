#include<bits/stdc++.h>

using namespace std;

class Point{
private:
    double x, y;
public:
    Point(){
        x = 0;
        y = 0;
    }
    Point(double x, double y){
        this->x = x;
        this->y = y;
    }
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    double distance(Point other){
          return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
    }
    friend istream& operator >> (istream &in, Point &A){
        return in >> A.x >> A.y;
    }
   
};

int main(){
    int t; cin >> t;
    while(t--){
        // double x, y;
        // cin >> x >> y;
        // Point A(x, y);
        // cin >> x >> y;
        // Point B(x, y);
        // cin >> x >> y;
        // Point C(x, y);
        Point A, B, C;
        cin >> A >> B >> C;
        double AB = A.distance(B);
        double AC = A.distance(C);
        double BC = B.distance(C);
        if (AB + BC > AC && AB + AC > BC && BC + AC > AB) {
            cout << fixed << setprecision(3) << AB + BC + AC << endl;
        } else {
            cout << "INVALID\n";
        }
    }
}
