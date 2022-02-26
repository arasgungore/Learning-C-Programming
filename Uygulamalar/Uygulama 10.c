#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Klavyeden girilen a ve b tam sayýlarý arasýnda kaç tane tam kare sayý bulunduðunu yazdýran program

int main() {
	int a,b;
	printf("Iki sayi giriniz: ");
	scanf("%d%d",&a,&b);	//sqrt,floor,ceil fonksiyonlarýnýn hepsi double döndürüyor, explicit casting ile double int'e dönüþtürülüyor
	printf("%d ile %d arasindaki tam karelerin sayisi: %d",a,b,(int)(floor(sqrt(b))-ceil(sqrt(a))+1));
}

   0'dan 9'a kadar olan rakamlarýn yazýlý olduðu rakamlar.txt belgesini fgets ile okuyan ve bu rakamlarý bir int array'inin elemanlarýna atayýp konsola yazdýran program

int main() {
	FILE *textfile=fopen("..\\falan filan\\rakamlar.txt","r");
	char text[10];				//".\": bu dosyanýn ("Uygulama 10.c") bulunduðu directory ==> "C:\Users\Aras Güngöre\Desktop\C-ikiþ\Uygulamalar\"
	fgets(text,11,textfile);	//"..\": bu dosyanýn bulunduðu directory'nin bir üstündeki directory	"C:\Users\Aras Güngöre\Desktop\C-ikiþ\"
	fclose(textfile);
	int i=0,array[10];
	for(i=0;i<10;i++) {
		array[i]=(int)(text[i]-'0');
		printf("%d",array[i]);
	}
	exit(0);
}

   Klavyeden girilen sayý-karakter ikilisine göre yýlbaþý aðacý çizdiren program					Klavyeden girilen boyuta göre 2'lerden oluþan italik bir M harfi çizdiren program

int main() {																						int main() {
	char ch;																							int satir,i,j;
	int N,i,j,k,sayac;																					printf("M'in boyutunu giriniz: ");
	printf("Girdi (sayi-karakter): ");																	scanf("%d",&satir);
	scanf("%d%c",&N,&ch);																				for(i=0;i<satir;i++) {
	printf("\n");																							printf("222");
	for(i=1;i<=N;i++) {																						for(j=3;j<i;j++)
		sayac= i-2>0 ? i-2 : 0;																					printf("-");
		for(j=1;j<=i;j++) {																					printf( i>2 ? "222" : (i==2 ? "22" : (i==1 ? "2" : "")));
			for(k=0;k<2*N-j-sayac;k++)																		for(j=0;j<satir-3-i;j++)
				printf(" ");																					printf("-");
			for(k=0;k<j+sayac;k++)																			printf( i<satir-2 ? "222" : (i==satir-2 ? "22" : "2"));
				printf("/");																				for(j=3;j<i;j++)
			printf("%c",ch);																					printf("-");
			for(k=0;k<j+sayac;k++)																			printf( i>2 ? "222" : (i==2 ? "22" : (i==1 ? "2" : "")));
				printf("\\");																				printf("\n");
			printf("\n");																				}
		}																							}
	}
	for(i=0;i<3*N/4;i++) {																			Klavyeden girilen n sayfalý bir kitapta p numaralý sayfaya ulaþmak için kitabýn baþýndan ya da
		for(j=0;j<3*N/2+1;j++)																		sonundan baþlayarak kaç defa sayfa çevrilmesi gerektiðini yazdýran program
			printf(" ");
		for(j=0;N%2==1 ? j<N : j<N-1;j++)															int main() {
			printf("%c",ch);																			int n,p;
		printf("\n");																					printf("Kitabin sayfa sayisini ve aranan sayfayi giriniz: ");
	}																									scanf("%d%d",&n,&p);
	printf("\n\nMutlu yillar!!!");																		printf("Cevrilmesi gereken sayfa sayisi: %d", (n-p)<(n+1)/2 ? n/2-p/2 : p/2 );
	return 0;																						}
}

   Klavyeden girilen tek sayý-karakter ikilisine göre Totoro resmi çizdiren program					Klavyeden girilen basamak sayýsýna ve rakamlar toplamýna sahip, maksimum 100 basamaklý en küçük
																									ve en büyük pozitif tam sayýyý diziler yardýmýyla yazdýran program
