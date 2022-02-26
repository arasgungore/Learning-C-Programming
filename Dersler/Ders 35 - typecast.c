#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* "implicit casting: kapalý dönüþtürme"          "explicit casting: açýk dönüþtürme"
   bir veri tipindeki deðeri baþka bir veri tipine atarken yapýlan dönüþüme "casting" adý verilir
   implicit (kapalý) ve explicit (açýk) olmak üzere iki tür dönüþtürme yöntemi vardýr:

int main() {																			int main() { 
	int x=10;			//integer x															double x=1.2;		//double x 
	char y='a';			//character y														int y=(int)x + 1;	//x explicit bir þekilde int'e dönüþtürüldü
	x=x+y;				//y implicit bir þekilde int'e dönüþtürüldü		('a'=97)			printf("y=%d",y);	//"y=2"
	float z=x+1.0;		//x implicit bir þekilde float'a dönüþtürüldü					}
	printf("x=%d, z=%.3f",x,z);	//"x=107, z=108.000"
}

int main() {
	char ch;
	int a=15,b=39;
	float f=2.71;
	double g;
	ch='t'-7;				//'t' karakteri implicit casting ile int'e dönüþtürüldü, sonra bunlarýn sonucu da implicit casting ile char'a dönüþtürüldü		('t'=116)
	printf("Karakter ve ASCII kodu: %d %c",(int)ch,ch);	//ch explicit casting ile int'e dönüþtürüldü,	"109 m"
	g=f+b/a;				//f implicit casting ile double'a dönüþtürüldü, ayrýca a ve b 2'si de int olduðundan int bölmesi yapýldý ve bunun sonucu da implicit casting ile double'a dönüþtürüldü
	printf("\ng=%lf",g);	//2.710000+2.000000="4.710000"
	g = f + (double)b/a;	//f yine implicit casting ile double'a dönüþtürüldü, ama b explicit olarak double, a ise int olduðundan a implicit olarak double oldu, double bölmesi yapýldý ve bunun sonucu da double oldu
	printf("\ng=%lf",g);	//2.710000+2.600000="5.310000"
	return 0;
}

   tabii bunlarý az çok biliyorduk, þimdi string'i de iþin içine katalým
   <stdlib.h> kütüphanesinde bulunan ve string ile sayýsal veri tipleri (int,long,float,...) arasýnda dönüþüm yapmamý saðlayan fonksiyonlar þunlardýr: atoi, atol, atof, itoa, ltoa, ftoa

   "atoi: ASCII to integer"     "atol: ASCII to long"     "atof: ASCII to float"     "itoa: integer to ASCII"     "ltoa: long to ASCII"

   atoi(str): str katarýný int veri tipine dönüþtürür
   atol(str): str katarýný long veri tipine dönüþtürür	
   atof(str): str katarýný float veri tipine dönüþtürür
   itoa(int,str,t): int veri tipindeki ve t tabanýndaki "int" adlý deðiþkeni string'e dönüþtürür
   ltoa(long,str,t): long veri tipindeki ve t tabanýndaki "int" adlý deðiþkeni string'e dönüþtürür
   hadi þimdi bir örnekte görelim

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
   itoa() ve ltoa() fonksiyonlarýna daha iyi ve kapsamlý bir alternatif olarak sprintf ve snprintf fonksiyonlarý kullanýlabilir
   printf fonksiyonu nasýl parametre olarak girilen katarý konsola, fprintf ise dosya pointer'ýna yazdýrýyorsa sprintf de girilen katarý baþka bir string deðiþkenine atýyor
   sprintf fonksiyonu strcpy, snprintf fonksiyonu ise strncpy gibi düþünülebilir */

int main() {
	int a=10,b=20;
	char cumle[200];
	sprintf(cumle,"%d ile %d'nin toplami %d'dir.",a,b,a+b);			//cumle adlý katarýn tuttuðu 1. deðer
	printf("%s\n",cumle);
	sprintf(cumle,"Pi'nin bellekte saklanan degeri: %.20f",M_PI);	//2. deðer
	printf("%s\n",cumle);
	int gun=7,ay=3,yil=2020;
	sprintf(cumle,"Bugun tarihlerden %02d.%02d.%d",gun,ay,yil);		//3. deðer
	printf("%s\n",cumle);
	char cumle2[20];
	strcpy(cumle2,"Sikim 31 cm");						//cumle adlý katarýn tuttuðu 1. deðer
	snprintf(cumle2+6,13,"0.00000001 mm");				//2. deðer, ve strncpy fonksiyonu gibi cumle'nin 6. harfinden itibaren olan kýsmý deðiþtirdim
	printf("%s",cumle2);	//bu arada "&string[i]" ile "string+i" ayný þeyler olduðundan ötürü yukarýda 1. parametreye "&cumle2[6]" de yazýlabilirdi
	exit(0);
}
