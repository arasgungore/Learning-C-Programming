#include <stdio.h>
#include <stdlib.h>

/* "char: character"
   adı üzerinde, char değişkenine sadece ama sadece BİR tane karakter atayabilirim   (karakterimin harf, rakam, noktalama işareti, hatta boşluk olması bile fark etmez, zira hepsi karakter ;))
   ama biz standart char syntax'ı olan char değişkenadı eşittir tek tırnak tek tırnak ==> char degiskenadi='' ile pek ilgilenmeyeceğiz
   char değişkeninin daha geniş syntax'ı char değişkenadı aç köşeli parantez kapa köşeli parantez eşittir tırnak tırnak =====>  char degiskenadi[]=""
   normalde char degiskenadi biçimindeki char değişkenlerine sadece bir tane karakter atanabilir ama char degiskenadi[] biçiminde yazarsam buna çok karakterli değerler (string) de atayabilirim

   köşeli parantez içine yazılan sayı string'imizin karakter sınırını (barındırabileceği maksimum karakter sayısını) belirler     (Twitter gibi: 1 mesaj 140 karakter)
   eğer karakter sınırını aşarsam yazdığım şeyin karakter sınırını aştıktan sonraki kısmını bilgisayar almaz
   aşmazsam da boş kalan kapasiteyi bilgisayar "null" olarak girer        (aslında direkt char degiskenadi="" olarak da girebilir, bilgisayar kapasiteyi önceden kendi belirliyor zaten)
   zaten derleyici ona göre warning (uyarı) veriyor

   printf içinde char değişkenini ifade etmek "%c: character", char dizilerini ifade etmek için ise "%s: string" belirteci kullanılır
   özetle; char degiskenadi[] syntax'ı ile çift tırnak içine karakter sınırını aşmayan herhangi bir string yazılabilirken, standart char degiskenadi syntax'ı ile tek tırnak içine sadece tek bir karakter yazılabilir
   sondaki noktalı virgülleri unutma amcık

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
