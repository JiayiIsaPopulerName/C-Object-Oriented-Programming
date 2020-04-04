#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Vec
{   
    double *v;
    int len; 
    public:
		Vec(int a,  double *b,int n);
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
class n_exception
{
    private:
        int i;
    public:
    string comment;
        n_exception(string commen) : comment(commen){}       
        ~n_exception(){}
};
Vec::Vec(int a,double *b,int n)
{
    if(a!=n)
        throw n_exception("число элементов массива не совпадает с количеством элементов в массиве.");
    len = a;
    v = new double[len];   
    for(int i=0;i<len;i++) 
        *(v+i) = *(b+i);
}
Vec::Vec(int a)
{
    if(a<0)
        throw n_exception("неправильное число элементов");
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
    if (!(coord >= 0 &&  coord < len))
        throw ("неправильный номер  координаты.");
    v[coord] = arg;
}
double Vec::get(int coord)
{
    if (!(coord >= 0 &&  coord < len))
       throw ("неправильный номер  координаты."); 
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
    try
    {
        double y1[3] = {1,2,3};
        double y2[5] = {2,1,0,5,7};
        Vec x(3, y1,sizeof(y1)/sizeof(y1[0])), y(5, y2,sizeof(y2)/sizeof(y2[0])), z(4);
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
    }
    catch(n_exception & obj)
    {
        cout<< obj.comment <<endl;
    }

    return 0;
}