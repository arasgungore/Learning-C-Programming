#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Parseller arazinin dýþýna çýkabildiðine göre; eni m, boyu n metre olan bir araziyi kenarý a metre			Klavyeden girilen maksimum 100 harf uzunluðundaki kelimeleri 10 harften uzunsa ilk harfi ve son harfi arasýndaki
   olan kare parsellerle tamamen kaplamak için gereken minimum parsel sayýsýný yazdýran program					harf sayýsýný harflerin yerine yazdýran, deðilse kelimeyi olduðu gibi yazdýran program

int main() {																									int main() {
	unsigned int m,n,a;																								char **s;
	unsigned long long parselsayisi;																				int n,i,j;
	printf("Arazinin eni ve boyunu giriniz: ");																		printf("Kelime sayisini giriniz: ");
	scanf("%d%d",&m,&n);																							scanf("%d",&n);
	printf("Parselin kenar uzunlugunu giriniz: ");																	s=(char**) malloc(sizeof(char*)*n);
	scanf("%d",&a);																									for(i=0;i<n;i++) {
	parselsayisi=(unsigned long long)ceil((double)m/a)*ceil((double)n/a);												s[i]=(char*) malloc(sizeof(char)*100);
	printf("Gereken minimum parsel sayisi: %llu",parselsayisi);															scanf("%s",s[i]);
}																														s[i]=(char*) realloc(s[i],strlen(s[i])+1);
																													}
																													printf("\n");
																													for(i=0;i<n;i++)
																														if(strlen(s[i])>10)
																															printf("%c%d%c\n",s[i][0],strlen(s[i])-2,s[i][strlen(s[i])-1]);
																														else
																															printf("%s\n",s[i]);
																												}
   n kiþinin bulunduðu bir oyunda klavyeden büyükten küçüðe göre girilmesi gerektiði bilinen skor 
   sýralamasýnda soldan k. sýradaki kiþiden fazla veya ona eþit puan alanlarýn oyunu kazandýðý bilinmektedir.	
   0 alanlarýn hiçbir türü oyunu kazanmýyor sayýldýðý ve oyunda negatif puan almak imkansýz olduðuna göre		Klavyeden girilen maksimum 100 karakter uzunluðundaki Ýngilizce bir kelimenin sesli harflerini (a,A,e,E,i,I,o,O,u,U,y,Y) silen
   oyunu kaç kiþinin kazandýðýný yazdýran program																ve geri kalan sessiz harflerden her birinin baþýna nokta iþareti koyup kelimeyi komple küçük harflerle döndüren program

int main() {																									int main() {
	int n,k,i;																										char kelime[100];
	printf("Katilimci sayisini ve k degerini giriniz: ");															int i;
	scanf("%d%d",&n,&k);																							printf("Kelimeyi yaziniz: ");
	int *dizi=(int*) malloc(sizeof(int)*n);																			scanf("%s",kelime);
	printf("Skor siralamasi: ");																					for(i=0;i<strlen(kelime);i++)
	for(i=0;i<n;i++)																									if(!strchr("AEIOUYaeiouy",kelime[i]))	//sesli harfler arasýnda kelime[i] YOKSA if'in içindeki yazdýr komutu çalýþýr
		scanf("%d",&dizi[i]);																								printf(".%c",tolower(kelime[i]));
	for(i=0;i<n;i++)																							}
		if(n>1 && i!=n-1)
			if(dizi[i+1]>dizi[i] || dizi[i]<0)
				exit(1);	//eðer skor tablosuna negatif sayý giriþi yapýlýrsa ya da aykýrý bir sýralama girilirse program sonlandýrýlacak
	for(i=0;dizi[i]>=dizi[k-1] && dizi[i] && i<n;i++);		//dikkat ederseniz bu satýrdaki for için scope açmadým, ama for'un içinde
	printf("Oyunu kazanan kisi sayisi: %d",i);				//kod bloðu oluþturmasam bile içerdeki 3 koþul birden doðru olduðu sürece
}															//i birer birer artacak ve sayaç rolü üstlenecek
	//bu arada "dizi[i]" koþulu dizi[i]!=0 ise "true" [a[i]==-n,...,-3,-2,-1,1,2,3,...,n], dizi[i]==0 ise "false" oluyor

   Eni m, boyu n cm olan bir boþ tahtaya eni 1, boyu 2 cm olan dominolardan üst üste gelmeyecek þekilde			Klavyeden toplam n defa olmak üzere her yeni satýrda "X++", "++X", "X--", "--X" operasyonlarýndan biri girildiðinde x=0
   maksimum kaç tane yerleþtirilebileceðini yazdýran program													deðerine bu operasyonlar gerçekleþtirildiðine göre tüm operasyonlar bittiðinde x deðerinin son deðerini döndüren program

