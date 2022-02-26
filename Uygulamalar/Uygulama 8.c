#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/* printf ve scanf fonksiyonlarýný kullanmadan klavyeden girilen bir cümleyi " .,;!?()[]'"%&^\/ "		1'den 100'e kadar numaralandýrýlmýþ olan adaylara halkýn verdiði oylar klavyeden girileceðine göre en çok oy alan
   karakterlerinden arýndýrarak yazdýran program														en küçük no'lu adayý aldýðý oy sayýsýyla birlikte yazdýran program

int main() {																							int main() {
	char cumle[1000],semboller[17]=".,;!?()[]'\"%&^\\/";													int i,j,n,oy_sayisi[100],max=0;
	unsigned int i,j;																						for(i=0;i<100;i++)
	gets(cumle);																								oy_sayisi[i]=0;
	for(i=0;i<strlen(cumle);i++)																			printf("Oy sayisi: ");
		for(j=0;j<17;j++)																					scanf("%d",&n);
			if(cumle[i]==semboller[j])																		int *dizi=(int*) malloc(sizeof(int)*n);
				cumle[i]=' ';																				printf("Oylar: ");
	puts(cumle);																							for(i=0;i<n;i++) {
}																												scanf("%d",dizi+i);			//"dizi+i" ile "&dizi[i]" ayný þey
																												oy_sayisi[dizi[i]-1]++;
   Klavyeden girilen bir int array'inde ortalamadan sapmasý 50 ve daha küçük olan elemanlarý					if(oy_sayisi[dizi[i]-1]>max || (oy_sayisi[dizi[i]-1]==max && dizi[i]<j)) {
   sýrayla yazdýran program																							max=oy_sayisi[dizi[i]-1];
																													j=dizi[i];
int main() {																									}
	int i,n,*dizi,toplam=0;																					}
	printf("Eleman sayisini giriniz: ");																	printf("En cok oy alan aday ve aldigi oy sayisi: %d %d",j,max);
	scanf("%d",&n);																						}
	dizi=(int*) malloc(sizeof(int)*n);
	printf("Diziyi giriniz: ");																			Klavyeden girilen 8 kelime için sadece ilk kelimeden leksikografik olarak küçük olan kelimelerle bir cümle kuran program
	for(i=0;i<n;i++) {
		scanf("%d",&dizi[i]);																			int main() {
		toplam+=dizi[i];																					int i;
	}																										char string[8][20];
	double ort=(double)toplam/n;																			printf("8 tane kelime giriniz (her satýr baþýna bir kelime):");
	printf("Ortalamadan sapmasi 50 ve daha kucuk olan elemanlar: ");										for(i=0;i<8;i++)
	for(i=0;i<n;i++)																							gets(string[i]);
		if(dizi[i]<=ort+50 && ort-50<=dizi[i])																printf("Olusan cumle: ");
			printf("%d ",dizi[i]);																			for(i=1;i<8;i++)
}																												if(strcmp(string[i],string[0])<0)
																													printf("%s ",string[i]);
   Klavyeden sýrasýyla merkezlerinin xy koordinatlarý ve yarýçaplarý girilen 2 çemberin					}
   koordinat düzlemi üzerinde kesiþip kesiþmediðini yazdýran program

