#include<iostream>
#include<cmath>

using namespace std;

class Person
{
    private:
        string firstname;
        string lastname;
    protected:
        int age;
    public:
        Person(const string &fn = "none",const string &ln = "none", int age = 0): firstname(fn), lastname(ln),age(age){ cout << " Person ";}
        virtual void Print() const;// витуальная
        void Change_age(int new_age){age = new_age;}
        ~Person() { cout << " del Person ";}
};

void Person::Print() const
{
    cout << firstname << " " << lastname << " " << age;
    cout << endl;
}

class Student : public Person
{
    float average_mark;
    public:
        Student(const string & fn = "none", const string & ln = "none", int ag = 0, float am = 0.) : Person(fn, ln, ag),average_mark(am) {cout << "Student ";}
    virtual void Print() const;
    void Change_mark(float new_mark) 
    {
        average_mark = new_mark;
    }
    bool Bonus() const;
    virtual ~Student() { cout << " del Student ";};
};
class Goog_Student : public Person {};
class Aspirant : public Person {};
bool Student::Bonus() const
{
    if (age <= 18 && average_mark >=4.5)
        return true;
    else
        return false;
}
void Student::Print() const
{
    Person::Print();
    cout << "Average mark " << average_mark << endl;
}

int main ()
{
    const int NUM = 5;
    Person *pr[NUM];
    for(int i = 0; i < NUM; i++)
    {
        if (i%2)
            pr[i] = new Person("PF", "PL", i+20);
        else
            pr[i] = new Student("SF", "SL", i+15, i*1.2);
    }
    for(int i = 0; i < NUM; i++)
    {
        cout << i << endl;
        pr[i] -> Print();
    }
    for(int i = 0; i < NUM; i++)
        delete pr[i];
    return 0;
}
//void f(Person & op) { }

/*int main()
{
    Person pers0("A", "B", 32);
    pers0.Print();
    pers0.Change_age(33);
    pers0.Print();
    Student stud0("C", "D", 19, 4.5);
    stud0.Print();
    stud0.Change_age(17);
    stud0.Person::Print();
    if (stud0.Bonus())
        cout << " Bonus = OK" << endl;
    Person & pers1 = stud0;
    Person *pers2 = &stud0;
    //Student &stud1 = pers0;//error
    pers1.Print();
    pers2->Print();
    f(pers0);
    f(stud0);
    return 0;
}*/