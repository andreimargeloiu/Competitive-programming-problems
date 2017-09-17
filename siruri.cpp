# include <fstream>
# include <cstring>
# define LB(p) ((-p) & p)
# define NR 1000005
# define mod 41357
# define alpha 26
using namespace std;
ifstream f("siruri.in");
ofstream g("siruri.out");
int i,j,n,m,tip,S,x,ci,cs,poz;
int AIB[30], B[200005];
char s[NR];
int suma (int poz)
{
    int S=0;
    for (int i=poz; i>=1; i-=LB(i))
        S+=AIB[i];
    return (S%mod);
}
void actualizare (int poz, int S)
{
    for (int i=poz; i<=alpha; i+=LB(i))
        AIB[i]=(AIB[i]+S)%mod;
}
int cb (int x)
{
    int st=ci, dr=cs, mij;
    while (st<=dr)
    {
        mij=(st+dr)/2;
        if (x<B[mij]) dr=mij-1;
                 else st=mij+1;
    }
    return dr;
}
int main ()
{
    f>>tip>>n; f.get();
    f.getline(s+1, NR);
    if (tip==1)// nr de subsiruri strict crescatoare
    {
        for (i=1; i<=n; ++i)
        {
            x=s[i]-'a'+1;
            S=suma(x); //nr de subsuri anterioare
            actualizare (x, S+1);
        }
        S=suma (alpha);
        g<<S<<"\n";
    }
    else //tip==2 // partitionarea in subsiruri
    {
        ci=200000; cs=200000;
        B[cs]=s[1]-'a'+1;
        for (i=2; i<=n; ++i)
        {
            x=s[i]-'a'+1;
            if (x<B[ci]) B[--ci]=x;
            else {
                     poz=cb(x);
                     B[poz]=x;
                 }
            if (B[cs]==alpha && B[cs-1]==alpha) --cs;
        }
        g<<200000-ci+1<<"\n";
    }

    return 0;
}
