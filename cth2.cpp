#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int a[20][20], q[20],jovisited[20],n,i,j,f=0,r=-1;
void jobfs(int v)
{
	for (i=1; i<=n; i++)
		if(a[v][i] && ! jovisited[i])
			q[++r] =i;
		if(f<=r)
		{
			jovisited[q[f]]=1;
			jobfs(q[f++]);
		}
}
int main()
{
	int v;
	cout << " masukan matriks atau vertex :  "; cin >> n;
	for (i=1; i<=n; i++)
	{
		q[i] =0;
		jovisited[i] =0;
	}
	cout << " masukan data graph dalam bentuk matriks [nxn] :  " << endl;
for(i=1; i<=n; i++)
{
		for(j=1; j<=n; j++)
		{
			cin >> a[i][j];
		}
}
cout <<" masukan vertex awal :  "; cin>>v;
jobfs(v);
cout << " Node yang dpt di capai :  ";
for(i=1; i<=n; i++ )
{
	if ( jovisited[i])
		cout << i << " ";
	else
	{
		cout << " bfs - tidak semua node dapat dijangkau ";
		break;
	}
}
cout << endl;
cin.get();
}