#include <stdio.h>
#include <stdlib.h>

/* "string: katar , karakter dizini"		"puts: put string , katar� yazd�r"		"gets: get string , katar� oku"
   char de�i�keninden elde edilen bir boyutlu array'ler olan string'ler as�l veri t�rlerinden biri de�ildir ve char[karaktersiniri]="degisken" bi�iminde yaz�l�p tan�mlanabilirler
   printf ve scanf'in s�k�a arg�man� olan string'ler "%s" belirteciyle ifade edilirken scanf maalesef bo�luk karakterinden sonras�n� almad��� i�in onun yerine stringler i�in
   "puts" ve "gets" fonksiyonlar� kullan�l�r, bunlar�n genel syntax'lar� ise gets a� parantez de�i�kenad� kapa parantez ve puts a� parantez de�i�kenad� kapa parantez ==> gets(degiskenadi) puts(degiskenadi)
   "gets", "scanf" fonksiyonu ile ayn� i�levi g�r�rken ona ek olarak i�ine girilen B�T�N veriyi saklar, yani bo�luktan sonra yan �izmez ;)
   "puts" ise "gets"e yaz�lan veriyi aynen yazd�r�r
   alternatif olarak puts("") syntax'� kullan�larak puts fonksiyonu printf fonksiyonunun yerine kullan�labilir

int main() {										//Ders 1'e throwback :)
	puts("********** Ogrenci Bilgi **********\n");	//puts fonksiyonu printf'in aksine otomatik olarak alt sat�ra ge�er
	puts("Isim: Aras");								//o y�zden sat�r sonunu "\n" ile bitirince 1 de�il 2 sat�r atl�yor
	puts("Soyad: Gungore");
	puts("Ogrenci No: 2018401117");
	puts("Dogum Tarihi: 11/09/2000\n");
	puts("***********************************");
}

int main() {
	char bilgi[100];
	printf("Bilgiyi Giriniz: ");
	scanf("%s",bilgi);
	printf("\n\nBilgi: %s",bilgi);	//mesela "Dostoyevski" yazsayd�m ��kt�m yine "Dostoyevski" olurdu
}									//ama "Suc ve Ceza" yazsayd�m ��kt�m "Suc" olurdu ��nk� ilk girdi�im bo�luktan sonra kalan veriyi bilgisayar belle�e atm�yor

int main() {
	char bilgi[100];
	printf("Bilgiyi Giriniz: ");
	gets(bilgi);
	printf("\n\nBilgi: ");			//burada Dostoyevski de yazsam Suc ve Ceza da yazsam fark etmeyecek, yazd���m veriyi 100 karakter s�n�r�n� a�mad���m s�rece aynen alacam
	puts(bilgi);
}

   "%s" demi�ken bunu daha yak�ndan inceleyelim

int main() {
	char kitap[40];
	printf("Kitap Ismi: ");
	scanf("%s",kitap);				//mesela "Mufettis" yazay�m   (8 karakterli string)
	printf("\n%s",kitap);			//��kt� "Mufettis" olacak, yani ayn�s�
	printf("\n%.4s",kitap);			//��kt� "Mufe" olacak, bilgisayar "Mufettis"in ilk 4 karakterini yazd�rd�
	printf("\n%18s",kitap);			//��kt� "          Mufettis" olacak, bilgisayar ba�a 10 tane bo�luk koyarak toplam karakter say�s�n� 18'e tamamlad�
	printf("\n%20.5s",kitap);		//��kt� "               Mufet" olacak, bilgisayar �nce "Mufettis"in ilk 5 karakterini yazd�rd�, sonra da karakter say�s�n� 20'ye tamamlamak i�in ba�a 15 tane bo�luk koydu
	printf("\n%-15s",kitap);		//��kt� "Mufettis       " olacak, bilgisayar sona 7 tane bo�luk koyarak toplam karakter say�s�n� 15'e tamamlad�
	printf("\n%-20.4sttis",kitap);	//��kt� "Mufe                ttis" olacak, bilgisayar �nce "Mufettis"in ilk 4 karakterini yazd�rd�, sonra karakter say�s�n� 20'ye tamamlamak i�in sona 16 tane bo�luk koydu, en son da "ttis" yazd�rd�
}

   "%f" de buna benzer �al���r, "%sayi.f" de sayi k�sm�na yazd���m say� de�eri, bilgisayar�n virg�lden sonra yazd�raca�� basamak say�s�n� belirler */
   
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
