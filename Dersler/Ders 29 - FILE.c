#include <stdio.h>
#include <stdlib.h>

/* "fopen: open file , dosya a�ma"		"fclose: close file , dosya kapama"		"w: write , yazma"		"r: read , okuma"		"a: add , ekleme"
   gelgelelim zurnan�n z�rt dedi�i yere, dosya i�lemleri...
   a��l���m�z� fopen ile yapal�m o zaman (no pun intended)
   fopen fonksiyonun genel syntax'� fopen a� parantez t�rnak dosya_adresi t�rnak virg�l t�rnak komut t�rnak kapa parantez ==> fopen("dosya_adresi","komut")
   bu fonksiyon "w: write" komutuyla kullan�ld���nda girilen adresteki isme ve yere g�re YAZMAK i�in bir dosya olu�turur

int main() {
	fopen("C:\\Users\\Aras G�ng�re\\Desktop\\falan filan\\Merhaba D�nya.txt","w");	//masa�st�mdeki "falan filan" adl� dosyam�n i�inde "Merhaba D�nya" isimli bo� bir metin belgesi olu�tu
	return 0;	//ters slash'lar printf i�inde \n,\b,\t gibi ka��� dizileri (escape sequence) i�in kullan�ld���ndan ters slash'�n kendisi iki tane ters slash ile ifade edilir
}				//ayr�ca T�rk�e karakterler dosya i�lemlerinde sorun yaratmaz ;)


   "putc/fputc: put character in file , yazma"			"fputs: put string in file , toplu yazma"
   normalde puts ve printf fonksiyonlar� siyah ekrana (konsola) metin yazd�rmak i�in kullan�l�rken putc, fputc, puts fonksiyonlar� dosyalar�n i�ine metin yazd�rmak i�in kullan�l�r
   fputc(x,d): d adl� g�stericinin tuttu�u dosyaya x karakterini yazd�r�r
			   printf("%c",karakteradi) fonksiyonunun kankas�
   putc(x,d): fputc ile birebir ayn�, birbirlerinin yerine kullan�labilir (bkz. fputc)
   fputs(x,d): d adl� g�stericinin tuttu�u dosyaya x katar�n� yazd�r�r
			   printf("%s",kataradi) ve puts(kataradi) fonksiyonlar�n�n kankas�
   �u 3 fonksiyondan H��B�R� otomatik olarak sat�r atlamaz, yani newline yapmaz

   ayr�ca, en son bir dosyayla i�imiz bitti�inde o dosyay� kapatmak i�in fclose fonksiyonu kullan�l�r


int main() {
	FILE *dosya;
	dosya=fopen("C:\\Users\\Aras G�ng�re\\Desktop\\C-iki�\\falan filan\\metin1.txt","w");
	fputc('a',dosya);
	fputc('b',dosya);	//metin2 adl� metin belgesine ilk "abv" yazd�rd�m
	fputc('v',dosya);	//alternatif olarak putc kullan�labilir
	fputs("\n\nDonald Trump",dosya);	//sonra da 2 sat�r atlay�p "Donald Trump" yazd�rd�m
	fclose(dosya);
}

int main() {
	FILE *metinbelgesi;
	char veri1[20]="Bilgisayar ",veri2[20]="Muhendisligi ",veri3[20]="Bolumu";
	metinbelgesi=fopen("C:\\Users\\Aras G�ng�re\\Desktop\\C-iki�\\falan filan\\metin2.txt","w");
	fputs(veri1,metinbelgesi);
	fputs(veri2,metinbelgesi);
	fputs(veri3,metinbelgesi);
}


   "getc/fgetc: get character from file , okuma"		"fgets: get string from file , toplu okuma"
   normalde gets ve scanf fonksiyonlar� konsoldan kullan�c�n�n klavyeyle sonradan girdi�i metni okumak (veri almak) i�in kullan�l�rken getc, fgetc, fgets fonksiyonlar� dosyalar�n i�inden metin okumak i�in kullan�l�r
   fgetc(d): d adl� g�stericinin tuttu�u dosyadan bir karakter okur
			 scanf("%c",&karakteradi) fonksiyonunun kankas�
   getc(d): fgetc ile birebir ayn�, birbirlerinin yerine kullan�labilir (bkz. fgetc)
   fgets(x,n,d): d adl� g�stericinin tuttu�u dosyadan yeni sat�r (\n: newline) ya da dosya sonu (EOF: End of File) gelene kadar n tane karakterden olu�an bir katar okur ve bunu x adl� katara e�itler (strncpy gibi)
				 scanf("%s",kataradi) ve gets(kataradi) fonksiyonlar�n�n kankas�
   tabii bu fonksiyonlar� kullanabilmek i�in fopen fonksiyonunu "r: read" komutuyla kullanaca��z ve �nceden olu�turulmu� bir dosyay� OKUMAK i�in a�aca��z


int main() {
	FILE *belge;
	char karakter;
	belge=fopen("C:\\Users\\Aras G�ng�re\\Desktop\\C-iki�\\falan filan\\oku_bunu.txt","r");
	do {
		karakter=fgetc(belge);	//alternatif olarak getc kullan�labilir
		printf("%c",karakter);	//dosyadan karakteri al ve ald���n karakteri oldu�u gibi konsola yazd�r
	} while(karakter!=EOF);		//b�ylelikle t�m dosyadaki metin aynen konsola yazd�r�lm�� olur
	fclose(belge);
}

int main() {																									int main() {
	FILE *belge;																									FILE *belge;
	char katar[50];																									char katar[50];
	belge=fopen("C:\\Users\\Aras G�ng�re\\Desktop\\C-iki�\\falan filan\\oku_bunu2.txt","r");								belge=fopen("C:\\Users\\Aras G�ng�re\\Desktop\\C-iki�\\falan filan\\oku_bunu2.txt","r");
	fgets(katar,6,belge);	//son karaktere otomatik olarak NULL atanaca��ndan 5 karakter almak 6 koydum			fgets(katar,50,belge);	//"Iyi geceler Izmir Sirinyer"
	puts(katar);	//ilk be� karakter: "Iyi g"																		puts(katar);
	fgets(katar,11,belge);																						}
	puts(katar);	//sonraki 10 karakter: "eceler Izm"
	fgets(katar,16,belge);	//12. karakter newline oldu�u i�in 11 karakterden sonra okumay� kesecek
	puts(katar);	//sonraki 11 karakter: "ir Sirinyer"
	fclose(belge);
}

int main() {
	FILE *fp1; int i;
	if((fp1=fopen("C:\\Users\\Aras G�ng�re\\Desktop\\C-iki�\\falan filan\\alfabe.txt","w"))==NULL) {
		printf("Dosya a�ma hatas�!");
		exit(1);
	}
	for(i='a';i<='z';i++)
		fputc(i,fp1);	//alfabeyi harf harf "alfabe" adl� metin belgesine yazd�r
	fclose(fp1);

	if((fp1=fopen("C:\\Users\\Aras G�ng�re\\Desktop\\C-iki�\\falan filan\\alfabe.txt","r"))==NULL) {
		printf("Dosya a�ma hatas�!");
		exit(1);
	}
	for(i='a';i<='z';i++)
		printf("%c",fgetc(fp1));	//metin belgesinden okudu�un harfleri (alfabeyi) s�rayla konsola yazd�r
	fclose(fp1);
}


   "fprintf: print formatted in file"		"fscanf: scan formatted in file"
   printf ve scanf ile neredeyse t�pat�p ayn� olan fprintf ve fscanf'in bu ikisinden tek fark� konsola yazd�r�p konsoldan okumak i�in de�il dosyaya yazd�r�p dosyadan okumak i�in kullan�lmalar�
   fprintf ve fscanf ilaveten bir dosya g�stericisini parametre olarak kullan�r, bir de son olarak:
   r: okuma i�in bir metin dosyas� a�ar
   w: yazma i�in bir metin dosyas� olu�turur
   a: bir metin dosyas�na ekleme yapar
   r+: okuma ve yazma i�in bir metin dosyas� a�ar
   w+: okuma ve yazma i�in bir metin dosyas� olu�turur
   a+: okuma ve yazma i�in bir metin dosyas� olu�turur veya ekleme yapar


int main() {
	int a=10,b=20;
	FILE *dosya=fopen("C:\\Users\\Aras G�ng�re\\Desktop\\C-iki�\\falan filan\\fprintf.txt","w");
	fprintf(dosya,"Merhaba Dunya\nCorona virusunun amina koyam\n%d+%d=%d",a,b,a+b);
	fclose(dosya);
}

int main() {
	int i;
	char isim[50];
	FILE *fptr=fopen("C:\\Users\\Aras G�ng�re\\Desktop\\C-iki�\\falan filan\\karaliste.txt","w");
	if(fptr==NULL) {
		printf("Error 404 file not found");
		return 0;
	}
	puts("*****Kara listeye yazilacaklar*****");	//otomatik newline b�rak�r
	fputs("***** Kara Liste *****\n",fptr);			//otomatik newline b�rakmaz
	for(i=1;i<=10;i++) {
		printf("Isim giriniz: ");
		gets(isim);			//otomatik newline b�rak�r
		fprintf(fptr,"%d. %s\n",i,isim);	//fprintf de printf gibi otomatik newline b�rakmaz
	}
	fclose(fptr);
	return 0;		//demek ki sadece puts ve gets fonksiyonlar� newline b�rak�yormu�
}
*/
int main () {
	char str1[10],str2[20],str3[10];
	int ay,yil;
	FILE *fp=fopen("C:\\Users\\Aras G�ng�re\\Desktop\\C-iki�\\falan filan\\tarih.txt","w+");
	fputs("Bugun tarihlerden 16 subat 2020",fp);
	rewind(fp);			//okuma i�lemini en ba�a ald�
	fscanf(fp,"%s %s %d %s %d",str1,str2,&ay,str3,&yil);
	printf("%s %s %d %s %d",str1,str2,ay,str3,yil);
	fclose(fp);
}
