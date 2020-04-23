#include <iostream>
#include <string>
 using namespace std;

 class vec
 {
    private:
        int x,y;
    private:
        vec(int coordx = 0,int coordy = 0):x(coordx),y(coordy){}
        vec(int a):x(a),y(0){}
    
        friend istream operator >> (ostream & os,const vec & obj);
        friend ostream operator << (ostream & os,const vec & obj);        
 };
    istream operator>> (ostream & os,const vec & obj)
    {
        os >> obj.x >>obj.y;
    }
    ostream operator<< (ostream & os,const vec &obj)
    {
        os <<obj.x <<obj.y<<endl;
    }
 class Exception
 {
    protected:
        string Comment;
        Exception(const string comment):Comment(comment){}
        ~Exception(){}   
 };
 class check : public Exception
 {
    private:
        int x,y;
    public:
        check(string comment,int coordx,int coordy) : Comment(comment),x(coordx),y(coordy){}
    
 };