int main() {
	int i,j,n; char k;																				int main() {
	printf("Girdi (sayi-karakter): ");																	int max[101]={0}, min[101]={1}, length,sum,i,n;		//min=100000...0000, max=000000...0000
	scanf("%d %c",&n,&k);																				printf("Basamak sayisi ve rakamlar toplamini giriniz: ");
	printf("\n");																						scanf("%d%d",&length,&sum);
	for(i=0;i<n;i++) {																					if((sum==0 && length!=1) || sum>9*length)
		for(j=0;j<n-i;j++)																					printf("Imkansiz olay");
			printf(" ");																				else {
		if(i==0) {																							for(n=sum,i=0; n>9; i++,n-=9)
			printf("/\\");																						max[i]=9;		//max=9999...999000...0000
			for(j=0;j<n;j++)																				max[i]=n;
				printf("_");																				for(n=sum,i=length-1; n>9; i--,n-=9)
			printf("/\\\n");																					min[i]=9;		//min=1000...000999...9999
			continue;																						min[i]+=n-1;
		}																									printf("En kucuk sayi: ");
		printf("/");																						for(i=0;i<length;i++)
		for(j=0;j<n+2*i+2;j++) {																				printf("%d",min[i]);
			if(i==n/2+1) {																					printf("\nEn buyuk sayi: ");
				if(j==n/2+1 || j==3*n/2+2) {																for(i=0;i<length;i++)
					printf("%c",k);																				printf("%d",max[i]);
					continue;																			}
				}																						return 0;
				else if(j==n+1) {																	}
					printf(".");
					continue;																		Klavyeden girilen n büyüklüðündeki iki dizi istedikleri elemanlar arasýnda k defa swap yapma hakkýna sahiptir.
				}																					Buna göre, 1. dizinin elemanlarý toplamýnýn bu swap'lardan sonra maksimum kaç olabileceðini yazdýran program
			}
			printf(" ");																			int main() {
		}																								int t;
		printf("\\\n");																					printf("Test senaryosu sayisini giriniz: ");
	}																									scanf("%d",&t);
	for(i=n;i>0;i--) {																					while(t--) {
		for(j=0;j<n-i;j++)																					int i,n,k,a_sum=0;
			printf(" ");																					printf("Dizilerin uzunlugunu ve swap hakkini giriniz: ");
		printf(i!=n ? "\\" : "(");																			scanf("%d%d",&n,&k);
		for(j=0;j<n+2*i+2;j++)																				int *a=(int*) malloc(n*sizeof(int)), *b=(int*) malloc(n*sizeof(int));
			printf(i!=1 ? " " : "_");																		printf("Birinci diziyi giriniz: ");
		printf(i!=n ? "/\n" : ")\n");																		for(i=0;i<n;i++)
	}																											scanf("%d",&a[i]);
	return 0;																								printf("Ikinci diziyi giriniz: ");
}																											for(i=0;i<n;i++)
																												scanf("%d",&b[i]);
   Ýlk satýr ve sütunu 1 deðerlerinden oluþan N*N'lik bir matriste kalan satýr ve sütunlardaki				while(k--) {
   deðerler daima bir solundaki ve bir yukarýsýndaki iki deðerin toplamý olduðuna göre, klavyeden				int min_a=a[0],max_b=b[0],a_i=0,b_i=0;
   girilen N deðeri için bu matrisi ve bu matristeki en büyük deðeri yazdýran program							for(i=1;i<n;i++) {
																													if(a[i]<min_a) {
int main() {																											min_a=a[i];		//birinci dizideki en küçük sayýyý bul
	int N;																												a_i=i;
	printf("Matrisin buyuklugunu giriniz: ");																		}
	scanf("%d",&N);																									if(b[i]>max_b) {	//ikinci dizideki en büyük sayýyý bul
	int matrix[N][N],i,j,k=0,l=1;																						max_b=b[i];
	for(i=0;i<N;i++)																									b_i=i;
		matrix[0][i]=matrix[i][0]=1;																				}
	while(1) {																									}
		if(k<N-1)		k++;																					if(min_a<max_b) {
		else if(l<N-1)	l++;																						int temp=a[a_i];	//swap yap
		else			break;																						a[a_i]=b[b_i];
		for(j=l,i=k; 0<i && j<N; i--,j++)																			b[b_i]=temp;
			matrix[i][j]=matrix[i-1][j]+matrix[i][j-1];															}
	}																											else					//eðer swap yapmaya gerek yoksa, döngüden çýk
	printf("\n\n");																									break;
	for(i=0;i<N;i++) {																						}
		for(j=0;j<N;j++)																					for(i=0;i<n;i++)
			printf("%d\t",matrix[i][j]);																		a_sum+=a[i];
		printf("\n");																						printf("Birinci dizinin elemanlari toplaminin max degeri: %d\n",a_sum);
	}																									}
	printf("\nMaksimum sayi: %d",matrix[N-1][N-1]);													}
}

   Bir PDF'te Ýngiliz alfabesindeki harflerin boylarýnýn kaç birim sayýlacaðý klavyeden girildiðine ve bütün harflerin tabanlarý 1 birim sayýldýðýna
   göre klavyeden girilen en fazla 1000 harfli bir kelimenin bu PDF içerisinde highlight edildiðinde kaç birimkare alan kaplayacaðýný yazdýran program

