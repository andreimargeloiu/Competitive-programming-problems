# include <fstream>
# include <cstring>
using namespace std;
ifstream f("copii.in");
ofstream g("copii.out");
int i,j,n,nr,VV;
int ver[11][11],drum[100][100],a[100];
char s[100];
int verifica()
{
    int ok=1;
    for (i=1; i<=n; ++i) //init
        for (j=1; j<=n; ++j)
            ver[i][j]=0;
    for (i=1; i<=n; ++i) //vad ce grupe se invecineaza
        for (j=1; j<=n; ++j)
            if (drum[i][j]) ver[a[i]][a[j]]=1;

    for (i=1; i<=nr; ++i)//verific
        for (j=1; j<=nr; ++j)
            if (i!=j && !ver[i][j]) return 0;
    return 1;
}
void back (int k)
{
    int i;
    if (k==n+1)
    {
       VV+=verifica();
    }
    else
    {
        for (i=1; i<=nr; ++i)
        {
            a[k]=i;
            back(k+1);
        }

        a[k]=++nr;
        back(k+1);
        --nr;
    }
}
int main ()
{
    f>>n; f.get();
    for (i=1; i<=n; ++i)
    {
        f.getline(s+1,100);
        for (j=1; j<=n; ++j)
            if (s[j]=='1') drum[i][j]=1;
    }
    back(1);
    g<<VV-1<<"\n";
    return 0;
}
