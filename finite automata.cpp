#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
ifstream in("date.in");

char a[100][100][100];
int v[100],n,r[100][100],ok;


void AFN(int stare,char cuv[])
{

    if(cuv[0]=='1'&&v[stare]==1)
    {
        cout<<"DA";
        ok=1;
    }

    char c=cuv[0];
    int i,j;
    for(j=1; j<=n; j++)
        for(i=1; i<=r[stare][j]; i++)
            if(a[stare][j][i]==c)
            {
                char cuv2[23];
                strcpy(cuv2,cuv+1);
                AFN(j,cuv2);
            }

}

int main()
{

    int i,k,x,y,k2;
    char c;
    in>>n>>k;
    for(i=1; i<=k; i++)
    {
        in>>x>>y>>c;
        r[x][y]++;
        a[x][y][r[x][y]]=c;

    }
    in>>k2;
    for(i=1; i<=k2; i++)
    {
        in>>x;
        v[x]=1;
    }

    in.get();
    char cuv[23];
    in.get(cuv,23);


    if(strcmp(cuv,"lambda")==NULL)
    {
        if(v[1]==1)
            cout<<"DA";
        else
            cout<<"NU";
    }
    else
    {
        strcat(cuv,"1");
        AFN(1,cuv);

        if(ok!=1)
            cout<<"NU";
    }
}

/*
datele din fisier

nr de stari
nr de muchii
npdul de pornire, de final si litera
nr de stari finale
v[]-marchez cu 1 ndurile finale
cuvantul verificat

3
6
1 1 b
1 2 a
2 1 b
2 3 a
3 3 a
3 3 b
2
1 2
bbababbba


*/
