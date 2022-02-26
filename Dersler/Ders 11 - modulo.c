#include <stdio.h>
#include <stdlib.h>

/* ufak bir hat�rlatma
   "%: modulo operator , mod alma operat�r�"
   bunun syntax'� b=a%c bi�imindedir ve matematiksel kar��l��� da en k���k pozitif b de�eri i�in a=b	(mod c) tir
   if i�erisine (a%c==b) bi�iminde yaz�laca�� i�in genelde a int de�i�keni, b ve c ise say� olur   (b==a%c bi�iminde yazmak da s�k�nt� yapmaz)
   bu i�lemi a/c gibi d���nebiliriz, sadece "="den �NCE b�l�m� de�il de kalan� yaz�yoruz   (b=a%c ise a/c i�leminden kalan b'dir ve mod c'de a=b'dir)
   misal mod 4'te 1=5=9=13=17 dir ama 1=17%4 ya da 1=13%4 t�r
   "=" programlamada mod (%) operat�r� i�in sol tarafa yaz�l�r, �te yandan "=="in hangi tarafa yaz�ld���n�n bir �nemi yok
   ayn� �ey d�rt i�lem i�in de ge�erli, de�i�kenler aras� denklem kurarken "=" daima sol tarafa yaz�lmal�   (d=a+b+c ve toplam=toplam+4*i do�ru, a+b+c=d ve toplam+4*i=toplam yanl��)

   "=: e�ittir (atama)"           "==: e�it midir (sorgulama)"            "!=: e�it de�il midir (sorgulama)"

int main() {
	int i;
	for(i=1,i<=50,i++) {					//1'den 50'ye kadar olan b�t�n i de�erlerinden sadece 5'e tam b�l�nenleri yazd�r�yor
		if(i%5==0) {						//yani 5 10 15 ... 45 50
		printf("%d\n",i);					//daha pratik olarak:	int main() {
		}																int i;
	}																	for(i=5;i<=50;i+=5) {
}																		printf("%d\n",i);
																		}
																	}			yaz�labilir...

   modulo operat�r� pozitif say�lar�n o moddaki pozitif en k���k (0'a en yak�n) dengini d�nd�r�rken negatif say�lar i�in o moddaki negatif en b�y�k (0'a en yak�n) dengini d�nd�r�r

int main() {
	int x,y;
	printf("Lutfen ozellikle negatif bir sayi giriniz: ");
	scanf("%d",&x);
	printf("Modu giriniz: ");
	scanf("%d",&y);
	printf("Negatif (default) deger: %d\nPozitif deger: %d", x%y, x%y + y);
}

   bir say�n�n 3'e, 5'e ve 7'ye b�l�nebilirli�ine bakan bir kod yazal�m

int main () {
	int sayi;
	printf("Sayiyi Girin: ");
	scanf("%d",&sayi);
	if(sayi%3==0 && sayi%5==0 && sayi%7==0) {
		printf("Bu sayi 3, 5 ve 7'ye tam bolunur");
	}
	if(sayi%3==0 && sayi%5==0 && sayi%7!=0) {
		printf("Bu sayi 3 ve 5'e tam bolunur, 7'ye tam bolunmez");
	}
	if(sayi%3==0 && sayi%5!=0 && sayi%7==0) {
		printf("Bu sayi 3 ve 7'ye tam bolunur, 5'e tam bolunmez");
	}
	if(sayi%3!=0 && sayi%5==0 && sayi%7==0) {
		printf("Bu sayi 5 ve 7'ye tam bolunur, 3'e tam bolunmez");
	}
	if(sayi%3!=0 && sayi%5!=0 && sayi%7==0) {
		printf("Bu sayi sadece 7'ye tam bolunur, 3 ve 5'e tam bolunmez");
	}
	if(sayi%3!=0 && sayi%5==0 && sayi%7!=0) {
		printf("Bu sayi sadece 5'e tam bolunur, 3 ve 7'ye tam bolunmez");
	}
	if(sayi%3==0 && sayi%5!=0 && sayi%7!=0) {
		printf("Bu sayi sadece 3'e tam bolunur, 5 ve 7'ye tam bolunmez");
	}
	if(sayi%3!=0 && sayi%5!=0 && sayi%7!=0) {
		printf("Bu sayi 3, 5 ve 7'den hicbirine tam bolunmez");
	}
}

   hadi 3 basamakl� bir say�y� basamaklar�na ay�ral�m */

int main() {

	int sayi,yuzler,onlar,birler;

	printf("3 basamakli bir sayi giriniz: ");
	scanf("%d",&sayi);

	yuzler=sayi/100;	//int de�i�keni sa�olsun

	onlar=sayi/10;
	onlar=onlar%10;		//onlar de�i�kenine �st sat�rda de�er atasam da ben yeniden onlar de�i�kenine kendi son atanan de�eri �zerinden tekrar yeni bir de�er atayabilirim
						//veya onlar1=sayi/10   onlar2=onlar1%10 da diyebilirdim :P
	birler=sayi%10;

	printf("%d\n%d\n%d",yuzler,onlar,birler);

	return 0;
}
