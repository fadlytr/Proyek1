/* ===========================================================
Program			: Aji_002_Cahya_007.c
Deskripsi		: Latihan membuat modul 2
Author			: Ahmad Aji Naufal ALi	(171524002)
				  Cahya Ramadhan		(171524007)
Versi / tanggal : 0.2 / 5 Nov 2017
Compiler		: Code::Blocks 16.01 / Dev C++ 5.11
=============================================================*/
#include <stdio.h>
#include <stdbool.h>

/* Prototipe */
bool isMatriksNol(int n, int m, int M[n][n]);
bool isMatriksDiagonal(int n, int m, int M[n][m]);
bool isMatriksIdentitas(int n, int m, int M[n][n]);
bool isMatriksSimetris(int n, int m, int M[n][m]);
bool TampilkanMenu(int n, int m, int M[n][m]);
bool isSegitigaAtas(int n, int m, int M[n][m]);
bool isSegitigaBawah(int n, int m, int M[n][m]);
bool isSepuluhAda(int n, int m, int M[n][m]);
bool isMatriksSkalar(int n, int m, int M[n][m]);
bool isAdaPrima(int n, int m, int M[n][m]);

void transposeMatriks(int n, int m, int M[n][m], int Mt[n][m]);
void tampilMatriks(int n, int m, int M[n][m]);
void sortAscending(int n, int m, int M[n][m]);

int selisihMaxMin(int n, int m, int M[n][m]);
int lokasiSepuluh(int n, int m, int M[n][m]);
int maxPrima(int n, int m, int M[n][m]);
int maxInArray(int l, int P[l]);

int main(){
	
	/* Deklarasi */
	int baris, kolom;
	bool diagonal = false;
	char ch;
	bool ulang = true, done = false;
	
	/* Algoritma */
	while (ulang == true)
	{
		int	Matriks[5][5] =
		{
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0},
		};
	
//		int	Matriks[5][5] =
//		{
//			{10, 10, 10, 6, 10},
//			{10, 10, 9, 9, 8},
//			{0, 0, 5, 2, 7},
//			{0, 0, 0, 3, 8},
//			{0, 0, 0, 0, 4},
//		};

//		int	Matriks[5][5] =
//		{
//			{3, 2, 5, 7, 11},
//			{3, 2, 5, 7, 11},
//			{3, 2, 5, 7, 11},
//			{3, 2, 5, 7, 11},
//			{3, 2, 5, 7, 11},
//		};
		
//		int	Matriks[5][5] =
//		{
//			{1, 0, 0, 0, 0},
//			{0, 1, 0, 0, 0},
//			{0, 0, 1, 0, 0},
//			{0, 0, 0, 1, 0},
//			{0, 0, 0, 0, 1},
//		};
	
//		int	Matriks[5][5] =
//		{
//			{0, 0, 0, 0, 5},
//			{0, 0, 0, 5, 0},
//			{0, 0, 5, 0, 0},
//			{0, 5, 0, 0, 0},
//			{5, 0, 0, 0, 0},
//		};
//	
//		int	Matriks[5][5] =
//		{
//			{1, 2, 3, 4, 5},
//			{6, 7, 8, 9, 10},
//			{11, 12, 13, 14, 15},
//			{16, 17, 18, 19, 20},
//			{21, 22, 23, 24, 25},
//		};
	
//		int	Matriks[5][5] =
//		{
//			{2, 3, 5, 1, 4},
//			{3, 7, 8, 9, 10},
//			{5, 8, 13, 14, 15},
//			{1, 9, 14, 19, 20},
//			{4, 10, 15, 20, 25},
//		};

		done = TampilkanMenu(5, 5, Matriks);
		
		if(done == true){
			printf("\n\n\t\t\t\t\t(Tekan enter untuk ulangi program)\n");
			printf("\n\t\t\t\t  (Tekan spasi untuk ulangi keluar dari program)\n\n");
			ch = getch();
			if(ch == 13) // 13 merupakan kode ASCII dari enter
				ulang = true;
				else if(ch == 32){ // 32 merupakan kode ASCII dari spasi
					printf("\n\t=================================================================================================="); 
					printf("\n\t==========================  Terima kasih telah menggunakan program ini  ==========================");
					printf("\n\t=                           \t\t                     \t\t                         ="); 
					printf("\n\t=                           \t\t   Created by :     \t\t                         ="); 
					printf("\n\t=                           \t\t                     \t\t                         ="); 
					printf("\n\t=                           - Ahmad Aji Naufal Ali \t(171524002)\t                         ="); 
					printf("\n\t=                           - Cahya Ramadhan \t\t(171524007)  \t                         =");
					printf("\n\t=================================================================================================="); 
					return 0;
				}
					else ulang = false;
		}
		else{
			printf("\n\n\t=================================================================================================="); 
			printf("\n\t==========================  Terima kasih telah menggunakan program ini  ==========================");
			printf("\n\t=                           \t\t                     \t\t                         ="); 
			printf("\n\t=                           \t\t   Created by :     \t\t                         ="); 
			printf("\n\t=                           \t\t                     \t\t                         ="); 
			printf("\n\t=                           - Ahmad Aji Naufal Ali \t(171524002)\t                         ="); 
			printf("\n\t=                           - Cahya Ramadhan \t\t(171524007)  \t                         =");
			printf("\n\t=================================================================================================="); 
			return 0;	
		}
	}
	return 0;
}

