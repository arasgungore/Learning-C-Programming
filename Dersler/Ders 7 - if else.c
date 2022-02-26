#include <stdio.h>
#include <stdlib.h>

/* "if: eðer böyle ise"			"else: eðer böyle deðilse"
   karar yapýlarý olarak kullanýlan if ve ardýndan gelen else'ýn syntax'ý if aç parantez kapa parantez aç süslü parantez kapa süslü parantez else aç süslü parantez kapa süslü parantez
   yani if() {
   }
   else {
   }				biçimindedir
   if yapýsýnda parantez içine girilen koþul saðlanýyorsa scope içindeki komutu uygular, aksi takdirde altýndaki else yapýsýnýn scope'u içindeki komutu uygular
   her else komutu sadece bir üstündeki if için geçerlidir (if (1) {}, if (2) {}, if (3) {}, else {} biçiminde ise kodum; else {} sadece if (3) {} ün tersini algýlar)
   zaten else bir üstündeki if'in koþulunun tam tersini algýladýðý için kendisine if'teki gibi koþul tanýmlamaya gerek yok 
   else olmadan da onun yerine sadece if kullanýlabilir (amelelik olsa da biraz)
   "=: atama (eþittir)"				"==: sorgulama (eþit midir?)"
   "< >: küçük müdür?  büyük müdür?"				"<=  >=: küçük eþit midir?  büyük eþit midir?"  (eþittir hep saðda)
   "&&: and , ve (iki koþulu da ayný anda saðlayan deðerler için)"                "||: or , veya (iki koþulun ayrý ayrý saðlandýðý bütün deðerler için)"


int main() {													int main() {																	int main () {

	int sayi=4;														int sayi1,sayi2,toplam;															int s1,s2,ort;

	if(sayi==5)														sayi1=24;																		printf("1. sýnavinizi girin: ");
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

   o zaman hadi MATH 101 notumuzu hesaplayalým...

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
		printf("Not Ortalamaniz: %f\nF aldin, en azindan hayattayiz, bu da bi sey abi",ort);	//bu kod if, if, if,..., if yerine if, else if, else if,..., else if, else olarak da yazýlabilirdi
	}

	return 0;

}

   "else if: eðer öyle deðil de böyleyse"	(ne bilem xd)
   programýn yukarýdaki örnekteki gibi gereksiz yüzlerce if yapýlarýný da okuyup bilgisayarýn çalýþmasýný aksatmamak ve performansý arttýrmak için programcýlar if-else if-else yapýlarýný kullanýrlar
   syntax'ý:
   if() {
   } else if() {
   } else if() {
   } else if() {
   } ...
   else {
   }				biçimindedir
   if yapýsýnda parantez içine girilen koþul saðlanýyorsa scope içindeki komutu uygular, aksi takdirde altýndaki else if yapýsýnýn scope'u içindeki komutu uygular
   else if yapýsýnda parantez içine girilen koþul saðlanýyorsa scope içindeki komutu uygular, aksi takdirde altýndaki else if veya else yapýsýnýn scope'u içindeki komutu uygular
   üstteki if veya else if yapýlarýnýn koþullarýndan biri doðruysa alttaki else if'ler okunmayacaðýndan dolayý program else if yapýlarýyla daha hýzlý ve verimli bir þekilde çalýþýr */

int main() {
	int kilo;	//kg
	float boy;	//m		(177 cm=1.77 m)

	printf("Kilo (kg) ve boyunuzu (m) giriniz: ");
	scanf("%d %f",&kilo,&boy);

	double bki=(double)kilo/(double)(boy*boy);		//float'a göre daha fazla precision için double kullandým, ayrýca explicit casting yaptým

	if(bki<18.5) printf("Zayif");
	else if(bki<25) printf("Normal");				//else if(18.5<=bki && bki<25) ile ayný þey
	else if(bki<30) printf("Fazla kilolu");			//else if(25<=bki && bki<30) ile ayný þey
	else if(bki<35) printf("I. derece obez");		//else if(30<=bki && bki<35) ile ayný þey
	else if(bki<40) printf("II. derece obez");		//else if(35<=bki && bki<40) ile ayný þey
	else printf("III. derece obez");				//else if(40<=bki) ile ayný þey

	return 0;
}
