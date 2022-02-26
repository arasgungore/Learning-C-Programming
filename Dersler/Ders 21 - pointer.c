#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* "pointer: gösterici"
   programlamada bellekte (RAM'de) saklanan verilerin hafýza alanýný göstermek için kullanýlan veri tipine "pointer" (gösterici) denir
   RAM (Random Access Memory, Rastgele Eriþimli Bellek) bilgilerin geçici olarak saklandýðý bir bellek türüdür ve bu bilgisayar için 16 GB=16*1024*1024*1024=2^34=17179869184 adet byte'dan (gözden) oluþur
   1 göz=1 byte=8 bit olduðunu da bildiðimize göre misal "int tam=33" verisini ele alalým
   int deðiþkeni 4 byte'lýk bir veri tipi olduðu için ona bellekte 4 byte'lýk bir hücre ayrýlýr
   bu hücreye 33 sayýsýnýn binary'deki karþýlýðý olan 4 byte'lýk (32 bit'lik) "00000000 00000000 00000000 00100001" sayýsý hücrenin 67108117-67108120 numaralý gözleri iþgal ettiðini varsayarsak belleðe þöyle yazýlýr:
   Bellek gözleri (1 byte):		........	........	00000000	00000000	00000000	00100001	........	........	........	........	........
   Adres (hexadecimal):			0x3fffd12	0x3fffd13	0x3fffd14	0x3fffd14	0x3fffd15	0x3fffd16	0x3fffd17	0x3fffd18	0x3fffd19	0x3fffd1a	0x3fffd1b
   Adres (decimal):				67108115	67108116	67108117	67108118	67108119	67108120	67108121	67108122	67108123	67108124	67108125
   bellek adresleri genellikle on altýlýk (hexadecimal) sayý sistemi ile gösterilir ve "%x: hexadecimal" veya "%p: pointer" belirteçleri ile ifade edilir   (iki belirteç de ayný çýktýyý verir)
   deðiþkenlerin bellek adreslerini yazdýrmak için printf fonksiyonu "&" adres operatörü ile birlikte kullanýlýr

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

   göstericilerin genel syntax'ý deðiþkentürü yýldýz pointeradý eþittir ampersand deðiþkenadý ==> degiskenturu *pointeradi=&degiskenadi
   pointer'lar deðiþkenlerin girildiði adreslerin yerini tutar
   misal 1 byte'lýk "char harf='m'" verisini ele alalým, ve pointer'ýmýzý da "char *p=&harf" diye tanýmlayalým
   m karakterinin ASCII (American Standard Code for Information Interchange) kodu 109 olduðu için bunun binary'deki karþýlýðý olan "01101101" sayýsý bellekteki bir göze kaydedilir
   char harf='m' verisi için 5490238 numaralý gözü, char *p=&harf verisinin de 5490241 numaralý gözü iþgal ettiðini varsayarsak bu veriler belleðe þöyle yazýlýr:
   Bellek gözleri (1 byte):		........	........	........	01101101	........	........	5490238		........
   Adres (decimal):				5490235		5490236		5490237		5490238		5490239		5490240		5490241		5490242
   görüldüðü üzere p pointer'ý char harf='m' verisinin saklandýðý adresi hafýzada baþka bir gözün içinde tutar

int main() {
	char soru='?';
	int satan=666;
	char *quiz=&soru;
	int *cehennem=&satan;
	printf("******* Verileri Ekrana Yazdirma *******\n1. Veri: %c\n2. Veri: %d\n\n",soru,satan);
	printf("******* Adresleri Ekrana Yazdirma *******\n1. Adres: %x\n2. Adres: %x",quiz,cehennem);		//bu aþamada &soru ve &satan yazmakla quiz ve cehennem göstericilerini kullanmak ayný þey
}

   pointer'lara yaptýðým iþlemlerle verinin bellekte saklandýðý yeri (adresini) deðiþtirebilirim

int main() {
	char pipi='h';
	int kuku=69;
	char *pt1=&pipi;
	int *pt2=&kuku;
	printf("Adres 1: %x (%d) Adres 2: %x (%d)\n\n",pt1,pt1,pt2,pt2);	//çýktýlarým misal onluk taban sisteminde "100" ve "106" olsun
	pt1++;																//(normalde 7 basamaklý sayýlar, ve RAM'im daha çok iþgal edilseydi 8-12 basamaklý sayýlar dahi olabilirdi)
	pt2++;
	printf("Adres 1: %x (%d) Adres 2: %x (%d)\n\n",pt1,pt1,pt2,pt2);	//yeni çýktýlarým "101" ve "110" olacak
	pt1+=15;															//bunun sebebi char deðiþkeninin 1 byte'lýk, int deðiþkeninin ise 4 byte'lýk bir veri tipi olmasý
	pt2-=6;																//bu yüzden char deðiþkeninin adresi 1 artarken, bellekte 4 byte yer kaplayan int deðiþkeninin adresi haliyle 4 artacak
	printf("Adres 1: %x (%d) Adres 2: %x (%d)\n\n",pt1,pt1,pt2,pt2);	//bu sefer ise çýktýlarým "116" ve "86" olacak
}																		//char pipi='h' verisinin adresi 1*15=15 artarken, int kuku=69 verisinin adresi 4*6=24 azalýr

int main() {
	int a=10;
	int *p,*q;
	p=&a;
	q=&p;
	printf("a'nin degeri: %d\n",a);			//a'nýn deðerini yazdýrýr, yani "10"
	printf("a'nin adresi: %d\n",&a);		//a'nýn adresini yazdýrýr (bunu bilemem)
	printf("a'nin adresi: %d\n",p);			//a'nýn adresini yazdýrýr, çünkü p=&a, yani p pointer'ý a'nýn adres deðerine eþit
	printf("a'nin degeri: %d\n",*p);		//p'nin gittiði yerin deðerini yazdýrýr, ve p pointer'ý a'ya gittiði için a'nýn deðeri olan "10" yazdýrýr
	printf("p'nin adresi: %d\n",&p);		//p'nin adresini yazdýrýr (bunu da bilemem)
	printf("p'nin adresi: %d\n",q);			//p'nin adresini yazdýrýr, çünkü q=&p, yani q pointer'ý p pointer'ýnýn adres deðerine eþit
	printf("a'nin adresi: %d\n",*q);		//q'nun gittiði yerin deðerini yazdýrýr, ve q pointer'ý p'ye gittiði için p pointer'ýnýn deðeri olan a'nýn adresini yazdýrýr
	printf("q'nun adresi: %d\n",&q);		//q'nun adresini yazdýrýr (adresleri bilemem demiþ miydim?)
}											//o zaman p=&a, q=&p iken *p=a, *q=p olur, bu da gösterir ki & ve * operatörleri birbirinin tersi oluyor
											//p=&a: p pointer'ý a'nýn bulunduðu adres deðerine eþittir; *p=a: p pointer'ýnýn tuttuðu adres deðerinde saklanan veri a'ya eþittir

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

   diziler ve göstericiler arasýnda yakýn bir iliþki vardýr, çünkü bir dizinin ADI dizinin ilk elemanýný saklayan bir GÖSTERÝCÝdir
   o yüzden array bir dizi, p bir pointer ve p=array olmak üzere array[i] ile *(p+i) ayný þey demektir, ikisi de dizinin i+1. elemanýný göstermek için kullanýlýr

int main() {
	int kutle[]={1,5,6,9,10,2,8,13},*p,i;
	p=kutle;		//p=&kutle[0] demek ile ayný þey
	for(i=0;i<8;i++) {
		printf("%d ",*(p+i));	//olan olay þu: normalde p pointer'ý kutle dizisinin ilk elemanýnýn saklandýðý yerin adresinin deðerini tutuyor
	}							//mesela ilk elemanýn adresi sallýyorum 9181340 olsaydý 2. elemanýn 9181344, 3. elemanýn 9181348, 4. elemanýn 9181352,..., 8. elemanýn ise 9181368 olurdu
}								//adreslerin 4'er 4'er artmasý olay deðil bu arada, çünkü nasýl p++ olunca bir int deðiþkeninin adresi 4 artarsa, p+i yaptýðýmda da o p pointer'ýnýn tuttuðu adres deðeri 4i kadar artmalý
								//ve dizilerde elemanlarýn ardýþýk adreslerde saklandýðýný da bildiðime göre printf fonksiyonu sýrayla p,p+4,p+8,...,p+28 adres deðerlerinde saklanan verileri
								//yani bu dizinin elemanlarýný bana sýrasýyla yazdýracak ve çýktým "1 5 6 9 10 2 8 13" olacak

   demek ki neymiþ: *(array+i)=array[i], array+i=&array[i]

int main() {
	int tamsayi[]={23,56,99,4,1337},i;
	float ondalik[]={1.2,3.6,7.7,6.7};
	char string[3][8]={"Ahmet","Mustafa","Coskun"};

	printf("***tamsayi array'i icin***\n");
	for(i=0;i<5;i++)
		printf("%d. index'teki elemanin adresi: %x  |  %d\n",i,tamsayi+i,tamsayi+i);
	for(i=0;i<5;i++)	//adresler 4'er 4'er artýyor (sizeof(int)=4)
		printf("%d. index'teki elemanin degeri: %d\n",i,*(tamsayi+i));

	printf("\n\n***ondalik array'i icin***\n");
	for(i=0;i<4;i++)
		printf("%d. index'teki elemanin adresi: %x  |  %d\n",i,ondalik+i,ondalik+i);
	for(i=0;i<4;i++)	//adresler 4'er 4'er artýyor (sizeof(float)=4)
		printf("%d. index'teki elemanin degeri: %.1f\n",i,*(ondalik+i));

	printf("\n\n***string array'i icin***\n");
	for(i=0;i<3;i++)
		printf("%d. index'teki elemanin adresi: %x  |  %d\n",i,string+i,string+i);
	for(i=0;i<3;i++)	//adresler 8'er 8'er artýyor (sizeof(*string)=8)
		printf("%d. index'teki elemanin degeri: %s\n",i,*(string+i));
}

int main() {
	int dizi[]={13,4,9,-5,45};
	int *ptr;
	ptr=&dizi[0]; //ptr=dizi demek ile ayný þey

	printf("Dizim: {13, 4, 9, -5, 45}\n");
	printf("Index:   0, 1, 2,  3,  4\n\n");

	printf("*ptr'nin degeri= %d\n", *ptr);				//ptr dizinin ilk elemanýný gösterdiði için çýktým "13"
	printf("ptr'nin adresi= %p\n\n", ptr);				//diyelim "62FE00" olsun ptr pointer'ýnýn adresi

	printf("*(ptr++)'nin degeri= %d\n", *(ptr++));		//ptr pointer'ýnýn o anlýk gösterdiði deðer yine 13 olduðundan çýktým "13" olacak ve en son da pointer 1 artacak
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer 1 arttýðý (int olduðu için adres 4 artacak) için çýktým "62FE04"

	printf("(*ptr)++'nin degeri= %d\n", (*ptr)++);		//ptr pointer'ý 1 arttýðý için bir sonraki index'teki eleman olan 4'u gösterecek, çýktým "4", ve en son da pointer'ýn GÖSTERDÝÐÝ DEÐER 1 artacak
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer artmadýðý için çýktým "62FE04"

	printf("++*ptr'nin degeri= %d\n", ++*ptr);			//ptr pointer'ýnýn gösterdiði deðer 1 artacak ve pointer'ýn gösterdiði son deðer 4+1+1=6 olduðundan çýktým "6"
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer hala ayný adresi tutuyor, çýktým "62FE04"

	printf("*++ptr'nin degeri= %d\n", *++ptr);			//ptr pointer'ý bir artacak, dolayýsýyla bir sonraki index'teki elemaný göstereceði için çýktým "9"
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer 1 arttýðý için çýktým "62FE08"

	printf("*ptr--'nin degeri= %d\n", *ptr--);			//ptr pointer'ýnýn anlýk gösterdiði son deðer 9 idi, o yüzden çýktým "9", en son da pointer 1 azalacak
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer 1 azaldýðý için çýktým "62FE04"

	printf("*--ptr'nin degeri= %d\n", *--ptr);			//pointer (gösterdiði deðer DEÐÝL) 1 defa daha azalacaðýndan 2 önceki index'teki elemaný gösterecek, o da 13, çýktým "13"
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer 1 azalacaðýndan çýktým "62FE00"

	printf("--*ptr'nin degeri= %d\n", --*ptr);			//pointer'ýn gösterdiði deðer 1 azalacaðýndan çýktým "12"
	printf("ptr'nin adresi= %p\n\n", ptr);				//pointer deðiþmediði için çýktým "62FE00"
}

int main() {
	int yarram[]={13,4,9,-5,45};
	printf("yarram[3]= %d\n",yarram[3]);	//çýktým "-5"
	printf("3[yarram]= %d",3[yarram]);		//çýktým yine "-5"
}											//yarram zaten bu dizinin ilk elemanýný gösteren bir pointer bunu biliyoruz   o yüzden yarram[3]=*(yarram+3)=3[yarram]

   göstericiler ve fonksiyonlar arasýnda da bir iliþki kurulabilir

void f1(int n) {		//call by value: deðer geçerek aktarým , deðer yoluyla argüman geçirme
	n=77;
	printf("x'in f1 fonksiyonu icindeki degeri: %d\n",n);		//"77"
}
void f2(int *n) {		//call by reference: adres geçerek aktarým , referans yoluyla argüman geçirme
	*n=45;
	printf("x'in f2 fonksiyonu icindeki degeri: %d\n",*n);		//"45"
}
int main() {
	int x=114;
	printf("x'in ilk degeri: %d\n",x);							//"114"
	f1(x);														//"77"
	printf("x'in f1 cagrildiktan sonraki degeri: %d\n",x);		//f1 fonksiyonunda deðer geçerek aktarým yaptýðým halde return komutu kullanmadýðým için geri deðer döndürmüyor, o yüzden çýktým "114"
	f2(&x);														//"45"
	printf("x'in f2 cagrildiktan sonraki degeri: %d",x);		//f2 fonksiyonunda return komutu olmamasýna karþýn adres geçerek aktarým yaptýðým için çýktým "45"
	return 0;
}

   hadi "call by value" ve "call by reference"ý bir de geçen ders gördüðümüz struct'lar ile yapalým

typedef struct {
	double reel;
	double imaj;
} Complex;
void toplagel(Complex c1, Complex c2, Complex *sonuc) {
	sonuc->reel=c1.reel+c2.reel;		//gösterici bildirimi struct'larda "nesne_adi->ozellik" biçiminde "." yerine "->" iþareti ile yapýlýr
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

   son olarak nested structure'larda struct pointer'ý oluþturup bu struct'ý call by reference ile bir fonksiyonda kullanarak konuyu (þimdilik) kapatalým */

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
															 //(struct Adres[]){"Trabzon","Boztepe",4} þeklinde tek süslü parantez kullanýnca warning veriyor
	showInfo(&Mustafa);

	exit(0);
}
