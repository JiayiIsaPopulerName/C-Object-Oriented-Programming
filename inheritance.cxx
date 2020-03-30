#include<iostream>
#include<string>
using namespace std;

class event
{
    private:
        int year;
        int month;
        int day;
        string sessio;         //!
    public:
        event(const string &subj = "none",int y=0,int m=0,int d=0) : sessio(subj), month(m), year(y), day(d){}
        virtual void print_res() const;
        virtual void change_mark(bool new_mark){}      //{}; !              
        virtual void change_mark(int new_mark2){} //pure virtual function ?
        void change_date(int new_year,int new_month,int new_day);
        virtual ~event(){}
};  

    void event::change_date(int new_year,int new_month,int new_day)
    {
        year=new_year;
        month=new_month;
        day=new_day;
    }
    void event::print_res() const
    {
        cout << "Название предмета и дата:"<<' '<< sessio <<' ' << year <<' '<< month <<' '<< day<<' ';
    }
class test : public event
{
    bool mark;
    public:
        test(const string &subj,int y,int m,int d,bool mr) :event(subj,y,m,d),mark(mr){}
        virtual void print_res()const;
        virtual void change_mark(bool new_mark);//override;
        //virtual void change_mark(int new_mark);
        virtual ~test(){}
};
    void test::print_res()const 
    {
        int i;
        event::print_res();
        if(mark)
            cout << "false!" << endl;
        else
        cout << "true" << endl;
    }
    void test::change_mark(bool new_mark) 
    {
        //event::change_mark(new_mark);           //!
        mark =  new_mark;//subj.mark
    }
   /* void test::change_mark(int new_mark)
    {

    }*/

class exam : public event
{
    private:    
        int mark;
    public:
        exam (const string &subj,int y,int m,int d,int mr) : event(subj,y,m,d),mark(mr){}
        virtual void change_mark(int new_mark2);
        virtual void print_res()const;
       // void change_mark(bool new_mark);
        virtual ~exam(){}
};
    void exam::print_res()const 
    {
        event::print_res();
        if(mark)
            cout << mark << endl;
    }
    void exam::change_mark(int new_mark2) 
    {
        //event::change_mark(new_mark2);
        mark = new_mark2;
    }
   /* void exam::change_mark(bool new_mark)
    {

    }*/

int main()
{
    const int NUM = 7;
    event *session[NUM];

    session[0] = new test("MS Office", 2019, 12, 23, true);
    session[1] = new exam("Operation  System", 2020, 1, 15, 4);  //  Экзамен было страшно
    session[2] = new test("Practicum", 2019, 12, 25, false);  // Надо было больше заниматься
    session[3] = new exam("Differential equation", 2020, 1, 20, 4); // Это было Интересно
    session[4] = new test("Theory of probability", 2020, 12, 29, true); // Это было абтрактно
    session[5] = new exam("Philosophy", 2020, 1, 24, 3);  // Я не люблю философию
    session[6] = new exam("C++", 2020, 1, 11, 4);  

    for(int i = 0; i < NUM; i++)
       session[i]->print_res();

    session[2]->change_date(2020, 2, 29); 
    session[2]->change_mark(true);  // все сдал

    session[1]->change_date(2020, 2, 15);
    session[1]->change_mark(3);  // Я наконец сдал этот экзамен!!!

    for(int i = 0; i < NUM; i++)
       session[i]->print_res();

    for(int i = 0; i < NUM; i++)
        delete session[i];

    return 0;
}