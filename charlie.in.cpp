# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 100005
using namespace std;
ifstream f("charlie.in");
ofstream g("charlie.out");
int i,j,n,m,VV,maxx,tip,niv;
char s[NR];
int st[NR];

void procesare ()
{
    while (niv>=3 && st[niv-2]>st[niv-1] && st[niv-1]<st[niv])
    {
        maxx+=max(st[niv-2], st[niv]);
        st[niv-1]=st[niv]; st[niv]=0;
        --niv;
    }
}

int main ()
{
    f>>tip; f.get();
    f.getline (s+1, NR); n=strlen(s+1);

if (tip==1)
{
    VV=1; i=1;
    while (i<=n-2)
    {
        maxx=max(maxx, VV);
        if (s[i]>s[i+1] && s[i+1]<s[i+2])
        {
            VV+=2; i=i+2;
        }
        else
        {
            ++i; VV=1;
        }
    }
    if (maxx==1) maxx=0;
    g<<maxx<<"\n";
}
else
{
     VV=1;
     for (i=1; i<=n; ++i)
     {
         st[++niv]=s[i]-'0';
         procesare ();
     }

     for (i=1; i<=niv; ++i)
         g<<st[i];
     g<<"\n"<<maxx<<"\n";
}


    return 0;
}
