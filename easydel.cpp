# include <fstream>
# include <cstring>
# include <algorithm>
# define NR 10005
using namespace std;
ifstream f("easydel.in");
ofstream g("easydel.out");
int i,j,n,m,x,y,N,maxx,S,I,nr,sol,VV;
int a[NR], ap[15], var[NR];
char s[NR];
int main ()
{
    f.getline(s+1, NR); n=strlen(s+1);
    for (i=1; i<=n; ++i)
        a[i]=s[i]-'0';

    while (n>0)
    {
        memset (ap, 0, sizeof(ap));
        for (i=1; i<=n; ++i)
            ap[a[i]]=1;

        maxx=-1;
        for (j=1; j<=9; ++j)
            if (ap[j])
            {
                nr=0; S=0; VV=0;
                for (i=1; i<=n; ++i)
                {
                    if (a[i]==j) ++nr;
                    else S+=nr, var[++VV]=nr;
                }
                if (S>maxx) maxx=S, I=j;
            }
        sol+=maxx;

        N=0;
        for (i=1; i<=n; ++i)
            if (a[i]!=I) a[++N]=a[i];
        for (i=N+1; i<=n; ++i)
            a[i]=0;
        n=N;
    }
    g<<sol<<"\n";

    return 0;
}
