#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream f("palindrom.in");
ofstream g("palindrom.out");
int l,ok;
char a[100],b[100];
int main()
{
    f.getline(a,100);
    f.getline(b,100);
    strcpy(a,b);
    g<<a;
    g<<endl;
    l=strlen(b);
    a[l]='a';
    g<<a;
    g<<endl;
    if(strchr (a, 'a')) g<<"1";
        else g<<"0";


    return 0;
}
