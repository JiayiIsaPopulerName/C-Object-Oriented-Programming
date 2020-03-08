#include <iostream>
using namespace std;

class vector_2d
{
    int x,y;
    public:
        vector_2d(int arg_x=0,int arg_y = 0):x(arg_x),y(arg_x){}
        void print(const char*);
        vector_2d operator+(vector_2d op);
        vector_2d operator-(vector_2d op){return vector_2d(x-op.x,y-op.y);}
        void operator=(vector_2d op)
        
};
vector_2d vector_2d::operator+(vector_2d op)
{
    vector_2d tmp;
    tmp.x = x + op.x;
    tmp.y = y + op.x;
    return tmp;

}

void vector_2d::print(const char *str = 0)
{
    if(str)
    cout<< str << "=";
    cout<< "("<<x<<","<<"y"<<")"<<endl;
}
int main()
{
    vector_2d u,v(2),w(3,4);
    u.print("u");
    v.print("v");
    w.print("w");
    (v+w).print("v+w");    
}