int main() {											//sorunun alternatif çözümü:							int main() {
	int m,n,i,j,sayac=0;								//int main() {												int x=0,n;
	printf("Tahtanin eni ve boyunu giriniz: ");			//    int m,n;												char girdi[4];	//3 karakter + 1 NULL
	scanf("%d%d",&m,&n);								//    printf("Eni ve boyu girin: ");						printf("Operasyon sayisi: ");
	int **tahta=(int**) malloc(sizeof(int*)*m);			//    scanf("%d%d",&m,&n);									scanf("%d\n",&n);
	for(i=0;i<m;i++) {									//    printf("Domino sayisi: %d",m*n/2);					while(n--) {	//n>0 ise true, n=0 olduðu an false
		tahta[i]=(int*) malloc(sizeof(int)*n);			//}																gets(girdi);	
		for(j=0;j<n;j++)																								x+=44-girdi[1];		//girdi[1], girdinin 2. karakteri olduðundan ya '+' ya da '-'dir
			tahta[i][j]=0;																							}		//ASCII kodlarýna göre '+'=43 ve '-'=45 olduðundan eðer girdi[1]='+' ise statement x+=1, '-' ise x-=1 (x+=-1) olur
	}																												printf("Sonuc: %d",x);
	for(i=0;i<m-1;i+=2)																							}
		for(j=0;j<n;j++) {
			tahta[i][j]=1;																						Toplam n tane olmak üzere kýrmýzý, mavi veya yeþil renklerdeki taþlar masada bir sýra halinde dizilmiþ olarak bulunmaktadýr.
			tahta[i+1][j]=1;																					Klavyeden n deðeri ve taþlarýn sýralanýþý taþlarýn renklerine göre 'K','M' ve 'Y' ile gösterildiði bir katar biçiminde girildiðine	
			sayac++;																							göre komþu taþlarýn birbirinden farklý renklerde olmasý için masadan minimum kaç taþ alýnmasý gerektiðini yazdýran program
		}
	i=m-1;																										int main() {
	for(j=0;j<n-1;j+=2)																								int n,i,sayac=0;
		if(!tahta[i][j] && !tahta[i][j+1]) {																		printf("Tas sayisini giriniz: ");
			tahta[i][j]=1;																							scanf("%d",&n);
			tahta[i][j+1]=1;																						printf("Tas sirasini giriniz (M: Mavi, Y: Yesil, K: Kirmizi): ");
			sayac++;																								char *string=(char*) malloc(n);		//sizeof(char)=1 olduðu için çarpým durumunda yazmýyorum, yazmayacaðým
		}																											scanf("%s",string);
	printf("Yerlestirilebilecek maksimum domino sayisi: %d",sayac);		//!! sayac=(int)(m*n/2) !!					for(i=0;i<n-1;i++)		//n=strlen(string) bu arada
}																														if(string[i]==string[i+1])
																															sayac++;
   Maksimum 100 tane rakamla yapýlabilen ve toplananlarý klavyeden girilen seri bir toplama iþleminde				printf("\nAlinmasi gereken tas sayisi: %d",sayac);
   toplananlarý küçükten büyüðe doðru sýralayýp kullanýcýya ayný seri toplama iþlemini döndüren program				}

