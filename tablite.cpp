# include <fstream>
# include <algorithm>
# define MOD 60106
using namespace std;
ifstream f("tablite.in");
ofstream g("tablite.out");
int l[15],var[10][10],a[10][1010],b[10][1010];
int i,j,q,n,S,Suma,maxx,minn,nr,ant;
void preprocesare ()
{
    for (i=0; i<=9; ++i)//i
    {
        for (j=0; j<=9; ++j)//i-1
        {
            if (i<=1 || j<=1) var[i][++l[i]]=j;
            else {
                     maxx=max(i,j); minn=min(i,j);
                     if (maxx%minn!=0) var[i][++l[i]]=j;
                 }
        }
    }
    for (i=1; i<=9; ++i)
        a[i][i]=1;
}
int main ()
{
    f>>n>>S;
    preprocesare ();
    /*for (i=0; i<=9; ++i)
    {
        for (j=1; j<=l[i]; ++j)
            g<<var[i][j]<<" ";
        g<<"\n";
    }*/
    for (i=2; i<=n; ++i)
    {
        for (nr=0; nr<=9; ++nr)//fiecare cifra pe care vrem sa o punem acum
        {
             for (ant=1; ant<=l[nr]; ++ant)//fiecare cifra care putea fii anterioara
             {
                 for (j=1; j<=S; ++j)//fiecare suma
                 {
                     b[nr][j+nr]+=a[var[nr][ant]][j];
                     if (b[nr][j+nr]>=MOD) b[nr][j+nr]-=MOD;
                 }
             }
        }
        for (j=0; j<=9; ++j)
            for (q=1; q<=S; ++q)
            {
                a[j][q]=b[j][q];
                b[j][q]=0;
            }
    }

    for (i=0; i<=9; ++i)
        Suma+=a[i][S];

    g<<Suma%MOD<<"\n";
    return 0;
}
