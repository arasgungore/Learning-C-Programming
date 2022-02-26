#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Klavyeden girilen 5 tam say�dan en b�y�k ve en k���k olanlar� yazd�ran program							Eleman say�s� klavyeyle girilen diziyi ters olarak yazd�ran program

int main() {																								int main() {
	int a[5],max,min,i;																							int x,*dizi,i,gecici;
	for(i=0;i<5;i++) {																							printf("Eleman sayisi: ");
		printf("%d. sayiyi girin: ",i+1);																		scanf("%d",&x);
		scanf("%d",&a[i]);																						dizi=(int*) malloc(sizeof(int)*x);
	}																											for(i=0;i<x;i++) {
	max=min=a[0];	//kar��la�t�rma yapabilmek i�in dizinin elemanlar�ndan birini max ve min yapt�m					printf("%d. Eleman: ",i+1);
	for(i=0;i<5;i++) {																								scanf("%d",dizi+i);
		if(a[i]<min)	//a[0]'dan k���k bir de�er varsa onu min yapar											}
		min=a[i];		//ondan da k���k bir de�er varsa onu min yapar
		if(a[i]>max)	//a[0]'dan b�y�k bir de�er varsa onu max yapar											for(i=0;i<x/2;i++) {
		max=a[i];		//ondan da b�y�k bir de�er varsa onu max yapar												gecici=dizi[i];
	}																												dizi[i]=dizi[x-i-1];
	printf("\nDizinin minimum (en kucuk) degeri: %d\n",min);														dizi[x-i-1]=gecici;
	printf("Dizinin maksimum (en buyuk) degeri: %d\n",max);														}
}																												printf("\nDizinin Tersi: ");
																												for(i=0;i<x;i++)
   Klavyeden girilen a ve b tam say�lar� ile tan�mlanan [a,b] aral���ndaki 1 ila 9 aras�ndaki						printf("%d ",*(dizi+i));
   say�lar�n adlar�n�, 9'tan b�y�k say�lar i�inse say�n�n tek mi �ift mi oldu�unu yazd�ran program				}

int main() {																								Klavyeden girilen k ve n de�erleri i�in 1'den n'e kadar olan say�lar�n birbirleri aras�ndaki bitsel
	int a,b,i;																								ve (AND), veya (OR), �zel veya (XOR) operat�rleri ile i�lemlerinin d�nd�rd��� de�erlerin k say�s�ndan
	printf("Alt siniri giriniz: ");																			k���k olmak �art�yla maksimum de�erlerini yazd�ran program
	scanf("%d",&a);
	printf("Ust siniri giriniz: ");																			int main() {
	scanf("%d",&b);																								int n,k,i,j,AND=0,OR=0,XOR=0,geciciAND,geciciOR,geciciXOR;
	for(i=a;i<=b;i++) {																							printf("n degerini girin: ");
		if(i==1)																								scanf("%d",&n);
		printf("bir\n");	//if, if, if,..., if, if yerine if, else if, else if,..., else if, else				printf("k degerini girin: ");
		else if(i==2)		//yap�s� kullan�labilir																scanf("%d",&k);
		printf("iki\n");																						for(i=1;i<=n;i++) {
		else if(i==3)		//if, if, if,..., if, else yap�s�ndaki "else" SADECE B�R �STTEK� "if" yap�s�na			for(j=i+1;j<=n;j++) {
		printf("uc\n");		//ait oldu�undan if, else if, else if,..., else if, else yerine kullan�lamaz				geciciAND=i&j;
		else if(i==4)																									geciciOR=i|j;
		printf("dort\n");																								geciciXOR=i^j;
		else if(i==5)																									if(geciciAND>AND && geciciAND<k)
		printf("bes\n");																								AND=geciciAND;
		else if(i==6)																									if(geciciOR>OR && geciciOR<k)
		printf("alti\n");																								OR=geciciOR;
		else if(i==7)																									if(geciciXOR>XOR && geciciXOR<k)
		printf("yedi\n");																								XOR=geciciXOR;
		else if(i==8)																								}
		printf("sekiz\n");																						}
		else if(i==9)																							printf("max(AND)<k: %d\nmax(OR)<k: %d\nmax(XOR)<k: %d",AND,OR,XOR);
		printf("dokuz\n");																					}
		else {
			if(i%2==0)
			printf("cift\n");
			else
			printf("tek\n");
		}
	}
}

   Klavyeden girilen n ve r de�erleri i�in n elemanl� bir tam say� k�mesinin r elemanl� b�t�n alt k�melerini iterative recursion yaparak yazd�ran program

