#include<cstdio>
using namespace std;
int a[1002][1002],b[1002][1002],n,m;
void citire()
{
	int i,j;

	scanf ("%d%d", &n, &m);
	for(i=1;i<=n;i++)
	  for(j=1;j<=m;j++)
	    scanf ("%d", &a[i][j]);
}
int stare(int i,int j)
{
	int c=0;

	if(b[i-1][j]+b[i-1][j-1]==1) c++;
	if(b[i-1][j]+b[i-2][j]==1) c++;
	if(b[i-1][j]+b[i-1][j+1]==1) c++;
	return c;
}
void construieste()
{
	int i,j;

	for(i=2;i<n;i++)
	  for(j=2;j<m;j++)
	    if(stare(i,j)!=a[i-1][j])
	      b[i][j]=1-b[i-1][j];
	    else
	      b[i][j]=b[i-1][j];
}
void afisare()
{
	int i,j;

	for(i=1;i<=n;i++)
	  {
	    printf (".");
	    for(j=2;j<=m;j++)
	      {
            if(b[i][j-1]!=b[i][j]) printf ("|");
            else printf (".");
            if(b[i+1][j]!=b[i][j]) printf ("_");
            else printf (".");
	      }
	    printf ("\n");
	  }
}
int main()
{
    freopen ("desen1.in", "r", stdin);
    freopen ("desen1.out", "w", stdout);
	citire();
	construieste();
	afisare();
	return 0;
}
