#include <stdio.h>
#include <stdlib.h>

/* "string: katar , karakter dizini"		"puts: put string , katarý yazdýr"		"gets: get string , katarý oku"
   char deðiþkeninden elde edilen bir boyutlu array'ler olan string'ler asýl veri türlerinden biri deðildir ve char[karaktersiniri]="degisken" biçiminde yazýlýp tanýmlanabilirler
   printf ve scanf'in sýkça argümaný olan string'ler "%s" belirteciyle ifade edilirken scanf maalesef boþluk karakterinden sonrasýný almadýðý için onun yerine stringler için
   "puts" ve "gets" fonksiyonlarý kullanýlýr, bunlarýn genel syntax'larý ise gets aç parantez deðiþkenadý kapa parantez ve puts aç parantez deðiþkenadý kapa parantez ==> gets(degiskenadi) puts(degiskenadi)
   "gets", "scanf" fonksiyonu ile ayný iþlevi görürken ona ek olarak içine girilen BÜTÜN veriyi saklar, yani boþluktan sonra yan çizmez ;)
   "puts" ise "gets"e yazýlan veriyi aynen yazdýrýr
   alternatif olarak puts("") syntax'ý kullanýlarak puts fonksiyonu printf fonksiyonunun yerine kullanýlabilir

int main() {										//Ders 1'e throwback :)
	puts("********** Ogrenci Bilgi **********\n");	//puts fonksiyonu printf'in aksine otomatik olarak alt satýra geçer
	puts("Isim: Aras");								//o yüzden satýr sonunu "\n" ile bitirince 1 deðil 2 satýr atlýyor
	puts("Soyad: Gungore");
	puts("Ogrenci No: 2018401117");
	puts("Dogum Tarihi: 11/09/2000\n");
	puts("***********************************");
}

int main() {
	char bilgi[100];
	printf("Bilgiyi Giriniz: ");
	scanf("%s",bilgi);
	printf("\n\nBilgi: %s",bilgi);	//mesela "Dostoyevski" yazsaydým çýktým yine "Dostoyevski" olurdu
}									//ama "Suc ve Ceza" yazsaydým çýktým "Suc" olurdu çünkü ilk girdiðim boþluktan sonra kalan veriyi bilgisayar belleðe atmýyor

int main() {
	char bilgi[100];
	printf("Bilgiyi Giriniz: ");
	gets(bilgi);
	printf("\n\nBilgi: ");			//burada Dostoyevski de yazsam Suc ve Ceza da yazsam fark etmeyecek, yazdýðým veriyi 100 karakter sýnýrýný aþmadýðým sürece aynen alacam
	puts(bilgi);
}

   "%s" demiþken bunu daha yakýndan inceleyelim

int main() {
	char kitap[40];
	printf("Kitap Ismi: ");
	scanf("%s",kitap);				//mesela "Mufettis" yazayým   (8 karakterli string)
	printf("\n%s",kitap);			//çýktý "Mufettis" olacak, yani aynýsý
	printf("\n%.4s",kitap);			//çýktý "Mufe" olacak, bilgisayar "Mufettis"in ilk 4 karakterini yazdýrdý
	printf("\n%18s",kitap);			//çýktý "          Mufettis" olacak, bilgisayar baþa 10 tane boþluk koyarak toplam karakter sayýsýný 18'e tamamladý
	printf("\n%20.5s",kitap);		//çýktý "               Mufet" olacak, bilgisayar önce "Mufettis"in ilk 5 karakterini yazdýrdý, sonra da karakter sayýsýný 20'ye tamamlamak için baþa 15 tane boþluk koydu
	printf("\n%-15s",kitap);		//çýktý "Mufettis       " olacak, bilgisayar sona 7 tane boþluk koyarak toplam karakter sayýsýný 15'e tamamladý
	printf("\n%-20.4sttis",kitap);	//çýktý "Mufe                ttis" olacak, bilgisayar önce "Mufettis"in ilk 4 karakterini yazdýrdý, sonra karakter sayýsýný 20'ye tamamlamak için sona 16 tane boþluk koydu, en son da "ttis" yazdýrdý
}

   "%f" de buna benzer çalýþýr, "%sayi.f" de sayi kýsmýna yazdýðým sayý deðeri, bilgisayarýn virgülden sonra yazdýracaðý basamak sayýsýný belirler */
   
int main() {
	double x;
	printf("Kusuratli bir sayi giriniz: ");
	scanf("%lf",&x);
	printf("Tam sayi: %.f\n",x);
	printf("Virgulden sonra 1 basamak: %.1f\n",x);
	printf("Virgulden sonra 2 basamak: %.2f\n",x);
	printf("Virgulden sonra 3 basamak: %.3f\n",x);
	printf("Virgulden sonra 4 basamak: %.4f\n",x);
	printf("Virgulden sonra 5 basamak: %.5f\n",x);
	printf("Virgulden sonra 6 basamak: %.6f\n",x);
}