/* Function */
bool TampilkanMenu(int n, int m, int M[n][m]){
	//  Deksripsi	: Menampilkan Menu
	
	bool done = false, Ada = false, yes = false;
	int pilihMenu, Mt[5][5], selisih, maxp;
	while(done == false)
	{
		system("cls");
	    printf("===============================================================================================================\n");
	    printf("=                                                 Menu                                                        =\n");
	    printf("===============================================================================================================\n");
		printf("\nPilih Menu : \n");
		printf("1.  Matriks 0 ?\n2.  Matriks Diagonal ?\n3.  Matriks Identitas ?\n");
		printf("4.  Segitiga Atas\n5.  Segitiga Bawah\n6.  Matriks Simetris\n");
		printf("7.  Matriks Skalar\n8.  Transpose Matriks\n");
		printf("9.  Sort Matriks\n10. Adakah nilai 10 di Matriks ?\n11. Menampilkan jumlah kemunculan angka 10 dan posisinya pada Matriks\n");
		printf("12. Selisih nilai terbesar dan nilai terkecil pada Matriks\n13. Adakah bilangan prima pada Matriks ?\n");
		printf("14. Mengirimkan nilai prima terbesar pada Matriks\n15. Tampilkan Matriks\n16. Keluar Program");

		printf("\n\nMasukkan nomor pilihan : ");
		
		scanf("%d", &pilihMenu);
		switch(pilihMenu){
			case 1 : 	
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						yes = isMatriksNol(n, m, M);
						if (yes)
						{
							printf("\n\nMatriks ini ADALAH MATRIKS NOL");
						} else 
							{
								printf("\n\nMatriks ini BUKAN MATRIKS NOL");
							}
					    done = true; break;
			case 2 :	
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						yes = isMatriksDiagonal(n, m, M);
						if(yes == true)
							printf("\n\nMatriks ini merupakan Matriks Diagonal");
							else printf("\n\nMatriks ini bukan Matriks Diagonal");
					    done = true; break;
			case 3 : 	
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						yes = isMatriksIdentitas(n, m, M);
						if(yes)
						{
							printf("\n\nMatriks ini ADALAH MATRIKS IDENTITAS");
						} else
							{
							  printf("\n\nMatriks ini BUKAN MATRIKS IDENTITAS");
							}
					    done = true; break;
			case 4 : 			
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						yes = isSegitigaAtas(n, m, M);
						if(yes == true)
							printf("\n\nMatriks ini merupakan Matriks Segitiga Atas");
							else printf("\n\nMatriks ini bukan Matriks Segitiga Atas");
					    done = true; break;
			case 5 :	
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						yes = isSegitigaBawah(n, m, M);
						if(yes)
						{
							printf("\n\nMatriks ini ADALAH MATRIKS SEGITIIGA BAWAH");
						} else
							{
							  printf("\n\nMatriks ini BUKAN MATRIKS SEGITIGA BAWAH");
							}
					    done = true; break;
			case 6 :
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						yes = isMatriksSimetris(n, m, M);
						if(yes == true)
							printf("\nMatriks ini merupakan Matriks Simetris");
							else printf("\nMatriks ini bukan Matriks Simetris");
					    done = true; break;
			case 7 :
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						yes = isMatriksSkalar(n, m, M);
						if(yes)
						{
							printf("\nMatriks ini ADALAH MATRIKS SKALAR");
						} else
							{
							  printf("\nMatriks ini BUKAN MATRIKS SKALAR");
							}
					    done = true; break;
			case 8 :
						printf("\nMatriks SEBELUM di TRANSPOSE : \n");
						tampilMatriks(n, m, M);
						transposeMatriks(n, m, M, Mt);
						printf("\n\nMatriks yang sudah di transpose : \n");
						tampilMatriks(n, m, Mt);
					    done = true; break;
			case 9 :	
						printf("\nMatriks SEBELUM di SORT\n");
						tampilMatriks(n, m, M);
						sortAscending(n, m, M);
						printf("\n\nMatriks SETELAH di SORT ASCENDING PER BARIS : \n");
						tampilMatriks(n, m, M);
					    done = true; break;
			case 10 :
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						yes = isSepuluhAda(n, m, M);
						if(yes == true)
							printf("\n\nAngka 10 ada di Matriks");
							else printf("\n\nAngka 10 tidak ada di Matriks");
					    done = true; break;
			case 11 :
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						lokasiSepuluh(n, m, M);
					    done = true; break;
			case 12 :
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						selisih = selisihMaxMin(n, m, M);
						printf("\n\nSelisih nilai terbesar dan terkecil adalah %d", selisih);
					    done = true; break;
			case 13 : 	
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						yes = isAdaPrima(n, m, M);
						if (yes) //jika true artinya tidak ada
						{
							printf("\nTIDAK ADA BILANGAN PRIMA\n");
						} else
							{
								printf("\nADA BILANGAN PRIMA !\n");
							}
						done = true; break;
			case 14 : 
						printf("\nMatriks yang dipakai : \n");
						tampilMatriks(n, m, M);
						maxp = maxPrima(n, m, M);
						printf("\n\nNilai Bilangan Prima terbesasr adalah %d", maxp);
						done = true; break;
			case 15 : 
						printf("\nTampilan Matriks : \n");
						tampilMatriks(n, m, M);
						done = true; break;

			case 16 : //Keluar Program
						done = false; return done; break;

			default  : 
	            		printf("\n\nMaaf, pilihan yang anda masukkan tidak valid\nSilahkan masukkan lagi...");
						getch(); done = false; break;
		}
	}
	if(done == true)
		return true;
}