int main() {																						Cüzdanýnda sonsuz sayýda 10 kuruþluk ve bir tane de x kuruþluk bozukluðu olan bir müþteri belli sayýda kürek alacaktýr.
	char kelime[1000];																				Küreklerin kuruþ cinsinden fiyatý ve ekstra bozukluðun x deðeri klavyeden girileceðine göre, bu müþterinin para üstü
	int i,j,alfabe[26],max=1;																		almadan alabileceði en az kürek sayýsýný yazdýran program
	printf("Alfabedeki harflere degerler atayin: ");
	for(i=0;i<26;i++)																				int main() {
		scanf("%d",&alfabe[i]);																			int fiyat,bozukluk,kurek_sayisi;
	printf("Kelimeyi yazin: ");																			printf("Kuregin fiyatini ve eldeki ekstra bozuklugun degerini giriniz: ");
	scanf("%s",kelime);																					scanf("%d%d",&fiyat,&bozukluk);
	for(i=0;i<strlen(kelime);i++)																		for(kurek_sayisi=1; (kurek_sayisi*(fiyat%10))%10!=bozukluk && (i*fiyat)%10!=0; kurek_sayisi++);
		for(j=0;j<26;j++)																				printf("Para ustu almadan alinabilecek minimum kurek sayisi: %d",kurek_sayisi);
			if(kelime[i]==j+97) {																	}
				if(alfabe[j]>max)
					max=alfabe[j];
				else
					break;
			}
	int alan=max*strlen(kelime);
	printf("Girilen kelimenin alani: %d",alan);
}

   Klavyeden "hh:mm:dd AM" veya "hh:mm:dd PM" formatýnda string olarak girilen zamaný AM ve PM'i dikkate alarak standart dijital saat gösterimine uygun bir þekilde döndüren program

