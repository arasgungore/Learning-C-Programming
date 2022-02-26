#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* "preprocessor: ön iþlemci"		"define: tanýmlama"
   C'de bir kod yazýldýðýnda derleme öncesi ön iþlemci (preprocessor) komutlarý çalýþtýrýlýr ve bu komutlara makro adý verilir		(#include <math.h> gibi)
   týpký main fonksiyonunun içinde tanýmlanan char,int,float,double deðiþkenleri (variable) gibi makro direktiflerinden "define" ile sabitler (constant) tanýmlanýr
   genel syntax'ý hashtag define makroadi => #define makroadi biçimindedir

#define PI 3.141592
int main() {
	double r,teta;			//PI sabit (constant), r ve teta deðiþken (variable)
	printf("Daire diliminin yaricapini ve acisini (derece) giriniz: ");
	scanf("%lf%lf",&r,&teta);
	double dairedilimi=PI*r*r*teta/360;
	printf("Daire diliminin alani: %lf",dairedilimi);
}

   typedef ile veri türlerine yaptýðýmýz gibi built-in fonksiyonlara da takma isimler verebiliriz

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

   dahasý kendi custom fonksiyonlarýmýzý da define ile tanýmlayabiliriz

#define merhaba_yazdir(x) int i; for(i=1;i<=x;i++) printf("Merhaba\n");

int main() {
	int yazdirma_adedi;
	printf("Kac defa \"Merhaba\" yazdirilsin?: ");
	scanf("%d",&yazdirma_adedi);
	merhaba_yazdir(yazdirma_adedi);
}


#define MAK01(id1,id2) id1+id2			//fonksiyonun return'lediði deðeri tanýmladým
#define MAK02(cp1,cp2) strcpy(cp1,cp2)
#define MAK03(cp1,cp2) strcat(cp1,cp2)
#define MAK04(id1) fonk(id1)			//fonksiyonlarý tanýmladým

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

#define nesemizi "havamýzý"
#define sebiha "Semra"
#define ekrana_yazdir printf
#define deger_al scanf

typedef int tam_sayi;
typedef double ondalikli_sayi;
int main() {
	setlocale(LC_ALL,"Turkish");	//<locale.h> kütüphanesindeki setlocale fonksiyonu sayesinde Türkçe dahil bilumum bütün dillerin kendine has karakterlerini kullanabilirim
	ondalikli_sayi x,y;
	tam_sayi secim;
	ekrana_yazdir("Semra 2 sayý gir de neþemizi bulalým: ");	//artýk "ç,Ç,ð,Ð,ý,Ý,ö,Ö,þ,Þ,ü,Ü" harflerini printf içinde kullanabilirim :))
	deger_al("%lf%lf",&x,&y);
	ekrana_yazdir("\n1-Toplama\n2-Çýkarma\n3-Çarpma\n4-Bölme\n5-Mod alma\n\nSemra yapmak istediðin iþlemi seç de neþemizi bulalým: ");
	deger_al("%d",&secim);
	switch(secim) {
		case 1: ekrana_yazdir(sebiha " sonucu gör de " nesemizi " bulalým: %lf",x+y); break;
		case 2: ekrana_yazdir(sebiha " sonucu gör de " nesemizi " bulalým: %lf",x-y); break;
		case 3: ekrana_yazdir(sebiha " sonucu gör de " nesemizi " bulalým: %lf",x*y); break;
		case 4: ekrana_yazdir(sebiha " sonucu gör de " nesemizi " bulalým: %lf",x/y); break;
		case 5: ekrana_yazdir(sebiha " sonucu gör de " nesemizi " bulalým: %d",(int)x%(int)y); break;
		default: ekrana_yazdir("Aþk olsun " sebiha ", " nesemizi "\b kaçtý");
	}
	return 0;
}
