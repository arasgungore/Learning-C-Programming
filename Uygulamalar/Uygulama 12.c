#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

/* Klavyeden girilen 4 tam sayýdan en büyük olaný array kullanmadan ve sadece if else içeren bir fonksiyon yardýmýyla döndüren program

int max_of_four(int a, int b, int c, int d) {														Babil yöntemiyle klavyeden girilen sayýnýn karekökünü hesaplayan program
	int max;
	if(a>b) {																						int main() {
		if(a>c) {																						double kok=1,sayi;
			if(a>d)																						int i;
				max=a;
			else																						printf("Karekoku hesaplanacak sayiyi girin: ");
				max=d;																					scanf("%lf",&sayi);
		}
		else {																							for(i=0;i<20;i++)			//20 iterasyon yeterli, zira daha fazla precision'ý bilgisayar bellekte tutmuyor
			if(c>d)																							kok=(sayi/kok+kok)/2;	//sayýnýn köke bölümü köke eklenir ve 2'ye bölünür, ayný iþlem yeni kök üzerinden devam eder
				max=c;
			else																						printf("\nSayinin karekoku:\t%.20f",kok);
				max=d;																					printf("\nsqrt(%lf):\t%.20f",sayi,sqrt(sayi));
		}																								printf("\n\nSon hanesine kadar ayni ;)");		//aslýnda %.15f de kullanabilirdim, zira virgülden sonra 15. haneden sonrasý 0
	}																									//yani 15. haneden sonrasý hafýzada tutulmuyor, ama sqrt() fonksiyonunun precision'ýnýn 15 hane olduðunu göstermek için böyle yaptým
	else {																								return 0;
		if(b>c) {																					}
			if(b>d)
				max=b;																				cos(x)=x^3 denkleminin kökünü hesaplayýp yazdýran program
			else
				max=d;																				int main() {
		}																								long double x=0.50L;
		else {																							int i;
			if(c>d)
				max=c;																					for(i=0;i<10;i++)		//Newton'un metodunu kullandým, yukarýdaki Babil yöntemi de aslýnda bu yöntemden türeyen özel bir metot
			else																							x=(x-((cos(x)-pow(x,3))/(-sin(x)-3*pow(x,2))));		//ayrýca 10 iterasyon yeter xd
				max=d;
		}																								printf("cos(x)=x^3 denkleminin koku: %.15f",(double)x);
	}																								}
	return max;
}
int main() {
	int a,b,c,d;
	printf("Dort tane sayi giriniz: ");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	int ans=max_of_four(a,b,c,d);
	printf("Max: %d",ans);
}

   Klavyeden girilen bir katarý palindrom yapmak için katarýn baþýna, içine veya sonuna toplam kaç harf eklenmesi gerektiðini yazdýran recursive program

//int min(int a,int b) { return a<b ? a : b; }			min fonksiyonu <windows.h> kütüphanesinde makro olarak tanýmlý zaten ;)
int MinEklemeSayisiniBul(char str[], int bas, int son) {
	if(bas>son) return INT_MAX;		//base case'ler
	else if(bas==son) return 0;
	else if(bas==son-1) return str[bas]==str[son] ? 0 : 1;

	return str[bas]==str[son] ? MinEklemeSayisiniBul(str,bas+1,son-1) : (min(MinEklemeSayisiniBul(str,bas,son-1),MinEklemeSayisiniBul(str,bas+1,son)) + 1);
}
void PalindromMuDegilMi(char x[]) {
	if(MinEklemeSayisiniBul(x,0,strlen(x)-1)>0)
		printf("\"%s\"i palindrom yapmak icin gereken ekleme sayisi: %d\n",x,MinEklemeSayisiniBul(x,0,strlen(x)-1));
	else
		printf("\"%s\" bir palindromdur.\n",x);
}
int main() {
	char a[]="amcik",b[]="palindrom",c[]="racecar",d[]="monoton";
	PalindromMuDegilMi(a);
	PalindromMuDegilMi(b);
	PalindromMuDegilMi(c);
	PalindromMuDegilMi(d);

	char kullanicigirsin[1000];
	printf("Kendiniz bir string giriniz: ");
	gets(kullanicigirsin);
	PalindromMuDegilMi(kullanicigirsin);
}

   Üzerinde rastgele deðerler yazan n tane madeni paranýn konu olduðu bir oyunda 2 kiþi oyunun sonunda en büyük toplamý elde etmeye çalýþacaktýr. 2 kiþinin de oyunu en iyi þekilde oynadýðý bilindiðine göre,
   ilk baþlayan kiþinin elde edebileceði en büyük toplamý yazdýran ve optimum strateji algoritmasýyla çalýþan Ýngilizce program

//int min(int a,int b) { return a<b ? a : b; }
//int max(int a,int b) { return a>b ? a : b; }		<windows.h> kütüphanesini import etmeseydik bu þekilde min() ve max() fonksiyonlarýný tanýmlamamýz gerekebilirdi, neyseki hazýr implement edilmiþ :)
void optimalStrategyOfGame(int* arr, int n) {	//bir oyuncunun n tane madeni paradan toplayabileceði en büyük toplamý yazdýran fonksiyon (n çift olmalý)
	int **table=malloc(n*sizeof(int*)),i,j,gap;
	for(i=0;i<n;i++)
		table[i]=malloc(n*sizeof(int));			//dinamik bellek organizasyonu ile i. hamleden sonraki durumlarý table[i-1] dizisinde saklayan n*n'lik bir **table matrisi oluþturdum
	for(gap=0;gap<n;gap++)		//tabloyu aþaðýdaki recursive formülü kullanarak çapraz þekilde doldur
		for(i=0,j=gap;j<n;i++,j++) {
			int x= i+2<=j ? table[i+2][j] : 0;
			int y= i+1<=j-1 ? table[i+1][j-1] : 0;
			int z= i<=j-2 ? table[i][j-2] : 0;
			table[i][j]=max(arr[i]+min(x,y),arr[j]+min(y,z));
		}	//F(a,b) a. paradan b.paraya kadar elde edilebilecek en büyük toplam olduðuna göre x=F(i+2,j), y=F(i+1,j-1) ve z=F(i,j-2)
	printf("Optimal strategy for game {");		//F(i,j) = max(Vi + min(F(i+2,j),F(i+1,j-1)) , Vj + min(F(i+1,j-1),F(i,j-2)))
	for(i=0;i<n;i++)
		printf("%d,",arr[i]);
	printf("\b} is: %d\n",table[0][n-1]);															Rastgele karakterlerin yer aldýðý harfler1.txt dosyasýnýn özel karakterler haricindeki her karakterini bir arttýrarak harfler2.txt
}																									belgesine dosyanýn orijinal biçimini koruyarak yazdýran program
int main() {
	int arr1[]={8,15,3,7};																			int main() {
	int n=sizeof(arr1)/sizeof(int);																		char karakter=NULL;
	optimalStrategyOfGame(arr1,n);																		FILE *belge1=fopen("..\\falan filan\\harfler1.txt","r"),*belge2=fopen("..\\falan filan\\harfler2.txt","w");
																										while(1) {
	int arr2[]={2,2,2,2};																					karakter=fgetc(belge1);
	n=sizeof(arr2)/sizeof(int);																				if(karakter==EOF)
	optimalStrategyOfGame(arr2,n);																				break;
																											else if('a'<=karakter && karakter<='z')
	int arr3[]={20,30,2,2,2,10};																				karakter= karakter=='z' ? 'a' : karakter+1;
	n=sizeof(arr3)/sizeof(int);																				else if('0'<=karakter && karakter<='9')
	optimalStrategyOfGame(arr3,n);																				karakter= karakter=='9' ? '0' : karakter+1;
																											fputc(karakter,belge2);
	srand(time(NULL));																					}
	n=2*(rand()%15+1);	//n'in alabileceði deðerler: 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30			fclose(belge1);
	int *arr4=malloc(n*sizeof(int)),i;																	fclose(belge2);
	for(i=0;i<n;i++)																					exit(0);
		arr4[i]=rand()%1000+1;																		}
	optimalStrategyOfGame(arr4,n);
}

   Klavyeden girilen sayý kadar sýrayla saða, aþaðý ve sola giden bir yýldýz animasyonu oynatan program

#define TEKRAR 5																					Lindermayer'in alglerin üremesini modelleyen L-sistemini ilk 10 nesil için algleri 'A' ve 'B' harfleriyle göstererek yazdýran program
#define SURE 70000
int main() {																						int main() {
	int n,i,j,k;																						char mevcut[1000]="A",sonraki[1000]="";
	printf("Bir sayi giriniz: ");																		unsigned int i,nesil_no=0;
	scanf("%d",&n);																						printf("Nesil %d: %s\n",nesil_no++,mevcut);
	printf("\n\n");																						while(nesil_no<=10) {
	for(k=0;k<TEKRAR;k++) {																					for(i=0;i<strlen(mevcut);i++) {
		for(i=0;i<n;i++) {																						char k=mevcut[i];
			printf("*");																						if(k=='A')
			usleep(SURE);																							strcat(sonraki,"AB");
			printf("\b ");																						else if(k=='B')
		}																											strcat(sonraki,"A");
		printf("\n");																						}
		for(i=0;i<n;i++) {																					strcpy(mevcut,sonraki);
			for(j=0;j<n;j++)																				printf("Nesil %d: %s\n",nesil_no++,mevcut);
				printf(" ");																				strcpy(sonraki,"");
			printf("*");																				}
			usleep(SURE);																				return 0;
			printf("\b \n");																		}
		}
		for(i=0;i<n;i++)																			Uluslararasý Telsiz Telefon Yazým Alfabesi, nam-ý diðer NATO fonetik alfabesine göre klavyeden girilen katarý kodlayan Ýngilizce program
			printf(" ");
		for(i=0;i<n;i++) {																			int main() {
			printf("*");																				const char NATOphoneticAlphabet[26][9] = {"Alpha","Bravo","Charlie","Delta","Echo","Foxtrot","Golf","Hotel","India","Juliett","Kilo","Lima","Mike",
			usleep(SURE);																													"November","Oscar","Papa","Quebec","Romeo","Sierra","Tango","Uniform","Victor","Whiskey","X-ray","Yankee","Zulu"};
			printf("\b \b\b");																			char string[1000];
		}																								unsigned int i;
	}																									printf("*****NATO Phonetic Alphabet*****\nPlease enter a word/sentence: ");
	return 0;																							gets(string);
}																										for(i=0;i<strlen(string);i++)
																											printf( ('a'<=string[i] && string[i]<='z') || ('A'<=string[i] && string[i]<='Z') ? "%c as in %s\n" : "\n", string[i], NATOphoneticAlphabet[tolower(string[i])-'a']);
   Göstericilere rastgele diziler döndüren Ýngilizce program										}

int* getRandomArray(const unsigned int n) {															Doðum günü paradoksunu 1'den 365'e kadar olan kiþi sayýlarý için çözen program
	static int x[1000];
	static unsigned int i;																			int main() {
	printf("Random array: ");																			long double p;
	for(i=0;i<n;i++) {																					unsigned short i,n;
		x[i]=rand()%100+1;																				for(n=1;n<=365;n++) {
		printf("%d ",x[i]);																					p=1.0;
	}																										for(i=2;i<=n;i++)
	printf("\n");																								p *= (long double)(366-i)/365.0;	//n kiþiden herkesin doðum gününün farklý olma olasýlýðý: P(n) = [365*364*363*...*(365-n+1)]/365^n
	return x;																								p=(1.0-p)*100.0;						//mantýken, n kiþiden en az iki kiþinin doðum gününün ayný olma olasýlýðý: 1-P(n)
}																											__mingw_printf("%hu kisiden dogum gunu ayni olan iki kisi cikma olasiligi: %%%.50Lf\n",n,p);
int main() {																							}
	srand((unsigned)time(NULL));																		return 0;
	int *p,*r,*s,i;																					}

	p=getRandomArray(10);																			Klavyeden girilen büyük harfli 3 kelimeden ilk 2'sinin tüm harfleri kullanýlarak 3. kelimenin elde edilip edilemeyeceðini yazdýran program
	printf("Size of p: %u bytes\n",(unsigned int)sizeof(p));
	for(i=0;i<10;i++)																				int main() {
		printf("*(p+%d)=%d\n",i,*(p+i));																int letter_count[26]={0},i,j;
																										char word[120];
	printf("\n\n");																						for(i=0;i<2;i++) {
	r=getRandomArray(20);																					scanf("%s",word);
	printf("Size of r: %u bytes\n",(unsigned int)sizeof(r));												for(j=0;word[j];j++)		//"word[j]" ile "word[j]!='\0'" condition'larý eþit
	for(i=0;i<20;i++)																							letter_count[word[j]-'A']++;
		printf("*(r+%d)=%d\n",i,*(r+i));																}
																										scanf("%s",word);
	printf("\n\n");																						for(i=0;word[i];i++)
	s=getRandomArray(50);																					letter_count[word[i]-'A']--;
	printf("Size of s: %u bytes\n",(unsigned int)sizeof(s));											for(i=0;i<26;i++)
	for(i=0;i<50;i++)																						if(letter_count[i]) {		//"letter_count[i]" ile "letter_count[i]!=0" condition'larý eþit
		printf("*(s+%d)=%d\n",i,*(s+i));																		printf("3. kelime ilk 2 kelimeden elde edilemez");
}																												return 0;
																											}
																										printf("3. kelime ilk 2 kelimeden elde edilebilir");
																										return 0;
																									}

   Zaman aralýklarý çakýþan dersler ayný holde iþlenemeyeceðine göre, baþlangýç ve bitiþ saatleri verilen dersleri iþlemek için minimum kaç hol gerektiðini yazdýran program

#define MAX 24
int minHolSayisi(const int ders_saatleri[][2], const int ders_sayisi) {
	int i;
	int toplagel[MAX]={0};
	for(i=0;i<ders_sayisi;i++) {
		toplagel[ders_saatleri[i][0]]++;
		toplagel[ders_saatleri[i][1]+1]--;
	}
    int sonuc=toplagel[0];
	for(i=1;i<MAX;i++) {
		toplagel[i]+=toplagel[i-1];
		sonuc=max(sonuc,toplagel[i]);
	}
	return sonuc;
}
int main() {
	const int fizik_ders_saatleri[][2]={ {0,5},
										 {1,2},
										 {1,10} };
	const int fizik_ders_sayisi=sizeof(fizik_ders_saatleri)/sizeof(fizik_ders_saatleri[0]);
	printf("Fizik dersi icin gerekli minimum hol sayisi: %d\n",minHolSayisi(fizik_ders_saatleri,fizik_ders_sayisi));
	const int kimya_ders_saatleri[][2]={ {0,9},
										 {1,7},
										 {3,5},
										 {13,17},
										 {4,10} };
	const int kimya_ders_sayisi=sizeof(kimya_ders_saatleri)/sizeof(kimya_ders_saatleri[0]);
	printf("Kimya dersi icin gerekli minimum hol sayisi: %d\n",minHolSayisi(kimya_ders_saatleri,kimya_ders_sayisi));
	return 0;
}

   Bir iskambil destesini matris olarak hafýzaya atýp bu desteyi switch case yapýsýndan da yararlanarak karýþtýrýp karýþtýrýp ekrana yazdýran program

#define sinek 0
#define maca 1
#define kupa 2
#define karo 3

#define as 0
#define vale 10
#define kiz 11
#define kral 12
void swap(int *a,int *b) {
	int gecici=*a;
	*a=*b;
	*b=gecici;
}
void desteyiYazdir(int deste[][2]) {
	int i;
	for(i=0;i<52;i++) {
		switch(deste[i][0]) {
			case sinek: printf("Sinek "); break;
			case maca: printf("Maca "); break;
			case kupa: printf("Kupa "); break;
			case karo: printf("Karo ");
		}
		switch(deste[i][1]) {
			case as: printf("As"); break;
			case vale: printf("Vale"); break;
			case kiz: printf("Kiz"); break;
			case kral: printf("Kral"); break;
			default: printf("%d",deste[i][1]+1);
		}
		printf("\n");
	}
	printf("\n\n");
}
void desteyiKaristir(int deste[][2], int n) {
	int i;
	for(i=0;i<n;i++) {
		int a=rand()%52;
		int b=rand()%52;
		swap(&deste[a][0],&deste[b][0]);
		swap(&deste[a][1],&deste[b][1]);
	}
}
int main() {
	srand(time(0));
	int deste[52][2],i,j;
	for(i=0,j=0;i<52;i++,j++) {
		deste[i][0]=i/13;	//i: 0-12 => sinek (0) , 13-25 => maça (1) , 26-38 => kupa (2) , 39-51 => karo (3)
		deste[i][1]=j%13;	//j: 0-12, 13-25, 26-38, 39-51 => as(0),2(1),3(2),4(3),5(4),6(5),7(6),8(7),9(8),10(9),vale(10),kýz(11),kral(12)
	}
	printf("Orijinal deste:\n");
	desteyiYazdir(deste);
	desteyiKaristir(deste,20);
	printf("%d defa karistirilmis deste:\n",20);
	desteyiYazdir(deste);
	desteyiKaristir(deste,200);
	printf("%d defa karistirilmis deste:\n",200);
	desteyiYazdir(deste);
	desteyiKaristir(deste,2000);
	printf("%d defa karistirilmis deste:\n",2000);
	desteyiYazdir(deste);
	return 0;
}

   Katsayýlarý 1 ila 40 arasýnda, derecesi 5 olan rastgele 3 polinom üretip klavyeden girilen deðerin bu polinomlardaki çýktýsýný yazdýran program

char* rastgelePolinomUret(int max_katsayi, int max_derece) {
	static int x=1;
	char *polinom=(char*) malloc(1000*sizeof(char));
	strcpy(polinom,"");
	int i,derece=max_derece;
	for(i=1;i<=max_derece+1;i++,derece--) {
		int katsayi=rand()%max_katsayi+1;
		if(derece!=0)
			sprintf(polinom+strlen(polinom),"%d*x^%d+",katsayi,derece);
		else if(derece==0)
			sprintf(polinom+strlen(polinom),"%d",katsayi);
	}
	printf("%d. Polinom: %s\n",x++,polinom);
	return polinom;
}
long long polinomdaYerineKoy(char* polinom, int x) {
	long long sonuc=0,terim=1;
	int i,derece=100;
	while(1) {
		int katsayi=atoi(polinom);
		terim*=katsayi;
		if(derece>1) {
			while(*(polinom-1)!='^')
				polinom++;
			derece=atoi(polinom);
		}
		else {
			sonuc+=terim;
			break;
		}
		for(i=1;i<=derece;i++)
			terim*=x;
		sonuc+=terim;
		while(*(polinom-1)!='+')
			polinom++;
		terim=1;
	}
	return sonuc;
}
int main() {
	srand(time(NULL));
	char *polinom[3];
	int i,x;
	for(i=0;i<3;i++) {
		polinom[i]=(char*) malloc(1000*sizeof(char));
		polinom[i]=rastgelePolinomUret(40,5);
	}
	printf("Bir sayi giriniz: ");
	scanf("%d",&x);
	for(i=0;i<3;i++) {
		long long sonuc=polinomdaYerineKoy(polinom[i],x);
		printf("Polinom %d (%d) = %lld\n",i+1,x,sonuc);
	}
	exit(0);
}

   Klavyeden dans yetenekleri girilen M tane erkek ve N tane kýz kendi aralarýnda çiftler kurup dans pistine çýkacaktýr. Her dans pistine çýkan çiftin
   dans yetenekleri arasýndaki farkýn 2'yi aþmamasý gerektiðine göre, piste uygun eþleþmeler ile en fazla kaç çiftin çýkabileceðini yazdýran program */

