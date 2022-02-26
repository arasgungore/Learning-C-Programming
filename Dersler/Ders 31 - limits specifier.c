#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*

int main() {
	int min_deger=INT_MIN;	//int deðiþkeninin bellekte tutabildiði maksimum deðer
	int max_deger=INT_MAX;	//int deðiþkeninin bellekte tutabildiði minimum deðer
	printf("INT_MAX: %d\nINT_MIN: %d\n",min_deger,max_deger);
	int a=max_deger+1;		//int 4 byte=32 bit olduðundan çýktýlarým 2^31="-2147483648" ve (2^31)-1="2147483647"
	printf("INT_MAX+1=%d",a);	//çýktým INT_MIN="-2147483648"
}

	yukarýda gözlemlenen INT_MAX+1=INT_MIN olayýna "overflow" adý verilir
	aslýnda bilgisayar verileri mod biçiminde saklar, misal bu int veri tipi için atanan_deger%(2^32)=saklanan_deger biçimindedir
	baþka bir deyiþle bilgisayar maksimum deðeri aþtýðýnda baþa (minimum deðere) sararken minimum deðeri aþtýðýnda sona (maksimum deðere) sarar

int main() {
	printf("INT_MIN: %d\tINT_MAX: %d\nSHRT_MIN: %hi\tSHRT_MAX: %hi\nLONG_MIN: %ld\tLONG_MAX: %ld\nLONG_LONG_MIN: %lld\tLONG_LONG_MAX: %lld",INT_MIN,INT_MAX,SHRT_MIN,SHRT_MAX,LONG_MIN,LONG_MAX,LONG_LONG_MIN,LONG_LONG_MAX);
}

int main() {
	printf("Number of bits in a byte\t=\t%d\n",CHAR_BIT);
	printf("Minimum value of SIGNED CHAR\t=\t%d\n",SCHAR_MIN);
	printf("Maximum value of SIGNED CHAR\t=\t%d\n",SCHAR_MAX);
	printf("Maximum value of UNSIGNED CHAR\t=\t%d\n",UCHAR_MAX);
	printf("Minimum value of SHORT INT\t=\t%d\n",SHRT_MIN);
	printf("Maximum value of SHORT INT\t=\t%d\n",SHRT_MAX);
	printf("Minimum value of INT\t\t=\t%d\n",INT_MIN);
	printf("Maximum value of INT\t\t=\t%d\n",INT_MAX);
	printf("Minimum value of CHAR\t\t=\t%d\n",CHAR_MIN);
	printf("Maximum value of CHAR\t\t=\t%d\n",CHAR_MAX);
	printf("Minimum value of LONG\t\t=\t%ld\n",LONG_MIN);
	printf("Maximum value of LONG\t\t=\t%ld\n",LONG_MAX);
	return 0;
}

   int ile long Windows'ta ayný, aslýnda standart þöyle: char => en az 1 byte (8 bit), int => en az 2 byte (16 bit), long (int) => en az 4 byte (32 bit), long long (int) => en az 8 byte (64 bit)
   çoðu iþletim sisteminde uzun bir süredir (no pun intended) int 4 byte (32 bit) olduðu için böyle bir karýþýklýða yol açmýþ olabilir

   "specifier: belirteç"
   printf ve scanf içinde veri tiplerini yazdýrmak ve okumak için kullanýlan ve '%' iþareti ile belirtilen (no pun intended x2) ifadeler belirteç denir
   C dilindeki belirteçler þunlardýr:
   %c (character): "char" veri tipini yazdýrmak ve okumak için kullanýlýr
   %s (string): "string" veri tipini yazdýrmak ve okumak için kullanýlýr
   %d (decimal), %i (integer): "(signed) int" veri tipini yazdýrmak ve okumak için kullanýlýr
   %hi (short integer): "(signed) short" veri tipini yazdýrmak ve okumak için kullanýlýr
   %l (long), %ld (long decimal), %li (long int): "(signed) long" veri tipini yazdýrmak ve okumak için kullanýlýr
   %lld (long long decimal), %lli (long long int), %l64d (long 64 bit decimal): "(signed) long long" veri tipini yazdýrmak ve okumak için kullanýlýr
   %f (float): "float" veri tipini yazdýrmak ve okumak için kullanýlýr, alternatif olarak double veri tipini yazdýrmak için de kullanýlabilir
   %lf (long float): "double" veri tipini yazdýrmak ve okumak için kullanýlýr
   %u (unsigned int): "unsigned int" veri tipini yazdýrmak ve okumak için kullanýlýr
   %hu (unsigned short): "unsigned short" veri tipini yazdýrmak ve okumak için kullanýlýr
   %lu (unsigned long): "unsigned long" veri tipini yazdýrmak ve okumak için kullanýlýr
   %llu (unsigned long long): "unsigned long long" veri tipini yazdýrmak ve okumak için kullanýlýr
   %p (pointer): "pointer" (baþka bir deyiþle "void *") veri tipini yazdýrmak ve okumak için kullanýlýr
   %o (octal): "unsigned int" veri tipini 8 tabanýnda yazdýrmak ve okumak için kullanýlýr
   %x, %X (hexadecimal): "unsigned int" veri tipini 16 tabanýnda yazdýrmak ve okumak için kullanýlýr, ayrýca adresleri hexadecimal olarak yazdýrmak için "%p"ye alternatif olarak kullanýlabilir
   %e, %E: "float" ve "double" veri tiplerini bilimsel gösterimiyle yazdýrmak için kullanýlýr
   %g, %G: "float" ve "double" veri tiplerini bilimsel gösterimiyle yazdýrmak için kullanýlýr
   		   ama "%e" ve "%E" belirteçlerinin aksine eðer veri tipinin "%f" belirteci ile gösterimi (ondalýk gösterimi) daha kýsa ise bilimsel gösterimini (%e, %E) deðil ondalýk gösterimini (%f) yazdýrýr
   %n (nothing): hiçbir þey yazdýrmaz
   %%: '%' karakterini yazdýrmak için kullanýlýr

int main() {													int main() {
	unsigned int a;													float x=457.32649;
	printf("a'nin degerini giriniz: ");								double y=31934.213553;
	scanf("%u",&a);													int z=897365;
	printf("Decimal karsiligi: %i\n",a);							printf("x=%e\n",x);
	printf("Octal karsiligi: %o\n",a);								printf("y=%e\n",y);
	printf("Hexadecimal karsiligi: %X\n",a);						printf("z=%E\n",(double)z);
	printf("Adresi: %p",&a);										printf("x*y=%e\nx/y=%e\nx/y/z=%E",x*y,x/y,x/y/z);
}																}

*/

#define N 5
int main() {
	double dizi[N]={31.69, 896.956, 56000.0, 2.789605431, 91839150.713189};
	int i;
	for(i=0;i<N;i++) {
		printf("%%.4f: %.4f\n",dizi[i]);
		printf("%%.2f: %.2f\n",dizi[i]);
		printf("%%f: %f\n",dizi[i]);
		printf("%%e: %e\n",dizi[i]);
		printf("%%g: %g\n\n\n",dizi[i]);
	}
}
