# include <fstream>
# include <algorithm>
# include <deque>
# define NR 1050
# define inf 999999999
using namespace std;
ifstream f("mall.in");
ofstream g("mall.out");
deque <int> dh, dl;
int i,j,n,m,x,y;
int a[NR][NR], L[NR], E[NR], H[NR], C[NR];
int main ()
{
    f>>n>>m;

    for (i=1; i<=n; ++i)
    {
        f>>L[i]>>E[i]>>H[i]>>C[i];
        if (i==1)
        for (j=0; j<=m; ++j)
        {
            if (j<C[i])       a[i][j]=L[i];
            else if (j==C[i]) a[i][j]=E[i];
            else if (j>C[i])  a[i][j]=H[i];
        }
    }

    for (i=2; i<=n; ++i) //fiecare firma
    {
        dl.clear(); dh.clear();
        for (j=0; j<=m; ++j) // fiecare suma totala de muncitori
        {
            //nu trimit niciun muncitor
            if (C[i]==0) a[i][j]=a[i-1][j] + E[i];
                    else a[i][j]=a[i-1][j] + L[i];

            //trimit exact C[i]
            if (j>=C[i]) a[i][j]=max(a[i][j], a[i-1][j-C[i]] + E[i]); //adaug C[i]

            // adaug mai putin
            if (C[i]>0 && j>0)
            {
                while (! dl.empty() && a[i-1][j-1]>=a[i-1][dl.back()])
                    dl.pop_back();

                dl.push_back(j-1);

                if (j>=C[i] && j-dl.front()==C[i]) dl.pop_front();

                a[i][j]=max(a[i][j], a[i-1][dl.front()] + L[i]);
            }
            //adaug mai mult
            if (j>C[i])
            {
                while (! dh.empty() && a[i-1][j-C[i]]>=a[i-1][dh.back()])
                    dh.pop_back();

                dh.push_back(j-C[i]);

                a[i][j]=max(a[i][j], a[i-1][dh.front()] + H[i]);
            }
        }
    }

    g<<a[n][m]<<"\n";

    return 0;
}
