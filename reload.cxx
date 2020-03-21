#include <iostream>
#include <string>
#include <string>
using namespace std;

class mystring
{
    public:
    string s;
    mystring(const mystring &obj);
    mystring(string str);
    ~mystring();

    public:
    const char Length();
    const bool IsEmpty();
    const string AddSymStr(string add = 0);
    const string InsertSybStr(string as=0);
    const string DeleteSybStr(int pos=0,string amt=0);
    const int FindSubstring(string subs);
    const string ChangeSubstring(int pos=0,int amount=0,string subs=0);
    const string print();
};

mystring::mystring(string str)
{
    string s = str;   
}
mystring::mystring(const mystring &obj)
{
    string s = 0;
    s = obj.s;
}
/*
mystring::~mystring()
{
    delete s;
}
*/
const char mystring::Length()
{
    return (sizeof(s));
}
const bool mystring::IsEmpty()
{   
    char l = sizeof(s);
    return l = NULL ? true : false;
}
const string mystring::AddSymStr(string add=0)
{
    string add;
    return s.push_back('add');
}
const string mystring::InsertSybStr(string as=0)
{
    return s.insert(0,as);
}
const string mystring::DeleteSybStr(int pos=0,string amt=0)
{
    return s.erase(pos,amt);
}
const int mystring::FindSubstring(string subs)
{
    return s.find(subs);
}
const string mystring::ChangeSubstring(int pos=0,int amount=0,string subs=0)
{
    return s.replace(pos,amount,subs);
}

int main(int argc,char **argv)
{
    string s;
    cout<<"input string : "<<endl;
    cin>>s;

}
