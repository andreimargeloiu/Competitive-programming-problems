# include <fstream>
# include <cstring>
# define NMax 505
using namespace std;
ifstream f("stiva.in");
ofstream g("stiva.out");
int n,i,d,t,j,o;
char s[NMax+1];
int minn[NMax][NMax];
int main()
{
     f.getline(s+1, 1005);
     n=strlen(s+1);
     for (i=1; i<=n; ++i) minn[i][i]=1;

     for (d=2; d<=n; ++d)
         for (i=1; i+d-1<=n; ++i)
         {
             j=i+d-1;
             minn[i][j]=minn[i][j-1]+1;
             for (o=i; o<j; ++o)
                if (s[o]==s[j])
                    if (minn[i][o]+minn[o+1][j-1]<minn[i][j]) minn[i][j]=minn[i][o]+minn[o+1][j-1];
         }

     g<<2*minn[1][n]+n<<'\n';

     return 0;
}


