#include <iostream>
#include <cstdlib>
using namespace std;
class Point {
  private:
    int x,y;
  public:
    Point(int _x=0,int _y=0):x(_x),y(_y) {};
    Point(Point &p):x(p.x),y(p.y) {};
    ~Point() {};
    int disX(const Point &b) {
        return b.x-x;
    };
    int disY(const Point &b) {
        return b.y-y;
    }
};

class Rectangle {
  private:
    Point a,b;
  public:
    Rectangle(Point _a,Point _b):a(_a),b(_b) {};
    Rectangle(int ax=0,int ay=0,int bx=1,int by=1):a(ax,ay),b(bx,by) {}
    Rectangle(Rectangle &r):a(r.a),b(r.b) {};
    ~Rectangle() {
        cout<<"hh"<<endl;
    };
    int area() {
        return abs(a.disX(b)*a.disY(b));
    };
};

int main() {
    cout<<"请输入矩形的左上角和右下角坐标(整数)"<<endl;
    int ax,ay,bx,by;
    while(1) {
        cin>>ax>>ay>>bx>>by;
        if(ax>bx||ay<by||cin.fail()) {
            cout<<"输入的矩形不合法"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
        } else {
            Rectangle myRectangle(ax,ay,bx,by);
            cout<<"该矩形的面积为"<<myRectangle.area()<<endl;
            break;
        }
    }
    return 0;
}
