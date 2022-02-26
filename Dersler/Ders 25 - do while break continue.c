#include <stdio.h>
#include <stdlib.h>

/* "do while: do while loop, yap iken döngüsü"		"break: fren , döngüyü kýr"		"continue: döngüye devam et"
   "do while" döngüsü esas repetitive statement'larýmýz olan for ve while'a alternatif olarak kullanýlan bir repetitive statement'týr ve iþleyiþi while döngüsüne çok benzer
   do while döngüsünün genel syntax'ý do aç süslü parantez kapa süslü parantez while aç parantez kapa parantez
   yani do {
   		} while();    biçimindedir    (for ve while'ýn aksine sonuna noktalý virgül konmalý)
   while döngüsünden tek farký while içine yazýlan koþula bakýlmaksýzýn döngünün EN AZ BÝR DEFA tekrar edecek olmasýdýr

int main() {
	int i=0;
	do {
		printf("%2d: Merhaba Dunya\n",++i);	//Önce i'nin deðeri arttýrýlýyor, sonra Merhaba Dunya yazdýrýlýyor
	} while(i<10);	//i=1,2,3,4,5,6,7,8,9,10 için Merhaba Dunya yazdýrýlacak, i=10 için de yazdýrýlmasýnýn sebebi
}					//i=9 için döngü tekrar eder, printf sýrasýnda i'nin deðeri 1 artar, ve i=10 koþulu saðlamadýðýndan da döngü biter
					//do while döngüsünün while'dan asýl farký i'nin deðeri 0 olsa da, 1000 olsa da, en azýndan bir kez Merhaba Dunya'nýn yazdýrýlacak olmasýdýr
					//ancak while'de kontrol (sorgulama) önce yapýldýðý için, hiçbir þey ekrana yazýlmaz

int main() {
	int sayi1,sayi2;
	char devam_mi;
	do {
		printf("Birinci sayiyi giriniz: ");
		scanf("%d",&sayi1);
		printf("Ikinci sayiyi giriniz: ");
		scanf("%d",&sayi2);
		printf("%d + %d = %d\n", sayi1, sayi2, sayi1+sayi2);
		printf("Devam etmek ister misiniz? (Evet icin e/E giriniz): ");
		
		do {
			scanf("%c",&devam_mi);
		} while(devam_mi=='\n');	//C'de karakter okumalarý, biraz sýkýntýlýdýr	eðer giriþ tampon belleðinde (Buffer) veri bulunuyorsa, bu direkt karaktere atanýr
									//bundan kurtulmanýn birçok yöntemi olduðu gibi, uygulanabilecek bir yöntem de "do while" döngüsü þeklinde deðer almaktýr 
		printf("\n");				//ben daha bir þey girmeden, ilk deðer '\n' (NULL) geleceðinden, döngünün ikinci çalýþmasýnda doðru deðer atanacaktýr
	} while(devam_mi=='E' || devam_mi=='e');	//char deðiþkenim E veya e olduðu sürece döngü devam edecek
}

   switch case'te gördüðümüz "break" komutu case'lerdeki kullanýmýna benzer bir þekilde istediðim zaman döngüden çýkmak, kýsaca döngüyü kýrmak için kullanýlýr

   0 ila 99 arasýnda tesadüfi sayýlar üreten bir programýn, kaçýncý seferde 61 sayýsýný bulacaðýna bakalým

int main() {
	int i,tesadufi_sayi;
	int deneme_sayisi=0;	//bu satýrdaki deðiþken sayaç gibi davranacak
	while(1) {		//while içinde 1 (true) olduðundan sonsuza kadar döngü çalýþýr
		tesadufi_sayi=rand()%100;	//rand() fonksiyonu random (rastgele) bir sayý atar, tabii (mod 100)'de iþlem yaptýðýmýz için aslýnda atanan sayýlar 0 ila 99 arasýndadýr
		deneme_sayisi++;			//eðer mod operatörünü kullanmasaydýk bu sefer -(2^31-1) ila 2^31-1 arasýnda rastgele bir deðer atanabilirdi
		if(tesadufi_sayi==61)
			break;
	}
	printf("Toplam deneme sayisi: %d\n",deneme_sayisi);		//çýktým her seferinde "15" olacak
}

   break komutunun döngüyü kýrmak için olduðundan bahsetmiþtim		bunun dýþýnda iþlem yapmadan döngüyü devam ettirmek gibi durumlar içinde continue (devam) komutunu kullanýlýr

   1 ila 200 arasýndaki tek sayýlarý yazdýralým */

int main() {
	int i;
	for(i=1;i<200;i++) {
		if(i%2==0)		//i deðiþkeninin 2'ye göre modu 0 sonucunu veriyorsa, bu onun bir çift sayý olduðunu gösterir. Bu durumda ekrana YAZDIRILMAMASI için döngü bir sonraki adýma geçer
			continue;	//baþka bir deyiþle i'nin (mod 2)'deki deðeri 0 ise alttaki printf fonksiyonu okunmaz, onun yerine döngü scope sonuna gelmiþ sayýlýr ve bir sonraki i deðerine geçer
		printf("%3d\n",i);
	}		//demek ki break komutu döngüden komple çýkýp geri kalan hiç bir adýmý okumamak için kullanýlýrken
}			//continue komutu ise döngüde o adýmýn devamýnda yer alan/geri kalan kod bloðunu es geçerek/okumadan bir sonraki adýma geçmeyi saðlar
