#include <iostream>
using namespace std;

class ComplexNumber
{
    double re,im;
    public:
    ComplexNumber(){re =0;im =0;}
    ComplexNumber(double a,double b);
    ComplexNumber(double a);
    ComplexNumber(const ComplexNumber & obj);
    
    public:
    const  ComplexNumber operator+(const ComplexNumber &obj)const;
    friend const ComplexNumber operator-(const ComplexNumber &obj, const ComplexNumber&ob);
    const  ComplexNumber operator*(const ComplexNumber &obj)const;
    ComplexNumber & operator=(const ComplexNumber &obj)
    {
    re = obj.re;
    im = obj.im;
    return *this;
    }
    const bool operator==(const ComplexNumber &obj)const
    {
        return ((re ==obj.re)&&(im ==obj.im))? true:false; 

    }
    friend ostream & operator<<(ostream & os ,const ComplexNumber &obj)
    {
    os << obj.re << "+" <<"(" << obj.im <<")"<< "i";
    }
    friend const ComplexNumber operator*(double a,const ComplexNumber &obj)
    {
        return (a*obj.re,a*obj.im);
    }
};


ComplexNumber::ComplexNumber(double a,double b)
{
    re = a;
    im = b;
}
ComplexNumber::ComplexNumber(double a)
{
    re = a;
    im = 0;
}
const ComplexNumber ComplexNumber::operator+(const ComplexNumber &obj) const
{
    ComplexNumber tmp;
    tmp.re = re+obj.re;
    tmp.im = im+obj.im;
    return tmp; //omplexNumber(tmp.re=re +obj.re,tmp.im = im + obj.im);
}
const ComplexNumber operator-(const ComplexNumber &obj, const ComplexNumber&ob)
{  
    return ComplexNumber(obj.re-ob.re, obj.im-ob.im);
}
const ComplexNumber ComplexNumber::operator*(const ComplexNumber &obj)const
{  
    return ComplexNumber(re * obj.re , im * obj.im); 
}

int main()
{
   ComplexNumber c(1,2), g(3), v;
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
        v = 2.*ComplexNumber(0,1);
   else
        v = 2.;
   cout << "c = " << c << " g = " << g << "v = " << v << endl;
   return 0;
}
