#include <stdio.h>
#include <stdlib.h>

/* "scanf: scan formatted"
   normalde printf fonksiyonunda yazd�r�lacak veriyi kodun i�ine haz�r olarak yaz�yorduk
   bu sefer veriyi (misal de�i�kenin de�erini) �al��t�r kutusunda biz yaz�yoruz
   b�ylelikle istedi�imiz de�erleri de�i�kene atayabiliriz
   scanf a� parantez t�rnak t�rnak kapa parantez virg�l de�i�kenadi ==> scanf("",degiskenadi)       printf ile ayn� syntax'a (yaz�m kurallar�na) sahip aq
   scanf fonksiyonunun tek s�k�nt�s� bo�lu�u ve ondan sonra gelen verileri alg�lamamas�
   scanf'in i�ine daima %s,%c,%d,%f... belirte�leri filan yaz�l�r, de�i�kenine g�re bunlar� girmeyi unutma

int main() {

	char kitapad[31];
	printf("Kitabin Adini Giriniz: ");
	scanf("%s",kitapad);			//misal ben "Fareler ve Insanlar" yazsam (yani kitapad[31]="Fareler ve Insanlar" olur char de�i�kenim) �al��t�r'da ��kt�m "Fareler" olurdu
	printf("Girmis Oldugunuz Kitap: %s",kitapad);

}

   scanf'in bo�luktan sonraki verileri de alg�lamas� i�in �zel olarak "%[^\n]%*c" kal�b� kullan�l�r
   detaya girecek olursak "^\n" yeni bir sat�ra (newline) ge�meden �nceki b�t�n girdileri (karakterleri) belle�e al
   "%*c" ise yeni sat�rdaki ilk karakteri al ve onu discard et (bellekten at) demek

int main() {

	char kitapad[100];
	scanf("%[^\n]",kitapad);		//alternatif olarak bu koda ama "Fareler ve Insanlar" yazarsam ��kt�m "Fareler ve Insanlar" olur
	printf("Girdiginiz kitabin tam adi: %s",kitapad);

}

   tabii scanf("%[^\n]%*c",degiskenadi) kal�b� her zaman �al��maz ��nk� bu statement kendisinden bir �nceki sat�rdaki newline karakterini de okuyabilir
   o y�zden bu kal�p scanf("\n%[^\n]%*c",degiskenadi) veya scanf(" %[^\n]%*c",degiskenadi) syntax'lar� ile kullan�l�r

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
