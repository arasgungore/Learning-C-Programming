#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/* printf ve scanf fonksiyonlar�n� kullanmadan klavyeden girilen bir c�mleyi " .,;!?()[]'"%&^\/ "		1'den 100'e kadar numaraland�r�lm�� olan adaylara halk�n verdi�i oylar klavyeden girilece�ine g�re en �ok oy alan
   karakterlerinden ar�nd�rarak yazd�ran program														en k���k no'lu aday� ald��� oy say�s�yla birlikte yazd�ran program

int main() {																							int main() {
	char cumle[1000],semboller[17]=".,;!?()[]'\"%&^\\/";													int i,j,n,oy_sayisi[100],max=0;
	unsigned int i,j;																						for(i=0;i<100;i++)
	gets(cumle);																								oy_sayisi[i]=0;
	for(i=0;i<strlen(cumle);i++)																			printf("Oy sayisi: ");
		for(j=0;j<17;j++)																					scanf("%d",&n);
			if(cumle[i]==semboller[j])																		int *dizi=(int*) malloc(sizeof(int)*n);
				cumle[i]=' ';																				printf("Oylar: ");
	puts(cumle);																							for(i=0;i<n;i++) {
}																												scanf("%d",dizi+i);			//"dizi+i" ile "&dizi[i]" ayn� �ey
																												oy_sayisi[dizi[i]-1]++;
   Klavyeden girilen bir int array'inde ortalamadan sapmas� 50 ve daha k���k olan elemanlar�					if(oy_sayisi[dizi[i]-1]>max || (oy_sayisi[dizi[i]-1]==max && dizi[i]<j)) {
   s�rayla yazd�ran program																							max=oy_sayisi[dizi[i]-1];
																													j=dizi[i];
int main() {																									}
	int i,n,*dizi,toplam=0;																					}
	printf("Eleman sayisini giriniz: ");																	printf("En cok oy alan aday ve aldigi oy sayisi: %d %d",j,max);
	scanf("%d",&n);																						}
	dizi=(int*) malloc(sizeof(int)*n);
	printf("Diziyi giriniz: ");																			Klavyeden girilen 8 kelime i�in sadece ilk kelimeden leksikografik olarak k���k olan kelimelerle bir c�mle kuran program
	for(i=0;i<n;i++) {
		scanf("%d",&dizi[i]);																			int main() {
		toplam+=dizi[i];																					int i;
	}																										char string[8][20];
	double ort=(double)toplam/n;																			printf("8 tane kelime giriniz (her sat�r ba��na bir kelime):");
	printf("Ortalamadan sapmasi 50 ve daha kucuk olan elemanlar: ");										for(i=0;i<8;i++)
	for(i=0;i<n;i++)																							gets(string[i]);
		if(dizi[i]<=ort+50 && ort-50<=dizi[i])																printf("Olusan cumle: ");
			printf("%d ",dizi[i]);																			for(i=1;i<8;i++)
}																												if(strcmp(string[i],string[0])<0)
																													printf("%s ",string[i]);
   Klavyeden s�ras�yla merkezlerinin xy koordinatlar� ve yar��aplar� girilen 2 �emberin					}
   koordinat d�zlemi �zerinde kesi�ip kesi�medi�ini yazd�ran program

