# include <fstream>
using namespace std;
ifstream f("back.in");
ofstream g("back.out");
int n,i,st[100],as,ev,vi,vf,rel;
void init (int k)
{
    st[k]=vi-rel;
}
void succesor (int k, int &as)
{
    if (st[k]+rel<=vf) st[k]+=rel,as=1;
        else as=0;
}
void valid (int k, int &ev)
{
    int i; ev=1;
    for (i=1; i<k; ++i)
        if (st[i]==st[k]) ev=0;
}
int solutie (int k)
{
    if (k==n) return 1;
    else return 0;
}
void tipar ()
{
    for (int i=1; i<=n; ++i)
        g<<st[i]<<" ";
    g<<"\n";
}
void back (int k)
{
    init (k);
    while (k>0)
    {
        do {
               succesor (k, as);
               if (as) valid (k, ev);
           }while (as && !ev);
        if (as)
        {
            if (solutie(k)) tipar();
               else {
                        ++k;
                        init(k);
                    }
        }
        else --k;
    }
}
int main ()
{
    f>>n;
    vi=1; vf=n; rel=1;
    back (1);

    return 0;
}
