#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* "typedef: type definition"
   veri (deðiþken) türlerini yeniden adlandýrmak için typedef yapýsý kullanýlýr
   typedef'in genel syntax'ý typedef degiskenin_default_adi degiskenin_yeni_adi biçimindedir	(pretty self-explanatory bence)

typedef int tam_sayi;																	typedef float d1;
typedef double ondalikli_sayi;															int main() {
int main() {																				float toplam;
	tam_sayi a=8,b=19;																		d1 d2=20.45;		//"float" ve "d1" ayný þey þuan, yani "d1" bir deðiþken deðil deðiþken türü oluyor
	ondalikli_sayi x=4.56,y=11.313131;														d1 d3=43.167;
	printf("Tam sayilar: a=%d b=%d\nOndalikli sayilar: x=%lf y=%lf",a,b,x,y);				toplam=d2+d3;
	return 0;																				printf("Toplam: %.3f",toplam);
}																							}


typedef int tms;
typedef tms tams;

int main() {
	int sayi1;
	tms sayi2;
	tams sayi3;

	sayi2=4;
	sayi3=11;

	for(sayi1=1; sayi1<=5; sayi1++, sayi2++, sayi3++)
		printf("sayi2+sayi3=%d\n", sayi2+sayi3);		//çýktýlar "15,17,19,21,23"
}

   typedef özellikle structure'larla birlikte kullanýlýr

typedef struct kitaplar {
   char baslik[50];
   char yazar[50];
   char konu[100];
   int kitap_id;
} Kitap;	//önce "kitaplar" adlý structure'ýmý oluþturup sonra "typedef struct kitaplar Kitap" da diyebilirdim, ama böylelikle hem struct'ýmý oluþturup hem de yeniden adlandýrdým

int main() {
	Kitap kitap1,kitap2;	//"Kitap" adlý struct'ým ile main fonksiyonu içerisinde "kitap1" ve "kitap2" olarak iki tane obje oluþturdum

	strcpy(kitap1.baslik,"Mein Kampf (Kavgam)");
	strcpy(kitap1.yazar,"Adolf Hitler");
	strcpy(kitap1.konu,"Nasyonal sosyalizm");
	kitap1.kitap_id=6495407;
	printf("Kitabin basligi: %s\n",kitap1.baslik);
	printf("Kitabin yazari: %s\n",kitap1.yazar);
	printf("Kitabin konusu: %s\n",kitap1.konu);
	printf("Kitap_id: %d\n",kitap1.kitap_id);


	strcpy(kitap2.baslik,"Fifty Shades of Grey (Grinin 50 Tonu)");
	strcpy(kitap2.yazar,"E. L. James");
	strcpy(kitap2.konu,"Cinsellik");
	kitap2.kitap_id=7490123;
	printf("\n\nKitabin basligi: %s\n",kitap2.baslik);
	printf("Kitabin yazari: %s\n",kitap2.yazar);
	printf("Kitabin konusu: %s\n",kitap2.konu);
	printf("Kitap_id: %d\n",kitap2.kitap_id);
	return 0;
}


typedef struct {
	char cdizi1[20];
	char cdizi2[20];
	int id1;
} bolum;
int main() {
	bolum b1,b2;		//"bolum" struct'ýma ait y1 ve y2 olmak üzere 2 tane nesnem var
	strcpy(b1.cdizi1,"Bilgisayar");
	strcpy(b1.cdizi2,"Muhendisligi");
	strcpy(b2.cdizi1,"Makine");
	strcpy(b2.cdizi2,"Muhendisligi");
	b1.id1=150;
	b2.id1=210;
	printf("Bolum 1: %s %s\nBolum 2: %s %s\n",b1.cdizi1,b1.cdizi2,b2.cdizi1,b2.cdizi2);
	printf("Bolum 1 id: %d\nBolum 2 id: %d",b1.id1,b2.id1);
}

   "." yerine "->" kullanarak iþaretçi (pointer) bildirimiyle struct'ýmýzdaki verilere eriþebiliriz */

typedef struct {
	char cdizi1[20];
	char cdizi2[20];
	int id1;
} yapi1;
int main() {
	yapi1 *yp1;	//yapi1 structure'na ait *yp1 adlý bir pointer nesnesi tanýmladým
	yp1=(yapi1*) malloc(sizeof(yapi1));		//sizeof(yapi1)=20+20+4=44 byte
	strcpy(yp1 -> cdizi1, "Bilgisayar");	//bu arada struct'larý array gibi düþünebiliriz, ama aslýnda ayrý bir veri tipi
	strcpy(yp1 -> cdizi2, "Programlama");
	yp1 -> id1 = 42;
	printf("%s %s %d", yp1 -> cdizi1, yp1 -> cdizi2, yp1 -> id1);
}
