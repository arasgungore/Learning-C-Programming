#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* "function: fonksiyon"			"void: boþluk"			"return: geri döndürme"
   programlamadaki fonksiyonlar matematiksel anlamdaki fonksiyonlardan farksýz olup týpký matematiksel fonksiyonlarda olduðu gibi en önemli özelliði girdi (parametre) almasýdýr
   fonksiyonlar standart kütüphane (built-in) fonksiyonlarý (printf(), scanf(), gets(), puts(), ceil(), floor(), strlen(), strcpy() vs.) ve kullanýcý tanýmlý fonksiyonlar olmak üzere 2'ye ayrýlýr
   standart kütüphane fonksiyonlarýný az çok bildiðimiz için bugün kullanýcý tanýmlý fonksiyonlar ile ilgileneceðiz
   kullanýcý tanýmlý fonksiyonlar da kendi arasýnda geri deðer döndüren ve geri deðer döndürmeyen olmak üzere 2'ye ayrýlýr
   geri deðer döndürmeyen fonksiyonlar için void fonksiyon_adý aç parantez deðiþkentürü deðer1 virgül deðiþkentürü deðer2 kapa parantez aç süslü parantez kapa süslü parantez
   yani void fonksiyon_adi(degiskenturu deger1,degiskenturu deger2) {
   		}																		syntax'ý kullanýlýr
   týpký enum ve struct'ta olduðu gibi kullanýcý tanýmlý fonksiyonlar main() fonksiyonunun dýþýna yazýlýr, yalnýz ; ile bitmez!!
   deðer 1 ve deðer 2'ye atanacak deðerler main() fonksiyonunun (asýl kodumuzun) içinde fonksiyon_adi(deger1,deger2) biçiminde ifade edilir

