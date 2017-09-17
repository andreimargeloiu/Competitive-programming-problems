#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream f("sortarecuvinte1.in");
ofstream g("sortarecuvinte1.out");
char a[205][35],s[100],aux[100];
int i,voc,j,maxim,l,n;
int main()
{
    n=0;
    while(f.getline(s,50))
    {
        ++n;
        strcpy(a[n],s);
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(strcmp(a[i],a[j])==1)
            {
                strcpy(aux,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],aux);
            }
        }
    }
    for(i=1;i<=n;i++)
        g<<a[i]<<"\n";


    return 0;
}
