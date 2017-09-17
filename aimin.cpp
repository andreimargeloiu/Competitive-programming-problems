# include<fstream>
# define NMAX 100005
using namespace std;
ifstream fin("aimin.in");
ofstream fout("aimin.out");
int n,k,L[NMAX],H[NMAX];
int main()
{
    int i;
    fin>>n;
    for (i=1;i<=n;++i)
        fin>>L[i];
    if (n==1)
    {
        fout<<L[1]<<"\n";
        return 0;
    }
    H[++k]=1+max(L[1],L[2]), H[k+1]=L[2];
    for (i=3; i<=n; ++i)
    {
        while (k>0 && H[k]<=1+max(L[i],H[k+1]))
            H[k+1]=0, --k;

        H[++k]=1+max(L[i],H[k]);
        H[k+1]=L[i];
    }
    fout<<H[1]<<"\n";
    return 0;
}