typedef struct {																						Klavyeden girilen string'deki say�lar� ay�klay�p toplam�n� yazd�r�p kalan string'i k���k harflerle yazd�ran program
	double x;
	double y;																							int main() {
	double r;																								unsigned int i,k=0,sayac=0,sayac_2=0;
} cember;																									char string[500],string_2[500];
int main() {																								printf("Girdi: ");
	cember c1,c2;																							gets(string);
	printf("1. cemberin merkez koordinatlarini ve yaricapini giriniz: ");									strlwr(string);
	scanf("%lf%lf%lf",&c1.x,&c1.y,&c1.r);																	for(i=0;i<strlen(string);i++) {
	printf("2. cemberin merkez koordinatlarini ve yaricapini giriniz: ");										if('a'<=string[i] && string[i]<='z')
	scanf("%lf%lf%lf",&c2.x,&c2.y,&c2.r);																			string_2[k++]=string[i];
	double merkezler_arasi_uzaklik=sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));						while('0'<=string[i+1] && string[i+1]<='9') {
	double yaricaplar_toplami=c1.r+c2.r;					//d^2 = (x1-x2)^2 + (y1-y2)^2							sayac*=10;
	if(yaricaplar_toplami<merkezler_arasi_uzaklik)																	sayac+=string[++i]-'0';
		printf("Cemberler kesismiyor");																			}
	if(yaricaplar_toplami>merkezler_arasi_uzaklik)																sayac_2+=sayac;
		printf("Cemberler kesisiyor");																			sayac=0;
	if(yaricaplar_toplami==merkezler_arasi_uzaklik)															}
		printf("Cemberler birbirine teget");																printf("Toplam: %d\nAyiklanmis string: %s",sayac_2,cumle);
}																										}

   Klavyeden girilen matrisin 180 derece kendi etraf�nda d�nd�r�lm�� halini yazd�ran program			Klavyeden girilen matristeki ilk tekrar eden eleman�n ilk kez tekrar etti�i index no'lar�n�n toplam�n� yazd�ran program

void swap(int *a,int *b) {																				int main() {
	int gecici=*a;																							int i,j,k,l,m,n;
	*a=*b;																									printf("Matrisin boyutlarini giriniz: ");
	*b=gecici;																								scanf("%d%d",&m,&n);
}																											printf("Matrisi giriniz: ");
int main() {																								int **matrix=(int**) malloc(sizeof(int*)*m);
	int n,i,j;																								for(i=0;i<m;i++)
	printf("Matrisin buyuklugu: ");																				matrix[i]=(int*) malloc(sizeof(int)*n);		//matris[m][n] de yap�labilirdi dinamik bellek tahsisi yerine
	scanf("%d",&n);																							for(i=0;i<m;i++)
	int matrix[n][n];																							for(j=0;j<n;j++)
	puts("Matrisi giriniz:");																						scanf("%d",&matrix[i][j]);
	for(i=0;i<n;i++)																						for(i=0;i<m;i++)
		for(j=0;j<n;j++)																						for(j=0;j<n;j++) {
			scanf("%d",&matrix[i][j]);																				for(k=i,l=j+1;l<n;l++)
	for(i=0;i<(n+1)/2;i++)																								if(matrix[i][j]==matrix[k][l]) {
		for(j=0;j<n;j++) {																									printf("Ilk tekrar eden elemanin ilk kez tekrar ettigi index no'lari toplami: %d",k+l);
			if(n%2==1 && i==n/2 && j==n/2)																					return 0;
				break;																									}
			swap(&matrix[i][j],&matrix[n-1-i][n-1-j]);																for(k=i+1;k<m;k++)
		}																												for(l=0;l<n;l++)
	puts("\nMatrisin 180 derece dondurulmus hali:");																		if(matrix[i][j]==matrix[k][l]) {
	for(i=0;i<n;i++) {																											printf("Ilk tekrar eden elemanin ilk kez tekrar ettigi index no'lari toplami: %d",k+l);
		for(j=0;j<n;j++)																										return 0;
			printf("%d ",matrix[i][j]);																						}
		printf("\n");																							}
	}																										printf("Tekrar eden eleman yok");
	return 0;																								return 0;
}																										}

   Klavyeden girilen matriste index no'lar�na g�re elemanlar en ba�tan itibaren s�rayla okundu�unda
   ilk defa tekrar etti�i g�r�len eleman�n index no'lar�n�n toplam�n� yazd�ran program					Klavyeden girilen dizinin ayn� elemanlar� aras�nda aralar�ndaki mesafe minimum olanlar�n�n index no'lar�n� yazd�ran program

