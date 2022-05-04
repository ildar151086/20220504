#include <iostream>

using namespace std;


class Point {
    int id;
    static int statY;
    int x;
    int y;
public:
    Point() {
        x = 0;
        y = 0;
        id = statY++;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
        id = statY++;
    }
    void print() {
        cout << "id = " << id << " x = " << x << " y = " << y << endl;
    }
    void printStatics() {
        cout << "Count = " << statY << endl;
    }
    float getX() {
        return x;
    }
    float getY() {
        return y;
    }
};


class calcArea: public Point {
    float area;
    inline float lengthAB(Point second, Point trey) {
        return sqrt((second.getX() - trey.getX()) * (second.getX() - trey.getX())
            + (second.getY() - trey.getY()) * (second.getY() - trey.getY()));
    };
    inline float calcAreaSqr(float a, float b, float c, float p) {
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
public:
    calcArea(Point first, Point second, Point trey) {
        float a = lengthAB(first, second);
        float b = lengthAB(second, trey);
        float c = lengthAB(first, trey);
        float p = (a + b + c) / 2;
        area = calcAreaSqr(a, b, c, p);
    }
    calcArea(Point *pT) {
        float a = lengthAB(pT[0], pT[1]);
        float b = lengthAB(pT[0], pT[2]);
        float c = lengthAB(pT[1], pT[2]);
        float p = (a + b + c) / 2;
        area = calcAreaSqr(a, b, c, p);
    }

    float getArea() {
        return area;
    }
};

int Point::statY = 0;

int main()
{
    setlocale(LC_ALL, "RUS");
    int const SIZE = 3;
    
    Point* p = new Point[SIZE]{
        Point(1,1),
        Point(1,3),
        Point(6,4)
    };
    for (int i = 0; i < SIZE; i++) {
        p[i].print();
    }
    //p[0].printStatics();

    calcArea area(p[0],p[1],p[2]);
    calcArea pArea(p);
    cout << "Площадь треугольника = " << area.getArea() << endl;
    cout << "Площадь треугольника = " << pArea.getArea() << endl;

    delete[] p;
}