/* Function */
bool isMatriksNol(int n, int m, int M[n][m])
{
	//  Deksripsi	: Mengetahui matriks nol
	//  Input		: M merupakan parameter input array dua dimensi bertipe integer
	//				  n, m merupakan parameter input bertipe integer (elemen dari array M)
	//  Output		: True / False (Boolean)
	//  Author		: Ahmad Aji Naufal Ali
	bool cek = true;
	int i, j;
	
	i = 0;
	while ((i < n) && (cek))
	{
		j = 0;
		while ((j < m) && (cek))
		{
			if (M[i][j] != 0)
			{
				cek = false;
			}
		j++;
		}
	i++;		
	}	
	
	return cek;
}

/* Function */
bool isMatriksDiagonal(int n, int m, int M[n][m]){

	//  Deksripsi	: Membuktikan apakah suatu matriks merupakan matriks diagonal
	//  Input		: M merupakan parameter input array dua dimensi bertipe integer
	//				  n, m merupakan parameter input bertipe integer (elemen dari array M)
	//  Output		: True / False (Boolean)
	//  Author		: Cahya Ramadhan
	
	int benar = 0, baris, kolom;
	
	for(baris = 0; baris < n; baris++){
		for(kolom = 0; kolom < m; kolom++){
			if(baris == kolom){
				if(M[baris][kolom] != 0)
					benar++;
			}
				else if(M[baris][kolom] == 0)
					benar++;
		}
	}
	if(benar == n*m)
		return true;
		else return false;
}

