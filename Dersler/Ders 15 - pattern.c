#include <stdio.h>
#include <stdlib.h>

/* "pattern: desen"				aritmetikte �arpma i�areti olarak kullan�lan y�ld�z i�aretini bu sefer �ekil �ukul yapmak i�in kullan�ca��z T_T

int main() {
	int i,j;
	for(i=1;i<=5;i++) {		   //"*			i=1 iken j=1 oluyor ve o j de�eri i�in 1 tane "*" yazd�r�yor, sonra j d�ng�s�nden ��k�p tekrar kendi i d�ng�s�ne giriyor ve i=1 i�in bir sat�r a�a�� ge�iyor
		for(j=1;j<=i;j++) {		//**		i=2 iken j=1,2 oluyor ve her bir j de�eri i�in 2 tane "*" yazd�r�yor, sonra j d�ng�s�nden ��k�p tekrar kendi i d�ng�s�ne giriyor ve i=2 i�in bir sat�r a�a�� ge�iyor
			printf("*");		//***		i=3 iken j=1,2,3 oluyor ve her bir j de�eri i�in 3 tane "*" yazd�r�yor, sonra j d�ng�s�nden ��k�p tekrar kendi i d�ng�s�ne giriyor ve i=3 i�in bir sat�r a�a�� ge�iyor
		}						//****		i=4 iken j=1,2,3,4 oluyor ve her bir j de�eri i�in 4 tane "*" yazd�r�yor, sonra j d�ng�s�nden ��k�p tekrar kendi i d�ng�s�ne giriyor ve i=4 i�in bir sat�r a�a�� ge�iyor
		printf("\n");			//*****"	i=5 iken j=1,2,3,4,5 oluyor ve her bir j de�eri i�in 5 tane "*" yazd�r�yor, sonra j d�ng�s�nden ��k�p tekrar kendi i d�ng�s�ne giriyor ve i=5 i�in bir sat�r a�a�� ge�iyor
	}							//			ve nihayetinde i=5 de�erini al�nca i d�ng�s� de bitiyor ve son
	
}

int main() {
	int i,j;
	for(i=1;i<=5;i++) {		   //"*****		i=1 iken j=5,4,3,2,1 oluyor ve her bir j de�eri i�in 5 tane "*" yazd�r�yor, sonra j d�ng�s�nden ��k�p tekrar kendi i d�ng�s�ne giriyor ve i=1 i�in bir sat�r a�a�� ge�iyor
		for(j=5;j>=i;j--) {		//****		i=2 iken j=5,4,3,2 oluyor ve her bir j de�eri i�in 4 tane "*" yazd�r�yor, sonra j d�ng�s�nden ��k�p tekrar kendi i d�ng�s�ne giriyor ve i=2 i�in bir sat�r a�a�� ge�iyor
			printf("*");		//***		i=3 iken j=5,4,3 oluyor ve her bir j de�eri i�in 3 tane "*" yazd�r�yor, sonra j d�ng�s�nden ��k�p tekrar kendi i d�ng�s�ne giriyor ve i=3 i�in bir sat�r a�a�� ge�iyor
		}						//**		i=4 iken j=5,4 oluyor ve her bir j de�eri i�in 2 tane "*" yazd�r�yor, sonra j d�ng�s�nden ��k�p tekrar kendi i d�ng�s�ne giriyor ve i=4 i�in bir sat�r a�a�� ge�iyor
		printf("\n");			//*"		i=5 iken j=5 oluyor ve o j de�eri i�in 1 tane "*" yazd�r�yor, sonra j d�ng�s�nden ��k�p tekrar kendi i d�ng�s�ne giriyor ve i=5 i�in bir sat�r a�a�� ge�iyor
	}							//			ve nihayetinde i=5 de�erini al�nca i d�ng�s� de bitiyor ve son
	
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

   e�kenar ��gen �izmeye gelelim

int main() {

	int i,j,taban;
	printf("***** Yildizlarla Eskenar Ucgen Cizme *****\n\nTaban Degerimiz Kac Olsun?: ");
	scanf("%d",&taban);
   
	for(i=0;i<=taban;i++)
	{
    	for(j=25;j>i;j--)			//i=0 i�in j=25,24,...,1 yani 25 tane "bo�luk", d�ng�den ��k, 2. j d�ng�s� okunmaz ��nk� j=0 iken j<i=0 sa�lanm�yor		 ==>	"                         "
    	{							//i=1 i�in j=25,24,...,2 yani 24 tane "bo�luk", d�ng�den ��k, 2. j d�ng�s� i�in j=0 yani 1 tane "y�ld�z bo�luk"			 ==>	"                        * "
    		printf(" ");			//i=2 i�in j=25,24,...,3 yani 23 tane "bo�luk", d�ng�den ��k, 2. j d�ng�s� i�in j=0,1 yani 2 tane "y�ld�z bo�luk"		 ==>	"                       * * "
    	}							//i=3 i�in j=25,24,...,4 yani 22 tane "bo�luk", d�ng�den ��k, 2. j d�ng�s� i�in j=0,1,2 yani 3 tane "y�ld�z bo�luk"		 ==>	"                      * * * "
    	for(j=0;j<i;j++)			//i=4 i�in j=25,24,...,5 yani 21 tane "bo�luk", d�ng�den ��k, 2. j d�ng�s� i�in j=0,1,2,3 yani 4 tane "y�ld�z bo�luk"	 ==>	"                     * * * * "
    	{							//i=5 i�in j=25,24,...,6 yani 20 tane "bo�luk", d�ng�den ��k, 2. j d�ng�s� i�in j=0,1,2,3,4 yani 5 tane "y�ld�z bo�luk"	 ==>	"                    * * * * * "
    		printf("* ");			//printf(" *") de olurdu bu arada
    	}
    	printf("\n");
	}
	return 0;
}

   kelebek �izelim �imdi de

int main() {

	int i,j,k,l;
       
    for(i=1;i<=5;i++) {
        for(j=1;j<=i;j++) {				//i=1 i�in 1) j=1; 2) j=1,2,...,8; 3) j=1 olaca��ndan s�rayla "1 y�ld�z, 8 bo�luk, 1 y�ld�z"				  ==>	"*        *"
        printf("*");					//i=2 i�in 1) j=1,2; 2) j=1,2,...,6; 3) j=1,2 olaca��ndan s�rayla "2 y�ld�z, 6 bo�luk, 2 y�ld�z"			  ==>	"**      **"
		}								//i=3 i�in 1) j=1,2,3; 2) j=1,2,3,4; 3) j=1,2,3 olaca��ndan s�rayla "3 y�ld�z, 4 bo�luk, 3 y�ld�z"			  ==>	"***    ***"
		for(j=1;j<=10-2*i;j++) {		//i=4 i�in 1) j=1,2,3,4; 2) j=1,2; 3) j=1,2,3,4 olaca��ndan s�rayla "4 y�ld�z, 2 bo�luk, 4 y�ld�z"			  ==>	"****  ****"
		printf(" ");					//i=5 i�in 1) j=1,2,...,5; 2) okunmayacak ��nk� 1<0 yanl�� yarg�; 3) j=1,2,...,5 olaca��ndan 5+5="10 y�ld�z"  ==>	"**********"
		}								//k=1 i�in 1) l=4,3,2,1; 2) l=1,2; 3) l=4,3,2,1 olaca��ndan s�rayla "4 y�ld�z, 2 bo�luk, 4 y�ld�z"			  ==>	"****  ****"
		for(j=1;j<=i;j++) {				//i=2 i�in 1) l=4,3,2; 2) l=1,2,3,4; 3) l=4,3,2 olaca��ndan s�rayla "3 y�ld�z, 4 bo�luk, 3 y�ld�z"			  ==>	"***    ***"
		printf("*");					//i=3 i�in 1) l=4,3; 2) l=1,2,...,6; 3) l=4,3 olaca��ndan s�rayla "2 y�ld�z, 6 bo�luk, 2 y�ld�z"			  ==>	"**      **"
		}								//i=4 i�in 1) l=4; 2) l=1,2,...,8; 3) l=4 olaca��ndan s�rayla "1 y�ld�z, 8 bo�luk, 1 y�ld�z"				  ==>	"*        *"
		printf("\n");
		}     							//i�in p�f noktas� �u, e�er ben bir karakterden bir sat�rda "a" kadar yazd�racaksam: "for(i=1;i<=a;i++) { printf("karakter"); }"
										//e�er ben 2 farkl� karakterden ayn� sat�rda s�rayla "a" ve "b" kadar yazd�racaksam: "for(i=1;i<=a;i++) { printf("karakter1"); }	for(i=1;i<=b;i++) { printf("karakter2"); }"
	for(k=1;k<=4;k++) {					//e�er ben 2 farkl� karakteri "c" kadar sat�ra s�rayla "a" ve "b" kadar yazd�racaksam: "for(i=1;i<=c;i++) { for(j=1;j<=a;j++) { printf("karakter1"); }	for(j=1;j<=b;j++) { printf("karakter2"); } }"
										//tabii bu a,b,c de�erleri bazen kullan�c�ya ba�l� bazen de bizzat i veya j de�i�kenlerine ba�l� olaca�� i�in olu�turaca��n �eklin sat�r numaras� ile a ve b
		for(l=4;l>=k;l--) {				//aras�ndaki denklemi bulup bunu for d�ng�s�ne eklemek sana kalm��   (mesela burada y�ld�z say�s� her bir sat�r i�in "i" kadar, bo�luk say�s� da "10-2i" kadar oldu�u i�in
		printf("*");					//buradaki "a" ve "b" de�i�kenleri dedi�im �eyler s�ras�yla "a=i" ve "b=10-2i" olmu� oldu)
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
			for(a=1;a<=11;a++) {							//�st yar�s� 11 sat�r olacak
				for(b=1;b<=a;b++) {							//sat�r numaras� kadar y�ld�z
				printf("*");
				}
				for(c=1;c<=bosluk;c++) {					//bosluk de�i�keninin de�eri kadar bo�luk
				printf(" ");
				}
				for(b=1;b<=a;b++) {							//yine sat�r numaras� kadar y�ld�z
				printf("*");
				}
				printf("\n");
				bosluk=bosluk-2;							//d�ng�n�n sonunda yazd�r�lan bosluk de�eri 2 azal�p yeni bir de�er alaca�� i�in her bir sonraki sat�rda 2 az bo�luk girilecek
			}
			bosluk+=2;										//d�ng�den ��k�l�nca bosluk de�i�keninin son de�eri -2 oldu, simetrik olarak tekrar artt�raca��m i�in bosluk=0 yapt�m
	 		for(a=11;1<=a;a--) {							//alt yar�s� da �st yar�s� gibi 11 sat�r olacak
				for(b=1;b<=a;b++) {							//bu sefer sat�r numaralar� 11,10,9,...,1 diye gitti�i i�in ve yine sat�r numaras� kadar y�ld�z yazd�r�laca�� i�in
				printf("*");								//�sttekinin simetri�i olmu� oldu
				}
				for(c=1;c<=bosluk;c++) {
				printf(" ");
				}
				for(b=1;b<=a;b++) {
				printf("*");
				}
				bosluk+=2;									//ilk 11 sat�rda bosluk de�i�keninin ald��� 20,18,...,2,0 idi, son 11 sat�rda ise b�ylelikle 0,2,...,18,20 olacak
				printf("\n");
			}
			break;
  		case 3:												//sa�a dayal� ��gen
			for(a=1;a<=10;a++) {							//10 tane sat�r
				for(b=10;a<=b;b--) {						//s�ras�yla 10,9,8,...,1 tane bo�luk
				printf(" ");
				}
				for(c=1;c<=a;c++) {							//sat�r numaras� kadar y�ld�z
				printf("*");
				}
			printf("\n");
			}
			break;
		case 4:												//e�kenar ��gen
			for(a=1;a<=15;a++) {							//15 sat�r
				for(b=1;b<=15-a;b++) {						//s�ras�yla 15,14,...,1,0 tane bo�luk
				printf(" ");
				}
				for(c=1;c<=2*a-1;c++) {						//s�ras�yla 1,3,5,...,27,29 tane y�ld�z
				printf("*");
				}
			printf("\n");
			}
			break;
		case 5:												//baklava   (e�kenar d�rtgen)
			yildiz=1;
			bosluk=9;
			for(a=1;a<20;a++) {								//19 sat�r
				for(b=1;b<=bosluk;b++) {					//bosluk de�i�keni kadar bo�luk
    	        printf(" ");
    	    	}
				for(b=1;b<yildiz*2;b++) {					//yildiz de�i�keninin 2 kat�n�n 1 eksi�i kadar y�ld�z	(2*yildiz-1 kadar y�ld�z)
				printf("*");
				}
				printf("\n");
				if(a<10) {									//ilk 9 sat�r i�in bosluk ve yildiz de�i�kenlerinin de�erleri s�ras�yla bosluk=9,8,7,...,1 ve yildiz=1,2,3,...,9 olacak
					bosluk--;								//yani 1. sat�r i�in "9 bo�luk, 1 y�ld�z", 2. sat�r i�in "8 bo�luk, 3 y�ld�z", 3. sat�r i�in "7 bo�luk, 5 y�ld�z",..., 9. sat�r i�in "1 bo�luk, 17 y�ld�z"
					yildiz++;
    		    }
        		else {										//son 10 sat�r i�in bosluk ve yildiz de�i�kenlerinin de�erleri s�ras�yla bosluk=0,1,2,...,9 ve yildiz=10,9,8,...,1 olacak
					bosluk++;								//yani 10. sat�r i�in "19 y�ld�z", 11. sat�r i�in "1 bo�luk, 17 y�ld�z", 12. sat�r i�in "2 bo�luk, 15 y�ld�z",..., 19. sat�r i�in "9 bo�luk, 1 y�ld�z"
					yildiz--;
				}
			}
			break;
		case 6:												//kalp
			for(a=7;a<=15;a+=2) {							//s�ras�yla a=7,9,11,13,15 i�in, yani 5 sat�r
				for(b=1;b<15-a;b+=2) {						//a=7 i�in b=1,3,5,7; a=9 i�in b=1,3,5; a=11 i�in b=1,3; a=13 i�in b=1; a=15 i�in de okunmaz
				printf(" ");								//yani s�ras�yla 4,3,2,1 ve 0 tane bo�luk
				}
				for(b=1;b<=a;b++) {							//s�ras�yla 7,9,11,13,15 tane y�ld�z
				printf("*");
				}
				for(b=1;b<=14-a;b++) {						//s�ras�yla 7,5,3,1,0 tane bo�luk
				printf(" ");
				}
				if(a==15) {
					a--;
				}
				for(b=1;b<=a;b++) {							//s�ras�yla 7,9,11,13,14 tane y�ld�z, if olmasa sonuncusu 15 tane y�ld�z olacakt�
				printf("*");
				}
				printf("\n");
			}
			for(a=15;a>=1;a--) {							//15 sat�r
				for(b=a;b<16;b++) {							//s�ras�yla 1,2,3,...,15 tane bo�luk
				printf(" ");
				}
				for(b=1;b<=2*a-3;b++) {						//s�ras�yla 27,25,23,...,1,0 tane y�ld�z
				printf("*");
				}
				printf("\n");
			}
			break;
		case 7:												//cross   (�arp�)
			for(a=10;a>=1;a--) {							//10 sat�r
				for(b=1;b<=10-a;b++) {						//s�ras�yla 0,1,2,...,9 tane bo�luk
				printf(" ");
				}
				printf("**");								//sonra 2 tane y�ld�z
				for(b=1;b<=2*a-2;b++) {						//ard�ndan s�ras�yla 18,16,14,...,2,0 tane bo�luk
				printf(" ");
				}
				printf("**");								//son olarak da 2 tane y�ld�z
				printf("\n");
			}
			for(a=1;a<=10;a++) {							//�st yar�s�n�n birebir simetri�i
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

   say� ile �izilen desenlerde saya� tutulur

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
		sayac=n;		//mesela 7 girseydim ��kt�m b�yle olurdu:
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

   son olarak matrisli bir desen �izdirelim */

