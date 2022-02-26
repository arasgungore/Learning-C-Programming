#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/* "ternary: üç parçalý, üçlü, üç koþul operatörü"
   öncelikle kýsaca þu ana kadar öðrendiðimiz ve öðreneceðimiz bütün operatörleri bir tekrar edelim
   1) aritmetiksel operatörler:
       "+": toplama
       "-": çýkarma
       "*": çarpma
       "/": bölme
       "%": mod alma
   2) atama (assignment) operatörleri:
       "=": atama
       "+=": arttýrma, topla-ata
       "-=": azaltma, çýkar-ata
       "*=": katýný alma, çarp-ata
       "/=": bölümünü alma, böl-ata
       "%=": kalanýný alma, mod al-ata
       "++": bir arttýrma
       "--": bir azaltma      (solda ise pre-increment/decrement, saðda ise post-increment/decrement)
   3) mantýksal (logical) operatörler:
       "&&": ve
       "||": veya
       "!": deðil
   4) karþýlaþtýrma (comparison), iliþkisel (relational) operatörler:
       "==": eþit midir
       "!=": eþit deðil midir
       "<": küçük müdür
       "<=": küçük eþit midir
       ">": büyük müdür
       ">=": büyük eþit midir
   5) ikidelik, bitsel (bitwise) operatörler:   (bunlardan daha sonra tekrar bahsedeceðim)
       "&": bitsel VE (AND)
       "|": bitsel VEYA (OR)
       "^": bitsel YA DA (XOR)
       "~": bitsel tümleyen
       "<<": sola kaydýr (left shift)
       ">>": saða kaydýr (right shift)
   6) koþula baðlý (conditional) operatör:   (mevzubahis bu)
       "?:": ternary (üçlü koþul)

   þu an bu listenin sonunda yer alan ve ayný zamanda bu serinin ilk dersinin en sonunda deðindiðim koþula baðlý (conditional) ternary operatörünü göreceðiz
   genel syntax'ý "kosul ? kosul_dogru_ise_ben : kosul_yanlis_ise_ben" olan ternary operatörü if else ile ayný mantýkta çalýþýr
   zaten bu operatörle yapýp if else if else ile yapamayacaðýn hiçbir þey yok

   örneðin if else ile yazýlmýþ olan bu kod:								alternatif olarak þöyle yazýlabilir:

int main() {																int main() {
	int a=1, b=2, cevap;														int a=1, b=2, cevap;
	if(a==1) {																	cevap = (a==1 ? (b==2 ? 3 : 5) : 0);
		if(b==2) {																printf("Cevap: %d", cevap);		//cevap "3" bu arada xd
			cevap=3;														}
		}
		else {
			cevap=5;
		}
	}
	else {
		cevap=0;
	}
	printf("Cevap: %d", cevap);
}

   o zaman hadi örneklere bakalým

int main() {
	printf( 2==3 ? "Dogru\n" : "Yanlis\n");
	printf( 3<5 ? "Dogru\n" : "Yanlis\n");
	printf( 1+3==2+2 ? "Dogru\n" : "Yanlis\n");
	printf( pow(2,4)==pow(4,2) ? "Dogru\n" : "Yanlis\n");
	printf( strcmp("elma","armut")>0 ? "Dogru\n" : "Yanlis\n");
	printf( strchr("abcdefghi",'j') ? "Dogru\n" : "Yanlis\n");
	printf( strlen("patates")==7 ? "Dogru" : "Yanlis");
}	//"Yanlis, Dogru, Dogru, Dogru, Dogru, Yanlis, Dogru"

int main() {														int main() {
	int a,b,c,max;														int a,b;
	printf("Uc sayi giriniz: ");										a=10;
	scanf("%d%d%d",&a,&b,&c);											printf("b'nin degeri: %d" a==10 ? 20 : 30);	//"20"
	max= a>b ? (a>c ? a : c) : (b>c ? b : c);							printf("b'nin degeri: %d" a==1 ? 20 : 30);	//"30"
	printf("Girdiginiz sayilardan en buyugu: %d",max);				}
}

   bir 2 bir 5 artan örüntü											girdiðimiz sayý pozitif mi negatif mi ona bakalým

int main() {														int main() {
	int a=0,i;															int x;
	for(i=1;i<=20;i++) {												printf("Sayi giriniz: ");
		a+= i%2==1 ? 2 : 5;												scanf("%d",&x);
		printf("%d ",a);												printf( x>0 ? "Girdiginiz sayi pozitif" : (x<0 ? "Girdiginiz sayi negatif" : "Girdiginiz sayi sifir"));
	}																}
}

int main() {
	int a,b;
	printf("Iki sayi giriniz: ");
	scanf("%d%d",&a,&b);
	printf( (a>0 && b>0) ? ((a%b==0) ? "%d %d'ye tam bolunur" : "%d %d'ye tam bolunmez") : "Negatif girdi gecersiz",a,b);
}	//belirteçlere atanacak parametreler DAÝMA en sona yazýlýr

   makro ile fonksiyon tanýmlarken de ternary operatörünü kullanabiliriz

#define maksimum(s1,s2) s1>s2 ? s1 : s2
#define minimum(s1,s2) s1<s2 ? s1 : s2
#define tambolunurmu(s1,s2) s1%s2==0 || s2%s1==0 ? "bolunur" : "bolunmez"
int main() {
	int x,y;
	printf("Iki sayi giriniz: ");
	scanf("%d%d",&x,&y);
	printf("Buyuk sayi: %d\nKucuk sayi: %d", maksimum(x,y), minimum(x,y));
	printf("\n%d %d'ye tam %s", maksimum(x,y), minimum(x,y), tambolunurmu(x,y));
}

#define MAK01(id1,id2)  (id1<id2) && (id1>5) && (id1%2==0) ? 1 : 0
int main() {
	int sayi1,sayi2;
	printf("Bir int deger giriniz: ");
	scanf("%d",&sayi1);
	printf("Bir int deger daha giriniz: ");
	scanf("%d",&sayi2);
	printf("(sayi1<sayi2 && sayi1>5 && sayi1%%2==0)=%d",MAK01(sayi1,sayi2));
	return 0;	//birinci sayý ikinciden küçük ve 5'ten büyük çift bir sayý ise koþul doðru (true), deðilse yanlýþ (false)
}

#define mutlak_deger(sayi)  sayi>=0 ? sayi : -sayi
#define mutlak_deger_yazdir(sayi)  printf("%d'nin mutlak degeri: %d\n",sayi,mutlak_deger(sayi));
int main() {
	int i;
	for(i=-100;i<=100;i++)
		mutlak_deger_yazdir(i);
	return 0;
} */

int main() {
	setlocale(LC_ALL,"Turkish");	//arada öylesine Türkçe karakterlerle yazdýrmayý seviyorum
	int a;
	printf("Bir sayý giriniz: ");
	scanf("%d",&a);
	printf( a>0 ? (a%2==0 ? "%d pozitif çift bir sayý" : "%d pozitif tek bir sayý") : (a<0 ? "%d negatif bir sayý, mutlak deðeri %d" : "Sýfýr iþte la"),a,abs(a));
}
