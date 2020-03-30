#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cerrno>
using namespace std;

class FileException
{
    char *filename;
    string comment;
    int err_code;
    public:
    FileException(const char *arg_file,const char *arg_conmment);
    FileException(const FileException &other);
    ~FileException();
    char *GetFilename(){return filename;}
    string GetComment(){return comment;}
    int GetErrCode(){return err_code;}
    private:
    static char*strdup(const char *arg);    
};

FileException::FileException(const char *arg_file,const char *arg_comment)
{
    filename = strdup(arg_file);
    comment = arg_comment;
    err_code=errno;
}
FileException::FileException(const FileException & other)
{
    filename = strdup(other.filename);
    comment = other.comment;
    err_code=other.err_code;
}
FileException::~FileException()
{
    delete [] filename;
}
char* FileException::strdup(const char *arg)
{
    char* res =new char[strlen(arg)+1];
    strcpy(res,arg);
    return res;
}
int count_symbols(const char *file_name)
{
    int n = 0;
    ifstream fin(file_name);//read; ofstream-write in file;

    if (!fin.is_open())
        throw FileException(file_name,"cant open file")
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
    catch(FileException & ex)
    {
        cerr <<"exception:(string):"<<ex.GetComment()<<" "<<ex.GetFilename()<<endl;
        cerr<<"errorcode:"<<strerror(ex.GetErrCode())<<endl;
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