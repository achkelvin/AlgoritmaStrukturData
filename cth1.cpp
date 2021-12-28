#include<iostream>
#include<stdlib.h>
using namespace std;
int achcost[10][10],i,j,k,n,madstk[10],keltop,v,vinvisit[10],kelvinvisited[10];
int main() {
	int m;
	cout << " Masukan vertex =  "; cin >> n;
	cout << " Masukan Busur  =  "; cin >> m;
	cout << " Busur " <<endl;
	for ( k=1; k<=m; k++ )
	{
		cin >> i >> j;
		achcost[i][j] =1;
	}
	cout << " inisialisasi vertex =  "; cin>>v;
	cout << " DFS Order Vertex    =  "; cout << v << " ";
	kelvinvisited[v]=1;
	k=1;
	while (k<n){
		for (j=n; j>=1; j--)
			if ( achcost[v][j] !=0 && kelvinvisited[j] !=1 && vinvisit[j] !=1)
			{
				vinvisit[j] =1;
				madstk[keltop]=j;
				keltop++;
			}
		v= madstk[--keltop];
		cout << v << " ";
		k++;
		vinvisit[v] =0;
		kelvinvisited[v] =1; 
	}
	cin.get();
	return 0; 
}