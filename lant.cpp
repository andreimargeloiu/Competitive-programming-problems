# include <fstream>
# include <cstring>
# include <cstdlib>
# include <vector>
# define maxc 31
# define nmaxc 151
typedef char Cuvant[maxc];
using namespace std;
ifstream f("lant.in");
ofstream g("lant.out");
vector <int> v[1000];
Cuvant c[nmaxc];
int nc, k;
int a[nmaxc][nmaxc];
int d[maxc+1][maxc+1];
int nr[nmaxc];
void adauga(char*);
void graf();
void Numara(int);
int main()
{
     char s[1001], *p;
     f>>k; f.get();
     while (!f.eof())
     {
         f.getline(s,1001);
         if (f.good())
         {
             p=strtok(s," ,.:;?!-");
             while (p)
             {
                 adauga(p);
                 p=strtok(NULL," ,.:;?!-");
             }
         }
     }
     graf();
     Numara(0);
     g<<nr[0]<<"\n";
}
void adauga(char *p)
{
     int i;
     for (i=0; i<nc && strcmp(p,c[i]); ++i);
        if (i==nc) strcpy(c[nc++],p);
}
int dist (char *p, char *q)
{
    int n, m, i, j;
    n=strlen(p); m=strlen(q);
    for (i=0; i<=n; i++) d[i][m]=n-i;
    for (j=0; j<=m; j++) d[n][j]=m-j;
    for (i=n-1; i>=0; i--)
        for (j=m-1; j>=0; j--)
        {
            d[i][j]=1+d[i][j+1];
            if (d[i][j]>1+d[i+1][j]) d[i][j]=1+d[i+1][j];

            if (p[i]==q[j] && d[i][j]>d[i+1][j+1]) d[i][j]=d[i+1][j+1];
        }
    return d[0][0];
}
void graf()
{
     int i, j;
     for (i=0; i<nc; i++)
         for (j=i+1; j<nc; j++)
             if (dist(c[i],c[j])<=k)
                     v[i].push_back(j);
}
void Numara(int vf)
{
    int i;
    if (! v[vf].size()) {nr[vf]=1; return;}
    int s=0;
    for (i=0; i<v[vf].size(); i++)
    {
        if (nr[v[vf][i]]==0)
            Numara(v[vf][i]);
        s+=nr[v[vf][i]];
    }
    nr[vf]=s;
}

