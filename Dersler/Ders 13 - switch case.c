#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* "switch: anahtar"     "case:durum"
   esas conditional statement'�m�z olan if'e, ya da daha geni� bir �ekilde if, else if, else if, ..., else yap�s�na alternatif olarak switch case conditional statement'� kullan�l�r
   switch case'in genel syntax'� switch a� parantez de�i�kenad� kapa parantez a� s�sl� parantez kapa s�sl� parantez
   yani switch(degiskenadi) {
    	}						bi�imindedir, ve scope i�ine de case'ler yaz�l�r

   o y�zden en genel haliyle syntax'�m�z ==>	switch(degiskenadi) {
   													case 'deger1':
													case 'deger2':
													case 'deger3':
													}								bi�imindedir
	switch fonksiyonu beni i�ine yazd���m de�i�kenin de�erine g�re beni o de�er i�in yaz�l� case'e g�nderecek
	"break: fren"				break komutu, kodu o sat�rda durdurmak i�in kullan�l�r
	e�er break koymazsam her bir case'ten sonra o zaman ondan sonraki case'leri de bilgisayar okur
	"default: varsay�lan"		e�er girdi�im case tan�ml� de�ilse, bilgisayar buna girili komutu okur    (default bir bak�ma else yap�s� gibi burada)
	zaten baz� dillerde (mesela Python'da) switch case'in i�levini if, else if, else if, ..., else yap�s� g�rd���nden switch case bulunmaz bile

int main() {
	char grade;
	printf("Enter your grade: ");
	scanf("%c",&grade);

	switch(grade) {
		case 'A':
			printf("Excellent!\n");
			break;
		case 'B':
		case 'C':
			printf("Well done\n");
			break;
		case 'D':
			printf("You passed\n");
			break;
		case 'F':
			printf("Better try again\n");
			break;
		default:
			printf("Invalid grade\n");
	}

	printf("Your grade is %c",grade);
}

int main() {														int main() {
	int ay;																char ders;
	printf("Lutfen Ay Numarasi Giriniz: ");								printf("Ders Kodu: ");
	scanf("%d",&ay);													scanf("%c",&ders);		//switch case'te char de�i�keni i�in de scanf'te ve operat�r� kullan�l�r

	switch(ay)															switch(ders) {
	{																		case 't':printf("Turkce"); break;
		case 1:printf("Ocak"); break;										case 'm':printf("Matematik"); break;
		case 2:printf("Subat"); break;										case 'f':printf("Fen Bilgisi"); break;
		case 3:printf("Mart"); break;										case 's':printf("Sosyal Bilgiler"); break;
		case 4:printf("Nisan"); break;										default:printf("Hatali Kod Girisi Yapilmistir");
		case 5:printf("Mayis"); break;									}
		case 6:printf("Haziran"); break;							}
		case 7:printf("Temmuz"); break;
		case 8:printf("Agustos"); break;
		case 9:printf("Eylul");
		case 10:printf("Ekim");		//switch, girdi�im ay numaras�na g�re o de�i�ken de�eri i�in tan�ml� case'e y�nlendiriyor
		case 11:printf("Kasim");	//break olmay�nca da bilgisayar haliyle alt sat�ra ge�iyor ve di�er case'ler i�in tan�ml� fonksiyonlar� da uyguluyor
		case 12:printf("Aralik");	//o y�zden ��kt� "EylulEkimKasimAralikGecersizGiris" oluyor
		default:printf("Gecersiz Giris");
	}
}

int main() {
	float sayi1,sayi2,sonuc;
	char islem;
	printf("Birinci Sayiyi Giriniz: ");
	scanf("%f",&sayi1);
	printf("Ikinci Sayiyi Giriniz: ");
	scanf("%f",&sayi2);
	printf("Yapilacak Islemi Seciniz: ");
	scanf("%s",&islem);
	
	switch(islem) {
		case '+':
			sonuc=sayi1+sayi2;
			printf("Sonuc: %f",sonuc); break;
		case '-':
			sonuc=sayi1-sayi2;
			printf("Sonuc: %f",sonuc); break;
		case '*':
			sonuc=sayi1*sayi2;
			printf("Sonuc: %f",sonuc); break;
		case '/':
			sonuc=sayi1/sayi2;
			printf("Sonuc: %f",sonuc); break;
		default:printf("Gecersiz Islem Girdiniz");
		}
	}

int main() {
	
	float a,b,c,d,pi;
	int secim,i;
	pi=3.141592;

	printf("************ Matematik Menusu ************\n\n");
	printf("1-Dikdortgende Alan ve Cevre Hesabi\n");
	printf("2-Dairede Alan ve Cevre Hesabi\n");
	printf("3-3x^2+4x+5 Isleminin Sonucu\n");
	printf("4-Aritmetik Ortalama\n");
	printf("5-Geometrik Ortalama\n\n");
	printf("******************************************\n\n");
	printf("Birinci Sayiyi Giriniz: ");
	scanf("%f",&a);
	printf("Ikinci Sayiyi Giriniz: ");
	scanf("%f",&b);
	printf("Isleminizi Seciniz: ");
	scanf("%d",&secim);
	
	switch(secim) {
		case 1:
			c=2*a+2*b;
			d=a*b;
			printf("\nAlan: %f\n",d);
			printf("Cevre: %f",c);
			break;
		case 2:
			c=2*pi*a;
			d=pi*a*a;
			printf("\nAlan: %f\n",d);
			printf("Cevre: %f",c);
			break;
		case 3:
			c=3*a*a+4*a+5;
			printf("\nSonuc: %f",c);
			break;
		case 4:
			c=(a+b)/2;
			printf("\nOrtalama: %f",c);
			break;
		case 5:
			c=sqrt(a*b);
			printf("\nOrtalama: %f",c);
			break;
		default:
			for(i=0;i<=10;i--) {
			printf("ERROR ");
			}			//infinite loop (sonsuz d�ng�) yapt�m, hehehe       ayr�ca scanf'te say� yerine harf girince de ERROR veriyo :))
	}					//tabii infinite loop'u direkt while(1) { } veya for(;1;) { } kal�plar�n� kullanarak da yapabilirdim
						//normalde ko�ul yarg�lar� ge�erli, yani "true" ise for,while,if yap�lar�ndaki kod okunur; ge�ersiz, yani "false" ise bu yap�lardaki kodlar okunmaz
	return 0;			//programlama dilinde "1: true, 0: false" oldu�u i�in ben ko�ul yarg�s� olarak 1 koydu�umdan daima while d�ng�s� �al��aca��ndan (��nk� 0: false d�nd�rm�yor ki d�ng�den ��ks�n) program sonsuz d�ng�ye giriyor
} */

int main() {
	int onlar,birler;
	printf("Iki basamakli sayi giriniz: ");
	scanf("%1d%1d",&onlar,&birler);		//%1d de�i�kenler sadece bir basamakl� say� alabilir demek
	printf("Girdiginiz sayinin Ingilizcesi: ");
	switch(onlar) {
		case 1:
			switch(birler) {
				case 0:
					printf("ten"); return 0;	//return 0 komutu D�REKT kodu (main fonksiyonunu) sonland�r�r
				case 1:
					printf("eleven"); return 0;
				case 2:
					printf("twelve"); return 0;
				case 3:
					printf("thirteen"); return 0;
				case 4:
					printf("fourteen"); return 0;
				case 5:
					printf("fifteen"); return 0;
				case 6:
					printf("sixteen"); return 0;
				case 7:
					printf("seventeen"); return 0;
				case 8:
					printf("eigthteen"); return 0;
				case 9:
					printf("nineteen"); return 0;
			}
		case 2:
			printf("twenty"); break;
		case 3:
			printf("thirty"); break;
		case 4:
			printf("forty"); break;
		case 5:
			printf("fifty"); break;
		case 6:
			printf("sixty"); break;
		case 7:
			printf("seventy"); break;
		case 8:
			printf("eighty"); break;
		case 9:
			printf("ninety"); break;
	}

	switch(birler) {
		case 1:
			printf("-one"); break;
		case 2:
			printf("-two"); break;
		case 3:
			printf("-three"); break;
		case 4:
			printf("-four"); break;
		case 5:
			printf("-five"); break;
		case 6:
			printf("-six"); break;
		case 7:
			printf("-seven"); break;
		case 8:
			printf("-eight"); break;
		case 9:
			printf("-nine"); break;
	}
	return 0;
}