void altkumebul(int dizi[], int altkume[], int bas, int son, int index, int r) {
	int i;
	if(index==r) {						//altkume[0]=dizi[0],altkume[1]=dizi[1],altkume[2]=dizi[2],...,altkume[r-1]=dizi[r-1]
		for(i=0;i<r;i++)				//altkume[0]=dizi[0],altkume[1]=dizi[1],altkume[2]=dizi[2],...,altkume[r-1]=dizi[r]
			printf("%d ",altkume[i]);	//altkume[0]=dizi[0],altkume[1]=dizi[1],altkume[2]=dizi[2],...,altkume[r-1]=dizi[r+1].....
		printf("\n");					//............................................................,altkume[r-1]=dizi[n-1]
		return;							//........................................altkume[r-2]=dizi[r-1],altkume[r-1]=dizi[r]
	}									//........................................altkume[r-2]=dizi[r-1],altkume[r-1]=dizi[r+1].....
	for(i=bas;i<=son && son-i+1>=r-index;i++) {		//............................altkume[r-2]=dizi[r-1],altkume[r-1]=dizi[n-1]...........
		altkume[index]=dizi[i];						//en ba�taki ask�da kalan d�ng� en son okunuyor
		altkumebul(dizi, altkume, i+1, son, index+1, r);
	}
}
int main() {
	int *dizi,*altkume,n,r,i;
	printf("Eleman sayisi: ");
	scanf("%d",&n);
	dizi=(int*) malloc(sizeof(int)*n);
	printf("\nElemanlari girin: ");
	for(i=0;i<n;i++)
		scanf("%d",&dizi[i]);
	printf("Alt kumelerin eleman sayisi: ");
	scanf("%d",&r);
	altkume=(int*) malloc(sizeof(int)*r);
	altkumebul(dizi, altkume, 0, n-1, 0, r);
}

   Klavyeden kenar uzunluklar� girilen ��genleri alanlar�na g�re k���kten b�y��e alt alta s�ralayan program

struct ucgen {
	double a;
	double b;
	double c;
};
typedef struct ucgen ucgen;
void swap(double *a,double *b) {
	double tut=*a;
	*a=*b;
	*b=tut;
}

int main() {
	int n,i,j;
	printf("Ucgen sayisi: ");
	scanf("%d",&n);
	ucgen *tr=malloc(n*sizeof(ucgen));		//bir s�r� ��gen kullanaca��m�z i�in pointer ile struct'�m� dizi yapt�m   (sanki matris gibi ama de�il :p)
	for(i=0;i<n;i++) {
		yeniden:
		printf("%d. ucgen: ",i+1);
		scanf("%lf%lf%lf",&tr[i].a,&tr[i].b,&tr[i].c);		//scanf bo�luktan sonras�n� alg�lamad��� i�in ben bo�lu�a bast���mda bir sonraki de�i�kene ge�ecek
		if(tr[i].a>=tr[i].b+tr[i].c || tr[i].a<=abs(tr[i].b-tr[i].c) || tr[i].b>=tr[i].a+tr[i].c || tr[i].b<=abs(tr[i].a-tr[i].c) || tr[i].c>=tr[i].a+tr[i].b || tr[i].c<=abs(tr[i].a-tr[i].b)) {
			printf("Bu bir ucgen degildir, lutfen tekrar deneyiniz!!\n");		//��gen e�itsizli�i o_O
			goto yeniden;
		}
	}
	double *alan=malloc(n*sizeof(double));
	for(i=0;i<n;i++) {
		double p=(tr[i].a+tr[i].b+tr[i].c)/2.0;
		alan[i]=sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));	//Heron form�l�: �evrenin yar�s� ve �evrenin yar�s� ile di�er kenarlar�n farklar�n�n �arp�m�n�n karek�k� alan� verir
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(alan[i]<alan[j]) {
				double tut=alan[j];			//komplike bir swap; dizide farkl� s�ralamalarda (klavyeden benim girdi�im s�ralamada) bulunan 2 ��genin kenarlar�n� ve alanlar�n� birbiriyle de�i�tiriyorum
				swap(&alan[i],&alan[j]);
				swap(&tr[i].a,&tr[j].a);
				swap(&tr[i].b,&tr[j].b);
				swap(&tr[i].c,&tr[j].c);
			}
		}
	}
	printf("\n\n");
	for(i=0;i<n;i++)
		printf("%lf %lf %lf\t\tAlani: %lf\n",tr[i].a,tr[i].b,tr[i].c,alan[i]);
}

   Klavyeden girilen sat�r say�s�na g�re Pascal ��genini �izdiren program

