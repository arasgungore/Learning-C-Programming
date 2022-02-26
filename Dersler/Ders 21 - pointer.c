#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* "pointer: g�sterici"
   programlamada bellekte (RAM'de) saklanan verilerin haf�za alan�n� g�stermek i�in kullan�lan veri tipine "pointer" (g�sterici) denir
   RAM (Random Access Memory, Rastgele Eri�imli Bellek) bilgilerin ge�ici olarak sakland��� bir bellek t�r�d�r ve bu bilgisayar i�in 16 GB=16*1024*1024*1024=2^34=17179869184 adet byte'dan (g�zden) olu�ur
   1 g�z=1 byte=8 bit oldu�unu da bildi�imize g�re misal "int tam=33" verisini ele alal�m
   int de�i�keni 4 byte'l�k bir veri tipi oldu�u i�in ona bellekte 4 byte'l�k bir h�cre ayr�l�r
   bu h�creye 33 say�s�n�n binary'deki kar��l��� olan 4 byte'l�k (32 bit'lik) "00000000 00000000 00000000 00100001" say�s� h�crenin 67108117-67108120 numaral� g�zleri i�gal etti�ini varsayarsak belle�e ��yle yaz�l�r:
   Bellek g�zleri (1 byte):		........	........	00000000	00000000	00000000	00100001	........	........	........	........	........
   Adres (hexadecimal):			0x3fffd12	0x3fffd13	0x3fffd14	0x3fffd14	0x3fffd15	0x3fffd16	0x3fffd17	0x3fffd18	0x3fffd19	0x3fffd1a	0x3fffd1b
   Adres (decimal):				67108115	67108116	67108117	67108118	67108119	67108120	67108121	67108122	67108123	67108124	67108125
   bellek adresleri genellikle on alt�l�k (hexadecimal) say� sistemi ile g�sterilir ve "%x: hexadecimal" veya "%p: pointer" belirte�leri ile ifade edilir   (iki belirte� de ayn� ��kt�y� verir)
   de�i�kenlerin bellek adreslerini yazd�rmak i�in printf fonksiyonu "&" adres operat�r� ile birlikte kullan�l�r

int main() {
	
	int sayi1=10,sayi2=20;
	float sayi3=10.25;
	char harf='a',kelime[10]="karanfil";
	printf("********* Veriler *********\n\n");
	printf("%d\n%d\n%f\n%c\n%s",sayi1,sayi2,sayi3,harf,kelime);
	printf("\n\n**** Verilerin Bellek Adresleri ****\n\n");
	printf("16 Tabaninda (hexadecimal):\n%x\n%x\n%x\n%x\n%x\n\n",&sayi1,&sayi2,&sayi3,&harf,&kelime);
	printf("10 Tabaninda (decimal):\n%d\n%d\n%d\n%d\n%d",&sayi1,&sayi2,&sayi3,&harf,&kelime);
}

   g�stericilerin genel syntax'� de�i�kent�r� y�ld�z pointerad� e�ittir ampersand de�i�kenad� ==> degiskenturu *pointeradi=&degiskenadi
   pointer'lar de�i�kenlerin girildi�i adreslerin yerini tutar
   misal 1 byte'l�k "char harf='m'" verisini ele alal�m, ve pointer'�m�z� da "char *p=&harf" diye tan�mlayal�m
   m karakterinin ASCII (American Standard Code for Information Interchange) kodu 109 oldu�u i�in bunun binary'deki kar��l��� olan "01101101" say�s� bellekteki bir g�ze kaydedilir
   char harf='m' verisi i�in 5490238 numaral� g�z�, char *p=&harf verisinin de 5490241 numaral� g�z� i�gal etti�ini varsayarsak bu veriler belle�e ��yle yaz�l�r:
   Bellek g�zleri (1 byte):		........	........	........	01101101	........	........	5490238		........
   Adres (decimal):				5490235		5490236		5490237		5490238		5490239		5490240		5490241		5490242
   g�r�ld��� �zere p pointer'� char harf='m' verisinin sakland��� adresi haf�zada ba�ka bir g�z�n i�inde tutar

int main() {
	char soru='?';
	int satan=666;
	char *quiz=&soru;
	int *cehennem=&satan;
	printf("******* Verileri Ekrana Yazdirma *******\n1. Veri: %c\n2. Veri: %d\n\n",soru,satan);
	printf("******* Adresleri Ekrana Yazdirma *******\n1. Adres: %x\n2. Adres: %x",quiz,cehennem);		//bu a�amada &soru ve &satan yazmakla quiz ve cehennem g�stericilerini kullanmak ayn� �ey
}

   pointer'lara yapt���m i�lemlerle verinin bellekte sakland��� yeri (adresini) de�i�tirebilirim

int main() {
	char pipi='h';
	int kuku=69;
	char *pt1=&pipi;
	int *pt2=&kuku;
	printf("Adres 1: %x (%d) Adres 2: %x (%d)\n\n",pt1,pt1,pt2,pt2);	//��kt�lar�m misal onluk taban sisteminde "100" ve "106" olsun
	pt1++;																//(normalde 7 basamakl� say�lar, ve RAM'im daha �ok i�gal edilseydi 8-12 basamakl� say�lar dahi olabilirdi)
	pt2++;
	printf("Adres 1: %x (%d) Adres 2: %x (%d)\n\n",pt1,pt1,pt2,pt2);	//yeni ��kt�lar�m "101" ve "110" olacak
	pt1+=15;															//bunun sebebi char de�i�keninin 1 byte'l�k, int de�i�keninin ise 4 byte'l�k bir veri tipi olmas�
	pt2-=6;																//bu y�zden char de�i�keninin adresi 1 artarken, bellekte 4 byte yer kaplayan int de�i�keninin adresi haliyle 4 artacak
	printf("Adres 1: %x (%d) Adres 2: %x (%d)\n\n",pt1,pt1,pt2,pt2);	//bu sefer ise ��kt�lar�m "116" ve "86" olacak
}																		//char pipi='h' verisinin adresi 1*15=15 artarken, int kuku=69 verisinin adresi 4*6=24 azal�r

int main() {
	int a=10;
	int *p,*q;
	p=&a;
	q=&p;
	printf("a'nin degeri: %d\n",a);			//a'n�n de�erini yazd�r�r, yani "10"
	printf("a'nin adresi: %d\n",&a);		//a'n�n adresini yazd�r�r (bunu bilemem)
	printf("a'nin adresi: %d\n",p);			//a'n�n adresini yazd�r�r, ��nk� p=&a, yani p pointer'� a'n�n adres de�erine e�it
	printf("a'nin degeri: %d\n",*p);		//p'nin gitti�i yerin de�erini yazd�r�r, ve p pointer'� a'ya gitti�i i�in a'n�n de�eri olan "10" yazd�r�r
	printf("p'nin adresi: %d\n",&p);		//p'nin adresini yazd�r�r (bunu da bilemem)
	printf("p'nin adresi: %d\n",q);			//p'nin adresini yazd�r�r, ��nk� q=&p, yani q pointer'� p pointer'�n�n adres de�erine e�it
	printf("a'nin adresi: %d\n",*q);		//q'nun gitti�i yerin de�erini yazd�r�r, ve q pointer'� p'ye gitti�i i�in p pointer'�n�n de�eri olan a'n�n adresini yazd�r�r
	printf("q'nun adresi: %d\n",&q);		//q'nun adresini yazd�r�r (adresleri bilemem demi� miydim?)
}											//o zaman p=&a, q=&p iken *p=a, *q=p olur, bu da g�sterir ki & ve * operat�rleri birbirinin tersi oluyor
											//p=&a: p pointer'� a'n�n bulundu�u adres de�erine e�ittir; *p=a: p pointer'�n�n tuttu�u adres de�erinde saklanan veri a'ya e�ittir

int main() {
	int ***p,**q,*r,s;
	s=823;
	r=&s;
	q=&r;
	p=&q;
	printf("q pointer'inin adresi: %p\n",p);		// p = &q
	printf("r pointer'inin adresi: %p\n",*p);		// *p = q = &r
	printf("r pointer'inin adresi: %p\n",q);		// q = &r
	printf("s pointer'inin adresi: %p\n",**p);		// &***p = **p = *q = r = &s
	printf("s pointer'inin adresi: %p\n",*q);		// &**q = *q = r = &s
	printf("s pointer'inin adresi: %p\n",r);		// &*r = r = &s
	printf("s'nin degeri: %d\n",***p);				// ***p = **q = *r = s
	printf("s'nin degeri: %d\n",**q);				// **q = *r = s
	printf("s'nin degeri: %d",*r);					// *r = s
}

   diziler ve g�stericiler aras�nda yak�n bir ili�ki vard�r, ��nk� bir dizinin ADI dizinin ilk eleman�n� saklayan bir G�STER�C�dir
   o y�zden array bir dizi, p bir pointer ve p=array olmak �zere array[i] ile *(p+i) ayn� �ey demektir, ikisi de dizinin i+1. eleman�n� g�stermek i�in kullan�l�r

int main() {
	int kutle[]={1,5,6,9,10,2,8,13},*p,i;
	p=kutle;		//p=&kutle[0] demek ile ayn� �ey
	for(i=0;i<8;i++) {
		printf("%d ",*(p+i));	//olan olay �u: normalde p pointer'� kutle dizisinin ilk eleman�n�n sakland��� yerin adresinin de�erini tutuyor
	}							//mesela ilk eleman�n adresi sall�yorum 9181340 olsayd� 2. eleman�n 9181344, 3. eleman�n 9181348, 4. eleman�n 9181352,..., 8. eleman�n ise 9181368 olurdu
}								//adreslerin 4'er 4'er artmas� olay de�il bu arada, ��nk� nas�l p++ olunca bir int de�i�keninin adresi 4 artarsa, p+i yapt���mda da o p pointer'�n�n tuttu�u adres de�eri 4i kadar artmal�
								//ve dizilerde elemanlar�n ard���k adreslerde sakland���n� da bildi�ime g�re printf fonksiyonu s�rayla p,p+4,p+8,...,p+28 adres de�erlerinde saklanan verileri
								//yani bu dizinin elemanlar�n� bana s�ras�yla yazd�racak ve ��kt�m "1 5 6 9 10 2 8 13" olacak

   demek ki neymi�: *(array+i)=array[i], array+i=&array[i]

int main() {
	int tamsayi[]={23,56,99,4,1337},i;
	float ondalik[]={1.2,3.6,7.7,6.7};
	char string[3][8]={"Ahmet","Mustafa","Coskun"};

	printf("***tamsayi array'i icin***\n");
	for(i=0;i<5;i++)
		printf("%d. index'teki elemanin adresi: %x  |  %d\n",i,tamsayi+i,tamsayi+i);
	for(i=0;i<5;i++)	//adresler 4'er 4'er art�yor (sizeof(int)=4)
		printf("%d. index'teki elemanin degeri: %d\n",i,*(tamsayi+i));

	printf("\n\n***ondalik array'i icin***\n");
	for(i=0;i<4;i++)
		printf("%d. index'teki elemanin adresi: %x  |  %d\n",i,ondalik+i,ondalik+i);
	for(i=0;i<4;i++)	//adresler 4'er 4'er art�yor (sizeof(float)=4)
		printf("%d. index'teki elemanin degeri: %.1f\n",i,*(ondalik+i));

	printf("\n\n***string array'i icin***\n");
	for(i=0;i<3;i++)
		printf("%d. index'teki elemanin adresi: %x  |  %d\n",i,string+i,string+i);
	for(i=0;i<3;i++)	//adresler 8'er 8'er art�yor (sizeof(*string)=8)
		printf("%d. index'teki elemanin degeri: %s\n",i,*(string+i));
}

int main() {
	int dizi[]={13,4,9,-5,45};
	int *ptr;
	ptr=&dizi[0]; //ptr=dizi demek ile ayn� �ey

	printf("Dizim: {13, 4, 9, -5, 45}\n");
	printf("Index:   0, 1, 2,  3,  4\n\n");

	printf("*ptr'nin degeri= %d\n", *ptr);				//ptr dizinin ilk eleman�n� g�sterdi�i i�in ��kt�m "13"
	printf("ptr'nin adresi= %p\n\n", ptr);				//diyelim "62FE00" olsun ptr pointer'�n�n adresi

	printf("*(ptr++)'nin degeri= %d\n", *(ptr++));		//ptr pointer'�n�n o anl�k g�sterdi�i de�er yine 13 oldu�undan ��kt�m "13" olacak ve en son da pointer 1 artacak
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer 1 artt��� (int oldu�u i�in adres 4 artacak) i�in ��kt�m "62FE04"

	printf("(*ptr)++'nin degeri= %d\n", (*ptr)++);		//ptr pointer'� 1 artt��� i�in bir sonraki index'teki eleman olan 4'u g�sterecek, ��kt�m "4", ve en son da pointer'�n G�STERD��� DE�ER 1 artacak
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer artmad��� i�in ��kt�m "62FE04"

	printf("++*ptr'nin degeri= %d\n", ++*ptr);			//ptr pointer'�n�n g�sterdi�i de�er 1 artacak ve pointer'�n g�sterdi�i son de�er 4+1+1=6 oldu�undan ��kt�m "6"
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer hala ayn� adresi tutuyor, ��kt�m "62FE04"

	printf("*++ptr'nin degeri= %d\n", *++ptr);			//ptr pointer'� bir artacak, dolay�s�yla bir sonraki index'teki eleman� g�sterece�i i�in ��kt�m "9"
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer 1 artt��� i�in ��kt�m "62FE08"

	printf("*ptr--'nin degeri= %d\n", *ptr--);			//ptr pointer'�n�n anl�k g�sterdi�i son de�er 9 idi, o y�zden ��kt�m "9", en son da pointer 1 azalacak
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer 1 azald��� i�in ��kt�m "62FE04"

	printf("*--ptr'nin degeri= %d\n", *--ptr);			//pointer (g�sterdi�i de�er DE��L) 1 defa daha azalaca��ndan 2 �nceki index'teki eleman� g�sterecek, o da 13, ��kt�m "13"
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer 1 azalaca��ndan ��kt�m "62FE00"

	printf("--*ptr'nin degeri= %d\n", --*ptr);			//pointer'�n g�sterdi�i de�er 1 azalaca��ndan ��kt�m "12"
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer de�i�medi�i i�in ��kt�m "62FE00"
}

int main() {
	int yarram[]={13,4,9,-5,45};
	printf("yarram[3]= %d\n",yarram[3]);	//��kt�m "-5"
	printf("3[yarram]= %d",3[yarram]);		//��kt�m yine "-5"
}											//yarram zaten bu dizinin ilk eleman�n� g�steren bir pointer bunu biliyoruz   o y�zden yarram[3]=*(yarram+3)=3[yarram]

   g�stericiler ve fonksiyonlar aras�nda da bir ili�ki kurulabilir

void f1(int n) {		//call by value: de�er ge�erek aktar�m , de�er yoluyla arg�man ge�irme
	n=77;
	printf("x'in f1 fonksiyonu icindeki degeri: %d\n",n);		//"77"
}
void f2(int *n) {		//call by reference: adres ge�erek aktar�m , referans yoluyla arg�man ge�irme
	*n=45;
	printf("x'in f2 fonksiyonu icindeki degeri: %d\n",*n);		//"45"
}
int main() {
	int x=114;
	printf("x'in ilk degeri: %d\n",x);							//"114"
	f1(x);														//"77"
	printf("x'in f1 cagrildiktan sonraki degeri: %d\n",x);		//f1 fonksiyonunda de�er ge�erek aktar�m yapt���m halde return komutu kullanmad���m i�in geri de�er d�nd�rm�yor, o y�zden ��kt�m "114"
	f2(&x);														//"45"
	printf("x'in f2 cagrildiktan sonraki degeri: %d",x);		//f2 fonksiyonunda return komutu olmamas�na kar��n adres ge�erek aktar�m yapt���m i�in ��kt�m "45"
	return 0;
}

   hadi "call by value" ve "call by reference"� bir de ge�en ders g�rd���m�z struct'lar ile yapal�m

typedef struct {
	double reel;
	double imaj;
} Complex;
void toplagel(Complex c1, Complex c2, Complex *sonuc) {
	sonuc->reel=c1.reel+c2.reel;		//g�sterici bildirimi struct'larda "nesne_adi->ozellik" bi�iminde "." yerine "->" i�areti ile yap�l�r
	sonuc->imaj=c1.imaj+c2.imaj;
}
int main() {
	Complex c1,c2,sonuc;
	printf("Birinci sayi icin:\n1) Reel kismi giriniz: ");
	scanf("%lf",&c1.reel);
	printf("2) Sanal kismi giriniz: ");
	scanf("%lf",&c1.imaj);
	printf("\nIkinci sayi icin:\n1) Reel kismi giriniz: ");
	scanf("%lf",&c2.reel);
	printf("2) Sanal kismi giriniz: ");
	scanf("%lf",&c2.imaj);
	toplagel(c1,c2,&sonuc);
	printf("\nSonuc:\n1) Reel kisim: %.4f\n2) Sanal kisim: %.4f",sonuc.reel,sonuc.imaj);
	return 0;
}

   son olarak nested structure'larda struct pointer'� olu�turup bu struct'� call by reference ile bir fonksiyonda kullanarak konuyu (�imdilik) kapatal�m */

struct Adres {
	char sehir[20];
	char semt[20];
	int kapiNo;
};
struct Employee {
	int id;
	int maas;
	char isim[30];
	char departman[30];
	struct Adres* adresim;
};
void showInfo(struct Employee* emp) {
	printf("***** %s *****\nID: %d\nMaas: %d TL\nDepartman: %s\nSehir: %s\nSemt: %s\nKapi No: %d\n\n", emp->isim, emp->id, emp->maas, emp->departman, emp->adresim->sehir, emp->adresim->semt, emp->adresim->kapiNo);
}
int main() {
	//1. metot
	struct Employee Cenkay;
	Cenkay.id=31;
	Cenkay.maas=3000;
	strcpy(Cenkay.isim,"Cenkay Kafali");
	strcpy(Cenkay.departman,"bos isler muduru");

	struct Adres CenkayinAdresi={"Istanbul","Bebek",13};
	Cenkay.adresim=&CenkayinAdresi;

	struct Employee* ptr=&Cenkay;

	showInfo(ptr);


	//2. metot
	struct Employee Mustafa={69,4000,"Mustafa Cihan","Bilisim",(struct Adres[]){{"Trabzon","Boztepe",4}}};
															 //(struct Adres[]){"Trabzon","Boztepe",4} �eklinde tek s�sl� parantez kullan�nca warning veriyor
	showInfo(&Mustafa);

	exit(0);
}
