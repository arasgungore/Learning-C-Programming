#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Klavyeden girilen 5 tam sayýdan en büyük ve en küçük olanlarý yazdýran program							Eleman sayýsý klavyeyle girilen diziyi ters olarak yazdýran program

int main() {																								int main() {
	int a[5],max,min,i;																							int x,*dizi,i,gecici;
	for(i=0;i<5;i++) {																							printf("Eleman sayisi: ");
		printf("%d. sayiyi girin: ",i+1);																		scanf("%d",&x);
		scanf("%d",&a[i]);																						dizi=(int*) malloc(sizeof(int)*x);
	}																											for(i=0;i<x;i++) {
	max=min=a[0];	//karþýlaþtýrma yapabilmek için dizinin elemanlarýndan birini max ve min yaptým					printf("%d. Eleman: ",i+1);
	for(i=0;i<5;i++) {																								scanf("%d",dizi+i);
		if(a[i]<min)	//a[0]'dan küçük bir deðer varsa onu min yapar											}
		min=a[i];		//ondan da küçük bir deðer varsa onu min yapar
		if(a[i]>max)	//a[0]'dan büyük bir deðer varsa onu max yapar											for(i=0;i<x/2;i++) {
		max=a[i];		//ondan da büyük bir deðer varsa onu max yapar												gecici=dizi[i];
	}																												dizi[i]=dizi[x-i-1];
	printf("\nDizinin minimum (en kucuk) degeri: %d\n",min);														dizi[x-i-1]=gecici;
	printf("Dizinin maksimum (en buyuk) degeri: %d\n",max);														}
}																												printf("\nDizinin Tersi: ");
																												for(i=0;i<x;i++)
   Klavyeden girilen a ve b tam sayýlarý ile tanýmlanan [a,b] aralýðýndaki 1 ila 9 arasýndaki						printf("%d ",*(dizi+i));
   sayýlarýn adlarýný, 9'tan büyük sayýlar içinse sayýnýn tek mi çift mi olduðunu yazdýran program				}

int main() {																								Klavyeden girilen k ve n deðerleri için 1'den n'e kadar olan sayýlarýn birbirleri arasýndaki bitsel
	int a,b,i;																								ve (AND), veya (OR), özel veya (XOR) operatörleri ile iþlemlerinin döndürdüðü deðerlerin k sayýsýndan
	printf("Alt siniri giriniz: ");																			küçük olmak þartýyla maksimum deðerlerini yazdýran program
	scanf("%d",&a);
	printf("Ust siniri giriniz: ");																			int main() {
	scanf("%d",&b);																								int n,k,i,j,AND=0,OR=0,XOR=0,geciciAND,geciciOR,geciciXOR;
	for(i=a;i<=b;i++) {																							printf("n degerini girin: ");
		if(i==1)																								scanf("%d",&n);
		printf("bir\n");	//if, if, if,..., if, if yerine if, else if, else if,..., else if, else				printf("k degerini girin: ");
		else if(i==2)		//yapýsý kullanýlabilir																scanf("%d",&k);
		printf("iki\n");																						for(i=1;i<=n;i++) {
		else if(i==3)		//if, if, if,..., if, else yapýsýndaki "else" SADECE BÝR ÜSTTEKÝ "if" yapýsýna			for(j=i+1;j<=n;j++) {
		printf("uc\n");		//ait olduðundan if, else if, else if,..., else if, else yerine kullanýlamaz				geciciAND=i&j;
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

   Klavyeden girilen n ve r deðerleri için n elemanlý bir tam sayý kümesinin r elemanlý bütün alt kümelerini iterative recursion yaparak yazdýran program

void altkumebul(int dizi[], int altkume[], int bas, int son, int index, int r) {
	int i;
	if(index==r) {						//altkume[0]=dizi[0],altkume[1]=dizi[1],altkume[2]=dizi[2],...,altkume[r-1]=dizi[r-1]
		for(i=0;i<r;i++)				//altkume[0]=dizi[0],altkume[1]=dizi[1],altkume[2]=dizi[2],...,altkume[r-1]=dizi[r]
			printf("%d ",altkume[i]);	//altkume[0]=dizi[0],altkume[1]=dizi[1],altkume[2]=dizi[2],...,altkume[r-1]=dizi[r+1].....
		printf("\n");					//............................................................,altkume[r-1]=dizi[n-1]
		return;							//........................................altkume[r-2]=dizi[r-1],altkume[r-1]=dizi[r]
	}									//........................................altkume[r-2]=dizi[r-1],altkume[r-1]=dizi[r+1].....
	for(i=bas;i<=son && son-i+1>=r-index;i++) {		//............................altkume[r-2]=dizi[r-1],altkume[r-1]=dizi[n-1]...........
		altkume[index]=dizi[i];						//en baþtaki askýda kalan döngü en son okunuyor
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

   Klavyeden kenar uzunluklarý girilen üçgenleri alanlarýna göre küçükten büyüðe alt alta sýralayan program

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
	ucgen *tr=malloc(n*sizeof(ucgen));		//bir sürü üçgen kullanacaðýmýz için pointer ile struct'ýmý dizi yaptým   (sanki matris gibi ama deðil :p)
	for(i=0;i<n;i++) {
		yeniden:
		printf("%d. ucgen: ",i+1);
		scanf("%lf%lf%lf",&tr[i].a,&tr[i].b,&tr[i].c);		//scanf boþluktan sonrasýný algýlamadýðý için ben boþluða bastýðýmda bir sonraki deðiþkene geçecek
		if(tr[i].a>=tr[i].b+tr[i].c || tr[i].a<=abs(tr[i].b-tr[i].c) || tr[i].b>=tr[i].a+tr[i].c || tr[i].b<=abs(tr[i].a-tr[i].c) || tr[i].c>=tr[i].a+tr[i].b || tr[i].c<=abs(tr[i].a-tr[i].b)) {
			printf("Bu bir ucgen degildir, lutfen tekrar deneyiniz!!\n");		//üçgen eþitsizliði o_O
			goto yeniden;
		}
	}
	double *alan=malloc(n*sizeof(double));
	for(i=0;i<n;i++) {
		double p=(tr[i].a+tr[i].b+tr[i].c)/2.0;
		alan[i]=sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));	//Heron formülü: çevrenin yarýsý ve çevrenin yarýsý ile diðer kenarlarýn farklarýnýn çarpýmýnýn karekökü alaný verir
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(alan[i]<alan[j]) {
				double tut=alan[j];			//komplike bir swap; dizide farklý sýralamalarda (klavyeden benim girdiðim sýralamada) bulunan 2 üçgenin kenarlarýný ve alanlarýný birbiriyle deðiþtiriyorum
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

   Klavyeden girilen satýr sayýsýna göre Pascal üçgenini çizdiren program

int main() {
	int satir,i,j,a;
	printf("Satir sayisini giriniz: ");
	scanf("%d",&satir);
	printf("\n");
	for(i=1;i<=satir;i++) {
		a=1;					//her alt satýra geçildiðinde a'nýn deðeri 1 deðerine reset'lenecek böylelikle her satýr 1 elemaný ile baþlayacak
		for(j=1;j<=satir-i;j++)	//misal satýr sayýsý 10 ise her satýr için sýrayla 9,8,7,...,1,0 boþluk   (alttaki döngüde oluþturulan boþluklar hariç)
			printf(" ");
		for(j=0;j<i;j++) {
			printf(" %d ",a);	//Pascal üçgeninde (n+1). satýrda bulunan elemanlar bir öncekinin n,n-1/2,n-2/3,n-3/4,...,2/n-1,1/n katý biçiminde ilerler
			a=a*(i-j-1)/(j+1);	//misal 8. satýrdaki sayýlar 1 7 21 35 35 21 7 1'dir, ve her eleman bir öncekinin sýrayla 7,6/2,5/3,4/4,3/5,2/6,1/7 katýdýr
		}
		printf("\n");
	}
}

   Klavyeden girilen satýr sayýsýna göre Pascal üçgenini dinamik bellek tahsisi
   ve 2 boyutlu dizi yardýmýyla çizdiren alternatif program

int main() {
	int **pascal_ucgeni,satir_sayisi,i,j;
	printf("Satir sayisini giriniz: ");
	scanf("%d",&satir_sayisi);
	printf("\n");
	pascal_ucgeni=(int**) malloc(sizeof(int*)*satir_sayisi);

	for(i=0;i<satir_sayisi;i++) {
		pascal_ucgeni[i]=(int*) malloc(sizeof(int)*(i+1));
		pascal_ucgeni[i][0]=1;		//Pascal üçgeninin 1. satýrýnda 1 eleman, 2. satýrýnda 2 eleman,..., n.satýrýnda n tane eleman bulunur
		pascal_ucgeni[i][i]=1;
	}
									//Pascal üçgeninin her satýrý 1 ile baþlar ve 1 ile biter
	for(i=2;i<satir_sayisi;i++)
		for(j=1;j<i;j++)
			pascal_ucgeni[i][j]=pascal_ucgeni[i-1][j-1]+pascal_ucgeni[i-1][j];
									//Pascal üçgenindeki bir eleman sol üst çapraz ve sað üst çaprazýndaki sayýlarýn toplamýna eþittir
	for(i=0;i<satir_sayisi;i++) {
		for(j=0;j<satir_sayisi-i;j++)
			printf(" ");
		for(j=0;j<=i;j++)
			printf(" %d ",pascal_ucgeni[i][j]);
		printf("\n");
	}
}

   Klavyeden girilen cümleyi kendisini oluþturan büyük ve küçük harflerden her birini Ýngiliz alfabesindeki bir sonraki harfe kaydýrýlmýþ olarak þifreleyen program

int main() {																											Klavyeden girilen cümleyi kendisini oluþturan büyük ve küçük harflerden her birini ASCII kodlarýndan da
	char *cumle,kucuk_alfabe[26]="abcdefghijklmnopqrstuvwxyz",buyuk_alfabe[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";			yararlanarak Ýngiliz alfabesindeki bir sonraki harfe kaydýrýlmýþ olarak þifreleyen alternatif program
	int i,j;
	printf("Cumle yaziniz: ");																							int main() {
	cumle=(char*) malloc(1000);			//sizeof(char)=1 olduðu için çarpým durumunda yazmýyorum							char *cumle;
	gets(cumle);																											int i;
	cumle=(char*) realloc(cumle,strlen(cumle)+1);	//kelimemin bellekte gereksiz yer kaplamamasýný saðlýyorum				printf("Cumle yaziniz: ");
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
				if(cumle[i]==buyuk_alfabe[25])																							cumle[i]=cumle[i]+1;	//ASCII kodunu bir arttýrdým, mesela 'a'+1='b', 'f'+1='g', 'A'+1='B', 'H'+1='I'
					cumle[i]=buyuk_alfabe[0];																					}
				else																											printf("%c",cumle[i]);
					cumle[i]=buyuk_alfabe[j+1];																				}
				break;																									}
			}
		}
	}
	printf("\nYeni cumle: %s",cumle);
}

   n tane bilyenin her birinin üzerinde rastgele sayýlar bulunmaktadýr. n deðeri ve bilyelerin üzerinde yazan sayýlar rastgele bir sýrada klavyeden girileceðine göre alýnan bilyelerin üzerinde yazan sayýlar
   toplamýnýn geriye kalan bilyeler üzerinde yazan sayýlar toplamýndan daha büyük olmasý için minimum kaç tane bilye alýnmasý gerektiðini yazdýran program

int main() {																											n tane odanýn bulunduðu bir otelde Aras ve Mustafa birlikte kalacak otelde bir oda arýyorlardýr.
	int n,i,j,toplam=0,toplam2=0,gecici;																				Oda sayýsý, bu odalarda sýrayla kaç kiþi bulunduðu ve oda kapasitelerinin kaç kiþilik olduðu klavyeden
	printf("Bilye sayisini giriniz: ");																					girildiðine göre Aras ve Mustafa'nýn kaç tane odada birlikte kalabileceðini yazdýran program
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
			}		//swap sayesinde dizi büyükten küçüðe sýralý artýk														printf("Musait oda sayisi: %d",sayac);
	i=0;																												}
	while(toplam2<=toplam/2 && i<n) {
		toplam2+=dizi[i];
		i++;		//en büyük sayýlardan itibaren bilyeleri almaya baþlýyorum, bunun sayýsýný da i sayacý tutuyor
	}
	printf("Minimum alinmasi gereken bilye sayisi: %d",i);
	return 0;
}

   Klavyeden girilen maksimum 1000 karakter uzunluðundaki cümleyi harf ve boþluk haricindeki tüm karakterlerden arýndýrarak yazdýran program

int main() {									//sorunun alternatif çözümü:  int main() {
	char k,cumle[1000];														//    char cumle1[1000],cumle2[1000];
	int i=0;																//    int i,j=0;
	printf("Cumleyi giriniz: ");											//    printf("Cumleyi giriniz: ");
	while(scanf("%c",&k) && k!='\n')										//    gets(cumle1);
		if(('a'<=k && k<='z') || ('A'<=k && k<='Z') || k==' ')				//    for(i=0;i<strlen(cumle1);i++)
			cumle[i++]=k;													//    if(('a'<=cumle1[i] && cumle1[i]<='z') || ('A'<=cumle1[i] && cumle1[i]<='Z') || cumle1[i]==' ')
	printf("Arindirilmis cumle: %s",cumle);									//    cumle2[j++]=cumle1[i];
}																			//    printf("Arindirilmis cumle: %s",cumle);
																			//}

   Klavyeden sýrayla girilen a ve b deðerleri için a sayýsýna en yakýn b tane asal sayýyý ayný uzaklýktaki sayýlardan öncelikle küçük olan sayýlarý yazdýrmak þartýyla sýrayla artan uzaklýkta yazdýran program

int asalsorgula(int sayi) {																								z1=a+bi ve z2=c+di için z1*z2=(ac-bd)+(ad+bc)i olduðuna göre klavyeden ondalýk olarak reel ve imajiner
	int i;																												kýsýmlarý girilen bir sanal sayýnýn p. kuvvetini fonksiyon çaðýrarak yazdýran program
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
			printf("%d ",num-i);																						1 ila 1000 arasýndaki pozitif tam sayýlarý, ortada tek çarpan ve bu çarpanýn etrafýnda 2 çarpanlarý
		}																												olacak þekilde ifade eden recursive program
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
   Klavyeden girilen iki sayýnýn EKOK ve EBOB'unu hesaplayan iterative program													printf(" * 2");
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

   Klavyeden negatif bir sayý girilene kadar girilen sayýlarýn ortalamasýný ve karþýlýk geldiði kelimeyi önce küçük sonra büyük harflerle yazdýran recursive program

void oncekucuksonrabuyukyazdir(int* arr, int arr_size, int index) {		//arr_size parametresi atamak yerine "sizeof(arr)/sizeof(arr[0])" ifadesini kullanamam, çok yanlýþ olur
	if(index==arr_size) {												//o ifadeyi yalnýzca main fonksiyonu içerisinde tanýmlanan diziler için kullanabilirim
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

   En sol basamaðý hariç diðer bütün basamaklarý 0 olan pozitif tam sayýlara yuvarlak dendiðine göre, klavyeden girilen sayýlarý yuvarlak tam sayýlarýn toplamý biçiminde yazdýran program */

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