int main() {																							int main() {
	int i,j,k,l,m,n;																						int i,j,k,l,boyut,mesafe;
	printf("Matrisin boyutlarini giriniz: ");																printf("Dizinin boyutunu giriniz: ");
	scanf("%d%d",&m,&n);																					scanf("%d",&boyut);
	printf("Matrisi giriniz: ");																			printf("Diziyi giriniz: ");
	int **matrix=(int**) malloc(sizeof(int*)*m);															int *dizi=(int*) malloc(sizeof(int)*boyut);
	for(i=0;i<m;i++)																						mesafe=boyut;
		matrix[i]=(int*) malloc(sizeof(int)*n);																for(i=0;i<boyut;i++)
	for(i=0;i<m;i++)																							scanf("%d",&dizi[i]);
		for(j=0;j<n;j++) {																					for(i=0;i<boyut;i++)
			scanf("%d",&matrix[i][j]);																			for(j=0;j<boyut;j++)
			for(k=0;k<i;k++)																						if(i!=j && dizi[i]==dizi[j] && abs(i-j)<mesafe) {
				for(l=0;l<n;l++)																						mesafe=abs(i-j);
					if(matrix[i][j]==matrix[k][l]) {																	k=i,l=j;
						printf("Ilk tekrar ettigi gorulen elemanin index no'lari toplami: %d",i+j);					}
						return 0;																			if(mesafe==boyut)
					}																							printf("Tekrar eden eleman yok");
			for(k=i,l=0;l<j;l++)																			else
				if(matrix[i][j]==matrix[k][l]) {																printf("Aradaki uzaklik: %d\nEleman: %d\nElemanlarin index no'lari: %d %d",mesafe,dizi[k],k,l);
					printf("Ilk tekrar ettigi gorulen elemanin index no'lari toplami: %d",i+j);			}
					return 0;
				}
		}
	printf("Tekrar eden eleman yok");
	return 0;
}

   Klavyeden x ekseni �zerindeki konumlar� ve x eksenine g�re h�zlar� girilen 2 kangurunun birim zamanda bir kere s��rad�klar� bilindi�ine g�re bu
   kangurular�n herhangi bir zaman diliminde ayn� konumda bulunup bulunmayaca��n� "EVET" ve "HAYIR" d�nd�ren bir fonksiyon yard�m�yla yazd�ran program

char* kanguru(int x1,int v1,int x2,int v2) {															Bir �evre yolu �zerinde birbirinden e�it uzakl�kta, saat y�n�nde s�rayla 1'den n'e kadar numaraland�r�lm�� n tane ev bulunmaktad�r.
	if(v1==0 && v2==0) {																				1 no'lu evde oturan ki�i m tane eve s�rayla ziyarete gidecektir. Trafik ak��� da tek saat y�n�nde ve ard���k iki ev aras� 1 saat
		if(x1==x2)																						oldu�una g�re, t�m seferin toplam ka� saat tutaca��n� array kullanmadan yazd�ran program
			return "EVET";
		else																							int main() {
			return "HAYIR";																					long long n,m,x,i,sum=0,pos=1;
	}																										printf("Sirayla toplam ev sayisini ve ziyaret edilecek ev sayisini giriniz: ");
	int arkax= x1<x2 ? x1 : x2;																				scanf("%I64d %I64d",&n,&m);
	int arkav= arkax==x1 ? v1 : v2;																			printf("Ziyaret edilecek ev no'larini sirayla giriniz: ");
	int onx= x1>x2 ? x1 : x2;																				for(i=0;i<m;i++) {
	int onv= onx==x1 ? v1 : v2;																					scanf("%I64d",&x);
	while(arkax<onx) {																							sum += x>=pos ? x-pos : n+x-pos;
		arkax+=arkav;																							pos=x;
		onx+=onv;																							}
		if(arkax==onx)																						printf("Toplam sefer suresi: %I64d saat",sum);
			return "EVET";																				}
	}
	return "HAYIR";																						n uzunlu�undaki bir kurdele, a, b veya c uzunluklar�na sahip par�alara b�l�necektir. Buna g�re, bu kurdelenin a, b, c
}																										uzunluklar�ndan herhangi birine sahip en fazla ka� par�aya b�l�nebilece�ini yazd�ran program
int main() {
	int x1,v1,x2,v2;																					int main() {
	printf("Sirayla 1. ve 2. kangurularin konumlarini ve hizlarini giriniz: ");								int n,a,b,c,i,j,ans=0;
	scanf("%d%d%d%d",&x1,&v1,&x2,&v2);																		printf("Kurdelenin ve parcalarin uzunluklarini giriniz: ");
	printf("Bu iki kanguru ayni anda karsilasir mi: %s",kanguru(x1,v1,x2,v2));								scanf("%d %d %d %d",&n,&a,&b,&c);
	return 0;																								for(i=0;i*a<=n;i++)
}																												for(j=0;j*b<=n;j++)
																													if(i*a+j*b<=n && (n-i*a-j*b)%c==0 && ans<i+j+(n-i*a-j*b)/c)
																														ans=i+j+(n-i*a-j*b)/c;
																											printf("Maksimum elde edilebilecek parca sayisi: %d",ans);
																										}

   Bir �niversite hocas�, klavyeden girilen ��rencilerin ders ba�ar� notlar�n� ��renci 40'�n alt�nda not al�p dersten kalmad��� s�rece al�nan not notun yuvarlanabilece�i 5'in kat�ndan
   en fazla 2 puan eksikse notu 5'in en yak�n kat�na yuvarlay�p ��rencilerin notlar�n� y�kseltti�ine g�re ��rencilerin nihai ders ba�ar� notlar�n� yazd�ran program

