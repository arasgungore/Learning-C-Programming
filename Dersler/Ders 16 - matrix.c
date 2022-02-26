#include <stdio.h>
#include <stdlib.h>

/* "matrix (2D array): matris , iki boyutlu dizi"
   matematikte satýr ve sütünlardan oluþan dikdörtgen sayýlar tablolarýna "matris" denir
   programlamada da benzer bir þekilde 2 boyutlu diziler matris tabiriyle ifade edilirler çünkü bilgisayar 2 boyutlu dizileri matris formatýnda belleðe kodlar
   þu ana kadar gördüðümüz tek boyutlu sayý dizileri nasýl int dizi[]={sayi1,sayi2,sayi3,...} syntax'ý ile ifade edilirse matrisler de benzer bir þekilde:
   int matris[][]={sayi1,sayi2,sayi3,...} syntax'ý ile ifade edilirler

   yine tek boyutlu dizilerde nasýl köþeli parantez içindeki sayý dizinin eleman sayýsýný (ya da kapasitesini) belirtiyorsa
   matrislerde de köþeli parantezler sýrasýyla o matrisin satýr ve sütun sayýsýný belirler
   mesela 2*3'lÜk bir matrisi eðer matris[2][3]={34,58,69,110,2,9001} olarak tanýmlarsam bilgisayar bu 2 boyutlu diziyi belleðe þöyle kodlar:
   index	0		1		2
   0		34		58		69
   1		110		2		9001		görüldüðü üzere bilgisayar ilk satýrý doldurduktan sonra ikinci satýra verileri yazar

   baþka bir deyiþe bilgisayar bir satýrý verilerle sýrayla doldurmadan bir sonraki satýra geçmez
   yine index default'unun 0 olmasý burada da geçerli, dolayýsýyla mesela bir matrisin 2. satýr ve 3. sütununda bulunan veri bilgisayar için 1. satýr ve 2. sütunda bulunur   (ve matris[1][2] olarak ifade edilir)

   ilk o zaman matrisi tek tek kodlayalým

int main () {																						int main() {
	int dizi[2][2];																						int F[2][2];
					//burada kutucuk içindeki sayýlar matrisin satýr ve sütün sayýsýný belirtiyor
	dizi[0][0]=14;																						F[0][0]=290;
	dizi[0][1]=45;																						F[0][1]=39;
	dizi[1][0]=399;																						F[1][0]=42;
	dizi[1][1]=7;	//burada kutucuk içindeki sayýlar elemanlarýn indeks numaralarýný belirtiyor		F[1][1]=1;

	printf("%d",dizi[1][0]);  //bana 399 yazdýracak														printf("%d\t%d\n%d\t%d",F[0][0],F[0][1],F[1][0],F[1][1]);  //"290	39
																																									//42	1"
}																									}

int main() {
	
	int matris[2][3]={10,20,30,40,50,60};
	int i,j;
	for(i=0;i<2;i++) {
		for(j=0;j<3;j++) {					//yýldýzlarla þekil oluþturmayla ayný mantýk
			printf("%d ",matris[i][j]);		//i=0 iken, j=0 için matris[0][0]="10" yazdýrýlacak, j=1 için matris[0][1]="20" yazdýrýlacak, j=2 için matris[0][2]="30" yazdýrýldýðýnda
		}									//bilgisayar j döngüsünden çýkacak, alt satýra geçecek, ve bu sefer i=1 ve j=0,1,2 deðerleri için sýrayla "40","50" ve "60" deðerlerini yazdýracak
		printf("\n");						//dolayýsýyla burada i benim satýr index'im, j ise benim sütün index'im oldu
	}
}										   //"10 20 30
											//40 50 60"

   hadi kendi matrisimizi kendimiz yazýp bilgisayardan isteyelim

int main() {

	int satir,sutun,i,j;

	printf("Satir Sayisi: ");
	scanf("%d",&satir);
	printf("Sutun Sayisi: ");
	scanf("%d",&sutun);

	int matris[satir][sutun];	//satýr ve sutun deðiþkenlerine deðer atandýktan sonra bunu yazmak çok önemli, yoksa dinamik olduðundan hata verebilir

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
	for(i=0;i<3;i++) {				//3: satýr sayýsý, 5: sütun sayýsý, 20: karakter sýnýrý

		for(j=0;j<5;j++)			//aslýnda 3 boyutlu bir char dizisi, 2 boyutlu bir string dizisi (matrisi) olarak düþünülebilir
			printf("%s\t",dizi[i][j]);

		printf("\n");					//"1      23      344      45      5
	}									//Arda    Enes    Samet    Zebra Onur    3.14
}										//2.3556  70.369"

   gelgelelim matrislerde dört iþleme...   öncelikle toplama ve çýkarma iþlemlerinde toplanýp çýkarýlacak 2 matrisin de ayný satýr ve sütun boylarýna eþit olmasý lazým
   eðer matrislerimiz ayný boyutlardaysa toplama ve çýkarma iþlemleri ayný index numaralarýna sahip elemanlarýn birbiriyle toplanýlýp çýkarýlmasý biçiminde gerçekleþir, mesela:
   index	 0		1		index	 0		1		index	 0		1
   0		[10		12]	+	0		[8		11]	=	0		[18		23]
   1		[15		18]		1		[14		6]		1		[29		24]			gelin bi de bunu yazdýralým xd

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

   matrislerde çarpma iþlemi gerçekleþtirebilmek için ise öncelikle 1. matrisin satýr sayýsý 2. matrisin sütun sayýsýna eþit olmalý
   öncelik 1. matrisin bir satýrý 2. matrisin tüm sütunlarý ile eþleþmeden 1. matrisin bir sonraki satýrýna geçmemek olacak biçimde
   1. matrisin a. satýrý, 2. matrisin b. sütunu ile eþleþtiðinde çarpýmlar toplamý çarpým matrisinin a. satýrýn b. sütuna yazýlýr
   o yüzden bir A matrisi a*b boyutlarýnda ve bir B matrisi b*c boyutlarýnda ise A*B matrisi her zaman a*c boyutlarýnda olur
   index	 0		1		2		index	 0		1		index	 0				1
   0		[a		b		c]	+	0		[g		h]	=	0		[a*g+b*k+c*o	a*h+b*l+c*p]
   1		[d		e		f]		1		[k		l]		1		[d*g+e*k+f*o	d*h+e*l+f*p]		hadi bunu klavyeden girilen herhangi 2*3 ve 3*2'lik matris için yazdýralým
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
