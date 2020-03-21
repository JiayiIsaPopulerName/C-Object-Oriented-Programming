#include<iostream>
#include<fstream>
#include<cstdio>
#include<cerrno>
#include<cstring>

using namespace std;

class FileException
{
    char *filename;
    string comment;
    int err_code;
    public:
        FileException(const char *arg_file, const char *arg_comment);
        FileException(const FileException & other);
        ~FileException();
    public:
        char *GetFilename() {return filename;}
        string GetComment() {return comment;}
        int GetErrCode() {return err_code;}
    private:
        static char* strdup(const char * arg);
};

FileException::FileException(const char *arg_file, const char *arg_conment)
{
    filename = strdup(arg_file);
    comment = arg_conment;
    err_code = errno; 
}

FileException::FileException(const FileException & other)
{
    filename = strdup(other.filename);
    comment = other.comment;
    err_code = other.err_code;
}

FileException::~FileException()
{
    delete [] filename;
}

char* FileException::strdup(const char * arg)
{
    char* res = new char[strlen(arg+1)];
    strcpy(res, arg);
    return res;
}
int count_symbols(const char * file_name)
{
    int n = 0;
    ifstream fin(file_name);

    if (!fin.is_open())
        throw FileException(file_name,"can't open file");
    else
    {
        while(fin.get() != EOF)
            n++;   
    }
    fin.close();
    return n;
} 

int main(int argc, char **argv)
{
    int n;
    if (argc < 2)
    {
        cerr << "No file name" << endl;
        return -1;
    }
    try
    {
        n = count_symbols(argv[1]);
        cout << "File " << argv[1] << " contains " << n << " symbols" << endl;
    }
    catch(FileException & ex)
    {
        cerr << "Exception:(string):" << ex.GetComment() << " " << ex.GetFilename() << endl;
        cerr << "Error code: " << strerror(ex.GetErrCode()) << " " << endl;
        return 1;
    }
    
    ofstream fout("data.txt");

    if (!fout.is_open())
    {
        cerr << " Can't open file data,txt" << endl;
        return -2;
    }
    fout << n << " ";
    fout.close();
    
    return 0;
}