/* Function */
bool isMatriksIdentitas(int n, int m, int M[n][n])
{
	//  Deksripsi	: Mengetahui matriks identitas
	//  Input		: M merupakan parameter input array dua dimensi bertipe integer
	//				  n, m merupakan parameter input bertipe integer (elemen dari array M)
	//  Output		: True / False (Boolean)
	//  Author		: Ahmad Aji Naufal Ali
	
	bool cek = true;
	int i, j;
	
	i = 0;
	while ((i < n) && (cek))
	{
		j = 0;
		while ((j < m) && (cek))
		{
			if ((i == j) && (M[i][j] != 1))
			{
				cek = false;
			} else if ((i != j) && (M[i][j] != 0))
				{
					cek = false;
				}
		j++;
		}
	i++;		
	}	
	
	return cek;
}

/* Function */
bool isMatriksSimetris(int n, int m, int M[n][m]){
	
	//  Deksripsi	: Membuktikan apakah suatu matriks merupakan matriks simetris
	//  Input		: M merupakan parameter input array dua dimensi bertipe integer
	//				  n, m merupakan parameter input bertipe integer (elemen dari array M)
	//  Output		: True / False (Boolean)
	//  Author		: Cahya Ramadhan

	int benar = 0, baris, kolom, Mt[n][m];
	
	transposeMatriks(n, m, M, Mt);
	for(baris = 0; baris < 5; baris++){
		for(kolom = 0; kolom < 5; kolom++){
			if(M[baris][kolom] == Mt[baris][kolom])
				benar++;
		}
	}
	if(benar == 25)
		return true;
		else return false;
}

/* Function */
bool isMatriksSkalar(int n, int m, int M[n][m])
{
	//  Deksripsi	: Mengetahui matriks skalar
	//  Input		: M merupakan parameter input array dua dimensi bertipe integer
	//				  n, m merupakan parameter input bertipe integer (elemen dari array M)
	//  Output		: True / False (Boolean)
	//  Author		: Ahmad Aji Naufal Ali
	
	bool cek = true;
	int i, j, temp;
	
	i = 0;
	temp = M[i][j]; //pojok kiri atas
	if ((temp == 1) || (temp == 0))
	{
		cek = false; //matriks skalar mirip identitas, tapi nilai yg mengisi diagonal utamanya tidak boleh 1
	}
	while ((i < n) && (cek))
	{
		j = 0;
		while ((j < m) && (cek))
		{
			if ((i == j) && (M[i][j] != temp))
			{
				cek = false;
			} else if ((i != j) && (M[i][j] != 0))
				{
					cek = false;
				}
		j++;
		}
	i++;		
	}	
	
	return cek;
}

/* Function */
bool isSegitigaAtas(int n, int m, int M[n][m]){

	//  Deksripsi	: Membuktikan apakah suatu matriks merupakan matriks segitiga atas
	//  Input		: M merupakan parameter input array dua dimensi bertipe integer
	//				  n, m merupakan parameter input bertipe integer (elemen dari array M)
	//  Output		: True / False (Boolean)
	//  Author		: Cahya Ramadhan

	int baris, kolom, benar = 0;
	for(baris = 0; baris < n; baris++){
		for(kolom = 0; kolom < baris; kolom++){
			if(M[baris][kolom] == 0)
				benar++;
		}
	}
	for(baris = 0; baris < n; baris++){
		for(kolom = 0; kolom <= baris; kolom++){
			if(M[kolom][baris] != 0)
				benar++;
		}
	}
	if(benar == n*m)
		return true;
		else return false;
}

