#include<iostream>
using namespace std;

class figure
{
    protected:
        double x,y,z;
    public:
        figure(double coordx = 0, double coordy = 0, double coordz = 0):x(coordx),y(coordy),z(coordz){}
        ~figure(){}
        //virtual void move() = 0;
        virtual void print() = 0;
        virtual double volume() = 0;
        virtual double square() = 0;
};
class cube : public figure
{
    private:
    double l;
    public:
    cube(double coordx = 0, double coordy = 0, double coordz = 0,double length = 0) : figure(coordx,coordy,coordz),l(length){}
    virtual void move(double new_x,double new_y,double new_z);
    virtual void print();
    virtual double volume();
    virtual double square();
    virtual ~cube(){} 
};
    void cube::move(double new_x,double new_y,double new_z)
    {
        x=new_x;
        y=new_y;
        z=new_z;
    }
    void cube::print()
    {
        cout<<"координаты центра куба:("<< x << ","<< y << ","<< z << ")"<<endl;
    }
    double cube::volume()
    {
        return l*l*l;
    }
    double cube::square()
    {
        return 6*l*l;
    }

class sphere : public figure
{
    private:
    double r;
    public:
    sphere(double coordx = 0, double coordy = 0, double coordz = 0,double radi = 0):figure(coordx,coordy,coordz),r(radi){}
    virtual void move(double new_x,double new_y,double new_z);
    virtual void print();
    virtual double volume();
    virtual double square();
    virtual ~sphere(){}
};
    void sphere::move(double new_x,double new_y,double new_z)
    {
        x=new_x;
        y=new_y;
        z=new_z;
    }
    void sphere::print()
    {
        cout<<"координаты центра шара:("<< x << ","<< y << ","<< z << ")"<<endl;
    }
    double sphere::volume()
    {
        return (4/3)*3.14*r*r*r;
    }
    double sphere::square()
    {
       return 4*3.14*r; 
    }
class cylinder : public figure
{
    private:
    double r,h;
    public:
    cylinder(double coordx = 0,double coordy = 0,double coordz = 0,double radi = 0,double hight = 0) : figure(coordx,coordy,coordz),r(radi),h(hight){}
    virtual void move(double new_x,double new_y,double new_z);
    virtual void print();
    virtual double volume();
    virtual double square();
    virtual ~cylinder(){}
};
    void cylinder::move(double new_x,double new_y,double new_z)
    {
        x=new_x;
        y=new_y;
        z=new_z;
    }
    void cylinder::print()
    {
        cout<<"координаты центра цилиндра:("<< x << ","<< y << ","<< z << ")"<<endl;
    }
    double cylinder::volume()
    {
        return r*r*3.14*h;
    }
    double cylinder::square()
    {
        return h*2*r*3.14 + 2*r*r*3.14;
    }

int main()
{
    cube cub(2,3,4,1);
    sphere spher(6,3,9,2);
    cylinder cylinde(0,2,7,3,4);

    cub.print();
    cout << "cube volume= " << cub.volume() << endl;
    spher.print();
    cout << "sphere square= " << spher.square() << endl;
    cylinde.print();
    cout << "cylinder square= " << cylinde.square() << endl;

    cout << endl;

    cub.move(3,4,5);
    spher.move(2,6,9);
    cylinde.move(0,4,1);

    cub.print();
    cout << "cube volume= " << cub.volume() << endl;
    spher.print();
    cout << "sphere square= " << spher.square() << endl;
    cylinde.print();
    cout << "cylinder square= " << cylinde.square() << endl;
    return 0;
}
