#include <stdio.h>
#include <stdlib.h>

/* "printf: print formatted"
   yazd�rma komutu olarak kullan�lan printf fonksiyonunun syntax'� a� parantez t�rnak t�rnak kapa parantez ===>  printf("")         t�rnaklar� unutma
   "\n: newline , yeni sat�r"		printf i�inde bir alt sat�ra ge�mek i�in kullan�l�r
   "\t: tab , sat�r bo�lu�u"		printf i�inde uzunca bir bo�luk koymak ve karakterleri ayn� d��ey hizaya getirmek i�in kullan�l�r
   "\b: backspace , geri tu�u"		printf i�inde �nceden yazd�r�lm�� bir karakteri silmek ya da konsol imlecini bir karakter geri almak i�in kullan�l�r
   "\": �ift t�rnak"
   "\\: ters slash"			bu 2 karakter printf'in t�rnak i�areti ve escape sequence'lar�n ters slash'� ile kar��mamas� i�in ba��na fazladan bir ters slash i�areti konarak yaz�lmal�d�rlar
   "%%: y�zde i�areti"      bu karakter ise belirte�lerin (specifier) y�zde i�areti ile kar��mamas� i�in ba��na fazladan bir y�zde i�areti daha konarak yaz�lmal�d�r
   kod yazarken her sat�ra bir yarg� (statement) yaz�l�r ve her statement ise ; ile biter

   int main() {

   return 0;
   }			her kod bu klasik "int main() { }" kal�b�n�n i�ine yaz�l�r
				"return 0;" olmasa da olur, bu ifade main fonksiyonunun 0 de�eri d�nd�r�p bitti�ini g�sterir; ama warning vermemesi i�in genelde her kod return 0 ile biter
   sonda "return 0" koymayacaksak "int main()" yerine "void main()" de yazabiliriz, ama biz hep "int main()" kullanaca��z


int main() {

	printf("Hello World");

	return 0;
}

int main() {

	printf("********** Ogrenci Bilgi **********\n\n");
	printf("Isim: Aras\n");
	printf("Soyad: Gungore\n");
	printf("Ogrenci No: 2018401117\n");
	printf("Dogum Tarihi: 11/09/2000\n\n");
	printf("***********************************");

	return 0;
} */

int main() {

	printf("Abla n'olur\b ben\bi silme\b\b\b   \n");		//2. kelimenin son harfi, 3. kelimenin 3. harfi, ve son kelimenin sondan 3 harfi silindi
	printf("%s guzellik, %s mi?", "Selam", "tanisalim");	//"%s" belirteci ile printf'te belirteci koydu�um yerlere s�rayla istedi�im string'leri yazd�rabilirim
	printf("\n%d+%d=%d\n",2,3,2+3);							//"%d" belirteci ile printf'te belirteci koydu�um yerlere istedi�im tam say�lar� yazd�rabilirim
	printf( 3<5 ? "Uc besten kucuktur\n\n" : "Uc besten buyuktur\n\n");	//kosul ? "kosul dogruysa beni yazdir" : "kosul yanlissa beni yazdir" syntax'� ile ko�ula ba�l� olarak alternatif 2 �ey yazd�rabilirim   (if else)

	printf(" katarinin uzunlugu: %d", printf("Hello World"));	//asl�nda printf fonksiyonu konsola yazd�raca�� string'in karakter say�s�n� return'ler
																//yani strlen("Hello World")=11 oldu�undan ��kt�m "11", ama ondan �nce function call yap�ld��� i�in "Hello World" de print'ler

	int x=10;
	printf("\n\n\n");
	printf("%d",x);			//"10" yazd�r�r,     ��kt�m "10"
	printf("\n");
	printf("%d",printf("%d",x));	//bu y�zden ilk "10" yazd�r�r, sonra da printf("%d",x) 2 d�nd�rece�i i�in "2" yazd�r�r,     ��kt�m "102"
	printf("\n");
	printf("%d",printf("%d",printf("%d",x)));	//ilk "10" yazd�r�r, sonra "10"un karakter say�s� olan "2", en son da "2"nin karakter say�s� "1" yazd�r�r,     ��kt�m "1021"
	printf("\n");
	printf("%d",printf("%d",printf("%d",printf("%d",x))));	//��kt�m "10211"
	printf("\n\n\n");

	printf("%d",printf("%d",printf("%d",printf("%s","ILOVECPROGRAMMING"))));	//"ILOVECPROGRAMMING"in uzunlu�u 17, 17'nin uzunlu�u 2, 2'nin uzunlu�u 1,     ��kt�m "ILOVECPROGRAMMING1721"

	printf("\n\n\nAmini sikeyim Dunya\n\n");

	return 0;
}
