#include <iostream>
#include <string.h>
using namespace std;

// deklarasi struktur simpul
struct node
{
	int data;
	node *link;
};

class llist
{
	private:
	node *first, *last, *q;
	public:
	llist(); // fungsi yang khusus untuk diakses oleh pihak diluar kelas
	int insertkiri(int data);
	void cetak1();
	void cetak2();
};

int main()
{
	llist Xx;
	Xx. insertkiri(22);
	Xx. insertkiri(66);
	Xx. insertkiri(28);
	Xx. insertkiri(63);
	Xx. insertkiri(10);
	Xx. cetak1();
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "nilai  :  ";
	Xx.cetak2();
	cin.get();
}

//inisialisasi
llist :: llist()
{
	first = NULL;  //inisialisasi linked list
}

//menginsert simpul sebelah kiri
int llist :: insertkiri(int dt)
{
	node *p;
	p = new node;
	p -> link = first;
	p -> data = dt;
	first = p;
	return(1);
}

//menampilkan data berupa string
void llist :: cetak1()
{
	node *q;
	q = first;
	while(q != NULL)
	{
		cout << "nilai : " << q -> data << endl;
		q = q -> link;
	}
}

//menampilkan data berupa string
void llist :: cetak2 ()
{
	node *q;
	while (q != NULL)
	{
		cout << q -> data << "  " ;
		q = q -> link;
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	