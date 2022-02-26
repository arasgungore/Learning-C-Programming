#include <stdio.h>
#include <stdlib.h>

/* "local variable: yerel de�i�ken"		"global variable: genel de�i�ken"		"static variable: kal�c� de�i�ken"
   C dilinde de�i�kenler local (yerel), global (genel) ve static (kal�c�) olmak �zere 3'e ayr�l�r
   bir fonksiyonun i�inde tan�mlan�p sadece o fonksiyon i�inde kullan�labilen de�i�kenlere local de�i�ken denir
   farkl� fonksiyonlarda local de�i�kenler i�in ayn� isimler kullan�labilir

void fonksiyon1() {																					int main() {
	int a=3,b=7;																						int a=100;
	printf("a=%d b=%d",a,b);	//"a=3 b=7" yazd�racak													{
}																										int a=10;
void fonksiyon2() {																						printf("Icerdeki a = %d\n",a);
	int a=5;																							}		//bu kod blo�unun i�inde tan�mlanan a de�eri kod blo�unun d���ndaki a'dan ba��ms�z
	printf("a=%d",a);	//"a=5" yazd�r�r, ama e�er burada a'ya de�er atamasayd�m "3" yazd�r�rd�			printf("Disardaki a = %d",a);
}																									}
int main() {
	fonksiyon1();
	printf("\n");
	fonksiyon2();
}

   main fonksiyonu dahil t�m fonksiyonlar�n d���nda tan�mlanan de�i�kenlere global de�i�ken denir

int a,b=10;		//global de�i�kenleri tan�mlay�p initialize (ilk de�eri atamak) ediyorum
				//a'ya de�er atanmad��� i�in bilgisayar otomatik 0 alacak
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

   birden fazla fonksiyon �a��rma s�z konusu oldu�unda son de�erini koruyan de�i�kenlere static de�i�ken denir ve "static degiskenturu degiskenadi" syntax'� ile g�sterilir
   normalde bir fonksiyonun i�erisinde olu�turulan (main() dahil) local de�i�kenler fonksiyon bitti�inde (return veya kod blo�u sonu ile) bellekten silinir
   ancak static de�i�kenler fonksiyon i�erisinde olu�turuldu�unda fonksiyon bitse dahi program �al��t��� s�rece bellekten silinmez ve kendisine yap�lan de�i�iklikleri hat�rlar
   bu eleman� OOP'de tekrar g�rece�imiz i�in �imdilik bu kadar bilmemiz yeterli

void f() {
	int a=20;			//a: local de�i�ken
	static int b=100;	//b: static de�i�ken
	printf("a = %d\n",a);	//��kt�m 3 defa "a = 20" olacak ��nk� a her kod sonunda bir artt�r�lsa da her f fonksiyonu �a�r�ld���nda yeni de�eri RAM'den silinecek ve eski de�eri olan 20'e d�necek
	printf("b = %d\n\n",b);	//��kt�lar�m s�rayla "b = 100","b = 101","b = 102" olacak ��nk� b her kod sonunda bir artt�r�lacak ve tekrar f fonksiyonu �a��r�ld���nda
	a++;					//kendisine yap�lan de�i�iklikleri hat�rlayacak ve initialize edilmi� (ba�lang��) de�eri olan 100'e bir daha d�nmeyecek
	b++;
}
int a=2,b=10;	//local ve static de�i�kenlerin global de�i�kenlere g�re �nceli�i oldu�u i�in bu statement'�n hi�bir etkisi yok
int main() {
	f();
	f();
	f();		//for(i=0;i<5;i++) f();  ile ayn� �ey
	f();
	f();
}

   "const: constant , sabit de�er"
   hi�bir t�rl� initialize edilmi� de�eri de�i�tirilemeyen veri tiplerine constant denir ve "const degiskenturu degiskenadi" syntax'� ile g�sterilir
   dikkat ederseniz de�i�ken demiyorum ��nk� de�i�emezler */

int main() {
	const int a=6;
	const int dizi[5]={10,20,30,40,50};

/*	a=20;
	a++;
	dizi[3]=25;		gibi statement'lar error veriyor, hi� bo�una u�ra�may�n */

	printf("a: %d\nDizinin 3. elemani: %d\n",a,*(dizi+2));

	const float x;
	printf("x icin deger giriniz: ");
	scanf("%f",&x);		//const objeye klavyeden de�er atamak da warning veriyor ama neyse
	printf("x'in degeri: %f",x);

	return 0;
}
