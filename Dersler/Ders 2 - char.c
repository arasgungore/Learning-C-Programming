#include <stdio.h>
#include <stdlib.h>

/* "char: character"
   ad� �zerinde, char de�i�kenine sadece ama sadece B�R tane karakter atayabilirim   (karakterimin harf, rakam, noktalama i�areti, hatta bo�luk olmas� bile fark etmez, zira hepsi karakter ;))
   ama biz standart char syntax'� olan char de�i�kenad� e�ittir tek t�rnak tek t�rnak ==> char degiskenadi='' ile pek ilgilenmeyece�iz
   char de�i�keninin daha geni� syntax'� char de�i�kenad� a� k��eli parantez kapa k��eli parantez e�ittir t�rnak t�rnak =====>  char degiskenadi[]=""
   normalde char degiskenadi bi�imindeki char de�i�kenlerine sadece bir tane karakter atanabilir ama char degiskenadi[] bi�iminde yazarsam buna �ok karakterli de�erler (string) de atayabilirim

   k��eli parantez i�ine yaz�lan say� string'imizin karakter s�n�r�n� (bar�nd�rabilece�i maksimum karakter say�s�n�) belirler     (Twitter gibi: 1 mesaj 140 karakter)
   e�er karakter s�n�r�n� a�arsam yazd���m �eyin karakter s�n�r�n� a�t�ktan sonraki k�sm�n� bilgisayar almaz
   a�mazsam da bo� kalan kapasiteyi bilgisayar "null" olarak girer        (asl�nda direkt char degiskenadi="" olarak da girebilir, bilgisayar kapasiteyi �nceden kendi belirliyor zaten)
   zaten derleyici ona g�re warning (uyar�) veriyor

   printf i�inde char de�i�kenini ifade etmek "%c: character", char dizilerini ifade etmek i�in ise "%s: string" belirteci kullan�l�r
   �zetle; char degiskenadi[] syntax'� ile �ift t�rnak i�ine karakter s�n�r�n� a�mayan herhangi bir string yaz�labilirken, standart char degiskenadi syntax'� ile tek t�rnak i�ine sadece tek bir karakter yaz�labilir
   sondaki noktal� virg�lleri unutma amc�k

int main() {									int main() {								int main() {

	char kitapad[20]="Mufettis";					char kitaptur[14]="Tiyatro Kitabi";			char ad[20]="Kanadi Kirik Kuslar";
	char kitapyazar[10]="Gogol";					printf("Kitap Turu: %s",kitaptur);			char yazar[15]="Ayse Kulin";
																								char tur[10]="Roman";
	printf("%s\n",kitapad);						}												char sayfa[3]="390";
	printf("%s",kitapyazar);																	char yil[4]="2017";
	
}																								printf("********** Kitap Tanitim **********\n\n");
																								printf("Kitap Adi: %s - Kitap Yazari: %s\n",ad,yazar);
																								printf("Kitap Turu: %s\n",tur);
																								printf("Sayfa Sayisi: %s\n",sayfa);
																								printf("Basim Yili: %s\n\n",yil);
																								printf("***************************************");
																										
																							}
																								
																								
   */

int main() {
	
	char arasdasdas[31]="Aras Gungore";
	char cenabet[13]="Mustafa Cihan senin ben gelmisini gecmisini";
	
	printf("%s has big pp\n",arasdasdas);
	printf("%s has small pp",cenabet);
	
	return 0;
}
