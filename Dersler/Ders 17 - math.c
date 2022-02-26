#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* int(integer): tam sayýlar için kullanýlýr, printf ve scanf'te "%d: decimal" belirteci ile ifade edilir
                 girilen sayýnýn ondalýk kýsmýný bellekte tutmaz

   float: ondalýklý sayýlar için kullanýlýr, printf ve scanf'te "%f: float" belirteci ile ifade edilir

   double: ondalýklý sayýlar için kullanýlýr, scanf'te "%lf: long float", printf'te "%lf" veya "%f" olarak ifade edilir		(printf'te %lf ve %f ayný þey olduðundan fark etmiyor)
           float'ýn 2 katý basamak hassasiyetine sahip olduðu ve bundan ötürü de aritmetiksel iþlemlerde daha doðru sonuçlar verdiði için float'a tercih edilir

   <math.h> kütüphanesinde olan fonksiyonlar: fabs, floor, ceil, sqrt, pow, pow10, log, log10, sin, cos

   "abs: absolute value , mutlak deðer"     "fabs: float absolute , float için mutlak deðer"
   "floor: taban (küçük tam sayýya yuvarlama)"     "ceil: ceiling , tavan (büyük tam sayýya yuvarlama)"
   "sqrt: square root , karekök"     "pow: power , kuvvetini alma"
   "log: logarithm , logaritma"     "sin: sine , sinüs"     "cos: cosine , kosinüs"

   abs(x): x tam sayýsýnýn mutlak deðerini alýr		(aslýnda bu fonksiyon <stdlib.h> kütüphanesine ait)
   fabs(x): x ondalýk sayýsýnýn mutlak deðerini alýr
   floor(x): x sayýsýný kendisinden küçük en büyük tam sayýya yuvarlar
   ceil(x): x sayýsýný kendisinden büyük en küçük tam sayýya yuvarlar
   sqrt(x): x sayýsýnýn karekökünü alýr
   pow(x,y): x sayýsýnýn y. kuvvetini alýr
   pow10(x): 10 sayýsýnýn x. kuvvetini alýr
   log(x): doðal logaritma tabanýnda (e=2.71828182...) x'in logaritmasýný alýr (ln x)
   log10(x): 10 tabanýnda x'in logaritmasýný alýr (log x)
   sin(x): radyan cinsinden girilen x açýsýnýn sinüs deðerini hesaplar
   cos(x): radyan cinsinden girilen x açýsýnýn kosinüs deðerini hesaplar

   mesela:
   abs(134)=134    abs(-37)=37    fabs(-3.1792)=3.1792    fabs(11.9)=11.9
   floor(5.612)=6    floor(-4.2)=-5    ceil(5.612)=5    ceil(-4.2)=-4    floor(31)=ceil(31)=31
   sqrt(4)=2    sqrt(121)=11    pow(2,3)=2^3=8    pow(9,0.5)=9^0.5=3    pow10(2)=10^2=100
   log(10)=ln 10=2.302585    log(2.718281)=ln e=0.999999    log10(100)=log 100=2
   sin(1)=sin(1 radyan)=0.841471    cos(2)=cos(2 radyan)=-0.416146

   son olarak yukarýda "#include <kutuphaneadi.h>" syntax'ý ile kütüphane (aslýnda header dosyasý) dahil edilmezse, o kütüphanede bulunan fonksiyonlar kodumda tanýmlý olmadýðýndan bunlarý kodumda kullanamam demektir
   örneðin baþta "#include <math.h>" yazmadan math kütüphanesindeki hiçbir fonksiyondan (fabs,ceil,sqrt,log) yararlanamam, kullanabilsem dahi derleyici bana warning verir

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
