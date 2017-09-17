# include <fstream>
# include <cstring>
using namespace std;
ifstream f("doi.in");
ofstream g("doi.out");
int n,VV,t,l,a[505],i,I,nr;
char s[505];
void tampon ()
{
    while (l && a[l]==0) --l;
}
void impartire ()
{
    int i,R=0;
    for (i=l; i>=1; --i)
    {
        R=R*10+a[i];
        a[i]=R/2;
        R=R%2;
    }
    tampon();
}
int main ()
{
    f>>t; f.get();
    for (int o=1; o<=t; ++o)
    {
        f.getline(s+1, 505); l=strlen(s+1);
        for (i=1; i<=l; ++i)
            a[i]=s[l-i+1]-'0';
        VV=0;
        while (l)
        {
            ++VV;
            if (a[1]%2==0) impartire();
            else {
                     nr=a[1]+a[2]*10;
                     if ((nr==3 && l==1) || nr%4==1)
                     {
                         --a[1];
                         int t=0; I=1;
                         while (a[I]<0 || t==-1)
                         {
                             a[I]+=t;
                             if (a[I]<0) a[I]+=10, t=-1;
                             else t=0;
                             ++I;
                         }
                         tampon();
                     }
                     else {
                             ++a[1];
                             int t=0; I=1;
                             while (a[I]>9 || (I<=l && t))
                             {
                                 a[I]+=t;
                                 if (a[I]>9) a[I]-=10, t=1;
                                 else t=0;
                                 ++I;
                             }
                             if (t) a[++l]=1;
                          }
                 }
        }
        g<<VV<<"\n";
    }
    return 0;
}
