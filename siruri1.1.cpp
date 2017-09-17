#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,j,n,ok,l;
char ch1,ch2,s[105];
int main()
{
    f.getline(s, 100);
    l=strlen(s);
    ok=1;
    for(i=1;i<=l-1;i++)
        if(s[i]-s[i-1]!=1) ok=0;
    g<<ok;


    return 0;
}
