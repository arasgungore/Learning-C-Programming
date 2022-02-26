#include <stdio.h>
#include <stdlib.h>

/* "if: e�er b�yle ise"			"else: e�er b�yle de�ilse"
   karar yap�lar� olarak kullan�lan if ve ard�ndan gelen else'�n syntax'� if a� parantez kapa parantez a� s�sl� parantez kapa s�sl� parantez else a� s�sl� parantez kapa s�sl� parantez
   yani if() {
   }
   else {
   }				bi�imindedir
   if yap�s�nda parantez i�ine girilen ko�ul sa�lan�yorsa scope i�indeki komutu uygular, aksi takdirde alt�ndaki else yap�s�n�n scope'u i�indeki komutu uygular
   her else komutu sadece bir �st�ndeki if i�in ge�erlidir (if (1) {}, if (2) {}, if (3) {}, else {} bi�iminde ise kodum; else {} sadece if (3) {} �n tersini alg�lar)
   zaten else bir �st�ndeki if'in ko�ulunun tam tersini alg�lad��� i�in kendisine if'teki gibi ko�ul tan�mlamaya gerek yok 
   else olmadan da onun yerine sadece if kullan�labilir (amelelik olsa da biraz)
   "=: atama (e�ittir)"				"==: sorgulama (e�it midir?)"
   "< >: k���k m�d�r?  b�y�k m�d�r?"				"<=  >=: k���k e�it midir?  b�y�k e�it midir?"  (e�ittir hep sa�da)
   "&&: and , ve (iki ko�ulu da ayn� anda sa�layan de�erler i�in)"                "||: or , veya (iki ko�ulun ayr� ayr� sa�land��� b�t�n de�erler i�in)"


int main() {													int main() {																	int main () {

	int sayi=4;														int sayi1,sayi2,toplam;															int s1,s2,ort;

	if(sayi==5)														sayi1=24;																		printf("1. s�navinizi girin: ");
	{																sayi2=28;																		scanf("%d",&s1);
		printf("Sayi bese esittir");								toplam=sayi1+sayi2;
	}																																				printf("2. sinavinizi girin: ");
	else															if(toplam<=50)																	scanf("%d",&s2);
	{																{
		printf("Sayi bese esit degildir");								printf("Toplam degeriniz %d 50'den kucuk",toplam);							ort=(s1+s2)/2;
	}																}																				printf("Ortalama: %d\n\n",ort);
	return 0;														else
}																	{																				if(ort>=50) {
																																						printf("Tebrikler gectiniz :)))");
																		printf("Toplam degeriniz %d 50'den buyuk",toplam);							}
																	}																				else {
																}																						printf("Maalesef kaldiniz :(((");
																																					}
																																				}

int main() {

	int sayi1,sayi2,sayi3;

	printf("Uc tane sayi giriniz: ");
	scanf("%d %d %d",&sayi1,&sayi2,&sayi3);

	if(sayi1>sayi2 && sayi1>sayi3) {
		printf("Birinci sayi en buyuk\t(%d>%d && %d>%d)",sayi1,sayi2,sayi1,sayi3);
	}

	if(sayi2>sayi1 && sayi2>sayi3) {
		printf("Ikinci sayi en buyuk\t(%d>%d && %d>%d)",sayi2,sayi1,sayi2,sayi3);
	}

	if(sayi3>sayi1 && sayi3>sayi2) {
		printf("Ucuncu sayi en buyuk\t(%d>%d && %d>%d)",sayi3,sayi1,sayi3,sayi2);
	}
}

   o zaman hadi MATH 101 notumuzu hesaplayal�m...

int main () {

	float sinav1,sinav2,final,ort;

	printf("Birinci Sinav Notunu Giriniz: ");
	scanf("%f",&sinav1);

	printf("Ikinci Sinav Notunu Giriniz: ");
	scanf("%f",&sinav2);

	printf("Final Notunu Giriniz: ");
	scanf("%f",&final);

	ort=(30*sinav1+30*sinav2+40*final)/100;

	if(85<=ort && ort<=100) {
		printf("Not Ortalamaniz: %f\nAA aldin lan serefsiz, siktir git amcik",ort);
	}

	if(80<=ort && ort<85) {
		printf("Not Ortalamaniz: %f\nBA aldin, ulan pezevenk yine iyisin",ort);
	}

	if(75<=ort && ort<80) {
		printf("Not Ortalamaniz: %f\nBB aldin, fena degil benc",ort);
	}

	if(65<=ort && ort<75) {
		printf("Not Ortalamaniz: %f\nCB aldin, calissan raad BA vardi da sal b'olum",ort);
	}

	if(50<=ort && ort<65) {
		printf("Not Ortalamaniz: %f\nCC aldin, dersi gectin mi gectin, keyfine bak",ort);
	}

	if (ort<50) {
		printf("Not Ortalamaniz: %f\nF aldin, en azindan hayattayiz, bu da bi sey abi",ort);	//bu kod if, if, if,..., if yerine if, else if, else if,..., else if, else olarak da yaz�labilirdi
	}

	return 0;

}

   "else if: e�er �yle de�il de b�yleyse"	(ne bilem xd)
   program�n yukar�daki �rnekteki gibi gereksiz y�zlerce if yap�lar�n� da okuyup bilgisayar�n �al��mas�n� aksatmamak ve performans� artt�rmak i�in programc�lar if-else if-else yap�lar�n� kullan�rlar
   syntax'�:
   if() {
   } else if() {
   } else if() {
   } else if() {
   } ...
   else {
   }				bi�imindedir
   if yap�s�nda parantez i�ine girilen ko�ul sa�lan�yorsa scope i�indeki komutu uygular, aksi takdirde alt�ndaki else if yap�s�n�n scope'u i�indeki komutu uygular
   else if yap�s�nda parantez i�ine girilen ko�ul sa�lan�yorsa scope i�indeki komutu uygular, aksi takdirde alt�ndaki else if veya else yap�s�n�n scope'u i�indeki komutu uygular
   �stteki if veya else if yap�lar�n�n ko�ullar�ndan biri do�ruysa alttaki else if'ler okunmayaca��ndan dolay� program else if yap�lar�yla daha h�zl� ve verimli bir �ekilde �al���r */

int main() {
	int kilo;	//kg
	float boy;	//m		(177 cm=1.77 m)

	printf("Kilo (kg) ve boyunuzu (m) giriniz: ");
	scanf("%d %f",&kilo,&boy);

	double bki=(double)kilo/(double)(boy*boy);		//float'a g�re daha fazla precision i�in double kulland�m, ayr�ca explicit casting yapt�m

	if(bki<18.5) printf("Zayif");
	else if(bki<25) printf("Normal");				//else if(18.5<=bki && bki<25) ile ayn� �ey
	else if(bki<30) printf("Fazla kilolu");			//else if(25<=bki && bki<30) ile ayn� �ey
	else if(bki<35) printf("I. derece obez");		//else if(30<=bki && bki<35) ile ayn� �ey
	else if(bki<40) printf("II. derece obez");		//else if(35<=bki && bki<40) ile ayn� �ey
	else printf("III. derece obez");				//else if(40<=bki) ile ayn� �ey

	return 0;
}
