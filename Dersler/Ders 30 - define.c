#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* "preprocessor: �n i�lemci"		"define: tan�mlama"
   C'de bir kod yaz�ld���nda derleme �ncesi �n i�lemci (preprocessor) komutlar� �al��t�r�l�r ve bu komutlara makro ad� verilir		(#include <math.h> gibi)
   t�pk� main fonksiyonunun i�inde tan�mlanan char,int,float,double de�i�kenleri (variable) gibi makro direktiflerinden "define" ile sabitler (constant) tan�mlan�r
   genel syntax'� hashtag define makroadi => #define makroadi bi�imindedir

#define PI 3.141592
int main() {
	double r,teta;			//PI sabit (constant), r ve teta de�i�ken (variable)
	printf("Daire diliminin yaricapini ve acisini (derece) giriniz: ");
	scanf("%lf%lf",&r,&teta);
	double dairedilimi=PI*r*r*teta/360;
	printf("Daire diliminin alani: %lf",dairedilimi);
}

   typedef ile veri t�rlerine yapt���m�z gibi built-in fonksiyonlara da takma isimler verebiliriz

#define PI	3.141592
#define ekrana_yazdir	printf
#define deger_al	scanf
int main() {
	double yaricap,alan,cevre;
	ekrana_yazdir("Cemberin yaricapini giriniz: ");
	deger_al("%lf",&yaricap);
	alan=PI*yaricap*yaricap;
	cevre=2*PI*yaricap;
	ekrana_yazdir("Cemberin alani: %.4f\nCemberin cevresi: %.4f",alan,cevre);
}

   dahas� kendi custom fonksiyonlar�m�z� da define ile tan�mlayabiliriz

#define merhaba_yazdir(x) int i; for(i=1;i<=x;i++) printf("Merhaba\n");

int main() {
	int yazdirma_adedi;
	printf("Kac defa \"Merhaba\" yazdirilsin?: ");
	scanf("%d",&yazdirma_adedi);
	merhaba_yazdir(yazdirma_adedi);
}


#define MAK01(id1,id2) id1+id2			//fonksiyonun return'ledi�i de�eri tan�mlad�m
#define MAK02(cp1,cp2) strcpy(cp1,cp2)
#define MAK03(cp1,cp2) strcat(cp1,cp2)
#define MAK04(id1) fonk(id1)			//fonksiyonlar� tan�mlad�m

void fonk(char* string) {
	int i;
	for(i=0;i<20;i++)
		printf("%s",string);
}
int main() {
	char cdizi[50];
	MAK02(cdizi,"Object");
	printf("CMPE %d - %s\ntr", MAK01(MAK01(69,31),60), MAK03(cdizi," Oriented Programming"));
	MAK04("ol");
} */

#define nesemizi "havam�z�"
#define sebiha "Semra"
#define ekrana_yazdir printf
#define deger_al scanf

typedef int tam_sayi;
typedef double ondalikli_sayi;
int main() {
	setlocale(LC_ALL,"Turkish");	//<locale.h> k�t�phanesindeki setlocale fonksiyonu sayesinde T�rk�e dahil bilumum b�t�n dillerin kendine has karakterlerini kullanabilirim
	ondalikli_sayi x,y;
	tam_sayi secim;
	ekrana_yazdir("Semra 2 say� gir de ne�emizi bulal�m: ");	//art�k "�,�,�,�,�,�,�,�,�,�,�,�" harflerini printf i�inde kullanabilirim :))
	deger_al("%lf%lf",&x,&y);
	ekrana_yazdir("\n1-Toplama\n2-��karma\n3-�arpma\n4-B�lme\n5-Mod alma\n\nSemra yapmak istedi�in i�lemi se� de ne�emizi bulal�m: ");
	deger_al("%d",&secim);
	switch(secim) {
		case 1: ekrana_yazdir(sebiha " sonucu g�r de " nesemizi " bulal�m: %lf",x+y); break;
		case 2: ekrana_yazdir(sebiha " sonucu g�r de " nesemizi " bulal�m: %lf",x-y); break;
		case 3: ekrana_yazdir(sebiha " sonucu g�r de " nesemizi " bulal�m: %lf",x*y); break;
		case 4: ekrana_yazdir(sebiha " sonucu g�r de " nesemizi " bulal�m: %lf",x/y); break;
		case 5: ekrana_yazdir(sebiha " sonucu g�r de " nesemizi " bulal�m: %d",(int)x%(int)y); break;
		default: ekrana_yazdir("A�k olsun " sebiha ", " nesemizi "\b ka�t�");
	}
	return 0;
}
