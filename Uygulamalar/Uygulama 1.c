#include <stdio.h>
#include <stdlib.h>

/* Klavyeden girilen say�n�n asal olup olmad���n� yazd�ran program										A�a��daki program�n ��kt�s�

int main() {																							int main() {
	int sayi,i,sayac=0;																						int a=5,b=4,c=1,i;
	printf("Sayi: ");																						a=b*a+c-4;				//a de�i�keninin yeni de�eri a=5*4+1-4 ==> a=17
	scanf("%d",&sayi);																						b=c*a+2;				//b de�i�keninin yeni de�eri b=1*17+2 ==> b=19
	for(i=2;i<sayi;i++) {																					for(i=0;i<=3;i++) {
		if(sayi%i==0) {																							c=c+1				//d�ng� sonunda c de�i�keninin yeni de�eri c=1+1+1+1+1 ==> c=5
			sayac++;																						}
		}																									int toplam=a+b+c;
	}																										printf("%d",toplam);	//��kt� toplam=17+19+5 ten ==> toplam="41"
	if(sayac==0) {																						}
		if(sayi==1) {
			printf("\n%d asal bir sayi degildir",sayi);													Klavyeden girilen say�n�n k�p�n� yazd�ran program
		}
		if(sayi!=1) {																					int main() {
			printf("\n%d asal bir sayidir",sayi);															int sayi,kup;
		}																									printf("Sayi: ");
	}																										scanf("%d",&sayi);
	else {																									kup=sayi*sayi*sayi;
		printf("\n%d asal bir sayi degildir",sayi);															printf("Sayinin Kupu: %d",kup);
	}																									}
}

   �� basamakl� rakamlar� birbirlerinden farkl� toplam ka� tane say� oldu�unu yazd�ran program			Bir bakteri t�r� her saat ba�� kendini ikiye b�lerek �o�al�yorsa, bu laboratuvarda 24 saat sonra ka� tane bakteri oldu�unu yazd�ran program

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

   Klavyeden girilen say�n�n tam b�lenlerini yazd�ran program											Klavyeden 4 tane tam say� al�p bunlar�n toplam�n� yazd�ran program

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

   Bir otopark �irketinde �cretlendirme 0-4 saat aras� 10 TL, 5-8 saat aras� 12 TL, 9-12 saat
   aras� 15 TL ve 13 saat �st�nde 18 TL oldu�una g�re, klavyeden ka� saat kald��� girilen arac�n
   �demesi gereken tutar� yazd�ran program																Klavyeden 0 girilene kadar girilen b�t�n say�lar� toplayan program

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

   1+5+9+13+...+81 serisinin toplam�n� yazd�ran program													Klavyeden girilen 6 basamakl� bir say�n�n rakamlar� toplam�n� yazd�ran program

int main() {																							int main() {
	int i,toplam=0;																							int sayi,a,b,c,d,e,f,toplam;
	for(i=1;i<=81;i+=4) {																					printf("Sayi: ");
		toplam=toplam+i;																					scanf("%d",&sayi);
	}																										a=sayi/100000;
	printf("Toplam: %d",toplam);																			b=(sayi/10000)%10;
}																											c=(sayi/1000)%10;
																											d=(sayi/100)%10;
   n tane ki�i aras�ndan 3 ki�ilik bir tak�m kurulup bu tak�m bir yetenek yar��mas�na kat�lacakt�r.			e=(sayi/10)%10;
   Ayn� yar��mac�lar yar��maya en fazla 5 defa kat�labildi�ine g�re, klavyeden mevcut kat�l�m				f=sayi%10;
   say�lar� girilen ki�iler aras�ndan ka� farkl� tak�m kurulabilece�ini yazd�ran program					toplam=a+b+c+d+e+f;
																											printf("Rakamlar Toplami: %d",toplam);
int main() {																							}
	int i,n,k,sayac=0,x;
	printf("Katilimci sayisini ve kurulacak takimin kac defa katilacagini giriniz: ");					Klavyeden girilen a, b, c tam say� de�erleri i�in a ve b aras�ndaki say�lar�n kareleri aras�ndan
	scanf("%d%d",&n,&k);																				c'den b�y�k olanlar�n�n say�s� ile c'den k���k olanlar�n�n say�s�n�n fark�n� bulup yazd�ran program
	for(i=1;i<=n;i++) {
		printf("%d. katilimcinin katilim sayisini giriniz: ",i);										int main() {
		scanf("%d",&x);																						int i,a,b,c,sayac1=0,sayac2=0;
		if(5>=k+x)																							printf("a, b, c degerlerini giriniz: ");
			sayac++;																						scanf("%d%d%d",&a,&b,&c);
	}																										for(i=a;i<=b;i++) {
	printf("Sadece bir bolumlemeyle olusturulabilecek maksimum farkli takim sayisi: %d", sayac/3);				if(i*i>c)
	printf("Toplam olusturulabilecek farkli takimlarin sayisi: %d", sayac*(sayac-1)*(sayac-2)/6);					sayac1++;
}								//sayac'�n 3'l�s� ( C(sayac,3) = sayac*(sayac-1)*(sayac-2)/3! )					if(i*i<c)
																													sayac2++;
																											}
																											printf("Sonuc: %d",sayac1-sayac2);
																										}

   Bir futbol tak�m�n�n 10 haftal�k ma� istatistikleri �u dizide verilmi�tir:	2	1	0	0	2	1	1	2	1	0
   Bu dizide 2'ler galibiyetleri, 1'ler ma�lubiyetleri, 0'lar ise beraberlikleri belirtmektedir. Bu ligde galibiyetlere 3 puan, ma�lubiyetlere 0 puan, beraberliklere de 1 puan verilecektir.
   Bu tak�m�n k�me d��memesi i�in 12 puan almas� gerekmektedir. Verilenlere g�re, bu tak�m�n 10 hafta sonunda k�me kal�p kalmad���n� puan� ile birlikte yazd�ran program

int main() {																							Klavyeden girilen herhangi bir do�al say�y� tersten yazd�ran program
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

   4'�n kat� olan y�llar 100'�n kat� de�ilse kesinlikle art�k y�l iken 100'�n kat� olan y�llar 400'�n
   kat� de�ilse kesinlikle art�k y�l de�ildir. 4'�n kat� olmayan y�llar ise kesinlikle art�k y�l		Klavyeden s�rayla bir ayda satt��� araba say�s�, satt��� arabalar�n ortalama fiyat� ve ald��� komisyon oran� y�zde
   olmad���na g�re, klavyeden girilen y�l�n art�k y�l olup olmad���n� yazd�ran program					olarak girilen bir araba sat�c�s�n�n bir ayl�k kazanc�n� virg�lden sonraki 2 haneyle birlikte yazd�ran program

int main() {																							int main() {
	unsigned int yil;	//ayn� kural hem M.�. (-) hem de M.S. (+) seneler i�in ge�erli oldu�undan			unsigned int araba,fiyat,komisyon;
	printf("Yili giriniz: ");	//unsigned ile M.�. (-) tarihleri bellekte M.S. (+) tutup					float kazanc;
	scanf("%d",&yil);			//negatif y�llar�n mutlak de�eriyle i�lem yapabilirim						printf("Sirayla satilan araba sayisini, ortalama fiyati ve komisyon oranini giriniz: ");
	if(yil%4==0) {																							scanf("%d%d%d",&araba,&fiyat,&komisyon);
		if(yil%100==0) {																					kazanc=(float)araba*fiyat*komisyon/100;
			if(yil%400==0)																					printf("Aylik kazanc: %.2f",kazanc);
				printf("\n%d artik bir yildir",yil);													}
			else
				printf("\n%d artik bir yil degildir",yil);												Klavyeden ilk 'B' veya 'b' girilirse sonraki girilecek 2 say�dan b�y�k olan�, 'K' veya 'k' girilirse sonraki girilecek 2
		}																								say�dan k���k olan�, e�er ba�ka bir karakter girilirse veya 2 say� da e�itse sonraki girilecek 2 say�n�n toplam�n�
		else																							yazd�ran program
			printf("\n%d artik bir yildir",yil);
	}																									int main() {
	else																									char harf;
		printf("\n%d artik bir yil degildir",yil);															int a,b,buyuk,kucukveyaesit;
}																											printf("1 harf ve 2 sayi giriniz: ");
																											scanf("%c%d%d",&harf,&a,&b);
   Bir markette bulunan �r�nler a�a��daki numaralar ile kodlanm��t�r:										if(a>b)
   100    91    22    52    71    9    11    24    2    80														buyuk=a;
   Buna g�re, klavyeden �r�n numaras� girilen �r�n�n markette bulunup bulunmad���n� yazd�ran program		else
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
	}	//linear search, ileride bunu �ok daha verimli bir �ekilde "binary search" ile yapmay� ��renece�iz
	if(bulundumu)
		printf("%d no'lu urun bulundu",urunno);
	else
		printf("%d no'lu urun bulunamadi",urunno);
}

   Klavyeden girilen mebla�� s�rayla 200, 100, 50, 20, 10 ve 5 TL'lik banknotlara, kalan� da 1 TL'lik madeni paralara ay�ran program

int main() {
	int adet,meblag,nominal_degerler[7]={200,100,50,20,10,5,1},i;
	printf("Meblagi girin: ");
	scanf("%d",&meblag);
	printf("\nadet\t*\tbanknot\t=\ttutar\n***************************************\n");
	for(i=0;i<7;i++) {
		adet=meblag/nominal_degerler[i];
		if(adet) {			//adet=0 ise if yap�s�ndaki kod �al��maz ( if(0)=if(false) ), di�er de�erler i�in �al���r ( if(!0)=if(true) )
			meblag=meblag%nominal_degerler[i];		//kalan mebla�
			printf("%d\t*\t%d\t=\t%d\n",adet,nominal_degerler[i],adet*nominal_degerler[i]);
		}
	}
}

   Sat�r say�s�na g�re slash i�aretleri ile �im�ek resmi �izdiren program								t1 (saat) s�resince v1 (km/h), t2 (saat) s�resince v2 (km/h), t3 (saat) s�resince v3 (km/h) h�z�yla gitmi� bir
																										araban�n (t1+t2+t3) zaman aral���ndaki ortalama h�z�n� virg�lden sonraki 4 haneye kadar km/h cinsinden yazd�ran program
int main() {
	int satir,i,j;																						int main() {
	printf("Satir sayisini giriniz (3'un kati olsun): ");													double t1,v1,t2,v2,t3,v3,OrtHiz;
	scanf("%d",&satir);																						printf("Sirayla v1,t1,v2,t2,v3,t3 degerlerini giriniz: ");
	printf("\n");																							scanf("%lf%lf%lf%lf%lf%lf",&v1,&t1,&v2,&t2,&v3,&t3);
	for(i=0;i<satir/3;i++) {																				OrtHiz=(v1*t1+v2*t2+v3*t3)/(t1+t2+t3);
		for(j=0;j<i;j++)	//sat�r no kadar bo�luk															printf("Ortalama Hiz: %.4f",OrtHiz);
			printf(" ");																				}
		printf("\\ \n");
	}		//ters slash i�areti sorun yaratt��� i�in ba��na bir tane daha ters slash koydum			Bir �ehrin metro ula��m� i�in �cret tarifesi �u tablodaki gibidir:
	for(i=satir/3;i<2*satir/3;i++) {		//yani "//" asl�nda "/" yazd�r�yor										Giri� �creti	1. aktarma		2. aktarma		3. veya daha fazla aktarma
		for(j=0;j<i;j++)																				��renci:	1.25 TL			0.55 TL			0.50 TL			0.45 TL
			printf(" ");	//sat�r no kadar bo�luk														Tam:		2.60 TL			1.85 TL			1.40 TL			0.90 TL
		printf("\\");																					Klavyede ilk girilen 'O' veya 'o' harfi ki�inin ��renci �creti, 'T' veya 't' harfi ise tam �cret �deyece�ini g�sterirken sonra
		for(j=0;j<4*satir/3-2*(i+1);j++)	//2*satir/3,2*satir/3-2,2*satir/3-4,...,2,0 tane bo�luk		girilen de�er o ki�inin yapt��� sefer say�s� oldu�una g�re, bu ki�inin toplam �demesi gereken tutar� yazd�ran program
			printf(" ");
		printf("/");																					int main() {
		for(j=0;j<2*i-2*satir/3;j++)	//0,2,...,2*satir/3-4,2*satir/3-2,2*satir/3 tane bo�luk				int sefer; float tutar=0.00; char kisi;				//statement'lar ';' ile bitti�i s�rece di�er programlama
			printf(" ");																					printf("Ogrenci/Tam ve sefer sayisini giriniz: ");	//dillerinin aksine ayn� sat�ra yaz�labilir
		printf("\\ \n");																					scanf("%c%d",&kisi,&sefer);
	}																										if(kisi=='O' || kisi=='o') {
	for(i=2*satir/3;i<satir;i++) {																				if(sefer>=1)
		for(j=0;j<2*satir/3+i;j++)		//4*satir/3,4*satir/3+1,4*satir/3+2,...,5*satir/3 tane bo�luk				tutar+=1.25;
			printf(" ");																						if(sefer>=2)
		printf("\\ \n");																							tutar+=0.55;
	}																											if(sefer>=3)
}																													tutar+=0.50;
																												while(sefer>=4) {
   Collatz dizisi bir n say�s�ndan ba�layarak e�er bir terim �ift ise sonraki terim onun yar�s�,					tutar+=0.45; sefer--;
   tek ise sonraki terim onun 3 kat�n�n 1 fazlas� olacak �ekilde ilerleyip dizinin son terimi 1					}
   oldu�unda biten dizi olarak tan�mland���na g�re, bu Collatz dizisini klavyeden girilen bir				}
   n say�s� i�in yazd�ran program																			if(kisi=='T' || kisi=='t') {
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

   Son girilen say� -1 olana kadar klavyeden say� de�eri girdisi alan ve girilen say�lardan s�ralamada	Bir dizinin en sonundaki eleman� ba�a, di�er elemanlar� da bir sa�a kayd�r�l�yorsa o dizi bir sa�a d�nd�r�lm�� oluyor.
   kendisinden bir �nceki ve bir sonraki say�lardan b�y�k olan say�lar� s�rayla d�nd�ren program		Buna g�re, k���kten b�y��e s�ral� bir dizinin k defa sa�a d�nd�r�lm�� hali klavyeden girilen ve bu diziyi eski haline
																										getirmek i�in ka� defa sola d�nd�r�lmesi gerekti�ini yazd�ran program
int main() {
	int n,a,b;																							int main() {
	printf("Sayi dizisi giriniz (-1 ile bitiriniz): ");														int i,n,min=1000000,min_index,rotasyon_sayisi;
	scanf("%d",&n);																							printf("Dizinin eleman sayisini giriniz: ");
	a=n;																									scanf("%d",&n);
	scanf("%d",&n);																							int dizi[n];		//asl�nda "int *dizi=(int*) malloc(sizeof(int)*n)" yap�s� kullan�lmal� ama neyse
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

   Klavyeden girilen bir say� ve bir karakterden olu�an girdiye g�re ortas� d��ey �eritli,
   i�i bo� baklava �izdiren program																		Klavyeden girilen sat�r say�s�na g�re y�ld�z i�aretleri ile �anak resmi �izdiren program

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

   n tane tak�m�n oldu�u bir turnuvada n*(n+1) tane ma� yap�lacakt�r. Her tak�m, kendi memleketinde
   oynad��� ma�larda ayr� forma, deplasmanda oynad��� ma�larda ayr� forma giyecektir. Bu tak�mlar�n		Klavyeden girilen n tane say�dan -1'ler zamanla i�lenen su� say�s�n�, pozitif say�lar ise sonradan eklenen
   giyece�i ev sahibi ve konuk formalar� tam say�larla ifade edilip klavyeden girilece�ine g�re,		mevcut polis say�s�n� ifade etmektedir. Her i�lenen su� i�in olay yerine bir polis gidece�ine ve ba�ka su�larla
   turnuvada iki tak�m�n da ayn� formay� giydi�i toplam ka� ma� yap�ld���n� yazd�ran program			ilgilenemeyece�ine g�re, g�z ard� edilmi� su�lar�n say�s�n� yazd�ran program

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

   Klavyeden girilen i� a�� de�erine sahip bir d�zg�n �okgenin var olup olmad���n� yazd�ran program		Klavyeden girilen bir say�n�n pronik say� (iki ard���k tam say�n�n �arp�m� bi�iminde
																										yaz�labilen say�lar) olup olmad��� yazd�ran, ve e�er pronik ise hangi iki ard���k tam
int main() {																							say�n�n �arp�m� oldu�unu, de�ilse pozitif tam say� b�lenlerinin toplam�n� d�nd�ren program
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

   0 yaz�ld���nda girdi almay� b�rakan ve ilk girilen 0'a kadar okunan (0 hari�) say� dizisindeki tek say�lar fazla ise bu dizideki tek say�lar�,
   �ift say�lar fazla ise bu dizideki �ift say�lar�, ikisi de e�it say�da ise b�t�n diziyi s�rayla yazd�ran program

int main() {																							Klavyeden ard���k ikili harf perm�tasyonlar�n�n birle�imi olarak girilen �ifrelenmi� katarlar�
	int a,i=0,j=0,k=0,l,cift[100],tek[100],hepsi[100];													(mesela "asdf"�n �ifrelenmi� hali: 'as' + 'sd' + 'df' = "assddf") de�ifre edip yazd�ran program
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
		for(l=0;l<k;l++)																						for(i=0;katar[i];i++)				//katar[i]!='\0' ile ayn� condition
			printf("%d ",hepsi[l]);																					if(katar[i+1]==katar[i+2])		//katarlar NULL ('\0') ile bitti�i i�in NULL'a eri�ince d�ng�den ��k
	else if(i>j)																										for(j=i+1;katar[j];j++)
		for(l=0;l<i;l++)																									katar[j]=katar[j+1];	//left shift array
			printf("%d ",cift[l]);																				printf("Desifre edilmis katar: %s\n",katar);
	else																									}
		for(l=0;l<j;l++)																				}
			printf("%d ",tek[l]);
}

   Klavyeden girilen en ve boy uzunluklar�na g�re bir y�lan resmi �izdiren program						Klavyeden en ve boy uzunluklar� girilen iki e� dikd�rtgenin s��abilece�i en k���k alanl� karenin alan�n� yazd�ran program

int main() {																							int main() {
	int i,j,n,m;																							int a,b;
	printf("Sirayla en ve boy uzunluklarini giriniz: ");													printf("Dikdortgenlerin en ve boy uzunluklarini giriniz: ");
	scanf("%d%d",&n,&m);																					scanf("%d%d",&a,&b);
	for(i=0;i<n;i++) {																						int min = a<b ? a : b, max = a>b ? a : b;
		if(i%2==0)																							printf("Karenin alani: %d", 2*min>max ? 4*min*min : max*max);
			for(j=0;j<m;j++)																			}
				printf("#");
		else {																							Klavyeden girilen a, b ve n say�lar� i�in, a'ya b veya b'ye a eklenerek en az ka� hamlede n say�s�n�n ge�ilebilece�ini yazd�ran program
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

   �ahika Han�m son moda elbiseyi almak �zere belli ma�azalara gidecektir ve bu ma�azalar�n her birinde bu elbise farkl� fiyatlara sat�lmaktad�r.
   Her g�n farkl� bir kredi kart�yla al��veri� yapan �ahika Han�m'�n bakiyesine g�re her g�n en fazla ka� ma�azadan bu elbiseyi sat�n alabilece�ini yazd�ran program

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

   �ekmecesinde n tane �ift �orab� bulunan Aras'a, annesi m. g�n�n sonunda �ekmecesine yeni bir �ift �orap koymaktad�r. Aras g�n boyunca
   kulland��� �oraplar� g�n�n sonunda kirli sepetine att���na g�re ve ertesi g�n�n sabah�nda yeni bir �ift �orap giydi�ine g�re, Aras'�n
   �oraplar t�kenmeden en fazla ka� g�n �orapla idare edebilece�ini yazd�ran program

int main() {
	int n,m;
	printf("Corap cifti sayisini ve yeni corap gununu giriniz: ");
	scanf("%d%d",&n,&m);		//bu arada m'nin de�eri l�tfen 1 olmas�n, yoksa infinite loop'a girer
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

   Klavyeden girilen diziler ve x de�eri i�in, diziden rastgele se�ilen ve aralar�ndaki fark x'den b�y�k olmayan eleman �iftinden k���k e�it
   olan eleman� mevcut diziden ��karma i�lemini s�rekli tekrar ede ede dizinin tek bir elemana indirgenip indirgenemeyece�ini yazd�ran program

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

   Bir dizinin b�t�n elemanlar� index'leriyle ayn� teklik-�iftlik durumuna sahipse o diziye iyi dizi denmektedir. Buna g�re,
   klavyeden girilen bir diziyi iyi dizi yapmak i�in elemanlar� aras�nda en az ka� swap yap�lmas� gerekti�ini yazd�ran program

int main() {
	int n,tek_elemanlar=0,cift_elemanlar=0;			//iyi olmayan bir dizinin hatal� index'lerinde tek index'ler kadar �ift eleman, �ift index'ler kadar da tek eleman vard�r
	printf("Dizinin eleman sayisini giriniz: ");	//dolay�s�yla bir dizinin iyi dizi, yani her tek eleman�n tek index'te, her �ift eleman�n da �ift index'te olabilmesi i�in
	scanf("%d",&n);									//tek elemanlar�n say�s�n�n �ift elemanlar�n say�s�na e�it olmas� laz�m
	int array[n],i;
	printf("Diziyi giriniz: ");
	for(i=0;i<n;i++) {
		scanf("%d",&array[i]);
		if(i%2!=array[i]%2)
			array[i]%2 ? tek_elemanlar++ : cift_elemanlar++;
	}								//e�er dizinin iyi dizi olmas� m�mk�n de�ilse -1 yazd�r�r
	printf("Yapilmasi gereken swap sayisi: %d", tek_elemanlar==cift_elemanlar ? tek_elemanlar : -1);
}

   9 uzunluklu katarlar aras�ndan ka��n�n "10101" �r�nt�s�n� i�erdi�ini hesaplayan program

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

   N tane �ekerin ve N tane portakal�n bulundu�u dizilerdeki �eker ile portakal say�lar� kendi aralar�nda e�itlenene kadar bir �eker,
   bir portakal ya da ayn� s�rada bulunan bir �eker ve bir portakal �ekilecektir. Buna g�re, gereken en az hamle say�s�n� hesaplayan program */

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