int main() {																							Klavyeden girilen say�lar�n T-asal� (toplamda 3 tane pozitif tam say� b�leni olan do�al say�) olup olmad�klar�n� yazd�ran program
	int i,n;
	printf("Not sayisini giriniz: ");																	int main() {	//asal say�lar�n toplamda 2 tane pozitif tam say� b�leni (kendisi ve 1) varken T-asallar�n�n bir tane daha vard�r
	scanf("%d",&n);																							int n; long long a,b,i;		//b�t�n T-asallar� asl�nda asal say�lar�n karelerinden ibarettir
	int *notlar=calloc(n,sizeof(int));																		printf("Kac tane sayi gireceginizi giriniz: ");
	printf("Notlari giriniz: ");																			scanf("%d",&n);				//yani asal say�lar k�mesinin t�m elemanlar�n�n karesi al�narak T-asallar� k�mesi elde edilir
	for(i=0;i<n;i++) {																						printf("Taranacak sayilar: ");
		scanf("%d",notlar+i);																				while(n--) {
		printf( i==0 ? "Son notlar: " : " ");																	scanf("%I64d",&a);
		*(notlar+i)= notlar[i]<40 || notlar[i]%5<3 ? notlar[i] : notlar[i]-(notlar[i]%5)+5;						b=sqrt(a);
		printf("%d",*(notlar+i));																				for(i=2;i*i<=b;i++) if(b%i==0) break;
	}																											printf(i*i>b && b*b==a && a>1 ? "%I64d bir T-asalidir.\n" : "%I64d bir T-asali degil.\n", a);
}																											}
																										}

   Klavyeden kenar uzunluklar� girilen dikd�rtgenler aras�ndan en k���k alana sahip dikd�rtgenin alan�n� yazd�ran program

