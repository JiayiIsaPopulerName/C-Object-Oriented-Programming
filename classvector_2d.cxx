#include<iostream>

using namespace std;

class Vector_2d
{
    int x, y;
    public:
        Vector_2d(int arg_x = 0, int arg_y = 0) : x(arg_x), y(arg_y){}
        Vector_2d(const Vector_2d& other)
        {
            x = other.x;
            y = other.y;
            cout << " Copy " << endl;
        }
        void print(const char*) const;
      //int get_x() const {return x;}
      //int get_y() const {return y;}
        const Vector_2d operator + (const Vector_2d & op) const;
        const Vector_2d operator - (const Vector_2d & op) const
        {
            return Vector_2d(x-op.x, y-op.y);
        }
        Vector_2d & operator = (const Vector_2d & op)
        {
            x = op.x;
            y = op.y;
            return *this;
        }
        const Vector_2d operator*(int a) const
        {
            return Vector_2d(a*x, a*y);
        }
        friend const Vector_2d operator*(int a, const Vector_2d & op);
        friend ostream& operator << (ostream & os, const Vector_2d &op);
};

ostream & operator << (ostream & os, const Vector_2d &op)
{
    os << "(" << op.x << "," << op.y << ")";
}
const Vector_2d operator*(int a, const Vector_2d & op)
{
    //double tmp_x = op.get_x();
    //double tmp_y = op.get_y();
    return Vector_2d(a*op.x, a*op.y);
}
const Vector_2d Vector_2d::operator + (const Vector_2d & op) const
{
    Vector_2d tmp;
    tmp.x = x + op.x;
    tmp.y = y + op.y;
    return tmp;
}
void Vector_2d::print(const char *str = 0) const
{
    if (str)
        cout << str << "= ";
    cout << "(" << x << ", " << y << ")" <<endl;
}
int main()
{
    Vector_2d u, v(2), w(3,4);
    u.print("u");
    v.print("v");
    w.print("w");
    (v-w).print("v+w");
    u = w*4;
    cout << "u"  << u <<endl;
    //if (v + w = u)
    u.print("u = w + v");
    w.print("w = v");
    return 0;
}