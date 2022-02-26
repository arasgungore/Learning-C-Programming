#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* "function: fonksiyon"			"void: bo�luk"			"return: geri d�nd�rme"
   programlamadaki fonksiyonlar matematiksel anlamdaki fonksiyonlardan farks�z olup t�pk� matematiksel fonksiyonlarda oldu�u gibi en �nemli �zelli�i girdi (parametre) almas�d�r
   fonksiyonlar standart k�t�phane (built-in) fonksiyonlar� (printf(), scanf(), gets(), puts(), ceil(), floor(), strlen(), strcpy() vs.) ve kullan�c� tan�ml� fonksiyonlar olmak �zere 2'ye ayr�l�r
   standart k�t�phane fonksiyonlar�n� az �ok bildi�imiz i�in bug�n kullan�c� tan�ml� fonksiyonlar ile ilgilenece�iz
   kullan�c� tan�ml� fonksiyonlar da kendi aras�nda geri de�er d�nd�ren ve geri de�er d�nd�rmeyen olmak �zere 2'ye ayr�l�r
   geri de�er d�nd�rmeyen fonksiyonlar i�in void fonksiyon_ad� a� parantez de�i�kent�r� de�er1 virg�l de�i�kent�r� de�er2 kapa parantez a� s�sl� parantez kapa s�sl� parantez
   yani void fonksiyon_adi(degiskenturu deger1,degiskenturu deger2) {
   		}																		syntax'� kullan�l�r
   t�pk� enum ve struct'ta oldu�u gibi kullan�c� tan�ml� fonksiyonlar main() fonksiyonunun d���na yaz�l�r, yaln�z ; ile bitmez!!
   de�er 1 ve de�er 2'ye atanacak de�erler main() fonksiyonunun (as�l kodumuzun) i�inde fonksiyon_adi(deger1,deger2) bi�iminde ifade edilir

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

   geri de�er d�nd�ren fonksiyonlar i�in ise de�i�kent�r� fonksiyon_ad� a� parantez de�i�kent�r� de�er1 virg�l de�i�kent�r� de�er2 kapa parantez a� s�sl� parantez return sonuc kapa s�sl� parantez
   yani degiskenturu fonksiyon_adi(degiskenturu deger1,degiskenturu deger2) {
   		return sonuc;
   		}																			syntax'� kullan�l�r
   void yap�s�ndan fark� bu fonksiyonlar hesaplanan sonucu kullan�c�ya geri d�nd�r�r
   ve kullan�c�ya d�nd�rd��� de�erin veri tipi (de�i�ken t�r�) fonksiyonun ba��na yaz�l�r   (int d�nd�r�yorsa int fonk(), char d�nd�r�yorsa char fonk(), double array'i d�nd�r�yorsa double* fonk() gibi)

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
	else							//if(sorgula(sayi)==69) demek ile ayn�
	printf("\nBu sayi tektir");		//e�er if,else,for,while yap�lar�n�n alt�na sadece bir sat�r yazacaksam scope kullanmama gerek yok
}