int main() {																									Sadece küçük harflerden oluþan bir Ýngilizce bir kelimenin birbirinden farklý kaç tane harften oluþtuðunu yazdýran program
	char string[200];
	int i,j;																									int main() {
	printf("Toplama islemini giriniz: ");																			char *alfabe="abcdefghijklmnopqrstuvwxyz",kelime[200];
	gets(string);																									int i,j,sayac=0;
	for(i=0;i<strlen(string);i++)																					printf("Kelimeyi yaziniz: ");
		for(j=0;j<strlen(string);j++)																				gets(kelime);
			if(!strchr("+",string[i]) && !strchr("+",string[j]) && string[i]<=string[j]) {							for(i=0;i<26;i++)
				char gecici=string[i];																					for(j=0;j<strlen(kelime);j++)
				string[i]=string[j];																						if(kelime[j]==alfabe[i]) {
				string[j]=gecici;																								sayac++;
			}																													break;
	printf("\nDuzenlenmis toplama: ");																						}
	for(i=0;i<strlen(string);i++)																					printf("Farklý harf sayýsý: %d",sayac); 
		printf("%c",string[i]);																					}
}

   Klavyeden girilen ve 24 tane 0 ile bir tane 1'den oluþan 5*5'lik bir matriste sadece yan yana				Klavyeden x, y, z bileþenleri girilen n tane vektörün bileþkesi 0 ise "EVET", deðilse "HAYIR" yazdýran program
   veya üst üste konumlanmýþ iki elemanýn yerlerini deðiþtirerek minimum kaç hamlede 1 elemanýný
   matrisin merkezine yerleþtirebileceðimizi yazdýran program													struct vektor {
																													int x;
void swap(int a,int b) {																							int y;
    int tut=a;																										int z;
    a=b;																										};
    b=tut;																										typedef struct vektor vektor;
}																												int main() {
int main() {																										int i,n,toplam[3]={0,0,0};
    int matris[5][5],i,j,hamle=0;																					printf("Vektor sayisini giriniz: ");
    for(i=0;i<5;i++)																								scanf("%d",&n);
        for(j=0;j<5;j++)																							vektor *v=malloc(sizeof(vektor)*n);
            scanf("%d",&matris[i][j]);																				for(i=0;i<n;i++) {
    for(i=0;i<5;i++)																									printf("%d. vektoru giriniz: ",i+1);
        for(j=0;j<5;j++)																								scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].z);
            if(matris[i][j]) {																							toplam[0]+=v[i].x;
                while(!matris[2][2]) {																					toplam[1]+=v[i].y;
                    if(i<2)																								toplam[2]+=v[i].z;
                        swap(matris[i][j],matris[++i][j]);															}
                    else if(i>2)																					if(toplam[0]==0 && toplam[1]==0 && toplam[2]==0)
                        swap(matris[i][j],matris[--i][j]);																printf("EVET");
                    else																							else
                        if(j<2)																							printf("HAYIR");
                            swap(matris[i][j],matris[i][++j]);													}
                        else if(j>2)
                            swap(matris[i][j],matris[i][--j]);													Klavyeden girilen bir katarýn birtakým harfleri çýkarýldýðýnda "hello" kelimesi elde edilebiliyorsa "EVET", hiçbir
                        else																					türlü elde edilemiyorsa "HAYIR" yazdýran program
                            break;
                    hamle++;																					int main() {
                }																									int i=0;
                printf("\nGereken minimum hamle sayisi: %d",hamle);													char harf,hello[5]="hello";
                return 0;	//exit(0) ile ayný; main fonksiyonu burada biter, program sonlanýr						while(scanf("%c",&harf) && harf!='\n')	//newline olana kadar (baþ harften son harfe kadar) girilen katarýn her bir harfi
            }																											if(harf=hello[i])			//tek tek incelenir ve gelen harfler "hello"nun sýrayla 1.,2.,3.,4.,5. harflerine
}																															i++;					//eþitse araya giren harfler çýkarýldýðýnda yine "hello" elde edilebilir demektir
																													printf(i==5 ? "EVET" : "HAYIR");	//" if(i==5)  printf("EVET");  else  printf("HAYIR"); " ile ayný þey, tabii daha kýsa :)
   Sadece 4 ve 7 rakamlarýndan oluþan sayýlar ve bu sayýlara tam bölünebilen sayýlar þanslý sayý olarak
   tanýmlandýðýna göre, klavyeden girilen 1 ila 1000 arasýndaki bir sayýnýn þanslý olup olmadýðýný yazdýran program

