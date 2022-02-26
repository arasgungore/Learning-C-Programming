#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* int(integer): tam say�lar i�in kullan�l�r, printf ve scanf'te "%d: decimal" belirteci ile ifade edilir
                 girilen say�n�n ondal�k k�sm�n� bellekte tutmaz

   float: ondal�kl� say�lar i�in kullan�l�r, printf ve scanf'te "%f: float" belirteci ile ifade edilir

   double: ondal�kl� say�lar i�in kullan�l�r, scanf'te "%lf: long float", printf'te "%lf" veya "%f" olarak ifade edilir		(printf'te %lf ve %f ayn� �ey oldu�undan fark etmiyor)
           float'�n 2 kat� basamak hassasiyetine sahip oldu�u ve bundan �t�r� de aritmetiksel i�lemlerde daha do�ru sonu�lar verdi�i i�in float'a tercih edilir

   <math.h> k�t�phanesinde olan fonksiyonlar: fabs, floor, ceil, sqrt, pow, pow10, log, log10, sin, cos

   "abs: absolute value , mutlak de�er"     "fabs: float absolute , float i�in mutlak de�er"
   "floor: taban (k���k tam say�ya yuvarlama)"     "ceil: ceiling , tavan (b�y�k tam say�ya yuvarlama)"
   "sqrt: square root , karek�k"     "pow: power , kuvvetini alma"
   "log: logarithm , logaritma"     "sin: sine , sin�s"     "cos: cosine , kosin�s"

   abs(x): x tam say�s�n�n mutlak de�erini al�r		(asl�nda bu fonksiyon <stdlib.h> k�t�phanesine ait)
   fabs(x): x ondal�k say�s�n�n mutlak de�erini al�r
   floor(x): x say�s�n� kendisinden k���k en b�y�k tam say�ya yuvarlar
   ceil(x): x say�s�n� kendisinden b�y�k en k���k tam say�ya yuvarlar
   sqrt(x): x say�s�n�n karek�k�n� al�r
   pow(x,y): x say�s�n�n y. kuvvetini al�r
   pow10(x): 10 say�s�n�n x. kuvvetini al�r
   log(x): do�al logaritma taban�nda (e=2.71828182...) x'in logaritmas�n� al�r (ln x)
   log10(x): 10 taban�nda x'in logaritmas�n� al�r (log x)
   sin(x): radyan cinsinden girilen x a��s�n�n sin�s de�erini hesaplar
   cos(x): radyan cinsinden girilen x a��s�n�n kosin�s de�erini hesaplar

   mesela:
   abs(134)=134    abs(-37)=37    fabs(-3.1792)=3.1792    fabs(11.9)=11.9
   floor(5.612)=6    floor(-4.2)=-5    ceil(5.612)=5    ceil(-4.2)=-4    floor(31)=ceil(31)=31
   sqrt(4)=2    sqrt(121)=11    pow(2,3)=2^3=8    pow(9,0.5)=9^0.5=3    pow10(2)=10^2=100
   log(10)=ln 10=2.302585    log(2.718281)=ln e=0.999999    log10(100)=log 100=2
   sin(1)=sin(1 radyan)=0.841471    cos(2)=cos(2 radyan)=-0.416146

   son olarak yukar�da "#include <kutuphaneadi.h>" syntax'� ile k�t�phane (asl�nda header dosyas�) dahil edilmezse, o k�t�phanede bulunan fonksiyonlar kodumda tan�ml� olmad���ndan bunlar� kodumda kullanamam demektir
   �rne�in ba�ta "#include <math.h>" yazmadan math k�t�phanesindeki hi�bir fonksiyondan (fabs,ceil,sqrt,log) yararlanamam, kullanabilsem dahi derleyici bana warning verir

int main() {
	double sayi,s,c,tan,cot,sec,csc;
	printf("Aci Giriniz (radyan): ");
	scanf("%lf",&sayi);
	s=sin(sayi);
	c=cos(sayi);
	tan=s/c;
	cot=c/s;
	sec=1/c;
	csc=1/s;
	printf("\nsin %lf= %lf\ncos %lf= %lf\ntan %lf= %lf\ncot %lf= %lf\nsec %lf= %lf\ncosec %lf= %lf",sayi,s,sayi,c,sayi,tan,sayi,cot,sayi,sec,sayi,csc);
}
   
   */

int main() {
	double x,y,sonuc=1;
	int secim,i,a;
	printf("**********Hesap Makinesi Uygulamasi**********");
	printf("\n1-Mutlak Deger Alma\n2-Uste ve Alta Yuvarlama\n3-Karekok Alma\n4-Kuvvet Alma\n5-Logaritma Alma\n6-Faktoriyel Alma\n\nLutfen Secim Yapiniz: ");
	yeniden:
	scanf("%d",&secim);
	switch(secim) {
		case 1:
			printf("Sayi Girin: ");
			scanf("%lf",&x);
			sonuc=fabs(x);
			printf("Mutlak Deger: %lf",sonuc); break;
		case 2:
			printf("Sayi Girin: ");
			scanf("%lf",&x);
			sonuc=floor(x);
			printf("Taban Deger: %lf\n",sonuc);
			sonuc=ceil(x);
			printf("Tavan Deger: %lf",sonuc); break;
		case 3:
			printf("Sayi Girin: ");
			scanf("%lf",&x);
			sonuc=sqrt(x);
			printf("Karekok: %lf",sonuc); break;
		case 4:
			printf("Tabani Girin: ");
			scanf("%lf",&x);
			printf("Ussu Girin: ");
			scanf("%lf",&y);
			sonuc=pow(x,y);
			printf("Sonuc: %lf",sonuc); break;
		case 5:
			printf("Sayi Girin: ");
			scanf("%lf",&x);
			printf("Taban Girin: ");
			scanf("%lf",&y);
			sonuc=log(x)/log(y);
			printf("Sonuc: %lf",sonuc); break;
		case 6:
			printf("Sayi Gir: ");
			scanf("%d",&a);
			for(i=1;i<=a;i++) {
				sonuc=sonuc*i;
			}
			printf("%d!=%f",a,sonuc); break;
		default:
			printf("Hatali Giris Yaptiniz, Lutfen Tekrar Deneyiniz: ");
			goto yeniden;
	}
	return 0;
}
