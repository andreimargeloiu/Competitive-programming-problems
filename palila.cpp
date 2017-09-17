#include <fstream>
#include <cstring>
#define NMAX 500005

using namespace std;

char s[NMAX];
int n,i,sol,x;
int main()
{
    ifstream f("palalila2.in");
    ofstream g("palalila2.out");
    f.getline(s+1,NMAX);
    int x=strlen(s+1);
    sol=0;i=1;
    while(i<x)
    {
        while(s[i] >= s[i+1] && i<x) ++i;
        ++sol;
        if(i<x)
        {
            while(s[i] <= s[i+1] && i<x) ++i;
            ++sol;
        }
    }
    g<<sol<<"\n";
    return 0;

}
