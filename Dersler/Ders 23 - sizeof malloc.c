#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* "sizeof: size of variable , deðiþkenin boyutu"		"malloc: memory allocation , bellek tahsisi , hafýzada yer ayýrma"
   char, int, float, double,..., vs. bütün veri tipleri bellekte 1 ila 16 byte arasýnda bellekte yer kaplar
   bu deðiþkenlerin hafýzada kaç byte yer kapladýðýný bulmak için "sizeof" fonksiyonu kullanýlýr
   syntax'ý sizeof aç parantez degiskenturu kapa parantez ==> sizeof(degiskenturu)

int main() {
	printf("Veri Tipi            Boyut\n");
	printf("=============================\n");
	printf("char               : %d byte\n", sizeof(char));				//"char: 1 byte"
	printf("int                : %d byte\n", sizeof(int));				//"int: 4 byte"
	printf("float              : %d byte\n", sizeof(float));			//"float: 4 byte" , tam sayý hassasiyeti küçük, ama ondalýk basamak hassasiyeti var, o yüzden int ile ayný yeri kaplýyor
	printf("double             : %d byte\n", sizeof(double));			//"double: 8 byte" , adý üzerinde float'ýn 2 katý kadar yer kaplar ki ondalýk basamak hassasiyeti daha çok olsun
	printf("short              : %d byte\n", sizeof(short));			//"short: 2 byte" , short küçük tam sayýlar için kullanýlan bir deðiþkendir, o yüzden de int'in yarýsý kadar yer kaplar
	printf("long               : %d byte\n", sizeof(long));				//"long: 4 byte" , long Windows'ta int ile bellekte ayný yeri (4 byte) kaplar, ama diðer iþletim sistemlerinde mesela long 8 byte olabiliyor
	printf("long long          : %d byte\n", sizeof(long long));		//"long long: 8 byte" , o yüzden biz büyük tam sayýlar için long yerine long long kullanacaðýz
	printf("long double        : %d byte\n", sizeof(long double));		//"long double: 16 byte" , double'ýn 2 katý kadar yer kaplayarak daha büyük sayýlarla yüksek ondalýk basamak hassasiyetiyle iþlem yapabilir
	printf("unsigned char      : %d byte\n", sizeof(unsigned char));	//"unsigned char: 1 byte"
	printf("unsigned short     : %d byte\n", sizeof(unsigned short));	//"unsigned short: 2 byte"
	printf("unsigned int       : %d byte\n", sizeof(unsigned int));		//"unsigned int: 4 byte" , unsigned negatif tam sayýlarý algýlamadýðý için int ile ayný yeri kaplayarak int'in algýladýðý aralýðýn 2 katý kadar pozitif tam sayý algýlayabilir
	printf("unsigned long      : %d byte\n", sizeof(unsigned long));	//"unsigned long: 4 byte"
	printf("unsigned long long : %d byte", sizeof(unsigned long long));	//"unsigned long long: 8 byte"
}

   x kadar byte kaplayan bir veriye bellekte rastgele bir adres atamak için "malloc" fonksiyonu kullanýlýr
   syntax'ý malloc aç parantez byte_sayýsý kapa parantez ==> malloc(byte_sayisi)
   malloc fonksiyonunun çýktýsý bellekteki boþ olan rastgele bir adres deðeri olduðu için genel olarak "(int*) malloc(sizeof(degiskenturu))" syntax'ý ile kullanýlýr

int main() {
	int *a;

	a=(int*) malloc(sizeof(int)); 	//program malloc() fonksiyonunun döndürdüðü deðeri (adres) direkt olarak a pointer'ýna atar
	*a=126;							//böylece int bir deðer için ayrýlmýþ olan bellek alanýnýn baþlangýç adresi a pointer'ýna atanmýþ olur ve sonra a pointer'ýnýn gösterdiði adrese ise 126 sayýsýný atar

	printf("%x\n",a);				//en son da a göstericisinin deðeri (adres) ile göstericinin gösterdiði adrese saklanan deðeri ekrana yazdýrýr
	printf("%d",*a);
}

   "dizi[a]; a=50;" diye otomatik bellek tahsisi sýkýntý yarattýðýndan a elemanlý bir dizi için genel olarak "degiskenturu *dizi=(int*) malloc(sizeof(degiskenturu)*a)" kalýbý ile dinamik bellek tahsisi yapýlýr