int main() {
    int i,sayi,sanslisayi[9]={4,7,47,74,447,474,477,747,774};
    printf("Sayi giriniz: ");	//44, 77, 444, 744 ve 777 þanslý sayýlar olsa da zaten 4 ya da 7'nin katý olduðu
    scanf("%d",&sayi);			//için diziye ekleyip bilgisayarý fazladan yormaya gerek yok
    for(i=0;i<9;i++)																							Ýki N-S kutuplu çubuk mýknatýs birbirlerini çekip birleþtiklerinde tek bir mýknatýs sayýlmaktadýr. Klavyeden mýknatýs sayýsý
        if(sayi%sanslisayi[i]==0) {																				ve ayný doðrultuda olduðu varsayýlan bu çubuk mýknatýslarýn birbirlerine göre nasýl kutuplandýðý NS veya SN olarak sýrayla
            printf("%d bir sansli sayidir",sayi);																girileceðine göre, bu mýknatýslar serbest býrakýldýktan sonra toplam kaç mýknatýs bulunacaðýný yazdýran program
            break;
        }																										int main() {
    if(i==9)																										int n,i;
        printf("%d bir sansli sayi degildir",sayi);																	printf("Miknatis sayisini ve bu miknatislarin kutuplanislarini giriniz: ");
}																													scanf("%d",&n);
																													int N=n;
   1'den n'e kadar numaralandýrýlmýþ n tane kiþi kendi aralarýnda baþkalarýna ya da kendilerine hediye				char **magnetler=(char**) malloc(sizeof(char*)*N);
   verecektir. n deðeri ve 1,2,3,...,n no'lu kiþilerin sýrayla kaç no'lu kiþilere hediye vereceði klavyeden			for(i=0;i<N;i++) {
   girileceðine göre; 1,2,3,...,n no'lu kiþilerin kaç no'lu kiþilerden hediye aldýðýný sýrayla yazdýran program			magnetler[i]=(char*) malloc(sizeof(char)*2);
																														scanf("%s",magnetler[i]);
int main() {																										}
	int n,i,j,gecici;								//sorunun 2. dizi oluþturmadan yapýlan alternatif çözümü:		for(i=0;i<N-1;i++)
	printf("Kisi sayisini giriniz: ");								//int main() {										if(strcmp(magnetler[i],magnetler[i+1])==0)
	scanf("%d",&n);													//    int dizi[500],n,i,t;								n--;
	int *dizi=(int*) malloc(sizeof(int)*n);							//    printf("Kisi sayisi: ");					printf("OLusan miknatis sayisi: %d",n);
	int *dizi2=(int*) malloc(sizeof(int)*n);						//    scanf("%d",&n);						}
	printf("Kisilerin kimlere hediye verecegini sirayla yaziniz: ");//    printf("Hediye verenler sirasi: ");
	for(i=0;i<n;i++) {												//    for(i=1;i<=n;i++) {
		scanf("%d",&dizi[i]);										//        scanf("%d",&t);
		for(j=1;j<=n;j++)											//        dizi[t]=i;
			if(dizi[i]==j)											//    }		//dizi[0] NULL kalýyor
				dizi2[j-1]=i+1;										//    printf("Hediye alanlar sirasi: ");
	}																//    for(i=1;i<=n;i++)
	printf("Kisilerin kimlerden hediye aldiginin listesi: ");		//        printf("%d ",dizi[i]);
	for(i=0;i<n;i++)												//}
		printf("%d ",dizi2[i]);
}

   Bir n tam sayýsý için 1'den n'e kadar olan tam sayýlar arasýndan ilk olarak tek sayýlar küçükten büyüðe
   sýralandýktan sonra ardýndan çift sayýlar küçükten büyüðe sýralanýyor. Klavyeden n ve k deðerleri girilen ve
   n deðeri için oluþturulan bu dizide k. sýrada hangi sayýnýn olduðunu array kullanmadan yazdýran program

int main() {
    unsigned long long n,k;		//int => 4 byte=32 bit, long => 8 byte=64 bit, long long ==> 16 byte=128 bit
    scanf("%lld%lld",&n,&k);	//int bölmesi yaparken "ceil" yapmak, yani sayý ondalýksa üst sayýya yuvarlamak için ceil(n/2) yerine (n+1)/2 kullanýlýr
    printf("%lld",k<=(n+1)/2 ? 2*k-1 : 2*(k-(n+1)/2));	//" if(k<=(n+1)/2)  printf("%lld",2*k-1);  else  printf("%lld",2*(k-(n+1)/2)); " ile ayný þey
}	//k deðeri orta deðerden küçük eþitse 2*k-1 deðerini yazdýr (1,3,5,7,...,(n+1)/2), deðilse orta deðerle farkýnýn 2 katýný (2,4,6,8,...,n) yazdýr

   1,2,3,4 kiþilik öðrenci gruplarý Kapadokya'ya gitmek için belli sayýda 4 kiþilik taksi çaðýracaklardýr.
   Ayný grubun elemanlarý ayný taksiye bineceðine ve bir taksiye birden fazla grup binebileceðine göre grup
   sayýsý ve bu gruplarýn kaç kiþilik olduðu sýrayla klavyeden girilen ve bütün öðrencilerin Kapadokya'ya
   gidebilmesi için en az kaç taksi çaðýrýlmasý gerektiðini yazdýran program

int main() {
	int n,i,x,taxi[5]={0,0,0,0,0};	//taxi[0] elemaný kullanýlmayacak
	printf("Grup sayisi: ");
	scanf("%d",&n);
	printf("Gruplarin kac kisi oldugu: ");
	for(i=0;i<n;i++) {
		scanf("%d",&x);
		taxi[x]++;		//1 kiþilik grup sayýsýný taxi[1], 2 kiþilik grup sayýsýný taxi[2], 3 kiþilik grup sayýsýný taxi[3], 4 kiþilik grup sayýsýný taxi[4] tutuyor
	}					//4 ve 3 kiþilik gruplar için çaðýrýlan taksi sayýsý toplam grup sayýsý kadar zira 4 kiþilik grubun bulunduðu taksilere kimse binemezken 3 kiþilik gruplarýn bulunduðu taksilere sadece 1 kiþi binebilir
	printf("Gerekli taksi sayisi: %d",taxi[4]+taxi[3]+(2*taxi[2]+(taxi[1]>taxi[3] ? taxi[1]-taxi[3] : 0)+3)/4);	//1 kiþilik grup sayýsý 3 kiþilik grup sayýsýndan fazla ise 2'sinin farkýný, deðilse 0 döndür
}	//böylelikle 3 kiþilik gruplarýn bulunduðu taksilere 1 kiþilik gruplar biner ve fazladan taksi çaðýrýlmaz, geri kalan 1 kiþilik gruplarýn bindiði taksi sayýsý (taxi[1]-taxi[3])/4 olurken 2 kiþilik gruplarýn
	//bindiði taksi sayýsý taxi[2]/2 olur     toplamada "+3" ise ceil fonksiyonu misali int bölmesinin sonucu ondalýk çýkarsa sonucu bir üst sayýya yuvarlamak için var

   Klavyeden girilen kelimeleri kelimeyi oluþturan harfler o kelime içerisinde alfabetik sýralamada dizilmiþ olacak þekilde sýrayla döndüren program

int main() {																									Klavyeden girilen bir katarý "blah" ve "BLAH" adlý katarlardan arýndýrarak döndüren program
	char kelime[200][1000],gecici,a;	//max 200 kelime, kelime baþý max 1000 harf
	int i,j,k=-1;																								int main() {
	printf("Kelimeleri giriniz: ");																					char a[1000]; int i;
	while(a!='\n') {																								printf("Katari giriniz: ");
		scanf("%s%c",kelime[++k],&a);		//alternatif olarak 208-214 no'lu satýrlar:								gets(a);
		for(i=0;i<strlen(kelime[k]);i++)			//for(i=0;i<strlen(kelime[k])-1;i++)							for(i=0;a[i]!=NULL;i++)
			for(j=0;j<strlen(kelime[k]);j++)		//    for(j=0;j<strlen(kelime[k])-i-1;j++)							if((a[i]=='b' && a[i+1]=='l' && a[i+2]=='a' && a[i+3]=='h') || (a[i]=='B' && a[i+1]=='L' && a[i+2]=='A' && a[i+3]=='H')) {
				if(kelime[k][i]<kelime[k][j]) {		//        if(kelime[k][j]>kelime[k][j+1]) {								a[i]=' ';
					gecici=kelime[k][i];			//            gecici=kelime[k][j];										a[i+1]=' ';
					kelime[k][i]=kelime[k][j];		//            kelime[k][j]=kelime[k][j+1];								a[i+2]=' ';
					kelime[k][j]=gecici;			//            kelime[k][j+1]=gecici;									a[i+3]=' ';
				}									//        }															}
	}				//olarak bubble sort ile deðiþtirilirse kod yaklaþýk 2 kat daha hýzlý çalýþýr					printf("Arindirilmis katar: %s",a);
	printf("Duzenlenmis kelimeler: ");																			}
	for(i=0;i<=k;i++)
		printf("%s ",kelime[i]);
}

   k tane oyuncu ekip çalýþmasýyla n tane seviyeden oluþan bir bilgisayar oyununu bitirmeye çalýþacaktýr.
   Oyundaki seviye sayýsý, oyuncu sayýsý ve bu oyuncularýn her birinin tek baþlarýna oyunun hangi
   seviyelerini geçebildiði klavyeden girildiðine göre bu oyuncularýn birlikte oyunu bitirip					Klavyeden girilen bir dizinin elemanlarýnýn sadece birinin tek diðerlerinin çift ya da sadece birinin çift diðerlerinin
   bitiremeyeceðini yazdýran program 																			tek olduðu bilindiðine göre teklik-çiftlik açýsýndan farklý olan sayýnýn sýrasýný yazdýran program

int main() {																									int main() {
	int n,o,s,i,j,k;																								int i,j=0,k=0,n;
	printf("Seviye sayisini giriniz: ");																			printf("Dizinin eleman sayisi: ");
	scanf("%d",&n);																									scanf("%d",&n);
	int *level=(int*) malloc(sizeof(int)*n);																		int dizi[n],tek[n],cift[n];		//sakýn böyle yazmayýn, onun yerine dinamik bellek tahsisi yapýn
	for(i=0;i<n;i++)																								printf("Diziyi giriniz: ");
		level[i]=0;																									for(i=0;i<n;i++) {
	printf("Oyuncu sayisini giriniz: ");																				scanf("%d",&dizi[i]);
	scanf("%d",&o);																										if(dizi[i]%2==0)
	for(i=1;i<=o;i++) {																										cift[j++]=i+1;
		printf("%d. oyuncunun gecebildigi seviye sayisini giriniz: ",i);												else
		scanf("%d",&s);																										tek[k++]=i+1;
		printf("%d. oyuncunun gectigi seviyeleri giriniz: ",i);														}
		for(j=1;j<=s;j++) {																							if(j==1)
			scanf("%d",&k);																								printf("Farkli eleman: %d",cift[0]);
			level[k-1]=k;																							if(k==1)
		}																												printf("Farkli eleman: %d",tek[0]);
	}																											}
	for(i=0;i<n;i++)
		if(level[i]==0) {
			printf("\nGame over! Try again?");
			return 0;
		}
	printf("\nCongratulations!!! You are winrar!");
	return 0;
}

   Klavyeden liste yöntemiyle girilen bir harf kümesinde küçük-büyük harf ayrýmý fark etmeksizin
   kaç farklý harf olduðunu yazdýran program

int i,alf[30],sayac; //global deðiþken olduklarý için i, sayac ve alf[30] dizisinin her elemanýnýn
char n;				 //default deðeri 0
int main() {
	printf("Kumeyi giriniz: ");
	while(n!='}') {
		scanf("%c",&n);
		if(n!=' ' && n!=',')
			alf[tolower(n)-'a']++;	//Büyük harfler otomatik olarak küçük harfe dönüþtürülüyor
	}								//ve o küçük harfin kümedeki sayýsýna ekleniyor
	for(i='a';i<='z';i++)
		if(alf[i-'a'])	//eðer alf[i-'a']'nin deðeri en az 1 ise true, 0 ise yani o harf kümede yoksa false
			sayac++;
	printf("Farkli harf sayisi: %d",sayac);
}	//bu arada bu -'a' kalýplarý olmasa da kod sorunsuz çalýþýr da index'i 97-122 arasý yerine klasik 0-25 arasý tutmak için böyle yaptým

   Aþaðýdaki programýn çýktýsý

int main() {
	int m=7,n=4,k=8;
	float a,b;
	a=(float)(m*4)/(n+k);		//a=(7*4)/(4+8)=2.333333
	b=(float)((2*n)/(m-n));		//b=floor((2*4)/(7-4))=floor(2.666667)=2.000000
	m+=n++;				//m=m+n=7+4=11		n=4+1=5
	n+=--k;				//n=n+(k-1)=5+(8-1)=12		k=8-1=7
	printf("%.3f",a+b+m+n-k);		//çýktý 2.333333+2+11+12-7=20.333333'ün son 3 basamaðýna kadar ==> "20.333"
}

   Ýki zarla oynanan bir oyunda; atýþta gelen sayýlarýn toplamý 9 ya da daha büyükse oyuncu kazanýyor, 5 ila 8 arasýnda ise oyuncu tekrar zar atýyor, 4 ya da daha küçükse oyuncu kaybediyor.
   Buna göre, oyuncu kaybedene ya da kazanana kadar oyunu oynayan program

int zar1,zar2;																									Ýki zarla oynanan bir oyunda; atýþta gelen sayýlarýn toplamý 9 ya da daha büyükse oyuncu kazanýyor, 5 ila 8 arasýnda ise oyuncu tekrar zar atýyor, 4 ya da daha küçükse oyuncu kaybediyor.	
int ZarAt() {																									Buna göre, oyuncu kaybedene ya da kazanana kadar oyunu goto yardýmýyla oynayan alternatif program
	zar1=1+rand()%6;
	zar2=1+rand()%6;																							int zar1,zar2;
	return (zar1+zar2);																							int ZarAt() {
}																													zar1=1+rand()%6;
int main() {																										zar2=1+rand()%6;
	srand(time(NULL));																								return (zar1+zar2);
	int x=ZarAt();																								}
	printf("Atis sonucu %d+%d=%d\n",zar1,zar2,x);																int main() {
	do {																											srand(time(NULL));
		if(x>=9) {																									int x;
			printf("Oyunu kazandiniz! Tebrikler!!!");																tekrar:
			break;																									x=ZarAt();
		}																											printf("Atis sonucu %d+%d=%d\n",zar1,zar2,x);
		else if(x>=5) {																								if(x>=9)
			printf("Oyunu tekrarlayiniz\n");																			printf("Oyunu kazandiniz! Tebrikler!!!");
			x=ZarAt();																								else if(x>=5) {
			printf("Atis sonucu %d+%d=%d\n",zar1,zar2,x);																printf("Oyunu tekrarlayiniz\n");
		}																												goto tekrar;
		else {																										}
			printf("Oyunu kaybettiniz :((");																		else
			break;																										printf("Oyunu kaybettiniz :((");
		}																										}		//mülakattan atýlmak istemiyorsan goto ve global deðiþken kullanma
	} while(1);
	return 0;
}

   Klavyeden girilen cümleyi 0'a basýldýðýnda rakamlardan arýndýrarak yazdýran, 1'e basýldýðýnda ise büyük harflerde yazdýran program

int main() {
	char cumle[100];
	int x,i;
	printf("Rakamlari cikarmak icin 0'a, buyuk harfte yazdirmak icin 1'e basiniz\nCumle: ");
	gets(cumle);
	printf("Secim: ");
	scanf("%d",&x);
	switch(x) {
		case 0:
			for(i=0;i<strlen(cumle);i++)
				if(!strchr("0123456789",cumle[i]))
					printf("%c",cumle[i]);
			break;
		case 1: puts(strupr(cumle));
	}
	exit(0);
}

   1'den n'e kadar numaralandýrýlmýþ olan n tane kiþi ardýþýk numaralý kiþiler yan yana gelecek þekilde bir yuvarlak masaya oturmuþtur.
   s numaralý kiþiden baþlayarak artan sýra no'suna göre bu kiþilere m tane þeker daðýtýlacaðýna göre, klavyeden girilen m, n ve s
   deðerlerine göre son þekeri kaç numaralý kiþinin alacaðýný yazdýran program

int main() {
	int m,n,s;
	printf("Kisi sayisini, seker sayisini ve ilk sekeri alacak kisinin no'sunu giriniz: ");
	scanf("%d%d%d",&n,&m,&s);
	int a=s+m-1;
	printf("Son sekeri alacak kisinin no'su: %d", a>n ? (a%n==0 ? n : a%n) : a);
}

   Bir dizinin en sonundaki elemaný baþa, diðer elemanlarý da bir saða kaydýrýlýyorsa o dizi bir rotasyon geçirmiþ olduðuna göre, klavyeden
   girilen dizi r defa rotasyon geçirdikten sonra bu dizide klavyeden girilen index'lerde hangi sayýlarýn bulunduðunu yazdýran program */

int main() {
	int n1,n2,i,r;
	printf("Dizinin eleman sayisini giriniz: ");
	scanf("%d",&n1);
	int *dizi=calloc(n1,sizeof(int));
	printf("Diziyi giriniz: ");
	for(i=0;i<n1;i++)
		scanf("%d",&dizi[i]);
	printf("Rotasyon sayisini giriniz: ");
	scanf("%d",&r);
	printf("Index sayisini giriniz: ");
	scanf("%d",&n2);
	int *indexler=calloc(n2,sizeof(int)),*sonuc=calloc(n2,sizeof(int));
	printf("Index'leri giriniz: ");
	for(i=0;i<n2;i++)
		scanf("%d",&indexler[i]);
	printf("Bu index'lerdeki sayilar:");
	for(i=0;i<n2;i++) {
		sonuc[i]=dizi[(indexler[i]-(r%n1)+n1)%n1];
		printf(" %d",sonuc[i]);
	}
}
