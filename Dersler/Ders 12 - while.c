#include <stdio.h>
#include <stdlib.h>

/* "while: while loop , iken d�ng�s�"
   for d�ng�s� ile ayn� i�leve sahip olan while d�ng�s�n�n for'dan tek fark� syntax'idir
   for d�ng�s�n�n syntax'�	for(i=baslangic;i<=bitis;i+=artis miktari) { 	iken while'inki		i=baslangic;
   							}																	while(i=<bitis) {
																									i+=artis miktari
																						   		}                        bi�imindedir
	yani while d�ng�s�nde ba�lang�� de�eri en ba�ta atan�r, parantez i�ine biti� ko�ulu girilir, art�� miktar� da scope'un i�ine yaz�l�r
	for d�ng�s�ndeki gibi scope i�indeki fonksiyonlar veya komutlar i de�i�keninin ald��� de�erlere g�re s�rayla tekrar eder

int main() {

	int i=1;
	while(i<=5) {
		printf("Merhaba Kocaelililer\n");
		i++;	//e�er i++ olmasayd� sonsuz d�ng�ye girerdi
	}			//��nk� i<=5 sa�land��� s�rece printf fonksiyonu uygulanacak ve i=1 olarak kald��� i�in bu sonsuz defa "Merhaba Kocaelililer" yazd�r�lacak demektir
}				//ve evet for(i=1;i<=5;i++) { printf("Merhaba Kocaelililer\n"); } ile ayn� :P

   fakt�riyel yazal�m: while edition

int main() {																			int main() {
	int sayi,fuck;																			int a,b,c,d,x,i;
	printf("Faktoriyeli alinacak sayiyi girin: ");				//	sayi	fuck			a=b=c=i=1;
	scanf("%d",&sayi);											//	N/A		 1				printf("Tribonacci dizisinin ilk 3'� dahil kac terimini istersiniz?: ");
	fuck=1;														//	 5		 5				scanf("%d",&x);
	while(sayi>1) {												//	 4		 20				printf(" %d %d %d",a,b,c);
		fuck=fuck*sayi;											//	 3		 60				while(i<=x-3) {
		sayi--;													//	 2		 120				a=b;																																			d=a+b+c;
	}																							b=c;
	printf("Sonuc: %d",fuck);																	c=d;
	}																							printf(" %d",d);
																								i++;
																							}
																						}
*/

int main() {

	int weed=2;
	while(weed<=20) {
		if(weed%2==0 && weed!=14) {
			printf("%d\n",weed);
		}
		weed++;
	}

	return 0;		//1 ile 20 aras�nda bulunan, 14 say�s� haricindeki �ift say�lar� listeleyen kod bu
}					//weed=2,3,4,...,20 say�lar�ndan 14'e e�it olmayan ve 2'ye tam b�l�nenleri yazd�r�yor yani