typedef struct {																						Klavyeden girilen string'deki sayýlarý ayýklayýp toplamýný yazdýrýp kalan string'i küçük harflerle yazdýran program
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

   Klavyeden girilen matrisin 180 derece kendi etrafýnda döndürülmüþ halini yazdýran program			Klavyeden girilen matristeki ilk tekrar eden elemanýn ilk kez tekrar ettiði index no'larýnýn toplamýný yazdýran program

void swap(int *a,int *b) {																				int main() {
	int gecici=*a;																							int i,j,k,l,m,n;
	*a=*b;																									printf("Matrisin boyutlarini giriniz: ");
	*b=gecici;																								scanf("%d%d",&m,&n);
}																											printf("Matrisi giriniz: ");
int main() {																								int **matrix=(int**) malloc(sizeof(int*)*m);
	int n,i,j;																								for(i=0;i<m;i++)
	printf("Matrisin buyuklugu: ");																				matrix[i]=(int*) malloc(sizeof(int)*n);		//matris[m][n] de yapýlabilirdi dinamik bellek tahsisi yerine
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

   Klavyeden girilen matriste index no'larýna göre elemanlar en baþtan itibaren sýrayla okunduðunda
   ilk defa tekrar ettiði görülen elemanýn index no'larýnýn toplamýný yazdýran program					Klavyeden girilen dizinin ayný elemanlarý arasýnda aralarýndaki mesafe minimum olanlarýnýn index no'larýný yazdýran program

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

   Klavyeden x ekseni üzerindeki konumlarý ve x eksenine göre hýzlarý girilen 2 kangurunun birim zamanda bir kere sýçradýklarý bilindiðine göre bu
   kangurularýn herhangi bir zaman diliminde ayný konumda bulunup bulunmayacaðýný "EVET" ve "HAYIR" döndüren bir fonksiyon yardýmýyla yazdýran program

char* kanguru(int x1,int v1,int x2,int v2) {															Bir çevre yolu üzerinde birbirinden eþit uzaklýkta, saat yönünde sýrayla 1'den n'e kadar numaralandýrýlmýþ n tane ev bulunmaktadýr.
	if(v1==0 && v2==0) {																				1 no'lu evde oturan kiþi m tane eve sýrayla ziyarete gidecektir. Trafik akýþý da tek saat yönünde ve ardýþýk iki ev arasý 1 saat
		if(x1==x2)																						olduðuna göre, tüm seferin toplam kaç saat tutacaðýný array kullanmadan yazdýran program
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
	return "HAYIR";																						n uzunluðundaki bir kurdele, a, b veya c uzunluklarýna sahip parçalara bölünecektir. Buna göre, bu kurdelenin a, b, c
}																										uzunluklarýndan herhangi birine sahip en fazla kaç parçaya bölünebileceðini yazdýran program
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

   Bir üniversite hocasý, klavyeden girilen öðrencilerin ders baþarý notlarýný öðrenci 40'ýn altýnda not alýp dersten kalmadýðý sürece alýnan not notun yuvarlanabileceði 5'in katýndan
   en fazla 2 puan eksikse notu 5'in en yakýn katýna yuvarlayýp öðrencilerin notlarýný yükselttiðine göre öðrencilerin nihai ders baþarý notlarýný yazdýran program

int main() {																							Klavyeden girilen sayýlarýn T-asalý (toplamda 3 tane pozitif tam sayý böleni olan doðal sayý) olup olmadýklarýný yazdýran program
	int i,n;
	printf("Not sayisini giriniz: ");																	int main() {	//asal sayýlarýn toplamda 2 tane pozitif tam sayý böleni (kendisi ve 1) varken T-asallarýnýn bir tane daha vardýr
	scanf("%d",&n);																							int n; long long a,b,i;		//bütün T-asallarý aslýnda asal sayýlarýn karelerinden ibarettir
	int *notlar=calloc(n,sizeof(int));																		printf("Kac tane sayi gireceginizi giriniz: ");
	printf("Notlari giriniz: ");																			scanf("%d",&n);				//yani asal sayýlar kümesinin tüm elemanlarýnýn karesi alýnarak T-asallarý kümesi elde edilir
	for(i=0;i<n;i++) {																						printf("Taranacak sayilar: ");
		scanf("%d",notlar+i);																				while(n--) {
		printf( i==0 ? "Son notlar: " : " ");																	scanf("%I64d",&a);
		*(notlar+i)= notlar[i]<40 || notlar[i]%5<3 ? notlar[i] : notlar[i]-(notlar[i]%5)+5;						b=sqrt(a);
		printf("%d",*(notlar+i));																				for(i=2;i*i<=b;i++) if(b%i==0) break;
	}																											printf(i*i>b && b*b==a && a>1 ? "%I64d bir T-asalidir.\n" : "%I64d bir T-asali degil.\n", a);
}																											}
																										}

   Klavyeden kenar uzunluklarý girilen dikdörtgenler arasýndan en küçük alana sahip dikdörtgenin alanýný yazdýran program

typedef struct {																						Klavyeden girilen 11'den büyük pozitif bir tam sayýyý, iki tane bileþik (asal olmayan) sayýnýn toplamý
	double a;																							olarak ifade eden bütün ikili kombinasyonlarý yazdýran program
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

   Bir parolanýn güçlü sayýlabilmesi için en az bir rakam, bir küçük harf, bir büyük harf ve bir özel karakter ("!@#$%^&*()-+") içermesi
   ve en az 6 karakter uzunluðunda olmasý gerektiðine göre, klavyeden girilen bir parolanýn güçlü olmasý için parolaya en az kaç karakter
   daha eklenmesi gerektiðini yazdýran program

int minimumNumber(unsigned int n, char* password) {														Klavyeden girilen bir sayýyý son ya da sondan bir önceki rakamýný silebilme kaydýyla maksimuma çýkaran program
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

   Klavyeden önce bir müzik türü seçilip sonra da klavyeden þarkýlarýn isimleri, söyleyen sanatçýlarý ve dahil olduðu müzik türleri girildiðine göre girilen þarkýlar arasýndan
   sadece seçilen müzik türüne dahil olanlarý listeyen Ýngilizce program

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
	}	//"%c" belirteci boþluk karakterini hafýzaya atmasýn diye "%s"den sonra bir boþluk býraktým
	printf("\nSelected songs:");
	for(i=0;i<number_of_songs;i++)
		if(s[i].genre==chosen_genre)
			printf("\n%s - %s",s[i].song_name,s[i].artist);
	return 0;
}

   5x5'lik bir haritada müþterilerin "a,b,c,d,e,f,g,h,i" harfleriyle, drone'un ise 'D' harfiyle gösterildiði ve drone'un herhangi bir dört yönde bir karakter ilerlediðinde yakýtýný 1
   tükettiði bilindiðine göre klavyeden girilen harita ve yakýt deðeri için drone'un hangi müþterilere ulaþabileceðini alfabetik olarak yazdýran program

int uzaklik(int i1,int j1,int i2,int j2) {
	return abs(i1-i2)+abs(j1-j2);		//uzaklýk=|x1-x2|+|y1-y2|
}
void bulucu(char harita[][5],char a,int *xi,int *xj) {
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(harita[i][j]==a) {
				*xi=i;		//girilen karakterin haritadaki koordinatlarýný bulur ve *xi ve *xj pointer'larýna atar
				*xj=j;
			}
}
int main() {
	char harita[5][5],must;
	int i,k=0,yakit,Dronei,Dronej,Musti,Mustj,uzak[9];	//Dronei ve Dronej: drone'un haritadaki koordinatlarý
	printf("Yakit: ");										//Musti ve Mustj: müþterinin haritadaki koordinatlarý
	scanf("%d",&yakit);						//uzak[9]: a,b,c,d,e,f,g,h,i müþterilerinin drone'a olan uzaklýklarý (drone'un bu müþterilere kaç hamle ile gelebileceði)
	for(i=0;i<5;i++)
		scanf(" %[^\n]%*c",harita[i]);
	bulucu(harita,'D',&Dronei,&Dronej);		//Dronei ve Dronej þuan drone'un koordinatlarýný tutuyor

	for(must='a';must<='i';must++) {
		bulucu(harita,must,&Musti,&Mustj);	//Musti ve Mustj þuan müþterinin koordinatlarýný tutuyor
		uzak[must-97]=uzaklik(Dronei,Dronej,Musti,Mustj);	//'a'=97   'a'-97=0
		if(uzak[must-97]<=yakit) {
			printf("%c ",must);		//eðer uzaklýk yakýtýn eriþebileceði menzil içerisindeyse müþteriyi yazdýr
			k++;
		}
	}
	printf(!k ? "\nMenzilde musteri yok" : "\nMenzilde %d musteri var",k);
	return 0;
}

   Klavyeden büyükten küçüðe diðer oyuncularýn skorlarý ve Alice'in bu oyunu tekrar tekrar oynadýðýnda kazandýðý skorlar girilen bir yarýþmada ayný skoru alan kiþiler
   ayný sýralamada yer aldýðýna göre Alice'in her oynadýðý sefer skor tablosunda kaçýncý olduðunu yazdýran Ýngilizce program

int main() {
	int i,n,m,score,top=0,leaderboard[1000]={0};
	printf("Enter number of players: ");
	scanf("%d",&n);
	printf("Enter the leaderboard scores in descending order: ");
	for(i=0;i<n;i++) {		//eðer skorlar farklý ise leaderboard array'ine sýrayla kaydet
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

   Klavyeden girilen cümleyi kelimelerinin baþ harfleri büyük olacak þekilde yazdýran program

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

   l metre uzunluðundaki düz bir sokakta n tane özdeþ sokak lambasý, sokaðýn baþlangýcý 0, sonu l olmak üzere 0-l arasýndaki pozisyonlarda bulunmaktadýr.
   Sokak lambalarýnýn sayýsý, sokaðýn uzunluðu ve sokak lambalarýnýn pozisyonlarý sýrayla klavyeden girileceðine göre, bütün sokaðýn aydýnlatabilmesi
   için sokak lambalarýnýn sokaðý aydýnlatma yarýçapýnýn minimum kaç metre olmasý gerektiðini yazdýran program

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
		for(j=1;j<n-i;j++)		//1 ila n. index'lerdeki elemanlar, yani sokak lambalarýnýn pozisyonlarý bubble sort ile küçükten büyüðe sýralanýyor
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

   Bir MMORPG oyununda belli miktarda bir güç puaný toplamýþ pro gamer Kirita, oyunun son seviyesinde ejderlerle dövüþmektedir ve dövüþün galibi daha
   fazla güç puanýna sahip olan taraf olmaktadýr. Her öldürdüðü ejder için bonus güç alan Kirita ejderlerle istediði sýrada dövüþebileceðine göre,
   Kirita'nýn bütün ejderleri öldürüp oyunu kazanýp kazanamayacaðýný yazdýran Ýngilizce program */

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
