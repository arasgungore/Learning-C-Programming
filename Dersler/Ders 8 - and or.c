#include <stdio.h>
#include <stdlib.h>

/* hemen bir hatýrlayalým
   "=: atama (eþittir)"				"==: sorgulama (eþit midir?)"
   "< >: küçük müdür?  büyük müdür?"				"<=  >=: küçük eþit midir?  büyük eþit midir?"
   bu iþaretler if'in içine yazýlacak koþulu belirlemek için kullanýlýr

   "&&: and , ve (iki koþulu da ayný anda saðlayan deðerler için)"                "||: or , veya (iki koþulun ayrý ayrý saðlandýðý bütün deðerler için)"
   bu iki operatör iki koþul arasýnda baðlaç olarak kullanýlýr

   "%: mod alma operatörü"   bunun syntax'ý b=a%c biçimindedir ve matematiksel karþýlýðý da en küçük b deðeri için a=b (mod c) tir
   if içerisine (a%c==b) biçiminde yazýlacaðý için genelde a int deðiþkeni, b ve c ise sayý olur
   bu iþlemi a/c gibi ama sadece "="den ÖNCE bölümü deðil de kalaný yazdýðýmýzý düþünebiliriz (b=a%c ise a/c iþleminden kalan b'dir ve mod c'de a=b'dir)
   misal mod 4'te 1=5=9=13=17 dir ama 1=17%4 ya da 1=13%4 tür
   "=" programlamada mod (%) operatörü için sol tarafa yazýlýr, öte yandan "=="in hangi tarafa yazýldýðýnýn bir önemi yok   (dört iþlemde ise ne "="in ne de "=="in hangi tarafa yazýldýðýnýn bir önemi yok)

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
