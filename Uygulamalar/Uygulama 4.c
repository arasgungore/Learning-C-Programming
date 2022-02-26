#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Bir kitaplýðýn raflarýna farklý veya ayný sayfa sayýsýna sahip kitaplar yerleþtirilecektir. Kitaplýðýn raf sayýsý, kaçýncý rafa kaç sayfalýk toplam kaç kitap yerleþtirileceði klavyeden girileceðine göre
   bir rafta kaç tane kitap ve toplam kaç sayfa bulunduðunu, bir raftaki herhangi bir kitabýn kaç sayfa olduðunu ve kitaplýkta kaç kitap ve toplam kaç sayfa bulunduðunu yazdýran program

int main() {
	int **sayfa_sayisi,*kitap_sayisi,raf_sayisi,istek_no1_sayisi,i,j,a,b,c,x,y,toplam=0,toplam1=0,toplam2=0;
	printf("***************Istek No***************\n\n1-Kacinci rafa kac sayfalik kitap yerlestirelim\n2-Kacinci rafta kac kitap ve toplam kac sayfa var");
	printf("\n3-Kacinci rafta kacinci sirada kac sayfalik kitap var\n4-Kitaplikta kac kitap ve toplam kac sayfa var\n\n");
	printf("**************************************\n\nKitapligin raf sayisini giriniz: ");
	scanf("%d",&raf_sayisi);
	kitap_sayisi=(int*) malloc(sizeof(int)*raf_sayisi);		//kitap_sayisi dizisinin elemanlarý sýrayla her bir raftaki kitap sayýsýný tutacak
	sayfa_sayisi=(int**) malloc(sizeof(int*)*raf_sayisi);	//sayfa_sayisi matrisi sýrayla her bir raftaki kitabýn sýrayla sayfa sayýlarýný tutacak
	for(i=0;i<raf_sayisi;i++) {					//dolayýsýyla bu matriste satýrlar raf no'larýný, sütünlar ise o raftaki kitaplarýn sýra no'larýný tutacak
		kitap_sayisi[i]=0;									//her bir rafta þimdilik 0 tane kitap var
		sayfa_sayisi[i]=(int*) malloc(sizeof(int));			//her bir raftaki kitap sayýsý belli olmadýðý gibi bu 2 boyutlu dizide matematiksel matrislerin aksine
	}				//her rafta farklý sayýlarda kitap olabileceðinden þimdilik bellekte her satýra 1 elemanlýk yer ayýrýyoruz, zaten bunu ileride realloc ile düzelteceðiz
	printf("1-Toplam kac kitap yerlestireceginizi giriniz: ");
	scanf("%d",&istek_no1_sayisi);
	while(istek_no1_sayisi--) {								//while içinde yer alan "istek_no1_sayisi--" yargýsý istek_no1_sayisi=0 (false) olmadýðý sürece okunacak ve döngü devam edecek
		printf("Raf no ve sayfa sayisi giriniz: ");			//istek_no1_sayisi=0 (false) olunca da döngüden çýkacak ("--" sol deðil sað tarafta yer aldýðý için ilk true mu (!0) false mu (0) diye bakacak sonra bir azaltacak)
		scanf("%d%d",&x,&y);
		kitap_sayisi[x-1]+=1;		//kitap_sayisi dizisi elemanlarýnda sadece raflardaki kitap sayýlarýnýn hesabýný tuttuðu için her bir elemaný sayaç gibi bir bir artar
		*(sayfa_sayisi+x-1)=realloc(*(sayfa_sayisi+x-1),*(kitap_sayisi+x-1)*sizeof(int));	//sayfa_sayisi matrisininin satýrlarýndaki eleman sayýsý (kitaplýðýn raflarýndaki kitap sayýsý)
		*(*(sayfa_sayisi+x-1)+*(kitap_sayisi+x-1)-1)=y;		//realloc ile belirlenirken (x-1) index'li satýrda (*(kitap_sayisi+x-1)-1) index'li sütundaki eleman	
	}														//x. rafta *(kitap_sayisi+x-1). sýradaki kitabýn sayfa sayýsýný tutacak
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

   Klavyeden girilen 2 tarih arasýndaki gün, ay ve yýl farkýný yazdýran program

int main() {
	int gun1,ay1,yil1,gun2,ay2,yil2,gun_farki,ay_farki,yil_farki;
	printf("Birinci tarihi giriniz (GG/AA/YYYY): ");
	scanf("%d/%d/%d",&gun1,&ay1,&yil1);
	printf("Ikinci tarihi giriniz (GG/AA/YYYY): ");
	scanf("%d/%d/%d",&gun2,&ay2,&yil2);		//girilen deðerlerin algýlanmasý için bu sefer slash'leri de klavyeyle yazmak zorundayým
	if(!tarihfonk(gun1,ay1,yil1)) {			//normalde if,while,for gibi yapýlar içindeki koþul yargýlarý "true" iken çalýþýr
		printf("Ilk tarih gecersiz\n");		//"!" iþareti ters yaptýðý için yargý=>true ise !yargý=>false ve vice versa olduðundan
		exit(0);							//fonksiyon false (0) gönderirken true (1) gönderiyor gibi olacak
	}										//exit(0) veya exit(1) ayný return komutu gibi main fonksiyonunu sonlandýrýr
	if(!tarihfonk(gun2,ay2,yil2)) {			//exit(0): program baþarýlý bir þekilde sonlandýrýlmýþtýr (exit success)
		printf("Ikinci tarih gecersiz\n");	//exit(1): program hatalý bir þekilde sonlandýrýlmýþtýr (exit failure)
		exit(0);							//kod içerisinde return 0 ve return 1 yerine sýrayla exit(0) ve exit(1) kullanýlabilir
	}
	if(gun2<gun1) {
		if(ay2==3) {	//þubat ayýndan gün alalým		(ay2 normalde mart oluyo ama bir önceki aydan yani þubattan gün alýyor)
			if((yil2%4==0 && yil2%100!=0) || (yil2%400==0))		//artýk yýl mý deðil mi kontrol edelim
				gun2+=29;
            else
				gun2+=28;
		}
		else if(ay2==5 || ay2==7 || ay2==10 || ay2==12)
			gun2+=30;	//nisan, haziran, eylül veya kasýmdan gün alalým
		else
			gun2+=31;	//ocak, mart, mayýs, temmuz, aðustos, ekim veya aralýktan gün alalým

		ay2-=1;		//aydan gün aldýðým için bir düþtü (misal 62-29=33 iþleminde 2'den 9 çýkmaz,
	}				//o yüzden 12-9=3 olur ve eksilenin onlar basamaðý 6-1=5 olurken 50-20=30'dan 30+3=33 gelir)
	if(ay2<ay1) {
		ay2+=12;
		yil2-=1;
	}
	gun_farki=gun2-gun1;
	ay_farki=ay2-ay1;
	yil_farki=yil2-yil1;
	printf("Tarihler arasindaki fark: %04d yil %02d ay ve %02d gun",yil_farki,ay_farki,gun_farki);
}
int tarihfonk(int gun, int ay, int yil) {	//girilen tarih geçerli mi deðil mi kontrol eden fonksiyon
	int gecerli=1,artik_yil=0;
	if(yil>=1 && yil<=9999) {
		if((yil%4==0 && yil%100!=0) || (yil%400==0))	//artýk yýl mý deðil mi kontrol edelim
			artik_yil=1;
		if(ay>=1 && ay<=12) {				//ay 1 ve 12 arasýnda mý kontrol edelim
			if(ay==2) {
				if(artik_yil && gun==29)
					gecerli=1;				//þubatý kontrol edelim
				else if(gun>28)
					gecerli=0;
			}
			else if(ay==4 || ay==6 || ay==9 || ay==11)
				if(gun>30)		//nisan, haziran, eylül ve kasýmý kontrol edelim
					gecerli=0;
			else if(gun>31)		//geriye kalan aylarý (ocak, mart, mayýs, temmuz, aðustos, ekim ve aralýk) kontrol edelim
				gecerli=0;
		}
		else
			gecerli=0;
	}
	else
		gecerli=0;
	return gecerli;
}

   Klavyeden girilen kelimelerin bütün permütasyonlarýný leksikografik sýralamada (sözlüklerde kullanýlan evrensel sýralama) yazdýran program

void swap(char **s,int a,int b) {
	char *gecici=s[a];
	s[a]=s[b];
	s[b]=gecici;
}
int sonraki_permutasyon(char **s,int n) {
	int i=n-1;		//i son katarýn index'ine eþit
	while(i>0 && strcmp(s[i-1],s[i])>=0)
		i--;		//permütasyonda bir önceki katar bir sonrakinden büyük eþit olduðu sürece i'yi bir azalt
	if(i==0)
		return 0;	//eðer i'nin deðeri 0 ise main içindeki do while yapýsýna false döndür ve kodu sonlandýr	(çünkü sýralama en büyükten en küçüðe olduðundan son permütasyon bulunmuþ demektir)
					//i'nin deðeri 0 deðilse zaten büyükten küçüðe olan sýralamayý sondan bozan ilk katarý bulduk demektir
	int j=n-1;		//i-1 sýralamayý bozan bu katarýn index'ine, j ise son katarýn index'ine eþit
	while(strcmp(s[i-1],s[j])>=0)	//(i-1). index'teki katar j. index'teki katardan büyük eþit olduðu sürece j'yi bir azalt
		j--;
	swap(s,i-1,j);

	j=n-1;			//j tekrar son katarýn index'ine eþit
	while(i<j) {
		swap(s,i,j);
		i++;
		j--;		//i. index'teki katardan son katara kadar olan sýralamanýn tersini alýyor (reverse)
	}				//böylelikle en sondaki büyükten küçüðe kadar olan kýsým 1 tanesi hariç ayný katarlarla küçükten büyüðe sýralanýyor
	return 1;		//ve o 1 tane de önceki permütasyondaki büyükten küçüðe sýralamayý sondan bozan katar oluyor
}					//dahasý o katar sondan kendisinden büyük en küçük katarla deðiþtiðinden (swap) bir sonraki leksikografik permütasyona geçiliyor
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
				swap(s,i,j);			//þuan katarlar en küçükten en büyüðe doðru sýralanmýþ durumda
	do {
		for(i=0;i<n;i++)
			printf("%s%c",s[i], i==n-1 ? '\n' : ' ');	//i deðeri n-1'e eþitse alt satýra geç, deðilse boþluk býrak
	} while(sonraki_permutasyon(s,n));					//while'ýn içindeki fonksiyon true (1) döndürdüðü sürece permütasyonlarý yazdýrmaya devam et
}														//en son permütasyonda katarlar en büyükten en küçüðe doðru sýralanmýþ durumda olacaktýr

   Klavyeden girilen decimal (on tabanýndaki) bir sayýyý binary (2 tabanýndaki), octal (8 tabanýndaki) ya da
   hexadecimal (16 tabanýndaki) karþýlýðýný sonsuz döngü içinde switch case yardýmýyla yazdýran program

