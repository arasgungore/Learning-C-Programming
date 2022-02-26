#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

/* "ternary: �� par�al�, ��l�, �� ko�ul operat�r�"
   �ncelikle k�saca �u ana kadar ��rendi�imiz ve ��renece�imiz b�t�n operat�rleri bir tekrar edelim
   1) aritmetiksel operat�rler:
       "+": toplama
       "-": ��karma
       "*": �arpma
       "/": b�lme
       "%": mod alma
   2) atama (assignment) operat�rleri:
       "=": atama
       "+=": artt�rma, topla-ata
       "-=": azaltma, ��kar-ata
       "*=": kat�n� alma, �arp-ata
       "/=": b�l�m�n� alma, b�l-ata
       "%=": kalan�n� alma, mod al-ata
       "++": bir artt�rma
       "--": bir azaltma      (solda ise pre-increment/decrement, sa�da ise post-increment/decrement)
   3) mant�ksal (logical) operat�rler:
       "&&": ve
       "||": veya
       "!": de�il
   4) kar��la�t�rma (comparison), ili�kisel (relational) operat�rler:
       "==": e�it midir
       "!=": e�it de�il midir
       "<": k���k m�d�r
       "<=": k���k e�it midir
       ">": b�y�k m�d�r
       ">=": b�y�k e�it midir
   5) ikidelik, bitsel (bitwise) operat�rler:   (bunlardan daha sonra tekrar bahsedece�im)
       "&": bitsel VE (AND)
       "|": bitsel VEYA (OR)
       "^": bitsel YA DA (XOR)
       "~": bitsel t�mleyen
       "<<": sola kayd�r (left shift)
       ">>": sa�a kayd�r (right shift)
   6) ko�ula ba�l� (conditional) operat�r:   (mevzubahis bu)
       "?:": ternary (��l� ko�ul)

   �u an bu listenin sonunda yer alan ve ayn� zamanda bu serinin ilk dersinin en sonunda de�indi�im ko�ula ba�l� (conditional) ternary operat�r�n� g�rece�iz
   genel syntax'� "kosul ? kosul_dogru_ise_ben : kosul_yanlis_ise_ben" olan ternary operat�r� if else ile ayn� mant�kta �al���r
   zaten bu operat�rle yap�p if else if else ile yapamayaca��n hi�bir �ey yok

   �rne�in if else ile yaz�lm�� olan bu kod:								alternatif olarak ��yle yaz�labilir:

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

   o zaman hadi �rneklere bakal�m

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

   bir 2 bir 5 artan �r�nt�											girdi�imiz say� pozitif mi negatif mi ona bakal�m

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
}	//belirte�lere atanacak parametreler DA�MA en sona yaz�l�r

   makro ile fonksiyon tan�mlarken de ternary operat�r�n� kullanabiliriz

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
	return 0;	//birinci say� ikinciden k���k ve 5'ten b�y�k �ift bir say� ise ko�ul do�ru (true), de�ilse yanl�� (false)
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
	setlocale(LC_ALL,"Turkish");	//arada �ylesine T�rk�e karakterlerle yazd�rmay� seviyorum
	int a;
	printf("Bir say� giriniz: ");
	scanf("%d",&a);
	printf( a>0 ? (a%2==0 ? "%d pozitif �ift bir say�" : "%d pozitif tek bir say�") : (a<0 ? "%d negatif bir say�, mutlak de�eri %d" : "S�f�r i�te la"),a,abs(a));
}
