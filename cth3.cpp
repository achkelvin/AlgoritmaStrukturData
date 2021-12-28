#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];
int jodel();
void joadd(int item);
void jobfs(int s, int n);
void jodfs(int s, int n);
void jopush(int item);
int jopop();
int main()
{
	int n,i,s,ch,j;
	cout << "Masukkan Data "; cin >> n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout << " Masukkan " << i << " Data Jika Mempunyai Simpul " << j << " selain itu ";
			cin >> a[i][j];
		}
	}
	cout << "Matrik Adjacency" << endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout << a[i][j] << " ";
		}
		cout <<  endl;
	}
	for(i=1;i<=n;i++)
	{
		vis[i]=0;
		cout << " MENU " << endl;
		cout << "~~~~~~~~" << endl;
		cout << "1. BFS - Breadth First Search " << endl;
		cout << "2. DFS - Depth First Search " <<  endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << " Pilihan " << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << " Pilih : " ; cin >> ch;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << " Masukkan Simpul Sumber: "; cin >> s;
		switch (ch)
		{
		case 1 : jobfs(s,n);
		case 2 : jodfs(s,n);
		case 3 :
		break;
		}
	}
	return(0);
}
void jobfs(int s,int n)
{
	int p,i;
	joadd(s);
	vis[s]=1;
	p=jodel();
	if(p!=0)
		cout << p << " ";
	while(p!=0)
	{
		for(i=1;i<=n;i++)
			if ((a[p][i]!=0)&&(vis[i]==0))
			{
				joadd(i);
				vis[i]=1;
			}
			p=jodel();
			if(p!=0)
				cout << p << " ";
	}
	for(i=1;i<=n;i++)
		if(vis[i]==0)
			jobfs(i,n);

}

void joadd(int item)
{
		if(rear==19)
		{
			cout << "Antrian Penuh" << endl;
			cout << "~~~~~~~~~~~~~" << endl;
		}
		else
			if(rear==-1)
			{
				q[++rear]=item;
				front++;
			}
			else
				q[++rear]=item;
}

int jodel()
{
	int k;
	if((front>rear)||(front==-1))
		return(0);
	else{
		k=q[front++];
		return(k);
	}
}
void jodfs(int s,int n)
{
	int i,k;
	jopush(s);
	vis[s]=1;
	k=jopop();
	if(k!=0)
		cout << k << " ";
while(k!=0)
{
	for(i=1;i<=n;i++)
		if((a[k][i]!=0)&&(vis[i]==0))
		{
			jopush(i);
			vis[i]=1;
		}
		k=jopop();
		if(k!=0)
			cout << k << " ";
}
for(i=1;i<=n;i++)
	if(vis[i]==0)
		jodfs(i,n);
}
void push(int item)
{
	if(top==19)
		cout << "stack overflow" << endl;
	else
		stack[++top]=item;
}
int jopop()
{
	int k;
	if(top==-1)
		return (0);
	else
	{
		k=stack[top--];
		return(k);
	}
}
