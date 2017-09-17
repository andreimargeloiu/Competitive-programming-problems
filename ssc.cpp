# include <fstream>
using namespace std;
ifstream f("ssm.in");
ofstream g("ssm.out");
int i,j,n,m,s,x,ci,cs,I,J,maxx;
int main ()
{
    f>>n; maxx=-99999999;
    s=-999999999; ci=1;
    for (i=1; i<=n; ++i)
    {
        f>>x;
        if (s+x>=x)
        {
            s=s+x;
            ++cs;
        }
        else
        {
            s=x;
            ci=cs=i;
        }
        if (s>maxx) maxx=s, I=ci, J=cs;
    }
    g<<maxx<<" "<<I<<" "<<J<<"\n";

    return 0;
}
