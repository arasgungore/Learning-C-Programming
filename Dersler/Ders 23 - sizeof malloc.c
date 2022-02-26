#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* "sizeof: size of variable , de�i�kenin boyutu"		"malloc: memory allocation , bellek tahsisi , haf�zada yer ay�rma"
   char, int, float, double,..., vs. b�t�n veri tipleri bellekte 1 ila 16 byte aras�nda bellekte yer kaplar
   bu de�i�kenlerin haf�zada ka� byte yer kaplad���n� bulmak i�in "sizeof" fonksiyonu kullan�l�r
   syntax'� sizeof a� parantez degiskenturu kapa parantez ==> sizeof(degiskenturu)

int main() {
	printf("Veri Tipi            Boyut\n");
	printf("=============================\n");
	printf("char               : %d byte\n", sizeof(char));				//"char: 1 byte"
	printf("int                : %d byte\n", sizeof(int));				//"int: 4 byte"
	printf("float              : %d byte\n", sizeof(float));			//"float: 4 byte" , tam say� hassasiyeti k���k, ama ondal�k basamak hassasiyeti var, o y�zden int ile ayn� yeri kapl�yor
	printf("double             : %d byte\n", sizeof(double));			//"double: 8 byte" , ad� �zerinde float'�n 2 kat� kadar yer kaplar ki ondal�k basamak hassasiyeti daha �ok olsun
	printf("short              : %d byte\n", sizeof(short));			//"short: 2 byte" , short k���k tam say�lar i�in kullan�lan bir de�i�kendir, o y�zden de int'in yar�s� kadar yer kaplar
	printf("long               : %d byte\n", sizeof(long));				//"long: 4 byte" , long Windows'ta int ile bellekte ayn� yeri (4 byte) kaplar, ama di�er i�letim sistemlerinde mesela long 8 byte olabiliyor
	printf("long long          : %d byte\n", sizeof(long long));		//"long long: 8 byte" , o y�zden biz b�y�k tam say�lar i�in long yerine long long kullanaca��z
	printf("long double        : %d byte\n", sizeof(long double));		//"long double: 16 byte" , double'�n 2 kat� kadar yer kaplayarak daha b�y�k say�larla y�ksek ondal�k basamak hassasiyetiyle i�lem yapabilir
	printf("unsigned char      : %d byte\n", sizeof(unsigned char));	//"unsigned char: 1 byte"
	printf("unsigned short     : %d byte\n", sizeof(unsigned short));	//"unsigned short: 2 byte"
	printf("unsigned int       : %d byte\n", sizeof(unsigned int));		//"unsigned int: 4 byte" , unsigned negatif tam say�lar� alg�lamad��� i�in int ile ayn� yeri kaplayarak int'in alg�lad��� aral���n 2 kat� kadar pozitif tam say� alg�layabilir
	printf("unsigned long      : %d byte\n", sizeof(unsigned long));	//"unsigned long: 4 byte"
	printf("unsigned long long : %d byte", sizeof(unsigned long long));	//"unsigned long long: 8 byte"
}

   x kadar byte kaplayan bir veriye bellekte rastgele bir adres atamak i�in "malloc" fonksiyonu kullan�l�r
   syntax'� malloc a� parantez byte_say�s� kapa parantez ==> malloc(byte_sayisi)
   malloc fonksiyonunun ��kt�s� bellekteki bo� olan rastgele bir adres de�eri oldu�u i�in genel olarak "(int*) malloc(sizeof(degiskenturu))" syntax'� ile kullan�l�r

int main() {
	int *a;

	a=(int*) malloc(sizeof(int)); 	//program malloc() fonksiyonunun d�nd�rd��� de�eri (adres) direkt olarak a pointer'�na atar
	*a=126;							//b�ylece int bir de�er i�in ayr�lm�� olan bellek alan�n�n ba�lang�� adresi a pointer'�na atanm�� olur ve sonra a pointer'�n�n g�sterdi�i adrese ise 126 say�s�n� atar

	printf("%x\n",a);				//en son da a g�stericisinin de�eri (adres) ile g�stericinin g�sterdi�i adrese saklanan de�eri ekrana yazd�r�r
	printf("%d",*a);
}

   "dizi[a]; a=50;" diye otomatik bellek tahsisi s�k�nt� yaratt���ndan a elemanl� bir dizi i�in genel olarak "degiskenturu *dizi=(int*) malloc(sizeof(degiskenturu)*a)" kal�b� ile dinamik bellek tahsisi yap�l�r

