#include<iostream>
#include<string>

using namespace std;

class date
{
    int y,m,d;
    public:
    date(int arg_y,int arg_m,int arg_d):y(arg_y),m(arg_m),d(arg_d){}
    friend istream operator >> (ostream & os,const date & obj)
    {
        if((arg_m >12)&&(arg_d>31))
            throw exc("wrong date");

        if(!" ")
            is >> obj.y >> obj.m>>obj.d;    
    }
    friend ostream operator << (ostream & os,const date & obj)
    {
        os<< obj.y << " "<< obj.m<< " "<< obj.d<<endl;
    }
};

class exc :public date
{
    string comment;
    public:
    exc(string commen) : comment(commen){}       
     ~exc(){}

};