void tabanaritmetigi(int sayi,int taban) {																	Klavyeden uðrayacaðý durak sayýsý girilen boþ bir otobüse klavyeden bu duraklarda sýrasýyla otobüsten inen ve otobüse
	int rakam;																								binen kiþi sayýlarý girilecektir. Ýlk durakta otobüsten kimse inmediðine ve son durak otobüsten herkes indiðine göre
	if(sayi==0)																								otobüsün minimum kapasitesinin kaç kiþi olmasý gerektiðini yazdýran program
		return;
	else {																									struct otobus {
		rakam=sayi%taban;					//en saðdaki rakamý al												int binen;
		tabanaritmetigi(sayi/taban,taban);	//recursive call													int inen;
		if(taban==16 && rakam>=10)																			};
			printf("%c",rakam+55);																			int main() {
		else																									struct otobus oto;
			printf("%d",rakam);																					int n,i,kapasite=0,toplam=0;
	}																											printf("Durak sayisini giriniz: ");
}																												scanf("%d",&n);
int main() {																									for(i=1;i<=n;i++) {
	int sayi,secim,taban;																							printf("%d. durakta inen ve binen kisi sayilari: ");
	while(1) {		//sonsuz döngü  (infinite loop)																	scanf("%d%d",&oto.inen,&oto.binen);
		printf("********** Taban Aritmetigi Menusu **********\n\n");												toplam+=oto.binen-oto.inen;
		printf("1. Decimal --> Binary\n");																			if(toplam>kapasite)
		printf("2. Decimal --> Octal\n");																				kapasite=toplam;
		printf("3. Decimal --> Hexadecimal\n");																	}
		printf("4. Programi sonlandir\n\n");																	printf("Minimum kapasite: %d",kapasite);
		printf("Secim yapiniz: ");																			}
a:		scanf("%d",&secim);
		switch(secim) {																						n kiþinin bir bulunduðu bir kuyrukta geçen her saat sonunda erkeklerin kendilerinin bir arkasýndaki kadýnlarýn bir öne
			case 1:																							geçmesine müsaade ettiði bilinmektedir. Kuyruðun uzunluðu sabit kaldýðýna göre; kiþi sayýsý (n), geçen süre (t saat)
				taban=2; break;																				ve kuyruðun ilk hali kuyruðun en baþýndan itibaren sýrayla kimlerin yer aldýðý 'E' (erkek) ve 'K' (kadýn) harfleriyle
			case 2:																							bir katar biçiminde klavyeden girildikten sonra t sürenin sonunda kuyruðun durumunu yazdýran program
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
   Bir ilkokul öðretmeni sýnýfýndaki her bir öðrenci için yapboz alacaktýr. Ancak markette satýlan						else
   yapbozlarýn zorluk dereceleri parça sayýlarýyla orantýlý olduðundan öðretmen öðrencilerine adil							i++;
   davranmak için aldýðý yapbozlarýn parça sayýlarýný birbirlerine olabildiðince yakýn tutmak, yani en				}
   çok parçaya sahip yapboz ile en az parçaya sahip yapboz arasýndaki farký minimum tutmak istiyor.					i=0;
   Öðrenci sayýsý, markette bulunan yapboz sayýsý ve bu yapbozlarýn parça sayýlarý sýrayla						}
   klavyeden girileceðine göre öðretmenin bu farký minimum kaç tutabileceðini yazdýran program					printf("Kuyrugun %d saat sonraki hali: %s",T,sira);
																											}

