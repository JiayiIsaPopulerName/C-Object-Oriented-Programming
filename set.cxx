# include<iostream>
using namespace std;


template<typename T>
class set
{
    private:
        T data ;
        T id;
        T n_set;
    public:
        set(T dat, T idd, T se){this->data=dat; this->id=idd; this->n_set =se;}
        void add(T new_data, T new_id, T new_se);
        void del(T del_id, T del_se);
        void in(T dat,T idd,T se);
        set<T> & operator*(const set<T> & obj);//пересечение множеств
        set<T> & operator+(const set<T> & obj);//объединение множест   
};
    template<typename T>
    void set<T>::add(T new_data, T new_id, T new_se)
    {
        set(new_data, new_id, new_se);
    }

    template<typename T>
    void set<T>::del(T del_id, T del_set)
    {
        set(0,del_id,del_set);
    }

    template<typename T>
    void set<T>::in(T dat,T idd,T se)//проверка вхождения элемента
    {
        for(int i=0; i<10; i++)
            {
                if(set(dat,i,se) == set(dat,idd,se))
                    cout<<"повторение элемента"<<endl;
            }
    }

    template<typename T>
    set<T> & operator*(const set<T> & obj)
    {
        for (int i=0; i<10; i++)
            for(int j=0; j<10; j++)
            {
                if(set(obj.dat,obj.idd) == set(dat,i,j))
                    return obj;
            }
    }
    template<typename T>
    set<T> & operator+(const set<T> & obj)
    {
        for (int i=0; i<10; i++)
            for(int j=0; j<10; j++)
            {
                if(set(obj.dat,obj.idd) == set(dat,i,j))
                    return obj;
            }
    }



int main()
{
    set se(29,0,1);
    set se(65,0,2);
    set se(32,1,2);

    set se.add(34，2,1);
    set se.del(3,1);
    set se.in(29,1);


    cout<<"пересечение множеств : " << se(1)*se(2) << endl;
    cout<<"объединение множеста : " << se(1)+se(2) << endl;
    

}