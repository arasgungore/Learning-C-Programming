#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* "recursion: �z yineleme"     "recursive: �z yineli , kendi kendini yineleyen"
   kendi kendini �a��ran fonksiyonlara recursive (�z yineli) denir
   �o�unlukla d�ng�lerle (for,while) ��z�lebilen problemler (fakt�riyel,�s alma,desen �izme) recursive fonksiyonlar ile �ok daha kolay ��z�lebilir

   fakt�riyel ile ba�layal�m																													1'den (klavyeden girilen) n'e kadar say�lar� toplayal�m

int fact(int a) {																																int sayac=1,toplam=0;	//global de�i�kenler
	if(a<0)																																		void toplagel(int x) {
		printf("\nHatali giris!");																													toplam+=sayac;		//int de�i�kenlerini fonksiyon i�ine de�il en ba�a yazarak
	else if(a==0)																																	sayac++;			//say�lar�n eski de�erlerine resetlenmesini �nl�yorum
		return 1;																																	if(sayac<=x)
	else																																				toplagel(x);
		return a*fact(a-1);																															else
}	//4 girseydim mesela ��kt�m fact(4)=sonuc=4*fact(3)=4*3*fact(2)=4*3*2*fact(1)=4*3*2*1*fact(0)=4*3*2*1*1="24" olurdu									printf("Toplam: %d",toplam);
	//0'dan k���k say�lar i�in fonksiyon tan�ml� bir say� d�nd�rmedi�i i�in bu fonksiyonun taban par�as� fact(0) oldu							}
int main() {																																	int main() {
	int sayi;																																		int n;
	printf("Sayi girin: ");																															printf("Sayi girin: ");
	scanf("%d",&sayi);																																scanf("%d",&n);
	if(sayi>=0)																																		toplagel(n);
		printf("\nFaktoriyel: %d",fact(sayi));																									}
	else
		fact(sayi);
}

   Fibonacci yapmayal� uzun zaman oldu																											2 pozitif tam say�y� �arpma operat�r�n� (*) kullanmadan �arpal�m

int Fibonacci(int n) {																															int carp(int a,int b) {
	if(n==0)																																		int carpim=0,i=1;
		return 0;		//Fibonacci(0)=0	Fibonacci(1)=1 haz�r girili																				while(i<=a) {
	else if(n==1)		//Fibonacci(2)=Fibonacci(1)+Fibonacci(0)=1+0=1	Fibonacci(3)=Fibonacci(2)+Fibonacci(1)=1+1=2									carpim+=b;
		return 1;		//Fibonacci(4)=Fibonacci(3)+Fibonacci(2)=2+1=3	Fibonacci(5)=Fibonacci(4)+Fibonacci(3)=3+2=5...									i++;
	else		//main i�indeki for d�ng�s� n=0 (ve negatif say�lar) i�in zaten �al��mayaca��ndan zaten 0. terim olan 0 yazd�r�lmayacak				}
		return (Fibonacci(n-1)+Fibonacci(n-2));																										return carpim;
}																																				}
int main() {																																	int main() {
	int i,n;																																		int a,b;
	printf("Terim sayisi: ");																														printf("Iki pozitif tam sayi giriniz: ");
	scanf("%d",&n);																																	scanf("%d%d",&a,&b);
	printf("\nFibonacci sayilari\n");																												if(a<0 || b<0) {
	for(i=1;i<=n;i++)																																	while(a<0 || b<0) {
		printf("%d\n",Fibonacci(i));																														printf("Hatali giris, lutfen tekrar giriniz: ");
}																																							scanf("%d%d",&a,&b);
																																						}
																																					}
																																					printf("Carpim: %d",carp(a,b));
																																				}

   ekok (en k���k ortak kat), ebob (en b�y�k ortak b�len) yapal�m

int sayac=1;																																	int ebobbul(int x,int y) {
int ekokbul(int a,int b) {																															while(x!=y) {		//b�y�k olan say�dan k���k olan� ��kar�nca 2 say�n�n
	if(sayac%a==0 && sayac%b==0)																														if(x>y)			//ebob'u de�i�medi�inden b�y�kten k����� ��kara ��kara
		return sayac;																																		return ebobbul(x-y,y);		//en son x=y=ebob bulunur
	sayac++;			//a ve b say�lar�n�n ekok'u matematiksel anlamda hem (mod a) hem (mod b)'de 0'a e�it olan en k���k say�d�r						else			//if(y<x) ile ayn� �ey
	ekokbul(a,b);		//bu ko�ul sa�lanmad��� s�rece fonksiyon s�rekli kendini �a��racak ve saya� birer birer artacak										return ebobbul(x,y-x);		//x=y iken while d�ng�s� biter ve
}																																					}									//fonksiyon ebob olan x say�s�n� d�nd�r�r
int main() {																																		return x;
	int a,b;																																	}
	printf("Iki pozitif tam sayi giriniz: ");																									int main() {
	scanf("%d%d",&a,&b);																															int x,y;
	printf("EKOK: %d",ekokbul(a,b));																												printf("Iki pozitif tam sayi giriniz: ");
}																																					scanf("%d%d",&x,&y);
																																					printf("EBOB: %d",ebobbul(x,y));
																																				}
   i�leri zorla�t�ral�m, Hanoi kuleleri bulmacas�n� (klavyeden girilen) n tane disk i�in ��zelim

void HanoiKuleleri(char kaynak, char gecici, char hedef, int n) {																				int ebobbulv2(int a,int b,int sayac) {
	if(n==0)																																		if(a%sayac==0 && b%sayac==0)
		return;			//return komutu okununca fonksiyon bitecek																						return sayac;
	HanoiKuleleri(kaynak, hedef, gecici, n-1);																										sayac--;
	printf("\nUstten %d. disk (%c -> %c)", n, kaynak, hedef);																						ebobbulv2(a,b,sayac);
	HanoiKuleleri(gecici, kaynak, hedef, n-1);																									}
}																																				int main() {
int main() {																																		int a,b,sayac;
	int n;																																			printf("Iki pozitif tam sayi giriniz: ");
	printf("Disk sayisi \"n\": ");		//t�rnaklar�n ba��nda ters slash'ler olmadan t�rnak i�ine t�rnak yazamam									scanf("%d%d",&a,&b);
	scanf("%d",&n);																																	if(a>b)
	HanoiKuleleri('A','B','C',n);																													sayac=a;
}																																					else
																																					sayac=b;
																																					printf("EBOB: %d",ebobbulv2(a,b,sayac));
																																				}
   daha basit bir �ey yapal�m xP

int n;
void Nbasamaklisayilariyazdir(int a) {
	printf("%d ",a++);
	if(a==pow(10,n))
		return;
	Nbasamaklisayilariyazdir(a);
}
int main() {
	printf("Basamak sayisini giriniz (tercihen 5'den kucuk): ");
	scanf("%d",&n);													//5 veya daha b�y�k girince stack overflow oluyor :/
	printf("%d basamakli sayilar: ",n);
	Nbasamaklisayilariyazdir(pow(10,n-1));
}

void fonk(char *s) {
	if(s[0]=='\0')	//'\0' ile NULL (herhangi bir de�ere sahip olmama) ayn� �ey, dolay�s�yla dizi NULL ise fonksiyon biter
		return;		//fonk fonksiyonu: s[0]'� 1 kez, s[1]'i 2 kez, s[2]'yi 4 kez, s[i]'yi 2^i kez,...
	fonk(s + 1);	//s[strlen(s)-1]'i (son eleman) 2^(strlen(s)-1) kez yazd�r�r
	fonk(s + 1);	//dolay�s�yla ��kt�m 1+2+4+...+2^(strlen(s)-1)=(2^strlen(s))-1 uzunlu�unda olur
	printf("%c",s[0]);	//misal "xyz" i�in fonk("xyz") => 2 tane fonk("yz") => 4 tane fonk("z") eder zira s pointer'� bir bir artt���nda dizinin
}						//ilk eleman� unutuluyor ve s[0]'�n (ilk eleman) de�erleri s�rayla x,y,z oluyor
int main() {			//tabii fonksiyon her kendini �a��rd���nda en alttaki printf fonksiyonu okunamad��� i�in ilk z, sonra y, en son da x yazd�r�l�yor
	fonk("xyz");	//1 tane x, 2 tane y, 4 tane z
	printf("\n");	//��kt�m 2^3-1=7 karakter uzunlu�unda
	fonk("lmnop");	//1 tane l, 2 tane m, 4 tane n, 8 tane o, 16 tane p
	return 0;		//��kt�m 2^5-1=31 karakter uzunlu�unda
}

   son olarak da klasik bir merdiven �izelim */

void MerdivenYazdir(int bas,int son,char k) {
	int i;
	if(k=='t') {
		for(i=bas;i<son;i++)
			printf("*");
		printf("\n");
		if(bas==son)
			return;
		MerdivenYazdir(bas+1,son,'t');
	}
	else if(k=='d') {
		for(i=bas;i<son;i++)
			printf("*");
		printf("\n");
		if(bas==0)
			return;
		MerdivenYazdir(bas-1,son,'d');
	}
}
int main() {
	int n;
	printf("Merdivenin uzunlugunu giriniz: ");
	scanf("%d",&n);
	printf("\n***** Duz Merdiven *****\n\n");
	MerdivenYazdir(n-1,n,'d');
	printf("\n***** Ters Merdiven *****\n\n");
	MerdivenYazdir(0,n,'t');
	return 0;
}
