#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Her basama�� adam�n boyu uzunlu�unda olan merdiveni bir adam ��kacakt�r. Adam�n boyu ve merdivenin basamak say�s� klavyeden girilece�ine g�re,
   merdiveni ��kan adam� adam her karede bir basamak ��kacak �ekilde film �eridi gibi �izdiren program

int main() {
	int adamin_boyu,basamak_sayisi,i,j,k,l;
	printf("Basamak sayisini ve adamin boyunu giriniz: ");
	scanf("%d%d",&basamak_sayisi,&adamin_boyu);
	for(l=1;l<=basamak_sayisi+1;l++) {	//basamak say�s�n�n 1 fazlas� kadar kare
		for(k=1;l==1 && k<=adamin_boyu+2;k++) {
			for(j=1;j<=5*(basamak_sayisi+1);j++)	//basamak say�s�n�n 1 fazlas�n�n 5 kat� kadar bo�luk
				printf(" ");
			printf(k==1 ? "\b\bo\n" : "");
			printf(k==2 ? "\b\b\b/|\\\n" : "");
			printf(2<k && k<adamin_boyu+2 ? "\b\b|\n" : "");
			printf(k==adamin_boyu+2 ? "\b\b\b/ \\\n" : "");
		}	//l 1'e (ilk de�eri) e�itse for d�ng�s�ne gir ve adam�n kafas�, kollar�, g�vdesi ve bacaklar�n� �iz, de�ilse �izme
		for(i=1;i<=basamak_sayisi;i++) {		//basamak say�s� kadar... basamak say�s�
			for(j=1;j<=5*(basamak_sayisi-i+1);j++)
				printf(" ");		//basamak say�s� ile sat�r no fark�n�n 1 fazlas�n�n 5 kat� kadar bo�luk
			printf(l-1==i ? "\b\b\bo  ------" : "------");	//l-1 i'ye e�itse adam�n kafas�n� �iz, de�ilse �izme
			for(j=1;j<=5*(i-1);j++)
				printf("*");		//sat�r no'nun 1 eksi�inin 5 kat� kadar y�ld�z
			printf("|\n");			//basama��n 1/3'� tamam, kalan 2/3'�n� yazd�rmak i�in alt sat�ra ge�
			for(k=1;k<=adamin_boyu+1;k++) {
				for(j=1;j<=5*(basamak_sayisi-i+1);j++)
					printf(" ");	//basamak say�s� ile sat�r no fark�n�n 1 fazlas�n�n 5 kat� kadar bo�luk
				printf(l-1==i && k==1 ? "\b\b\b\b/|\\ |" : "|");	//hem l-1 i'ye e�it hem de k 1'e e�itse adam�n kollar�n� �iz, de�ilse �izme
				printf(l-1==i && 1<k && k<adamin_boyu+1 ? "\b\b\b\b|  |" : "");	//hem l-1 i'ye e�it hem de k 1 ile adamin_boyu+1 aras�nda ise adam�n g�vdesini �iz, de�ilse �izme
				printf(l-1==i && k==adamin_boyu+1 ? "\b\b\b\b\b/ \\ |" : "");	//hem l-1 i'ye e�it hem de k adamin_boyu+1'e e�itse adam�n bacaklar�n� �iz, de�ilse �izme
				for(j=1;j<=5*i;j++)
					printf("*");	//sat�r no'nun 5 kat� kadar y�ld�z
				printf("|\n");
			}	//bir basamak tamam, bir sonraki basamak i�in alt sat�ra ge�
		}
		printf("------");	//merdivenin en sondaki sat�r�
		for(j=1;j<=5*basamak_sayisi;j++)
			printf("*");	//basamak say�s�n�n 5 kat� kadar y�ld�z
		printf("|\n\n\n");
	}	//bir kare tamam, bir sonraki kare i�in 3 sat�r atla
	exit(0);
}		//ba�ar�yla program� sonland�r

   Klavyeden girilen farkl� spam kelimeler i�in klavyeden belirlenen puanlara g�re, klavyeden girilen bir e-mail'de bu spam
   kelimelerin k���k-b�y�k harf fark etmeksizin ka� defa ge�ti�ini tarayan ve e-mail'in toplam spam puan�n� d�nd�ren program

