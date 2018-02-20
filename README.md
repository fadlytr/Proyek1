# Proyek1
# Proyek1_Kost
# Halo gan
# Halo om
# Halo saya melline
# Saya Fadly Triansyah, project manager yang bertanggung jawab disini.. Saya wibu
# hmmm
# apa yah
/*=======================================
Program 		: Factorial.c
Deskripsi 		: Recrusive
Nama/NIM		: Fadly Triansyah Rahman/171524008
versi/Tanggal		: 1/26 oktober 2017
Compiler		: Devc++ 5.11
=======================================*/
#include <stdio.h>
int main ()
{ /*deklarasi*/
	int n,m, nilai;
  /*algoritma*/
  nilai=1000;
  scanf ("%d",&m);
  if (m>0)
  	{
  	for (n=1;n<=m;n++)
  		{
  			nilai=nilai*n;
		}
  	}
  printf ("%d",nilai);
  return 0;
}