int main() {																								Klavyeden girilen bir dizinin en büyük elemanýnýn dizinin en baþýnda, en küçük elemanýnýn ise dizinin en sonunda olmasý
    int ogrenci_sayisi,puzzle_sayisi,i,j,gecici,min;														için dizinin iki ardýþýk elemanlarý arasýnda en az kaç defa swap yapýlmasý gerektiðini yazdýran program
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
   Klavyeden girilen sayý bulunana kadar girilen tahminlerin bulunacak sayýya ne kadar								printf("Swap sayisi: %d",max_i+n-min_i-2);
   yaklaþtýðýný en yakýn tahminlerle birlikte yazdýran program													else
																													printf("Swap sayisi: %d",max_i+n-min_i-1);
int SayiyiBul(int x,int *altsinir,int *ustsinir) {															}
	int tahmin;
	scanf("%d",&tahmin);																					Bir array1 dizisini, array2 dizisiyle ortak olan elemanlarýný sildikten sonra tekrar yazdýran program
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

   Sýrayla kLavyeden girilen N, X ve K deðerleri için N elemanlý bir dizide X elemaný dizide bulunuyorsa	Klavyeden girilen kendi içinde rakamlarý farklý iki sayýnýn ortak kaç tane rakam barýndýrdýðýný yazdýran program
   X'in K kadar soluna ve saðýna uzanan kanatlarýnda bulunan komþu sayýlar X ile birlikte kendi arasýnda
   küçükten büyüðe sýralandýðýnda oluþan yeni diziyi döndüren, X elemaný dizide bulunmuyorsa diziyi			int is_Y_a_digit_in_X(int x, int y) {
   olduðu gibi döndüren program																					while(x>0) {
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
			if(dizi[j]>dizi[j+1]) {		//bubble sort, istenen sayý kabarcýk gibi en üste çýkýyor
				gecici=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=gecici;
			}
	printf("Duzenlenmis dizi: ");
	for(i=0;i<N;i++)
		printf("%d ",dizi[i]);
}

   Klavyeden girilen bir dizinin denge index'ini (sol ve sað kanatlarýndaki sayýlar toplamýnýn eþit olduðu index) döndüren Ýngilizce program */

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
