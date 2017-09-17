#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int i,j,nrcuv,ok;
char s1[300], s2[300];
int main()
{
    f.getline(s1,256);
    f.getline(s2,256);
    for(i=0;i<strlen(s1);i++)
    {
        ok=1;
        for(j=0;j<strlen(s2);j++)
            if(s1[i+j]!=s2[j]) ok=0;
        if(ok==1) ok2=1;
    }

    return 0;
}