int main() {
	char a=' ',spam[100][40],mail[1000][40];	//spam: 100 kelime, kelime ba�� max 40 karakter ; mail: 1000 kelime, kelime ba�� max 40 karakter
	int i=0,j,k=0,sayi[100],toplam=0;
	printf("Spam kelimeleri kucuk harflerle yaziniz: ");
	while(a==' ')						//%s belirteci bo�luk veya newline girilmedi�i s�rece input almaya devam ederken bo�luk veya newline gelince
		scanf("%s%c",spam[i++],&a);		//input almay� b�rakacak ve o bo�luk veya newline'� %c belirteci ile char de�i�kenim tutacak
	printf("\nBu kelimelerin sirayla spam puanlarini giriniz: ");
	for(j=0;j<i;j++)					//e�er char de�i�kenim bo�luk ise yeni bir string scan'lemeye devam edecek, newline ise d�ng�den ��k�p alt sat�ra ge�ecek
		scanf("%d",&sayi[j]);
	printf("\nE-maili giriniz:\n\n\t");
	do {
		scanf("%s%c",mail[k++],&a);
		for(j=0;j<i;j++)
			if(strcmp(strlwr(mail[k-1]),spam[j])==0)
				toplam+=sayi[j];
	} while(a==' ');		//char de�i�kenim en son newline idi, tekrar bo�luk de�erini atamak yerine do while kulland�m
	printf("\nMailin toplam spam puani: %d",toplam);
}

   Klavyeden girilen taban de�erine g�re klavyeden girilen o tabandaki say�larla klavyeden girilen karaktere g�re o tabanda taban aritmeti�i yap�p se�ilen i�lemin sonucunu yazd�ran program */

long long tabana_donustur(int sayi, int taban) {
	int i=0,j,dizi[100];
	long long sonuc=0;
	while(sayi!=0) {
		dizi[i++]=sayi%taban;
		sayi/=taban;
	}
	for(j=0;j<i;j++)
		sonuc+=dizi[j]*pow(10,j);
	return sonuc;
}
int tekrar_10_tabanina_cevir(long long sayi, int taban) {
	int rakam,i=0,toplam=0;
	while(sayi!=0) {
		rakam=sayi%10;
		toplam+=rakam*pow(taban,i++);
		sayi/=10;
	}
	return toplam;
}
int main() {
	int taban,x1,x2;
	long long sayi1,sayi2,sonuc;
	char secim;
	printf("Tabani giriniz (1-9): ");
	scanf("%d",&taban);
	printf("'+','a': Toplama\n'-','s': Cikarma\n'*','m': Carpma\n'\\','d': Bolme\nIslemi seciniz: ");
	scanf("%*c%c",&secim);	//istemeyerek okunan �nceki karakteri discard et, kullan�c�dan input bekle
	while(!strchr("+-*/asmd",secim)) {
		printf("'+','a': Toplama\n'-','s': Cikarma\n'*','m': Carpma\n'\','d': Bolme\nLutfen gecerli bir islem seciniz: ");
		scanf("%*c%c",&secim);
	}
	printf("Iki sayi giriniz: ");
	scanf("%lld%lld",&sayi1,&sayi2);
	x1=tekrar_10_tabanina_cevir(sayi1,taban);
	x2=tekrar_10_tabanina_cevir(sayi2,taban);
/*	if(secim=='+' || secim=='a') {
		sonuc=tabana_donustur(x1+x2,taban);
		secim='+';
	}
	else if(secim=='-' || secim=='s') {
		sonuc=tabana_donustur(x1-x2,taban);
		secim='-';
	}
	else if(secim=='*' || secim=='m') {
		sonuc=tabana_donustur(x1*x2,taban);
		secim='*';
	}
	else if(secim=='/' || secim=='d') {			//if, if, if, if �eklinde de yazabilsem de if, else if, else if, else if yap�s� daha h�zl� oldu�undan genellikle bu kullan�l�r
		sonuc=tabana_donustur(x1/x2,taban);
		secim='/';
	}	*/
	switch(secim) {								//ama switch case yap�s� daha da h�zl� ;)
		case '+':
		case 'a':
			sonuc=tabana_donustur(x1+x2,taban);
			secim='+';
			break;
		case '-':
		case 's':
			sonuc=tabana_donustur(x1-x2,taban);
			secim='-';
			break;
		case '*':
		case 'm':
			sonuc=tabana_donustur(x1*x2,taban);
			secim='*';
			break;
		case '/':
		case 'd':
			sonuc=tabana_donustur(x1/x2,taban);
			secim='/';
	}
	printf("\nSonuc: %lld%c%lld=%lld",sayi1,secim,sayi2,sonuc);
	return 0;
}
