#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/* Parseller arazinin d���na ��kabildi�ine g�re; eni m, boyu n metre olan bir araziyi kenar� a metre			Klavyeden girilen maksimum 100 harf uzunlu�undaki kelimeleri 10 harften uzunsa ilk harfi ve son harfi aras�ndaki
   olan kare parsellerle tamamen kaplamak i�in gereken minimum parsel say�s�n� yazd�ran program					harf say�s�n� harflerin yerine yazd�ran, de�ilse kelimeyi oldu�u gibi yazd�ran program

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
   n ki�inin bulundu�u bir oyunda klavyeden b�y�kten k����e g�re girilmesi gerekti�i bilinen skor 
   s�ralamas�nda soldan k. s�radaki ki�iden fazla veya ona e�it puan alanlar�n oyunu kazand��� bilinmektedir.	
   0 alanlar�n hi�bir t�r� oyunu kazanm�yor say�ld��� ve oyunda negatif puan almak imkans�z oldu�una g�re		Klavyeden girilen maksimum 100 karakter uzunlu�undaki �ngilizce bir kelimenin sesli harflerini (a,A,e,E,i,I,o,O,u,U,y,Y) silen
   oyunu ka� ki�inin kazand���n� yazd�ran program																ve geri kalan sessiz harflerden her birinin ba��na nokta i�areti koyup kelimeyi komple k���k harflerle d�nd�ren program

int main() {																									int main() {
	int n,k,i;																										char kelime[100];
	printf("Katilimci sayisini ve k degerini giriniz: ");															int i;
	scanf("%d%d",&n,&k);																							printf("Kelimeyi yaziniz: ");
	int *dizi=(int*) malloc(sizeof(int)*n);																			scanf("%s",kelime);
	printf("Skor siralamasi: ");																					for(i=0;i<strlen(kelime);i++)
	for(i=0;i<n;i++)																									if(!strchr("AEIOUYaeiouy",kelime[i]))	//sesli harfler aras�nda kelime[i] YOKSA if'in i�indeki yazd�r komutu �al���r
		scanf("%d",&dizi[i]);																								printf(".%c",tolower(kelime[i]));
	for(i=0;i<n;i++)																							}
		if(n>1 && i!=n-1)
			if(dizi[i+1]>dizi[i] || dizi[i]<0)
				exit(1);	//e�er skor tablosuna negatif say� giri�i yap�l�rsa ya da ayk�r� bir s�ralama girilirse program sonland�r�lacak
	for(i=0;dizi[i]>=dizi[k-1] && dizi[i] && i<n;i++);		//dikkat ederseniz bu sat�rdaki for i�in scope a�mad�m, ama for'un i�inde
	printf("Oyunu kazanan kisi sayisi: %d",i);				//kod blo�u olu�turmasam bile i�erdeki 3 ko�ul birden do�ru oldu�u s�rece
}															//i birer birer artacak ve saya� rol� �stlenecek
	//bu arada "dizi[i]" ko�ulu dizi[i]!=0 ise "true" [a[i]==-n,...,-3,-2,-1,1,2,3,...,n], dizi[i]==0 ise "false" oluyor

   Eni m, boyu n cm olan bir bo� tahtaya eni 1, boyu 2 cm olan dominolardan �st �ste gelmeyecek �ekilde			Klavyeden toplam n defa olmak �zere her yeni sat�rda "X++", "++X", "X--", "--X" operasyonlar�ndan biri girildi�inde x=0
   maksimum ka� tane yerle�tirilebilece�ini yazd�ran program													de�erine bu operasyonlar ger�ekle�tirildi�ine g�re t�m operasyonlar bitti�inde x de�erinin son de�erini d�nd�ren program

