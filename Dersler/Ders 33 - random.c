#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* "rand: random , rastgele"     "srand: set seed in random , random fonksiyonuna tohumu yerleþtir"     "seed: tohum , srand fonksiyonunun parametresi"
   rand() fonksiyonu adý üzerinde rastgele (!) deðerler döndürmek için kullanýlýr

int main() {
	printf("Random fonksiyonunun dondurdugu deger: %d",rand());	//çýktý daima "41" olacak
	printf("\nRandom fonksiyonunun dondurebilecegi max deger: %d",RAND_MAX);	//RAND_MAX=SHRT_MAX=(2^15)-1="32767"
}

int main() {
	int i,j;
	printf("*****Random sayilar*****\n\n");
	for(i=1;i<=3;i++) {
		for(j=1;j<=10;j++)
			printf("%d  ",rand());	//her seferinde ayný 30 sayýyý yazdýracak
		printf("\n");
	}
}

   öncelikle þunu söylemeliyim ki, yazýlýmda hiçbir zaman gerçek anlamda bir rastgelelik yoktur
   aslýnda olasýlýk teorisine göre gerçek hayatta da gerçek anlamda bir rastgelelik yoktur   (kuantum fiziði hariç)
   mesela bir zar attýðýnda zarýn kaç geleceðini zarý atýþ açýn, zarý atýþ kuvvetin, zarý atýþ biçimin, çevre koþullarý, zarýn aðýrlýk merkezi gibi bir sürü faktör (parametre) belirler
   bilgisayarda ise gerçek hayatýn rastgeleliðinden çok da farklý olmayarak rand fonksiyonu belli bir tohuma (seed) göre deðer döndürür
   bilgisayardaki mevzubahis yalancý rastgeleliði saðlayan yöntemlerden en popüleri tohumu ZAMANA baðlý olarak deðiþtirmektir
   time kütüphanesi ile import ettiðim time(NULL) fonksiyonu bana 1/1/1970 00:00:00 tarihinden bu yana kaç saniye geçtiðini döndürür ve bu deðer de srand fonksiyonu ile tohuma atanýr
   her geçen saniyede time(NULL) fonksiyonu farklý bir deðer (tohum) döndüreceðinden rand fonksiyonu da her çalýþtýrýldýðýnda farklý bir deðer döndürecektir
   kýsaca çoðu bilgisayar dili "time" fonksiyonunu seed olarak kullanýr, bu yüzden çoðu kaynak tanýmlanan seed'e göre deðer döndüren rand fonksiyonunun döndürdüðü sayýya yalancý rastgele (pseudo random) sayý adýný verir
   srand fonksiyonu genel olarak "srand(time(0)" ve "srand(time(NULL))" syntax'larý ile kullanýlýrken int tohum=tohum_degeri için "srand(tohum)" biçiminde de kullanýlabilir

   o zaman hadi zar atmaca ve yazý-tura oynayalým

int main() {
	int secim;
	srand(time(0));
	printf("1. Zar atmaca\n2. Yazi-tura\n3. 1 ile 100 arasinda rastgele bir sayi\nSeciminizi giriniz: ");
	scanf("%d",&secim);
	switch(secim) {
		case 1: printf("Atilan zar: %d",1+rand()%6); break;
		case 2: printf(rand()%2 ? "Atilan para: Yazi" : "Atilan para: Tura"); break;	//"rand()%2" 1 döndürürse yazý, 0 döndürürse tura
		default: printf("Sikime bak ya");
	}
}

   aklýmdaki sayýyý tahmin et													1 ile 100 arasýnda rastgele 10 sayý yazdýralým							klavyeden girilen tohuma (seed) göre 12 defa zar atalým

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
	int i,n,x,a=0,b=0,c=0,d=0;		//a,b,c,d birer sayaç burada
	printf("Kac tane rastgele sayi istiyorsunuz?: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		x=rand();		//döngü içerisinde x her seferinde farklý bir deðer alýyor
		printf("Rastgele sayi[%d]: %d\n",i,x);
		if(x<10000)		//bu satýra alternatif olarak if(x==(x%10000)) yazýlabilir
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
