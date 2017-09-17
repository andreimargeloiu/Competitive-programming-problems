# include <iostream>
using namespace std;

int main()
{
    int i,j;
    int k;
    int n;
    int v[100]; // elementele citite de la tastatura
    int l[100]; // l[i] = lungimea celui mai lung subsir crescator pana la pozitia i
    cout<<"n= "; cin>>n;

    for(int i=1; i<=n; i++)
    {
        cout<<"v["<<i<<"]="; cin>>v[i];

        l[i]=1; //initial, lungimea celui mai lung subsir este 1, adica el singur

        for (int j=i-1; j>0; --j)
            if (v[j]<=v[i] && l[j]+1>l[i]) l[i]=l[j]+1;
            // daca gasim in elementele anterioare un element mai mic sau egal cu v[i]
            // atunci elementul v[i] se poate adauga la acest subsir

        cout<<"Lungimea celui mai lung subsir crescator terminat pe pozitia "<<i<<" este: "<<l[i]<<endl;
    }

    return 0;
}
