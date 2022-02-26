#include <stdio.h>
#include <stdlib.h>

/* "while: while loop , iken döngüsü"
   for döngüsü ile ayný iþleve sahip olan while döngüsünün for'dan tek farký syntax'idir
   for döngüsünün syntax'ý	for(i=baslangic;i<=bitis;i+=artis miktari) { 	iken while'inki		i=baslangic;
   							}																	while(i=<bitis) {
																									i+=artis miktari
																						   		}                        biçimindedir
	yani while döngüsünde baþlangýç deðeri en baþta atanýr, parantez içine bitiþ koþulu girilir, artýþ miktarý da scope'un içine yazýlýr
	for döngüsündeki gibi scope içindeki fonksiyonlar veya komutlar i deðiþkeninin aldýðý deðerlere göre sýrayla tekrar eder

int main() {

	int i=1;
	while(i<=5) {
		printf("Merhaba Kocaelililer\n");
		i++;	//eðer i++ olmasaydý sonsuz döngüye girerdi
	}			//çünkü i<=5 saðlandýðý sürece printf fonksiyonu uygulanacak ve i=1 olarak kaldýðý için bu sonsuz defa "Merhaba Kocaelililer" yazdýrýlacak demektir
}				//ve evet for(i=1;i<=5;i++) { printf("Merhaba Kocaelililer\n"); } ile ayný :P

   faktöriyel yazalým: while edition

int main() {																			int main() {
	int sayi,fuck;																			int a,b,c,d,x,i;
	printf("Faktoriyeli alinacak sayiyi girin: ");				//	sayi	fuck			a=b=c=i=1;
	scanf("%d",&sayi);											//	N/A		 1				printf("Tribonacci dizisinin ilk 3'ü dahil kac terimini istersiniz?: ");
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

	return 0;		//1 ile 20 arasýnda bulunan, 14 sayýsý haricindeki çift sayýlarý listeleyen kod bu
}					//weed=2,3,4,...,20 sayýlarýndan 14'e eþit olmayan ve 2'ye tam bölünenleri yazdýrýyor yani
