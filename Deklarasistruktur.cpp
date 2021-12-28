#include<iostream>
#include<string.h>
using namespace std;

struct Node			//Deklarasi struktur simpul
{
int data;
Node *LINK;
};
class Llist
{
	private:
	Node *FIRST, *LAST, *O;
	public:
	Llist();	//fungsi yang khusus untuk diakses oleh pihak diluar kelas
	int INSERTKIRI (int data);
	void CETAK1();
	void CETAK290;
	
};