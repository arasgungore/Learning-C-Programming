#include <stdio.h>
#include <stdlib.h>

/* hemen bir hat�rlayal�m
   "=: atama (e�ittir)"				"==: sorgulama (e�it midir?)"
   "< >: k���k m�d�r?  b�y�k m�d�r?"				"<=  >=: k���k e�it midir?  b�y�k e�it midir?"
   bu i�aretler if'in i�ine yaz�lacak ko�ulu belirlemek i�in kullan�l�r

   "&&: and , ve (iki ko�ulu da ayn� anda sa�layan de�erler i�in)"                "||: or , veya (iki ko�ulun ayr� ayr� sa�land��� b�t�n de�erler i�in)"
   bu iki operat�r iki ko�ul aras�nda ba�la� olarak kullan�l�r

   "%: mod alma operat�r�"   bunun syntax'� b=a%c bi�imindedir ve matematiksel kar��l��� da en k���k b de�eri i�in a=b (mod c) tir
   if i�erisine (a%c==b) bi�iminde yaz�laca�� i�in genelde a int de�i�keni, b ve c ise say� olur
   bu i�lemi a/c gibi ama sadece "="den �NCE b�l�m� de�il de kalan� yazd���m�z� d���nebiliriz (b=a%c ise a/c i�leminden kalan b'dir ve mod c'de a=b'dir)
   misal mod 4'te 1=5=9=13=17 dir ama 1=17%4 ya da 1=13%4 t�r
   "=" programlamada mod (%) operat�r� i�in sol tarafa yaz�l�r, �te yandan "=="in hangi tarafa yaz�ld���n�n bir �nemi yok   (d�rt i�lemde ise ne "="in ne de "=="in hangi tarafa yaz�ld���n�n bir �nemi yok)

int main() {									int main() {												int main() {

	int sayi;   									int x;														int sayi;
	sayi=5;											printf("Sayiyi Girin: ");									printf("Sayiyi Girin: ");
													scanf("%d",&x);												scanf("%d",&sayi);
	if(sayi%2==0) {
		printf("Sayi cifttir");						if(x%5==0) {												if(sayi%3==0 && sayi%5==0) {
	}													printf("%d 5'e tam bolunur",x);								printf("Sayi 15'e tam bolunur");
	else {											}															}
		printf("Sayi tektir");						else {														else {
	}													printf("%d 5'e tam bolunmez",x);							printf("Sayi 15'e tam bolunmez");
}													}															}
   												}															}

int main() {

	printf("*****Suyun Durumu*****\n\n");
	int su;
	printf("Sicaklik degerini giriniz (Celcius): ");
	scanf("%d",&su);
	if(su<-273) {
		printf("\nGecersiz sicaklik degeri girdiniz");
	}
	if(-273<su && su<0) {
		printf("\nSu %d C sicakliginda buz halinde bulunur",su);
	}
	if(su==0) {
		printf("\nSu %d C sicakliginda sivi-buz karisimi olarak bulunur",su);
	}
	if(0<su && su<100) {
		printf("\nSu %d C sicakliginda sivi halinde bulunur",su);
	}
	if(su==100) {
		printf("\nSu %d C sicakliginda sivi-buhar karisimi olarak bulunur",su);
	}
	if(su>100) {
		printf("\nSu %d C sicakliginda buhar halinde bulunur",su);
	}
}		*/

int main() {

	int a,b,c;
	printf("Birinci Sayiyi (Boluneni) Giriniz: ");
	scanf("%d",&a);
	printf("Ikinci Sayiyi (Boleni) Giriniz: ");
	scanf("%d",&b);

	c=a%b;

	if(a%b==0) {
		printf("%d %d'e tam bolunur",a,b);
	}
	else {
		printf("%d'in %d'e bolumunden kalan %d'dir",a,b,c);
	}

	return 0;
}
