#include <iostream>
#include <cmath>

using namespace std;

class complex
{
    double re,im;
    public:
    complex(double a, double b)//kon =0 =0
    {
        re = a;
        im = b;
        }
    complex()//kon по мочанью
     {
         re = 0;
         im = 0;
         }
    complex(double a)//kon преобразования
    {
        re = a;
        im = 0;
        }
        
    double method()//method
    {
        return sqrt(re*re+im*im);
        }
    void print()//method
    {
        cout << "("<< re<< "(" << im << ")" << endl;
        }
};

int main()
{
   complex d(2,3);
   complex c;
   complex e = 3;
   cout<< "method = " << d.method () << endl;
    return 0;
}

