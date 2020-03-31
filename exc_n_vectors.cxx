#include <iostream>
#include <cmath>
using namespace std;

class Vec
{   
    double *v;
    int len; 
    public:
		Vec(int a,  double *b);
		Vec(int a);
		Vec(const Vec &obj); 
		~Vec();
    public:
		void set(double arg, int coord);
		double get(int coord);
		double euc_norm();
		double max_norm();
		void print();
};
class nexception
{
    private:
        int i;
    public:
        nexception(int n);
        nexception();
        int get();
        int set();
        ~nexception(){}
};
nexception::nexception(int n)
{

}
nexception::nexception()
{

}
int nexception::get()
{

}
Vec::Vec(int a,double *b)
{
    len = a;
    v = new double[len];   
    for(int i=0;i<len;i++) 
        *(v+i) = *(b+i);
}
Vec::Vec(int a)
{
    len = a;
    v = new double[len];  
 	for(int i = 0; i < len; i++)
		*(v+i) = 0;
}
Vec::Vec(const Vec &obj)
{
    len = obj.len;
	v = new double[obj.len];
    for(int i = 0;i<len;i++) 
	    *(v+i) = *(obj.v+i);
}
Vec::~Vec()
{
    delete [] v;            
}
void Vec::set(double arg,int coord)
{
    if (coord >= 0 &&  coord < len)
    v[coord] = arg;
}
double Vec::get(int coord)
{
    return v[coord];
}
double Vec::euc_norm()
{
    double euc;
    int i;
    for(int i = 0; i < len; i++)
        euc+=sqrt(v[i]*v[i]);
        return euc;
}
double Vec::max_norm()//method
{
    int i;
    double max=v[1];
    for(i=0;i < len;i++)
        if(max<abs(v[i]))
            max = abs(v[i]);
    return max;
}
void Vec::print()
{
    cout << "(";
	for(int i = 0; i < len; i++)
	{
		cout << v[i];
		if (i == (len - 1))
			cout << ")" << endl;
		else
			cout << ",";
	}
}

int main(void)
{
    double y1[3] = {1,2,3};
    double y2[5] = {2,1,0,5,7};
    Vec x(3, y1), y(5, y2), z(4);
    Vec u = x;

    y.print();
    x.print();
    z.print();
    u.print();

    x.set(23, 2);  u.set(34, 1);  z.set(-3, 3);
    cout << "x[2] = " << x.get(2) << endl;
    cout << "u[1] = " << u.get(1) << endl; 
    cout << "euc_norma y: " << y.euc_norm() << endl;
    cout << "max_norma z: " << z.max_norm() << endl;
    return 0;
}