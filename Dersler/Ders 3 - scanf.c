#include <stdio.h>
#include <stdlib.h>

/* "scanf: scan formatted"
   normalde printf fonksiyonunda yazdýrýlacak veriyi kodun içine hazýr olarak yazýyorduk
   bu sefer veriyi (misal deðiþkenin deðerini) çalýþtýr kutusunda biz yazýyoruz
   böylelikle istediðimiz deðerleri deðiþkene atayabiliriz
   scanf aç parantez týrnak týrnak kapa parantez virgül deðiþkenadi ==> scanf("",degiskenadi)       printf ile ayný syntax'a (yazým kurallarýna) sahip aq
   scanf fonksiyonunun tek sýkýntýsý boþluðu ve ondan sonra gelen verileri algýlamamasý
   scanf'in içine daima %s,%c,%d,%f... belirteçleri filan yazýlýr, deðiþkenine göre bunlarý girmeyi unutma

int main() {

	char kitapad[31];
	printf("Kitabin Adini Giriniz: ");
	scanf("%s",kitapad);			//misal ben "Fareler ve Insanlar" yazsam (yani kitapad[31]="Fareler ve Insanlar" olur char deðiþkenim) çalýþtýr'da çýktým "Fareler" olurdu
	printf("Girmis Oldugunuz Kitap: %s",kitapad);

}

   scanf'in boþluktan sonraki verileri de algýlamasý için özel olarak "%[^\n]%*c" kalýbý kullanýlýr
   detaya girecek olursak "^\n" yeni bir satýra (newline) geçmeden önceki bütün girdileri (karakterleri) belleðe al
   "%*c" ise yeni satýrdaki ilk karakteri al ve onu discard et (bellekten at) demek

int main() {

	char kitapad[100];
	scanf("%[^\n]",kitapad);		//alternatif olarak bu koda ama "Fareler ve Insanlar" yazarsam çýktým "Fareler ve Insanlar" olur
	printf("Girdiginiz kitabin tam adi: %s",kitapad);

}

   tabii scanf("%[^\n]%*c",degiskenadi) kalýbý her zaman çalýþmaz çünkü bu statement kendisinden bir önceki satýrdaki newline karakterini de okuyabilir
   o yüzden bu kalýp scanf("\n%[^\n]%*c",degiskenadi) veya scanf(" %[^\n]%*c",degiskenadi) syntax'larý ile kullanýlýr

int main() {

	char harf,kelime[20],cumle[100];

	printf("Harfi Giriniz: ");
	scanf("%c",&harf);

	printf("Kelimeyi Giriniz: ");
	scanf("%s",kelime);

	printf("Cumleyi Giriniz: ");
	scanf(" %[^\n]%*c",cumle);

	printf("\n\n\nHarf: %c\nKelime: %s\nCumle: %s",harf,kelime,cumle);

}

*/

int main() {
	
	char Ad[15],Soyad[15],Yas[2],Sehir[15],Meslek[15];
	
	printf("Adiniz: ");
	scanf("%s",Ad);
	
	printf("Soyadiniz: ");
	scanf("%s",Soyad);
	
	printf("Yasiniz: ");
	scanf("%s",Yas);
	
	printf("Sehriniz: ");
	scanf("%s",Sehir);
	
	printf("Mesleginiz: ");
	scanf("%s",Meslek);
	
	printf("\n\n");
	
	printf("Adi: %s - Soyadi: %s\n",Ad,Soyad);
	printf("Yasi: %s\n",Yas);
	printf("Meslek: %s - Sehir: %s",Meslek,Sehir);
	
	return 0;
}
