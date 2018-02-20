/*=======================================
Program 		: BasicIO1_Nama.c
Deskripsi 		: Hasil 2 kalinya x
Nama/NIM		: Fadly Triansyah Rahman/171524008
versi/Tanggal	: 1/21 oktober 2017
Compiler		: Devc++ 5.11
=======================================*/
#include <stdio.h>
int main() 
{
	/* Deklarasi*/
	int x;
	
	/* Algoritma*/
	printf ("Masukan Angka dari 0 hingga 100 : ");
	scanf ("%d", &x);
	if ((x <= 100) && (x >= 0))
		printf ("%d\n",x*2);
	else 
		printf ("Angka yang dimasukkan Harus 0 hingga 100 Yaa");
	return 0;
}
