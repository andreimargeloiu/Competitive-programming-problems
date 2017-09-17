#include <iostream>
#include<fstream>
#include<cmath>

using namespace std;
ifstream f("test.in");
ofstream g("test.out");
int n,i,ok,j,s;
int main()
{
    f>>n;
    ok=1;
    for(i=2; i<=n; i++)
    {
        ok=1;
        for(j=2; j<=sqrt(i); j++)
            if(i%j==0) ok=0;

        if(ok==1)
            s=s+i%3;

    }
    ok=1;
    for(i=2; i<=sqrt(s); i++)
        if(s%i==0) ok=0;
    if(ok==1)
        g<<"este prim";
    else
        g<<"nu este prim";


    return 0;
}