/* Function */
bool isSegitigaBawah(int n, int m, int M[n][m])
{

	//  Deksripsi	: Mengetahui matriks segitiga bawah
	//  Input		: M merupakan parameter input array dua dimensi bertipe integer
	//				  n, m merupakan parameter input bertipe integer (elemen dari array M)
	//  Output		: True / False (Boolean)
	//  Author		: Ahmad Aji Naufal Ali
	
	bool cek = true;
	int i, j;
	
	i = 0;
	while ((i < n) && (cek))
	{
		j = 0;
		while ((j < m) && (cek))
		{
			if ((i < j) && (i < 4) && (j < 4) && (M[i][j] != 0))
			{
				cek = false;
			} else if (M[i][j] == 0)
				{
					cek = false;
				}
		j++;
		}
	i++;		
	}	
	
	return cek;
	
}

/* Function */
bool isSepuluhAda(int n, int m, int M[n][m]){
	
	//  Deksripsi	: Mencari apakah ada angka 10 di suatu matriks
	//  Input		: M merupakan parameter input array dua dimensi bertipe integer
	//				  n, m merupakan parameter input bertipe integer (elemen dari array M)
	//  Output		: True / False (Boolean)
	//  Author		: Cahya Ramadhan

	int baris, kolom;
	bool ada = false;
	
	baris = 0;
	while(ada == false && baris < n){
		kolom = 0;
		while(ada == false && kolom < m){
			if(M[baris][kolom] == 10)
				ada = true;
			if(ada == false)
				kolom++;
		}
		if(ada == false)
			baris++;
	}
	
	if(ada == true)
		return true;
		else return false;
}

/* Function */
int lokasiSepuluh (int n, int m, int M[n][m])
{
	//  Deksripsi	: Mencari apakah ada angka 10 di suatu matriks
	//  Input		: M merupakan parameter input array dua dimensi bertipe integer
	//				  n, m merupakan parameter input bertipe integer (elemen dari array M)
	//  Output		: Tulisan kemunculan andka sepuluh dan lokasinya (JIKA ADA) 
	//				  Tulisan tidak adanya angka sepuluh (JIKA TAK ADA)
	//  Author		: Ahmad Aji Naufal Ali
	bool adaSepuluh, cek = true;
	int i, j, k, jmlSepuluh;
	
	typedef struct {
        int x;
        int y;
	} Point; 

	Point p[25]; //mendeklarasikan tipe data point
	
	adaSepuluh = isSepuluhAda(n, m, M);
	
	if (adaSepuluh)
	{
		i = 0;
		jmlSepuluh = 0;
		while (i < n)
		{
			j = 0;
			while (j < m)
			{
				if (M[i][j] == 10)
				{
					p[jmlSepuluh].y = i;
					p[jmlSepuluh].x = j;
					jmlSepuluh++;
					
				}
				
			j++;
			}
		i++;		
		}
		
		printf("\nJumlah KEMUNCULAN ANGKA SEPULUH : %d kali\n", jmlSepuluh);
		printf("\nTERLETAK DI POSISI : ");
		i = 0;
		while (i < jmlSepuluh)
		{
			printf("\n%d. (%d,%d)", i+1, p[i].y + 1, p[i].x + 1); //ditambah satu karena posisi dimulai dari 1 sedangkan indeks array dimulai dari 0	
		i++;
		}	
		
	} else 
		{
			printf("\nTIDAK ADA ANGKA SEPULUH pada matriks !\n");
		}
}


/* Procedure */
void sortAscending (int n, int m, int M[n][m])
{
	// Deskripsi 	: Mengurutkan Array dari yang terkecil dengan selection sort
	// I.S			: Array 
	// FS 			: Array yang sudah terurut per baris
	// Author		: Ahmad Aji Naufal Ali

    int i, j, k;
    int min, temp;
	
	k = 0;
	while (k < n)
	{
	    for(i = 0; i < m; i++)
	    {
	        temp = M[k][i];
	        for(j = i+1; j < m; j++)
	        {
	            if (temp > M[k][j]) //Jika lebih besar swap
	            {
	                temp   = M[k][j]; // min diisi nilai minimal
	                min    = M[k][i];
	                M[k][j] = min;
	                M[k][i] = temp; //Array yang lebih dahulu masuk ke
	            }
	        }
	    }
	k++;
	}
}