int main() {											//sorunun alternatif ��z�m�:							int main() {
	int m,n,i,j,sayac=0;								//int main() {												int x=0,n;
	printf("Tahtanin eni ve boyunu giriniz: ");			//    int m,n;												char girdi[4];	//3 karakter + 1 NULL
	scanf("%d%d",&m,&n);								//    printf("Eni ve boyu girin: ");						printf("Operasyon sayisi: ");
	int **tahta=(int**) malloc(sizeof(int*)*m);			//    scanf("%d%d",&m,&n);									scanf("%d\n",&n);
	for(i=0;i<m;i++) {									//    printf("Domino sayisi: %d",m*n/2);					while(n--) {	//n>0 ise true, n=0 oldu�u an false
		tahta[i]=(int*) malloc(sizeof(int)*n);			//}																gets(girdi);	
		for(j=0;j<n;j++)																								x+=44-girdi[1];		//girdi[1], girdinin 2. karakteri oldu�undan ya '+' ya da '-'dir
			tahta[i][j]=0;																							}		//ASCII kodlar�na g�re '+'=43 ve '-'=45 oldu�undan e�er girdi[1]='+' ise statement x+=1, '-' ise x-=1 (x+=-1) olur
	}																												printf("Sonuc: %d",x);
	for(i=0;i<m-1;i+=2)																							}
		for(j=0;j<n;j++) {
			tahta[i][j]=1;																						Toplam n tane olmak �zere k�rm�z�, mavi veya ye�il renklerdeki ta�lar masada bir s�ra halinde dizilmi� olarak bulunmaktad�r.
			tahta[i+1][j]=1;																					Klavyeden n de�eri ve ta�lar�n s�ralan��� ta�lar�n renklerine g�re 'K','M' ve 'Y' ile g�sterildi�i bir katar bi�iminde girildi�ine	
			sayac++;																							g�re kom�u ta�lar�n birbirinden farkl� renklerde olmas� i�in masadan minimum ka� ta� al�nmas� gerekti�ini yazd�ran program
		}
	i=m-1;																										int main() {
	for(j=0;j<n-1;j+=2)																								int n,i,sayac=0;
		if(!tahta[i][j] && !tahta[i][j+1]) {																		printf("Tas sayisini giriniz: ");
			tahta[i][j]=1;																							scanf("%d",&n);
			tahta[i][j+1]=1;																						printf("Tas sirasini giriniz (M: Mavi, Y: Yesil, K: Kirmizi): ");
			sayac++;																								char *string=(char*) malloc(n);		//sizeof(char)=1 oldu�u i�in �arp�m durumunda yazm�yorum, yazmayaca��m
		}																											scanf("%s",string);
	printf("Yerlestirilebilecek maksimum domino sayisi: %d",sayac);		//!! sayac=(int)(m*n/2) !!					for(i=0;i<n-1;i++)		//n=strlen(string) bu arada
}																														if(string[i]==string[i+1])
																															sayac++;
   Maksimum 100 tane rakamla yap�labilen ve toplananlar� klavyeden girilen seri bir toplama i�leminde				printf("\nAlinmasi gereken tas sayisi: %d",sayac);
   toplananlar� k���kten b�y��e do�ru s�ralay�p kullan�c�ya ayn� seri toplama i�lemini d�nd�ren program				}

