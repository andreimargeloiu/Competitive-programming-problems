# include <fstream>
using namespace std;
ifstream f("superstring.in");
ofstream g("superstring.out");
int i,j,n,m,q,rez;
long long ci,cs,mij,k;
int numara (long long k)
{
   int var=0;
   while (k>0)
      ++var,k=k/10;
   return var;
}
int numara2(long long x, int d)
{
    d=numara(x)-d;
    while(d>0)
        x/=10, --d;
    return x%10;
}
long long cifre (long long k)
{
    int Ncif=numara(k);
    long long noua=0,zece=1,suma=0,prec=0;
    for (i=1; i<=Ncif-1; ++i)
    {
        noua=noua*10+9; zece=zece*10;
        suma+=(noua*zece/2-prec)*i;
        prec=noua*zece/2;
    }
    suma+=(k*(k+1)/2-prec)*Ncif;
    return suma;
}
int main ()
{
    f>>n;
    for (q=1; q<=n; ++q)
    {
        f>>k;
        ci=1; cs=1000000000; rez=0;
        while (ci<=cs)
        {
            mij=(ci+cs)/2;
            if (k<=cifre(mij)) cs=mij-1;
                else ci=mij+1,rez=mij;
        }
        k-=cifre(rez);
        ++rez;
        k%=numara(rez);
        if (k==0) k=numara(rez);
        rez=numara2(rez,k);
        g<<rez<<"\n";
    }

    return 0;
}
