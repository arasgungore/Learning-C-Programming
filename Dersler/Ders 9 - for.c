#include <stdio.h>
#include <stdlib.h>

/* "for: for loop , için döngüsü"
   for döngüsünün syntax'ý for aç parantez kapa parantez aç süslü parantez kapa süslü parantez biçimindedir
   yani for() {
   }                 (if ile bu bakýmdan benzer syntax'a sahip)
   parantez içine sýrasýyla baþlangýç, bitiþ ve artýþ miktarý yazýlýrken scope'un içine parantez içindeki koþul aralýðýndaki her bir deðer için tekrar tekrar uygulanacak komut yazýlýr
   baþka bir deyiþle for(i=baslangic;i<=bitis;i+=artis miktari) { }
   ; ile ayýrmayý unutma!!
   "i: iterator , yineleyici"         "i+=: artýþ miktarý"         "i-=: azalýþ miktarý"         (i++ ile i+=1 ayný þey, birer birer artýyor demek ikisi de)

int main() {													int main() {

	int i;															int j;
	for(i=1;i<=10;i++)												for(j=0;j<=50;j++) {
	{																	printf("%d\n",j);
		printf("Merhaba Balikesir\n");								}
	}															}       //0'dan 50'ye kadar olan tam sayýlarý yazdýracak
}       //10 defa "Merhaba Balikesir" yazdýracak

int main() {																								int main() {

	int sayi;																									int c;
	sayi=5;																										for(c=0;c<=20;c+=3) {
	sayi++;																											printf("%d\n",c);
	printf("%d",sayi);																							}
}       //"6" yazdýracak direkt, eðer sayi+=2 veya sayi+=10 olsaydý sýrasýyla "7" ve "15" yazdýrýrdý		}       \\"0 3 6 9 12 15 18"


int main() {																			
	int sex;																				//"69 - Amini Sikeyim Dunya
	for(sex=69;sex>=31;sex-=4) {   //for(sex=31;sex<=69;sex+=4)nin tersteni 				//65 - Amini Sikeyim Dunya
		printf("%d - Amini Sikeyim Dunya\n",sex);											//61 - Amini Sikeyim Dunya
	}																					 //...31 - Amini Sikeyim Dunya"
}																							//printf'e %d eklemeseydik sýrasýyla 69,65,61,...,31 aralýðýndaki her bir deðer için Amini Sikeyim Dunya yazdýrdýðýný
   																							//daha iyi goremezdik ;)
*/

int main() {

	int k;
	for(k=-69;k<=69;k+=2)
	{
		printf("%d: sikis sokus\n",k);
	}
}