int main() {
	char gosterim[12];
	printf("Saati giriniz (hh:mm:dd[AM/PM]): ");
	gets(gosterim);
	int saat=atoi(gosterim);	//gosterim adlý string'i atoi fonksiyonu ile int'e çevirip saat adlý deðiþkene atadým
	saat+= strstr(gosterim,"PM") ? (saat>=12 ? 0 : 12) : (saat>=12 ? -12 : 0);
	printf("Gercek zaman: %02d:%.2s:%.2s",saat,gosterim+3,gosterim+6);
	return 0;	//a="string" ise a+1="tring", a+2="ring", a+3="ing", a+4="ng", a+5="g" oluyor
}

   Klavyeden newline yapýlana kadar girdi alan, küçükten büyüðe sýralý sayýlarýn olduðu bir dizi ve bu dizide aranacak, klavyeden girilen bir eleman için
   aranan eleman dizide bulunup bulunmadýðýný, bulunuyorsa da hangi index'te bulunduðunu "binary search" algoritmasýyla bulup yazdýran program

int binarySearch(int *dizi, int arka, int on, int x) {	//"binary search" brute force'a kayan linear search'e göre çok daha hýzlý ve verimlidir
	if(on>=arka) {
		int orta=(arka+on)/2;		//kabaca þöyle çalýþýyor: dizinin ortasýndaki elemandan (medyan) büyükse elemaný üst yarýda, deðilse alt yarýda arýyor
        if(dizi[orta]==x)			//daha sonra atýyorum aradýðým eleman üst yarýda ise bu yarýnýn medyanýndan (üst çeyrek) büyükse elemaný üst çeyrekte, deðilse alt çeyrekte arýyor
			return orta;			//böyle böyle ta ki eleman bulunana kadar diziyi yarýlaya yarýlaya gidiyor ve elemanýn zaten matematiksel olarak bulunmayacaðý gereksiz alt dizileri program taramamýþ oluyor ;)
		if(dizi[orta]>x)
			return binarySearch(dizi, arka, orta-1, x);
		return binarySearch(dizi, orta+1, on, x);													x ekseninde sýrayla x1, x2 ve x3 koordinatlarýnda bulunan 3 arkadaþ bir yýlbaþý partisi için ortak bir noktada buluþacaktýr.
	}																								Buna göre, bu arkadaþlarýn total benzin bakýmýndan en ekonomik yýlbaþý partisini düzenlemeleri için toplamda minimum
	return -1;																						ne kadar mesafe katetmeleri gerektiðini yazdýran program
}
int main() {																						int main() {
	int *dizi=calloc(1000,sizeof(int)),aranan,n=0;														double x1,x2,x3;
	char ayrac;																							printf("Sirayla bu 3 arkadasin lokasyonlarini giriniz: ");
	printf("Diziyi giriniz: ");																			scanf("%lf%lf%lf",&x1,&x2,&x3);
	while(ayrac!='\n')																					double min = x1>x2 ? (x2>x3 ? x3 : x2) : (x1>x3 ? x3 : x1);
		scanf("%d%c",&dizi[n++],&ayrac);																double max = x1>x2 ? (x1>x3 ? x1 : x3) : (x2>x3 ? x2 : x3);
	realloc(dizi,sizeof(int)*n);																		printf("Minimum gidilmesi gereken yol: %lf",max-min);
	printf("Aranacak elemani giriniz: ");															}						//alternatif olarak "(fabs(x1-x2)+fabs(x1-x3)+fabs(x2-x3))/3.0" da ayný sonucu verir
	scanf("%d",&aranan);
	int sonuc=binarySearch(dizi, 0, n-1, aranan);
	sonuc==-1 ? printf("Eleman dizide yok") : printf("Eleman %d no'lu index'te",sonuc);
	return 0;
}

   unsigned long long veri tipi bile 20'den büyük sayýlarýn faktöriyelini hafýzada overflow olmadan tutamadýðýna göre, 20'den büyük sayýlarýn faktöriyelini dizi yardýmýyla yazdýran program

