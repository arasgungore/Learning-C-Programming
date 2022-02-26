#include <stdio.h>
#include <stdlib.h>

/* "&: ampersand , adres operatörü , ve operatörü (bitsel operatör) , gemici düðümü"
   klavyeyle veri girerken kullandýðýmýz scanf fonksiyonunun içinde int deðiþkeni kullanýrken adres operatörü olarak "&" iþaretini kullanýyoruz
   ileride göreceðiz ama scanf fonksiyonu veri için ayrýlan adrese (&degiskenadi) klavyeden girilen veriyi koyar
   dolayýsýyla string'ler (char degiskenadi[]) için scanf syntax'ý scanf("%s",degiskenadi) iken char,int,float,double deðiþkenleri için scanf syntax'ý scanf("%c/%d/%f/%lf",&degiskenadi) oluyor
   yani fazladan & koymayý unutma   (printf'te & koymaya gerek yok, eðer & koyarsan bu sefer deðiþkenin deðerini deðil deðiþkenin RAM'de saklandýðý adresi yazdýrýr)

int main() {

	int sayi;
	printf("Lutfen Sayi Giriniz: ");
	scanf("%d",&sayi);
	printf("Girmis Oldugunuz Sayi: %d",sayi);
}

   misal gerçek bir hesap makinesi kullanýcýdan verileri alýr

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

	toplam=2*su+4*kola+5*misir+15*bilet;   //bu sinemada mýsýr 5 TL, kola 4 TL, su 2 TL, bilet ise 15 TL
	printf("\n*********************************\n\nToplam Borcunuz %d TL'dir. Iyi gunler dileriz.",toplam);

	return 0;
}
