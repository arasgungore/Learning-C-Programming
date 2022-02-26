#include <stdio.h>
#include <stdlib.h>

/* "&: ampersand , adres operat�r� , ve operat�r� (bitsel operat�r) , gemici d���m�"
   klavyeyle veri girerken kulland���m�z scanf fonksiyonunun i�inde int de�i�keni kullan�rken adres operat�r� olarak "&" i�aretini kullan�yoruz
   ileride g�rece�iz ama scanf fonksiyonu veri i�in ayr�lan adrese (&degiskenadi) klavyeden girilen veriyi koyar
   dolay�s�yla string'ler (char degiskenadi[]) i�in scanf syntax'� scanf("%s",degiskenadi) iken char,int,float,double de�i�kenleri i�in scanf syntax'� scanf("%c/%d/%f/%lf",&degiskenadi) oluyor
   yani fazladan & koymay� unutma   (printf'te & koymaya gerek yok, e�er & koyarsan bu sefer de�i�kenin de�erini de�il de�i�kenin RAM'de sakland��� adresi yazd�r�r)

int main() {

	int sayi;
	printf("Lutfen Sayi Giriniz: ");
	scanf("%d",&sayi);
	printf("Girmis Oldugunuz Sayi: %d",sayi);
}

   misal ger�ek bir hesap makinesi kullan�c�dan verileri al�r

int main() {

	int sayi1,sayi2,topla,cikar,carp,bol;

	printf("Birinci sayiyi giriniz: ");
	scanf("%d",&sayi1);

	printf("Ikinci sayiyi giriniz: ");
	scanf("%d",&sayi2);

	topla=sayi1+sayi2;
	cikar=sayi1-sayi2;
	carp=sayi1*sayi2;
	bol=sayi1/sayi2;

	printf("\n*************************\n\n");
	printf("Girdiginiz sayilarin,\na) Toplami: %d\nb) Farki: %d\nc) Carpimi: %d\nd) Bolumu: %d",topla,cikar,carp,bol);
} */

int main() {

	int su,kola,bilet,misir,toplam;

	printf("Misir Adeti: ");
	scanf("%d",&misir);
	printf("Kola Adeti: ");
	scanf("%d",&kola);
	printf("Su Adeti: ");
	scanf("%d",&su);
	printf("Bilet Adeti: ");
	scanf("%d",&bilet);

	toplam=2*su+4*kola+5*misir+15*bilet;   //bu sinemada m�s�r 5 TL, kola 4 TL, su 2 TL, bilet ise 15 TL
	printf("\n*********************************\n\nToplam Borcunuz %d TL'dir. Iyi gunler dileriz.",toplam);

	return 0;
}
