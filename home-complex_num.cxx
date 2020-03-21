#include<iostream>

using namespace std;

class Complex
{
    private:
    double re, im;
    public:
        Complex(double r = 0, double i = 0) : re(r), im(i){}
        Complex(const Complex & obj){re = obj.re;im = obj.im;};
    public:
        friend const Complex operator+(const Complex &x, const Complex &y);
        friend const Complex operator-(const Complex &x, const Complex &y);
        friend const Complex operator*(const Complex &x, const Complex &y);
        const Complex& operator=(const Complex &op);
        const bool operator==(const Complex &op);
        friend ostream& operator << (ostream &os, const Complex &op);
};

const Complex operator+(const Complex &x,const Complex&y)
{
    return Complex (x.re+y.re, x.im+y.im);
}
const Complex operator-(const Complex &x,const Complex&y)
{
    return Complex (x.re-y.re, x.im-y.im);
}
const Complex operator*(const Complex &x, const Complex &y)
{
    return Complex(x.re*y.re - x.im*y.im, x.im*y.re + x.re*y.im);
}
const Complex& Complex::operator=(const Complex &op)
{
    re = op.re;
    im = op.im;
    return *this;
}
const bool Complex::operator==(const Complex &op)
{
    ((re == op.re) && (im == op.im))?true:false;  
}
ostream &operator << (ostream &os, const Complex &op)
{
    if (op.re == 0 && op.im != 0)
        os << op.im << "i";
    else
    if (op.re != 0 && op.im == 0)
        os << op.re;
    else
    if (op.re == 0 && op.im == 0)
        os << "0";
    else
    os << op.re << "," << op.im << "i";
    return os;
}

int main()
{
   Complex c(1,2), g(3), v;
   cout << "c =" << c << endl;
   cout << "g =" << g << endl;
   cout << "v =" << v << endl;
   v = 4.*c*2.;
   cout << "v =" << v << endl;
   g = 3.-g+c-2.*v;
   cout << "g =" << g << endl;
   cout << "2.*g*v =" << 2.*g*v << endl;
   v = g = c;
   if (c == g)
        v = 2.*Complex(0,1);
   else
        v = 2.;
   cout << "c = " << c << " g = " << g << " v = " << v << endl;
   return 0;
}