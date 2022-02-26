#include <stdio.h>
#include <stdlib.h>

/* "array: dizi"
   ortak bir �zelli�i olan belli say�daki elemanlar�n olu�turdu�u s�ral� listelere "array" (dizi) ad� verilir
   ayn� matematikteki k�meler gibi, diziler �gelerden olu�ur ve s�sl� parantez i�inde g�sterilir
   bir dizinin syntax'� de�i�ken de�i�kenad� a� k��eli parantez elemansay�s� kapa k��eli parantez e�ittir a� s�sl� parantez kapa k��eli parantez
   yani degisken degiskenadi[]={ } idir      (misal char sehirler[5][10]={'ankara','bursa','istanbul','kayseri','trabzon'} veya int sayilar[10]={3,6,5,4,1,7,9,2,8,0})
   k��eli parantez i�ine dizinin eleman say�s�, scope i�ine ise elemanlar� yaz�l�r

   "index: adres , eleman s�ras�"         "bilgisayar 0'dan saymaya ba�lar" ifadesi index i�in ge�erlidir, ��nk� index'in ba�lang�� de�eri DA�MA 0'd�r
   mesela dizimiz int sayilar[]={13,456,3169,2,42,888} ise bilgisayar bu diziyi belle�e ��yle kodlar:

   index(adres):		0		1		2		3		4		5
   array(veri):			13		456		3169	2		42		888

   dizinin elemanlar� tekrar k��eli parantez i�ine eleman�n index'i (dizide ka��nc� s�rada yer ald���) yaz�larak belirtilebilir   (int ciftsayilar[]={2,4,6,8,10} ==> ciftsayilar[2]=6)
   dizi yazarken i�ini bo� b�raksan dahi k��eli parantez yazmay� unutma

int main() {

	int tekrakamlar[]={1,3,5,7,9};
	printf("%d",tekrakamlar[2]);	//5 yazd�racak ��nk� 2. indekste 5 var
}

int main() {

	char baskent[]={'A','n','k','a','r','a'};
	printf("%s",baskent);		//"Ankara" yazd�racak ��nk� t�m k�menin elemanlar� onu olu�turuyor
								//e�er printf("%s",baskent[1]) olursa �al��maz ama printf("%c",baskent[1]) olursa bilgisayar "n" yazd�r�r		(��nk� string: char array'i demek)
}								//son olarak k��eli parantez i�ini bo� b�rakt�m, eleman say�s� 6 oldu�undan i�ine 6 yazmak bir �eyi etkilemezdi
								//ama k��eli parantez i�ine 4 yazsayd�m "Anka" yazd�r�rd�, ��nk� A,n,k,a elemanlar� kodun kendisi i�in ona ay�rd��� yeri doldurdu�u i�in r ve a alg�lanmazd�   bkz. Ders 2

   scope i�ine elemanlar� yazmadan da amele gibi tek tek yazabiliriz :P

int main() {
	int sayilar[4];
	sayilar[0]=23;
	sayilar[1]=895;
	sayilar[2]=774;
	sayilar[3]=109;				//int sat�r�ndaki [4] onun eleman say�s�n�, sonraki [0],[1],[2],[3] ise o 4 eleman�n index'lerini belirtiyor
	
	printf("%d",sayilar[2]);	//do�al olarak "774" yazd�racak
}

   diziyi listeleyelim															listelemek s�k�c�, diziyi toplayal�m

int main() {																		int main() {

	int i;																				int dizi[]={5,10,15,20,25};
	int yarrak[]={8,22,14,16,10,2,34};													int i,toplam;
	for(i=0;i<7;i++) {																	toplam=0;
		printf("%d ",yarrak[i]);														printf("Dizi: ");
	}																					for(i=0;i<5;i++) {
	return 0;		//"8 22 14 16 10 2 34", burada i=index olmu� oldu ;)					toplam=toplam+dizi[i];	//diziyi toplayan komut						
}																							printf("%d ",dizi[i]);	//diziyi yazd�ran komut, bu komutlar� dizinin t�m elemanlara uygulamak istedi�im i�in d�ng�deler
																						}
   																						printf("\n\nDizi Toplami: %d",toplam);
   																					}

   3 elemanl� bir dizinin elemanlar�n� klavyeyle belirleyip diziyi bilgisayara yazd�ral�m

int main() {
	char sehir[3][15];				//1. k��eli parantez eleman say�s�n�, 2. k��eli parantez ise yazaca��m elemanlar�n karakter s�n�r�n� belirliyor
	int i;							//ba�ka bir deyi�le de bunu 2 boyutlu dizi gibi d���n�rsek sat�r say�s�na �ehir say�s�, s�t�n say�s�na da �ehrin harf boyutu girildi
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
	char gunler[7][10]={"Pazartesi","Sali","Carsamba","Persembe","Cuma","Cumartesi","Pazar"};	//Girdi�im veriler char de�il string oldu�u i�in tek t�rnak de�il �ift t�rnak kulland�m
	for(i=0;i<7;i++) {
		printf("%s haftanin %d. gunudur.\n",gunler[i],i+1);
	}
}

   bilgisayar default olarak n elemanl� bir array'e index'leri 0, 1, 2, ..., n-1 diye atasa da buna ayk�r� olarak istisnaden elemanlara rastgele index'ler de atayabilirim
   �iddetle tavsiye etmesem de, e�er �ans�ma sallad���m index'ler i�in RAM'de yer varsa ve program �al���rsa elemanlara g�t�mden index verebilirim

int main() {
	int dizi[4];
	dizi[17]=9;
	dizi[38]=31;
	dizi[96]=135;
	dizi[41]=69;
	printf("%d %d %d %d",dizi[17],dizi[38],dizi[96],dizi[41]);	//�al���rsa "9 31 135 69"
}

   Son olarak da kendi girece�imiz dinamik dizinin dinamik ortalamas�n� yazd�ral�m */

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
