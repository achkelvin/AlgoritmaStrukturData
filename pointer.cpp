#include <iostream>
#include <string>
using namespace std;

struct ktp {
		int noktp;
		char nama[25];
};
		struct alamat {
				char jalan[20];
				char kota[15];
				int kodepos; 	
};
		struct lahir	{
				int tanggal;
				int bulan;
				int tahun;	
};
int main () {
	struct ktp*jatidiri;
	struct alamat*tmpt;
	struct lahir*ttl;
	
	// input data 
	jatidiri = new ktp;
	cout <<" Masukan No KTP = ";cin >> jatidiri -> noktp;
	cout <<" Masukan nama 	= ";cin >> jatidiri -> nama;
	cout <<" Alamat 		"<<endl;
	tmpt = new alamat;
	cout <<" - Jalan 		= ";cin >> tmpt -> jalan;
	cout <<" - Kota 		= ";cin >> tmpt -> kota;
	cout <<" - Kode Pos 	= ";cin >> tmpt -> kodepos;
	cout <<" Tanggal Lahir 	"<<endl;
	ttl = new lahir;
	cout <<" - Tanggal 		= ";cin >> ttl-> tanggal;
	cout <<" - Bulan 		= ";cin >> ttl-> bulan;
	cout <<" - Tahun 		= ";cin >> ttl-> tahun;
	cout << endl;
	cout << endl;
	// Output data 
	cout <<" No KTP			= "<< jatidiri -> noktp <<endl;
	cout <<" Nama 			= "<< jatidiri -> nama <<endl;
	cout <<" Alamat			  "<< endl;
	cout <<" jalan			= "<< tmpt -> jalan <<endl;
	cout <<" Kota			= "<< tmpt -> kota <<endl;
	cout <<" Kode Pos		= "<< tmpt -> kodepos <<endl;
	cout <<" Tanggal Lahir	  "<<endl;
	cout <<" Tanggal		= "<< ttl -> tanggal <<endl;
	cout <<" Bulan			= "<< ttl -> bulan <<endl;
	cout <<" Tahun			= "<< ttl -> tahun <<endl;
	cout << endl;
cin.get();
}
