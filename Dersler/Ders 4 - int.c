#include <stdio.h>
#include <stdlib.h>

/* "int: integer"
   ad� �zerinde, int de�i�kenine atad���m de�erler sadece ama sadece tam say� olmal�    (char'�n aksine, birden fazla rakam atayabilirim)
   string'e veya char[]'a (ayn� �ey) tam say� atayabilirim ancak aritmetik i�lemlerde kullanamam, yazd���m say�lar sadece sembolik olur
   scanf ve printf'de int de�i�kenini temsil etmek ama�l� "%d: decimal" belirtecini kullan�yoruz    (char ==> %s veya %c , int ==> %d)
   "+: toplama operat�r�"          "-: ��karma operat�r�"          "*: �arpma operat�r�"          "/: b�lme operat�r�"
   int ve %d belirteci ondal�k say�larla ilgilenmedi�i i�in virg�lden sonras�n� haf�zaya almaz, misal 10/6=1, 2/3=0 olarak girer  (normalde 10/6=1.66666..., 2/3=0.66666... ama virg�lden sonras�n� bilgisayar alm�yor)
   haf�zada gereksiz yere fazladan yer kaplamamak i�in float ve double de�i�kenleri ve %f belirteci yerine int ve %d belirteci kullan�l�r
   
int main() {																			int main() {

	int kenar1,kenar2,cevre,alan;															int normal,el,fiyat;
	
	kenar1=12;																				normal=23;
	kenar2=8;																				el=11;
	alan=kenar1*kenar2;																		fiyat=(normal-15+el-8)*5;       //normal bagaj ve el bagaj i�in de s�n�r� a�an her kilo ba�� 5 TL
	cevre=2*(kenar1+kenar2);																printf("Odemeniz gereken fiyat %d TL'dir.",fiyat);

	printf("Dikdortgen Alani: %d\n",alan);												}
	printf("Dikdortgen Cevresi: %d",cevre);

}

   hadi EE 101 notumuzu hesaplayal�m ;)

int main() {																			int main() {

    int lab1,lab2,lab3,participation,midterm,proje,ort;										int kenar,alan;

    lab1=95;																				kenar=6;
    lab2=51;																				alan=kenar*kenar*sqrt(3)/4;		//karek�k fonksiyonu i�in <math.h> k�t�phanesini import etmek gerekli de buna ileride de�inece�iz
	lab3=97;																				printf("Kenari %d olan eskenar ucgenin alani %d'dir",kenar,alan);
	participation=100;
	midterm=85;																			}
	proje=100;
    ort=(lab1*10+lab2*10+lab3*10+participation*10+midterm*35+proje*25)/100;

	printf("Ortalamaniz: %d\nAA ile gectiniz. Tebrikler.",ort);

}

   hadi swap yapal�m

int main() {

	int a=22,b=33,gecici;
	printf("Takas oncesi: a=%d , b=%d\n\n",a,b);
	gecici=a;
	a=b;
	b=gecici;
	printf("Takas sonrasi: a=%d , b=%d",a,b);

} */

int main() {

	int sayi1,sayi2,topla,cikar,carp,bol;

	sayi1=10;
	sayi2=3;
	topla=sayi1+sayi2;
	cikar=sayi1-sayi2;
	carp=sayi1*sayi2;
	bol=sayi1/sayi2;

	printf("Toplam: %d\nFark: %d\nCarpim: %d\nBolum: %d",topla,cikar,carp,bol);

	return 0;
}