int main() {
	int sayi,sayi_uzunlugu=1,i,j;
	short sonuc[10000]={0};
	sonuc[0]=1;			//sonuc[10000]={1,0,0,0,...9994 tane daha 0 sonra...,0,0}
	printf("Faktoriyeli alinacak sayiyi giriniz: ");
	scanf("%d",&sayi);
	for(i=2;i<=sayi;i++) {
		int tasi=0;
		for(j=0;j<sayi_uzunlugu;j++) {
			int carpim=i*sonuc[j]+tasi;		//mesela 120*6=720 ara iþlemi için sonuc dizisi 120 (5!=120) sayýsýný {0,2,1} olarak tutuyor
			short rakam=carpim%10;			//6*0=0 için tasi=0, ama 6*2=12 için tasi=1 olduðundan son (aslýnda formal yazýlýþýna göre en baþtaki) basamak 6*1+1(tasi)=7 oluyor
			sonuc[j]=rakam;					//böylelikle de yeni sonuc dizim {0,2,7} oluyor
			tasi=carpim/10;			//720*7=5040 için ise sonuc dizisi {0,2,7}; 0*7=0, tasi=0; 2*7=14, tasi=1; 7*7+1(tasi)=50
		}							//bu iþlemlerde daima carpim'ýn mod 10'daki deðerleri dizide saklanýldýðý için sonuc dizim þimdilik {0,4,0} oluyor
		while(tasi) {	//tasi=0 ise çalýþmaz, tasi!=0 iken çalýþýr
			sayi_uzunlugu++;
			short rakam=tasi%10;
			sonuc[sayi_uzunlugu-1]=rakam;	//burada mesela 720*7=5040 ara iþlemindeki 5'i de yazdýrabiliyorum ve sonuc dizim {0,4,0,5} oluyor
			tasi/=10;
		}
	}
	printf("%d!=",sayi);
	for(i=sayi_uzunlugu-1;i>=0;i--)
		printf("%hi",sonuc[i]);	//diziyi tersten yazdýrýr, bir de short belirtecim "%hi"
	return 0;
}

   Klavyeden girilen a ve b tam sayý dizileri için a'nýn bütün elemanlarýna tam bölünen ve b'nin bütün elemanlarýný tam bölen toplamda kaç tane tam sayý olduðunu yazdýran program

int main() {																						Taranan index katarýn uzunluðunu geçiyorsa taranan index numarasý baþa sardýðýna göre, klavyeden girilen bir katarda
	int i,j,a_boyutu,b_boyutu,sayac1=0,sayac2=0;													klavyeden girilen bir karakterin ilk n index'te kaç defa tekrar ettiðini yazdýran program
	printf("a ve b dizilerinin boyutlarini giriniz: ");
	scanf("%d%d",&a_boyutu,&b_boyutu);																int main() {
																										unsigned int i,n,sayac1=0,sayac2=0;
	int *a=calloc(a_boyutu,sizeof(int)),*b=calloc(a_boyutu,sizeof(int));								char s[1000],k;
	printf("a dizisini giriniz: ");																		printf("Katari giriniz: ");
	for(i=0;i<a_boyutu;i++)																				gets(s);
		scanf("%d",&a[i]);																				printf("Aranacak karakteri giriniz: ");
	printf("b dizisini giriniz: ");																		k=getchar();
	for(i=0;i<b_boyutu;i++)																				printf("n degerini giriniz: ");
		scanf("%d",&b[i]);																				scanf("%d",&n);
																										for(i=0;i<strlen(s);i++)
	int max_a=a[0],min_b=b[0];																				if(s[i]==k)
	for(i=1;i<a_boyutu;i++)																						sayac1++;
		if(a[i]>max_a)																					for(i=0;i<n%strlen(s);i++)
			max_a=a[i];																						if(s[i]==k)
	for(i=1;i<b_boyutu;i++)																						sayac2++;
		if(b[i]<min_b)																					printf("Tekrar sayisi: %u",(unsigned int)(sayac1*(n/strlen(s))+sayac2));
			min_b=b[i];																				}

	for(i=max_a;i<=min_b;i++) {																		Klavyeden girilen bir pozitif tam sayýyý olabildiðince fazla asal sayýnýn toplamý olarak yazdýran program
		for(j=0;j<a_boyutu;j++)
			if(i%a[j]==0)																			int main() {
				sayac1++;																				int sayi;
		for(j=0;j<b_boyutu;j++)																			printf("1'den buyuk pozitif bir tam sayi giriniz: ");
			if(b[j]%i==0)																				scanf("%d",&sayi);
				sayac1++;																				printf("\n\n%d'in asal toplayan sayisi: %d\n\n%d = ",sayi,sayi/2,sayi);
		if(sayac1==a_boyutu+b_boyutu)																	for(;sayi>3;sayi-=2)
			sayac2++;																						printf("2 + ");
		sayac1=0;																						printf("%d",sayi);
	}																								}

	printf("a dizisinin elemanlarina tam bolunup b dizisinin elemanlarini tam bolen sayilarin sayisi: %d",sayac2);
	return 0;
}

   Bir sayý ile o sayýnýn tersten yazýlmýþý arasýndaki mutlak fark k'ye tam bölünüyorsa o sayýya k'ye göre güzel sayý adý verildiðine göre, klavyeden
   sýrayla girilen i, j, k deðerleri için i ve j arasýndaki sayýlardan kaç tanesinin k'ye göre güzel sayý olduðunu fonksiyon çaðýrarak yazdýran program

