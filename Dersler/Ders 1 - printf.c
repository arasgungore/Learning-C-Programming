#include <stdio.h>
#include <stdlib.h>

/* "printf: print formatted"
   yazdýrma komutu olarak kullanýlan printf fonksiyonunun syntax'ý aç parantez týrnak týrnak kapa parantez ===>  printf("")         týrnaklarý unutma
   "\n: newline , yeni satýr"		printf içinde bir alt satýra geçmek için kullanýlýr
   "\t: tab , satýr boþluðu"		printf içinde uzunca bir boþluk koymak ve karakterleri ayný düþey hizaya getirmek için kullanýlýr
   "\b: backspace , geri tuþu"		printf içinde önceden yazdýrýlmýþ bir karakteri silmek ya da konsol imlecini bir karakter geri almak için kullanýlýr
   "\": çift týrnak"
   "\\: ters slash"			bu 2 karakter printf'in týrnak iþareti ve escape sequence'larýn ters slash'ý ile karýþmamasý için baþýna fazladan bir ters slash iþareti konarak yazýlmalýdýrlar
   "%%: yüzde iþareti"      bu karakter ise belirteçlerin (specifier) yüzde iþareti ile karýþmamasý için baþýna fazladan bir yüzde iþareti daha konarak yazýlmalýdýr
   kod yazarken her satýra bir yargý (statement) yazýlýr ve her statement ise ; ile biter

   int main() {

   return 0;
   }			her kod bu klasik "int main() { }" kalýbýnýn içine yazýlýr
				"return 0;" olmasa da olur, bu ifade main fonksiyonunun 0 deðeri döndürüp bittiðini gösterir; ama warning vermemesi için genelde her kod return 0 ile biter
   sonda "return 0" koymayacaksak "int main()" yerine "void main()" de yazabiliriz, ama biz hep "int main()" kullanacaðýz


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
	printf("%s guzellik, %s mi?", "Selam", "tanisalim");	//"%s" belirteci ile printf'te belirteci koyduðum yerlere sýrayla istediðim string'leri yazdýrabilirim
	printf("\n%d+%d=%d\n",2,3,2+3);							//"%d" belirteci ile printf'te belirteci koyduðum yerlere istediðim tam sayýlarý yazdýrabilirim
	printf( 3<5 ? "Uc besten kucuktur\n\n" : "Uc besten buyuktur\n\n");	//kosul ? "kosul dogruysa beni yazdir" : "kosul yanlissa beni yazdir" syntax'ý ile koþula baðlý olarak alternatif 2 þey yazdýrabilirim   (if else)

	printf(" katarinin uzunlugu: %d", printf("Hello World"));	//aslýnda printf fonksiyonu konsola yazdýracaðý string'in karakter sayýsýný return'ler
																//yani strlen("Hello World")=11 olduðundan çýktým "11", ama ondan önce function call yapýldýðý için "Hello World" de print'ler

	int x=10;
	printf("\n\n\n");
	printf("%d",x);			//"10" yazdýrýr,     çýktým "10"
	printf("\n");
	printf("%d",printf("%d",x));	//bu yüzden ilk "10" yazdýrýr, sonra da printf("%d",x) 2 döndüreceði için "2" yazdýrýr,     çýktým "102"
	printf("\n");
	printf("%d",printf("%d",printf("%d",x)));	//ilk "10" yazdýrýr, sonra "10"un karakter sayýsý olan "2", en son da "2"nin karakter sayýsý "1" yazdýrýr,     çýktým "1021"
	printf("\n");
	printf("%d",printf("%d",printf("%d",printf("%d",x))));	//çýktým "10211"
	printf("\n\n\n");

	printf("%d",printf("%d",printf("%d",printf("%s","ILOVECPROGRAMMING"))));	//"ILOVECPROGRAMMING"in uzunluðu 17, 17'nin uzunluðu 2, 2'nin uzunluðu 1,     çýktým "ILOVECPROGRAMMING1721"

	printf("\n\n\nAmini sikeyim Dunya\n\n");

	return 0;
}
