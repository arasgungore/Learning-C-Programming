#include <stdio.h>
#include <stdlib.h>

/* Klavyeden girilen sayýnýn asal olup olmadýðýný yazdýran program										Aþaðýdaki programýn çýktýsý

int main() {																							int main() {
	int sayi,i,sayac=0;																						int a=5,b=4,c=1,i;
	printf("Sayi: ");																						a=b*a+c-4;				//a deðiþkeninin yeni deðeri a=5*4+1-4 ==> a=17
	scanf("%d",&sayi);																						b=c*a+2;				//b deðiþkeninin yeni deðeri b=1*17+2 ==> b=19
	for(i=2;i<sayi;i++) {																					for(i=0;i<=3;i++) {
		if(sayi%i==0) {																							c=c+1				//döngü sonunda c deðiþkeninin yeni deðeri c=1+1+1+1+1 ==> c=5
			sayac++;																						}
		}																									int toplam=a+b+c;
	}																										printf("%d",toplam);	//çýktý toplam=17+19+5 ten ==> toplam="41"
	if(sayac==0) {																						}
		if(sayi==1) {
			printf("\n%d asal bir sayi degildir",sayi);													Klavyeden girilen sayýnýn küpünü yazdýran program
		}
		if(sayi!=1) {																					int main() {
			printf("\n%d asal bir sayidir",sayi);															int sayi,kup;
		}																									printf("Sayi: ");
	}																										scanf("%d",&sayi);
	else {																									kup=sayi*sayi*sayi;
		printf("\n%d asal bir sayi degildir",sayi);															printf("Sayinin Kupu: %d",kup);
	}																									}
}

   Üç basamaklý rakamlarý birbirlerinden farklý toplam kaç tane sayý olduðunu yazdýran program			Bir bakteri türü her saat baþý kendini ikiye bölerek çoðalýyorsa, bu laboratuvarda 24 saat sonra kaç tane bakteri olduðunu yazdýran program

int main () {																							int main() {
	int yuzler,onlar,birler,i,sayac=0;																		int bakteri=1,i;
	for(i=100;i<=999;i++) {																					for(i=1;i<=24;i++) {
		yuzler=i/100;																							bakteri=bakteri*2;
		onlar=(i/10)%10;																					}
		birler=i%10;																						printf("%d",bakteri);
		if(yuzler!=onlar && onlar!=birler && yuzler!=birler) {											}
			sayac++;
		}
	}
	printf("%d",sayac);
}

   Klavyeden girilen sayýnýn tam bölenlerini yazdýran program											Klavyeden 4 tane tam sayý alýp bunlarýn toplamýný yazdýran program

int main() {																							int main() {
	int sayi,i;																								int sayi,i,toplam=0;
	printf("Sayi: ");																						for(i=1;i<=4;i++) {
	scanf("%d",&sayi);																							printf("%d. Sayi: ",i);
	for(i=1;i<=sayi;i++) {																						scanf("%d",&sayi);
		if(sayi%i==0) {																							toplam=toplam+sayi;
			printf("%d\n",i);																				}
		}																									printf("Toplam: %d",toplam);
	}																									}
}

   Bir otopark þirketinde ücretlendirme 0-4 saat arasý 10 TL, 5-8 saat arasý 12 TL, 9-12 saat
   arasý 15 TL ve 13 saat üstünde 18 TL olduðuna göre, klavyeden kaç saat kaldýðý girilen aracýn
   ödemesi gereken tutarý yazdýran program																Klavyeden 0 girilene kadar girilen bütün sayýlarý toplayan program

int main() {																							int main() {
	int saat;																								int sayi,toplam=0;
	printf("Otoparkta kac saat kaldiginizi giriniz: ");														while(sayi!=0) {
	scanf("%d",&saat);																							printf("Sayi: ");
	switch(saat) {																								scanf("%d",&sayi);
		case 0: case 1: case 2: case 3: case 4:printf("\n10 TL odemeniz gerekmektedir"); break;					toplam=toplam+sayi;
		case 5: case 6: case 7: case 8:printf("\n12 TL odemeniz gerekmektedir"); break;						}
		case 9: case 10: case 11: case 12:printf("\n15 TL odemeniz gerekmektedir"); break;					printf("Toplam: %d",toplam);
		default:printf("\n18 TL odemeniz gerekmektedir");												}
	}
}

   1+5+9+13+...+81 serisinin toplamýný yazdýran program													Klavyeden girilen 6 basamaklý bir sayýnýn rakamlarý toplamýný yazdýran program

int main() {																							int main() {
	int i,toplam=0;																							int sayi,a,b,c,d,e,f,toplam;
	for(i=1;i<=81;i+=4) {																					printf("Sayi: ");
		toplam=toplam+i;																					scanf("%d",&sayi);
	}																										a=sayi/100000;
	printf("Toplam: %d",toplam);																			b=(sayi/10000)%10;
}																											c=(sayi/1000)%10;
																											d=(sayi/100)%10;
   n tane kiþi arasýndan 3 kiþilik bir takým kurulup bu takým bir yetenek yarýþmasýna katýlacaktýr.			e=(sayi/10)%10;
   Ayný yarýþmacýlar yarýþmaya en fazla 5 defa katýlabildiðine göre, klavyeden mevcut katýlým				f=sayi%10;
   sayýlarý girilen kiþiler arasýndan kaç farklý takým kurulabileceðini yazdýran program					toplam=a+b+c+d+e+f;
																											printf("Rakamlar Toplami: %d",toplam);
int main() {																							}
	int i,n,k,sayac=0,x;
	printf("Katilimci sayisini ve kurulacak takimin kac defa katilacagini giriniz: ");					Klavyeden girilen a, b, c tam sayý deðerleri için a ve b arasýndaki sayýlarýn kareleri arasýndan
	scanf("%d%d",&n,&k);																				c'den büyük olanlarýnýn sayýsý ile c'den küçük olanlarýnýn sayýsýnýn farkýný bulup yazdýran program
	for(i=1;i<=n;i++) {
		printf("%d. katilimcinin katilim sayisini giriniz: ",i);										int main() {
		scanf("%d",&x);																						int i,a,b,c,sayac1=0,sayac2=0;
		if(5>=k+x)																							printf("a, b, c degerlerini giriniz: ");
			sayac++;																						scanf("%d%d%d",&a,&b,&c);
	}																										for(i=a;i<=b;i++) {
	printf("Sadece bir bolumlemeyle olusturulabilecek maksimum farkli takim sayisi: %d", sayac/3);				if(i*i>c)
	printf("Toplam olusturulabilecek farkli takimlarin sayisi: %d", sayac*(sayac-1)*(sayac-2)/6);					sayac1++;
}								//sayac'ýn 3'lüsü ( C(sayac,3) = sayac*(sayac-1)*(sayac-2)/3! )					if(i*i<c)
																													sayac2++;
																											}
																											printf("Sonuc: %d",sayac1-sayac2);
																										}

   Bir futbol takýmýnýn 10 haftalýk maç istatistikleri þu dizide verilmiþtir:	2	1	0	0	2	1	1	2	1	0
   Bu dizide 2'ler galibiyetleri, 1'ler maðlubiyetleri, 0'lar ise beraberlikleri belirtmektedir. Bu ligde galibiyetlere 3 puan, maðlubiyetlere 0 puan, beraberliklere de 1 puan verilecektir.
   Bu takýmýn küme düþmemesi için 12 puan almasý gerekmektedir. Verilenlere göre, bu takýmýn 10 hafta sonunda küme kalýp kalmadýðýný puaný ile birlikte yazdýran program

int main() {																							Klavyeden girilen herhangi bir doðal sayýyý tersten yazdýran program
	int skor[10]={2,1,0,0,2,1,1,2,1,0},puan=0,i;
	for(i=0;i<10;i++) {																					int main() {
		if(skor[i]==2) {																					int sayi,rakam;
			puan=puan+3;																					printf("Sayiyi giriniz: ");
		}																									scanf("%d",&sayi);
		if(skor[i]==0) {																					printf("Sayinin tersi: ");
			puan=puan+1;																					while(sayi>=10) {
		}																										rakam=sayi%10;
	}																											printf("%d",rakam);
	printf("Aldiginiz Puan: %d\n",puan);																		sayi=sayi/10;
	if(puan>=12) {																							}
		printf("Ligde kaldiniz");																			printf("%d",sayi);
	}																									}
	else {
		printf("Maalesef ligden dustunuz");
	}
}

   4'ün katý olan yýllar 100'ün katý deðilse kesinlikle artýk yýl iken 100'ün katý olan yýllar 400'ün
   katý deðilse kesinlikle artýk yýl deðildir. 4'ün katý olmayan yýllar ise kesinlikle artýk yýl		Klavyeden sýrayla bir ayda sattýðý araba sayýsý, sattýðý arabalarýn ortalama fiyatý ve aldýðý komisyon oraný yüzde
   olmadýðýna göre, klavyeden girilen yýlýn artýk yýl olup olmadýðýný yazdýran program					olarak girilen bir araba satýcýsýnýn bir aylýk kazancýný virgülden sonraki 2 haneyle birlikte yazdýran program

int main() {																							int main() {
	unsigned int yil;	//ayný kural hem M.Ö. (-) hem de M.S. (+) seneler için geçerli olduðundan			unsigned int araba,fiyat,komisyon;
	printf("Yili giriniz: ");	//unsigned ile M.Ö. (-) tarihleri bellekte M.S. (+) tutup					float kazanc;
	scanf("%d",&yil);			//negatif yýllarýn mutlak deðeriyle iþlem yapabilirim						printf("Sirayla satilan araba sayisini, ortalama fiyati ve komisyon oranini giriniz: ");
	if(yil%4==0) {																							scanf("%d%d%d",&araba,&fiyat,&komisyon);
		if(yil%100==0) {																					kazanc=(float)araba*fiyat*komisyon/100;
			if(yil%400==0)																					printf("Aylik kazanc: %.2f",kazanc);
				printf("\n%d artik bir yildir",yil);													}
			else
				printf("\n%d artik bir yil degildir",yil);												Klavyeden ilk 'B' veya 'b' girilirse sonraki girilecek 2 sayýdan büyük olaný, 'K' veya 'k' girilirse sonraki girilecek 2
		}																								sayýdan küçük olaný, eðer baþka bir karakter girilirse veya 2 sayý da eþitse sonraki girilecek 2 sayýnýn toplamýný
		else																							yazdýran program
			printf("\n%d artik bir yildir",yil);
	}																									int main() {
	else																									char harf;
		printf("\n%d artik bir yil degildir",yil);															int a,b,buyuk,kucukveyaesit;
}																											printf("1 harf ve 2 sayi giriniz: ");
																											scanf("%c%d%d",&harf,&a,&b);
   Bir markette bulunan ürünler aþaðýdaki numaralar ile kodlanmýþtýr:										if(a>b)
   100    91    22    52    71    9    11    24    2    80														buyuk=a;
   Buna göre, klavyeden ürün numarasý girilen ürünün markette bulunup bulunmadýðýný yazdýran program		else
																												kucukveyaesit=b;
int main() {																								if((harf=='B' || harf=='b' || harf=='K' || harf=='k') && kucukveyaesit!=a)
	int urunler[10]={100,91,22,52,71,9,11,24,2,80},urunno,bulundumu=0,i;										if(harf=='B' || harf=='b')
	printf("Aranacak urunun kodunu giriniz: ");																		printf("Cikti: %d",buyuk);
	scanf("%d",&urunno);																						else
	for(i=0;i<10;i++) {																								printf("Cikti: %d",kucukveyaesit);
		if(urunno==urunler[i]) {																			else
			bulundumu=1;																						printf("Cikti: %d",a+b);
			break;																						}
		}
	}	//linear search, ileride bunu çok daha verimli bir þekilde "binary search" ile yapmayý öðreneceðiz
	if(bulundumu)
		printf("%d no'lu urun bulundu",urunno);
	else
		printf("%d no'lu urun bulunamadi",urunno);
}

   Klavyeden girilen meblaðý sýrayla 200, 100, 50, 20, 10 ve 5 TL'lik banknotlara, kalaný da 1 TL'lik madeni paralara ayýran program

int main() {
	int adet,meblag,nominal_degerler[7]={200,100,50,20,10,5,1},i;
	printf("Meblagi girin: ");
	scanf("%d",&meblag);
	printf("\nadet\t*\tbanknot\t=\ttutar\n***************************************\n");
	for(i=0;i<7;i++) {
		adet=meblag/nominal_degerler[i];
		if(adet) {			//adet=0 ise if yapýsýndaki kod çalýþmaz ( if(0)=if(false) ), diðer deðerler için çalýþýr ( if(!0)=if(true) )
			meblag=meblag%nominal_degerler[i];		//kalan meblað
			printf("%d\t*\t%d\t=\t%d\n",adet,nominal_degerler[i],adet*nominal_degerler[i]);
		}
	}
}

   Satýr sayýsýna göre slash iþaretleri ile þimþek resmi çizdiren program								t1 (saat) süresince v1 (km/h), t2 (saat) süresince v2 (km/h), t3 (saat) süresince v3 (km/h) hýzýyla gitmiþ bir
																										arabanýn (t1+t2+t3) zaman aralýðýndaki ortalama hýzýný virgülden sonraki 4 haneye kadar km/h cinsinden yazdýran program
int main() {
	int satir,i,j;																						int main() {
	printf("Satir sayisini giriniz (3'un kati olsun): ");													double t1,v1,t2,v2,t3,v3,OrtHiz;
	scanf("%d",&satir);																						printf("Sirayla v1,t1,v2,t2,v3,t3 degerlerini giriniz: ");
	printf("\n");																							scanf("%lf%lf%lf%lf%lf%lf",&v1,&t1,&v2,&t2,&v3,&t3);
	for(i=0;i<satir/3;i++) {																				OrtHiz=(v1*t1+v2*t2+v3*t3)/(t1+t2+t3);
		for(j=0;j<i;j++)	//satýr no kadar boþluk															printf("Ortalama Hiz: %.4f",OrtHiz);
			printf(" ");																				}
		printf("\\ \n");
	}		//ters slash iþareti sorun yarattýðý için baþýna bir tane daha ters slash koydum			Bir þehrin metro ulaþýmý için ücret tarifesi þu tablodaki gibidir:
	for(i=satir/3;i<2*satir/3;i++) {		//yani "//" aslýnda "/" yazdýrýyor										Giriþ ücreti	1. aktarma		2. aktarma		3. veya daha fazla aktarma
		for(j=0;j<i;j++)																				Öðrenci:	1.25 TL			0.55 TL			0.50 TL			0.45 TL
			printf(" ");	//satýr no kadar boþluk														Tam:		2.60 TL			1.85 TL			1.40 TL			0.90 TL
		printf("\\");																					Klavyede ilk girilen 'O' veya 'o' harfi kiþinin öðrenci ücreti, 'T' veya 't' harfi ise tam ücret ödeyeceðini gösterirken sonra
		for(j=0;j<4*satir/3-2*(i+1);j++)	//2*satir/3,2*satir/3-2,2*satir/3-4,...,2,0 tane boþluk		girilen deðer o kiþinin yaptýðý sefer sayýsý olduðuna göre, bu kiþinin toplam ödemesi gereken tutarý yazdýran program
			printf(" ");
		printf("/");																					int main() {
		for(j=0;j<2*i-2*satir/3;j++)	//0,2,...,2*satir/3-4,2*satir/3-2,2*satir/3 tane boþluk				int sefer; float tutar=0.00; char kisi;				//statement'lar ';' ile bittiði sürece diðer programlama
			printf(" ");																					printf("Ogrenci/Tam ve sefer sayisini giriniz: ");	//dillerinin aksine ayný satýra yazýlabilir
		printf("\\ \n");																					scanf("%c%d",&kisi,&sefer);
	}																										if(kisi=='O' || kisi=='o') {
	for(i=2*satir/3;i<satir;i++) {																				if(sefer>=1)
		for(j=0;j<2*satir/3+i;j++)		//4*satir/3,4*satir/3+1,4*satir/3+2,...,5*satir/3 tane boþluk				tutar+=1.25;
			printf(" ");																						if(sefer>=2)
		printf("\\ \n");																							tutar+=0.55;
	}																											if(sefer>=3)
}																													tutar+=0.50;
																												while(sefer>=4) {
   Collatz dizisi bir n sayýsýndan baþlayarak eðer bir terim çift ise sonraki terim onun yarýsý,					tutar+=0.45; sefer--;
   tek ise sonraki terim onun 3 katýnýn 1 fazlasý olacak þekilde ilerleyip dizinin son terimi 1					}
   olduðunda biten dizi olarak tanýmlandýðýna göre, bu Collatz dizisini klavyeden girilen bir				}
   n sayýsý için yazdýran program																			if(kisi=='T' || kisi=='t') {
																												if(sefer>=1)
int main() {																										tutar+=2.60;
	int n;																										if(sefer>=2)
	printf("Birinci terimi giriniz: ");																				tutar+=1.85;
	scanf("%d",&n);																								if(sefer>=3)
	printf("Collatz dizisi: %d",n);																					tutar+=1.40;
	while(n!=1) {																								while(sefer>=4) {
		if(n%2==0) {																								tutar+=0.90; sefer--;
			n=n/2;																								}
			printf(" %d",n);																				}
		}																									printf("Tutar: %.2f TL",tutar);
		else {																							}
			n=3*n+1;
			printf(" %d",n);
		}
	}
}

   Son girilen sayý -1 olana kadar klavyeden sayý deðeri girdisi alan ve girilen sayýlardan sýralamada	Bir dizinin en sonundaki elemaný baþa, diðer elemanlarý da bir saða kaydýrýlýyorsa o dizi bir saða döndürülmüþ oluyor.
   kendisinden bir önceki ve bir sonraki sayýlardan büyük olan sayýlarý sýrayla döndüren program		Buna göre, küçükten büyüðe sýralý bir dizinin k defa saða döndürülmüþ hali klavyeden girilen ve bu diziyi eski haline
																										getirmek için kaç defa sola döndürülmesi gerektiðini yazdýran program
int main() {
	int n,a,b;																							int main() {
	printf("Sayi dizisi giriniz (-1 ile bitiriniz): ");														int i,n,min=1000000,min_index,rotasyon_sayisi;
	scanf("%d",&n);																							printf("Dizinin eleman sayisini giriniz: ");
	a=n;																									scanf("%d",&n);
	scanf("%d",&n);																							int dizi[n];		//aslýnda "int *dizi=(int*) malloc(sizeof(int)*n)" yapýsý kullanýlmalý ama neyse
	b=n;																									printf("Diziyi giriniz: ");
	printf("Komsusu olan sayilardan buyuk olan sayilar: ");													for(i=0;i<n;i++) {
	while(scanf("%d",&n)) {																						scanf("%d",&dizi[i]);
		if(b>n && b>a)																							if(dizi[i]<min) {
			printf("%d ",b);																						min=dizi[i];
		a=b;																										min_index=i;
		b=n;																									}
		if(n==-1)																							}
			break;																							rotasyon_sayisi=min_index;
	}																										printf("Rotasyon sayisi: %d",rotasyon_sayisi);
	return 0;																							}
}

   Klavyeden girilen bir sayý ve bir karakterden oluþan girdiye göre ortasý düþey þeritli,
   içi boþ baklava çizdiren program																		Klavyeden girilen satýr sayýsýna göre yýldýz iþaretleri ile çanak resmi çizdiren program

int main() {																							int main() {
	int i,j,N; char sym;																					int satir,i,j;
	printf("Girdi: ");																						printf("Satir sayisi giriniz: ");
	scanf("%d%c",&N,&sym);																					scanf("%d",&satir);
	for(i=1;i<=N;i++) {																						printf("\n");
		for(j=1;j<=N-i;j++)																					for(i=0;i<=satir;i++) {
			printf(" ");																						if(i!=satir) {
		printf("/");																								for(j=0;j<i;j++)
		for(j=1;j<i;j++)																								printf(" ");
			printf(" ");																							printf("*");
		printf("%c",sym);																							for(j=0;j<3*satir-2*(i+1);j++)
		for(j=1;j<i;j++)																								printf(" ");
			printf(" ");																							printf("*\n");
		printf("\\\n");																							}
	}																											else {
	for(i=N;i>=1;i--) {																								for(j=0;j<i;j++)
		for(j=1;j<=N-i;j++)																								printf(" ");
			printf(" ");																							for(j=0;j<i;j++)
		printf("\\");																									printf("*");
		for(j=1;j<i;j++)																						}
			printf(" ");																					}
		printf("%c",sym);																				}
		for(j=1;j<i;j++)
			printf(" ");
		printf("/\n");
	}
}

   n tane takýmýn olduðu bir turnuvada n*(n+1) tane maç yapýlacaktýr. Her takým, kendi memleketinde
   oynadýðý maçlarda ayrý forma, deplasmanda oynadýðý maçlarda ayrý forma giyecektir. Bu takýmlarýn		Klavyeden girilen n tane sayýdan -1'ler zamanla iþlenen suç sayýsýný, pozitif sayýlar ise sonradan eklenen
   giyeceði ev sahibi ve konuk formalarý tam sayýlarla ifade edilip klavyeden girileceðine göre,		mevcut polis sayýsýný ifade etmektedir. Her iþlenen suç için olay yerine bir polis gideceðine ve baþka suçlarla
   turnuvada iki takýmýn da ayný formayý giydiði toplam kaç maç yapýldýðýný yazdýran program			ilgilenemeyeceðine göre, göz ardý edilmiþ suçlarýn sayýsýný yazdýran program

int main() {																							int main() {
	int takim_sayisi,i,j,sayac=0;																			int i,n,police_officers=0,untreated_crimes=0;
	printf("Turnuvadaki takim sayisini giriniz: ");															printf("n degerini giriniz: ");
	scanf("%d",&takim_sayisi);																				scanf("%d",&n);
	int takimlar[takim_sayisi][2];																			printf("Suclari ve eklenen polis sayilarini giriniz: ");
	for(i=0;i<takim_sayisi;i++) {																			for(i=0;i<n;i++) {
		printf("%d. takimin ev sahibi ve konuk formalarini giriniz: ",i+1);										int x;
		scanf("%d %d",&takimlar[i][0],&takimlar[i][1]);															scanf("%d",&x);
	}																											if(x>=0)
	for(i=0;i<takim_sayisi;i++)																						police_officers+=x;
		for(j=i+1;j<takim_sayisi;j++) {																			else {
			if(takimlar[i][0]==takimlar[j][1])																		if(police_officers<1)
				sayac++;																								untreated_crimes++;
			if(takimlar[j][0]==takimlar[i][1])																		else
				sayac++;																								police_officers--;
		}																										}
	printf("Turnuvada ayni formalarin giyildigi mac sayisi: %d",sayac);										}
}																											printf("Goz ardi edilen suc sayisi: %d",untreated_crimes);
																										}

   Klavyeden girilen iç açý deðerine sahip bir düzgün çokgenin var olup olmadýðýný yazdýran program		Klavyeden girilen bir sayýnýn pronik sayý (iki ardýþýk tam sayýnýn çarpýmý biçiminde
																										yazýlabilen sayýlar) olup olmadýðý yazdýran, ve eðer pronik ise hangi iki ardýþýk tam
int main() {																							sayýnýn çarpýmý olduðunu, deðilse pozitif tam sayý bölenlerinin toplamýný döndüren program
	int i,j,t;
	double array[361];		//maksimum 360 kenara kadar													int main() {
	for(i=3;i<=360;i++)																						int n,i,toplam=0;
		array[i] = 180 - (double)360/i;																		printf("Sayiyi girin: ");
	printf("Test senaryosu sayisini giriniz: ");															scanf("%d",&n);
	scanf("%d",&t);																							for(i=1;i<=n;i++) {
	for(i=1;i<=t;i++) {																							if(n%i==0)
		double x;																									toplam+=i;
		printf("\n%d. senaryo icin bir ic aci degeri giriniz: ",i);												if(n==i*(i+1)) {
		scanf("%lf",&x);																							printf("%d pronik bir sayidir.\n%d=%d*%d",n,n,i+1,i);
		for(j=3;j<=360;j++)																							break;
			if(x==array[j]) {																					}
				printf("%lf ic acili bir duzgun cokgen vardir ve %d kenarlidir.\n",x,j);						else if(i==n)
				break;																								printf("%d pronik bir sayi degildir.\nToplam: %d",n,toplam);
			}																								}
			else if(j==360)																				}
				printf("%lf ic acili bir duzgun cokgen yoktur.\n",x);
	}
}

   0 yazýldýðýnda girdi almayý býrakan ve ilk girilen 0'a kadar okunan (0 hariç) sayý dizisindeki tek sayýlar fazla ise bu dizideki tek sayýlarý,
   çift sayýlar fazla ise bu dizideki çift sayýlarý, ikisi de eþit sayýda ise bütün diziyi sýrayla yazdýran program

int main() {																							Klavyeden ardýþýk ikili harf permütasyonlarýnýn birleþimi olarak girilen þifrelenmiþ katarlarý
	int a,i=0,j=0,k=0,l,cift[100],tek[100],hepsi[100];													(mesela "asdf"ýn þifrelenmiþ hali: 'as' + 'sd' + 'df' = "assddf") deþifre edip yazdýran program
	printf("Diziyi giriniz (0 son): ");
	while(scanf("%d",&a) && a!=0) {																		int main() {
		if(a%2==0)																							int t;
			cift[i++]=a;																					printf("Katar sayisini giriniz: ");
		else																								scanf("%d%*c",&t);
			tek[j++]=a;																						while(t--) {
		hepsi[k++]=a;																							char katar[101];
	}																											printf("Sifrelenmis katar: ");
	printf("Yeni dizi: ");																						gets(katar);
	if(i==j)																									int i,j;
		for(l=0;l<k;l++)																						for(i=0;katar[i];i++)				//katar[i]!='\0' ile ayný condition
			printf("%d ",hepsi[l]);																					if(katar[i+1]==katar[i+2])		//katarlar NULL ('\0') ile bittiði için NULL'a eriþince döngüden çýk
	else if(i>j)																										for(j=i+1;katar[j];j++)
		for(l=0;l<i;l++)																									katar[j]=katar[j+1];	//left shift array
			printf("%d ",cift[l]);																				printf("Desifre edilmis katar: %s\n",katar);
	else																									}
		for(l=0;l<j;l++)																				}
			printf("%d ",tek[l]);
}

   Klavyeden girilen en ve boy uzunluklarýna göre bir yýlan resmi çizdiren program						Klavyeden en ve boy uzunluklarý girilen iki eþ dikdörtgenin sýðabileceði en küçük alanlý karenin alanýný yazdýran program

int main() {																							int main() {
	int i,j,n,m;																							int a,b;
	printf("Sirayla en ve boy uzunluklarini giriniz: ");													printf("Dikdortgenlerin en ve boy uzunluklarini giriniz: ");
	scanf("%d%d",&n,&m);																					scanf("%d%d",&a,&b);
	for(i=0;i<n;i++) {																						int min = a<b ? a : b, max = a>b ? a : b;
		if(i%2==0)																							printf("Karenin alani: %d", 2*min>max ? 4*min*min : max*max);
			for(j=0;j<m;j++)																			}
				printf("#");
		else {																							Klavyeden girilen a, b ve n sayýlarý için, a'ya b veya b'ye a eklenerek en az kaç hamlede n sayýsýnýn geçilebileceðini yazdýran program
			if(i%4==3)
				printf("#");																			int main() {
			for(j=0;j<m-1;j++)																				int a, b, n, ctr=0;
				printf(".");																				printf("Sirayla a, b ve n sayilarini giriniz: ");
			if(i%4==1)																						scanf("%d%d%d",&a,&b,&n);
				printf("#");																				while(a<=n && b<=n) {
		}																										if(a>b)	b+=a;
		printf("\n");																							else	a+=b;
	}																											ctr++;
}																											}
																											printf("%d, %d'yi %d hamlede gecti", a>n ? a : b, n, ctr);
																										}

   Þahika Haným son moda elbiseyi almak üzere belli maðazalara gidecektir ve bu maðazalarýn her birinde bu elbise farklý fiyatlara satýlmaktadýr.
   Her gün farklý bir kredi kartýyla alýþveriþ yapan Þahika Haným'ýn bakiyesine göre her gün en fazla kaç maðazadan bu elbiseyi satýn alabileceðini yazdýran program

int main() {
	int i, j, magaza_sayisi, gun_sayisi, magazalar[1000001]={0};
	printf("Piyasadaki magaza sayisi: ");
	scanf("%d",&magaza_sayisi);
	printf("Sirayla magazalardaki elbise fiyatlari: ");
	for(i=0;i<magaza_sayisi;i++) {
		scanf("%d",&j);
		magazalar[j]++;
	}
	for(i=1;i<100001;i++)
		magazalar[i] += magazalar[i-1];
	printf("Sahika Hanim'in alisveris yapacagi gun sayisi: ");
	scanf("%d", &gun_sayisi);
	for(i=1;i<=gun_sayisi;i++) {
		printf("Sahika Hanim'in %d. gunku bakiyesi: ", i);
		scanf("%d",&j);
		printf("Sahika Hanim'in %d. gun bu elbiseyi alabilecegi %d magaza var.\n", i, magazalar[j<=100000 ? j : 100000]);
	}
}

   Çekmecesinde n tane çift çorabý bulunan Aras'a, annesi m. günün sonunda çekmecesine yeni bir çift çorap koymaktadýr. Aras gün boyunca
   kullandýðý çoraplarý günün sonunda kirli sepetine attýðýna göre ve ertesi günün sabahýnda yeni bir çift çorap giydiðine göre, Aras'ýn
   çoraplar tükenmeden en fazla kaç gün çorapla idare edebileceðini yazdýran program

int main() {
	int n,m;
	printf("Corap cifti sayisini ve yeni corap gununu giriniz: ");
	scanf("%d%d",&n,&m);		//bu arada m'nin deðeri lütfen 1 olmasýn, yoksa infinite loop'a girer
	int x=n,y=m;
	while(1) {
		if(x>=y)
			x++;
		else
			break;
		y+=m;
	}
	printf("Coraplarla idare edilen gun sayisi: %d",x);
}

   Klavyeden girilen diziler ve x deðeri için, diziden rastgele seçilen ve aralarýndaki fark x'den büyük olmayan eleman çiftinden küçük eþit
   olan elemaný mevcut diziden çýkarma iþlemini sürekli tekrar ede ede dizinin tek bir elemana indirgenip indirgenemeyeceðini yazdýran program

int main() {
	int t,x;
	printf("Test senaryosu sayisini ve x degerini giriniz: ");
	scanf("%d%d",&t,&x);
	while(t--) {
		int n,flag=1;
		printf("Dizinin eleman sayisini giriniz: ");
		scanf("%d",&n);
		int array[n],i,j;
		printf("Diziyi giriniz: ");
		for(i=0;i<n;i++)
			scanf("%d",&array[i]);
		for(i=0;i<n-1;i++)			//bubble sort
			for(j=0;j<n-i-1;j++)
				if(array[j]>array[j+1]) {
					int temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}
		for(i=0;i<n-1;i++)
			if(abs(array[i]-array[i+1])>x) {
				flag=0;
				break;
			}
		puts(flag ? "Evet, dizi 1 elemana indirgenebilir." : "Hayir, dizi 1 elemana indirgenemez.");
	}
}

   Bir dizinin bütün elemanlarý index'leriyle ayný teklik-çiftlik durumuna sahipse o diziye iyi dizi denmektedir. Buna göre,
   klavyeden girilen bir diziyi iyi dizi yapmak için elemanlarý arasýnda en az kaç swap yapýlmasý gerektiðini yazdýran program

int main() {
	int n,tek_elemanlar=0,cift_elemanlar=0;			//iyi olmayan bir dizinin hatalý index'lerinde tek index'ler kadar çift eleman, çift index'ler kadar da tek eleman vardýr
	printf("Dizinin eleman sayisini giriniz: ");	//dolayýsýyla bir dizinin iyi dizi, yani her tek elemanýn tek index'te, her çift elemanýn da çift index'te olabilmesi için
	scanf("%d",&n);									//tek elemanlarýn sayýsýnýn çift elemanlarýn sayýsýna eþit olmasý lazým
	int array[n],i;
	printf("Diziyi giriniz: ");
	for(i=0;i<n;i++) {
		scanf("%d",&array[i]);
		if(i%2!=array[i]%2)
			array[i]%2 ? tek_elemanlar++ : cift_elemanlar++;
	}								//eðer dizinin iyi dizi olmasý mümkün deðilse -1 yazdýrýr
	printf("Yapilmasi gereken swap sayisi: %d", tek_elemanlar==cift_elemanlar ? tek_elemanlar : -1);
}

   9 uzunluklu katarlar arasýndan kaçýnýn "10101" örüntüsünü içerdiðini hesaplayan program

int main() {
	int string[9] = {0}, i, j, ctr=0;
	for(i=0;i < 1<<9;i++) {
		for(j=0;j<9;j++)
			printf("%d", string[j]);
		for(j=8;j>3;j--)
			if(string[j] && !string[j-1] && string[j-2] && !string[j-3] && string[j-4]) {
				printf(" -> includes \"10101\"");
				ctr++;
				break;
			}
		printf("\n");
		string[8] = !string[8];
		if(!string[8])
			for(j=7;j>=0;j--)
				if(string[j])
					string[j] = !string[j];
				else {
					string[j] = !string[j];
					break;
				}
	}
	printf("Number of strings with \"10101\": %d", ctr);
	return 0;
}

   N tane þekerin ve N tane portakalýn bulunduðu dizilerdeki þeker ile portakal sayýlarý kendi aralarýnda eþitlenene kadar bir þeker,
   bir portakal ya da ayný sýrada bulunan bir þeker ve bir portakal çekilecektir. Buna göre, gereken en az hamle sayýsýný hesaplayan program */

int main() {
	int n, i, a[50], b[50], min_a=1e9, min_b=1e9;
	long long moves=0;
	printf("Seker ve portakal sayilarini giriniz: ");
	scanf("%d", &n);
	printf("Sekerleri giriniz: ");
	for(i=0;i<n;i++) {
		scanf("%d", a+i);
		if(a[i]<min_a)
			min_a = a[i];
	}
	printf("Portakallari giriniz: ");
	for(i=0;i<n;i++) {
		scanf("%d", b+i);
		if(b[i]<min_b)
			min_b = b[i];
	}
	for(i=0;i<n;i++)
		moves += a[i]-min_a > b[i]-min_b ? a[i]-min_a : b[i]-min_b;
	printf("Minimum gereken hamle sayisi: %I64d\n", moves);
}
