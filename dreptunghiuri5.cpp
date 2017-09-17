# include <fstream>
# include <algorithm>
# include <cstring>
# define NR 1005
using namespace std;
ifstream f("dreptunghiuri5.in");
ofstream g("dreptunghiuri5.out");
int i,j,n,m,lastok,VV,VVnou,k,ok;
int a[NR][NR], sus[NR][NR], st[NR];
long long sol;
int main ()
{
    f>>n>>m;
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j) {
            f>>a[i][j]; a[i][j]=1-a[i][j];

            if (a[i][j]) sus[i][j]=1 + sus[i-1][j];
        }
    //in stiva mentin mereu numere strict cescatoare !!!!

    for (i=n; i>=1; --i) {
        for (j=1; j<=m+1; ++j) {
            if (a[i][j]==0) { //trebuie sa eliberez stiva
                for (k=VV; k>=1; --k) {
                    if (lastok >= st[k]) ++sol;
                    st[k]=0;
                }
                VV=0; lastok=0;
            }
            else {
                if (sus[i][j] > sus[i][st[VV]]) st[++VV]=j;
                else if (sus[i][j] == sus[i][st[VV]]) i+=0;
                else { //trebuei sa scot
                    VVnou=VV;
                    for (k=VV; k>=1; --k) {
                        if (sus[i][st[k]] > sus[i][j]) { // il scot
                            if (lastok >= st[k]) ++sol;
                            sus[i][st[k]]=sus[i][j];
                            VVnou=k;
                        }
                        else if (sus[i][st[k]] == sus[i][j]) {
                            VVnou=k; break;}
                        else { // il pun
                            break;
                        }
                    }
                    VV=VVnou;
                }
                if (a[i+1][j]==0) lastok=j;
            }
        }
    }
    g<<sol<<"\n";

    return 0;
}
