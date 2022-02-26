#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* "command line argument: komut sat�r� arg�man�"     "argc: argument counter"     "argv: argument vector"
   burada her yeni bir proje a�t���m�zda default olarak main fonksiyonunun i�inde gelen argc ve argv parametrelerinin ne oldu�unu ve ne i�e yarad���n� g�rece�iz
   terminal �zerinde (cmd) i�lem yapabilmek i�in komut sat�r� arg�manlar� tan�mlan�r
   genelde int main(int argc, char *argv[]) { } veya int main(int argc, char **argv) { } syntax'lar� ile main fonksiyonuna argc ve argv parametreleri verilir
   argc ka� tane komut sat�r� arg�man� oldu�unu belirtirken argv ise komut sat�r� arg�manlar�n�n ne oldu�unu belirler
   argc int de�i�keni olarak, argv ise string array'i olarak haf�zada saklan�r
   "argc>0" ve "argv[0]=dosya_adi (filename)" olmak �zere komut sat�r� arg�manlar�nda iki kural ge�erlidir
   son olarak bu kodlar� Dev C++'�n compiler'� (derleyici) �zerinden de�il terminal �zerinden directory bulma komutlar� arac�l���yla ��yle �al��t�raca��z:

   C:\Users\Aras G�ng�re>cd Desktop

   C:\Users\Aras G�ng�re\Desktop>cd C-iki�

   C:\Users\Aras G�ng�re\Desktop\C-iki�>cd Dersler

   C:\Users\Aras G�ng�re\Desktop\C-iki�\Dersler>"Ders 32 - argc argv" arg1 arg2 arg3 ...		(direkt copy-paste yapabilirsin yani)

   son olarak olu�turdu�umuz "Terminal ile �al��t�r beni.c" (at�yorum) adl� C dosyas� i�in bir exe (executable) dosyas� olu�turmak istiyorsam
   terminale bu C dosyas�n�n bulundu�u directory'e girip �u komutu yazaca��m ==> gcc -o "exe dosyan� olu�turdum" "Terminal ile �al��t�r beni".c
   terminal arac�l���yla olu�turdu�umuz "exe dosyan� olu�turdum.exe" adl� dosyay� �al��t�rmak i�in ise terminale olu�turdu�um exe dosyas�n�n ad�n� yazmam yeterli olacakt�r ==> "exe dosyan� olu�turdum"
   ve voila, art�k terminal �zerinden input'lar� girip output'lar� g�rebilirsin


int main(int argc,char *argv[]) {
	int i;
	if(argc>=2) {
		printf("Saklanan argumanlar: ");
		for(i=1;i<argc;i++)
			printf("%s ",argv[i]);
	}
	else
		printf("Arguman listesi bos");
	return 0;
}

int main(int argc,char *argv[]) {
	setlocale(LC_ALL,"Turkish");
	printf("\nmain() : argc : %d\n",argc);
	int index=0;
	printf("\nmain() : argv[%d] : %s\n",index,argv[index++]);
	for(;index<argc;index++)
		if(strncmp(argv[index],"debug",5)==0)
			printf("\nmain() : HATA AYIKLA (PROGRAM DEBUG MODE)\n");
		else if(strncmp(argv[index],"-file",5)==0)
			printf("\nmain() : DOSYA ADINI OKU (PROGRAM READ FILENAME) : %s\n",argv[index+1]);
	printf("\nmain() : ��k�� yap�l�yor (Program Quit)\n");
	return 0;
} */

int main(int argc,char *argv[]) {
	int a,b,c;
	if(argc!=4) {
		printf("Sadece 4 arguman giriniz!   eg. \"dosya_adi (filename) arg1 arg2 arg3\"");
		return 0;
	}

	a=atoi(argv[1]);	//"atoi: ascii (string) to int" fonksiyonu string'leri int veri tipine d�n��t�rmek i�in kullan�l�r
	b=atoi(argv[2]);
	c=atoi(argv[3]);

	if(a<0 || b<0 || c<0) {
		printf("Sadece pozitif arguman giriniz!");
		return 1;
	}

	if(!(a!=b && b!=c && a!=c)) {	//if(a==b || b==c || a==c) olarak da yaz�labilirdi		(de Morgan kural�)
		printf("Lutfen birbirlerinden farkli 3 arguman giriniz!");
		return 1;
	}
	else {
		if(a>b && a>c)
			printf("En buyuk arguman %d",a);
		if(b>c && b>a)
			printf("En buyuk arguman %d",b);
		if(c>a && c>b)
			printf("En buyuk arguman %d",c);
	}
	return 0;
}
