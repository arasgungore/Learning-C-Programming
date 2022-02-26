#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*

int main() {
	int min_deger=INT_MIN;	//int de�i�keninin bellekte tutabildi�i maksimum de�er
	int max_deger=INT_MAX;	//int de�i�keninin bellekte tutabildi�i minimum de�er
	printf("INT_MAX: %d\nINT_MIN: %d\n",min_deger,max_deger);
	int a=max_deger+1;		//int 4 byte=32 bit oldu�undan ��kt�lar�m 2^31="-2147483648" ve (2^31)-1="2147483647"
	printf("INT_MAX+1=%d",a);	//��kt�m INT_MIN="-2147483648"
}

	yukar�da g�zlemlenen INT_MAX+1=INT_MIN olay�na "overflow" ad� verilir
	asl�nda bilgisayar verileri mod bi�iminde saklar, misal bu int veri tipi i�in atanan_deger%(2^32)=saklanan_deger bi�imindedir
	ba�ka bir deyi�le bilgisayar maksimum de�eri a�t���nda ba�a (minimum de�ere) sararken minimum de�eri a�t���nda sona (maksimum de�ere) sarar

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

   int ile long Windows'ta ayn�, asl�nda standart ��yle: char => en az 1 byte (8 bit), int => en az 2 byte (16 bit), long (int) => en az 4 byte (32 bit), long long (int) => en az 8 byte (64 bit)
   �o�u i�letim sisteminde uzun bir s�redir (no pun intended) int 4 byte (32 bit) oldu�u i�in b�yle bir kar���kl��a yol a�m�� olabilir

   "specifier: belirte�"
   printf ve scanf i�inde veri tiplerini yazd�rmak ve okumak i�in kullan�lan ve '%' i�areti ile belirtilen (no pun intended x2) ifadeler belirte� denir
   C dilindeki belirte�ler �unlard�r:
   %c (character): "char" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %s (string): "string" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %d (decimal), %i (integer): "(signed) int" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %hi (short integer): "(signed) short" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %l (long), %ld (long decimal), %li (long int): "(signed) long" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %lld (long long decimal), %lli (long long int), %l64d (long 64 bit decimal): "(signed) long long" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %f (float): "float" veri tipini yazd�rmak ve okumak i�in kullan�l�r, alternatif olarak double veri tipini yazd�rmak i�in de kullan�labilir
   %lf (long float): "double" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %u (unsigned int): "unsigned int" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %hu (unsigned short): "unsigned short" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %lu (unsigned long): "unsigned long" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %llu (unsigned long long): "unsigned long long" veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %p (pointer): "pointer" (ba�ka bir deyi�le "void *") veri tipini yazd�rmak ve okumak i�in kullan�l�r
   %o (octal): "unsigned int" veri tipini 8 taban�nda yazd�rmak ve okumak i�in kullan�l�r
   %x, %X (hexadecimal): "unsigned int" veri tipini 16 taban�nda yazd�rmak ve okumak i�in kullan�l�r, ayr�ca adresleri hexadecimal olarak yazd�rmak i�in "%p"ye alternatif olarak kullan�labilir
   %e, %E: "float" ve "double" veri tiplerini bilimsel g�sterimiyle yazd�rmak i�in kullan�l�r
   %g, %G: "float" ve "double" veri tiplerini bilimsel g�sterimiyle yazd�rmak i�in kullan�l�r
   		   ama "%e" ve "%E" belirte�lerinin aksine e�er veri tipinin "%f" belirteci ile g�sterimi (ondal�k g�sterimi) daha k�sa ise bilimsel g�sterimini (%e, %E) de�il ondal�k g�sterimini (%f) yazd�r�r
   %n (nothing): hi�bir �ey yazd�rmaz
   %%: '%' karakterini yazd�rmak i�in kullan�l�r

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