typedef struct {																						Klavyeden girilen 11'den b�y�k pozitif bir tam say�y�, iki tane bile�ik (asal olmayan) say�n�n toplam�
	double a;																							olarak ifade eden b�t�n ikili kombinasyonlar� yazd�ran program
	double b;
} dikdortgen;																							int isitPrime(int x) {
int main() {																								int i;
	int i,n;																								for(i=2;i<=sqrt(x);i++)
	double min;																									if(x%i==0)
	printf("Dikdortgen sayisi: ");																					return 0;
	scanf("%d",&n);																							return 1;
	double *alan=malloc(n*sizeof(double));																}
	dikdortgen *d=malloc(n*sizeof(dikdortgen));															int main() {
	for(i=0;i<n;i++) {																						int i,n;
		printf("%d. dikdortgen: ",i+1);																		printf("11'den buyuk bir tam sayi giriniz: ");
		scanf("%lf%lf",&d[i].a,&d[i].b);																	scanf("%d",&n);
		alan[i]=d[i].a*d[i].b;																				for(i=4;i<=n/2;i++)
		if(i==0 || alan[i]<min)																					if(!(isitPrime(i) || isitPrime(n-i)))
			min=alan[i];																							printf("%d\t+\t%d\t=\t%d\n",i,n-i,n);
	}																									}
	printf("En kucuk alana sahip dikdortgenin alani: %lf",min);
}

   Bir parolan�n g��l� say�labilmesi i�in en az bir rakam, bir k���k harf, bir b�y�k harf ve bir �zel karakter ("!@#$%^&*()-+") i�ermesi
   ve en az 6 karakter uzunlu�unda olmas� gerekti�ine g�re, klavyeden girilen bir parolan�n g��l� olmas� i�in parolaya en az ka� karakter
   daha eklenmesi gerekti�ini yazd�ran program

int minimumNumber(unsigned int n, char* password) {														Klavyeden girilen bir say�y� son ya da sondan bir �nceki rakam�n� silebilme kayd�yla maksimuma ��karan program
	int i,digit=0,upper=0,lower=0,special=0,x=0;
	for(i=0;password[i]!='\0';i++) {																	int max(int a,int b,int c) {
		if('0'<=password[i] && password[i]<='9')															return a>b ? (a>c ? a : c) : (b>c ? b : c);
			digit++;																					}
		else if('A'<=password[i] && password[i]<='Z')													int main() {
			upper++;																						int n; char str1[30], str2[30];
		else if('a'<=password[i] && password[i]<='z')														printf("Bir sayi giriniz: ");
			lower++;																						scanf("%d",&n);
		else																								itoa(n,str1,10);
			special++;																						itoa(n,str2,10);
	}																										str1[strlen(str1)-1]='\0';
	if(digit==0)																							str2[strlen(str2)-2]=str2[strlen(str2)-1];
		x++;																								str2[strlen(str2)-1]='\0';
	if(upper==0)																							int n1=atoi(str1), n2=atoi(str2);
		x++;																								printf("Arttirilmis yeni sayi: %d", max(n,n1,n2));
	if(lower==0)																						}
		x++;
	if(special==0)
		x++;
	if(n+x<6)
		x=6-n;
	return x;
}
int main() {
	char parola[100];
	printf("Parolayi giriniz: ");
	gets(parola);
	int x=minimumNumber(strlen(parola),parola);
	printf(x==0 ? "Parolaniz guclu" : "Parolaniz guclu degil, minimum %d karakter daha giriniz",x);
	return 0;
}

   Klavyeden �nce bir m�zik t�r� se�ilip sonra da klavyeden �ark�lar�n isimleri, s�yleyen sanat��lar� ve dahil oldu�u m�zik t�rleri girildi�ine g�re girilen �ark�lar aras�ndan
   sadece se�ilen m�zik t�r�ne dahil olanlar� listeyen �ngilizce program

