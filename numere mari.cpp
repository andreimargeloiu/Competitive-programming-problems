# include <fstream>
# include <cstring>
# define NR 100
using namespace std;
ifstream f("mari.in");
ofstream g("mari.out");
int i,j,n,m,l,la,lb,t,tip;
int a[NR], b[NR], c[NR];
char s[NR];
void tipar ()
{
    for (i=c[0]; i>=1; --i)
        g<<c[i];
    g<<"\n";
}
void adunare ()
{
    c[0]=max(a[0], b[0]);
    for (i=1; i<=c[0]; ++i)
    {
        t=t+a[i]+b[i];
        c[i]=t%10;
        t=t/10;
    }
    while (t) c[++c[0]]=t%10, t=t/10;
}
void scadere ()
{
    c[0]=max(a[0], b[0]);
    for (i=1; i<=a[0]; ++i)
    {
        c[i]=t+a[i]-b[i];
        if (c[i]<0) t=-1, c[i]+=10;
               else t=0;
    }
    while (c[c[0]]==0) --c[0];
}
void inmultire ()
{
    c[0]=a[0]+b[0]-1;
    for (i=1; i<=a[0]; ++i)
        for (j=1; j<=b[0]; ++j)
            c[i+j-1]+=a[i]*b[j];

    for (i=1; i<=c[0]; ++i)
    {
        t=t+c[i];
        c[i]=t%10;
        t=t/10;
    }
    while (t) c[++c[0]]=t%10, t=t/10;
}
void impartire (int x)
{
    int R=0;
    for (i=a[0]; i>=1; --i)
    {
        R=R*10+a[i];
        c[i]=R/x;
        R=R%x;
    }
    c[0]=a[0];
    while (c[0]>0 && ! c[c[0]]) --c[0];
}
int main ()
{
    f.getline (s+1, NR); la=strlen(s+1);
    for (i=la; i>=1; --i)
        a[la-i+1]=s[i]-'0';

    f.getline (s+1, NR); lb=strlen(s+1);
    for (i=lb; i>=1; --i)
        b[lb-i+1]=s[i]-'0';

    a[0]=la; b[0]=lb;

    f>>tip;
    if (tip==1) adunare (); //intre numere mari
    if (tip==2) scadere (); //intre nr mari, pp a > b
    if (tip==3) inmultire (); //intre numere mari
    if (tip==4) impartire (5); //unui mare la un scalar

    tipar ();

    return 0;
}
