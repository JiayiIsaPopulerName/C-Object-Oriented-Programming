#include<iostream>
#include<cmath>

using namespace std;

template<typename T>


    template<typename V>

int main()
{
    using namespace std; 
    int arri[6] = {1, 2, 5, 3, 1, -1};
    double arrd[4] = {2.3, -1.3, 8.7, 4.5};
    const char * arrc[5] = {"first", "second", "third", "long string", "another string"};

    cout << "max of integer = " << maxn(arri, 6) << endl;
    cout << "max of double = " << maxn(arrd, 4) << endl;
    cout << "max string is " << maxn(arrc, 5) << endl;

    return 0;
}