struct song {
	char song_name[15];
	char artist[15];
	char genre;
};
typedef struct song song;
int main() {
	char chosen_genre;
	int number_of_songs,i;
	printf("Select a genre (R: Rock, P: Pop, F: Funk, A: Alternative): ");
	scanf("%c",&chosen_genre);
	printf("Number of songs: ");
	scanf("%d",&number_of_songs);
	song *s=malloc(sizeof(song)*number_of_songs);
	for(i=0;i<number_of_songs;i++) {
		printf("Song name, artist, and genre: ");
		scanf("%s%s %c",s[i].song_name,s[i].artist,&s[i].genre);
	}	//"%c" belirteci bo�luk karakterini haf�zaya atmas�n diye "%s"den sonra bir bo�luk b�rakt�m
	printf("\nSelected songs:");
	for(i=0;i<number_of_songs;i++)
		if(s[i].genre==chosen_genre)
			printf("\n%s - %s",s[i].song_name,s[i].artist);
	return 0;
}

   5x5'lik bir haritada m��terilerin "a,b,c,d,e,f,g,h,i" harfleriyle, drone'un ise 'D' harfiyle g�sterildi�i ve drone'un herhangi bir d�rt y�nde bir karakter ilerledi�inde yak�t�n� 1
   t�ketti�i bilindi�ine g�re klavyeden girilen harita ve yak�t de�eri i�in drone'un hangi m��terilere ula�abilece�ini alfabetik olarak yazd�ran program

int uzaklik(int i1,int j1,int i2,int j2) {
	return abs(i1-i2)+abs(j1-j2);		//uzakl�k=|x1-x2|+|y1-y2|
}
void bulucu(char harita[][5],char a,int *xi,int *xj) {
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(harita[i][j]==a) {
				*xi=i;		//girilen karakterin haritadaki koordinatlar�n� bulur ve *xi ve *xj pointer'lar�na atar
				*xj=j;
			}
}
int main() {
	char harita[5][5],must;
	int i,k=0,yakit,Dronei,Dronej,Musti,Mustj,uzak[9];	//Dronei ve Dronej: drone'un haritadaki koordinatlar�
	printf("Yakit: ");										//Musti ve Mustj: m��terinin haritadaki koordinatlar�
	scanf("%d",&yakit);						//uzak[9]: a,b,c,d,e,f,g,h,i m��terilerinin drone'a olan uzakl�klar� (drone'un bu m��terilere ka� hamle ile gelebilece�i)
	for(i=0;i<5;i++)
		scanf(" %[^\n]%*c",harita[i]);
	bulucu(harita,'D',&Dronei,&Dronej);		//Dronei ve Dronej �uan drone'un koordinatlar�n� tutuyor

	for(must='a';must<='i';must++) {
		bulucu(harita,must,&Musti,&Mustj);	//Musti ve Mustj �uan m��terinin koordinatlar�n� tutuyor
		uzak[must-97]=uzaklik(Dronei,Dronej,Musti,Mustj);	//'a'=97   'a'-97=0
		if(uzak[must-97]<=yakit) {
			printf("%c ",must);		//e�er uzakl�k yak�t�n eri�ebilece�i menzil i�erisindeyse m��teriyi yazd�r
			k++;
		}
	}
	printf(!k ? "\nMenzilde musteri yok" : "\nMenzilde %d musteri var",k);
	return 0;
}

   Klavyeden b�y�kten k����e di�er oyuncular�n skorlar� ve Alice'in bu oyunu tekrar tekrar oynad���nda kazand��� skorlar girilen bir yar��mada ayn� skoru alan ki�iler
   ayn� s�ralamada yer ald���na g�re Alice'in her oynad��� sefer skor tablosunda ka��nc� oldu�unu yazd�ran �ngilizce program

int main() {
	int i,n,m,score,top=0,leaderboard[1000]={0};
	printf("Enter number of players: ");
	scanf("%d",&n);
	printf("Enter the leaderboard scores in descending order: ");
	for(i=0;i<n;i++) {		//e�er skorlar farkl� ise leaderboard array'ine s�rayla kaydet
		scanf("%d",&leaderboard[top+1]);
		if(leaderboard[top+1]!=leaderboard[top])
			top++;
	}
	int realtop=top;
	printf("Enter number of games Alice has played: ");
	scanf("%d",&m);
	printf("Enter Alice's scores in each game: ");
	for(i=0;i<m;i++) {
		scanf("%d",&score);
		while(top && score>=leaderboard[top])
			top--;
		printf(i==0 ? "Ranks of Alice in each game: %d" : " %d",top+1);
		top=realtop;
	}
}

   Klavyeden girilen c�mleyi kelimelerinin ba� harfleri b�y�k olacak �ekilde yazd�ran program