#define SKILL_DIFF 2
#define BOY 'b'
#define GIRL 'g'
int* bubble_sort(const int arr[], const int size) {		//dizinin küçükten büyüðe sýralý halini döndürür, ama call by reference yapmaz
	int *arr2=(int*) malloc(size*sizeof(int)),i,j;
	for(i=0;i<size;i++)
		arr2[i]=arr[i];				//arr dizisi arr2'ye kopyalandý, ve bir daha arr dizisine dokunulmadý
	for(i=0;i<size-1;i++)
		for(j=0;j<size-i-1;j++)
			if(arr2[j]>arr2[j+1]) {
				int temp=arr2[j];	//sort'lama fonksiyonlarýnýn olmazsa olmazý, klasik "a=b; b=c; c=a;" biçimli swap
				arr2[j]=arr2[j+1];	//it's a simple spell, but quite unbreakable
				arr2[j+1]=temp;
			}
	return arr2;
}
int where_am_I(const int x, const int arr[], const int size, const char gender) {
	int i,j;						//bir sayýnýn boys/girls dizisinde bulunduðu index'in 1 fazlasýný (sýrasýný) döndürüyor
	static int I_returned_that_boy[300], b=0, I_returned_that_girl[300], g=0;
	switch(gender) {
		case BOY:
			for(i=0;i<size;i++)
				if(arr[i]==x) {
					bool flag=false;
					for(j=0;j<b;j++)
						if(I_returned_that_boy[j]==i+1) {
							flag=true;
							break;
						}
					if(flag)
						continue;
					return I_returned_that_boy[b++]=i+1;
				}					//tabii eðer sayý boys dizisinde birden fazla geçiyorsa, ayný sayýyý tekrar döndürmek istemem
			break;					//o yüzden onu bir daha deðil, bir sonraki index'i döndürdüðümden emin olmalýyým
		case GIRL:
			for(i=0;i<size;i++)
				if(arr[i]==x) {
					bool flag=false;
					for(j=0;j<g;j++)
						if(I_returned_that_girl[j]==i+1) {
							flag=true;
							break;
						}
					if(flag)
						continue;
					return I_returned_that_girl[g++]=i+1;
				}					//tabii eðer sayý girls dizisinde birden fazla geçiyorsa, ayný sayýyý tekrar döndürmek istemem
	}								//o yüzden onu bir daha deðil, bir sonraki index'i döndürdüðümden emin olmalýyým
	return 0;
}
int main() {
	int i,prev_j,j,M,N,counter=0;
	printf("Erkek sayisini giriniz: ");
	scanf("%d",&M);
	int *boys=(int*) malloc(M*sizeof(int)), *boys2=(int*) malloc(M*sizeof(int));
	printf("Erkeklerin dans skill'lerini giriniz: ");
	for(i=0;i<M;i++)
		scanf("%d",&boys[i]);
	printf("Kiz sayisini giriniz: ");
	scanf("%d",&N);
	int *girls=(int*) malloc(N*sizeof(int)), *girls2=(int*) malloc(N*sizeof(int));
	printf("Kizlarin dans skill'lerini giriniz: ");
	for(i=0;i<N;i++)
		scanf("%d",&girls[i]);
	boys2 = bubble_sort(boys,M);
	girls2 = bubble_sort(girls,N);
	for(prev_j=i=0;i<M;i++)
		for(j=prev_j;j<N;j++)
//			if(boys2[i]==girls2[j]-2 || boys2[i]==girls2[j]-1 || boys2[i]==girls2[j] || boys2[i]==girls2[j]+1 || boys2[i]==girls2[j]+2) {
			if(abs(boys2[i]-girls2[j])<=SKILL_DIFF) {
				printf("\n%d. ciftimiz :\t %d. erkek = %d\t   &&\t %d. kiz = %d"
				, ++counter, where_am_I(boys2[i],boys,M,BOY), boys2[i], where_am_I(girls2[j],girls,N,GIRL), girls2[j]);
				prev_j=j+1;			//bir dahakine kýzlarý býraktýðý yerden taramaya baþlar
				break;
			}
	printf("\n\nDansa cikabilecek maksimum cift sayisi: %d",counter);
	return 0;
}
