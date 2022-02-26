#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Bir kitapl���n raflar�na farkl� veya ayn� sayfa say�s�na sahip kitaplar yerle�tirilecektir. Kitapl���n raf say�s�, ka��nc� rafa ka� sayfal�k toplam ka� kitap yerle�tirilece�i klavyeden girilece�ine g�re
   bir rafta ka� tane kitap ve toplam ka� sayfa bulundu�unu, bir raftaki herhangi bir kitab�n ka� sayfa oldu�unu ve kitapl�kta ka� kitap ve toplam ka� sayfa bulundu�unu yazd�ran program

int main() {
	int **sayfa_sayisi,*kitap_sayisi,raf_sayisi,istek_no1_sayisi,i,j,a,b,c,x,y,toplam=0,toplam1=0,toplam2=0;
	printf("***************Istek No***************\n\n1-Kacinci rafa kac sayfalik kitap yerlestirelim\n2-Kacinci rafta kac kitap ve toplam kac sayfa var");
	printf("\n3-Kacinci rafta kacinci sirada kac sayfalik kitap var\n4-Kitaplikta kac kitap ve toplam kac sayfa var\n\n");
	printf("**************************************\n\nKitapligin raf sayisini giriniz: ");
	scanf("%d",&raf_sayisi);
	kitap_sayisi=(int*) malloc(sizeof(int)*raf_sayisi);		//kitap_sayisi dizisinin elemanlar� s�rayla her bir raftaki kitap say�s�n� tutacak
	sayfa_sayisi=(int**) malloc(sizeof(int*)*raf_sayisi);	//sayfa_sayisi matrisi s�rayla her bir raftaki kitab�n s�rayla sayfa say�lar�n� tutacak
	for(i=0;i<raf_sayisi;i++) {					//dolay�s�yla bu matriste sat�rlar raf no'lar�n�, s�t�nlar ise o raftaki kitaplar�n s�ra no'lar�n� tutacak
		kitap_sayisi[i]=0;									//her bir rafta �imdilik 0 tane kitap var
		sayfa_sayisi[i]=(int*) malloc(sizeof(int));			//her bir raftaki kitap say�s� belli olmad��� gibi bu 2 boyutlu dizide matematiksel matrislerin aksine
	}				//her rafta farkl� say�larda kitap olabilece�inden �imdilik bellekte her sat�ra 1 elemanl�k yer ay�r�yoruz, zaten bunu ileride realloc ile d�zeltece�iz
	printf("1-Toplam kac kitap yerlestireceginizi giriniz: ");
	scanf("%d",&istek_no1_sayisi);
	while(istek_no1_sayisi--) {								//while i�inde yer alan "istek_no1_sayisi--" yarg�s� istek_no1_sayisi=0 (false) olmad��� s�rece okunacak ve d�ng� devam edecek
		printf("Raf no ve sayfa sayisi giriniz: ");			//istek_no1_sayisi=0 (false) olunca da d�ng�den ��kacak ("--" sol de�il sa� tarafta yer ald��� i�in ilk true mu (!0) false mu (0) diye bakacak sonra bir azaltacak)
		scanf("%d%d",&x,&y);
		kitap_sayisi[x-1]+=1;		//kitap_sayisi dizisi elemanlar�nda sadece raflardaki kitap say�lar�n�n hesab�n� tuttu�u i�in her bir eleman� saya� gibi bir bir artar
		*(sayfa_sayisi+x-1)=realloc(*(sayfa_sayisi+x-1),*(kitap_sayisi+x-1)*sizeof(int));	//sayfa_sayisi matrisininin sat�rlar�ndaki eleman say�s� (kitapl���n raflar�ndaki kitap say�s�)
		*(*(sayfa_sayisi+x-1)+*(kitap_sayisi+x-1)-1)=y;		//realloc ile belirlenirken (x-1) index'li sat�rda (*(kitap_sayisi+x-1)-1) index'li s�tundaki eleman	
	}														//x. rafta *(kitap_sayisi+x-1). s�radaki kitab�n sayfa say�s�n� tutacak
	printf("2-Raf no giriniz: ");
	scanf("%d",&a);
	for(j=0;j<*(kitap_sayisi+a-1);j++)
		toplam+=sayfa_sayisi[a-1][j];
	printf("%d. raftaki kitap sayisi ve toplam sayfa sayisi: %d %d\n",a,*(kitap_sayisi+a-1),toplam);
	printf("3-Raf no ve sira no giriniz: ");
	scanf("%d%d",&b,&c);
	printf("%d. rafta %d. siradaki kitabin sayfa sayisi: %d\n",b,c,*(*(sayfa_sayisi+b-1)+c-1));
	for(i=0;i<raf_sayisi;i++) {
		toplam1+=kitap_sayisi[i];
		for(j=0;j<*(kitap_sayisi+i);j++)
			toplam2+=sayfa_sayisi[i][j];
	}
	printf("4-Kitapliktaki toplam kitap sayisi ve toplam sayfa sayisi: %d %d",toplam1,toplam2);
}

   Klavyeden girilen 2 tarih aras�ndaki g�n, ay ve y�l fark�n� yazd�ran program

