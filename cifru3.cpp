#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
ofstream g("cifru3.out");
int sum, l;
long long sol;
long x[100],u[100],a[10],o[100],k,n,m;
int s[10];
int maxc;
long c[101][101];

int prime[100]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541};

long long perm(int k)
{  long long p=1;
   for (int i=1;i<=k;i++)
	   p=(p*i) % 46337;
   return p;
}

long long comb(int n,int k)
{
   int x[100];
   int m=0,j,i,d;

   if (k==0 || k==n) return 1;

   for (i=0;i<100;i++) x[i]=0;

   for (i=n-k+1;i<=n;i++)
   {
       j=i;
       d=0;
       while (j!=1)
       {
           while (j%prime[d]==0)
           {
               x[d]++;
               j=j/prime[d];
           }
           if (d>m)
             m=d;
           d++;
       }
   }
   for (i=2;i<=k;i++)
   {
       j=i;
       d=0;
       while (j!=1)
       {
           while (j%prime[d]==0)
           {
               x[d]--;
               j=j/prime[d];
           }
           d++;
       }
   }
   long long p=1;
   for (i=0;i<=m;i++)
      for (j=1;j<=x[i];j++)
         p=p*prime[i] % 46337;

   return p;
}



void calc(int l)
{  int i;

   long long v,p;
   p=1;
   for (i=1;i<=9;i++)
     p=p*comb(a[i],s[i]);

   v=p*perm(l) % 46337;
   v=v*perm(n-l-1) % 46337;

   sol=(sol+v) % 46337;
}

void back(int j,int nr)
{  int i;
   for (i=0;i<=a[j];i++)
   {  s[j]=i; sum=sum+s[j]*j;
      l=l+i;
      if (sum<=nr)
	    if (j<9 && sum<nr)
	      back(j+1,nr);
	    else
	      if (sum==nr)
	        calc(l);
      sum=sum-s[j]*j;
      l=l-i;
   }

}

int main()
{
   int v,i,t,p;

   ifstream f("cifru3.in");

   for (i=1;i<=9;i++)
     a[i]=0;

   maxc=0;

   f>>n>>p>>k;
   for (i=0;i<n;i++)
   {  f>>v; x[i]=0;
      u[i]=0; o[i]=0;
      while (v)
      {  x[i]=x[i]*10+v%10;
	     u[i]++;
	     if (v%10==k)
	       o[i]=1;
	     v=v/10;
      }
      a[u[i]]++;
      m=m+u[i];
   }

   f.close();
   sol=0;
   sum=0; l=0;
   for (i=0;i<n;i++)
     if (o[i]==1)
     {  t=0; v=x[i]; a[u[i]]--;
	    while (v>0)
	    {  t++;
	       if (v%10==k)
	         back(1,p-t);
	       v=v/10;
	    }
	    a[u[i]]++;
	    if (u[i]>maxc) maxc=u[i];
     }

   g<<sol;
   g.close();
}
