#include <stdio.h>
#include <stdlib.h>

/* "local variable: yerel deðiþken"		"global variable: genel deðiþken"		"static variable: kalýcý deðiþken"
   C dilinde deðiþkenler local (yerel), global (genel) ve static (kalýcý) olmak üzere 3'e ayrýlýr
   bir fonksiyonun içinde tanýmlanýp sadece o fonksiyon içinde kullanýlabilen deðiþkenlere local deðiþken denir
   farklý fonksiyonlarda local deðiþkenler için ayný isimler kullanýlabilir

void fonksiyon1() {																					int main() {
	int a=3,b=7;																						int a=100;
	printf("a=%d b=%d",a,b);	//"a=3 b=7" yazdýracak													{
}																										int a=10;
void fonksiyon2() {																						printf("Icerdeki a = %d\n",a);
	int a=5;																							}		//bu kod bloðunun içinde tanýmlanan a deðeri kod bloðunun dýþýndaki a'dan baðýmsýz
	printf("a=%d",a);	//"a=5" yazdýrýr, ama eðer burada a'ya deðer atamasaydým "3" yazdýrýrdý			printf("Disardaki a = %d",a);
}																									}
int main() {
	fonksiyon1();
	printf("\n");
	fonksiyon2();
}

   main fonksiyonu dahil tüm fonksiyonlarýn dýþýnda tanýmlanan deðiþkenlere global deðiþken denir

int a,b=10;		//global deðiþkenleri tanýmlayýp initialize (ilk deðeri atamak) ediyorum
				//a'ya deðer atanmadýðý için bilgisayar otomatik 0 alacak
void fonk_1() {
	printf("fonk_1() ile cagrilan global a = %d\n",a);
	printf("fonk_1() ile cagrilan global b = %d\n\n",b);
}
void fonk_2() {
	int a=5;
	printf("fonk_2() nin icindeki a = %d\n",a);
}
int main() {
	printf("Global a = %d\n",a);
	printf("Global b = %d\n\n",b);
	fonk_1();
	fonk_2();
}

   birden fazla fonksiyon çaðýrma söz konusu olduðunda son deðerini koruyan deðiþkenlere static deðiþken denir ve "static degiskenturu degiskenadi" syntax'ý ile gösterilir
   normalde bir fonksiyonun içerisinde oluþturulan (main() dahil) local deðiþkenler fonksiyon bittiðinde (return veya kod bloðu sonu ile) bellekten silinir
   ancak static deðiþkenler fonksiyon içerisinde oluþturulduðunda fonksiyon bitse dahi program çalýþtýðý sürece bellekten silinmez ve kendisine yapýlan deðiþiklikleri hatýrlar
   bu elemaný OOP'de tekrar göreceðimiz için þimdilik bu kadar bilmemiz yeterli

void f() {
	int a=20;			//a: local deðiþken
	static int b=100;	//b: static deðiþken
	printf("a = %d\n",a);	//çýktým 3 defa "a = 20" olacak çünkü a her kod sonunda bir arttýrýlsa da her f fonksiyonu çaðrýldýðýnda yeni deðeri RAM'den silinecek ve eski deðeri olan 20'e dönecek
	printf("b = %d\n\n",b);	//çýktýlarým sýrayla "b = 100","b = 101","b = 102" olacak çünkü b her kod sonunda bir arttýrýlacak ve tekrar f fonksiyonu çaðýrýldýðýnda
	a++;					//kendisine yapýlan deðiþiklikleri hatýrlayacak ve initialize edilmiþ (baþlangýç) deðeri olan 100'e bir daha dönmeyecek
	b++;
}
int a=2,b=10;	//local ve static deðiþkenlerin global deðiþkenlere göre önceliði olduðu için bu statement'ýn hiçbir etkisi yok
int main() {
	f();
	f();
	f();		//for(i=0;i<5;i++) f();  ile ayný þey
	f();
	f();
}

   "const: constant , sabit deðer"
   hiçbir türlü initialize edilmiþ deðeri deðiþtirilemeyen veri tiplerine constant denir ve "const degiskenturu degiskenadi" syntax'ý ile gösterilir
   dikkat ederseniz deðiþken demiyorum çünkü deðiþemezler */

int main() {
	const int a=6;
	const int dizi[5]={10,20,30,40,50};

/*	a=20;
	a++;
	dizi[3]=25;		gibi statement'lar error veriyor, hiç boþuna uðraþmayýn */

	printf("a: %d\nDizinin 3. elemani: %d\n",a,*(dizi+2));

	const float x;
	printf("x icin deger giriniz: ");
	scanf("%f",&x);		//const objeye klavyeden deðer atamak da warning veriyor ama neyse
	printf("x'in degeri: %f",x);

	return 0;
}
