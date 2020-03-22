#include <iostream>
using namespace std;

class person
{
    private:
        string firstname;
        string lastname;
        int age;
    public:
        person(const string &fn="none",const string &ln="none",int ag=0):
        firstname(fn),lastname(ln),age(ag){}
        void print() const;
        void change_age(int new_age){age=new_age;}
        ~person(){}
};
void person::print()const
{
    cout<< firstname <<" "<< lastname <<" "<<age;
    cout<< endl;
}
class student : public person
{
    float average_mark;
    public:
        student(const string &fn="none",const string &ln="none",int ag=0,float am =0.):person(fn,ln,ag),average_mark(am){}
        void print() const;
        void change_mark(float new_mark){average_mark=new_mark;}
};
void student::print()const
{
    person::print();
    cout<< "average mark" << average_mark <<endl;
}
int main()
{
    person pers0("a","b",32);
    pers0.print();
    pers0.change_age(33);
    pers0.print();
    student stud0("c","d",19,4.5);
    stud0.print();
    return 0;
}