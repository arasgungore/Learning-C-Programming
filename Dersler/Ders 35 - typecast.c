#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* "implicit casting: kapal� d�n��t�rme"          "explicit casting: a��k d�n��t�rme"
   bir veri tipindeki de�eri ba�ka bir veri tipine atarken yap�lan d�n���me "casting" ad� verilir
   implicit (kapal�) ve explicit (a��k) olmak �zere iki t�r d�n��t�rme y�ntemi vard�r:

int main() {																			int main() { 
	int x=10;			//integer x															double x=1.2;		//double x 
	char y='a';			//character y														int y=(int)x + 1;	//x explicit bir �ekilde int'e d�n��t�r�ld�
	x=x+y;				//y implicit bir �ekilde int'e d�n��t�r�ld�		('a'=97)			printf("y=%d",y);	//"y=2"
	float z=x+1.0;		//x implicit bir �ekilde float'a d�n��t�r�ld�					}
	printf("x=%d, z=%.3f",x,z);	//"x=107, z=108.000"
}

int main() {
	char ch;
	int a=15,b=39;
	float f=2.71;
	double g;
	ch='t'-7;				//'t' karakteri implicit casting ile int'e d�n��t�r�ld�, sonra bunlar�n sonucu da implicit casting ile char'a d�n��t�r�ld�		('t'=116)
	printf("Karakter ve ASCII kodu: %d %c",(int)ch,ch);	//ch explicit casting ile int'e d�n��t�r�ld�,	"109 m"
	g=f+b/a;				//f implicit casting ile double'a d�n��t�r�ld�, ayr�ca a ve b 2'si de int oldu�undan int b�lmesi yap�ld� ve bunun sonucu da implicit casting ile double'a d�n��t�r�ld�
	printf("\ng=%lf",g);	//2.710000+2.000000="4.710000"
	g = f + (double)b/a;	//f yine implicit casting ile double'a d�n��t�r�ld�, ama b explicit olarak double, a ise int oldu�undan a implicit olarak double oldu, double b�lmesi yap�ld� ve bunun sonucu da double oldu
	printf("\ng=%lf",g);	//2.710000+2.600000="5.310000"
	return 0;
}

   tabii bunlar� az �ok biliyorduk, �imdi string'i de i�in i�ine katal�m
   <stdlib.h> k�t�phanesinde bulunan ve string ile say�sal veri tipleri (int,long,float,...) aras�nda d�n���m yapmam� sa�layan fonksiyonlar �unlard�r: atoi, atol, atof, itoa, ltoa, ftoa

   "atoi: ASCII to integer"     "atol: ASCII to long"     "atof: ASCII to float"     "itoa: integer to ASCII"     "ltoa: long to ASCII"

   atoi(str): str katar�n� int veri tipine d�n��t�r�r
   atol(str): str katar�n� long veri tipine d�n��t�r�r	
   atof(str): str katar�n� float veri tipine d�n��t�r�r
   itoa(int,str,t): int veri tipindeki ve t taban�ndaki "int" adl� de�i�keni string'e d�n��t�r�r
   ltoa(long,str,t): long veri tipindeki ve t taban�ndaki "int" adl� de�i�keni string'e d�n��t�r�r
   hadi �imdi bir �rnekte g�relim

int main() {																			int main() {
	char katar1[4]="3169";																	int tam_sayi=256;
	char katar2[9]="123456789";																long uzun_tam_sayi=19141918;
	char katar3[7]="3.14159";																char a[3],b[8];
	int a=atoi(katar1);																		itoa(tam_sayi,a,10);
	long b=atol(katar2);																	ltoa(uzun_tam_sayi,b,10);
	float c=atof(katar3);																	printf("%s\n%s",a,b);
	printf("%d\n%ld\n%f",a,b,c);														}
}

   "sprintf: print formatted to string"
   itoa() ve ltoa() fonksiyonlar�na daha iyi ve kapsaml� bir alternatif olarak sprintf ve snprintf fonksiyonlar� kullan�labilir
   printf fonksiyonu nas�l parametre olarak girilen katar� konsola, fprintf ise dosya pointer'�na yazd�r�yorsa sprintf de girilen katar� ba�ka bir string de�i�kenine at�yor
   sprintf fonksiyonu strcpy, snprintf fonksiyonu ise strncpy gibi d���n�lebilir */

int main() {
	int a=10,b=20;
	char cumle[200];
	sprintf(cumle,"%d ile %d'nin toplami %d'dir.",a,b,a+b);			//cumle adl� katar�n tuttu�u 1. de�er
	printf("%s\n",cumle);
	sprintf(cumle,"Pi'nin bellekte saklanan degeri: %.20f",M_PI);	//2. de�er
	printf("%s\n",cumle);
	int gun=7,ay=3,yil=2020;
	sprintf(cumle,"Bugun tarihlerden %02d.%02d.%d",gun,ay,yil);		//3. de�er
	printf("%s\n",cumle);
	char cumle2[20];
	strcpy(cumle2,"Sikim 31 cm");						//cumle adl� katar�n tuttu�u 1. de�er
	snprintf(cumle2+6,13,"0.00000001 mm");				//2. de�er, ve strncpy fonksiyonu gibi cumle'nin 6. harfinden itibaren olan k�sm� de�i�tirdim
	printf("%s",cumle2);	//bu arada "&string[i]" ile "string+i" ayn� �eyler oldu�undan �t�r� yukar�da 1. parametreye "&cumle2[6]" de yaz�labilirdi
	exit(0);
}