int GuzelSayilar(int i,int j,int k) {
	char tersten[50],gecici;
	int i1,j1,I1,I2,sayac=0;
	for(I1=i;I1<=j;I1++) {
		sprintf(tersten,"%d",I1);	//sayý string'e çevrildi
		i1=0,j1=strlen(tersten)-1;
		while(i1<j1) {
			gecici=tersten[i1];
			tersten[i1]=tersten[j1];
			tersten[j1]=gecici;
			i1++,j1--;	//swap & reverse
		}
		I2=atoi(tersten);	//string tekrar sayýya çevrildi
		if(abs(I1-I2)%k==0)
			sayac++;
	}
	return sayac;
}
int main() {
	int i,j,k;
	printf("Araligi ve bolunecegi sayiyi giriniz: ");
	scanf("%d%d%d",&i,&j,&k);
	printf("Guzel sayilar: %d",GuzelSayilar(i,j,k));
	return 0;
}

   M*N'lik bir matristeki bütün elemanlar matris içinde 1 defa saat yönünde döndürüldüðünde oluþan matrisi yazdýran program

int i,j;																							Klavyeden girilen M*N'lik bir matristeki bütün elemanlar klavyeden girilen L sayýsý kadar sola kaydýrýldýðýnda oluþan matrisi yazdýran program
void matrisi_dondur(int M,int N,int matrix[M][N]) {
	int row=0,col=0,prev,i,orijinalM=M,orijinalN=N;													int i,j;
	while(row<M && col<N) {																			void L_sola_kaydir(int M,int N,int matrix[M][N],int L) {
		if(row+1==M || col+1==N)																		int yeni_matrix[M][N];
			break;																						for(i=0;i<M;i++)
		prev=matrix[row+1][col];																			for(j=0;j<N;j++)
		for(i=col;i<N;i++)																						if(j+L%N>=N)
			swap(&prev,&matrix[row][i]);																			yeni_matrix[i][j]=matrix[(i+L/N+1)%M][(j+L%N)%N];
		row++;																									else
		for(i=row;i<M;i++)																							yeni_matrix[i][j]=matrix[(i+L/N)%M][j+L%N];
			swap(&prev,&matrix[i][N-1]);																matrisi_yazdir(M, N, yeni_matrix);
		N--;																						}
		if(row<M)																					void matrisi_doldur(int M,int N,int matrix[M][N]) {
			for(i=N-1;i>=col;i--)																		for(i=0;i<M;i++)
				swap(&prev,&matrix[M-1][i]);																for(j=0;j<N;j++)
		M--;																									scanf("%d",&matrix[i][j]);
		if(col<N)																					}
			for(i=M-1;i>=row;i--)																	void matrisi_yazdir(int M,int N,int matrix[M][N]) {
				swap(&prev,&matrix[i][col]);															for(i=0;i<M;i++) {
		col++;																								for(j=0;j<N;j++)
	}																											printf("%d  ",matrix[i][j]);
	matrisi_yazdir(orijinalM, orijinalN, matrix);															printf("\n");
}																										}
void matrisi_yazdir(int M,int N,int matrix[M][N]) {													}
	for(i=0;i<M;i++) {																				int main() {
		for(j=0;j<N;j++)																				int M,N,L;
			printf("%d  ",matrix[i][j]);																printf("Matrisin boyutlarini giriniz: ");
		printf("\n");																					scanf("%d%d",&M,&N);
	}																									int matris[M][N];
}																										printf("Matrisi giriniz: ");
void swap(int *a,int *b) {																				matrisi_doldur(M, N, matris);
	int gecici=*a;																						printf("Elemanlarin kac sola kayacagini giriniz: ");
	*a=*b;																								scanf("%d",&L);
	*b=gecici;																							L=L%(M*N);
}																										printf("\nOrijinal matris:\n");
int main() {																							matrisi_yazdir(M, N, matris);
	int a[3][3]={ {1, 2, 3},																			printf("\nYeni matris:\n");
				  {4, 5, 6},																			L_sola_kaydir(M, N, matris, L);
				  {7, 8, 9} };																			exit(0);
	printf("Orijinal matris 1:\n");																	}
	matrisi_yazdir(3, 3, a);
	printf("\n\nYeni matris 1:\n");
	matrisi_dondur(3, 3, a);
	int b[4][4]={ {1, 2, 3, 4},
				  {5, 6, 7, 8},
				  {9, 10, 11, 12},
				  {13, 14, 15, 16} };
	printf("\n\nOrijinal matris 2:\n");
	matrisi_yazdir(4, 4, b);
	printf("\n\nYeni matris 2:\n");
	matrisi_dondur(4, 4, b);
	exit(0);
}

   Klavyeden girilen 1. katarýn 2. katara toplamda n tane yapýlmak üzere sil ya da ekle (append and delete) iþlemleriyle
   dönüþtürülüp dönüþtürülemeyeceðini "Evet" ya da "Hayýr" döndüren bir fonksiyon yardýmýyla cevaplayan program

