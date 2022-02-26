#include <stdio.h>
#include <stdlib.h>

/* "float: float variable"		(ne bekliyodun aq)
   ondalýk sayýlar için float deðiþkeni kullanýlýr ve printf ve scanf'te "%f: float" belirteci ile ifade edilir
   char ==> %c , string (char[]) ==> %s , int ==> %d , float==> %f
   en fazla virgülden sonraki 6 sayýyý algýlar
   scanf'te týpký int deðiþkeninde de olduðu gibi "&" (and) operatörü kullanýlýr
   her satýrý ; ile bitirmeyi unutma ve en sondaki printf'e yanlýþlýkla & koyma!!!

int main() {																										int main() {																	int main() {

	float pi,r,alan,cevre;																								float Turkce,mat,fen,sosyal,taban,toplampuan;									float eskimaas,zam,zamorani,yenimaas;
	printf("***** Dairede Cevre ve Alan *****\n\nDairenin Yaricapini Giriniz: ");										taban=100.160;																	printf("Maasinizi Giriniz: ");
	scanf("%f",&r);																										printf("Turkce Netiniz: ");														scanf("%f",&eskimaas);
	pi=3.14159265358979;  //zaten pi=3.141592 alacak																	scanf("%f",&Turkce);															printf("Yuzde Kac Zam Istersiniz?: ");
	cevre=2*pi*r;																										printf("Matematik Netiniz: ");													scanf("%f",&zamorani);
	alan=pi*r*r;																										scanf("%f",&mat);																zam=eskimaas*zamorani/100;
	printf("\nDairenin Alaný: %f - Dairenin Cevresi: %f",alan,cevre);													printf("Fen Bilimleri Netiniz: ");												yenimaas=eskimaas+zam;
}																														scanf("%f",&fen);																printf("\n\nYeni Maasiniz %f olmustur.Gule gule harcayin. :)))",yenimaas);
																														printf("Sosyal Bilimler Netiniz: ");											}
int main() {																											scanf("%f",&sosyal);
																														toplampuan=taban+Turkce*1.999+mat*3.998+fen*2.999+sosyal*1;
	float en,boy,yukseklik,yuzeyalani,hacim;																			printf("YGS-1 Puan Turunde Sonucunuz: %f",toplampuan);
																													}
	printf("***** Ondalik Kenar Uzunluklari Ile Prizma Yuzey Alani ve Hacim Hesaplama *****");

	en=5.167;
	boy=8.12;
	yukseklik=13.4;
	yuzeyalani=(en*boy+(boy+en)*yukseklik)*2;
	hacim=en*boy*yukseklik;

	printf("\n\nKenar uzunluklari sirasiyla %f, %f ve %f olan bir dikdortgen prizmanin:\na) Yuzey alani %f,\nb) Hacmi %f'dir.",en,boy,yukseklik,yuzeyalani,hacim);

}

   tabii verileri koda hazýr girmek sýkýcý olduðu için bir de kodu çalýþtýrýrken girelim ;) */

int main() {

	float en,boy,yukseklik,yuzeyalani,hacim;

	printf("***** Ondalik Kenar Uzunluklari Ile Prizma Yuzey Alani ve Hacim Hesaplama *****\n\n");

	printf("Prizmanin Enini Giriniz: ");
	scanf("%f",&en);
	printf("Prizmanin Boyunu Giriniz: ");
	scanf("%f",&boy);
	printf("Prizmanin Yuksekligini Giriniz: ");
	scanf("%f", &yukseklik);
	yuzeyalani=(en*boy+(boy+en)*yukseklik)*2;
	hacim=en*boy*yukseklik;

	printf("\n\n*******************************************************************************\n\nKenar uzunluklari sirasiyla %f, %f ve %f olan bir dikdortgen prizmanin:\na) Yuzey alani %f,\nb) Hacmi %f'dir.",en,boy,yukseklik,yuzeyalani,hacim);

	return 0;
}
