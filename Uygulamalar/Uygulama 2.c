#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* Klavyeden girilen 10 tane sayýyý küçükten büyüðe sýralayan program						Klavyeden birbirinden farklý 2 sayý girilmesini saðlayan ve bu iki sayý arasýndaki (bu iki sayý dahil) tam sayýlarýn toplamýný yazdýran program

int main() {																				int main() {
	int sayi[10],tut,i,j;																		int sayi1,sayi2,i,buyuk,kucuk,toplam=0;
	for(i=0;i<10;i++) {																			yeniden:
		printf("%d. Sayi: ",i+1);																printf("1. Sayi: ");
		scanf("%d",&sayi[i]);																	scanf("%d",&sayi1);
	}																							printf("2. Sayi: ");
	for(i=0;i<10;i++) {																			scanf("%d",&sayi2);
		for(j=0;j<10;j++) {																		if(sayi1==sayi2) {
			if(sayi[i]<sayi[j]) {																	goto yeniden;
				tut=sayi[i];																	}
				sayi[i]=sayi[j];																if(sayi1>sayi2) {
				sayi[j]=tut;																		buyuk=sayi1;
			}																						kucuk=sayi2;
		}			//swap oldu, yani sayi[i] ile sayi[j]'nin deðerleri birbiriyle deðiþti		}
	}																							else {
	printf("\nSayilarin Kucukten Buyuge Siralanisi: ");												kucuk=sayi1;
	for(i=0;i<10;i++) {																				buyuk=sayi2;
		printf("%d ",sayi[i]);																	}
	}																							for(i=kucuk;i<=buyuk;i++) {
}																									toplam=toplam+i;			//toplam+=i de yazýlabilirdi, ikisi ayný þey
//14-16. satýrlarlarý bubble sort ile þöyle deðiþtirebiliriz:									}
//for(i=0;i<9;i++) {																			printf("Toplam: %d",toplam);
//    for(j=0;j<9-i;j++) {																	}
//        if(sayi[i]>sayi[j]) { ...
//...sonra da genel kalýbý "gecici=a; a=b; b=gecici;" olan swap'ý if'in içerisine aynen implement ediyorsun

   Bir hava yolu þirketi yolcularý için bagaj sýnýrlamasý uygulamaktadýr. Her yolcunun el için 8 kg, normal için 15 kg bagaj hakký bulunmaktadýr. Eðer yolcular el haklarýný geçerse kg baþýna 4 TL, normal haklarýný
   geçerse kg baþýna 5 TL ödeme yapmak durumundadýr. Buna göre klavyeden el ve normal bagajlarýnýn kg olarak aðýrlýðýný giren yolcunun ödemesi gereken bagaj ücretini yazdýran program

int main () {
	int el,eltutar=0,normal,normaltutar=0,toplam=0;											Heybeliada'da bulunan yazýlým evi otelinde kýþýn 320 kiþi kalmýþtýr. Ýlkbaharda kýþ mevsiminin dörtte biri, yaz mevsiminde ilkbaharýn 8 katý,
	printf("El Bagaj Kg: ");																ve sonbaharda yaz mevsiminin onda biri kadar kiþi kaldýðýna göre bu otelde 1 yýl içinde toplam kaç kiþi kaldýðýný yazdýran program
	scanf("%d",&el);
	printf("Normal Bagaj Kg: ");															int main() {
	scanf("%d",&normal);																		int ilkbahar,yaz,sonbahar,kis=320;
	if(el>8) {																					ilkbahar=kis/4;  //80
		eltutar=4*(el-8);																		yaz=ilkbahar*8;  //640
	}																							sonbahar=yaz/10; //64
	if(normal>15) {																				printf("%d",ilkbahar+yaz+sonbahar+kis);
		normaltutar=5*(normal-15);															}
	}
	toplam=eltutar+normaltutar;
	printf("Toplam ucretiniz %d TL'dir, iyi yolculuklar...",toplam);
}

   10*10'luk bir çarpým tablosunu yazdýran program											Ýlk 4 mükemmel sayýyý (kendisi hariç pozitif tam bölenleri toplamý kendisini veren sayýlar) yazdýran program

int main() {																				int main() {
	int i,j;																					int x,i,toplam=0;
	for(i=1;i<=10;i++) {																		for(x=2;x<=9999;x++) {
		printf("\t%d",i);																			for(i=1;i<=x/2+1;i++) {			//a tamsayýsý için 1'den a'ya kadar olan aralýðýn ikinci yarýsýnda a'yý tam bölen bir sayý yoktur
	}																									if(x%i==0) {				//bitiþ noktasý olarak "i<=x" yazmak kodu daha geç çalýþtýrýr ve bilgisayarý yorar
	printf("\n -");																						toplam=toplam+i;
	for(i=1;i<=10;i++) {																				}
		printf("--------");																			}
	}																								if(toplam==x) {
	printf("\n");																					printf("%d ",x);
	for(i=1;i<=10;i++) {																			}
		printf("%d|\t",i);																		toplam=0;
		for(j=1;j<=10;j++) {																	}
			printf("%d\t",i*j);																}
		}
		printf("\n");
	}
}

   Ýlk 4 mükemmel sayýyý while döngüsü ve sayaç yardýmýyla yazdýran alternatif program		Ýlk 100 asal sayýyý yazdýran program

int main() {																				int main() {
	int x=2,i,toplam=0,sayac=0;																	int x=2,i,sayac1=0,sayac2=0;
	while(sayac<4) {																			while(sayac1<100) {
		for(i=1;i<=x/2+1;i++) {																		for(i=2;i<=x/2+1;i++) {
			if(x%i==0) {																				if(x%i==0) {
			toplam=toplam+i;																			sayac2++;
			}																							}
		}																							}
	if(toplam==x) {																				if(sayac2==0) {
	printf("%d ",x);																			printf("%d ",x);
	sayac++;																					sayac1++;
	}																							}
	toplam=0;																					sayac2=0;
	x++;																						x++;
	}																							}
	return 0;																					return 0;
}																							}

   Yýldýz iþaretleriyle dikey eni 8, yatay boyu ise 25 yýldýz uzunluðunda olan içi boþ bir dikdörtgen çizdiren program

int main() {																				Klavyeden girilen n tane sayýnýn aritmetik, geometrik ve harmonik ortalamalarýný yazdýran program
	int i,j;
	for(i=1;i<=8;i++) {																		int main() {
		if(i==1 || i==8) {																		double arit,geo,harm,sayi,toplam=0,carpim=1,htoplam=0;
			for(j=1;j<=25;j++) {																int i,n;
			printf("*");																		printf("Kac tane sayi gireceksiniz?: ");
			}																					scanf("%d",&n);
		}																						for(i=1;i<=n;i++) {
		else {																						printf("%d. Sayi: ",i);
			printf("*");																			scanf("%lf",&sayi);
			for(j=2;j<=24;j++) {																	toplam+=sayi;			//toplam=toplam+sayi
			printf(" ");																			carpim*=sayi;			//carpim=carpim*sayi
			}																						htoplam+=1/sayi;		//htoplam=htoplam+1/sayi
			printf("*");																		}
		}																						arit=toplam/n;
	printf("\n");																				geo=pow(carpim,1.0/n);
	}																							harm=n/htoplam;
}																								printf("\nAritmetik Ortalama: %lf\nGeometrik Ortalama: %lf\nHarmonik Ortalama: %lf",arit,geo,harm);
																							}

   a=/=0 olmak üzere ax^2+bx+c=0 biçimindeki ikinci dereceden bir denklemin klavyeden girilen a,b,c deðerlerine göre köklerini yazdýran program

int main() {																				Klavyeden girilen bir tam sayýyý asal çarpanlarýna ayýrýp yazdýran program
	double a,b,c,disk,kok1,kok2;
	printf("*****ax^2+bx+c=0 Bicimindeki Denklemleri Cozen Uygulama*****\n\n");				int main() {
	printf("a icin deger giriniz: ");															int i,sayi;
	scanf("%lf",&a);																			printf("Sayiyi giriniz: ");
	while(a==0) {																				scanf("%d",&sayi);
		printf("Lutfen a'ya 0 disinda bir deger giriniz: ");									for(i=2;sayi!=1;i++) {		//sayi deðiþkeni 1'e eþit olmadýðý sürece i tek tek artacak ve döngü devam edecek
		scanf("%lf",&a);																			if(sayi%i==0) {
	}																									sayi/=i;
	printf("b icin deger giriniz: ");																	printf("%d ",i);
	scanf("%lf",&b);																					i--;
	printf("c icin deger giriniz: ");																}
	scanf("%lf",&c);																			}
	disk=b*b-4*a*c;																			}
	printf("\n");
	if(disk>=0) {																			Klavyeden girilen satýr sayýsýna göre Floyd üçgenini (ardýþýk sayma sayýlarýnýn sola dayalý dizilmesiyle oluþan dik üçgen) çizdiren program
		kok1=(-b+sqrt(disk))/(2*a);
		kok2=(-b-sqrt(disk))/(2*a);															int main() {
		if(kok1!=kok2) {																		int i,j,satir,sayac=1;
			printf("Bu denklemin iki koku vardir.\n");											printf("Satir sayisini giriniz: ");
			printf("Kok 1: %lf\n",kok1);														scanf("%d",&satir);
			printf("Kok 2: %lf",kok2);															for(i=1;i<=satir;i++) {
		}																							for(j=1;j<=i;j++) {
		else {																							printf("%d\t",sayac);
			printf("Bu denklemin bir koku vardir.\n");													sayac++;
			printf("Cift Kok: %lf",kok1);															}
		}																							printf("\n");
	}																							}
	else {																					}
		printf("Bu denklemin reel sayilarda koku yoktur.");
	}
}

   100 ila 9999 arasýnda bulunan bütün palindromik (tersten yazýlýþ ve okunuþu ayný olan) sayýlarý alt alta yazdýran program

int main() {																				100 ila 9999 arasýndaki Armstrong sayýlarýný (rakamlarýnýn basamak sayýsý kadar kuvvetleri toplamý kendisini veren sayýlar) yazdýran program
	int i,j,k,l;
	puts("******Palindromik Sayilar******");												int main() {
	for(i=1;i<=9;i++) {																			int i,sayi,rakam,toplam=0;
		for(j=0;j<=9;j++) {																		for(i=100;i<=9999;i++) {
			for(k=0;k<=9;k++) {																		sayi=i;
				if(i==k)																			if(i/1000!=0)
				printf("%d\n",100*i+10*j+k);															while(sayi!=0) {
			}			//3 basamaklý ijk sayýsý i=k ise palindromiktir										rakam=sayi%10;
		}																									toplam+=rakam*rakam*rakam*rakam;
	}																										sayi/=10;
	for(i=1;i<=9;i++) {																					}
		for(j=0;j<=9;j++) {																			else
			for(k=0;k<=9;k++) {																			while(sayi!=0) {
				for(l=0;l<=9;l++) {																			rakam=sayi%10;
					if(i==l && j==k)																		toplam+=rakam*rakam*rakam;
					printf("%d\n",1000*i+100*j+10*k+l);														sayi/=10;
				}		//4 basamaklý ijkl sayýsý i=l VE j=k ise palindromiktir							}
			}																						if(i==toplam)
		}																								printf("%d bir Armstrong sayisidir\n",i);
	}																								toplam=0;
	return 0;																					}
}																							}

   Klavyeden girilen bir sayýnýn Armstrong sayýsý olup olmadýðýný yazdýran program			Klavyeden girilen bir kelimenin palindrom olup olmadýðýný yazdýran program

int main() {																				int main() {
	int sayi,orijinalsayi,rakam,sayac=0,toplam=0;												int i=0,j,palindrom_mu=1;	//i'yi ilk geçerli index'e eþitledim (ilk harfin index'i)
	printf("Sayi giriniz: ");																	char kelime[50];
	scanf("%d",&sayi);																			printf("Kelime yaziniz: ");
	orijinalsayi=sayi;																			scanf("%s",kelime);
	while(orijinalsayi!=0) {																	j=strlen(kelime)-1;			//j'yi son geçerli index'e eþitledim (son harfin index'i)
		orijinalsayi/=10;																		while(i<=j) {
		sayac++;		//sayaç girdiðim sayýnýn kaç basamaklý olduðunu tuttu						if(kelime[i]!=kelime[j]) {
	}																									palindrom_mu=0;
	orijinalsayi=sayi;																					break;
	while(orijinalsayi!=0) {																		}
		rakam=orijinalsayi%10;																		i++;
		toplam+=pow(rakam,sayac);																	j--;
		orijinalsayi/=10;																		}
	}																							if(palindrom_mu)
	if(toplam==sayi)																				printf("%s bir palindromdur",kelime);
		printf("%d bir Armstrong sayisidir",sayi);												else
	else																							printf("%s bir palindrom degildir",kelime);
		printf("%d bir Armstrong sayisi degildir",sayi);									}
}

   Rus köylü çarpým metodu ile klavyeden girilen 2 tam sayýnýn çarpýmýný yazdýran program

int main() {							//misal 12 ve 13 girdiðimi varsayalým
	int a,b,sonuc=0,m,n;				//1. sayý sürekli 2 ile çarpýlýrken 2. sayý sürekli 2'ye bölünür (int division, yani tam sayý bölmesiyle)
	printf("Iki tam sayi giriniz: ");	//2. sayý 1 olana kadar bu iþlem yapýlýr ve 2. sayýnýn çift olduðu satýrlar çizilir		m	n
	scanf("%d%d",&a,&b);				//çizilmemiþ satýrlardaki m deðerlerinin toplamý ise bana sonucu verir					12	13
	m=a;	//m: 1. sütundaki sayýlar	  12 * 13 = 12 + 48 + 96 = 156														  --24--6--
	n=b;	//n: 2. sütundaki sayýlar																							48	3
	while(n>0) {		//																										96	1
		if(n%2!=0)		//n sayýsý çift deðilse o satýrdaki m deðerini sonuca ekle
			sonuc+=m;
		m*=2;  // m'yi 2 ile çarp
		n/=2;  // n'yi 2'ye böl
	}
	printf("%d * %d = %d",a,b,sonuc);
}

   ELeman sayýsý ve elemanlarý klavyeden girilen bir sayý dizisinin içinde yer alan
   küçükten büyüðe olarak sýralanmýþ en uzun alt dizinin kaç elemanlý olduðunu yazdýran		Klavyeden girilen bir seneden sonra gelen en küçük rakamlarý farklý seneyi yazdýran program
   program

int main() {																				int main() {
	int n,i,sayac=1,max=1;																		int sene,rakam1,rakam2,rakam3,rakam4;
	printf("Dizinin eleman sayisi: ");															printf("Sene: ");
	scanf("%d",&n);																				scanf("%d",&sene);
	int *dizi=(int*) malloc(sizeof(int)*n);														do {
	printf("Dizinin elemanlarini giriniz: ");														sene++;
	for(i=0;i<n;i++)																				rakam4=a%10;
		scanf("%d",&dizi[i]);																		rakam3=(a/10)%10;
	for(i=0;i<n-1;i++) {																			rakam2=(a/100)%10;
		if(dizi[i]<=dizi[i+1])																		rakam1=a/1000;
			sayac++;																			} while(rakam1==rakam2 || rakam1==rakam3 || rakam1==rakam4 || rakam2==rakam3 || rakam2==rakam4 || rakam3==rakam4);
		else																					printf("Sene: %d",sene);
			sayac=1;																		}
		if(sayac>max)
			max=sayac;
	}
	printf("Kucukten buyuge sirali en uzun alt dizinin eleman sayisi: %d",max);
	return 0;
}

   Klavyeden saniye olarak girilen sayýyý sonradan klavyeden girilen karakter 'a' veya 'A'
   ise AM, 'p' veya 'P' ise PM olarak algýlayan ve "saat:dakika:saniye" biçiminde dijital	T 1 ila 10 arasýnda bir sayý olmak üzere klavyeden girilen decimal (10 tabanýndaki) bir sayýnýn T tabanýndaki gösterimindeki rakamlarý
   saat formatýnda döndüren program															toplamýnýn 10 tabanýndaki deðerini yazdýran program

int main() {																				int main() {
	int n,saat,dakika,saniye;																	int sayi,taban,rakam,toplam=0;
	char k;																						printf("Sayiyi ve cevrilecegi tabani giriniz (1<=taban<=10): ");
	printf("Sayi (0<=n<43200) ve karakter (A/a:AM   P/p: PM) giriniz: ");						scanf("%d%d",&sayi,&taban);
	scanf("%d %c",&n,&k);																		int orijinalsayi=sayi;
	saat=n/3600;																				while(sayi!=0) {
	dakika=(n/60)%60;																				rakam=sayi%taban;
	saniye=n%60;																					toplam+=rakam;
	if((k=='A' || k=='a') && 0<=n && n<43200)														sayi/=taban;
		printf("%02d:%02d:%02d",saat,dakika,saniye);											}
	if((k=='P' || k=='p') && 0<=n && n<43200) {													printf("%d'nin %d tabanindaki rakamlar toplami: %d",orijinalsayi,taban,toplam);
		saat+=12;																			}
		printf("%02d:%02d:%02d",saat,dakika,saniye);
	}
}

   Klavyeden girilen iki tam sayýyý ve bir float adresini parametre olarak alan bir
   fonksiyonbu iki tam sayýnýn ortalamasýný bu adreste depoladýðýna ve eðer ortalama tam
   sayý ise 1, deðilse 0 döndürdüðüne göre bu fonksiyon aracýlýðýyla iki tam sayýnýn		Boþluklar karakter sayýlmadýðýna göre, klavyeden girilen maksimum 1000 karakter uzunluðundaki bir katarý her satýrda bir karakter
   ortalamasýný küsuratý varsa küsuratlý, yoksa küsuratsýz yazdýran program					daha yazdýracak þekilde yazdýran ve katarýn sonuna gelindiðinde her satýrda bir karakter daha silecek bir þekilde yazdýrýlan katarý silen program

int ortbul(int a,int b,float *avr) {														int main() {
	float x1,x2;																				char *katar=(char*) malloc(1000);
	x1=(float)(a+b)/2;																			int i,j;
	x2=(a+b)/2;																					printf("Katari giriniz: ");
	*avr=x1;																					gets(katar);
	if(x1==x2)																					katar=(char*) realloc(katar,strlen(katar)+1);
		return 1;																				printf("\n");
	else																						for(i=0;i<strlen(katar);i++) {
		return 0;																					for(j=0;j<=i;j++) {
}																										if(j==i && katar[j]==' ')
int main() {																								i++;
	int x,y;																							printf("%c",katar[j]);
	float ort;																						}
	scanf("%d%d",&x,&y);																			printf("\n");
	if(ortbul(x,y,&ort))																		}
		printf("%d",(int)ort);																	for(i=strlen(katar)-2;i>=0;i--) {
	else																							for(j=0;j<=i;j++) {
		printf("%.1f",ort);																				if(j==i && katar[j]==' ')
	return 0;																								i--;
}																										printf("%c",katar[j]);
																									}
   Ayný tekrar sayýsýna sahip birden fazla mod adayý varsa bunlardan en küçüðü mod olarak			printf("\n");
   alýndýðýna göre, klavyeden girilen bir sayý dizisinin modunu (dizinin en çok tekrar			}
   eden elemaný) ve bu modun tekrar sayýsýný yazdýran program								}

int main() {																				Klavyeden sýrasýyla alt alta girilen a katarý, x deðeri, b katarý için a ve b katarlarý ile x deðeri 1 iken önce a sonra b'yi,
	int gecici,i,j,n,sayac,max=0;															x deðeri 2 iken ise önce b sonra a'yý yazdýrarak cümle kuran program
	printf("Dizinin eleman sayisini girin: ");
	scanf("%d",&n);																			int main() {
	int *dizi=(int*) malloc(sizeof(int)*n);														char a[1000],b[1000];
	printf("Dizinin elemanlarini girin: ");														int x;
	for(i=0;i<n;i++)																			gets(a);
		scanf("%d",&dizi[i]);																	scanf("%d%*c",&x);
	for(i=0;i<n;i++) {																			gets(b);
		sayac=0;																				if(x==2) {
		for(j=0;j<n;j++)																			strcat(a," ");
			if(dizi[i]==dizi[j])																	puts(strcat(a,b));
				sayac++;																		}
		if(sayac>max) {																			if(x==1) {
			max=sayac;																				strcat(b," ");
			gecici=dizi[i];																			puts(strcat(b,a));
		}																						}
		if(sayac==max)																		}
			if(dizi[i]<gecici) {
				max=sayac;																	Klavyeden girilen r ve x deðerleri için klavyeden girilen bir dizinin kendisi ile ayný permütasyondaki r elemanlý alt dizilerinin elemanlar
				gecici=dizi[i];																toplamýnýn kaç tanesinin x'e eþit olduðunu yazdýran program
			}
	}																						int main() {
	printf("Mod: %d\n",gecici);																	int i,j,r,x,N,toplam=0,sayac=0;
	printf("Tekrar sayisi: %d",max);															printf("Dizinin eleman sayisi: ");
}																								scanf("%d",&N);
																								int *dizi=(int*) malloc(N*sizeof(int));
   Klavyeden girilen elemanlarý 1 ila 10000 arasýnda deðiþen bir sayý dizisinin modunu			printf("Diziyi giriniz: ");
   ve modunun tekrar sayýsýný counter array'i (sayaç dizisi) tanýmlayarak yazdýran				for(i=0;i<N;i++)
   alternatif program																				scanf("%d",&dizi[i]);
																								for(i=0;i<N-r+1;i++) {
int main() {																						for(j=0;j<r;j++)
	int n,i,mod,max=0;																					toplam+=dizi[i+j];
	printf("Dizinin eleman sayisini girin: ");														if(toplam==x)
	scanf("%d",&n);																						sayac++;
	int *dizi=(int*) malloc(n*sizeof(int));															toplam=0;
	int *sayac=(int*) malloc(10000*sizeof(int));												}
	printf("Dizinin elemanlarini girin: ");														printf("%d elemanli alt diziler arasinda elemanlar toplami %d olanlarin sayisi: %d",r,x,sayac);
	for(i=0;i<n;i++)																		}
		scanf("%d",&dizi[i]);
	for(i=1;i<=10000;i++)																	Klavyeden isimleri girilen düzenli/düzgün çok yüzlülerin toplamda hepsinin kaç yüzü olduðunu yazdýran Ýngilizce program
		sayac[i]=0;		//sayac dizisi dizinin her bir elemanýnýn
	for(i=0;i<n;i++)	//dizide toplamda kaç defa geçtiðini tutacak						int main() {
		sayac[dizi[i]]++;																		int i,n,sum=0;
	for(i=0;i<n;i++)																			printf("Enter the number of polyhedrons: ");
		if(sayac[dizi[i]]>max || (sayac[dizi[i]]==max && mod>dizi[i])) {						scanf("%d",&n);
			max=sayac[dizi[i]];																	for(i=0;i<n;i++) {
			mod=dizi[i];																			char shape[13];
		}																							scanf("%s",shape);
	printf("Mod: %d\nTekrar sayisi: %d",mod,max);													if(strcmp(shape,"Tetrahedron")==0)			sum+=4;
}																									else if(strcmp(shape,"Cube")==0)			sum+=6;
																									else if(strcmp(shape,"Octahedron")==0)		sum+=8;
   Klavyeden girilen bir dizide bir elemanýn bulunup bulunmadýðýný, bulunuyorsa hangi				else if(strcmp(shape,"Dodecahedron")==0)	sum+=12;
   index'te veya index'lerde bulunduðunu da yazdýran program										else if(strcmp(shape,"Icosahedron")==0)		sum+=20;
																								}
int main() {																					printf("Total number of faces: %d",sum);
	int i,x,n,k=1;																			}
	printf("Dizinin eleman sayisi: ");
	scanf("%d",&n);																			Çift n deðerleri için sýrayla 2, 2^2, 2^3, 2^4, ..., 2^n kuruþluk madeni paralar n/2'lik iki gruba ayrýlacaktýr.
	int *dizi=(int*) malloc(sizeof(int)*n);													Bu iki gruptaki madeni paralarýn toplamlarý farkýnýn minimum kaç olacaðýný yazdýran program
	printf("Dizinin elemanlari: ");
	for(i=0;i<n;i++)																		int main() {
		scanf("%d",&dizi[i]);																	int t,n;
	printf("Aranacak elemani giriniz: ");														printf("Test senaryosu sayisini giriniz: ");
	scanf("%d",&x);																				scanf("%d",&t);
	for(i=0;i<n;i++)																			while(t--) {
		if(dizi[i]==x) {																			printf("Para sayisini giriniz: ");
			if(k>0) {																				scanf("%d",&n);		//tercihen 2<=n<=30 olursa iyi olur, malum INT_MAX'tan sonra overflow olur
				printf("Elemanin bulundugu index'ler: %d",i+1);										printf("Minimum fark: %d\n",(int)pow(2,n/2+1)-2);
				k--;																			}
			}		//linear search de, burada istenen eleman dizinin ayný anda				}
			else	//her yerinde olabileceði için binary search yapýlmaz zaten
				printf(" %d",i+1);
		}
		else if(i==n-1 && k==1)
			printf("Eleman bulunamadi");
}

   Klavyeden girilen bir cümlenin pangram (Latin alfabesinin her harfini içeren söz) olup olmadýðýný yazdýran program

int main() {
	char i,cumle[500],pangram_flag=1;	//pangram_flag normalde bool olarak tanýmlanýrdý, ama C'de bool deðiþkeni direkt olmadýðý için
	int j;								//pangram_flag'i bool veri tipi ile RAM'de ayný yeri kaplayan 1 byte'lýk char olarak tanýmladým
	printf("Bir cumle giriniz: ");
	gets(cumle);
	for(i='a';i<='z' && pangram_flag;i++)
		for(j=0;j<strlen(cumle);j++) {
			if(cumle[j]==i || cumle[j]==i-32)		//'a'-'A'=32
				break;			//küçük ya da büyük harf olan i char'ý kelimede varsa 2. (j) for döngüsünden çýk, boþ yere cümlenin kalan harflerini tarama
			else if(j==strlen(cumle)-1)
				pangram_flag=0;	//son harfe kadar gelinip halen döngüden çýkýlmamýþsa, bu cümlede i char'ý bulunmadýðý için bu cümle bir pangram deðildir
		}
	printf(pangram_flag ? "\"%s\" bir pangram" : "\"%s\" bir pangram degil", cumle);
	return 0;
}

   Sefer baþýna bir biletin kullanýldýðý bir otobüs yolculuðu için giþeden a TL'ye bir bilet veya b TL'ye topluca m tane bilet
   alýnabilmektedir. Bu deðerler ile kiþinin toplam yapacaðý sefer sayýsý klavyeden girileceðine göre, n defa sefer yapacak
   birinin tüm yolculuðunu en az kaç TL'ye getirebileceðini yazdýran program

int main() {
	unsigned int n,m,a,b,sum=0;
	printf("Sefer sayisini giriniz: "); scanf("%u",&n);
	printf("Toplu biletlerin sayisini giriniz: "); scanf("%u",&m);
	printf("Tek biletin ve toplu biletlerin fiyatini TL cinsinden giriniz: "); scanf("%u%u",&a,&b);
	if(b/m<a) {
		if((n%m)*a>b)
			sum=ceil((double)n/m)*b;
		else
			sum=(n/m)*b+(n%m)*a;
	}
	else
		sum=n*a;
	printf("Minimum tutar: %u TL",sum);
}

   x+2x+4x+8x+...+(2^(k-1))*x serisinin toplamý klavyeden girileceðine göre bu seri toplamýný saðlayan x ve k>1 pozitif tam sayý ikililerini yazdýran program */

int main() {
	unsigned int i,n,flag=1;
	printf("x+2x+4x+8x+...+(2^(k-1))*x serisinin toplamini giriniz: ");
	scanf("%u",&n);
	printf("\nx+2x+4x+8x+...+(2^(k-1))*x = %u denklemini saglayan k ve x degerleri:\n\n",n);
	for(i=2;(unsigned int)pow(2,i)-1<=n;i++)			//k 1'den büyük olmasý gerektiði için i 2'den baþlýyor, ve i burada k'yý temsil ediyor
		if(fmod(n,(unsigned int)pow(2,i)-1)==0.0) {		//x+2x+4x+8x+...+(2^(k-1))*x = (1+2+4+8+...+2^(k-1))*x = ((2^k)-1)*x = n
			printf("k = %u , x = %u\n",i,n/((unsigned int)pow(2,i)-1));
			flag=0;			//eðer n deðeri (2^k)-1 deðerine tam bölünürse denklemi saðlayan pozitif k ve x tam sayý deðerleri var demektir
		}					//eðer tek bir k,x ikilisi yazdýrmak isteseydim "break" komutunu eklerdim
	if(flag)
		puts("Bu denklemi saglayan herhangi bir k,x ikilisi yok, zaa");
	return 0;
}