int main() {
	int i,a,*dizi;
	printf("Eleman sayisi kac olsun: ");
	scanf("%d",&a);
	dizi=(int*) malloc(sizeof(int)*a);			//a tane int de�i�keni i�in dizi pointer'�na (ayn� zamanda dizinin ilk eleman�na) rastgele bir adres atand�
	for(i=0;i<a;i++) {
		printf("%d. elemani giriniz: ",i+1);
		scanf("%d",dizi+i);						//normalde scanf k�sm�na &degiskenadi yaz�l�r ��nk� program o de�i�kene ayr�lan adrese de�er koyar
	}											//bu sefer ama dizi bir pointer oldu�u ve adresin yerini zaten tuttu�u i�in direkt dizi+i yazd�k
	i=0;										//&(*(dizi+i)) de & ve * operat�rleri birbirini g�t�rd��� i�in de dizi+i yazd���m�z� d���nebiliriz
	printf("Diziniz: ");
	while(i<a) {
		printf("%d ",*(dizi+i));
		i++;
	}
}

   �imdi de matrisleri inceleyelim:
   normalde n elemanl� tek boyutlu bir diziye bellekte ayr�lacak yeri *dizi=(int*) malloc(sizeof(degiskenturu)*n) ile belirleyip sonra "dizi" pointer'� ile dizinin r. eleman�na dizi[r-1] veya *(dizi+r-1) ile ula��yorduk
   2 boyutlu dizilerde (matris) ise duble pointer kullan�p dizinin a. sat�r�ndaki b. s�tunundaki eleman�na "matris" duble pointer'� ile *(*(matris+a-1)+b-1) ile ula��yoruz
   matrislerde dinamik bellek tahsisi biraz daha kar���k, ��nk� matrislerde her bir sat�r bir dizi oldu�u i�in asl�nda sat�r say�s� kadar pointer kullan�l�r ve bu pointer'lara eri�mek i�in ise duble pointer kullan�l�r
   misal "int **q; q=(int**) malloc(sizeof(int*)*5);" dersem *(q+0) [veya *q], *(q+1), *(q+2), *(q+3), *(q+4)'tan her biri ayr� birer PO�NTER olmu� olur
   bu her bir pointer i�in de haliyle RAM'de ayr� ayr� yerler gerekece�i i�in bir for d�ng�s� i�inde malloc ile bu pointerlara bellekte birbiriyle �ak��mayan farkl� adresler tahsis edilebilir

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

   "realloc: re-allocation , yeniden bellek tahsisi"     "calloc: contiguous allocation , biti�ik bellek tahsisi"     "free: veriyi serbest b�rakma"
   malloc fonksiyonunun yan�nda dinamik bellek tahsisini en etkili bir �ekilde kullanabilmek i�in realloc, calloc ve free fonksiyonlar� kullan�l�r
   calloc malloc'a daha iyi bir alternatif olarak, realloc gereksiz yer kaplayan veri tiplerine tekrar yer atamak, free ise veriyle i�im bittikten sonra o veriyi haf�zadan atmak i�in kullan�l�r

int main() {
	char *cumle=calloc(100,sizeof(char));	//cumle pointer'�na ard���k g�zlerde bulunan 100*sizeof(char)=100*1=100 byte'l�k yer ayr�ld�
	printf("Cumle giriniz: ");				//char *cumle=malloc(100*sizeof(char)) da yap�labilirdi
	gets(cumle);
	realloc(cumle,strlen(cumle)+1);		//�nceki yer bo�alt�l�p cumle pointer'�na string uzunlu�unun 1 fazlas� (stringlerdeki son karakter '\0' (NULL) oldu�u i�in "+1") kadar yeniden yer ayr�ld�
	printf("Girdiginiz kelime: %s",cumle);
	free(cumle);	//cumle pointer'� haf�zadan bo�alt�ld�
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
		dinamik_dizi[i]=2*i+1;			//tek say�lar
		printf("dinamik_dizi[%d]=%d\n",i,dinamik_dizi[i]);
	}
	eleman_sayisi+=4;
	dinamik_dizi=realloc(dinamik_dizi,eleman_sayisi*sizeof(int));
	printf("\n***Tam kare sayilar*** (Realloc'tan sonra)\n");
	for(i=0;i<eleman_sayisi;i++) {
		dinamik_dizi[i]=(i+1)*(i+1);	//tam kare say�lar
		printf("dinamik_dizi[%d]=%d\n",i,dinamik_dizi[i]);
	}
	free(dinamik_dizi);
	return 0;
}
