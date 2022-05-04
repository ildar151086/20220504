#include <iostream>

using namespace std;


class Point {
    int id;
    int x;
    int y;
    static int statY;
    inline float lengthAB(Point pointLength) {
        return sqrt((x - pointLength.x) * (x - pointLength.x)
                  + (y - pointLength.y) * (y - pointLength.y));
    };
    inline float lengthAB(Point second, Point trey) {
        return sqrt((second.x - trey.x) * (second.x - trey.x)
                  + (second.y - trey.y) * (second.y - trey.y));
    };

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

    float areaTriangular(Point second, Point trey) {
        float a = lengthAB(second);
        float b = lengthAB(trey);
        float c = lengthAB(second,trey);
        float p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));        
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

    cout << "Площадь треугольника = " << p[0].areaTriangular(p[1], p[2]) << endl;

    delete[] p;
}