int main() {
	int satir,i,j,a;
	printf("Satir sayisini giriniz: ");
	scanf("%d",&satir);
	printf("\n");
	for(i=1;i<=satir;i++) {
		a=1;					//her alt sat�ra ge�ildi�inde a'n�n de�eri 1 de�erine reset'lenecek b�ylelikle her sat�r 1 eleman� ile ba�layacak
		for(j=1;j<=satir-i;j++)	//misal sat�r say�s� 10 ise her sat�r i�in s�rayla 9,8,7,...,1,0 bo�luk   (alttaki d�ng�de olu�turulan bo�luklar hari�)
			printf(" ");
		for(j=0;j<i;j++) {
			printf(" %d ",a);	//Pascal ��geninde (n+1). sat�rda bulunan elemanlar bir �ncekinin n,n-1/2,n-2/3,n-3/4,...,2/n-1,1/n kat� bi�iminde ilerler
			a=a*(i-j-1)/(j+1);	//misal 8. sat�rdaki say�lar 1 7 21 35 35 21 7 1'dir, ve her eleman bir �ncekinin s�rayla 7,6/2,5/3,4/4,3/5,2/6,1/7 kat�d�r
		}
		printf("\n");
	}
}

   Klavyeden girilen sat�r say�s�na g�re Pascal ��genini dinamik bellek tahsisi
   ve 2 boyutlu dizi yard�m�yla �izdiren alternatif program

int main() {
	int **pascal_ucgeni,satir_sayisi,i,j;
	printf("Satir sayisini giriniz: ");
	scanf("%d",&satir_sayisi);
	printf("\n");
	pascal_ucgeni=(int**) malloc(sizeof(int*)*satir_sayisi);

	for(i=0;i<satir_sayisi;i++) {
		pascal_ucgeni[i]=(int*) malloc(sizeof(int)*(i+1));
		pascal_ucgeni[i][0]=1;		//Pascal ��geninin 1. sat�r�nda 1 eleman, 2. sat�r�nda 2 eleman,..., n.sat�r�nda n tane eleman bulunur
		pascal_ucgeni[i][i]=1;
	}
									//Pascal ��geninin her sat�r� 1 ile ba�lar ve 1 ile biter
	for(i=2;i<satir_sayisi;i++)
		for(j=1;j<i;j++)
			pascal_ucgeni[i][j]=pascal_ucgeni[i-1][j-1]+pascal_ucgeni[i-1][j];
									//Pascal ��genindeki bir eleman sol �st �apraz ve sa� �st �apraz�ndaki say�lar�n toplam�na e�ittir
	for(i=0;i<satir_sayisi;i++) {
		for(j=0;j<satir_sayisi-i;j++)
			printf(" ");
		for(j=0;j<=i;j++)
			printf(" %d ",pascal_ucgeni[i][j]);
		printf("\n");
	}
}

   Klavyeden girilen c�mleyi kendisini olu�turan b�y�k ve k���k harflerden her birini �ngiliz alfabesindeki bir sonraki harfe kayd�r�lm�� olarak �ifreleyen program