int main() {																									Sadece k���k harflerden olu�an bir �ngilizce bir kelimenin birbirinden farkl� ka� tane harften olu�tu�unu yazd�ran program
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
	for(i=0;i<strlen(string);i++)																					printf("Farkl� harf say�s�: %d",sayac); 
		printf("%c",string[i]);																					}
}

   Klavyeden girilen ve 24 tane 0 ile bir tane 1'den olu�an 5*5'lik bir matriste sadece yan yana				Klavyeden x, y, z bile�enleri girilen n tane vekt�r�n bile�kesi 0 ise "EVET", de�ilse "HAYIR" yazd�ran program
   veya �st �ste konumlanm�� iki eleman�n yerlerini de�i�tirerek minimum ka� hamlede 1 eleman�n�
   matrisin merkezine yerle�tirebilece�imizi yazd�ran program													struct vektor {
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
                            swap(matris[i][j],matris[i][--j]);													Klavyeden girilen bir katar�n birtak�m harfleri ��kar�ld���nda "hello" kelimesi elde edilebiliyorsa "EVET", hi�bir
                        else																					t�rl� elde edilemiyorsa "HAYIR" yazd�ran program
                            break;
                    hamle++;																					int main() {
                }																									int i=0;
                printf("\nGereken minimum hamle sayisi: %d",hamle);													char harf,hello[5]="hello";
                return 0;	//exit(0) ile ayn�; main fonksiyonu burada biter, program sonlan�r						while(scanf("%c",&harf) && harf!='\n')	//newline olana kadar (ba� harften son harfe kadar) girilen katar�n her bir harfi
            }																											if(harf=hello[i])			//tek tek incelenir ve gelen harfler "hello"nun s�rayla 1.,2.,3.,4.,5. harflerine
}																															i++;					//e�itse araya giren harfler ��kar�ld���nda yine "hello" elde edilebilir demektir
																													printf(i==5 ? "EVET" : "HAYIR");	//" if(i==5)  printf("EVET");  else  printf("HAYIR"); " ile ayn� �ey, tabii daha k�sa :)
   Sadece 4 ve 7 rakamlar�ndan olu�an say�lar ve bu say�lara tam b�l�nebilen say�lar �ansl� say� olarak
   tan�mland���na g�re, klavyeden girilen 1 ila 1000 aras�ndaki bir say�n�n �ansl� olup olmad���n� yazd�ran program

