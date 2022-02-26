#include <stdio.h>
#include <stdlib.h>

/* ufak bir hatýrlatma
   "%: modulo operator , mod alma operatörü"
   bunun syntax'ý b=a%c biçimindedir ve matematiksel karþýlýðý da en küçük pozitif b deðeri için a=b	(mod c) tir
   if içerisine (a%c==b) biçiminde yazýlacaðý için genelde a int deðiþkeni, b ve c ise sayý olur   (b==a%c biçiminde yazmak da sýkýntý yapmaz)
   bu iþlemi a/c gibi düþünebiliriz, sadece "="den ÖNCE bölümü deðil de kalaný yazýyoruz   (b=a%c ise a/c iþleminden kalan b'dir ve mod c'de a=b'dir)
   misal mod 4'te 1=5=9=13=17 dir ama 1=17%4 ya da 1=13%4 tür
   "=" programlamada mod (%) operatörü için sol tarafa yazýlýr, öte yandan "=="in hangi tarafa yazýldýðýnýn bir önemi yok
   ayný þey dört iþlem için de geçerli, deðiþkenler arasý denklem kurarken "=" daima sol tarafa yazýlmalý   (d=a+b+c ve toplam=toplam+4*i doðru, a+b+c=d ve toplam+4*i=toplam yanlýþ)

   "=: eþittir (atama)"           "==: eþit midir (sorgulama)"            "!=: eþit deðil midir (sorgulama)"

int main() {
	int i;
	for(i=1,i<=50,i++) {					//1'den 50'ye kadar olan bütün i deðerlerinden sadece 5'e tam bölünenleri yazdýrýyor
		if(i%5==0) {						//yani 5 10 15 ... 45 50
		printf("%d\n",i);					//daha pratik olarak:	int main() {
		}																int i;
	}																	for(i=5;i<=50;i+=5) {
}																		printf("%d\n",i);
																		}
																	}			yazýlabilir...

   modulo operatörü pozitif sayýlarýn o moddaki pozitif en küçük (0'a en yakýn) dengini döndürürken negatif sayýlar için o moddaki negatif en büyük (0'a en yakýn) dengini döndürür

int main() {
	int x,y;
	printf("Lutfen ozellikle negatif bir sayi giriniz: ");
	scanf("%d",&x);
	printf("Modu giriniz: ");
	scanf("%d",&y);
	printf("Negatif (default) deger: %d\nPozitif deger: %d", x%y, x%y + y);
}

   bir sayýnýn 3'e, 5'e ve 7'ye bölünebilirliðine bakan bir kod yazalým

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

   hadi 3 basamaklý bir sayýyý basamaklarýna ayýralým */

int main() {

	int sayi,yuzler,onlar,birler;

	printf("3 basamakli bir sayi giriniz: ");
	scanf("%d",&sayi);

	yuzler=sayi/100;	//int deðiþkeni saðolsun

	onlar=sayi/10;
	onlar=onlar%10;		//onlar deðiþkenine üst satýrda deðer atasam da ben yeniden onlar deðiþkenine kendi son atanan deðeri üzerinden tekrar yeni bir deðer atayabilirim
						//veya onlar1=sayi/10   onlar2=onlar1%10 da diyebilirdim :P
	birler=sayi%10;

	printf("%d\n%d\n%d",yuzler,onlar,birler);

	return 0;
}