char* Sil_ve_Ekle(char* s, char* t, unsigned int k) {
	int i,ortak_uzunluk=0,min= strlen(s)<strlen(t) ? strlen(s) : strlen(t);
	for(i=0;i<min;i++) {
		if(s[i]==t[i])
			ortak_uzunluk++;
		else
			break;
	}
	if(strlen(s)+strlen(t)-2*ortak_uzunluk>k)
		return "Hayir";
	else if((strlen(s)+strlen(t)-2*ortak_uzunluk)%2==k%2)	//demek ki: (strlen(s)+strlen(t)-2*ortak_uzunluk)<=k
		return "Evet";			//bütün hamlelerin kullanýlmasý gerek, ondan ötürü
	else if(strlen(s)+strlen(t)<k)			//sonuçta 1. katar komple silinip baþtan yazýlarak 2. katara dönüþtürülebilir
		return "Evet";				//ve arada da bazý silme iþlemleri boþ (NULL) katarý silmeye çalýþacaðýndan boþa harcanabilir, üstteki koþula istisnaden
	else
		return "Hayir";
}
int main() {
	char a[1000],b[1000];
	unsigned int n;
	gets(a);
	gets(b);
	scanf("%d",&n);
	printf("\"%s\" katari \"%s\" katarina %d hamlede donusturulebilir mi?: %s",a,b,n,Sil_ve_Ekle(a,b,n));
}

   Bir matematik soru bankasýnda n tane bölüm, bu bölümlerde de farklý sayýlarda problem bulunmaktadýr. Bu kitap, sayfa baþýna en fazla k tane problem düþecek þekilde
   yazýldýðýna ve sayfa, bölüm ve problem no'larý 1'den baþlayarak artan sýrada numaralandýrýldýðýna göre, klavyeden bölüm sayýsý, bölümlerdeki problem sayýlarýný sýrayla
   içeren bir dizi ve sayfa baþýna düþen problem sýnýrý girilen ve bu girdilere göre kitapta problem no'su bulunduðu sayfa no'suna eþit olan kaç tane problem olduðunu yazdýran program

