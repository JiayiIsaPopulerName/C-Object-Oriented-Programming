#include <iostream>
#include <cmath>
using namespace std;

class Vec
{
        double *v;
        int len;
    public:
        Vec(int a, double *b);
        Vec(int b);
        Vec(const Vec &obj);
        ~Vec();
    public:
        void set(int nmb,double arg);
        int get(int coord);
        double euc_norm();
        double max_norm();
        void print();
        const Vec operator+(const Vec &obj);
        const Vec operator*(const Vec &obj)
        {
            len=obj.len;
            for(int i=0;i < obj.len;i++)
                return *Vec(obj.len,*((v+i)*(obj.v+i));
        }
        Vec operator=(const Vec &obj);
        double operator[](int x);
        friend ostream& operator<<(ostream &os,const Vec &obj);
};

Vec::Vec(int a,double *b)
{   
    len=a;
    v= new double [len];
    for(int i=0;i<len;i++)
        *(v+i) = *(b+i);      
}
Vec::Vec(int a)
{
    len = a;
    v = new double[len];  
 	for(int i = 0; i < len; i++)    //!
		*(v+i) = 0;
}
Vec::Vec(const Vec &obj)
{
    len = obj.len;
	v = new double[obj.len];
    for(int i = 0;i<len;i++)         //!
	    *(v+i) = *(obj.v+i);
}
Vec::~Vec(){delete [] v;}           //!

void Vec::set(int coord,double arg)
{
    if (coord >= 0 &&  coord < len)
    v[coord] = arg;
}
int Vec::get(int coord)
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
    double max=v[1];
    for(int i=0;i < len;i++)
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
const Vec Vec::operator+(const Vec &obj) 
{
    for(int i=0;i < len;i++)
        return (obj.len,*(v+i)+obj.(v+i));
}
Vec Vec::operator=(const Vec &obj)
{
    len=obj.len;
    v=new double[len];
    for(int i=0;i < len;i++)
        *(v+i)=*(obj.v+i);
        return *this;
}
double Vec::operator[](int x)
{

    return *(v+x);
}
ostream &operator<<(ostream& os,const Vec &obj)
{   
    cout<<"(";
    for(int i=0;i<obj.len;i++)
       {
           cout << obj.v[i];
		if (i == (obj.len - 1))
			cout << ")" << endl;
		else
			cout << ",";
       }
       return os;
}
int main(void)
{
        double y1[4] = {1,2,3,4};
        double y2[4] = {-2,1,3,-3};

        Vec u(4, y1), v(4, y2);
        Vec w(4);

        cout << "u = " << u << endl;
        cout << "v = " << v << endl;
        w = u = u;
        cout << "w = u = " << w << endl;
        w = 4.*u + v*3;
        cout << "w = 4.*u + v*3 = " << w << endl;
        w[2] = 3;
        w[0] = -1;
        cout << "w = " << w << endl;
    return 0;
}