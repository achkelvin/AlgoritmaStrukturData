// Program C ++ untuk algoritma Kruskal untuk mencari Minimum 
// Spanning Tree dari suatu terhubung, tidak terarah dan
// grafik berbobot
#include<bits/stdc++.h> 
using namespace std; 

// Membuat pintasan untuk pasangan integer pasangan
typedef pair<int, int> iPair; 

// Struktur untuk merepresentasikan grafik
struct Graph 
{ 
	int V, E; 
	vector< pair<int, iPair> > edges; 

	// Pembuat 
	Graph(int V, int E) 
	{ 
		this->V = V; 
		this->E = E; 
	} 

// Fungsi utilitas untuk menambahkan tepi
	void addEdge(int u, int v, int w) 
	{ 
		edges.push_back({w, {u, v}}); 
	} 

// Berfungsi untuk mencari MST menggunakan Kruskal
// Algoritma MST
	int kruskalMST(); 
}; 

// Untuk merepresentasikan Disjoint Sets
struct DisjointSets 
{ 
	int *parent, *rnk; 
	int n; 

	// Pembuat. 
	DisjointSets(int n) 
	{ 
		// Alokasikan memori
		this->n = n; 
		parent = new int[n+1]; 
		rnk = new int[n+1]; 

		// Awalnya, semua simpul berada dalam
// set berbeda dan memiliki peringkat 0.
		for (int i = 0; i <= n; i++) 
		{ 
			rnk[i] = 0; 

// setiap elemen adalah induknya sendiri
			parent[i] = i; 
		} 
	} 

	// Temukan induk dari simpul 'u'
// Kompresi Jalur
	int find(int u) 
	{ 
		/* Jadikan induk dari node di jalan
dari u -> induk [u] menunjuk ke induk [u] */
		if (u != parent[u]) 
			parent[u] = find(parent[u]); 
		return parent[u]; 
	} 

// Persatuan berdasarkan peringkat
	void merge(int x, int y) 
	{ 
		x = find(x), y = find(y); 

/* Buat pohon dengan tinggi lebih kecil
subpohon dari pohon lain */
		if (rnk[x] > rnk[y]) 
			parent[y] = x; 
		else // If rnk[x] <= rnk[y] 
			parent[x] = y; 

		if (rnk[x] == rnk[y]) 
			rnk[y]++; 
	} 
}; 

/* Fungsi mengembalikan bobot MST */

int Graph::kruskalMST() 
{ 
	int mst_wt = 0; // Initialize result 

// Urutkan tepi dalam urutan meningkat berdasarkan biaya
	sort(edges.begin(), edges.end()); 

// Buat set terputus-putus

	DisjointSets ds(V); 

// Iterasi melalui semua sisi yang diurutkan
	vector< pair<int, iPair> >::iterator it; 
	for (it=edges.begin(); it!=edges.end(); it++) 
	{ 
		int u = it->second.first; 
		int v = it->second.second; 

		int set_u = ds.find(u); 
		int set_v = ds.find(v); 

		// Periksa apakah tepi yang dipilih sedang dibuat
// a cycle or not (Siklus dibuat jika u
// dan v milik set yang sama) 
		if (set_u != set_v) 
		{ 
			// Tepi saat ini akan berada di MST
// jadi cetaklah 
			cout << u << " - " << v << endl; 

// Perbarui berat MST
			mst_wt += it->first; 

// Gabungkan dua set
			ds.merge(set_u, set_v); 
		} 
	} 

	return mst_wt; 
} 

// Program driver untuk menguji fungsi di atas
int main() 
{ 
	/* Mari kita buat di atas tertimbang
dan grafik tidak terputus */
	int V = 9, E = 14; 
	Graph g(V, E); 

// membuat grafik yang ditunjukkan di atas
	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 

	cout << "Edges of MST are \n"; 
	int mst_wt = g.kruskalMST(); 

	cout << "\nWeight of MST is " << mst_wt; 

	return 0; 
} 
