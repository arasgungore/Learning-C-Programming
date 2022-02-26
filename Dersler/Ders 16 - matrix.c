#include <stdio.h>
#include <stdlib.h>

/* "matrix (2D array): matris , iki boyutlu dizi"
   matematikte sat�r ve s�t�nlardan olu�an dikd�rtgen say�lar tablolar�na "matris" denir
   programlamada da benzer bir �ekilde 2 boyutlu diziler matris tabiriyle ifade edilirler ��nk� bilgisayar 2 boyutlu dizileri matris format�nda belle�e kodlar
   �u ana kadar g�rd���m�z tek boyutlu say� dizileri nas�l int dizi[]={sayi1,sayi2,sayi3,...} syntax'� ile ifade edilirse matrisler de benzer bir �ekilde:
   int matris[][]={sayi1,sayi2,sayi3,...} syntax'� ile ifade edilirler

   yine tek boyutlu dizilerde nas�l k��eli parantez i�indeki say� dizinin eleman say�s�n� (ya da kapasitesini) belirtiyorsa
   matrislerde de k��eli parantezler s�ras�yla o matrisin sat�r ve s�tun say�s�n� belirler
   mesela 2*3'l�k bir matrisi e�er matris[2][3]={34,58,69,110,2,9001} olarak tan�mlarsam bilgisayar bu 2 boyutlu diziyi belle�e ��yle kodlar:
   index	0		1		2
   0		34		58		69
   1		110		2		9001		g�r�ld��� �zere bilgisayar ilk sat�r� doldurduktan sonra ikinci sat�ra verileri yazar

   ba�ka bir deyi�e bilgisayar bir sat�r� verilerle s�rayla doldurmadan bir sonraki sat�ra ge�mez
   yine index default'unun 0 olmas� burada da ge�erli, dolay�s�yla mesela bir matrisin 2. sat�r ve 3. s�tununda bulunan veri bilgisayar i�in 1. sat�r ve 2. s�tunda bulunur   (ve matris[1][2] olarak ifade edilir)

   ilk o zaman matrisi tek tek kodlayal�m

int main () {																						int main() {
	int dizi[2][2];																						int F[2][2];
					//burada kutucuk i�indeki say�lar matrisin sat�r ve s�t�n say�s�n� belirtiyor
	dizi[0][0]=14;																						F[0][0]=290;
	dizi[0][1]=45;																						F[0][1]=39;
	dizi[1][0]=399;																						F[1][0]=42;
	dizi[1][1]=7;	//burada kutucuk i�indeki say�lar elemanlar�n indeks numaralar�n� belirtiyor		F[1][1]=1;

	printf("%d",dizi[1][0]);  //bana 399 yazd�racak														printf("%d\t%d\n%d\t%d",F[0][0],F[0][1],F[1][0],F[1][1]);  //"290	39
																																									//42	1"
}																									}

int main() {
	
	int matris[2][3]={10,20,30,40,50,60};
	int i,j;
	for(i=0;i<2;i++) {
		for(j=0;j<3;j++) {					//y�ld�zlarla �ekil olu�turmayla ayn� mant�k
			printf("%d ",matris[i][j]);		//i=0 iken, j=0 i�in matris[0][0]="10" yazd�r�lacak, j=1 i�in matris[0][1]="20" yazd�r�lacak, j=2 i�in matris[0][2]="30" yazd�r�ld���nda
		}									//bilgisayar j d�ng�s�nden ��kacak, alt sat�ra ge�ecek, ve bu sefer i=1 ve j=0,1,2 de�erleri i�in s�rayla "40","50" ve "60" de�erlerini yazd�racak
		printf("\n");						//dolay�s�yla burada i benim sat�r index'im, j ise benim s�t�n index'im oldu
	}
}										   //"10 20 30
											//40 50 60"

   hadi kendi matrisimizi kendimiz yaz�p bilgisayardan isteyelim

int main() {

	int satir,sutun,i,j;

	printf("Satir Sayisi: ");
	scanf("%d",&satir);
	printf("Sutun Sayisi: ");
	scanf("%d",&sutun);

	int matris[satir][sutun];	//sat�r ve sutun de�i�kenlerine de�er atand�ktan sonra bunu yazmak �ok �nemli, yoksa dinamik oldu�undan hata verebilir

	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			printf("%d. Satir, %d. Sutun Degerini Giriniz: ",i+1,j+1);
			scanf("%d",&matris[i][j]);
		}
	}
	printf("\n\nOlusan Matris\n");
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			printf("%d\t",matris[i][j]);
		}
		printf("\n");
	}
}

int main() {
	char dizi[3][5][20]={"1","23","344","45","5","Arda","Enes","Samet","Zebra Onur","3.14","2.3556","70.369"},i,j;
	for(i=0;i<3;i++) {				//3: sat�r say�s�, 5: s�tun say�s�, 20: karakter s�n�r�

		for(j=0;j<5;j++)			//asl�nda 3 boyutlu bir char dizisi, 2 boyutlu bir string dizisi (matrisi) olarak d���n�lebilir
			printf("%s\t",dizi[i][j]);

		printf("\n");					//"1      23      344      45      5
	}									//Arda    Enes    Samet    Zebra Onur    3.14
}										//2.3556  70.369"

   gelgelelim matrislerde d�rt i�leme...   �ncelikle toplama ve ��karma i�lemlerinde toplan�p ��kar�lacak 2 matrisin de ayn� sat�r ve s�tun boylar�na e�it olmas� laz�m
   e�er matrislerimiz ayn� boyutlardaysa toplama ve ��karma i�lemleri ayn� index numaralar�na sahip elemanlar�n birbiriyle toplan�l�p ��kar�lmas� bi�iminde ger�ekle�ir, mesela:
   index	 0		1		index	 0		1		index	 0		1
   0		[10		12]	+	0		[8		11]	=	0		[18		23]
   1		[15		18]		1		[14		6]		1		[29		24]			gelin bi de bunu yazd�ral�m xd

int main() {

	int m1[2][2]={10,12,15,18};
	int m2[2][2]={8,11,14,6};
	int toplam[2][2],i,j;

	for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
			toplam[i][j]=m1[i][j]+m2[i][j];
		}
	}
	printf("Toplam Matrisi\n\n");
	for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
			printf("%d ",toplam[i][j]);
		}
		printf("\n");
	}
}

   matrislerde �arpma i�lemi ger�ekle�tirebilmek i�in ise �ncelikle 1. matrisin sat�r say�s� 2. matrisin s�tun say�s�na e�it olmal�
   �ncelik 1. matrisin bir sat�r� 2. matrisin t�m s�tunlar� ile e�le�meden 1. matrisin bir sonraki sat�r�na ge�memek olacak bi�imde
   1. matrisin a. sat�r�, 2. matrisin b. s�tunu ile e�le�ti�inde �arp�mlar toplam� �arp�m matrisinin a. sat�r�n b. s�tuna yaz�l�r
   o y�zden bir A matrisi a*b boyutlar�nda ve bir B matrisi b*c boyutlar�nda ise A*B matrisi her zaman a*c boyutlar�nda olur
   index	 0		1		2		index	 0		1		index	 0				1
   0		[a		b		c]	+	0		[g		h]	=	0		[a*g+b*k+c*o	a*h+b*l+c*p]
   1		[d		e		f]		1		[k		l]		1		[d*g+e*k+f*o	d*h+e*l+f*p]		hadi bunu klavyeden girilen herhangi 2*3 ve 3*2'lik matris i�in yazd�ral�m
									2		[o		p]							*/

int main() {
	int i,j,k,m1[2][3],m2[3][2],m3[2][2];
	printf("Ilk matrisi giriniz (2x3):\n");
	for(i=0;i<2;i++) {
		for(j=0;j<3;j++) {
			scanf("%d",&m1[i][j]);
		}
	}
	printf("\nIkinci matrisi giriniz (3x2):\n");
	for(i=0;i<3;i++) {
		for(j=0;j<2;j++) {
			scanf("%d",&m2[i][j]);
		}
	}

	printf("\nCarpim matrisi (2x2):\n");
	for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
			m3[i][j]=0;
			for(k=0;k<3;k++) {
				m3[i][j]+=m1[i][k]*m2[k][j];
			}
		}
	}
	for(i=0;i<2;i++) {
		for(j=0;j<2;j++) {
			printf("%d\t",m3[i][j]);
		}
		printf("\n");
	}
	return 0;
}
