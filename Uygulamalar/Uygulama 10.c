#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Klavyeden girilen a ve b tam say�lar� aras�nda ka� tane tam kare say� bulundu�unu yazd�ran program

int main() {
	int a,b;
	printf("Iki sayi giriniz: ");
	scanf("%d%d",&a,&b);	//sqrt,floor,ceil fonksiyonlar�n�n hepsi double d�nd�r�yor, explicit casting ile double int'e d�n��t�r�l�yor
	printf("%d ile %d arasindaki tam karelerin sayisi: %d",a,b,(int)(floor(sqrt(b))-ceil(sqrt(a))+1));
}

   0'dan 9'a kadar olan rakamlar�n yaz�l� oldu�u rakamlar.txt belgesini fgets ile okuyan ve bu rakamlar� bir int array'inin elemanlar�na atay�p konsola yazd�ran program

int main() {
	FILE *textfile=fopen("..\\falan filan\\rakamlar.txt","r");
	char text[10];				//".\": bu dosyan�n ("Uygulama 10.c") bulundu�u directory ==> "C:\Users\Aras G�ng�re\Desktop\C-iki�\Uygulamalar\"
	fgets(text,11,textfile);	//"..\": bu dosyan�n bulundu�u directory'nin bir �st�ndeki directory	"C:\Users\Aras G�ng�re\Desktop\C-iki�\"
	fclose(textfile);
	int i=0,array[10];
	for(i=0;i<10;i++) {
		array[i]=(int)(text[i]-'0');
		printf("%d",array[i]);
	}
	exit(0);
}

   Klavyeden girilen say�-karakter ikilisine g�re y�lba�� a�ac� �izdiren program					Klavyeden girilen boyuta g�re 2'lerden olu�an italik bir M harfi �izdiren program

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
	for(i=0;i<3*N/4;i++) {																			Klavyeden girilen n sayfal� bir kitapta p numaral� sayfaya ula�mak i�in kitab�n ba��ndan ya da
		for(j=0;j<3*N/2+1;j++)																		sonundan ba�layarak ka� defa sayfa �evrilmesi gerekti�ini yazd�ran program
			printf(" ");
		for(j=0;N%2==1 ? j<N : j<N-1;j++)															int main() {
			printf("%c",ch);																			int n,p;
		printf("\n");																					printf("Kitabin sayfa sayisini ve aranan sayfayi giriniz: ");
	}																									scanf("%d%d",&n,&p);
	printf("\n\nMutlu yillar!!!");																		printf("Cevrilmesi gereken sayfa sayisi: %d", (n-p)<(n+1)/2 ? n/2-p/2 : p/2 );
	return 0;																						}
}

   Klavyeden girilen tek say�-karakter ikilisine g�re Totoro resmi �izdiren program					Klavyeden girilen basamak say�s�na ve rakamlar toplam�na sahip, maksimum 100 basamakl� en k���k
																									ve en b�y�k pozitif tam say�y� diziler yard�m�yla yazd�ran program
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
					continue;																		Klavyeden girilen n b�y�kl���ndeki iki dizi istedikleri elemanlar aras�nda k defa swap yapma hakk�na sahiptir.
				}																					Buna g�re, 1. dizinin elemanlar� toplam�n�n bu swap'lardan sonra maksimum ka� olabilece�ini yazd�ran program
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
   �lk sat�r ve s�tunu 1 de�erlerinden olu�an N*N'lik bir matriste kalan sat�r ve s�tunlardaki				while(k--) {
   de�erler daima bir solundaki ve bir yukar�s�ndaki iki de�erin toplam� oldu�una g�re, klavyeden				int min_a=a[0],max_b=b[0],a_i=0,b_i=0;
   girilen N de�eri i�in bu matrisi ve bu matristeki en b�y�k de�eri yazd�ran program							for(i=1;i<n;i++) {
																													if(a[i]<min_a) {
int main() {																											min_a=a[i];		//birinci dizideki en k���k say�y� bul
	int N;																												a_i=i;
	printf("Matrisin buyuklugunu giriniz: ");																		}
	scanf("%d",&N);																									if(b[i]>max_b) {	//ikinci dizideki en b�y�k say�y� bul
	int matrix[N][N],i,j,k=0,l=1;																						max_b=b[i];
	for(i=0;i<N;i++)																									b_i=i;
		matrix[0][i]=matrix[i][0]=1;																				}
	while(1) {																									}
		if(k<N-1)		k++;																					if(min_a<max_b) {
		else if(l<N-1)	l++;																						int temp=a[a_i];	//swap yap
		else			break;																						a[a_i]=b[b_i];
		for(j=l,i=k; 0<i && j<N; i--,j++)																			b[b_i]=temp;
			matrix[i][j]=matrix[i-1][j]+matrix[i][j-1];															}
	}																											else					//e�er swap yapmaya gerek yoksa, d�ng�den ��k
	printf("\n\n");																									break;
	for(i=0;i<N;i++) {																						}
		for(j=0;j<N;j++)																					for(i=0;i<n;i++)
			printf("%d\t",matrix[i][j]);																		a_sum+=a[i];
		printf("\n");																						printf("Birinci dizinin elemanlari toplaminin max degeri: %d\n",a_sum);
	}																									}
	printf("\nMaksimum sayi: %d",matrix[N-1][N-1]);													}
}

   Bir PDF'te �ngiliz alfabesindeki harflerin boylar�n�n ka� birim say�laca�� klavyeden girildi�ine ve b�t�n harflerin tabanlar� 1 birim say�ld���na
   g�re klavyeden girilen en fazla 1000 harfli bir kelimenin bu PDF i�erisinde highlight edildi�inde ka� birimkare alan kaplayaca��n� yazd�ran program

