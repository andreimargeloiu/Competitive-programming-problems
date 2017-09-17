# include <fstream>
# include <algorithm>
# include <vector>
# include <cmath>
# define NR 1005
using namespace std;
ifstream f("petsoft.in");
ofstream g("petsoft.out");
vector <int> v[NR];
int i,j,n,m,VV,ci,cs,x;
int a[NR], A[NR][3], mat[NR][NR];
int maxim (int a, int b, int c, int d)
{
    int nr1=max(a, b);
    int nr2=max(c, d);
    return max(nr1, nr2);
}
int maxx (int k, int VV)
{
    int i,j;
    for (j=1; j<=VV-1; ++j)
        for (i=1; i<=VV-j; ++i)
        {
            ci=i; cs=i+j;
            if (a[ci]==k)
            {
                mat[ci][cs]=max (mat[ci+1][cs],  mat[ci][cs-1]+max(A[cs][0], A[cs][1]));//nu le iau
                mat[ci][cs]=max (mat[ci][cs],  mat[ci+1][cs-1]+(a[cs]-a[ci])+A[cs][0]); //le iau pe ambele
                mat[ci][cs]=max (mat[ci][cs],  mat[ci+1][cs-1]+max(A[cs][0], A[cs][1]));
            }
            else if (a[cs]==k)
            {
                mat[ci][cs]=max (mat[ci][cs-1],  mat[ci+1][cs]+max(A[ci][0], A[ci][1]));//nu le iau
                mat[ci][cs]=max (mat[ci][cs],  mat[ci+1][cs-1]+(a[cs]-a[ci])+A[ci][0]); //le iau pe ambele
                mat[ci][cs]=max (mat[ci][cs],  mat[ci+1][cs-1]+max(A[ci][0], A[ci][1]));
            }
            else
            {
                mat[ci][cs]=max (mat[ci+1][cs]+max(A[ci][0], A[ci][1]),  mat[ci][cs-1]+max(A[cs][0], A[cs][1]));//nu le iau
                mat[ci][cs]=max (mat[ci][cs],  mat[ci+1][cs-1]+(a[cs]-a[ci])+A[ci][0]+A[cs][0]); //le iau pe ambele
                mat[ci][cs]=max (mat[ci][cs],  mat[ci+1][cs-1]+max(A[ci][0],  A[ci][1])+max(A[cs][0], A[cs][1]));
            }
        }

    return mat[1][VV];
}
void DFS (int k)
{
    int i;
    for (i=0; i<v[k].size(); ++i)
        DFS (v[k][i]);
    if (v[k].size()==1)
    {
        A[k][0]=max(A[v[k][0]][0], A[v[k][0]][1]);
        A[k][1]=abs(k-v[k][0]) + A[v[k][0]][0];
    }
    else
    {
        //fara el
        VV=0;
        for (i=0; i<v[k].size(); ++i)
            a[++VV]=v[k][i];

        sort (a+1, a+VV+1);
        A[k][0]=maxx (k, VV);

        //cu el
        a[++VV]=k;
        sort (a+1, a+VV+1);
        A[k][1]=maxx (k, VV);
    }
}
int main ()
{
    f>>n;
    for (i=2; i<=n; ++i)
    {
        f>>x;
        v[x].push_back(i);
    }
    DFS (1);

    g<<A[1][0];
    return 0;
}
