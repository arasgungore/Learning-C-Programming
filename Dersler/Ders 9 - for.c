#include <stdio.h>
#include <stdlib.h>

/* "for: for loop , i�in d�ng�s�"
   for d�ng�s�n�n syntax'� for a� parantez kapa parantez a� s�sl� parantez kapa s�sl� parantez bi�imindedir
   yani for() {
   }                 (if ile bu bak�mdan benzer syntax'a sahip)
   parantez i�ine s�ras�yla ba�lang��, biti� ve art�� miktar� yaz�l�rken scope'un i�ine parantez i�indeki ko�ul aral���ndaki her bir de�er i�in tekrar tekrar uygulanacak komut yaz�l�r
   ba�ka bir deyi�le for(i=baslangic;i<=bitis;i+=artis miktari) { }
   ; ile ay�rmay� unutma!!
   "i: iterator , yineleyici"         "i+=: art�� miktar�"         "i-=: azal�� miktar�"         (i++ ile i+=1 ayn� �ey, birer birer art�yor demek ikisi de)

int main() {													int main() {

	int i;															int j;
	for(i=1;i<=10;i++)												for(j=0;j<=50;j++) {
	{																	printf("%d\n",j);
		printf("Merhaba Balikesir\n");								}
	}															}       //0'dan 50'ye kadar olan tam say�lar� yazd�racak
}       //10 defa "Merhaba Balikesir" yazd�racak

int main() {																								int main() {

	int sayi;																									int c;
	sayi=5;																										for(c=0;c<=20;c+=3) {
	sayi++;																											printf("%d\n",c);
	printf("%d",sayi);																							}
}       //"6" yazd�racak direkt, e�er sayi+=2 veya sayi+=10 olsayd� s�ras�yla "7" ve "15" yazd�r�rd�		}       \\"0 3 6 9 12 15 18"


int main() {																			
	int sex;																				//"69 - Amini Sikeyim Dunya
	for(sex=69;sex>=31;sex-=4) {   //for(sex=31;sex<=69;sex+=4)nin tersteni 				//65 - Amini Sikeyim Dunya
		printf("%d - Amini Sikeyim Dunya\n",sex);											//61 - Amini Sikeyim Dunya
	}																					 //...31 - Amini Sikeyim Dunya"
}																							//printf'e %d eklemeseydik s�ras�yla 69,65,61,...,31 aral���ndaki her bir de�er i�in Amini Sikeyim Dunya yazd�rd���n�
   																							//daha iyi goremezdik ;)
*/

int main() {

	int k;
	for(k=-69;k<=69;k+=2)
	{
		printf("%d: sikis sokus\n",k);
	}
}