int main() {
	int gun1,ay1,yil1,gun2,ay2,yil2,gun_farki,ay_farki,yil_farki;
	printf("Birinci tarihi giriniz (GG/AA/YYYY): ");
	scanf("%d/%d/%d",&gun1,&ay1,&yil1);
	printf("Ikinci tarihi giriniz (GG/AA/YYYY): ");
	scanf("%d/%d/%d",&gun2,&ay2,&yil2);		//girilen de�erlerin alg�lanmas� i�in bu sefer slash'leri de klavyeyle yazmak zorunday�m
	if(!tarihfonk(gun1,ay1,yil1)) {			//normalde if,while,for gibi yap�lar i�indeki ko�ul yarg�lar� "true" iken �al���r
		printf("Ilk tarih gecersiz\n");		//"!" i�areti ters yapt��� i�in yarg�=>true ise !yarg�=>false ve vice versa oldu�undan
		exit(0);							//fonksiyon false (0) g�nderirken true (1) g�nderiyor gibi olacak
	}										//exit(0) veya exit(1) ayn� return komutu gibi main fonksiyonunu sonland�r�r
	if(!tarihfonk(gun2,ay2,yil2)) {			//exit(0): program ba�ar�l� bir �ekilde sonland�r�lm��t�r (exit success)
		printf("Ikinci tarih gecersiz\n");	//exit(1): program hatal� bir �ekilde sonland�r�lm��t�r (exit failure)
		exit(0);							//kod i�erisinde return 0 ve return 1 yerine s�rayla exit(0) ve exit(1) kullan�labilir
	}
	if(gun2<gun1) {
		if(ay2==3) {	//�ubat ay�ndan g�n alal�m		(ay2 normalde mart oluyo ama bir �nceki aydan yani �ubattan g�n al�yor)
			if((yil2%4==0 && yil2%100!=0) || (yil2%400==0))		//art�k y�l m� de�il mi kontrol edelim
				gun2+=29;
            else
				gun2+=28;
		}
		else if(ay2==5 || ay2==7 || ay2==10 || ay2==12)
			gun2+=30;	//nisan, haziran, eyl�l veya kas�mdan g�n alal�m
		else
			gun2+=31;	//ocak, mart, may�s, temmuz, a�ustos, ekim veya aral�ktan g�n alal�m

		ay2-=1;		//aydan g�n ald���m i�in bir d��t� (misal 62-29=33 i�leminde 2'den 9 ��kmaz,
	}				//o y�zden 12-9=3 olur ve eksilenin onlar basama�� 6-1=5 olurken 50-20=30'dan 30+3=33 gelir)
	if(ay2<ay1) {
		ay2+=12;
		yil2-=1;
	}
	gun_farki=gun2-gun1;
	ay_farki=ay2-ay1;
	yil_farki=yil2-yil1;
	printf("Tarihler arasindaki fark: %04d yil %02d ay ve %02d gun",yil_farki,ay_farki,gun_farki);
}
int tarihfonk(int gun, int ay, int yil) {	//girilen tarih ge�erli mi de�il mi kontrol eden fonksiyon
	int gecerli=1,artik_yil=0;
	if(yil>=1 && yil<=9999) {
		if((yil%4==0 && yil%100!=0) || (yil%400==0))	//art�k y�l m� de�il mi kontrol edelim
			artik_yil=1;
		if(ay>=1 && ay<=12) {				//ay 1 ve 12 aras�nda m� kontrol edelim
			if(ay==2) {
				if(artik_yil && gun==29)
					gecerli=1;				//�ubat� kontrol edelim
				else if(gun>28)
					gecerli=0;
			}
			else if(ay==4 || ay==6 || ay==9 || ay==11)
				if(gun>30)		//nisan, haziran, eyl�l ve kas�m� kontrol edelim
					gecerli=0;
			else if(gun>31)		//geriye kalan aylar� (ocak, mart, may�s, temmuz, a�ustos, ekim ve aral�k) kontrol edelim
				gecerli=0;
		}
		else
			gecerli=0;
	}
	else
		gecerli=0;
	return gecerli;
}

   Klavyeden girilen kelimelerin b�t�n perm�tasyonlar�n� leksikografik s�ralamada (s�zl�klerde kullan�lan evrensel s�ralama) yazd�ran program

