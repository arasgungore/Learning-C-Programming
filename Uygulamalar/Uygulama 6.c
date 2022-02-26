#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Her basamaðý adamýn boyu uzunluðunda olan merdiveni bir adam çýkacaktýr. Adamýn boyu ve merdivenin basamak sayýsý klavyeden girileceðine göre,
   merdiveni çýkan adamý adam her karede bir basamak çýkacak þekilde film þeridi gibi çizdiren program

int main() {
	int adamin_boyu,basamak_sayisi,i,j,k,l;
	printf("Basamak sayisini ve adamin boyunu giriniz: ");
	scanf("%d%d",&basamak_sayisi,&adamin_boyu);
	for(l=1;l<=basamak_sayisi+1;l++) {	//basamak sayýsýnýn 1 fazlasý kadar kare
		for(k=1;l==1 && k<=adamin_boyu+2;k++) {
			for(j=1;j<=5*(basamak_sayisi+1);j++)	//basamak sayýsýnýn 1 fazlasýnýn 5 katý kadar boþluk
				printf(" ");
			printf(k==1 ? "\b\bo\n" : "");
			printf(k==2 ? "\b\b\b/|\\\n" : "");
			printf(2<k && k<adamin_boyu+2 ? "\b\b|\n" : "");
			printf(k==adamin_boyu+2 ? "\b\b\b/ \\\n" : "");
		}	//l 1'e (ilk deðeri) eþitse for döngüsüne gir ve adamýn kafasý, kollarý, gövdesi ve bacaklarýný çiz, deðilse çizme
		for(i=1;i<=basamak_sayisi;i++) {		//basamak sayýsý kadar... basamak sayýsý
			for(j=1;j<=5*(basamak_sayisi-i+1);j++)
				printf(" ");		//basamak sayýsý ile satýr no farkýnýn 1 fazlasýnýn 5 katý kadar boþluk
			printf(l-1==i ? "\b\b\bo  ------" : "------");	//l-1 i'ye eþitse adamýn kafasýný çiz, deðilse çizme
			for(j=1;j<=5*(i-1);j++)
				printf("*");		//satýr no'nun 1 eksiðinin 5 katý kadar yýldýz
			printf("|\n");			//basamaðýn 1/3'ü tamam, kalan 2/3'ünü yazdýrmak için alt satýra geç
			for(k=1;k<=adamin_boyu+1;k++) {
				for(j=1;j<=5*(basamak_sayisi-i+1);j++)
					printf(" ");	//basamak sayýsý ile satýr no farkýnýn 1 fazlasýnýn 5 katý kadar boþluk
				printf(l-1==i && k==1 ? "\b\b\b\b/|\\ |" : "|");	//hem l-1 i'ye eþit hem de k 1'e eþitse adamýn kollarýný çiz, deðilse çizme
				printf(l-1==i && 1<k && k<adamin_boyu+1 ? "\b\b\b\b|  |" : "");	//hem l-1 i'ye eþit hem de k 1 ile adamin_boyu+1 arasýnda ise adamýn gövdesini çiz, deðilse çizme
				printf(l-1==i && k==adamin_boyu+1 ? "\b\b\b\b\b/ \\ |" : "");	//hem l-1 i'ye eþit hem de k adamin_boyu+1'e eþitse adamýn bacaklarýný çiz, deðilse çizme
				for(j=1;j<=5*i;j++)
					printf("*");	//satýr no'nun 5 katý kadar yýldýz
				printf("|\n");
			}	//bir basamak tamam, bir sonraki basamak için alt satýra geç
		}
		printf("------");	//merdivenin en sondaki satýrý
		for(j=1;j<=5*basamak_sayisi;j++)
			printf("*");	//basamak sayýsýnýn 5 katý kadar yýldýz
		printf("|\n\n\n");
	}	//bir kare tamam, bir sonraki kare için 3 satýr atla
	exit(0);
}		//baþarýyla programý sonlandýr

   Klavyeden girilen farklý spam kelimeler için klavyeden belirlenen puanlara göre, klavyeden girilen bir e-mail'de bu spam
   kelimelerin küçük-büyük harf fark etmeksizin kaç defa geçtiðini tarayan ve e-mail'in toplam spam puanýný döndüren program

int main() {
	char a=' ',spam[100][40],mail[1000][40];	//spam: 100 kelime, kelime baþý max 40 karakter ; mail: 1000 kelime, kelime baþý max 40 karakter
	int i=0,j,k=0,sayi[100],toplam=0;
	printf("Spam kelimeleri kucuk harflerle yaziniz: ");
	while(a==' ')						//%s belirteci boþluk veya newline girilmediði sürece input almaya devam ederken boþluk veya newline gelince
		scanf("%s%c",spam[i++],&a);		//input almayý býrakacak ve o boþluk veya newline'ý %c belirteci ile char deðiþkenim tutacak
	printf("\nBu kelimelerin sirayla spam puanlarini giriniz: ");
	for(j=0;j<i;j++)					//eðer char deðiþkenim boþluk ise yeni bir string scan'lemeye devam edecek, newline ise döngüden çýkýp alt satýra geçecek
		scanf("%d",&sayi[j]);
	printf("\nE-maili giriniz:\n\n\t");
	do {
		scanf("%s%c",mail[k++],&a);
		for(j=0;j<i;j++)
			if(strcmp(strlwr(mail[k-1]),spam[j])==0)
				toplam+=sayi[j];
	} while(a==' ');		//char deðiþkenim en son newline idi, tekrar boþluk deðerini atamak yerine do while kullandým
	printf("\nMailin toplam spam puani: %d",toplam);
}

   Klavyeden girilen taban deðerine göre klavyeden girilen o tabandaki sayýlarla klavyeden girilen karaktere göre o tabanda taban aritmetiði yapýp seçilen iþlemin sonucunu yazdýran program */

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
	scanf("%*c%c",&secim);	//istemeyerek okunan önceki karakteri discard et, kullanýcýdan input bekle
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
	else if(secim=='/' || secim=='d') {			//if, if, if, if þeklinde de yazabilsem de if, else if, else if, else if yapýsý daha hýzlý olduðundan genellikle bu kullanýlýr
		sonuc=tabana_donustur(x1/x2,taban);
		secim='/';
	}	*/
	switch(secim) {								//ama switch case yapýsý daha da hýzlý ;)
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