/* Function */
int selisihMaxMin(int n, int m, int M[n][m]){

	//  Deksripsi	: Menghitung selisih nilai terbesar dan nilai terkecil pada suatu matriks
	//  Input		: M merupakan parameter input array dua dimensi bertipe integer
	//				  n, m merupakan parameter input bertipe integer (elemen dari array M)
	//  Output		: Selisih dari nilai terbesar dan nilai terkecil (integer)
	//  Author		: Cahya Ramadhan

	int baris, kolom, max, min;
	
	max = M[0][0];
	min = M[0][0];
	for(baris = 0; baris < n; baris++){
		for(kolom = 0; kolom < m; kolom++){
			if(max < M[baris][kolom])
				max = M[baris][kolom];
			if(min > M[baris][kolom])
				min = M[baris][kolom];
		}
	}

	return max-min;	
}

/* Function */
bool isAdaPrima(int n, int m, int M[n][m])
{
	bool prima, lanjut = true; 
	int i, j, k;
	
	i = 0;
	while ((i < n) && (lanjut))
	{
		j = 0;
		while ((j < m) && (lanjut))
		{
			k = 2;
			prima = true;
			while ((k < M[i][j]) && (prima))
			{
				if (M[i][j] % k == 0)
				{
					prima = false; //bilangan bukan prima;
				}
			k++;
			}

			if (k == M[i][j])
			{
				lanjut = false; //bil prima ditemukan
			} else if (M[i][j] == 2)
				{
					lanjut = false;
				}
		j++;
		}
	i++;		
	}	
	
//	printf("%d %d", i, j);
	
	return lanjut;
	
}
/* Procedure */
void transposeMatriks(int n, int m, int M[n][m], int Mt[n][m]){

	// Deskripsi 	: Men-transposekan suatu matriks
	// I.S			: Array 2D (Matriks)
	// FS 			: Matriks yang sudah ditranspose
	// Author		: Cahya Ramadhan

	int baris, kolom, temp;
	
	for(baris = 0; baris < n; baris++){
		for(kolom = 0; kolom <= baris; kolom++){
			temp = M[baris][kolom];
			Mt[baris][kolom] = M[kolom][baris];
			Mt[kolom][baris] = temp;
		}
	}
}

/* Procedure */
void tampilMatriks(int n, int m, int M[n][m]){

	// Deskripsi 	: Menampilkan suatu matriks
	// I.S			: Array 2D (Matriks)
	// FS 			: Matriks yang sudah ditampilkan di layar
	// Author		: Cahya Ramadhan

	int baris, kolom;
	for(baris = 0; baris < n; baris++){
		for(kolom = 0; kolom < m; kolom++){
			printf("%d", M[baris][kolom]);
			if((kolom != m-1) && (M[baris][kolom] < 10))
			{
				printf("  ");
			} else if (kolom != m-1)
				{
					printf(" ");
				}
		}
		if(baris != n-1)
			printf("\n");
	}
}

/* Function */
int maxInArray(int l, int P[l]){

	int i, max;
	
	max = P[0];
	for(i = 0; i < l; i++){
		if(max < P[i])
			max = P[i];
	}
	return max;
}

/* Function */
int maxPrima(int n, int m, int M[n][m]){

	int baris, kolom, i, j, k = 0, Prima[25], faktor, maximum;
	
	for(baris = 0; baris < n; baris++){
		for(kolom = 0; kolom < m; kolom++){
			faktor = 0;
			for(i = 1; i <= M[baris][kolom]; i++){
				j = M[baris][kolom] % i;
				if(j == 0){
					faktor++;
				}
			}
			if(faktor == 2){
				Prima[k] = M[baris][kolom];
				k++;
			}
		}
	}

	maximum = maxInArray(k, Prima);
	return maximum;
}


