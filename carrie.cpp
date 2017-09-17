# include <fstream>
# include <algorithm>
# include <cstring>
# define mod 30211
# define NR 100005
using namespace std;
ifstream f("carry.in");
ofstream g("carry.out");
int i,j,n,m,K;
int a[NR][102][2], adaug[50], mentin[50], nr[NR];
// a[i][j]-numarul de moduri ca sa ajungi la pozitia i, facand j carryuri la de la pozi+1 in sus

char s[NR];
void preproc ()
{
    int i,j;
    for (i=0; i<=10; ++i)
        for (j=0; j<=9; ++j)
            if (i+j>=10) ++adaug[i];
                    else ++mentin[i];
}
int main ()
{
    preproc();

    f>>n>>K; f.get();
    f.getline(s+1, NR);
    for (i=1; i<=n; ++i)
        nr[i]=s[i]-'0';

    a[n][0][0]=1;
    for (i=n-1; i>=1; --i)
    {
        for (j=0; j<=K; ++j)
        {
            // fara transport
                a[i][j][0]= a[i+1][j][0]*mentin[nr[i+1]];
                a[i][j][0]+=a[i+1][j][1]*mentin[nr[i+1]+1];
                a[i][j][0]%=mod;
            //cu transport
            if (j>0)
            {
                a[i][j][1]= a[i+1][j-1][0]*adaug[nr[i+1]];
                a[i][j][1]+=a[i+1][j-1][1]*adaug[nr[i+1]+1];
                a[i][j][1]%=mod;
            }
        }
    }
    //prima cifra e speciala
    for (i=1; i<=9; ++i)
    {
        if (nr[1]+i<=9)   a[0][K][0]+=a[1][K][0];
        if (nr[1]+1+i<=9) a[0][K][0]+=a[1][K][1];
    }
    for (i=1; i<=9; ++i)
    {
        if (nr[1]+i>=10)   a[0][K][1]+=a[1][K-1][0];
        if (nr[1]+1+i>=10) a[0][K][1]+=a[1][K-1][1];
    }

    g<<(a[0][K][0] + a[0][K][1])%mod<<"\n";

    return 0;
}