void listele() {										void dortgen(int yatay,int dikey) {
	printf("Ozkan Cetinay\n");								int i,j;
	printf("Beyza Baskin\n");								for(i=1;i<=dikey;i++) {
	printf("Haktan Ozturkcu\n");								for(j=1;j<=yatay;j++) {
	printf("Kerem Aydin\n");									printf("*");
	printf("Bilge Tosun");										}
}																printf("\n");
															}
int main() {											}
														int main() {
	listele();												dortgen(2,3);
}															printf("\n");
															dortgen(4,10);
														}

   geri deðer döndüren fonksiyonlar için ise deðiþkentürü fonksiyon_adý aç parantez deðiþkentürü deðer1 virgül deðiþkentürü deðer2 kapa parantez aç süslü parantez return sonuc kapa süslü parantez
   yani degiskenturu fonksiyon_adi(degiskenturu deger1,degiskenturu deger2) {
   		return sonuc;
   		}																			syntax'ý kullanýlýr
   void yapýsýndan farký bu fonksiyonlar hesaplanan sonucu kullanýcýya geri döndürür
   ve kullanýcýya döndürdüðü deðerin veri tipi (deðiþken türü) fonksiyonun baþýna yazýlýr   (int döndürüyorsa int fonk(), char döndürüyorsa char fonk(), double array'i döndürüyorsa double* fonk() gibi)

double kupbul(double x) {								double ortbul(double a,double b,double c,double d,double e) {
	double y;												double ort=(a+b+c+d+e)/5;
	y=x*x*x;												return ort;
	return y;											}
}
														int main() {
int main() {												printf("%lf",ort(23.12,54.3,89.22,7,3.1459));
	double sayi;											printf("%.4f",ortbul(2.2,3.7,999,1,31.69));
	printf("Sayi Giriniz: ");							}
	scanf("%lf",&sayi);
	printf("\nSayinin Kupu: %lf",kupbul(sayi));
}


int sorgula(int x) {
	if(x%2==0)
	return 31;

	else
	return 69;
}
int main() {
	int sayi;
	printf("Sayi Girin: ");
	scanf("%d",&sayi);
	if(sorgula(sayi)==31)
	printf("\nBu sayi cifttir");
	else							//if(sorgula(sayi)==69) demek ile ayný
	printf("\nBu sayi tektir");		//eðer if,else,for,while yapýlarýnýn altýna sadece bir satýr yazacaksam scope kullanmama gerek yok
}


long long faktoriyel(int a) {								void usalma(int taban,int kuvvet) {								int asalsorgulama(int sayi) {
	int i; long long carpim=1;									int i,sonuc=1;													int i;
	for(i=1;i<=a;i++)											for(i=1;i<=kuvvet;i++)											for(i=2;i<=sqrt(sayi);i++) {
		carpim=carpim*i;											sonuc=sonuc*taban;												if(sayi%i==0)
	return carpim;												printf("pow(%d,%d)=%d",taban,kuvvet,sonuc);								return 0;
}															}																	}			//asal olmayan bir sayýnýn karekökü kendisini oluþturan en küçük asal sayýdan büyüktür
long long permutasyon(int n,int r) {						int main() {														return 1;	//sayýnýn kendisi yerine sayýnýn kareköküne kadar olan i deðerlerine bakarak kodu daha verimli yapýyorum
	long long perm=faktoriyel(n)/faktoriyel(n-r);				int x,y;													}				//týpký bir sayýnýn tam sayý bölenlere bakarken sayýnýn yarýsýna kadar olan i deðerlerini taramamýz gibi
	return perm;												printf("Taban giriniz: ");									int main() {
}																scanf("%d",&x);													int x;
long long kombinasyon(int n,int r) {							printf("Kuvvet giriniz: ");										printf("Asal mi degil mi: ");
	long long comb=permutasyon(n,r)/faktoriyel(r);				scanf("%d",&y);													scanf("%d",&x);			//while, if gibi yapýlarda parantez içindeki yargý "true" olduðu sürece
	return comb;												usalma(x,y);													if(asalsorgulama(x))	//scope içindeki kodu bilgisayar okur, "false" ise scope içi yok sayýlýp okunmaz
}															}																		printf("Asal");		//0: false, 1: true demek olduðu için if(asalsorgulama(x)==1) demek ile ayný
int main() {																													else
	printf("3!=%lld\n",faktoriyel(3));																								printf("Asal degil");
	printf("6!=%lld\n",faktoriyel(6));																						}
	printf("20!=%lld\n",faktoriyel(20));   //mesela 20! int (32 bit) yerine long (64 bit) kullanýlmadan yazdýrýlamazdý, yoksa overflow olurdu  ( 2^63-1 > 20! >> 2^31-1 )
	printf("C(5,2)=%lld\n",kombinasyon(5,2));
	printf("C(8,4)=%lld\n",kombinasyon(8,4));	//zaten biz long long (128 bit) kullandýðýmýz için 2^127-1'den küçük her sayý doðru bir þekilde hesaplanacak :))
	printf("P(6,4)=%lld\n",permutasyon(6,4));
	printf("P(10,3)=%lld\n",permutasyon(10,3));
}


int sorucevap(char *tahmin) {
	char *cevap="Hatay";
	if(strcmp(tahmin,cevap)==0) {	//strcmp fonksiyonu 0 döndürüyorsa tahmin doðrudur
		printf("Dogru cevap :)");
		return 0;		//tahmin doðru ise 0: false döndürecek ve while döngüsünden çýkacak
	}
	else				//tahmin yanlýþ ise 1: true döndürecek ve while döngüsünde olacaðýz
		return 1;
}
int main() {
	char string[50];
	int sayac=5;
	printf("Turkiye'nin en guneydeki ili hangisidir?: ");
	scanf("%s",string);												//while'ýn içindeki iki koþul yargýsý da true (1) olduðu sürece scope içindeki döngü devam edecek
	while(sorucevap(string) && sayac!=1) {							//sayac'ý yanlýþ tahminde bulunduktan sonra 1 azaltmadýðým için þuan olmasý gerekenden 1 fazla
		printf("Yanlis cevap, %d deneme hakkiniz kaldi: ",--sayac);	//o yüzden while(... && sayac!=1) {...} yerine sayac--; while(... && sayac!=0) {...} da yazýlabilir
		scanf("%s",string);											//bir de while'a 1. koþul olarak içine fonksiyonun kendisini yazarak aslýnda "recursion" yapmýþ oldum
	}
}


void swap(int *dizi_adi,int a,int b) {						int toplam(int s1,int s2) {
	int gecici=dizi_adi[a];										int s3;
	dizi_adi[a]=dizi_adi[b];									s3=s1+s2;
	dizi_adi[b]=gecici;											return s3;
}															}
void reverse(int *dizi_adi,int a,int b) {					char* birlestir(char *k1,char *k2) {	//stringler "char*" kalýbýyla ifade ediliyordu, hatýrlayýn
	while(a<b) {												char *k3="";	//NULL yani
		swap(dizi_adi,a,b);										k3=(char*) calloc(k3,strlen(k1)+strlen(k2)+1);
		a++;													strcat(k3,k1);
		b--;													strcat(k3," ");
	}															strcat(k3,k2);
}																return k3;
int main() {												}
	int i,rakamlar[10]={2,5,3,7,0,8,1,6,4,9};				int main() {
	printf("Dizim: ");											printf("%d\n",toplam(2,3));
	for(i=0;i<10;i++)											printf("%d\n",toplam(24,9));
		printf("%d ",rakamlar[i]);								printf("%s\n",birlestir("esek","sipasi"));
	reverse(rakamlar,0,9);										printf("%s\n",birlestir("Amini sikeyim","Cenkay"));
	printf("\nDizimin tersi: ");								printf("%s",birlestir( birlestir( "string","ogrenmek") , birlestir("cok","eglenceli") ));
	for(i=0;i<10;i++)										}
		printf("%d ",rakamlar[i]);
}

   fonksiyon pointer'ý diye bir þey de var, kýsa bir örnek verip geçeyim

int x=5;		//ilk deðeri 5 olan x global bir deðiþken
int* f() {
	return &x;	//x'in adresini döndüren bir fonksiyon
}
int main() {
	*f()=10;	//*(&x)=x=10 oldu þuan
	printf("x'in degeri: %d",x);
}

   Taylor serisi ile sinüs, kosinüs ve doðal logaritma (ln) hesabý yapalým */

int f(int a) {
	int i,factor=1;
	for(i=a;i>1;i--)
		factor*=i;
	return factor;
}
double taylorsin(double x) {
	int i;
	double toplamsin=0;
	for(i=0;i<=6;i++)
		toplamsin+=pow(-1,i)*pow(x,2*i+1)/f(2*i+1);
	return toplamsin;
}
double taylorcos(double x) {
	int i;
	double toplamcos=0;
	for(i=0;i<=6;i++)
		toplamcos+=pow(-1,i)*pow(x,2*i)/f(2*i);
	return toplamcos;
}
double taylorln(double x) {
	int i;
	double toplamln=0;
	for(i=1;i<=8;i++)
		toplamln+=pow(-1,i+1)*pow(x,i)/i;
	return toplamln;
}
int main() {
	double radyan,sayi;
	printf("Aci Giriniz (Radyan): ");
	scanf("%lf",&radyan);
	printf("taylorsin(%lf)=%lf\n",radyan,taylorsin(radyan));
	printf("sin(%lf)=%lf\n",radyan,sin(radyan));
	printf("taylorcos(%lf)=%lf\n",radyan,taylorcos(radyan));
	printf("cos(%lf)=%lf\n\n",radyan,cos(radyan));
	printf("Sayi Giriniz: ");
	yo:
	scanf("%lf",&sayi);
	if(sayi<=0 || sayi>=2) {
		printf("Lutfen 0 ila 2 Arasi Giriniz: ");
		goto yo;
	}
	printf("taylorln(%lf)=%lf\n",sayi,taylorln(sayi-1));
	printf("ln(%lf)=%lf",sayi,log(sayi));
	return 0;
}
