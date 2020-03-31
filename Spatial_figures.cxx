#include<iostream>
using namespace std;

class figure
{
    protected:
        int x,y,z;
    public:
        figure(int coordx = 0,int coordy = 0,int coordz = 0):x(coordx),y(coordy),z(coordz){}
        virtual ~figure(){}
        virtual void move();
        virtual void print();
        virtual double volume();
        virtual double square();
};
class cube : public figure
{
    int l;
    public:
    cube(int coordx = 0,int coordy = 0,int coordz = 0,int length = 0) : figure(coordx,coordy,coordz),l(length){}
    virtual void move(int new_x,int new_y,int new_z);
    virtual void print();
    virtual double volume();
    virtual double square();
    virtual ~cube(){} 
};
    void cube::move(int new_x,int new_y,int new_z)
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
    int r;
    public:
    sphere(int coordx = 0,int coordy = 0,int coordz = 0,int radi = 0):figure(coordx,coordy,coordz),r(radi){}
    virtual void move(int new_x,int new_y,int new_z);
    virtual void print();
    virtual double volume();
    virtual double square();
    virtual ~sphere(){}
};
    void sphere::move(int new_x,int new_y,int new_z)
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
    int r,h;
    public:
    cylinder(int coordx = 0,int coordy = 0,int coordz = 0,int radi = 0,int hight = 0) : figure(coordx,coordy,coordz),r(radi),h(hight){}
    virtual void move(int new_x,int new_y,int new_z);
    virtual void print();
    virtual double volume();
    virtual double square();
    virtual ~cylinder(){}
};
    void cylinder::move(int new_x,int new_y,int new_z)
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
    spher.print();
    cylinde.print();

    cub.move(3,4,5);


    return 0;
}