int main() {
	char cumle[1000];
	int i;
	printf("Cumleyi giriniz: ");
	gets(cumle);
	cumle[0]=toupper(cumle[0]);
	for(i=1;i<strlen(cumle);i++)
		if(cumle[i-1]==' ')
			cumle[i]=toupper(cumle[i]);
	printf("Yeni cumle: %s",cumle);
}

   l metre uzunlu�undaki d�z bir sokakta n tane �zde� sokak lambas�, soka��n ba�lang�c� 0, sonu l olmak �zere 0-l aras�ndaki pozisyonlarda bulunmaktad�r.
   Sokak lambalar�n�n say�s�, soka��n uzunlu�u ve sokak lambalar�n�n pozisyonlar� s�rayla klavyeden girilece�ine g�re, b�t�n soka��n ayd�nlatabilmesi
   i�in sokak lambalar�n�n soka�� ayd�nlatma yar��ap�n�n minimum ka� metre olmas� gerekti�ini yazd�ran program

int max(int a,int b) {return a>b ? a : b;}
int main() {
	int n,l;
	printf("Sokak lambalarinin sayisini giriniz: ");
	scanf("%d",&n);
	printf("Sokagin uzunlugunu giriniz (metre): ");
	scanf("%d",&l);
	int array[n+2],i,j;
	array[0]=0;
	array[n+1]=l;
	printf("Sokak lambalarinin pozisyonlarini giriniz: ");
	for(i=1;i<=n;i++)
		scanf("%d",&array[i]);
	for(i=0;i<n-1;i++)
		for(j=1;j<n-i;j++)		//1 ila n. index'lerdeki elemanlar, yani sokak lambalar�n�n pozisyonlar� bubble sort ile k���kten b�y��e s�ralan�yor
			if(array[j]>array[j+1]) {
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
	double max_r=max(array[1]-array[0],array[n+1]-array[n]);
	for(i=0;i<=n;i++)
		if((double)(array[i+1]-array[i])/2.0>max_r)
			max_r=(double)(array[i+1]-array[i])/2.0;
	printf("Sokak lambalarinin ideal aydinlatma yaricapi: %lf metre",max_r);
}

   Bir MMORPG oyununda belli miktarda bir g�� puan� toplam�� pro gamer Kirita, oyunun son seviyesinde ejderlerle d�v��mektedir ve d�v���n galibi daha
   fazla g�� puan�na sahip olan taraf olmaktad�r. Her �ld�rd��� ejder i�in bonus g�� alan Kirita ejderlerle istedi�i s�rada d�v��ebilece�ine g�re,
   Kirita'n�n b�t�n ejderleri �ld�r�p oyunu kazan�p kazanamayaca��n� yazd�ran �ngilizce program */

void swap(int *a, int *b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main() {
	int i,j,strength,number_of_dragons;
	printf("Enter Kirita's initial strength: ");
	scanf("%d",&strength);
	printf("Enter the number of dragons: ");
	scanf("%d",&number_of_dragons);
	int dragons[number_of_dragons][2];
	for(i=0;i<number_of_dragons;i++) {
		printf("Enter the %d. dragon and its loot bonus strength: ",i+1);
		scanf("%d%d",&dragons[i][0],&dragons[i][1]);
	}
	for(i=0;i<number_of_dragons-1;i++)
		for(j=0;j<number_of_dragons-i-1;j++)
			if(dragons[j][0]>dragons[j+1][0]) {
				swap(&dragons[j][0],&dragons[j+1][0]);
				swap(&dragons[j][1],&dragons[j+1][1]);
			}
	for(i=0;i<number_of_dragons;i++)
		if(strength>dragons[i][0])
			strength+=dragons[i][1];
		else {
			printf("Game over!\nDragons killed you, git gud.");
			return 0;
		}
	printf("Congratulations!!!\nAll dragons are defeated, a winrar is you!");
	return 0;
}
