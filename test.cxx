#include<iostream>
using namespace std;

class A
{
    int i;
    public:
    A(int arg_i = 0) : i(arg_i) {}
    A(const A& a){i=a.i;}
    const A& operator*=(const A& a)
    {
        i*=a.i;
        return *this;
    }
    int get(){return i;}       
};
int main () 
{
A a1 (5), a2 = 3;
a1 *= 10;
a2 *=a1 *= 2;
cout << a1.get() << a2.get() << endl;
return 0;
}