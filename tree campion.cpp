# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define inf 999999999
# define NR 155
using namespace std;
ifstream f("tree.in");
ofstream g("tree.out");
vector <int> v[NR];
int i,j,n,m,x,y,P,minn,I;
int a[NR][NR];
// a[i][j] - numarul de moduri de a face un subarbore de lungime j
//           din subarborele lui i
void DFS (int k, int tata)
{
    if (v[k].size()==0) {a[k][1]=0; return;}// e frunza

    a[k][1]=0;
    for (int i=0; i<v[k].size(); ++i) {
        int urm=v[k][i];
        //facem dinamica
        DFS (urm, k);
        for (int j=P; j>=2; --j) {//fiecare suma de descendenti
            int MINN=a[k][j] + 1; // iau 0 descendenti din fiul actual

            for (int o=1; o<j; ++o) // fiecare suma din fiu
                MINN=min (MINN, a[urm][o] + a[k][j-o]);

            a[k][j]=MINN;
        }
        ++a[k][1];
    }

    if (a[k][P]<=minn) minn=min(minn, a[k][P]), I=k;
}
int main ()
{
    f>>n>>P;
    for (i=1; i<n; ++i) {
        f>>x>>y;
        v[x].push_back(y);
    }
    for (i=1; i<=n; ++i) {
        for (j=1; j<=P; ++j)
            a[i][j]=inf;
    }
    minn=inf;
    DFS (1, 0);
    if (I==1) g<<minn<<"\n";
    else g<<minn+1<<"\n";
    return 0;
}
