#include <iostream>
using namespace std;
int n;
char a, b, c;
int i;
char v[100][100];
int hanoi(int n, char A, char B, char C)
{
    if (n==1)
    {
        cout<<"mut discul "<<v[n]<<" din "<<A<<" in "<<C<<endl;
        i++;
    }
    else
    {
        hanoi(n-1, A, C, B);
        cout<<"mut discul "<<v[n]<<" din "<<A<<" pe "<<C<<endl;
        i++;
        hanoi(n-1, B, A, C);
    }
}
int main()
{
    cout<<"Numarul de discuri este: ";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"Discul "<<i<<" se numeste: ";
        cin>>v[i];
        cout<<endl;
    }
    i=0;
    a='A'; b='B'; c='C';
    hanoi(n, a, b, c);
    cout<<endl<<"Numarul de mutari este "<<i<<endl;

    return 0;
}
