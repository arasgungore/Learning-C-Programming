#include <stdio.h>
#include <stdlib.h>

/* "do while: do while loop, yap iken d�ng�s�"		"break: fren , d�ng�y� k�r"		"continue: d�ng�ye devam et"
   "do while" d�ng�s� esas repetitive statement'lar�m�z olan for ve while'a alternatif olarak kullan�lan bir repetitive statement't�r ve i�leyi�i while d�ng�s�ne �ok benzer
   do while d�ng�s�n�n genel syntax'� do a� s�sl� parantez kapa s�sl� parantez while a� parantez kapa parantez
   yani do {
   		} while();    bi�imindedir    (for ve while'�n aksine sonuna noktal� virg�l konmal�)
   while d�ng�s�nden tek fark� while i�ine yaz�lan ko�ula bak�lmaks�z�n d�ng�n�n EN AZ B�R DEFA tekrar edecek olmas�d�r

int main() {
	int i=0;
	do {
		printf("%2d: Merhaba Dunya\n",++i);	//�nce i'nin de�eri artt�r�l�yor, sonra Merhaba Dunya yazd�r�l�yor
	} while(i<10);	//i=1,2,3,4,5,6,7,8,9,10 i�in Merhaba Dunya yazd�r�lacak, i=10 i�in de yazd�r�lmas�n�n sebebi
}					//i=9 i�in d�ng� tekrar eder, printf s�ras�nda i'nin de�eri 1 artar, ve i=10 ko�ulu sa�lamad���ndan da d�ng� biter
					//do while d�ng�s�n�n while'dan as�l fark� i'nin de�eri 0 olsa da, 1000 olsa da, en az�ndan bir kez Merhaba Dunya'n�n yazd�r�lacak olmas�d�r
					//ancak while'de kontrol (sorgulama) �nce yap�ld��� i�in, hi�bir �ey ekrana yaz�lmaz

int main() {
	int sayi1,sayi2;
	char devam_mi;
	do {
		printf("Birinci sayiyi giriniz: ");
		scanf("%d",&sayi1);
		printf("Ikinci sayiyi giriniz: ");
		scanf("%d",&sayi2);
		printf("%d + %d = %d\n", sayi1, sayi2, sayi1+sayi2);
		printf("Devam etmek ister misiniz? (Evet icin e/E giriniz): ");
		
		do {
			scanf("%c",&devam_mi);
		} while(devam_mi=='\n');	//C'de karakter okumalar�, biraz s�k�nt�l�d�r	e�er giri� tampon belle�inde (Buffer) veri bulunuyorsa, bu direkt karaktere atan�r
									//bundan kurtulman�n bir�ok y�ntemi oldu�u gibi, uygulanabilecek bir y�ntem de "do while" d�ng�s� �eklinde de�er almakt�r 
		printf("\n");				//ben daha bir �ey girmeden, ilk de�er '\n' (NULL) gelece�inden, d�ng�n�n ikinci �al��mas�nda do�ru de�er atanacakt�r
	} while(devam_mi=='E' || devam_mi=='e');	//char de�i�kenim E veya e oldu�u s�rece d�ng� devam edecek
}

   switch case'te g�rd���m�z "break" komutu case'lerdeki kullan�m�na benzer bir �ekilde istedi�im zaman d�ng�den ��kmak, k�saca d�ng�y� k�rmak i�in kullan�l�r

   0 ila 99 aras�nda tesad�fi say�lar �reten bir program�n, ka��nc� seferde 61 say�s�n� bulaca��na bakal�m

int main() {
	int i,tesadufi_sayi;
	int deneme_sayisi=0;	//bu sat�rdaki de�i�ken saya� gibi davranacak
	while(1) {		//while i�inde 1 (true) oldu�undan sonsuza kadar d�ng� �al���r
		tesadufi_sayi=rand()%100;	//rand() fonksiyonu random (rastgele) bir say� atar, tabii (mod 100)'de i�lem yapt���m�z i�in asl�nda atanan say�lar 0 ila 99 aras�ndad�r
		deneme_sayisi++;			//e�er mod operat�r�n� kullanmasayd�k bu sefer -(2^31-1) ila 2^31-1 aras�nda rastgele bir de�er atanabilirdi
		if(tesadufi_sayi==61)
			break;
	}
	printf("Toplam deneme sayisi: %d\n",deneme_sayisi);		//��kt�m her seferinde "15" olacak
}

   break komutunun d�ng�y� k�rmak i�in oldu�undan bahsetmi�tim		bunun d���nda i�lem yapmadan d�ng�y� devam ettirmek gibi durumlar i�inde continue (devam) komutunu kullan�l�r

   1 ila 200 aras�ndaki tek say�lar� yazd�ral�m */

int main() {
	int i;
	for(i=1;i<200;i++) {
		if(i%2==0)		//i de�i�keninin 2'ye g�re modu 0 sonucunu veriyorsa, bu onun bir �ift say� oldu�unu g�sterir. Bu durumda ekrana YAZDIRILMAMASI i�in d�ng� bir sonraki ad�ma ge�er
			continue;	//ba�ka bir deyi�le i'nin (mod 2)'deki de�eri 0 ise alttaki printf fonksiyonu okunmaz, onun yerine d�ng� scope sonuna gelmi� say�l�r ve bir sonraki i de�erine ge�er
		printf("%3d\n",i);
	}		//demek ki break komutu d�ng�den komple ��k�p geri kalan hi� bir ad�m� okumamak i�in kullan�l�rken
}			//continue komutu ise d�ng�de o ad�m�n devam�nda yer alan/geri kalan kod blo�unu es ge�erek/okumadan bir sonraki ad�ma ge�meyi sa�lar