int main() {
	int i,a,*dizi;
	printf("Eleman sayisi kac olsun: ");
	scanf("%d",&a);
	dizi=(int*) malloc(sizeof(int)*a);			//a tane int deðiþkeni için dizi pointer'ýna (ayný zamanda dizinin ilk elemanýna) rastgele bir adres atandý
	for(i=0;i<a;i++) {
		printf("%d. elemani giriniz: ",i+1);
		scanf("%d",dizi+i);						//normalde scanf kýsmýna &degiskenadi yazýlýr çünkü program o deðiþkene ayrýlan adrese deðer koyar
	}											//bu sefer ama dizi bir pointer olduðu ve adresin yerini zaten tuttuðu için direkt dizi+i yazdýk
	i=0;										//&(*(dizi+i)) de & ve * operatörleri birbirini götürdüðü için de dizi+i yazdýðýmýzý düþünebiliriz
	printf("Diziniz: ");
	while(i<a) {
		printf("%d ",*(dizi+i));
		i++;
	}
}

   þimdi de matrisleri inceleyelim:
   normalde n elemanlý tek boyutlu bir diziye bellekte ayrýlacak yeri *dizi=(int*) malloc(sizeof(degiskenturu)*n) ile belirleyip sonra "dizi" pointer'ý ile dizinin r. elemanýna dizi[r-1] veya *(dizi+r-1) ile ulaþýyorduk
   2 boyutlu dizilerde (matris) ise duble pointer kullanýp dizinin a. satýrýndaki b. sütunundaki elemanýna "matris" duble pointer'ý ile *(*(matris+a-1)+b-1) ile ulaþýyoruz
   matrislerde dinamik bellek tahsisi biraz daha karýþýk, çünkü matrislerde her bir satýr bir dizi olduðu için aslýnda satýr sayýsý kadar pointer kullanýlýr ve bu pointer'lara eriþmek için ise duble pointer kullanýlýr
   misal "int **q; q=(int**) malloc(sizeof(int*)*5);" dersem *(q+0) [veya *q], *(q+1), *(q+2), *(q+3), *(q+4)'tan her biri ayrý birer POÝNTER olmuþ olur
   bu her bir pointer için de haliyle RAM'de ayrý ayrý yerler gerekeceði için bir for döngüsü içinde malloc ile bu pointerlara bellekte birbiriyle çakýþmayan farklý adresler tahsis edilebilir

int main() {
	int **matrix,i,j,satir,sutun;
	printf("Matris kac satir olsun?: ");
	scanf("%d",&satir);
	printf("Matris kac sutun olsun?: ");
	scanf("%d",&sutun);
	matrix=(int**) malloc(sizeof(int*)*satir);
	for(i=0;i<satir;i++)
		*(matrix+i)=(int*) malloc(sizeof(int)*sutun);
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			printf("Matrisin %d. satirinin %d. sutunundaki elemani giriniz: ",i+1,j+1);
			scanf("%d",*(matrix+i)+j);
		}
	}
	printf("\n\n\n");
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++)
			printf("%d\t",*(*(matrix+i)+j));
		printf("\n");
	}
	return 0;
}

   "realloc: re-allocation , yeniden bellek tahsisi"     "calloc: contiguous allocation , bitiþik bellek tahsisi"     "free: veriyi serbest býrakma"
   malloc fonksiyonunun yanýnda dinamik bellek tahsisini en etkili bir þekilde kullanabilmek için realloc, calloc ve free fonksiyonlarý kullanýlýr
   calloc malloc'a daha iyi bir alternatif olarak, realloc gereksiz yer kaplayan veri tiplerine tekrar yer atamak, free ise veriyle iþim bittikten sonra o veriyi hafýzadan atmak için kullanýlýr

int main() {
	char *cumle=calloc(100,sizeof(char));	//cumle pointer'ýna ardýþýk gözlerde bulunan 100*sizeof(char)=100*1=100 byte'lýk yer ayrýldý
	printf("Cumle giriniz: ");				//char *cumle=malloc(100*sizeof(char)) da yapýlabilirdi
	gets(cumle);
	realloc(cumle,strlen(cumle)+1);		//önceki yer boþaltýlýp cumle pointer'ýna string uzunluðunun 1 fazlasý (stringlerdeki son karakter '\0' (NULL) olduðu için "+1") kadar yeniden yer ayrýldý
	printf("Girdiginiz kelime: %s",cumle);
	free(cumle);	//cumle pointer'ý hafýzadan boþaltýldý
}

int main () {
	char *ptr;
	ptr=(char*) malloc(11);
	strcpy(ptr,"Programming");
	printf("%s\t\tAdres: %u\n",ptr,ptr);

	ptr=(char*) realloc(ptr,17);
	strcat(ptr," in C");
	printf("%s\tAdres: %u\n",ptr,ptr);
	free(ptr);
	return 0;
} */

int main() {
	int *dinamik_dizi=NULL,eleman_sayisi=6,i;
	dinamik_dizi=calloc(eleman_sayisi,sizeof(int));
	printf("***Tek sayilar***\n");
	for(i=0;i<eleman_sayisi;i++) {
		dinamik_dizi[i]=2*i+1;			//tek sayýlar
		printf("dinamik_dizi[%d]=%d\n",i,dinamik_dizi[i]);
	}
	eleman_sayisi+=4;
	dinamik_dizi=realloc(dinamik_dizi,eleman_sayisi*sizeof(int));
	printf("\n***Tam kare sayilar*** (Realloc'tan sonra)\n");
	for(i=0;i<eleman_sayisi;i++) {
		dinamik_dizi[i]=(i+1)*(i+1);	//tam kare sayýlar
		printf("dinamik_dizi[%d]=%d\n",i,dinamik_dizi[i]);
	}
	free(dinamik_dizi);
	return 0;
}