long long faktoriyel(int a) {								void usalma(int taban,int kuvvet) {								int asalsorgulama(int sayi) {
	int i; long long carpim=1;									int i,sonuc=1;													int i;
	for(i=1;i<=a;i++)											for(i=1;i<=kuvvet;i++)											for(i=2;i<=sqrt(sayi);i++) {
		carpim=carpim*i;											sonuc=sonuc*taban;												if(sayi%i==0)
	return carpim;												printf("pow(%d,%d)=%d",taban,kuvvet,sonuc);								return 0;
}															}																	}			//asal olmayan bir say�n�n karek�k� kendisini olu�turan en k���k asal say�dan b�y�kt�r
long long permutasyon(int n,int r) {						int main() {														return 1;	//say�n�n kendisi yerine say�n�n karek�k�ne kadar olan i de�erlerine bakarak kodu daha verimli yap�yorum
	long long perm=faktoriyel(n)/faktoriyel(n-r);				int x,y;													}				//t�pk� bir say�n�n tam say� b�lenlere bakarken say�n�n yar�s�na kadar olan i de�erlerini taramam�z gibi
	return perm;												printf("Taban giriniz: ");									int main() {
}																scanf("%d",&x);													int x;
long long kombinasyon(int n,int r) {							printf("Kuvvet giriniz: ");										printf("Asal mi degil mi: ");
	long long comb=permutasyon(n,r)/faktoriyel(r);				scanf("%d",&y);													scanf("%d",&x);			//while, if gibi yap�larda parantez i�indeki yarg� "true" oldu�u s�rece
	return comb;												usalma(x,y);													if(asalsorgulama(x))	//scope i�indeki kodu bilgisayar okur, "false" ise scope i�i yok say�l�p okunmaz
}															}																		printf("Asal");		//0: false, 1: true demek oldu�u i�in if(asalsorgulama(x)==1) demek ile ayn�
int main() {																													else
	printf("3!=%lld\n",faktoriyel(3));																								printf("Asal degil");
	printf("6!=%lld\n",faktoriyel(6));																						}
	printf("20!=%lld\n",faktoriyel(20));   //mesela 20! int (32 bit) yerine long (64 bit) kullan�lmadan yazd�r�lamazd�, yoksa overflow olurdu  ( 2^63-1 > 20! >> 2^31-1 )
	printf("C(5,2)=%lld\n",kombinasyon(5,2));
	printf("C(8,4)=%lld\n",kombinasyon(8,4));	//zaten biz long long (128 bit) kulland���m�z i�in 2^127-1'den k���k her say� do�ru bir �ekilde hesaplanacak :))
	printf("P(6,4)=%lld\n",permutasyon(6,4));
	printf("P(10,3)=%lld\n",permutasyon(10,3));
}


int sorucevap(char *tahmin) {
	char *cevap="Hatay";
	if(strcmp(tahmin,cevap)==0) {	//strcmp fonksiyonu 0 d�nd�r�yorsa tahmin do�rudur
		printf("Dogru cevap :)");
		return 0;		//tahmin do�ru ise 0: false d�nd�recek ve while d�ng�s�nden ��kacak
	}
	else				//tahmin yanl�� ise 1: true d�nd�recek ve while d�ng�s�nde olaca��z
		return 1;
}
int main() {
	char string[50];
	int sayac=5;
	printf("Turkiye'nin en guneydeki ili hangisidir?: ");
	scanf("%s",string);												//while'�n i�indeki iki ko�ul yarg�s� da true (1) oldu�u s�rece scope i�indeki d�ng� devam edecek
	while(sorucevap(string) && sayac!=1) {							//sayac'� yanl�� tahminde bulunduktan sonra 1 azaltmad���m i�in �uan olmas� gerekenden 1 fazla
		printf("Yanlis cevap, %d deneme hakkiniz kaldi: ",--sayac);	//o y�zden while(... && sayac!=1) {...} yerine sayac--; while(... && sayac!=0) {...} da yaz�labilir
		scanf("%s",string);											//bir de while'a 1. ko�ul olarak i�ine fonksiyonun kendisini yazarak asl�nda "recursion" yapm�� oldum
	}
}


void swap(int *dizi_adi,int a,int b) {						int toplam(int s1,int s2) {
	int gecici=dizi_adi[a];										int s3;
	dizi_adi[a]=dizi_adi[b];									s3=s1+s2;
	dizi_adi[b]=gecici;											return s3;
}															}
void reverse(int *dizi_adi,int a,int b) {					char* birlestir(char *k1,char *k2) {	//stringler "char*" kal�b�yla ifade ediliyordu, hat�rlay�n
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

   fonksiyon pointer'� diye bir �ey de var, k�sa bir �rnek verip ge�eyim

int x=5;		//ilk de�eri 5 olan x global bir de�i�ken
int* f() {
	return &x;	//x'in adresini d�nd�ren bir fonksiyon
}
int main() {
	*f()=10;	//*(&x)=x=10 oldu �uan
	printf("x'in degeri: %d",x);
}

   Taylor serisi ile sin�s, kosin�s ve do�al logaritma (ln) hesab� yapal�m */

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
