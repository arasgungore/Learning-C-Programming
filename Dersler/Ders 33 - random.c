#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* "rand: random , rastgele"     "srand: set seed in random , random fonksiyonuna tohumu yerle�tir"     "seed: tohum , srand fonksiyonunun parametresi"
   rand() fonksiyonu ad� �zerinde rastgele (!) de�erler d�nd�rmek i�in kullan�l�r

int main() {
	printf("Random fonksiyonunun dondurdugu deger: %d",rand());	//��kt� daima "41" olacak
	printf("\nRandom fonksiyonunun dondurebilecegi max deger: %d",RAND_MAX);	//RAND_MAX=SHRT_MAX=(2^15)-1="32767"
}

int main() {
	int i,j;
	printf("*****Random sayilar*****\n\n");
	for(i=1;i<=3;i++) {
		for(j=1;j<=10;j++)
			printf("%d  ",rand());	//her seferinde ayn� 30 say�y� yazd�racak
		printf("\n");
	}
}

   �ncelikle �unu s�ylemeliyim ki, yaz�l�mda hi�bir zaman ger�ek anlamda bir rastgelelik yoktur
   asl�nda olas�l�k teorisine g�re ger�ek hayatta da ger�ek anlamda bir rastgelelik yoktur   (kuantum fizi�i hari�)
   mesela bir zar att���nda zar�n ka� gelece�ini zar� at�� a��n, zar� at�� kuvvetin, zar� at�� bi�imin, �evre ko�ullar�, zar�n a��rl�k merkezi gibi bir s�r� fakt�r (parametre) belirler
   bilgisayarda ise ger�ek hayat�n rastgeleli�inden �ok da farkl� olmayarak rand fonksiyonu belli bir tohuma (seed) g�re de�er d�nd�r�r
   bilgisayardaki mevzubahis yalanc� rastgeleli�i sa�layan y�ntemlerden en pop�leri tohumu ZAMANA ba�l� olarak de�i�tirmektir
   time k�t�phanesi ile import etti�im time(NULL) fonksiyonu bana 1/1/1970 00:00:00 tarihinden bu yana ka� saniye ge�ti�ini d�nd�r�r ve bu de�er de srand fonksiyonu ile tohuma atan�r
   her ge�en saniyede time(NULL) fonksiyonu farkl� bir de�er (tohum) d�nd�rece�inden rand fonksiyonu da her �al��t�r�ld���nda farkl� bir de�er d�nd�recektir
   k�saca �o�u bilgisayar dili "time" fonksiyonunu seed olarak kullan�r, bu y�zden �o�u kaynak tan�mlanan seed'e g�re de�er d�nd�ren rand fonksiyonunun d�nd�rd��� say�ya yalanc� rastgele (pseudo random) say� ad�n� verir
   srand fonksiyonu genel olarak "srand(time(0)" ve "srand(time(NULL))" syntax'lar� ile kullan�l�rken int tohum=tohum_degeri i�in "srand(tohum)" bi�iminde de kullan�labilir

   o zaman hadi zar atmaca ve yaz�-tura oynayal�m

int main() {
	int secim;
	srand(time(0));
	printf("1. Zar atmaca\n2. Yazi-tura\n3. 1 ile 100 arasinda rastgele bir sayi\nSeciminizi giriniz: ");
	scanf("%d",&secim);
	switch(secim) {
		case 1: printf("Atilan zar: %d",1+rand()%6); break;
		case 2: printf(rand()%2 ? "Atilan para: Yazi" : "Atilan para: Tura"); break;	//"rand()%2" 1 d�nd�r�rse yaz�, 0 d�nd�r�rse tura
		default: printf("Sikime bak ya");
	}
}

   akl�mdaki say�y� tahmin et													1 ile 100 aras�nda rastgele 10 say� yazd�ral�m							klavyeden girilen tohuma (seed) g�re 12 defa zar atal�m

#define aralik 20																int main() {															int main() {
int main() {																		srand((unsigned)time(NULL));											int i,tohum;
	srand(time(NULL));																int i,x;																printf("Tohumu giriniz: ");
	int tahmin,tutulan_sayi=rand()%aralik+1;										printf("10 tane random sayi: ");										scanf("%u",&tohum);
	do {																			for(i=1;i<=10;i++) {													srand(tohum);
		printf("Aklimdaki sayiyi tahmin et (1-%d): ",aralik);							x=1+rand()%100;														printf("\n************* Atilan zarlar *************\n");
		scanf("%d",&tahmin);															printf("%d  ",x);													for(i=1;i<=12;i++) {
		if(tahmin<1 || tahmin>aralik)												}																			printf("%10d",1+rand()%6);
			printf("Araligin disina ciktin\n");									}																				if(i%4==0)
		else {																																						printf("\n");
		if(tutulan_sayi>tahmin)																																}
			printf("Aklimdaki sayi daha buyuk\n");																										}
		if(tutulan_sayi<tahmin)
			printf("Aklimdaki sayi daha kucuk\n");
		}
	} while(tutulan_sayi!=tahmin);
	printf("Bildin, tebrikler!!!");
	return 0;
}

   random atan program (pun intended)

int main() {
	srand(time(NULL));
	int random_uzunlugu=25+rand()%51,i;		//25<=random_uzunlugu<=75
	char k;
	for(i=1;i<=random_uzunlugu;i++) {
		k=97+rand()%26;		//97<=k<=122 ==> 'a'<=k<='z'
		printf("%c",k);
	}
} */

int main() {
	srand(time(NULL));
	int i,n,x,a=0,b=0,c=0,d=0;		//a,b,c,d birer saya� burada
	printf("Kac tane rastgele sayi istiyorsunuz?: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		x=rand();		//d�ng� i�erisinde x her seferinde farkl� bir de�er al�yor
		printf("Rastgele sayi[%d]: %d\n",i,x);
		if(x<10000)		//bu sat�ra alternatif olarak if(x==(x%10000)) yaz�labilir
			a++;
		if(x<1000)
			b++;
		if(x<100)
			c++;
		if(x<10)
			d++;
	}
	printf("\n0-9999 arasindaki sayilar: %d",a);
	printf("\n0-999 arasindaki sayilar: %d",b);
	printf("\n0-99 arasindaki sayilar: %d",c);
	printf("\n0-9 arasindaki sayilar: %d",d);
}
