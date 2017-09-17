#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int ok,l,i,ok2;
char ch, s[256], s2[256],*p;
int main()
{
    cin.getline(s, 300);
    p=strtok(s," ");
    while(p)
    {
        strcpy(s2,p);
        ok=0;
        ok2=0;
        l=strlen(s2);
        for(i=0;i<l;i++)
        {
            if(strchr("aeiou",s2[i])) ++ok;
            if(s2[i]=='a') ok2=1;

        }
        if(ok==2 && ok2==1)
            cout<<s2<<"\n";

        p=strtok(NULL," ");

    }


    return 0;
}
