#include <stdio.h>
#include <stdlib.h>

/* "pattern: desen"				aritmetikte çarpma iþareti olarak kullanýlan yýldýz iþaretini bu sefer þekil þukul yapmak için kullanýcaðýz T_T

int main() {
	int i,j;
	for(i=1;i<=5;i++) {		   //"*			i=1 iken j=1 oluyor ve o j deðeri için 1 tane "*" yazdýrýyor, sonra j döngüsünden çýkýp tekrar kendi i döngüsüne giriyor ve i=1 için bir satýr aþaðý geçiyor
		for(j=1;j<=i;j++) {		//**		i=2 iken j=1,2 oluyor ve her bir j deðeri için 2 tane "*" yazdýrýyor, sonra j döngüsünden çýkýp tekrar kendi i döngüsüne giriyor ve i=2 için bir satýr aþaðý geçiyor
			printf("*");		//***		i=3 iken j=1,2,3 oluyor ve her bir j deðeri için 3 tane "*" yazdýrýyor, sonra j döngüsünden çýkýp tekrar kendi i döngüsüne giriyor ve i=3 için bir satýr aþaðý geçiyor
		}						//****		i=4 iken j=1,2,3,4 oluyor ve her bir j deðeri için 4 tane "*" yazdýrýyor, sonra j döngüsünden çýkýp tekrar kendi i döngüsüne giriyor ve i=4 için bir satýr aþaðý geçiyor
		printf("\n");			//*****"	i=5 iken j=1,2,3,4,5 oluyor ve her bir j deðeri için 5 tane "*" yazdýrýyor, sonra j döngüsünden çýkýp tekrar kendi i döngüsüne giriyor ve i=5 için bir satýr aþaðý geçiyor
	}							//			ve nihayetinde i=5 deðerini alýnca i döngüsü de bitiyor ve son
	
}

int main() {
	int i,j;
	for(i=1;i<=5;i++) {		   //"*****		i=1 iken j=5,4,3,2,1 oluyor ve her bir j deðeri için 5 tane "*" yazdýrýyor, sonra j döngüsünden çýkýp tekrar kendi i döngüsüne giriyor ve i=1 için bir satýr aþaðý geçiyor
		for(j=5;j>=i;j--) {		//****		i=2 iken j=5,4,3,2 oluyor ve her bir j deðeri için 4 tane "*" yazdýrýyor, sonra j döngüsünden çýkýp tekrar kendi i döngüsüne giriyor ve i=2 için bir satýr aþaðý geçiyor
			printf("*");		//***		i=3 iken j=5,4,3 oluyor ve her bir j deðeri için 3 tane "*" yazdýrýyor, sonra j döngüsünden çýkýp tekrar kendi i döngüsüne giriyor ve i=3 için bir satýr aþaðý geçiyor
		}						//**		i=4 iken j=5,4 oluyor ve her bir j deðeri için 2 tane "*" yazdýrýyor, sonra j döngüsünden çýkýp tekrar kendi i döngüsüne giriyor ve i=4 için bir satýr aþaðý geçiyor
		printf("\n");			//*"		i=5 iken j=5 oluyor ve o j deðeri için 1 tane "*" yazdýrýyor, sonra j döngüsünden çýkýp tekrar kendi i döngüsüne giriyor ve i=5 için bir satýr aþaðý geçiyor
	}							//			ve nihayetinde i=5 deðerini alýnca i döngüsü de bitiyor ve son
	
}

int main() {																int main() {
	int en,boy,i,j;																int taban,k,l;
	printf("*****Yildizlarla Dikdortgen Olusturma*****\n\n");					printf("*****Yildizlarla Sola Dayali Ikizkenar Dik Ucgen Olusturma*****\n\n");
	printf("En Degerini Giriniz: ");											printf("Taban Degeri Giriniz: ");
	scanf("%d",&en);															scanf("%d",&taban);
	printf("Boy Degerini Giriniz: ");											printf("\n");
	scanf("%d",&boy);															for(k=1;k<=taban;k++) {
	printf("\n");																	for(l=1;l<=k;l++) {
	for(i=1;i<=boy;i++) {																printf("*");
		for(j=1;j<=en;j++) {														}
			printf("*");															printf("\n");
		}																		}
		printf("\n");														}
	}
}

   eþkenar üçgen çizmeye gelelim

int main() {

	int i,j,taban;
	printf("***** Yildizlarla Eskenar Ucgen Cizme *****\n\nTaban Degerimiz Kac Olsun?: ");
	scanf("%d",&taban);
   
	for(i=0;i<=taban;i++)
	{
    	for(j=25;j>i;j--)			//i=0 için j=25,24,...,1 yani 25 tane "boþluk", döngüden çýk, 2. j döngüsü okunmaz çünkü j=0 iken j<i=0 saðlanmýyor		 ==>	"                         "
    	{							//i=1 için j=25,24,...,2 yani 24 tane "boþluk", döngüden çýk, 2. j döngüsü için j=0 yani 1 tane "yýldýz boþluk"			 ==>	"                        * "
    		printf(" ");			//i=2 için j=25,24,...,3 yani 23 tane "boþluk", döngüden çýk, 2. j döngüsü için j=0,1 yani 2 tane "yýldýz boþluk"		 ==>	"                       * * "
    	}							//i=3 için j=25,24,...,4 yani 22 tane "boþluk", döngüden çýk, 2. j döngüsü için j=0,1,2 yani 3 tane "yýldýz boþluk"		 ==>	"                      * * * "
    	for(j=0;j<i;j++)			//i=4 için j=25,24,...,5 yani 21 tane "boþluk", döngüden çýk, 2. j döngüsü için j=0,1,2,3 yani 4 tane "yýldýz boþluk"	 ==>	"                     * * * * "
    	{							//i=5 için j=25,24,...,6 yani 20 tane "boþluk", döngüden çýk, 2. j döngüsü için j=0,1,2,3,4 yani 5 tane "yýldýz boþluk"	 ==>	"                    * * * * * "
    		printf("* ");			//printf(" *") de olurdu bu arada
    	}
    	printf("\n");
	}
	return 0;
}

   kelebek çizelim þimdi de

int main() {

	int i,j,k,l;
       
    for(i=1;i<=5;i++) {
        for(j=1;j<=i;j++) {				//i=1 için 1) j=1; 2) j=1,2,...,8; 3) j=1 olacaðýndan sýrayla "1 yýldýz, 8 boþluk, 1 yýldýz"				  ==>	"*        *"
        printf("*");					//i=2 için 1) j=1,2; 2) j=1,2,...,6; 3) j=1,2 olacaðýndan sýrayla "2 yýldýz, 6 boþluk, 2 yýldýz"			  ==>	"**      **"
		}								//i=3 için 1) j=1,2,3; 2) j=1,2,3,4; 3) j=1,2,3 olacaðýndan sýrayla "3 yýldýz, 4 boþluk, 3 yýldýz"			  ==>	"***    ***"
		for(j=1;j<=10-2*i;j++) {		//i=4 için 1) j=1,2,3,4; 2) j=1,2; 3) j=1,2,3,4 olacaðýndan sýrayla "4 yýldýz, 2 boþluk, 4 yýldýz"			  ==>	"****  ****"
		printf(" ");					//i=5 için 1) j=1,2,...,5; 2) okunmayacak çünkü 1<0 yanlýþ yargý; 3) j=1,2,...,5 olacaðýndan 5+5="10 yýldýz"  ==>	"**********"
		}								//k=1 için 1) l=4,3,2,1; 2) l=1,2; 3) l=4,3,2,1 olacaðýndan sýrayla "4 yýldýz, 2 boþluk, 4 yýldýz"			  ==>	"****  ****"
		for(j=1;j<=i;j++) {				//i=2 için 1) l=4,3,2; 2) l=1,2,3,4; 3) l=4,3,2 olacaðýndan sýrayla "3 yýldýz, 4 boþluk, 3 yýldýz"			  ==>	"***    ***"
		printf("*");					//i=3 için 1) l=4,3; 2) l=1,2,...,6; 3) l=4,3 olacaðýndan sýrayla "2 yýldýz, 6 boþluk, 2 yýldýz"			  ==>	"**      **"
		}								//i=4 için 1) l=4; 2) l=1,2,...,8; 3) l=4 olacaðýndan sýrayla "1 yýldýz, 8 boþluk, 1 yýldýz"				  ==>	"*        *"
		printf("\n");
		}     							//iþin püf noktasý þu, eðer ben bir karakterden bir satýrda "a" kadar yazdýracaksam: "for(i=1;i<=a;i++) { printf("karakter"); }"
										//eðer ben 2 farklý karakterden ayný satýrda sýrayla "a" ve "b" kadar yazdýracaksam: "for(i=1;i<=a;i++) { printf("karakter1"); }	for(i=1;i<=b;i++) { printf("karakter2"); }"
	for(k=1;k<=4;k++) {					//eðer ben 2 farklý karakteri "c" kadar satýra sýrayla "a" ve "b" kadar yazdýracaksam: "for(i=1;i<=c;i++) { for(j=1;j<=a;j++) { printf("karakter1"); }	for(j=1;j<=b;j++) { printf("karakter2"); } }"
										//tabii bu a,b,c deðerleri bazen kullanýcýya baðlý bazen de bizzat i veya j deðiþkenlerine baðlý olacaðý için oluþturacaðýn þeklin satýr numarasý ile a ve b
		for(l=4;l>=k;l--) {				//arasýndaki denklemi bulup bunu for döngüsüne eklemek sana kalmýþ   (mesela burada yýldýz sayýsý her bir satýr için "i" kadar, boþluk sayýsý da "10-2i" kadar olduðu için
		printf("*");					//buradaki "a" ve "b" deðiþkenleri dediðim þeyler sýrasýyla "a=i" ve "b=10-2i" olmuþ oldu)
		}
		for(l=1;l<=2*k;l++) {
		printf(" ");
		}
		for(l=4;l>=k;l--) {
		printf("*");
		}
	printf("\n");
	}

}

int main() {
	int secim,a,a1,a2,b,b1,b2,c,c1,a3,b3,yildiz,bosluk;
  
	printf("***Yildizlarla Sekil Olusturma Uygulamasina Hos Geldiniz***\n\n");
	printf("Insan resmi gormek icin 1'e basiniz.\n");
	printf("Kelebek resmi gormek icin 2'ye basiniz.\n");
	printf("Saga dayali ucgen resmi gormek icin 3'e basiniz.\n");
	printf("Eskenar ucgen resmi gormek icin 4'e basiniz.\n");
	printf("Baklava resmi gormek icin 5'e basiniz.\n");
	printf("Kalp resmi gormek icin 6'ya basiniz.\n");
	printf("Carpi resmi gormek icin 7'ye basiniz.\n");
	printf("\nLutfen seciminizi yapiniz: ");
	scanf("%d",&secim);
	printf("\n");

	switch(secim) {
    	case 1:												//insan
    		for(a1=1;a1<2;a1++) {
			printf("        ******\n");						//1 tane bundan
			}
			for(a=2;a<=4;a++) {
			printf("       ********\n");					//3 tane bundan
			}
			for(a2=5;a2<6;a2++) {
			printf("        ******\n");						//1 tane bundan
			}
			for(b1=6;b1<7;b1++) {
			printf("    **************\n");					//1 tane bundan
			}
			for(b=7;b<15;b++) {
			printf("***  ************  ***\n");				//8 tane bundan
			}
			for(b2=15;b2<16;b2++) {
			printf("    **************\n");					//1 tane bundan
			}
			for(c=16;c<23;c++) {
			printf("     ***      *** \n");					//7 tane bundan
			}
			for(c1=23;c1<25;c1++) {
			printf("    *****    *****\n");					//2 tane bundan
			}
			break;
		case 2:												//kelebek
			bosluk=20;
			for(a=1;a<=11;a++) {							//üst yarýsý 11 satýr olacak
				for(b=1;b<=a;b++) {							//satýr numarasý kadar yýldýz
				printf("*");
				}
				for(c=1;c<=bosluk;c++) {					//bosluk deðiþkeninin deðeri kadar boþluk
				printf(" ");
				}
				for(b=1;b<=a;b++) {							//yine satýr numarasý kadar yýldýz
				printf("*");
				}
				printf("\n");
				bosluk=bosluk-2;							//döngünün sonunda yazdýrýlan bosluk deðeri 2 azalýp yeni bir deðer alacaðý için her bir sonraki satýrda 2 az boþluk girilecek
			}
			bosluk+=2;										//döngüden çýkýlýnca bosluk deðiþkeninin son deðeri -2 oldu, simetrik olarak tekrar arttýracaðým için bosluk=0 yaptým
	 		for(a=11;1<=a;a--) {							//alt yarýsý da üst yarýsý gibi 11 satýr olacak
				for(b=1;b<=a;b++) {							//bu sefer satýr numaralarý 11,10,9,...,1 diye gittiði için ve yine satýr numarasý kadar yýldýz yazdýrýlacaðý için
				printf("*");								//üsttekinin simetriði olmuþ oldu
				}
				for(c=1;c<=bosluk;c++) {
				printf(" ");
				}
				for(b=1;b<=a;b++) {
				printf("*");
				}
				bosluk+=2;									//ilk 11 satýrda bosluk deðiþkeninin aldýðý 20,18,...,2,0 idi, son 11 satýrda ise böylelikle 0,2,...,18,20 olacak
				printf("\n");
			}
			break;
  		case 3:												//saða dayalý üçgen
			for(a=1;a<=10;a++) {							//10 tane satýr
				for(b=10;a<=b;b--) {						//sýrasýyla 10,9,8,...,1 tane boþluk
				printf(" ");
				}
				for(c=1;c<=a;c++) {							//satýr numarasý kadar yýldýz
				printf("*");
				}
			printf("\n");
			}
			break;
		case 4:												//eþkenar üçgen
			for(a=1;a<=15;a++) {							//15 satýr
				for(b=1;b<=15-a;b++) {						//sýrasýyla 15,14,...,1,0 tane boþluk
				printf(" ");
				}
				for(c=1;c<=2*a-1;c++) {						//sýrasýyla 1,3,5,...,27,29 tane yýldýz
				printf("*");
				}
			printf("\n");
			}
			break;
		case 5:												//baklava   (eþkenar dörtgen)
			yildiz=1;
			bosluk=9;
			for(a=1;a<20;a++) {								//19 satýr
				for(b=1;b<=bosluk;b++) {					//bosluk deðiþkeni kadar boþluk
    	        printf(" ");
    	    	}
				for(b=1;b<yildiz*2;b++) {					//yildiz deðiþkeninin 2 katýnýn 1 eksiði kadar yýldýz	(2*yildiz-1 kadar yýldýz)
				printf("*");
				}
				printf("\n");
				if(a<10) {									//ilk 9 satýr için bosluk ve yildiz deðiþkenlerinin deðerleri sýrasýyla bosluk=9,8,7,...,1 ve yildiz=1,2,3,...,9 olacak
					bosluk--;								//yani 1. satýr için "9 boþluk, 1 yýldýz", 2. satýr için "8 boþluk, 3 yýldýz", 3. satýr için "7 boþluk, 5 yýldýz",..., 9. satýr için "1 boþluk, 17 yýldýz"
					yildiz++;
    		    }
        		else {										//son 10 satýr için bosluk ve yildiz deðiþkenlerinin deðerleri sýrasýyla bosluk=0,1,2,...,9 ve yildiz=10,9,8,...,1 olacak
					bosluk++;								//yani 10. satýr için "19 yýldýz", 11. satýr için "1 boþluk, 17 yýldýz", 12. satýr için "2 boþluk, 15 yýldýz",..., 19. satýr için "9 boþluk, 1 yýldýz"
					yildiz--;
				}
			}
			break;
		case 6:												//kalp
			for(a=7;a<=15;a+=2) {							//sýrasýyla a=7,9,11,13,15 için, yani 5 satýr
				for(b=1;b<15-a;b+=2) {						//a=7 için b=1,3,5,7; a=9 için b=1,3,5; a=11 için b=1,3; a=13 için b=1; a=15 için de okunmaz
				printf(" ");								//yani sýrasýyla 4,3,2,1 ve 0 tane boþluk
				}
				for(b=1;b<=a;b++) {							//sýrasýyla 7,9,11,13,15 tane yýldýz
				printf("*");
				}
				for(b=1;b<=14-a;b++) {						//sýrasýyla 7,5,3,1,0 tane boþluk
				printf(" ");
				}
				if(a==15) {
					a--;
				}
				for(b=1;b<=a;b++) {							//sýrasýyla 7,9,11,13,14 tane yýldýz, if olmasa sonuncusu 15 tane yýldýz olacaktý
				printf("*");
				}
				printf("\n");
			}
			for(a=15;a>=1;a--) {							//15 satýr
				for(b=a;b<16;b++) {							//sýrasýyla 1,2,3,...,15 tane boþluk
				printf(" ");
				}
				for(b=1;b<=2*a-3;b++) {						//sýrasýyla 27,25,23,...,1,0 tane yýldýz
				printf("*");
				}
				printf("\n");
			}
			break;
		case 7:												//cross   (çarpý)
			for(a=10;a>=1;a--) {							//10 satýr
				for(b=1;b<=10-a;b++) {						//sýrasýyla 0,1,2,...,9 tane boþluk
				printf(" ");
				}
				printf("**");								//sonra 2 tane yýldýz
				for(b=1;b<=2*a-2;b++) {						//ardýndan sýrasýyla 18,16,14,...,2,0 tane boþluk
				printf(" ");
				}
				printf("**");								//son olarak da 2 tane yýldýz
				printf("\n");
			}
			for(a=1;a<=10;a++) {							//üst yarýsýnýn birebir simetriði
				for(b=10-a;b>=1;b--) {
				printf(" ");
				}
				printf("**");
				for(b=2*a-2;b>=1;b--) {
				printf(" ");
				}
				printf("**");
				printf("\n");
			}
			break;
		default:printf("\nHatali sayi girdiniz.");
	}
}

   sayý ile çizilen desenlerde sayaç tutulur

int main() {
	int n,i,j,sayac;
	printf("Satir sayisi: ");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=n;i++) {
		for(j=1;j<=n-i;j++) {
			printf(" ");
		}									//"1
										    //232
		sayac=i;						   //34543
										  //4567654
		for(j=1;j<=i;j++) {				 //567898765
			printf("%d",sayac);			//67891011109876 ..."
			sayac++;
		}

		sayac-=2;

		for(j=1;j<i;j++) {
			printf("%d",sayac);
			sayac--;
		}

		printf("\n");
	}
}

int main() {
	int n,i,j,sayac;
	printf("Sayi girin: ");
	scanf("%d",&n);
	printf("\n");
	for(i=1;i<=n;i++) {
		sayac=n;		//mesela 7 girseydim çýktým böyle olurdu:
		for(j=1;j<=i-1;j++) {
			printf("%d ",sayac);	//"7 7 7 7 7 7 7 7 7 7 7 7 7
			sayac--;				// 7 6 6 6 6 6 6 6 6 6 6 6 7
		}							// 7 6 5 5 5 5 5 5 5 5 5 6 7
									// 7 6 5 4 4 4 4 4 4 4 5 6 7
		for(j=1;j<=2*n-2*i+1;j++)	// 7 6 5 4 3 3 3 3 3 4 5 6 7
			printf("%d ",sayac);	// 7 6 5 4 3 2 2 2 3 4 5 6 7
									// 7 6 5 4 3 2 1 2 3 4 5 6 7
		for(j=1;j<=i-1;j++) {		// 7 6 5 4 3 2 2 2 3 4 5 6 7
			sayac++;				// 7 6 5 4 3 3 3 3 3 4 5 6 7
			printf("%d ",sayac);	// 7 6 5 4 4 4 4 4 4 4 5 6 7
		}							// 7 6 5 5 5 5 5 5 5 5 5 6 7
		printf("\n");				// 7 6 6 6 6 6 6 6 6 6 6 6 7
	}								// 7 7 7 7 7 7 7 7 7 7 7 7 7"

	for(i=n-1;i>=1;i--) {
		sayac=n;
		for(j=i-1;j>=1;j--) {
			printf("%d ",sayac);
			sayac--;
		}

		for(j=1;j<=2*n-2*i+1;j++)
			printf("%d ",sayac);

		for(j=i-1;j>=1;j--) {
			sayac++;
			printf("%d ",sayac);
		}
		printf("\n");
	}
}

   son olarak matrisli bir desen çizdirelim */

