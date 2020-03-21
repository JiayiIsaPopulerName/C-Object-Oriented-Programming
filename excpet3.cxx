#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

class vac
{
    int *v;
    long len;
    public:
    vec(long n = 1)
    {
    if(n< 0)
        throw n;
    else
        len = n;
        v= (int*)malloc(len*sizeof(int));
        if(v == 0)
        throw "no memory";
        for(int i= 0;i<len;i++)
            v[i]=0;
    }
    ~vec(){free(v);}
    
}; 
int main()
{
    try{
        vec v1,v2,v2(-1),v3(1000000000);
    }
    catch(long n)
    {
        
    }
    catch(const char *str)
    {
        cerr<< str <<endl;//catch(...)
        return 2;
}