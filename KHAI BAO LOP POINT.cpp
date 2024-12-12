#include <bits/stdc++.h>

using namespace std;

class Point {
private:
    double x, y;

public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    double distance(Point other) {
        return sqrt(pow(this->x - other.getX(), 2) + pow(this->y - other.getY(), 2));
    }
    friend istream& operator >> (istream &in, Point &A){
        return in >> A.x >> A.y;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        // double x, y;
        // cin >> x >> y;
        // Point A(x, y);
        // cin >> x >> y;
        // Point B(x, y);
        Point A, B;
        cin >> A >> B;
        cout << fixed << setprecision(4) << A.distance(B) << endl;
    }
    return 0;
}