int main() {																											Klavyeden girilen c�mleyi kendisini olu�turan b�y�k ve k���k harflerden her birini ASCII kodlar�ndan da
	char *cumle,kucuk_alfabe[26]="abcdefghijklmnopqrstuvwxyz",buyuk_alfabe[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";			yararlanarak �ngiliz alfabesindeki bir sonraki harfe kayd�r�lm�� olarak �ifreleyen alternatif program
	int i,j;
	printf("Cumle yaziniz: ");																							int main() {
	cumle=(char*) malloc(1000);			//sizeof(char)=1 oldu�u i�in �arp�m durumunda yazm�yorum							char *cumle;
	gets(cumle);																											int i;
	cumle=(char*) realloc(cumle,strlen(cumle)+1);	//kelimemin bellekte gereksiz yer kaplamamas�n� sa�l�yorum				printf("Cumle yaziniz: ");
	for(i=0;i<strlen(cumle);i++) {																							cumle=(char*) malloc(1000);
		for(j=0;j<26;j++) {																									gets(cumle);
			if(cumle[i]==kucuk_alfabe[j]) {																					cumle=(char*) realloc(cumle,strlen(cumle)+1);
				if(cumle[i]==kucuk_alfabe[25])																				printf("Yeni cumle: ");
					cumle[i]=kucuk_alfabe[0];																				for(i=0;i<strlen(cumle);i++) {
				else																											if(cumle[i]!=' ') {
					cumle[i]=kucuk_alfabe[j+1];																						if(cumle[i]=='z')
				break;																													cumle[i]=a;
			}																														else if(cumle[i]=='Z')
																																		cumle[i]=A;
			if(cumle[i]==buyuk_alfabe[j]) {																							else
				if(cumle[i]==buyuk_alfabe[25])																							cumle[i]=cumle[i]+1;	//ASCII kodunu bir artt�rd�m, mesela 'a'+1='b', 'f'+1='g', 'A'+1='B', 'H'+1='I'
					cumle[i]=buyuk_alfabe[0];																					}
				else																											printf("%c",cumle[i]);
					cumle[i]=buyuk_alfabe[j+1];																				}
				break;																									}
			}
		}
	}
	printf("\nYeni cumle: %s",cumle);
}

   n tane bilyenin her birinin �zerinde rastgele say�lar bulunmaktad�r. n de�eri ve bilyelerin �zerinde yazan say�lar rastgele bir s�rada klavyeden girilece�ine g�re al�nan bilyelerin �zerinde yazan say�lar
   toplam�n�n geriye kalan bilyeler �zerinde yazan say�lar toplam�ndan daha b�y�k olmas� i�in minimum ka� tane bilye al�nmas� gerekti�ini yazd�ran program

int main() {																											n tane odan�n bulundu�u bir otelde Aras ve Mustafa birlikte kalacak otelde bir oda ar�yorlard�r.
	int n,i,j,toplam=0,toplam2=0,gecici;																				Oda say�s�, bu odalarda s�rayla ka� ki�i bulundu�u ve oda kapasitelerinin ka� ki�ilik oldu�u klavyeden
	printf("Bilye sayisini giriniz: ");																					girildi�ine g�re Aras ve Mustafa'n�n ka� tane odada birlikte kalabilece�ini yazd�ran program
	scanf("%d",&n);
	int *dizi=(int*) malloc(sizeof(int)*n);																				int main() {
	printf("Bilyelerin uzerinde yazan sayilari giriniz: ");																	int i,oda_sayisi,sayac=0;
	for(i=0;i<n;i++) {																										printf("Oda sayisini giriniz: ");
		scanf("%d",&dizi[i]);																								scanf("%d",&oda_sayisi);
		toplam+=dizi[i];																									int **odalar=(int**) malloc(sizeof(int*)*oda_sayisi);
	}																														for(i=0;i<oda_sayisi;i++) {
	for(i=0;i<n;i++)																											odalar[i]=(int*) malloc(sizeof(int)*2);
		for(j=0;j<n;j++)																										printf("%d. odanin mevcudunu ve kapasitesini giriniz: ",i+1);
			if(dizi[i]>dizi[j]) {																								scanf("%d%d",&odalar[i][0],&odalar[i][1]);
				gecici=dizi[i];																									if(odalar[i][1]-odalar[i][0]>=2)
				dizi[i]=dizi[j];																									sayac++;
				dizi[j]=gecici;																								}
			}		//swap sayesinde dizi b�y�kten k����e s�ral� art�k														printf("Musait oda sayisi: %d",sayac);
	i=0;																												}
	while(toplam2<=toplam/2 && i<n) {
		toplam2+=dizi[i];
		i++;		//en b�y�k say�lardan itibaren bilyeleri almaya ba�l�yorum, bunun say�s�n� da i sayac� tutuyor
	}
	printf("Minimum alinmasi gereken bilye sayisi: %d",i);
	return 0;
}

   Klavyeden girilen maksimum 1000 karakter uzunlu�undaki c�mleyi harf ve bo�luk haricindeki t�m karakterlerden ar�nd�rarak yazd�ran program

int main() {									//sorunun alternatif ��z�m�:  int main() {
	char k,cumle[1000];														//    char cumle1[1000],cumle2[1000];
	int i=0;																//    int i,j=0;
	printf("Cumleyi giriniz: ");											//    printf("Cumleyi giriniz: ");
	while(scanf("%c",&k) && k!='\n')										//    gets(cumle1);
		if(('a'<=k && k<='z') || ('A'<=k && k<='Z') || k==' ')				//    for(i=0;i<strlen(cumle1);i++)
			cumle[i++]=k;													//    if(('a'<=cumle1[i] && cumle1[i]<='z') || ('A'<=cumle1[i] && cumle1[i]<='Z') || cumle1[i]==' ')
	printf("Arindirilmis cumle: %s",cumle);									//    cumle2[j++]=cumle1[i];
}																			//    printf("Arindirilmis cumle: %s",cumle);
																			//}

   Klavyeden s�rayla girilen a ve b de�erleri i�in a say�s�na en yak�n b tane asal say�y� ayn� uzakl�ktaki say�lardan �ncelikle k���k olan say�lar� yazd�rmak �art�yla s�rayla artan uzakl�kta yazd�ran program

int asalsorgula(int sayi) {																								z1=a+bi ve z2=c+di i�in z1*z2=(ac-bd)+(ad+bc)i oldu�una g�re klavyeden ondal�k olarak reel ve imajiner
	int i;																												k�s�mlar� girilen bir sanal say�n�n p. kuvvetini fonksiyon �a��rarak yazd�ran program
	for(i=2;i<=sqrt(sayi);i++)
		if(sayi%i==0)																									void complex_power(double a,double b,int p,double *re,double *im) {
			return 0;																										int i;
	if(sayi>1)																												double reold=*re;
		return 1;																											for(i=1;i<p;i++) {
	else																														*re=a*(*re)-b*(*im);
		return 0;																												*im=a*(*im)+b*reold;
}																																reold=*re;
int main() {																												}
	int num,N,i=1;																										}
	printf("Klavyeden 2 deger giriniz: ");																				int main() {
	scanf("%d%d",&num,&N);																									double a,b;
	printf("%d sayina en yakin %d asal sayi: ",num,N);																		int p;
	if(asalsorgula(num)) {																									printf("(a+bi)^p ifadesindeki a, b ve p degerlerini giriniz: ");
		N--;																												scanf("%lf%lf%d",&a,&b,&p);
		printf("%d ",num);																									double re=a,im=b;
	}																														complex_power(a,b,p,&re,&im);
	while(N>0) {																											printf("Sayinin %d. kuvveti: %.4f+%.4fi",p,re,im);
		if(asalsorgula(num-i)) {																						}
			N--;
			printf("%d ",num-i);																						1 ila 1000 aras�ndaki pozitif tam say�lar�, ortada tek �arpan ve bu �arpan�n etraf�nda 2 �arpanlar�
		}																												olacak �ekilde ifade eden recursive program
		if(N<=0)
			break;																										void printTwos(int value) {
		if(asalsorgula(num+i)) {																							if(!(value%2)) {
			N--;																												printf("2 * ");
			printf("%d ",num+i);																								value/=2;
		}																													}
		i++;																												if(value%2)
	}																															printf("%d",value);
}																															else {
																																printTwos(value/2);
   Klavyeden girilen iki say�n�n EKOK ve EBOB'unu hesaplayan iterative program													printf(" * 2");
																															}
int main() {																											}
	int i,x,y,ekok,ebob;																								int main() {
	printf("Iki tane sayi giriniz: ");																						int i;
	scanf("%d %d",&x,&y);																									for(i=1;i<=1000;i++) {
	for(i=1;i<=x && i<=y;i++)																									printf("%d = ",i);
		if(x%i==0 && y%i==0)																									printTwos(i);
			ebob=i;																												printf("\n");
	for(i=x*y;i>=x && i>=y;i--)																								}
		if(i%x==0 && i%y==0)																							}
			ekok=i;
	printf("\nEKOK: %d\nEBOB: %d",ekok,ebob);
}

   Klavyeden negatif bir say� girilene kadar girilen say�lar�n ortalamas�n� ve kar��l�k geldi�i kelimeyi �nce k���k sonra b�y�k harflerle yazd�ran recursive program

void oncekucuksonrabuyukyazdir(int* arr, int arr_size, int index) {		//arr_size parametresi atamak yerine "sizeof(arr)/sizeof(arr[0])" ifadesini kullanamam, �ok yanl�� olur
	if(index==arr_size) {												//o ifadeyi yaln�zca main fonksiyonu i�erisinde tan�mlanan diziler i�in kullanabilirim
		printf("\n");
		return;
	}
	if(index==0)
		printf("Kucuk kelime: ");
	printf("%c",arr[index]);
	oncekucuksonrabuyukyazdir(arr,arr_size,index+1);
	if(index==arr_size-1)
		printf("Buyuk kelime: ");
	printf("%c",arr[arr_size-1-index]-'a'+'A');
}
int main() {
	int x,sayac=0,toplam=0,*dizi=(int*) malloc(1000*sizeof(int));
	printf("1-26 arasindan sayilar giriniz (1-a 2-b 3-c ... 26-z): ");
	while(scanf("%d",&x) && x>=0) {
		toplam+=x;
		x = x>26 ? 'z' : (x==0 ? 'a' : x+'a'-1);
		dizi[sayac++]=x;
	}
	realloc(dizi,sayac*sizeof(int));
	oncekucuksonrabuyukyazdir(dizi,sayac,0);
	printf("\nOrtalama: %lf",(double)toplam/sayac);
	return 0;
}

   En sol basama�� hari� di�er b�t�n basamaklar� 0 olan pozitif tam say�lara yuvarlak dendi�ine g�re, klavyeden girilen say�lar� yuvarlak tam say�lar�n toplam� bi�iminde yazd�ran program */

int main() {
	unsigned int test_sayisi;
	printf("Kac sayi girilecegini giriniz: ");
	scanf("%u",&test_sayisi);
	while(test_sayisi--) {								//alternatif olarak:
		unsigned int sayi,i,sayac=0;									//int main() {
		printf("\nSayi giriniz: ");										//    unsigned int test_sayisi;
		scanf("%u",&sayi);												//    printf("Kac sayi girilecegini giriniz: ");
		char string[11];												//    scanf("%u",&test_sayisi);
		itoa(sayi,string,10);											//    while(test_sayisi--) {
		for(i=0;i<strlen(string);i++)									//        unsigned int sayi,arr[6],sayac=0,p=1,i;
			if(string[i]!='0')											//        printf("\nSayi giriniz: ");
				sayac++;												//        scanf("%u",&sayi);
		printf("Yuvarlak sayilarin sayisi: %u\n%u = ",sayac,sayi);		//        for(;sayi>0;p*=10,sayi/=10)
		unsigned int n=(unsigned int)log10(sayi)+1;						//            if((arr[sayac]=(sayi%10)*p)>0)
		for(i=0;i<n;i++,sayi/=10) {										//                sayac++;
			int rakam=sayi%10;											//        printf("Yuvarlak sayilarin sayisi: %u\n%u = ",sayac,sayi);
			if(rakam!=0)												//        for(i=0;i<sayac;i++)
				printf("%u + ",(unsigned int)(rakam*pow(10,i)));		//            printf("%u + ",arr[i]);
		}																//        printf("\b\b\b  \n");
		printf("\b\b\b  \n");											//    }
	}																	//    return 0;
	return 0;															//}
}