int main() {
    int i,sayi,sanslisayi[9]={4,7,47,74,447,474,477,747,774};
    printf("Sayi giriniz: ");	//44, 77, 444, 744 ve 777 �ansl� say�lar olsa da zaten 4 ya da 7'nin kat� oldu�u
    scanf("%d",&sayi);			//i�in diziye ekleyip bilgisayar� fazladan yormaya gerek yok
    for(i=0;i<9;i++)																							�ki N-S kutuplu �ubuk m�knat�s birbirlerini �ekip birle�tiklerinde tek bir m�knat�s say�lmaktad�r. Klavyeden m�knat�s say�s�
        if(sayi%sanslisayi[i]==0) {																				ve ayn� do�rultuda oldu�u varsay�lan bu �ubuk m�knat�slar�n birbirlerine g�re nas�l kutupland��� NS veya SN olarak s�rayla
            printf("%d bir sansli sayidir",sayi);																girilece�ine g�re, bu m�knat�slar serbest b�rak�ld�ktan sonra toplam ka� m�knat�s bulunaca��n� yazd�ran program
            break;
        }																										int main() {
    if(i==9)																										int n,i;
        printf("%d bir sansli sayi degildir",sayi);																	printf("Miknatis sayisini ve bu miknatislarin kutuplanislarini giriniz: ");
}																													scanf("%d",&n);
																													int N=n;
   1'den n'e kadar numaraland�r�lm�� n tane ki�i kendi aralar�nda ba�kalar�na ya da kendilerine hediye				char **magnetler=(char**) malloc(sizeof(char*)*N);
   verecektir. n de�eri ve 1,2,3,...,n no'lu ki�ilerin s�rayla ka� no'lu ki�ilere hediye verece�i klavyeden			for(i=0;i<N;i++) {
   girilece�ine g�re; 1,2,3,...,n no'lu ki�ilerin ka� no'lu ki�ilerden hediye ald���n� s�rayla yazd�ran program			magnetler[i]=(char*) malloc(sizeof(char)*2);
																														scanf("%s",magnetler[i]);
int main() {																										}
	int n,i,j,gecici;								//sorunun 2. dizi olu�turmadan yap�lan alternatif ��z�m�:		for(i=0;i<N-1;i++)
	printf("Kisi sayisini giriniz: ");								//int main() {										if(strcmp(magnetler[i],magnetler[i+1])==0)
	scanf("%d",&n);													//    int dizi[500],n,i,t;								n--;
	int *dizi=(int*) malloc(sizeof(int)*n);							//    printf("Kisi sayisi: ");					printf("OLusan miknatis sayisi: %d",n);
	int *dizi2=(int*) malloc(sizeof(int)*n);						//    scanf("%d",&n);						}
	printf("Kisilerin kimlere hediye verecegini sirayla yaziniz: ");//    printf("Hediye verenler sirasi: ");
	for(i=0;i<n;i++) {												//    for(i=1;i<=n;i++) {
		scanf("%d",&dizi[i]);										//        scanf("%d",&t);
		for(j=1;j<=n;j++)											//        dizi[t]=i;
			if(dizi[i]==j)											//    }		//dizi[0] NULL kal�yor
				dizi2[j-1]=i+1;										//    printf("Hediye alanlar sirasi: ");
	}																//    for(i=1;i<=n;i++)
	printf("Kisilerin kimlerden hediye aldiginin listesi: ");		//        printf("%d ",dizi[i]);
	for(i=0;i<n;i++)												//}
		printf("%d ",dizi2[i]);
}

   Bir n tam say�s� i�in 1'den n'e kadar olan tam say�lar aras�ndan ilk olarak tek say�lar k���kten b�y��e
   s�raland�ktan sonra ard�ndan �ift say�lar k���kten b�y��e s�ralan�yor. Klavyeden n ve k de�erleri girilen ve
   n de�eri i�in olu�turulan bu dizide k. s�rada hangi say�n�n oldu�unu array kullanmadan yazd�ran program

int main() {
    unsigned long long n,k;		//int => 4 byte=32 bit, long => 8 byte=64 bit, long long ==> 16 byte=128 bit
    scanf("%lld%lld",&n,&k);	//int b�lmesi yaparken "ceil" yapmak, yani say� ondal�ksa �st say�ya yuvarlamak i�in ceil(n/2) yerine (n+1)/2 kullan�l�r
    printf("%lld",k<=(n+1)/2 ? 2*k-1 : 2*(k-(n+1)/2));	//" if(k<=(n+1)/2)  printf("%lld",2*k-1);  else  printf("%lld",2*(k-(n+1)/2)); " ile ayn� �ey
}	//k de�eri orta de�erden k���k e�itse 2*k-1 de�erini yazd�r (1,3,5,7,...,(n+1)/2), de�ilse orta de�erle fark�n�n 2 kat�n� (2,4,6,8,...,n) yazd�r

   1,2,3,4 ki�ilik ��renci gruplar� Kapadokya'ya gitmek i�in belli say�da 4 ki�ilik taksi �a��racaklard�r.
   Ayn� grubun elemanlar� ayn� taksiye binece�ine ve bir taksiye birden fazla grup binebilece�ine g�re grup
   say�s� ve bu gruplar�n ka� ki�ilik oldu�u s�rayla klavyeden girilen ve b�t�n ��rencilerin Kapadokya'ya
   gidebilmesi i�in en az ka� taksi �a��r�lmas� gerekti�ini yazd�ran program

int main() {
	int n,i,x,taxi[5]={0,0,0,0,0};	//taxi[0] eleman� kullan�lmayacak
	printf("Grup sayisi: ");
	scanf("%d",&n);
	printf("Gruplarin kac kisi oldugu: ");
	for(i=0;i<n;i++) {
		scanf("%d",&x);
		taxi[x]++;		//1 ki�ilik grup say�s�n� taxi[1], 2 ki�ilik grup say�s�n� taxi[2], 3 ki�ilik grup say�s�n� taxi[3], 4 ki�ilik grup say�s�n� taxi[4] tutuyor
	}					//4 ve 3 ki�ilik gruplar i�in �a��r�lan taksi say�s� toplam grup say�s� kadar zira 4 ki�ilik grubun bulundu�u taksilere kimse binemezken 3 ki�ilik gruplar�n bulundu�u taksilere sadece 1 ki�i binebilir
	printf("Gerekli taksi sayisi: %d",taxi[4]+taxi[3]+(2*taxi[2]+(taxi[1]>taxi[3] ? taxi[1]-taxi[3] : 0)+3)/4);	//1 ki�ilik grup say�s� 3 ki�ilik grup say�s�ndan fazla ise 2'sinin fark�n�, de�ilse 0 d�nd�r
}	//b�ylelikle 3 ki�ilik gruplar�n bulundu�u taksilere 1 ki�ilik gruplar biner ve fazladan taksi �a��r�lmaz, geri kalan 1 ki�ilik gruplar�n bindi�i taksi say�s� (taxi[1]-taxi[3])/4 olurken 2 ki�ilik gruplar�n
	//bindi�i taksi say�s� taxi[2]/2 olur     toplamada "+3" ise ceil fonksiyonu misali int b�lmesinin sonucu ondal�k ��karsa sonucu bir �st say�ya yuvarlamak i�in var

   Klavyeden girilen kelimeleri kelimeyi olu�turan harfler o kelime i�erisinde alfabetik s�ralamada dizilmi� olacak �ekilde s�rayla d�nd�ren program

int main() {																									Klavyeden girilen bir katar� "blah" ve "BLAH" adl� katarlardan ar�nd�rarak d�nd�ren program
	char kelime[200][1000],gecici,a;	//max 200 kelime, kelime ba�� max 1000 harf
	int i,j,k=-1;																								int main() {
	printf("Kelimeleri giriniz: ");																					char a[1000]; int i;
	while(a!='\n') {																								printf("Katari giriniz: ");
		scanf("%s%c",kelime[++k],&a);		//alternatif olarak 208-214 no'lu sat�rlar:								gets(a);
		for(i=0;i<strlen(kelime[k]);i++)			//for(i=0;i<strlen(kelime[k])-1;i++)							for(i=0;a[i]!=NULL;i++)
			for(j=0;j<strlen(kelime[k]);j++)		//    for(j=0;j<strlen(kelime[k])-i-1;j++)							if((a[i]=='b' && a[i+1]=='l' && a[i+2]=='a' && a[i+3]=='h') || (a[i]=='B' && a[i+1]=='L' && a[i+2]=='A' && a[i+3]=='H')) {
				if(kelime[k][i]<kelime[k][j]) {		//        if(kelime[k][j]>kelime[k][j+1]) {								a[i]=' ';
					gecici=kelime[k][i];			//            gecici=kelime[k][j];										a[i+1]=' ';
					kelime[k][i]=kelime[k][j];		//            kelime[k][j]=kelime[k][j+1];								a[i+2]=' ';
					kelime[k][j]=gecici;			//            kelime[k][j+1]=gecici;									a[i+3]=' ';
				}									//        }															}
	}				//olarak bubble sort ile de�i�tirilirse kod yakla��k 2 kat daha h�zl� �al���r					printf("Arindirilmis katar: %s",a);
	printf("Duzenlenmis kelimeler: ");																			}
	for(i=0;i<=k;i++)
		printf("%s ",kelime[i]);
}

   k tane oyuncu ekip �al��mas�yla n tane seviyeden olu�an bir bilgisayar oyununu bitirmeye �al��acakt�r.
   Oyundaki seviye say�s�, oyuncu say�s� ve bu oyuncular�n her birinin tek ba�lar�na oyunun hangi
   seviyelerini ge�ebildi�i klavyeden girildi�ine g�re bu oyuncular�n birlikte oyunu bitirip					Klavyeden girilen bir dizinin elemanlar�n�n sadece birinin tek di�erlerinin �ift ya da sadece birinin �ift di�erlerinin
   bitiremeyece�ini yazd�ran program 																			tek oldu�u bilindi�ine g�re teklik-�iftlik a��s�ndan farkl� olan say�n�n s�ras�n� yazd�ran program

int main() {																									int main() {
	int n,o,s,i,j,k;																								int i,j=0,k=0,n;
	printf("Seviye sayisini giriniz: ");																			printf("Dizinin eleman sayisi: ");
	scanf("%d",&n);																									scanf("%d",&n);
	int *level=(int*) malloc(sizeof(int)*n);																		int dizi[n],tek[n],cift[n];		//sak�n b�yle yazmay�n, onun yerine dinamik bellek tahsisi yap�n
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

   Klavyeden liste y�ntemiyle girilen bir harf k�mesinde k���k-b�y�k harf ayr�m� fark etmeksizin
   ka� farkl� harf oldu�unu yazd�ran program

int i,alf[30],sayac; //global de�i�ken olduklar� i�in i, sayac ve alf[30] dizisinin her eleman�n�n
char n;				 //default de�eri 0
int main() {
	printf("Kumeyi giriniz: ");
	while(n!='}') {
		scanf("%c",&n);
		if(n!=' ' && n!=',')
			alf[tolower(n)-'a']++;	//B�y�k harfler otomatik olarak k���k harfe d�n��t�r�l�yor
	}								//ve o k���k harfin k�medeki say�s�na ekleniyor
	for(i='a';i<='z';i++)
		if(alf[i-'a'])	//e�er alf[i-'a']'nin de�eri en az 1 ise true, 0 ise yani o harf k�mede yoksa false
			sayac++;
	printf("Farkli harf sayisi: %d",sayac);
}	//bu arada bu -'a' kal�plar� olmasa da kod sorunsuz �al���r da index'i 97-122 aras� yerine klasik 0-25 aras� tutmak i�in b�yle yapt�m

   A�a��daki program�n ��kt�s�

int main() {
	int m=7,n=4,k=8;
	float a,b;
	a=(float)(m*4)/(n+k);		//a=(7*4)/(4+8)=2.333333
	b=(float)((2*n)/(m-n));		//b=floor((2*4)/(7-4))=floor(2.666667)=2.000000
	m+=n++;				//m=m+n=7+4=11		n=4+1=5
	n+=--k;				//n=n+(k-1)=5+(8-1)=12		k=8-1=7
	printf("%.3f",a+b+m+n-k);		//��kt� 2.333333+2+11+12-7=20.333333'�n son 3 basama��na kadar ==> "20.333"
}

   �ki zarla oynanan bir oyunda; at��ta gelen say�lar�n toplam� 9 ya da daha b�y�kse oyuncu kazan�yor, 5 ila 8 aras�nda ise oyuncu tekrar zar at�yor, 4 ya da daha k���kse oyuncu kaybediyor.
   Buna g�re, oyuncu kaybedene ya da kazanana kadar oyunu oynayan program

int zar1,zar2;																									�ki zarla oynanan bir oyunda; at��ta gelen say�lar�n toplam� 9 ya da daha b�y�kse oyuncu kazan�yor, 5 ila 8 aras�nda ise oyuncu tekrar zar at�yor, 4 ya da daha k���kse oyuncu kaybediyor.	
int ZarAt() {																									Buna g�re, oyuncu kaybedene ya da kazanana kadar oyunu goto yard�m�yla oynayan alternatif program
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
		}																										}		//m�lakattan at�lmak istemiyorsan goto ve global de�i�ken kullanma
	} while(1);
	return 0;
}

   Klavyeden girilen c�mleyi 0'a bas�ld���nda rakamlardan ar�nd�rarak yazd�ran, 1'e bas�ld���nda ise b�y�k harflerde yazd�ran program

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

   1'den n'e kadar numaraland�r�lm�� olan n tane ki�i ard���k numaral� ki�iler yan yana gelecek �ekilde bir yuvarlak masaya oturmu�tur.
   s numaral� ki�iden ba�layarak artan s�ra no'suna g�re bu ki�ilere m tane �eker da��t�laca��na g�re, klavyeden girilen m, n ve s
   de�erlerine g�re son �ekeri ka� numaral� ki�inin alaca��n� yazd�ran program

int main() {
	int m,n,s;
	printf("Kisi sayisini, seker sayisini ve ilk sekeri alacak kisinin no'sunu giriniz: ");
	scanf("%d%d%d",&n,&m,&s);
	int a=s+m-1;
	printf("Son sekeri alacak kisinin no'su: %d", a>n ? (a%n==0 ? n : a%n) : a);
}

   Bir dizinin en sonundaki eleman� ba�a, di�er elemanlar� da bir sa�a kayd�r�l�yorsa o dizi bir rotasyon ge�irmi� oldu�una g�re, klavyeden
   girilen dizi r defa rotasyon ge�irdikten sonra bu dizide klavyeden girilen index'lerde hangi say�lar�n bulundu�unu yazd�ran program */

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
