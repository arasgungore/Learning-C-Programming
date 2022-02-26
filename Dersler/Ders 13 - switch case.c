#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* "switch: anahtar"     "case:durum"
   esas conditional statement'ýmýz olan if'e, ya da daha geniþ bir þekilde if, else if, else if, ..., else yapýsýna alternatif olarak switch case conditional statement'ý kullanýlýr
   switch case'in genel syntax'ý switch aç parantez deðiþkenadý kapa parantez aç süslü parantez kapa süslü parantez
   yani switch(degiskenadi) {
    	}						biçimindedir, ve scope içine de case'ler yazýlýr

   o yüzden en genel haliyle syntax'ýmýz ==>	switch(degiskenadi) {
   													case 'deger1':
													case 'deger2':
													case 'deger3':
													}								biçimindedir
	switch fonksiyonu beni içine yazdýðým deðiþkenin deðerine göre beni o deðer için yazýlý case'e gönderecek
	"break: fren"				break komutu, kodu o satýrda durdurmak için kullanýlýr
	eðer break koymazsam her bir case'ten sonra o zaman ondan sonraki case'leri de bilgisayar okur
	"default: varsayýlan"		eðer girdiðim case tanýmlý deðilse, bilgisayar buna girili komutu okur    (default bir bakýma else yapýsý gibi burada)
	zaten bazý dillerde (mesela Python'da) switch case'in iþlevini if, else if, else if, ..., else yapýsý gördüðünden switch case bulunmaz bile

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
	scanf("%d",&ay);													scanf("%c",&ders);		//switch case'te char deðiþkeni için de scanf'te ve operatörü kullanýlýr

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
		case 10:printf("Ekim");		//switch, girdiðim ay numarasýna göre o deðiþken deðeri için tanýmlý case'e yönlendiriyor
		case 11:printf("Kasim");	//break olmayýnca da bilgisayar haliyle alt satýra geçiyor ve diðer case'ler için tanýmlý fonksiyonlarý da uyguluyor
		case 12:printf("Aralik");	//o yüzden çýktý "EylulEkimKasimAralikGecersizGiris" oluyor
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
			}			//infinite loop (sonsuz döngü) yaptým, hehehe       ayrýca scanf'te sayý yerine harf girince de ERROR veriyo :))
	}					//tabii infinite loop'u direkt while(1) { } veya for(;1;) { } kalýplarýný kullanarak da yapabilirdim
						//normalde koþul yargýlarý geçerli, yani "true" ise for,while,if yapýlarýndaki kod okunur; geçersiz, yani "false" ise bu yapýlardaki kodlar okunmaz
	return 0;			//programlama dilinde "1: true, 0: false" olduðu için ben koþul yargýsý olarak 1 koyduðumdan daima while döngüsü çalýþacaðýndan (çünkü 0: false döndürmüyor ki döngüden çýksýn) program sonsuz döngüye giriyor
} */

int main() {
	int onlar,birler;
	printf("Iki basamakli sayi giriniz: ");
	scanf("%1d%1d",&onlar,&birler);		//%1d deðiþkenler sadece bir basamaklý sayý alabilir demek
	printf("Girdiginiz sayinin Ingilizcesi: ");
	switch(onlar) {
		case 1:
			switch(birler) {
				case 0:
					printf("ten"); return 0;	//return 0 komutu DÝREKT kodu (main fonksiyonunu) sonlandýrýr
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
