#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Klavyeden girilen 10 tane say�y� k���kten b�y��e s�ralayan program						Klavyeden birbirinden farkl� 2 say� girilmesini sa�layan ve bu iki say� aras�ndaki (bu iki say� dahil) tam say�lar�n toplam�n� yazd�ran program

int main() {																				int main() {
	int sayi[10],tut,i,j;																		int sayi1,sayi2,i,buyuk,kucuk,toplam=0;
	for(i=0;i<10;i++) {																			yeniden:
		printf("%d. Sayi: ",i+1);																printf("1. Sayi: ");
		scanf("%d",&sayi[i]);																	scanf("%d",&sayi1);
	}																							printf("2. Sayi: ");
	for(i=0;i<10;i++) {																			scanf("%d",&sayi2);
		for(j=0;j<10;j++) {																		if(sayi1==sayi2) {
			if(sayi[i]<sayi[j]) {																	goto yeniden;
				tut=sayi[i];																	}
				sayi[i]=sayi[j];																if(sayi1>sayi2) {
				sayi[j]=tut;																		buyuk=sayi1;
			}																						kucuk=sayi2;
		}			//swap oldu, yani sayi[i] ile sayi[j]'nin de�erleri birbiriyle de�i�ti		}
	}																							else {
	printf("\nSayilarin Kucukten Buyuge Siralanisi: ");												kucuk=sayi1;
	for(i=0;i<10;i++) {																				buyuk=sayi2;
		printf("%d ",sayi[i]);																	}
	}																							for(i=kucuk;i<=buyuk;i++) {
}																									toplam=toplam+i;			//toplam+=i de yaz�labilirdi, ikisi ayn� �ey
//14-16. sat�rlarlar� bubble sort ile ��yle de�i�tirebiliriz:									}
//for(i=0;i<9;i++) {																			printf("Toplam: %d",toplam);
//    for(j=0;j<9-i;j++) {																	}
//        if(sayi[i]>sayi[j]) { ...
//...sonra da genel kal�b� "gecici=a; a=b; b=gecici;" olan swap'� if'in i�erisine aynen implement ediyorsun

   Bir hava yolu �irketi yolcular� i�in bagaj s�n�rlamas� uygulamaktad�r. Her yolcunun el i�in 8 kg, normal i�in 15 kg bagaj hakk� bulunmaktad�r. E�er yolcular el haklar�n� ge�erse kg ba��na 4 TL, normal haklar�n�
   ge�erse kg ba��na 5 TL �deme yapmak durumundad�r. Buna g�re klavyeden el ve normal bagajlar�n�n kg olarak a��rl���n� giren yolcunun �demesi gereken bagaj �cretini yazd�ran program

int main () {
	int el,eltutar=0,normal,normaltutar=0,toplam=0;											Heybeliada'da bulunan yaz�l�m evi otelinde k���n 320 ki�i kalm��t�r. �lkbaharda k�� mevsiminin d�rtte biri, yaz mevsiminde ilkbahar�n 8 kat�,
	printf("El Bagaj Kg: ");																ve sonbaharda yaz mevsiminin onda biri kadar ki�i kald���na g�re bu otelde 1 y�l i�inde toplam ka� ki�i kald���n� yazd�ran program
	scanf("%d",&el);
	printf("Normal Bagaj Kg: ");															int main() {
	scanf("%d",&normal);																		int ilkbahar,yaz,sonbahar,kis=320;
	if(el>8) {																					ilkbahar=kis/4;  //80
		eltutar=4*(el-8);																		yaz=ilkbahar*8;  //640
	}																							sonbahar=yaz/10; //64
	if(normal>15) {																				printf("%d",ilkbahar+yaz+sonbahar+kis);
		normaltutar=5*(normal-15);															}
	}
	toplam=eltutar+normaltutar;
	printf("Toplam ucretiniz %d TL'dir, iyi yolculuklar...",toplam);
}

   10*10'luk bir �arp�m tablosunu yazd�ran program											�lk 4 m�kemmel say�y� (kendisi hari� pozitif tam b�lenleri toplam� kendisini veren say�lar) yazd�ran program

int main() {																				int main() {
	int i,j;																					int x,i,toplam=0;
	for(i=1;i<=10;i++) {																		for(x=2;x<=9999;x++) {
		printf("\t%d",i);																			for(i=1;i<=x/2+1;i++) {			//a tamsay�s� i�in 1'den a'ya kadar olan aral���n ikinci yar�s�nda a'y� tam b�len bir say� yoktur
	}																									if(x%i==0) {				//biti� noktas� olarak "i<=x" yazmak kodu daha ge� �al��t�r�r ve bilgisayar� yorar
	printf("\n -");																						toplam=toplam+i;
	for(i=1;i<=10;i++) {																				}
		printf("--------");																			}
	}																								if(toplam==x) {
	printf("\n");																					printf("%d ",x);
	for(i=1;i<=10;i++) {																			}
		printf("%d|\t",i);																		toplam=0;
		for(j=1;j<=10;j++) {																	}
			printf("%d\t",i*j);																}
		}
		printf("\n");
	}
}

   �lk 4 m�kemmel say�y� while d�ng�s� ve saya� yard�m�yla yazd�ran alternatif program		�lk 100 asal say�y� yazd�ran program

int main() {																				int main() {
	int x=2,i,toplam=0,sayac=0;																	int x=2,i,sayac1=0,sayac2=0;
	while(sayac<4) {																			while(sayac1<100) {
		for(i=1;i<=x/2+1;i++) {																		for(i=2;i<=x/2+1;i++) {
			if(x%i==0) {																				if(x%i==0) {
			toplam=toplam+i;																			sayac2++;
			}																							}
		}																							}
	if(toplam==x) {																				if(sayac2==0) {
	printf("%d ",x);																			printf("%d ",x);
	sayac++;																					sayac1++;
	}																							}
	toplam=0;																					sayac2=0;
	x++;																						x++;
	}																							}
	return 0;																					return 0;
}																							}

   Y�ld�z i�aretleriyle dikey eni 8, yatay boyu ise 25 y�ld�z uzunlu�unda olan i�i bo� bir dikd�rtgen �izdiren program

int main() {																				Klavyeden girilen n tane say�n�n aritmetik, geometrik ve harmonik ortalamalar�n� yazd�ran program
	int i,j;
	for(i=1;i<=8;i++) {																		int main() {
		if(i==1 || i==8) {																		double arit,geo,harm,sayi,toplam=0,carpim=1,htoplam=0;
			for(j=1;j<=25;j++) {																int i,n;
			printf("*");																		printf("Kac tane sayi gireceksiniz?: ");
			}																					scanf("%d",&n);
		}																						for(i=1;i<=n;i++) {
		else {																						printf("%d. Sayi: ",i);
			printf("*");																			scanf("%lf",&sayi);
			for(j=2;j<=24;j++) {																	toplam+=sayi;			//toplam=toplam+sayi
			printf(" ");																			carpim*=sayi;			//carpim=carpim*sayi
			}																						htoplam+=1/sayi;		//htoplam=htoplam+1/sayi
			printf("*");																		}
		}																						arit=toplam/n;
	printf("\n");																				geo=pow(carpim,1.0/n);
	}																							harm=n/htoplam;
}																								printf("\nAritmetik Ortalama: %lf\nGeometrik Ortalama: %lf\nHarmonik Ortalama: %lf",arit,geo,harm);
																							}

   a=/=0 olmak �zere ax^2+bx+c=0 bi�imindeki ikinci dereceden bir denklemin klavyeden girilen a,b,c de�erlerine g�re k�klerini yazd�ran program

int main() {																				Klavyeden girilen bir tam say�y� asal �arpanlar�na ay�r�p yazd�ran program
	double a,b,c,disk,kok1,kok2;
	printf("*****ax^2+bx+c=0 Bicimindeki Denklemleri Cozen Uygulama*****\n\n");				int main() {
	printf("a icin deger giriniz: ");															int i,sayi;
	scanf("%lf",&a);																			printf("Sayiyi giriniz: ");
	while(a==0) {																				scanf("%d",&sayi);
		printf("Lutfen a'ya 0 disinda bir deger giriniz: ");									for(i=2;sayi!=1;i++) {		//sayi de�i�keni 1'e e�it olmad��� s�rece i tek tek artacak ve d�ng� devam edecek
		scanf("%lf",&a);																			if(sayi%i==0) {
	}																									sayi/=i;
	printf("b icin deger giriniz: ");																	printf("%d ",i);
	scanf("%lf",&b);																					i--;
	printf("c icin deger giriniz: ");																}
	scanf("%lf",&c);																			}
	disk=b*b-4*a*c;																			}
	printf("\n");
	if(disk>=0) {																			Klavyeden girilen sat�r say�s�na g�re Floyd ��genini (ard���k sayma say�lar�n�n sola dayal� dizilmesiyle olu�an dik ��gen) �izdiren program
		kok1=(-b+sqrt(disk))/(2*a);
		kok2=(-b-sqrt(disk))/(2*a);															int main() {
		if(kok1!=kok2) {																		int i,j,satir,sayac=1;
			printf("Bu denklemin iki koku vardir.\n");											printf("Satir sayisini giriniz: ");
			printf("Kok 1: %lf\n",kok1);														scanf("%d",&satir);
			printf("Kok 2: %lf",kok2);															for(i=1;i<=satir;i++) {
		}																							for(j=1;j<=i;j++) {
		else {																							printf("%d\t",sayac);
			printf("Bu denklemin bir koku vardir.\n");													sayac++;
			printf("Cift Kok: %lf",kok1);															}
		}																							printf("\n");
	}																							}
	else {																					}
		printf("Bu denklemin reel sayilarda koku yoktur.");
	}
}

   100 ila 9999 aras�nda bulunan b�t�n palindromik (tersten yaz�l�� ve okunu�u ayn� olan) say�lar� alt alta yazd�ran program

int main() {																				100 ila 9999 aras�ndaki Armstrong say�lar�n� (rakamlar�n�n basamak say�s� kadar kuvvetleri toplam� kendisini veren say�lar) yazd�ran program
	int i,j,k,l;
	puts("******Palindromik Sayilar******");												int main() {
	for(i=1;i<=9;i++) {																			int i,sayi,rakam,toplam=0;
		for(j=0;j<=9;j++) {																		for(i=100;i<=9999;i++) {
			for(k=0;k<=9;k++) {																		sayi=i;
				if(i==k)																			if(i/1000!=0)
				printf("%d\n",100*i+10*j+k);															while(sayi!=0) {
			}			//3 basamakl� ijk say�s� i=k ise palindromiktir										rakam=sayi%10;
		}																									toplam+=rakam*rakam*rakam*rakam;
	}																										sayi/=10;
	for(i=1;i<=9;i++) {																					}
		for(j=0;j<=9;j++) {																			else
			for(k=0;k<=9;k++) {																			while(sayi!=0) {
				for(l=0;l<=9;l++) {																			rakam=sayi%10;
					if(i==l && j==k)																		toplam+=rakam*rakam*rakam;
					printf("%d\n",1000*i+100*j+10*k+l);														sayi/=10;
				}		//4 basamakl� ijkl say�s� i=l VE j=k ise palindromiktir							}
			}																						if(i==toplam)
		}																								printf("%d bir Armstrong sayisidir\n",i);
	}																								toplam=0;
	return 0;																					}
}																							}

   Klavyeden girilen bir say�n�n Armstrong say�s� olup olmad���n� yazd�ran program			Klavyeden girilen bir kelimenin palindrom olup olmad���n� yazd�ran program

int main() {																				int main() {
	int sayi,orijinalsayi,rakam,sayac=0,toplam=0;												int i=0,j,palindrom_mu=1;	//i'yi ilk ge�erli index'e e�itledim (ilk harfin index'i)
	printf("Sayi giriniz: ");																	char kelime[50];
	scanf("%d",&sayi);																			printf("Kelime yaziniz: ");
	orijinalsayi=sayi;																			scanf("%s",kelime);
	while(orijinalsayi!=0) {																	j=strlen(kelime)-1;			//j'yi son ge�erli index'e e�itledim (son harfin index'i)
		orijinalsayi/=10;																		while(i<=j) {
		sayac++;		//saya� girdi�im say�n�n ka� basamakl� oldu�unu tuttu						if(kelime[i]!=kelime[j]) {
	}																									palindrom_mu=0;
	orijinalsayi=sayi;																					break;
	while(orijinalsayi!=0) {																		}
		rakam=orijinalsayi%10;																		i++;
		toplam+=pow(rakam,sayac);																	j--;
		orijinalsayi/=10;																		}
	}																							if(palindrom_mu)
	if(toplam==sayi)																				printf("%s bir palindromdur",kelime);
		printf("%d bir Armstrong sayisidir",sayi);												else
	else																							printf("%s bir palindrom degildir",kelime);
		printf("%d bir Armstrong sayisi degildir",sayi);									}
}

   Rus k�yl� �arp�m metodu ile klavyeden girilen 2 tam say�n�n �arp�m�n� yazd�ran program

int main() {							//misal 12 ve 13 girdi�imi varsayal�m
	int a,b,sonuc=0,m,n;				//1. say� s�rekli 2 ile �arp�l�rken 2. say� s�rekli 2'ye b�l�n�r (int division, yani tam say� b�lmesiyle)
	printf("Iki tam sayi giriniz: ");	//2. say� 1 olana kadar bu i�lem yap�l�r ve 2. say�n�n �ift oldu�u sat�rlar �izilir		m	n
	scanf("%d%d",&a,&b);				//�izilmemi� sat�rlardaki m de�erlerinin toplam� ise bana sonucu verir					12	13
	m=a;	//m: 1. s�tundaki say�lar	  12 * 13 = 12 + 48 + 96 = 156														  --24--6--
	n=b;	//n: 2. s�tundaki say�lar																							48	3
	while(n>0) {		//																										96	1
		if(n%2!=0)		//n say�s� �ift de�ilse o sat�rdaki m de�erini sonuca ekle
			sonuc+=m;
		m*=2;  // m'yi 2 ile �arp
		n/=2;  // n'yi 2'ye b�l
	}
	printf("%d * %d = %d",a,b,sonuc);
}

   ELeman say�s� ve elemanlar� klavyeden girilen bir say� dizisinin i�inde yer alan
   k���kten b�y��e olarak s�ralanm�� en uzun alt dizinin ka� elemanl� oldu�unu yazd�ran		Klavyeden girilen bir seneden sonra gelen en k���k rakamlar� farkl� seneyi yazd�ran program
   program

int main() {																				int main() {
	int n,i,sayac=1,max=1;																		int sene,rakam1,rakam2,rakam3,rakam4;
	printf("Dizinin eleman sayisi: ");															printf("Sene: ");
	scanf("%d",&n);																				scanf("%d",&sene);
	int *dizi=(int*) malloc(sizeof(int)*n);														do {
	printf("Dizinin elemanlarini giriniz: ");														sene++;
	for(i=0;i<n;i++)																				rakam4=a%10;
		scanf("%d",&dizi[i]);																		rakam3=(a/10)%10;
	for(i=0;i<n-1;i++) {																			rakam2=(a/100)%10;
		if(dizi[i]<=dizi[i+1])																		rakam1=a/1000;
			sayac++;																			} while(rakam1==rakam2 || rakam1==rakam3 || rakam1==rakam4 || rakam2==rakam3 || rakam2==rakam4 || rakam3==rakam4);
		else																					printf("Sene: %d",sene);
			sayac=1;																		}
		if(sayac>max)
			max=sayac;
	}
	printf("Kucukten buyuge sirali en uzun alt dizinin eleman sayisi: %d",max);
	return 0;
}

   Klavyeden saniye olarak girilen say�y� sonradan klavyeden girilen karakter 'a' veya 'A'
   ise AM, 'p' veya 'P' ise PM olarak alg�layan ve "saat:dakika:saniye" bi�iminde dijital	T 1 ila 10 aras�nda bir say� olmak �zere klavyeden girilen decimal (10 taban�ndaki) bir say�n�n T taban�ndaki g�sterimindeki rakamlar�
   saat format�nda d�nd�ren program															toplam�n�n 10 taban�ndaki de�erini yazd�ran program

int main() {																				int main() {
	int n,saat,dakika,saniye;																	int sayi,taban,rakam,toplam=0;
	char k;																						printf("Sayiyi ve cevrilecegi tabani giriniz (1<=taban<=10): ");
	printf("Sayi (0<=n<43200) ve karakter (A/a:AM   P/p: PM) giriniz: ");						scanf("%d%d",&sayi,&taban);
	scanf("%d %c",&n,&k);																		int orijinalsayi=sayi;
	saat=n/3600;																				while(sayi!=0) {
	dakika=(n/60)%60;																				rakam=sayi%taban;
	saniye=n%60;																					toplam+=rakam;
	if((k=='A' || k=='a') && 0<=n && n<43200)														sayi/=taban;
		printf("%02d:%02d:%02d",saat,dakika,saniye);											}
	if((k=='P' || k=='p') && 0<=n && n<43200) {													printf("%d'nin %d tabanindaki rakamlar toplami: %d",orijinalsayi,taban,toplam);
		saat+=12;																			}
		printf("%02d:%02d:%02d",saat,dakika,saniye);
	}
}

   Klavyeden girilen iki tam say�y� ve bir float adresini parametre olarak alan bir
   fonksiyonbu iki tam say�n�n ortalamas�n� bu adreste depolad���na ve e�er ortalama tam
   say� ise 1, de�ilse 0 d�nd�rd���ne g�re bu fonksiyon arac�l���yla iki tam say�n�n		Bo�luklar karakter say�lmad���na g�re, klavyeden girilen maksimum 1000 karakter uzunlu�undaki bir katar� her sat�rda bir karakter
   ortalamas�n� k�surat� varsa k�suratl�, yoksa k�surats�z yazd�ran program					daha yazd�racak �ekilde yazd�ran ve katar�n sonuna gelindi�inde her sat�rda bir karakter daha silecek bir �ekilde yazd�r�lan katar� silen program

int ortbul(int a,int b,float *avr) {														int main() {
	float x1,x2;																				char *katar=(char*) malloc(1000);
	x1=(float)(a+b)/2;																			int i,j;
	x2=(a+b)/2;																					printf("Katari giriniz: ");
	*avr=x1;																					gets(katar);
	if(x1==x2)																					katar=(char*) realloc(katar,strlen(katar)+1);
		return 1;																				printf("\n");
	else																						for(i=0;i<strlen(katar);i++) {
		return 0;																					for(j=0;j<=i;j++) {
}																										if(j==i && katar[j]==' ')
int main() {																								i++;
	int x,y;																							printf("%c",katar[j]);
	float ort;																						}
	scanf("%d%d",&x,&y);																			printf("\n");
	if(ortbul(x,y,&ort))																		}
		printf("%d",(int)ort);																	for(i=strlen(katar)-2;i>=0;i--) {
	else																							for(j=0;j<=i;j++) {
		printf("%.1f",ort);																				if(j==i && katar[j]==' ')
	return 0;																								i--;
}																										printf("%c",katar[j]);
																									}
   Ayn� tekrar say�s�na sahip birden fazla mod aday� varsa bunlardan en k����� mod olarak			printf("\n");
   al�nd���na g�re, klavyeden girilen bir say� dizisinin modunu (dizinin en �ok tekrar			}
   eden eleman�) ve bu modun tekrar say�s�n� yazd�ran program								}

int main() {																				Klavyeden s�ras�yla alt alta girilen a katar�, x de�eri, b katar� i�in a ve b katarlar� ile x de�eri 1 iken �nce a sonra b'yi,
	int gecici,i,j,n,sayac,max=0;															x de�eri 2 iken ise �nce b sonra a'y� yazd�rarak c�mle kuran program
	printf("Dizinin eleman sayisini girin: ");
	scanf("%d",&n);																			int main() {
	int *dizi=(int*) malloc(sizeof(int)*n);														char a[1000],b[1000];
	printf("Dizinin elemanlarini girin: ");														int x;
	for(i=0;i<n;i++)																			gets(a);
		scanf("%d",&dizi[i]);																	scanf("%d%*c",&x);
	for(i=0;i<n;i++) {																			gets(b);
		sayac=0;																				if(x==2) {
		for(j=0;j<n;j++)																			strcat(a," ");
			if(dizi[i]==dizi[j])																	puts(strcat(a,b));
				sayac++;																		}
		if(sayac>max) {																			if(x==1) {
			max=sayac;																				strcat(b," ");
			gecici=dizi[i];																			puts(strcat(b,a));
		}																						}
		if(sayac==max)																		}
			if(dizi[i]<gecici) {
				max=sayac;																	Klavyeden girilen r ve x de�erleri i�in klavyeden girilen bir dizinin kendisi ile ayn� perm�tasyondaki r elemanl� alt dizilerinin elemanlar
				gecici=dizi[i];																toplam�n�n ka� tanesinin x'e e�it oldu�unu yazd�ran program
			}
	}																						int main() {
	printf("Mod: %d\n",gecici);																	int i,j,r,x,N,toplam=0,sayac=0;
	printf("Tekrar sayisi: %d",max);															printf("Dizinin eleman sayisi: ");
}																								scanf("%d",&N);
																								int *dizi=(int*) malloc(N*sizeof(int));
   Klavyeden girilen elemanlar� 1 ila 10000 aras�nda de�i�en bir say� dizisinin modunu			printf("Diziyi giriniz: ");
   ve modunun tekrar say�s�n� counter array'i (saya� dizisi) tan�mlayarak yazd�ran				for(i=0;i<N;i++)
   alternatif program																				scanf("%d",&dizi[i]);
																								for(i=0;i<N-r+1;i++) {
int main() {																						for(j=0;j<r;j++)
	int n,i,mod,max=0;																					toplam+=dizi[i+j];
	printf("Dizinin eleman sayisini girin: ");														if(toplam==x)
	scanf("%d",&n);																						sayac++;
	int *dizi=(int*) malloc(n*sizeof(int));															toplam=0;
	int *sayac=(int*) malloc(10000*sizeof(int));												}
	printf("Dizinin elemanlarini girin: ");														printf("%d elemanli alt diziler arasinda elemanlar toplami %d olanlarin sayisi: %d",r,x,sayac);
	for(i=0;i<n;i++)																		}
		scanf("%d",&dizi[i]);
	for(i=1;i<=10000;i++)																	Klavyeden isimleri girilen d�zenli/d�zg�n �ok y�zl�lerin toplamda hepsinin ka� y�z� oldu�unu yazd�ran �ngilizce program
		sayac[i]=0;		//sayac dizisi dizinin her bir eleman�n�n
	for(i=0;i<n;i++)	//dizide toplamda ka� defa ge�ti�ini tutacak						int main() {
		sayac[dizi[i]]++;																		int i,n,sum=0;
	for(i=0;i<n;i++)																			printf("Enter the number of polyhedrons: ");
		if(sayac[dizi[i]]>max || (sayac[dizi[i]]==max && mod>dizi[i])) {						scanf("%d",&n);
			max=sayac[dizi[i]];																	for(i=0;i<n;i++) {
			mod=dizi[i];																			char shape[13];
		}																							scanf("%s",shape);
	printf("Mod: %d\nTekrar sayisi: %d",mod,max);													if(strcmp(shape,"Tetrahedron")==0)			sum+=4;
}																									else if(strcmp(shape,"Cube")==0)			sum+=6;
																									else if(strcmp(shape,"Octahedron")==0)		sum+=8;
   Klavyeden girilen bir dizide bir eleman�n bulunup bulunmad���n�, bulunuyorsa hangi				else if(strcmp(shape,"Dodecahedron")==0)	sum+=12;
   index'te veya index'lerde bulundu�unu da yazd�ran program										else if(strcmp(shape,"Icosahedron")==0)		sum+=20;
																								}
int main() {																					printf("Total number of faces: %d",sum);
	int i,x,n,k=1;																			}
	printf("Dizinin eleman sayisi: ");
	scanf("%d",&n);																			�ift n de�erleri i�in s�rayla 2, 2^2, 2^3, 2^4, ..., 2^n kuru�luk madeni paralar n/2'lik iki gruba ayr�lacakt�r.
	int *dizi=(int*) malloc(sizeof(int)*n);													Bu iki gruptaki madeni paralar�n toplamlar� fark�n�n minimum ka� olaca��n� yazd�ran program
	printf("Dizinin elemanlari: ");
	for(i=0;i<n;i++)																		int main() {
		scanf("%d",&dizi[i]);																	int t,n;
	printf("Aranacak elemani giriniz: ");														printf("Test senaryosu sayisini giriniz: ");
	scanf("%d",&x);																				scanf("%d",&t);
	for(i=0;i<n;i++)																			while(t--) {
		if(dizi[i]==x) {																			printf("Para sayisini giriniz: ");
			if(k>0) {																				scanf("%d",&n);		//tercihen 2<=n<=30 olursa iyi olur, malum INT_MAX'tan sonra overflow olur
				printf("Elemanin bulundugu index'ler: %d",i+1);										printf("Minimum fark: %d\n",(int)pow(2,n/2+1)-2);
				k--;																			}
			}		//linear search de, burada istenen eleman dizinin ayn� anda				}
			else	//her yerinde olabilece�i i�in binary search yap�lmaz zaten
				printf(" %d",i+1);
		}
		else if(i==n-1 && k==1)
			printf("Eleman bulunamadi");
}

   Klavyeden girilen bir c�mlenin pangram (Latin alfabesinin her harfini i�eren s�z) olup olmad���n� yazd�ran program

int main() {
	char i,cumle[500],pangram_flag=1;	//pangram_flag normalde bool olarak tan�mlan�rd�, ama C'de bool de�i�keni direkt olmad��� i�in
	int j;								//pangram_flag'i bool veri tipi ile RAM'de ayn� yeri kaplayan 1 byte'l�k char olarak tan�mlad�m
	printf("Bir cumle giriniz: ");
	gets(cumle);
	for(i='a';i<='z' && pangram_flag;i++)
		for(j=0;j<strlen(cumle);j++) {
			if(cumle[j]==i || cumle[j]==i-32)		//'a'-'A'=32
				break;			//k���k ya da b�y�k harf olan i char'� kelimede varsa 2. (j) for d�ng�s�nden ��k, bo� yere c�mlenin kalan harflerini tarama
			else if(j==strlen(cumle)-1)
				pangram_flag=0;	//son harfe kadar gelinip halen d�ng�den ��k�lmam��sa, bu c�mlede i char'� bulunmad��� i�in bu c�mle bir pangram de�ildir
		}
	printf(pangram_flag ? "\"%s\" bir pangram" : "\"%s\" bir pangram degil", cumle);
	return 0;
}

   Sefer ba��na bir biletin kullan�ld��� bir otob�s yolculu�u i�in gi�eden a TL'ye bir bilet veya b TL'ye topluca m tane bilet
   al�nabilmektedir. Bu de�erler ile ki�inin toplam yapaca�� sefer say�s� klavyeden girilece�ine g�re, n defa sefer yapacak
   birinin t�m yolculu�unu en az ka� TL'ye getirebilece�ini yazd�ran program

int main() {
	unsigned int n,m,a,b,sum=0;
	printf("Sefer sayisini giriniz: "); scanf("%u",&n);
	printf("Toplu biletlerin sayisini giriniz: "); scanf("%u",&m);
	printf("Tek biletin ve toplu biletlerin fiyatini TL cinsinden giriniz: "); scanf("%u%u",&a,&b);
	if(b/m<a) {
		if((n%m)*a>b)
			sum=ceil((double)n/m)*b;
		else
			sum=(n/m)*b+(n%m)*a;
	}
	else
		sum=n*a;
	printf("Minimum tutar: %u TL",sum);
}

   x+2x+4x+8x+...+(2^(k-1))*x serisinin toplam� klavyeden girilece�ine g�re bu seri toplam�n� sa�layan x ve k>1 pozitif tam say� ikililerini yazd�ran program */

int main() {
	unsigned int i,n,flag=1;
	printf("x+2x+4x+8x+...+(2^(k-1))*x serisinin toplamini giriniz: ");
	scanf("%u",&n);
	printf("\nx+2x+4x+8x+...+(2^(k-1))*x = %u denklemini saglayan k ve x degerleri:\n\n",n);
	for(i=2;(unsigned int)pow(2,i)-1<=n;i++)			//k 1'den b�y�k olmas� gerekti�i i�in i 2'den ba�l�yor, ve i burada k'y� temsil ediyor
		if(fmod(n,(unsigned int)pow(2,i)-1)==0.0) {		//x+2x+4x+8x+...+(2^(k-1))*x = (1+2+4+8+...+2^(k-1))*x = ((2^k)-1)*x = n
			printf("k = %u , x = %u\n",i,n/((unsigned int)pow(2,i)-1));
			flag=0;			//e�er n de�eri (2^k)-1 de�erine tam b�l�n�rse denklemi sa�layan pozitif k ve x tam say� de�erleri var demektir
		}					//e�er tek bir k,x ikilisi yazd�rmak isteseydim "break" komutunu eklerdim
	if(flag)
		puts("Bu denklemi saglayan herhangi bir k,x ikilisi yok, zaa");
	return 0;
}