void swap(char **s,int a,int b) {
	char *gecici=s[a];
	s[a]=s[b];
	s[b]=gecici;
}
int sonraki_permutasyon(char **s,int n) {
	int i=n-1;		//i son katar�n index'ine e�it
	while(i>0 && strcmp(s[i-1],s[i])>=0)
		i--;		//perm�tasyonda bir �nceki katar bir sonrakinden b�y�k e�it oldu�u s�rece i'yi bir azalt
	if(i==0)
		return 0;	//e�er i'nin de�eri 0 ise main i�indeki do while yap�s�na false d�nd�r ve kodu sonland�r	(��nk� s�ralama en b�y�kten en k����e oldu�undan son perm�tasyon bulunmu� demektir)
					//i'nin de�eri 0 de�ilse zaten b�y�kten k����e olan s�ralamay� sondan bozan ilk katar� bulduk demektir
	int j=n-1;		//i-1 s�ralamay� bozan bu katar�n index'ine, j ise son katar�n index'ine e�it
	while(strcmp(s[i-1],s[j])>=0)	//(i-1). index'teki katar j. index'teki katardan b�y�k e�it oldu�u s�rece j'yi bir azalt
		j--;
	swap(s,i-1,j);

	j=n-1;			//j tekrar son katar�n index'ine e�it
	while(i<j) {
		swap(s,i,j);
		i++;
		j--;		//i. index'teki katardan son katara kadar olan s�ralaman�n tersini al�yor (reverse)
	}				//b�ylelikle en sondaki b�y�kten k����e kadar olan k�s�m 1 tanesi hari� ayn� katarlarla k���kten b�y��e s�ralan�yor
	return 1;		//ve o 1 tane de �nceki perm�tasyondaki b�y�kten k����e s�ralamay� sondan bozan katar oluyor
}					//dahas� o katar sondan kendisinden b�y�k en k���k katarla de�i�ti�inden (swap) bir sonraki leksikografik perm�tasyona ge�iliyor
int main() {
	char **s,*tut;
	int i,j,n;
	printf("Kelime sayisini giriniz: ");
	scanf("%d",&n);
	s=malloc(sizeof(char*)*n);
	printf("Kelimeleri giriniz: ");
	for(i=0;i<n;i++) {
		s[i]=malloc(sizeof(char)*20);
		scanf("%s",s[i]);
	}
	printf("\n\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(strcmp(s[i],s[j])<=0)
				swap(s,i,j);			//�uan katarlar en k���kten en b�y��e do�ru s�ralanm�� durumda
	do {
		for(i=0;i<n;i++)
			printf("%s%c",s[i], i==n-1 ? '\n' : ' ');	//i de�eri n-1'e e�itse alt sat�ra ge�, de�ilse bo�luk b�rak
	} while(sonraki_permutasyon(s,n));					//while'�n i�indeki fonksiyon true (1) d�nd�rd��� s�rece perm�tasyonlar� yazd�rmaya devam et
}														//en son perm�tasyonda katarlar en b�y�kten en k����e do�ru s�ralanm�� durumda olacakt�r

   Klavyeden girilen decimal (on taban�ndaki) bir say�y� binary (2 taban�ndaki), octal (8 taban�ndaki) ya da
   hexadecimal (16 taban�ndaki) kar��l���n� sonsuz d�ng� i�inde switch case yard�m�yla yazd�ran program

void tabanaritmetigi(int sayi,int taban) {																	Klavyeden u�rayaca�� durak say�s� girilen bo� bir otob�se klavyeden bu duraklarda s�ras�yla otob�sten inen ve otob�se
	int rakam;																								binen ki�i say�lar� girilecektir. �lk durakta otob�sten kimse inmedi�ine ve son durak otob�sten herkes indi�ine g�re
	if(sayi==0)																								otob�s�n minimum kapasitesinin ka� ki�i olmas� gerekti�ini yazd�ran program
		return;
	else {																									struct otobus {
		rakam=sayi%taban;					//en sa�daki rakam� al												int binen;
		tabanaritmetigi(sayi/taban,taban);	//recursive call													int inen;
		if(taban==16 && rakam>=10)																			};
			printf("%c",rakam+55);																			int main() {
		else																									struct otobus oto;
			printf("%d",rakam);																					int n,i,kapasite=0,toplam=0;
	}																											printf("Durak sayisini giriniz: ");
}																												scanf("%d",&n);
int main() {																									for(i=1;i<=n;i++) {
	int sayi,secim,taban;																							printf("%d. durakta inen ve binen kisi sayilari: ");
	while(1) {		//sonsuz d�ng�  (infinite loop)																	scanf("%d%d",&oto.inen,&oto.binen);
		printf("********** Taban Aritmetigi Menusu **********\n\n");												toplam+=oto.binen-oto.inen;
		printf("1. Decimal --> Binary\n");																			if(toplam>kapasite)
		printf("2. Decimal --> Octal\n");																				kapasite=toplam;
		printf("3. Decimal --> Hexadecimal\n");																	}
		printf("4. Programi sonlandir\n\n");																	printf("Minimum kapasite: %d",kapasite);
		printf("Secim yapiniz: ");																			}
a:		scanf("%d",&secim);
		switch(secim) {																						n ki�inin bir bulundu�u bir kuyrukta ge�en her saat sonunda erkeklerin kendilerinin bir arkas�ndaki kad�nlar�n bir �ne
			case 1:																							ge�mesine m�saade etti�i bilinmektedir. Kuyru�un uzunlu�u sabit kald���na g�re; ki�i say�s� (n), ge�en s�re (t saat)
				taban=2; break;																				ve kuyru�un ilk hali kuyru�un en ba��ndan itibaren s�rayla kimlerin yer ald��� 'E' (erkek) ve 'K' (kad�n) harfleriyle
			case 2:																							bir katar bi�iminde klavyeden girildikten sonra t s�renin sonunda kuyru�un durumunu yazd�ran program
				taban=8; break;
			case 3:																							int main() {
				taban=16; break;																				int n,t,i=0; char gecici;
			case 4:																								printf("Kuyruktaki kisi sayisini ve kac saat gectigini giriniz: ");
				printf("\nCikis yapiliyor..."); exit(1);														scanf("%d%d",&n,&t);
			default:																							int T=t;
				printf("\nHatali giris, lutfen tekrar giriniz: ");												printf("Kuyrugun ilk halini giriniz (E: Erkek, K: Kadin): ");
				goto a;																							char *sira=(char*) malloc(n);
		}																										scanf("%s",sira);
		printf("Sayi giriniz: ");																				while(t--) {
		scanf("%d",&sayi);																							while(i<n-1) {
		printf("Sonuc: ");																								if(sira[i]=='E' && sira[i+1]=='K') {
		tabanaritmetigi(sayi,taban);																						gecici=sira[i];
		printf("\n\n");																										sira[i]=sira[i+1];
	}																														sira[i+1]=gecici;
}																															i+=2;
																														}
   Bir ilkokul ��retmeni s�n�f�ndaki her bir ��renci i�in yapboz alacakt�r. Ancak markette sat�lan						else
   yapbozlar�n zorluk dereceleri par�a say�lar�yla orant�l� oldu�undan ��retmen ��rencilerine adil							i++;
   davranmak i�in ald��� yapbozlar�n par�a say�lar�n� birbirlerine olabildi�ince yak�n tutmak, yani en				}
   �ok par�aya sahip yapboz ile en az par�aya sahip yapboz aras�ndaki fark� minimum tutmak istiyor.					i=0;
   ��renci say�s�, markette bulunan yapboz say�s� ve bu yapbozlar�n par�a say�lar� s�rayla						}
   klavyeden girilece�ine g�re ��retmenin bu fark� minimum ka� tutabilece�ini yazd�ran program					printf("Kuyrugun %d saat sonraki hali: %s",T,sira);
																											}

int main() {																								Klavyeden girilen bir dizinin en b�y�k eleman�n�n dizinin en ba��nda, en k���k eleman�n�n ise dizinin en sonunda olmas�
    int ogrenci_sayisi,puzzle_sayisi,i,j,gecici,min;														i�in dizinin iki ard���k elemanlar� aras�nda en az ka� defa swap yap�lmas� gerekti�ini yazd�ran program
    printf("Ogrenci sayisini ve yapboz sayisini giriniz: ");
    scanf("%d%d",&ogrenci_sayisi,&puzzle_sayisi);															int main() {
    int *puzzlelar=(int*) malloc(sizeof(int)*puzzle_sayisi);													int n,i,k;
    printf("Yapbozlarin parca sayilarini giriniz: ");															printf("Dizinin eleman sayisi: ");
    for(i=0;i<puzzle_sayisi;i++)																				scanf("%d",&n);
        scanf("%d",&puzzlelar[i]);																				printf("Diziyi giriniz: ");
    for(i=0;i<puzzle_sayisi;i++)																				scanf("%d",&k);
        for(j=0;j<puzzle_sayisi;j++)																			int min=k,max=k,min_i=1,max_i=1;
            if(puzzlelar[i]<puzzlelar[j]) {																		for(i=2;i<=n;i++) {
                gecici=puzzlelar[i];																				scanf("%d",&k);
                puzzlelar[i]=puzzlelar[j];																			if(k>max) {
                puzzlelar[j]=gecici;																					max=k;
            }																											max_i=i;
    min=puzzlelar[puzzle_sayisi-1]-puzzlelar[0];																	}
    for(i=0;i<puzzle_sayisi-ogrenci_sayisi+1;i++)																	if(min<=k) {
        if(puzzlelar[i+ogrenci_sayisi-1]-puzzlelar[i]<min)																min=k;
            min=puzzlelar[i+ogrenci_sayisi-1]-puzzlelar[i];																min_i=i;
    printf("Minimum fark: %d",min);																					}
}																												}
																												if(max_i-min_i>=1)
   Klavyeden girilen say� bulunana kadar girilen tahminlerin bulunacak say�ya ne kadar								printf("Swap sayisi: %d",max_i+n-min_i-2);
   yakla�t���n� en yak�n tahminlerle birlikte yazd�ran program													else
																													printf("Swap sayisi: %d",max_i+n-min_i-1);
int SayiyiBul(int x,int *altsinir,int *ustsinir) {															}
	int tahmin;
	scanf("%d",&tahmin);																					Bir array1 dizisini, array2 dizisiyle ortak olan elemanlar�n� sildikten sonra tekrar yazd�ran program
	if(*ustsinir>tahmin && tahmin>x) {
		printf("Asagi in\n");																				void print_array(int *array, int array_size) {
		*ustsinir=tahmin;																						int i;
	}																											for(i=0;i<array_size;i++)
	else if(x>tahmin && tahmin>*altsinir) {																			printf("%d ",array[i]);
		printf("Yukari cik\n");																					printf("\n");
		*altsinir=tahmin;																					}
	}																										int main() {
	else if(tahmin>=*ustsinir)																					int array1[10]={98,23,46,32,13,7,130,534,2,1001};
		printf("Cok ciktin\n");																					int array2[5]={13,23,3,99,1001}, i,j,k,counter=0;
	else if(tahmin<=*altsinir)																					printf("A kumesi: ");
		printf("Cok indin\n");																					print_array(array1,10);
	return tahmin;																								printf("B kumesi: ");
}																												print_array(array2,5);
int main() {																									for(i=0;i<10-counter;i++)
	int x,altsinir=0,ustsinir=1000;																					for(j=0;j<5;j++)
	printf("Tahmin edilecek sayi: ");																					if(array1[i]==array2[j]) {
	scanf("%d",&x);																											counter++;
	printf("Tahminleri giriniz: ");																							for(k=i;k<9;k++)
	int tahmin=SayiyiBul(x,&altsinir,&ustsinir);																				array1[k]=array1[k+1];	//left shift
	while(tahmin!=x)																									}
		tahmin=SayiyiBul(x,&altsinir,&ustsinir);																printf("A\\B kumesi: ");
	printf("Voila!!!\nEn yakin tahminler: %d %d",altsinir,ustsinir);											print_array(array1,10-counter);
}																											}

   S�rayla kLavyeden girilen N, X ve K de�erleri i�in N elemanl� bir dizide X eleman� dizide bulunuyorsa	Klavyeden girilen kendi i�inde rakamlar� farkl� iki say�n�n ortak ka� tane rakam bar�nd�rd���n� yazd�ran program
   X'in K kadar soluna ve sa��na uzanan kanatlar�nda bulunan kom�u say�lar X ile birlikte kendi aras�nda
   k���kten b�y��e s�raland���nda olu�an yeni diziyi d�nd�ren, X eleman� dizide bulunmuyorsa diziyi			int is_Y_a_digit_in_X(int x, int y) {
   oldu�u gibi d�nd�ren program																					while(x>0) {
																													if(x%10==y)
int main() {																											return 1;
	int i,j,N,X,x,K,gecici,min,max;																					x/=10;
	printf("Dizinin eleman sayisini giriniz: ");																}
	scanf("%d",&N);																								return 0;
	int *dizi=(int*) malloc(sizeof(int)*N);																	}
	printf("Diziyi giriniz: ");																				int main() {
	for(i=0;i<N;i++)																							int a,b,common_digit=0;
		scanf("%d",&dizi[i]);																					printf("Iki sayi giriniz: ");
	printf("X elemanini ve kanat uzunlugunu giriniz: ");														scanf("%d%d",&a,&b);
	scanf("%d%d",&X,&K);																						int asil_a = a;
	for(x=0;x<N;x++) {																							while(a>0) {
		if(dizi[x]==X)																								common_digit += is_Y_a_digit_in_X(b, a%10);
			break;																									a/=10;
		if(x==N-1) {																							}
			for(i=0;i<N;i++)																					printf(common_digit ? "%d ve %d ortak %d tane rakam barindirir."
				printf("%d ",dizi[i]);																			: "%d ve %d ortak rakam barindirmaz.", asil_a, b, common_digit);
			return 0;																							return 0;
		}																									}
	}
	if(x-K<0)
		min=0;
	else
		min=x-K;
	if(x+K>N-1)
		max=N-1;
	else
		max=x+K;
	for(i=0;i<max-min;i++)
		for(j=min;j<max-i;j++)
			if(dizi[j]>dizi[j+1]) {		//bubble sort, istenen say� kabarc�k gibi en �ste ��k�yor
				gecici=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=gecici;
			}
	printf("Duzenlenmis dizi: ");
	for(i=0;i<N;i++)
		printf("%d ",dizi[i]);
}

   Klavyeden girilen bir dizinin denge index'ini (sol ve sa� kanatlar�ndaki say�lar toplam�n�n e�it oldu�u index) d�nd�ren �ngilizce program */

#define MAX_ARR_SIZE 100

void print_array(int arr[], int n) {
	int i;
	printf("Array:");
	for(i=0;i<n;i++)
		printf(" %d",arr[i]);
	puts("\n");
}
void scan_array(int arr[], int *arr_size) {
	int i;
	char ch;
	printf("Enter array: ");
	for(i=0;ch!='\n';i++)
		scanf("%d%c",&arr[i],&ch);
	puts("");
	*arr_size=i;
}
void equilibrium(int arr[], int n) {
	int i,j,ans=-1;
	for(i=0;i<n;i++) {
		int leftsum=0,rightsum=0;
		for(j=0;j<i;j++)
			leftsum+=arr[j];
		for(j=i+1;j<n;j++)
			rightsum+=arr[j];
		if(leftsum==rightsum) {
			ans=i;
			break;
		}
	}
	printf(ans==-1 ? "Equilibrium index not found.\n\n" : "Equilibrium index: %d\n\n", ans);
}
int main() {
	int arr[]={-7,1,5,2,-4,3,0}, arr_size=sizeof(arr)/sizeof(arr[0]), arr2[MAX_ARR_SIZE], arr2_size;
	print_array(arr,arr_size);
	equilibrium(arr,arr_size);
	scan_array(arr2,&arr2_size);
	equilibrium(arr2,arr2_size);
	return 0;
}
