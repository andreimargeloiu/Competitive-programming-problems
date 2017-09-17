# include <fstream>
# include <cstring>
# include <algorithm>
using namespace std;
ifstream f("tort.in");
ofstream g("tort.out");
int a[100],b[100],c[100],sum[100],sol[100];
int i,S,l,la,lb,lc,lsum,lsol;
char s[100],var[100],*p;
void etalonare (int a[],int &l)
{
    int i,t=0;
    for (i=1; i<=l; ++i)
    {
        t=t+a[i];
        a[i]=t%10;
        t=t/10;
    }
    while (t) a[++l]=t%10,t=t/10;
}
void SUMA ()
{
    int i,t=0;
    lsum=max(la,lb);
    for (i=1; i<=lsum; ++i)
    {
        t=a[i]+b[i]+t;
        sum[i]=t%10;
        t=t/10;
    }
    while (t) sum[++lsum]=t%10,t=t/10;
}
void produs (int a[], int b[], int c[], int la, int lb, int &lc)
{
    int i,j,t=0;
    lc=la+lb-1;
    for (i=1; i<=la; ++i)
        for (j=1; j<=lb; ++j)
            c[i+j-1]+=a[i]*b[j];

    for (i=1; i<=lc; ++i)
    {
        t=c[i]+t;
        c[i]=t%10;
        t=t/10;
    }
    while (t) c[++lc]=t%10,t=t/10;
}
void impartire ()
{
    int i,t=0;
    for (i=lsol; i>=1; --i)
    {
        t=10*t+sol[i];
        sol[i]=t/2;
        t=t%2;
    }
    while (lsol>1 && !sol[lsol]) --lsol;
}
int main ()
{
    f.getline(s,100);

    p=strtok(s," ");
    strcpy(var,p);
    l=strlen(var);
    for (i=l-1; i>=0; --i)
        a[++la]=var[i]-'0';

    p=strtok(NULL," ");
    strcpy(var,p);
    l=strlen(var);
    for (i=l-1; i>=0; --i)
        b[++lb]=var[i]-'0';

    ++a[1]; ++b[1];
    etalonare (a,la);
    etalonare (b,lb);
    SUMA (); //a+b+2
    produs (a,b,c,la,lb,lc);//(a+1)*(b+1)
    produs (c,sum,sol,lc,lsum,lsol);//(a+1)*(b+1)*(a+b+2)
    impartire ();
    for (i=lsol; i>=1; --i)
        g<<sol[i];
    //S=(a+1)*(b+1)*(a+b+2)/2;

    g<<"\n";

    return 0;
}
