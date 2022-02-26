#include <stdio.h>
#include <stdlib.h>

/* "fopen: open file , dosya açma"		"fclose: close file , dosya kapama"		"w: write , yazma"		"r: read , okuma"		"a: add , ekleme"
   gelgelelim zurnanýn zýrt dediði yere, dosya iþlemleri...
   açýlýþýmýzý fopen ile yapalým o zaman (no pun intended)
   fopen fonksiyonun genel syntax'ý fopen aç parantez týrnak dosya_adresi týrnak virgül týrnak komut týrnak kapa parantez ==> fopen("dosya_adresi","komut")
   bu fonksiyon "w: write" komutuyla kullanýldýðýnda girilen adresteki isme ve yere göre YAZMAK için bir dosya oluþturur

int main() {
	fopen("C:\\Users\\Aras Güngöre\\Desktop\\falan filan\\Merhaba Dünya.txt","w");	//masaüstümdeki "falan filan" adlý dosyamýn içinde "Merhaba Dünya" isimli boþ bir metin belgesi oluþtu
	return 0;	//ters slash'lar printf içinde \n,\b,\t gibi kaçýþ dizileri (escape sequence) için kullanýldýðýndan ters slash'ýn kendisi iki tane ters slash ile ifade edilir
}				//ayrýca Türkçe karakterler dosya iþlemlerinde sorun yaratmaz ;)


   "putc/fputc: put character in file , yazma"			"fputs: put string in file , toplu yazma"
   normalde puts ve printf fonksiyonlarý siyah ekrana (konsola) metin yazdýrmak için kullanýlýrken putc, fputc, puts fonksiyonlarý dosyalarýn içine metin yazdýrmak için kullanýlýr
   fputc(x,d): d adlý göstericinin tuttuðu dosyaya x karakterini yazdýrýr
			   printf("%c",karakteradi) fonksiyonunun kankasý
   putc(x,d): fputc ile birebir ayný, birbirlerinin yerine kullanýlabilir (bkz. fputc)
   fputs(x,d): d adlý göstericinin tuttuðu dosyaya x katarýný yazdýrýr
			   printf("%s",kataradi) ve puts(kataradi) fonksiyonlarýnýn kankasý
   þu 3 fonksiyondan HÝÇBÝRÝ otomatik olarak satýr atlamaz, yani newline yapmaz

   ayrýca, en son bir dosyayla iþimiz bittiðinde o dosyayý kapatmak için fclose fonksiyonu kullanýlýr


int main() {
	FILE *dosya;
	dosya=fopen("C:\\Users\\Aras Güngöre\\Desktop\\C-ikiþ\\falan filan\\metin1.txt","w");
	fputc('a',dosya);
	fputc('b',dosya);	//metin2 adlý metin belgesine ilk "abv" yazdýrdým
	fputc('v',dosya);	//alternatif olarak putc kullanýlabilir
	fputs("\n\nDonald Trump",dosya);	//sonra da 2 satýr atlayýp "Donald Trump" yazdýrdým
	fclose(dosya);
}

int main() {
	FILE *metinbelgesi;
	char veri1[20]="Bilgisayar ",veri2[20]="Muhendisligi ",veri3[20]="Bolumu";
	metinbelgesi=fopen("C:\\Users\\Aras Güngöre\\Desktop\\C-ikiþ\\falan filan\\metin2.txt","w");
	fputs(veri1,metinbelgesi);
	fputs(veri2,metinbelgesi);
	fputs(veri3,metinbelgesi);
}


   "getc/fgetc: get character from file , okuma"		"fgets: get string from file , toplu okuma"
   normalde gets ve scanf fonksiyonlarý konsoldan kullanýcýnýn klavyeyle sonradan girdiði metni okumak (veri almak) için kullanýlýrken getc, fgetc, fgets fonksiyonlarý dosyalarýn içinden metin okumak için kullanýlýr
   fgetc(d): d adlý göstericinin tuttuðu dosyadan bir karakter okur
			 scanf("%c",&karakteradi) fonksiyonunun kankasý
   getc(d): fgetc ile birebir ayný, birbirlerinin yerine kullanýlabilir (bkz. fgetc)
   fgets(x,n,d): d adlý göstericinin tuttuðu dosyadan yeni satýr (\n: newline) ya da dosya sonu (EOF: End of File) gelene kadar n tane karakterden oluþan bir katar okur ve bunu x adlý katara eþitler (strncpy gibi)
				 scanf("%s",kataradi) ve gets(kataradi) fonksiyonlarýnýn kankasý
   tabii bu fonksiyonlarý kullanabilmek için fopen fonksiyonunu "r: read" komutuyla kullanacaðýz ve önceden oluþturulmuþ bir dosyayý OKUMAK için açacaðýz


int main() {
	FILE *belge;
	char karakter;
	belge=fopen("C:\\Users\\Aras Güngöre\\Desktop\\C-ikiþ\\falan filan\\oku_bunu.txt","r");
	do {
		karakter=fgetc(belge);	//alternatif olarak getc kullanýlabilir
		printf("%c",karakter);	//dosyadan karakteri al ve aldýðýn karakteri olduðu gibi konsola yazdýr
	} while(karakter!=EOF);		//böylelikle tüm dosyadaki metin aynen konsola yazdýrýlmýþ olur
	fclose(belge);
}

int main() {																									int main() {
	FILE *belge;																									FILE *belge;
	char katar[50];																									char katar[50];
	belge=fopen("C:\\Users\\Aras Güngöre\\Desktop\\C-ikiþ\\falan filan\\oku_bunu2.txt","r");								belge=fopen("C:\\Users\\Aras Güngöre\\Desktop\\C-ikiþ\\falan filan\\oku_bunu2.txt","r");
	fgets(katar,6,belge);	//son karaktere otomatik olarak NULL atanacaðýndan 5 karakter almak 6 koydum			fgets(katar,50,belge);	//"Iyi geceler Izmir Sirinyer"
	puts(katar);	//ilk beþ karakter: "Iyi g"																		puts(katar);
	fgets(katar,11,belge);																						}
	puts(katar);	//sonraki 10 karakter: "eceler Izm"
	fgets(katar,16,belge);	//12. karakter newline olduðu için 11 karakterden sonra okumayý kesecek
	puts(katar);	//sonraki 11 karakter: "ir Sirinyer"
	fclose(belge);
}

int main() {
	FILE *fp1; int i;
	if((fp1=fopen("C:\\Users\\Aras Güngöre\\Desktop\\C-ikiþ\\falan filan\\alfabe.txt","w"))==NULL) {
		printf("Dosya açma hatasý!");
		exit(1);
	}
	for(i='a';i<='z';i++)
		fputc(i,fp1);	//alfabeyi harf harf "alfabe" adlý metin belgesine yazdýr
	fclose(fp1);

	if((fp1=fopen("C:\\Users\\Aras Güngöre\\Desktop\\C-ikiþ\\falan filan\\alfabe.txt","r"))==NULL) {
		printf("Dosya açma hatasý!");
		exit(1);
	}
	for(i='a';i<='z';i++)
		printf("%c",fgetc(fp1));	//metin belgesinden okuduðun harfleri (alfabeyi) sýrayla konsola yazdýr
	fclose(fp1);
}


   "fprintf: print formatted in file"		"fscanf: scan formatted in file"
   printf ve scanf ile neredeyse týpatýp ayný olan fprintf ve fscanf'in bu ikisinden tek farký konsola yazdýrýp konsoldan okumak için deðil dosyaya yazdýrýp dosyadan okumak için kullanýlmalarý
   fprintf ve fscanf ilaveten bir dosya göstericisini parametre olarak kullanýr, bir de son olarak:
   r: okuma için bir metin dosyasý açar
   w: yazma için bir metin dosyasý oluþturur
   a: bir metin dosyasýna ekleme yapar
   r+: okuma ve yazma için bir metin dosyasý açar
   w+: okuma ve yazma için bir metin dosyasý oluþturur
   a+: okuma ve yazma için bir metin dosyasý oluþturur veya ekleme yapar


int main() {
	int a=10,b=20;
	FILE *dosya=fopen("C:\\Users\\Aras Güngöre\\Desktop\\C-ikiþ\\falan filan\\fprintf.txt","w");
	fprintf(dosya,"Merhaba Dunya\nCorona virusunun amina koyam\n%d+%d=%d",a,b,a+b);
	fclose(dosya);
}

int main() {
	int i;
	char isim[50];
	FILE *fptr=fopen("C:\\Users\\Aras Güngöre\\Desktop\\C-ikiþ\\falan filan\\karaliste.txt","w");
	if(fptr==NULL) {
		printf("Error 404 file not found");
		return 0;
	}
	puts("*****Kara listeye yazilacaklar*****");	//otomatik newline býrakýr
	fputs("***** Kara Liste *****\n",fptr);			//otomatik newline býrakmaz
	for(i=1;i<=10;i++) {
		printf("Isim giriniz: ");
		gets(isim);			//otomatik newline býrakýr
		fprintf(fptr,"%d. %s\n",i,isim);	//fprintf de printf gibi otomatik newline býrakmaz
	}
	fclose(fptr);
	return 0;		//demek ki sadece puts ve gets fonksiyonlarý newline býrakýyormuþ
}
*/
int main () {
	char str1[10],str2[20],str3[10];
	int ay,yil;
	FILE *fp=fopen("C:\\Users\\Aras Güngöre\\Desktop\\C-ikiþ\\falan filan\\tarih.txt","w+");
	fputs("Bugun tarihlerden 16 subat 2020",fp);
	rewind(fp);			//okuma iþlemini en baþa aldý
	fscanf(fp,"%s %s %d %s %d",str1,str2,&ay,str3,&yil);
	printf("%s %s %d %s %d",str1,str2,ay,str3,yil);
	fclose(fp);
}
