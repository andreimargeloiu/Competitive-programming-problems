#include <stdlib.h>
#include <stdio.h>

#define DIM      5000
using namespace std;
typedef int Huge[DIM+1];

Huge A, B, C;
int n;
char c;

FILE *Fin, *Fout;

void Citire(void)
{
  Fin = fopen("perfect.in", "r");
  Fout = fopen("perfect.out", "w");
  fscanf(Fin, "%c %d", &c, &n);
  fclose(Fin);
}

void WriteHuge(Huge X)
{
  int i;
  for (i=X[0]; i; i--)
	 fprintf(Fout, "%d", X[i]);
  fprintf(Fout, "\n");
}

void Atrib0(Huge H)
{
  H[0]=0;
}

void AtribValue(Huge H, unsigned long X)
{
  H[0]=0;
  while (X)
	{
	  H[++H[0]]=X%10;
	  X/=10;
	}
}

void AtribHuge(Huge H, Huge X)
{
  int i;
  for (i=0; i<=X[0]; i++) H[i]=X[i];
}







void AddHuge(Huge A, Huge B, Huge C)
{
  int i, T=0;   //A+B-->C
  if (B[0]>A[0])
	{
	  for (i=A[0]+1; i<=B[0]; ) A[i++]=0;
	  A[0]=B[0];
	}
  else
	for (i=B[0]+1; i<=A[0]; ) B[i++]=0;
  C[0]=A[0];
  for (i=1; i<=A[0]; i++)
	{
	  C[i]=A[i]+B[i]+T;
	  T=C[i]/10;
	  C[i]%=10;
	}
  if (T) C[++C[0]]=T;
}

void MultHuge(Huge A, Huge B, Huge C)
{
  int i, j, T=0;         //A*B-->C
  Huge CC;
  CC[0]=A[0]+B[0]-1;
  for (i=1; i<=A[0]+B[0]; ) CC[i++]=0;
  for (i=1; i<=A[0]; i++)
	for (j=1; j<=B[0]; j++)
	  CC[i+j-1]+=A[i]*B[j];
  for (i=1; i<=CC[0]; i++)
	{
	  T=(CC[i]+=T)/10;
	  CC[i]%=10;
	}
  if (T) CC[++CC[0]]=T;

  for (i=0; i<=CC[0]; i++)
	C[i]=CC[i];
}











void CalculA(void)
{
  int i;

  AtribValue(A, 1);
  AtribValue(B, 1);

  for (i=2; i<=n; i++)
	{
	  AddHuge(A, B, C);
	  AtribHuge(A, B);
	  AtribHuge(B, C);
	}
}

void CalculB(void)
{
  int i;
  Huge Doi;

  AtribValue(Doi, 2);

  CalculA();

  MultHuge(A, B, C);
  MultHuge(C, Doi, C);
}








void CalculC(void)
{
  int p=n*(n+1)/2;
  Huge Doi;
  int i;

  AtribValue(Doi, 2);
  AtribValue(C, 1);
  for (i=1; i<=p; i++)
	MultHuge(C, Doi, C);
}






int main(void)
{
  Citire();
  switch (c)
	{
	  case 'A': CalculA(); WriteHuge(C); break;
	  case 'B': CalculB(); WriteHuge(C); break;
	  case 'C': CalculC(); WriteHuge(C); break;
	}
  fclose(Fout);
  return(0);
}