int main() {
	int m,n,i,j,sayi,sayac=1,matris[100][100];
	printf("Sayi giriniz: ");
	scanf("%d",&sayi);			//mesela 5 girseydim çýktým böyle olurdu:
	printf("\n");								//"1    2    4    7    11
	for(i=1;i<=sayi;i++) {	//ilk çapraz		// 3    5    8    12   16
		m=0;	//daima 1. satýr				// 6    9    13   17   20
		n=i-1;	//i. sütun						// 10   14   18   21   23
		for(j=1;j<=i;j++)						// 15   19   22   24   25"
			matris[m++][n--]=sayac++;
	}	//önce m'yi gir, sonra 1 arttýr; önce n'yi gir, sonra 1 azalt	(1 satýr aþaðý 1 sütun sola)
		//eðer "++m" veya "--n" olsaydý tam tersi olurdu (önce m'yi bir arttýr, sonra gir; önce n'yi 1 azalt, sonra gir)
	for(i=1;i<=sayi-1;i++) {	//ikinci çapraz
		m=i;		//(i+1).satýr
		n=sayi-1;	//daima (sayi). sütun
		for(j=1;j<=sayi-i;j++)
			matris[m++][n--]=sayac++;	//"1 satýr aþaðý 1 sütun sola"ya devam
	}
		//þu ana kadar sadece matrisdeki elemanlara atama yapýldý, gelgelelim yazdýrmaya >:)
	for(i=0;i<sayi;i++) {
		for(j=0;j<sayi;j++)
			printf("%d\t",matris[i][j]);
    	printf("\n");
	}
}