int main() {																						Karþýlýklý yinelemeyle (mutual recursion) klavyeden girilen bir sayýnýn tek mi çift mi olduðunu yazdýran program
	int n,k,i,j,ozel=0,sayfa=1;
	printf("Chapter sayisini ve problem limitini giriniz: ");										bool cift_mi(unsigned int n);
	scanf("%d%d",&n,&k);																			bool tek_mi(unsigned int n);
	int *chapter=calloc(n,sizeof(int));
	printf("Chapter'lardaki problem sayilarini giriniz: ");											bool cift_mi(unsigned int n) {	return n==0 ? true : tek_mi(n-1);	}
	for(i=0;i<n;i++)																				bool tek_mi(unsigned int n) {	return n==0 ? false : cift_mi(n-1);	}
		scanf("%d",&chapter[i]);
	for(i=0;i<n;i++) {																				int main() {
		for(j=1;j<=chapter[i];j++) {																	int sayi;
			if(j==sayfa)																				for(sayi=-100;sayi<=100;sayi++)
				ozel++;																						printf(cift_mi(abs(sayi)) ? "%d cifttir.\n" : "%d tektir.\n", sayi);
			if(j%k==0)																					printf("\n\nBir sayi giriniz: ");
				sayfa++;																				scanf("%d",&sayi);
		}																								printf(tek_mi(abs(sayi)) ? "Bu sayi tektir." : "Bu sayi cifttir.");
		if(arr[i]%k!=0)																					return 0;
			sayfa++;																				}
	}
	printf("Ozel soru sayisi: %d",ozel);
}

   n tane oyuncunun yarýþtýðý bir programlama yarýþmasýnda m tane konu baþlýðý altýnda oyunlar yapýlacaktýr. Oyuncularýn bu konu baþlýklarýndaki oyunlardan aldýðý skorlar sýrayla
   1 ve 0'lardan oluþan string'ler biçiminde girildiðine göre bu oyunculardan ikili takýmlar oluþturulduðunda oluþturulabilecek takýmlardan kaçýnýn birinci olacaðýný yazdýran program */

int main() {
	int n,m,i;
	printf("Sirayla oyuncu ve konu basligi sayisini giriniz: ");
	scanf("%d%d",&n,&m);
	char *topic[n];
	for(i=0;i<n;i++) {
		topic[i]=(char*) calloc(200,sizeof(char));
		printf("%d. oyuncunun skor tablosunu giriniz: ",i+1);
		scanf("%s",topic[i]);
		topic[i]=(char*) realloc(topic[i],strlen(topic[i])+1);
	}
	int known,max_known=0,know_all=0,j,k;
	for(i=0;i<n-1;i++) {
		for(j=i+1;j<n;j++) {
			known=0;
			for(k=0;k<m;k++) {
				if(topic[i][k]=='1' || topic[j][k]=='1')
					known++;
				if(max_known<known) {
					max_known=known;
					know_all=0;
				}
				if(known==max_known)
					know_all++;
			}
		}
	}
	printf("Birinci takimin kazandigi oyun sayisi: %d\nBirinci olan takim sayisi: %d",max_known,know_all);
	return 0;
}