int main() {
	int m,n,i,j,sayi,sayac=1,matris[100][100];
	printf("Sayi giriniz: ");
	scanf("%d",&sayi);			//mesela 5 girseydim ��kt�m b�yle olurdu:
	printf("\n");								//"1    2    4    7    11
	for(i=1;i<=sayi;i++) {	//ilk �apraz		// 3    5    8    12   16
		m=0;	//daima 1. sat�r				// 6    9    13   17   20
		n=i-1;	//i. s�tun						// 10   14   18   21   23
		for(j=1;j<=i;j++)						// 15   19   22   24   25"
			matris[m++][n--]=sayac++;
	}	//�nce m'yi gir, sonra 1 artt�r; �nce n'yi gir, sonra 1 azalt	(1 sat�r a�a�� 1 s�tun sola)
		//e�er "++m" veya "--n" olsayd� tam tersi olurdu (�nce m'yi bir artt�r, sonra gir; �nce n'yi 1 azalt, sonra gir)
	for(i=1;i<=sayi-1;i++) {	//ikinci �apraz
		m=i;		//(i+1).sat�r
		n=sayi-1;	//daima (sayi). s�tun
		for(j=1;j<=sayi-i;j++)
			matris[m++][n--]=sayac++;	//"1 sat�r a�a�� 1 s�tun sola"ya devam
	}
		//�u ana kadar sadece matrisdeki elemanlara atama yap�ld�, gelgelelim yazd�rmaya >:)
	for(i=0;i<sayi;i++) {
		for(j=0;j<sayi;j++)
			printf("%d\t",matris[i][j]);
    	printf("\n");
	}
}
