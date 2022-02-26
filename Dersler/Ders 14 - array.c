#include <stdio.h>
#include <stdlib.h>

/* "array: dizi"
   ortak bir özelliði olan belli sayýdaki elemanlarýn oluþturduðu sýralý listelere "array" (dizi) adý verilir
   ayný matematikteki kümeler gibi, diziler ögelerden oluþur ve süslü parantez içinde gösterilir
   bir dizinin syntax'ý deðiþken deðiþkenadý aç köþeli parantez elemansayýsý kapa köþeli parantez eþittir aç süslü parantez kapa köþeli parantez
   yani degisken degiskenadi[]={ } idir      (misal char sehirler[5][10]={'ankara','bursa','istanbul','kayseri','trabzon'} veya int sayilar[10]={3,6,5,4,1,7,9,2,8,0})
   köþeli parantez içine dizinin eleman sayýsý, scope içine ise elemanlarý yazýlýr

   "index: adres , eleman sýrasý"         "bilgisayar 0'dan saymaya baþlar" ifadesi index için geçerlidir, çünkü index'in baþlangýç deðeri DAÝMA 0'dýr
   mesela dizimiz int sayilar[]={13,456,3169,2,42,888} ise bilgisayar bu diziyi belleðe þöyle kodlar:

   index(adres):		0		1		2		3		4		5
   array(veri):			13		456		3169	2		42		888

   dizinin elemanlarý tekrar köþeli parantez içine elemanýn index'i (dizide kaçýncý sýrada yer aldýðý) yazýlarak belirtilebilir   (int ciftsayilar[]={2,4,6,8,10} ==> ciftsayilar[2]=6)
   dizi yazarken içini boþ býraksan dahi köþeli parantez yazmayý unutma

int main() {

	int tekrakamlar[]={1,3,5,7,9};
	printf("%d",tekrakamlar[2]);	//5 yazdýracak çünkü 2. indekste 5 var
}

int main() {

	char baskent[]={'A','n','k','a','r','a'};
	printf("%s",baskent);		//"Ankara" yazdýracak çünkü tüm kümenin elemanlarý onu oluþturuyor
								//eðer printf("%s",baskent[1]) olursa çalýþmaz ama printf("%c",baskent[1]) olursa bilgisayar "n" yazdýrýr		(çünkü string: char array'i demek)
}								//son olarak köþeli parantez içini boþ býraktým, eleman sayýsý 6 olduðundan içine 6 yazmak bir þeyi etkilemezdi
								//ama köþeli parantez içine 4 yazsaydým "Anka" yazdýrýrdý, çünkü A,n,k,a elemanlarý kodun kendisi için ona ayýrdýðý yeri doldurduðu için r ve a algýlanmazdý   bkz. Ders 2

   scope içine elemanlarý yazmadan da amele gibi tek tek yazabiliriz :P

int main() {
	int sayilar[4];
	sayilar[0]=23;
	sayilar[1]=895;
	sayilar[2]=774;
	sayilar[3]=109;				//int satýrýndaki [4] onun eleman sayýsýný, sonraki [0],[1],[2],[3] ise o 4 elemanýn index'lerini belirtiyor
	
	printf("%d",sayilar[2]);	//doðal olarak "774" yazdýracak
}

   diziyi listeleyelim															listelemek sýkýcý, diziyi toplayalým

int main() {																		int main() {

	int i;																				int dizi[]={5,10,15,20,25};
	int yarrak[]={8,22,14,16,10,2,34};													int i,toplam;
	for(i=0;i<7;i++) {																	toplam=0;
		printf("%d ",yarrak[i]);														printf("Dizi: ");
	}																					for(i=0;i<5;i++) {
	return 0;		//"8 22 14 16 10 2 34", burada i=index olmuþ oldu ;)					toplam=toplam+dizi[i];	//diziyi toplayan komut						
}																							printf("%d ",dizi[i]);	//diziyi yazdýran komut, bu komutlarý dizinin tüm elemanlara uygulamak istediðim için döngüdeler
																						}
   																						printf("\n\nDizi Toplami: %d",toplam);
   																					}

   3 elemanlý bir dizinin elemanlarýný klavyeyle belirleyip diziyi bilgisayara yazdýralým

int main() {
	char sehir[3][15];				//1. köþeli parantez eleman sayýsýný, 2. köþeli parantez ise yazacaðým elemanlarýn karakter sýnýrýný belirliyor
	int i;							//baþka bir deyiþle de bunu 2 boyutlu dizi gibi düþünürsek satýr sayýsýna þehir sayýsý, sütün sayýsýna da þehrin harf boyutu girildi
	for(i=0;i<3;i++) {
		printf("%d. sehiri girin: ",i+1);
		scanf("%s",sehir[i]);
	}
	printf("Girdiginiz sehir isimleri: ");
	for(i=0;i<3;i++) {
		printf("%s ",sehir[i]);
	}
}

int main() {
	int i;
	char gunler[7][10]={"Pazartesi","Sali","Carsamba","Persembe","Cuma","Cumartesi","Pazar"};	//Girdiðim veriler char deðil string olduðu için tek týrnak deðil çift týrnak kullandým
	for(i=0;i<7;i++) {
		printf("%s haftanin %d. gunudur.\n",gunler[i],i+1);
	}
}

   bilgisayar default olarak n elemanlý bir array'e index'leri 0, 1, 2, ..., n-1 diye atasa da buna aykýrý olarak istisnaden elemanlara rastgele index'ler de atayabilirim
   þiddetle tavsiye etmesem de, eðer þansýma salladýðým index'ler için RAM'de yer varsa ve program çalýþýrsa elemanlara götümden index verebilirim

int main() {
	int dizi[4];
	dizi[17]=9;
	dizi[38]=31;
	dizi[96]=135;
	dizi[41]=69;
	printf("%d %d %d %d",dizi[17],dizi[38],dizi[96],dizi[41]);	//çalýþýrsa "9 31 135 69"
}

   Son olarak da kendi gireceðimiz dinamik dizinin dinamik ortalamasýný yazdýralým */

int main() {

	float dizi[100];
	int i,x;
	float toplam=0,ort;
	printf("Eleman Sayisi: ");
	scanf("%d",&x);

	for(i=0;i<x;i++){
		printf("%d. Elemani: ",i+1);
		scanf("%f",&dizi[i]);
		toplam=toplam+dizi[i];
	}

	printf("\nDizi: ");
	for(i=0;i<x;i++){
		printf("%f ",dizi[i]);
	}

	ort=toplam/x;
	printf("\nToplam: %f\nOrtalama: %f",toplam,ort);
}
