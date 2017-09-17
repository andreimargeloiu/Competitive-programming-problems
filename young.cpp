# include <fstream>
using namespace std;
ifstream f("young.in");
ofstream g("young.out");
int i,j,n,T,p,ap[1000],ap2[1000],a[100][100],nr[1000],q,VV,NR,I,var,t;
int sol[10000];
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
    {
        f>>nr[i];
        VV+=nr[i];
        for (j=1; j<=nr[i]; ++j)
            a[i][j]=1;
    }
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=nr[i]; ++j)
        {
            NR=nr[i]-j+1;
            I=i;
            while (a[I+1][j])
            {
                ++NR; ++I;
            }
            q=2;
            while (NR>1)
            {
                while (NR && NR%q==0)
                    NR/=q, ++ap2[q];
                ++q;
            }
        }
    }
    //desc suma factoriala
    for (i=2; i<=VV; ++i)
    {
        q=2; var=i;
        while (var>1)
        {
            while (var && var%q==0)
                var/=q, ++ap[q];
            ++q;
        }
    }
    sol[1]=1; VV=1;
    for (i=1; i<=1000; ++i)
    {
        for (j=1; j<=ap[i]-ap2[i]; ++j)
        {
            t=0;
            for (q=1; q<=VV; ++q)
            {
                sol[q]=sol[q]*i+t;
                t=sol[q]/10;
                sol[q]=sol[q]%10;
            }
            while (t) sol[++VV]=t%10, t=t/10;
        }
    }
    for (i=VV; i>=1; --i)
        g<<sol[i];
    return 0;
}