int main() {																						C�zdan�nda sonsuz say�da 10 kuru�luk ve bir tane de x kuru�luk bozuklu�u olan bir m��teri belli say�da k�rek alacakt�r.
	char kelime[1000];																				K�reklerin kuru� cinsinden fiyat� ve ekstra bozuklu�un x de�eri klavyeden girilece�ine g�re, bu m��terinin para �st�
	int i,j,alfabe[26],max=1;																		almadan alabilece�i en az k�rek say�s�n� yazd�ran program
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

   Klavyeden "hh:mm:dd AM" veya "hh:mm:dd PM" format�nda string olarak girilen zaman� AM ve PM'i dikkate alarak standart dijital saat g�sterimine uygun bir �ekilde d�nd�ren program

int main() {
	char gosterim[12];
	printf("Saati giriniz (hh:mm:dd[AM/PM]): ");
	gets(gosterim);
	int saat=atoi(gosterim);	//gosterim adl� string'i atoi fonksiyonu ile int'e �evirip saat adl� de�i�kene atad�m
	saat+= strstr(gosterim,"PM") ? (saat>=12 ? 0 : 12) : (saat>=12 ? -12 : 0);
	printf("Gercek zaman: %02d:%.2s:%.2s",saat,gosterim+3,gosterim+6);
	return 0;	//a="string" ise a+1="tring", a+2="ring", a+3="ing", a+4="ng", a+5="g" oluyor
}

   Klavyeden newline yap�lana kadar girdi alan, k���kten b�y��e s�ral� say�lar�n oldu�u bir dizi ve bu dizide aranacak, klavyeden girilen bir eleman i�in
   aranan eleman dizide bulunup bulunmad���n�, bulunuyorsa da hangi index'te bulundu�unu "binary search" algoritmas�yla bulup yazd�ran program

int binarySearch(int *dizi, int arka, int on, int x) {	//"binary search" brute force'a kayan linear search'e g�re �ok daha h�zl� ve verimlidir
	if(on>=arka) {
		int orta=(arka+on)/2;		//kabaca ��yle �al���yor: dizinin ortas�ndaki elemandan (medyan) b�y�kse eleman� �st yar�da, de�ilse alt yar�da ar�yor
        if(dizi[orta]==x)			//daha sonra at�yorum arad���m eleman �st yar�da ise bu yar�n�n medyan�ndan (�st �eyrek) b�y�kse eleman� �st �eyrekte, de�ilse alt �eyrekte ar�yor
			return orta;			//b�yle b�yle ta ki eleman bulunana kadar diziyi yar�laya yar�laya gidiyor ve eleman�n zaten matematiksel olarak bulunmayaca�� gereksiz alt dizileri program taramam�� oluyor ;)
		if(dizi[orta]>x)
			return binarySearch(dizi, arka, orta-1, x);
		return binarySearch(dizi, orta+1, on, x);													x ekseninde s�rayla x1, x2 ve x3 koordinatlar�nda bulunan 3 arkada� bir y�lba�� partisi i�in ortak bir noktada bulu�acakt�r.
	}																								Buna g�re, bu arkada�lar�n total benzin bak�m�ndan en ekonomik y�lba�� partisini d�zenlemeleri i�in toplamda minimum
	return -1;																						ne kadar mesafe katetmeleri gerekti�ini yazd�ran program
}
int main() {																						int main() {
	int *dizi=calloc(1000,sizeof(int)),aranan,n=0;														double x1,x2,x3;
	char ayrac;																							printf("Sirayla bu 3 arkadasin lokasyonlarini giriniz: ");
	printf("Diziyi giriniz: ");																			scanf("%lf%lf%lf",&x1,&x2,&x3);
	while(ayrac!='\n')																					double min = x1>x2 ? (x2>x3 ? x3 : x2) : (x1>x3 ? x3 : x1);
		scanf("%d%c",&dizi[n++],&ayrac);																double max = x1>x2 ? (x1>x3 ? x1 : x3) : (x2>x3 ? x2 : x3);
	realloc(dizi,sizeof(int)*n);																		printf("Minimum gidilmesi gereken yol: %lf",max-min);
	printf("Aranacak elemani giriniz: ");															}						//alternatif olarak "(fabs(x1-x2)+fabs(x1-x3)+fabs(x2-x3))/3.0" da ayn� sonucu verir
	scanf("%d",&aranan);
	int sonuc=binarySearch(dizi, 0, n-1, aranan);
	sonuc==-1 ? printf("Eleman dizide yok") : printf("Eleman %d no'lu index'te",sonuc);
	return 0;
}

   unsigned long long veri tipi bile 20'den b�y�k say�lar�n fakt�riyelini haf�zada overflow olmadan tutamad���na g�re, 20'den b�y�k say�lar�n fakt�riyelini dizi yard�m�yla yazd�ran program

int main() {
	int sayi,sayi_uzunlugu=1,i,j;
	short sonuc[10000]={0};
	sonuc[0]=1;			//sonuc[10000]={1,0,0,0,...9994 tane daha 0 sonra...,0,0}
	printf("Faktoriyeli alinacak sayiyi giriniz: ");
	scanf("%d",&sayi);
	for(i=2;i<=sayi;i++) {
		int tasi=0;
		for(j=0;j<sayi_uzunlugu;j++) {
			int carpim=i*sonuc[j]+tasi;		//mesela 120*6=720 ara i�lemi i�in sonuc dizisi 120 (5!=120) say�s�n� {0,2,1} olarak tutuyor
			short rakam=carpim%10;			//6*0=0 i�in tasi=0, ama 6*2=12 i�in tasi=1 oldu�undan son (asl�nda formal yaz�l���na g�re en ba�taki) basamak 6*1+1(tasi)=7 oluyor
			sonuc[j]=rakam;					//b�ylelikle de yeni sonuc dizim {0,2,7} oluyor
			tasi=carpim/10;			//720*7=5040 i�in ise sonuc dizisi {0,2,7}; 0*7=0, tasi=0; 2*7=14, tasi=1; 7*7+1(tasi)=50
		}							//bu i�lemlerde daima carpim'�n mod 10'daki de�erleri dizide saklan�ld��� i�in sonuc dizim �imdilik {0,4,0} oluyor
		while(tasi) {	//tasi=0 ise �al��maz, tasi!=0 iken �al���r
			sayi_uzunlugu++;
			short rakam=tasi%10;
			sonuc[sayi_uzunlugu-1]=rakam;	//burada mesela 720*7=5040 ara i�lemindeki 5'i de yazd�rabiliyorum ve sonuc dizim {0,4,0,5} oluyor
			tasi/=10;
		}
	}
	printf("%d!=",sayi);
	for(i=sayi_uzunlugu-1;i>=0;i--)
		printf("%hi",sonuc[i]);	//diziyi tersten yazd�r�r, bir de short belirtecim "%hi"
	return 0;
}

   Klavyeden girilen a ve b tam say� dizileri i�in a'n�n b�t�n elemanlar�na tam b�l�nen ve b'nin b�t�n elemanlar�n� tam b�len toplamda ka� tane tam say� oldu�unu yazd�ran program

int main() {																						Taranan index katar�n uzunlu�unu ge�iyorsa taranan index numaras� ba�a sard���na g�re, klavyeden girilen bir katarda
	int i,j,a_boyutu,b_boyutu,sayac1=0,sayac2=0;													klavyeden girilen bir karakterin ilk n index'te ka� defa tekrar etti�ini yazd�ran program
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

	for(i=max_a;i<=min_b;i++) {																		Klavyeden girilen bir pozitif tam say�y� olabildi�ince fazla asal say�n�n toplam� olarak yazd�ran program
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

   Bir say� ile o say�n�n tersten yaz�lm��� aras�ndaki mutlak fark k'ye tam b�l�n�yorsa o say�ya k'ye g�re g�zel say� ad� verildi�ine g�re, klavyeden
   s�rayla girilen i, j, k de�erleri i�in i ve j aras�ndaki say�lardan ka� tanesinin k'ye g�re g�zel say� oldu�unu fonksiyon �a��rarak yazd�ran program

int GuzelSayilar(int i,int j,int k) {
	char tersten[50],gecici;
	int i1,j1,I1,I2,sayac=0;
	for(I1=i;I1<=j;I1++) {
		sprintf(tersten,"%d",I1);	//say� string'e �evrildi
		i1=0,j1=strlen(tersten)-1;
		while(i1<j1) {
			gecici=tersten[i1];
			tersten[i1]=tersten[j1];
			tersten[j1]=gecici;
			i1++,j1--;	//swap & reverse
		}
		I2=atoi(tersten);	//string tekrar say�ya �evrildi
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

   M*N'lik bir matristeki b�t�n elemanlar matris i�inde 1 defa saat y�n�nde d�nd�r�ld���nde olu�an matrisi yazd�ran program

int i,j;																							Klavyeden girilen M*N'lik bir matristeki b�t�n elemanlar klavyeden girilen L say�s� kadar sola kayd�r�ld���nda olu�an matrisi yazd�ran program
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

   Klavyeden girilen 1. katar�n 2. katara toplamda n tane yap�lmak �zere sil ya da ekle (append and delete) i�lemleriyle
   d�n��t�r�l�p d�n��t�r�lemeyece�ini "Evet" ya da "Hay�r" d�nd�ren bir fonksiyon yard�m�yla cevaplayan program

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
		return "Evet";			//b�t�n hamlelerin kullan�lmas� gerek, ondan �t�r�
	else if(strlen(s)+strlen(t)<k)			//sonu�ta 1. katar komple silinip ba�tan yaz�larak 2. katara d�n��t�r�lebilir
		return "Evet";				//ve arada da baz� silme i�lemleri bo� (NULL) katar� silmeye �al��aca��ndan bo�a harcanabilir, �stteki ko�ula istisnaden
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

   Bir matematik soru bankas�nda n tane b�l�m, bu b�l�mlerde de farkl� say�larda problem bulunmaktad�r. Bu kitap, sayfa ba��na en fazla k tane problem d��ecek �ekilde
   yaz�ld���na ve sayfa, b�l�m ve problem no'lar� 1'den ba�layarak artan s�rada numaraland�r�ld���na g�re, klavyeden b�l�m say�s�, b�l�mlerdeki problem say�lar�n� s�rayla
   i�eren bir dizi ve sayfa ba��na d��en problem s�n�r� girilen ve bu girdilere g�re kitapta problem no'su bulundu�u sayfa no'suna e�it olan ka� tane problem oldu�unu yazd�ran program

int main() {																						Kar��l�kl� yinelemeyle (mutual recursion) klavyeden girilen bir say�n�n tek mi �ift mi oldu�unu yazd�ran program
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

   n tane oyuncunun yar��t��� bir programlama yar��mas�nda m tane konu ba�l��� alt�nda oyunlar yap�lacakt�r. Oyuncular�n bu konu ba�l�klar�ndaki oyunlardan ald��� skorlar s�rayla
   1 ve 0'lardan olu�an string'ler bi�iminde girildi�ine g�re bu oyunculardan ikili tak�mlar olu�turuldu�unda olu�turulabilecek tak�mlardan ka��n�n birinci olaca��n� yazd�ran program */

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
