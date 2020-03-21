#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int count_symbols(const char *file_name)
{
    int n = 0;
    ifstream fin(file_name);//read; ofstream-write in file;

    if (!fin.is_open())
    {
        cerr<<"cant open file"<<endl;
        return -1;
    }
    else
    {
        while (fin.get()!=EOF)//fin.open,fin.close
            n++;
    }
    fin.close();
    return n;   
}
int main(int argc,char **argv)
{
    int n;
    if(argc < 2)
    {
        cerr<<"no file name"<<endl;
        return -1;
    }
    try
    {
        n = count_symbols(argv[1]);
        cout << "file"<< argv[1]<< "contains"<<n<<"symbols"<<endl;
    }
    catch(const const char * exception)
    {
        cerr <<"exception:(string):"<< exception<< endl;
        return 1;
    }

    ofstream fout("data.txt");
    if(!fout.is_open())
    {
        cerr<<"cant open file"<<endl;
        return -2;
    }
    fout << n<< " ";
    fout.close();
    return 0;
}