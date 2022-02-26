#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* "command line argument: komut satýrý argümaný"     "argc: argument counter"     "argv: argument vector"
   burada her yeni bir proje açtýðýmýzda default olarak main fonksiyonunun içinde gelen argc ve argv parametrelerinin ne olduðunu ve ne iþe yaradýðýný göreceðiz
   terminal üzerinde (cmd) iþlem yapabilmek için komut satýrý argümanlarý tanýmlanýr
   genelde int main(int argc, char *argv[]) { } veya int main(int argc, char **argv) { } syntax'larý ile main fonksiyonuna argc ve argv parametreleri verilir
   argc kaç tane komut satýrý argümaný olduðunu belirtirken argv ise komut satýrý argümanlarýnýn ne olduðunu belirler
   argc int deðiþkeni olarak, argv ise string array'i olarak hafýzada saklanýr
   "argc>0" ve "argv[0]=dosya_adi (filename)" olmak üzere komut satýrý argümanlarýnda iki kural geçerlidir
   son olarak bu kodlarý Dev C++'ýn compiler'ý (derleyici) üzerinden deðil terminal üzerinden directory bulma komutlarý aracýlýðýyla þöyle çalýþtýracaðýz:

   C:\Users\Aras Güngöre>cd Desktop

   C:\Users\Aras Güngöre\Desktop>cd C-ikiþ

   C:\Users\Aras Güngöre\Desktop\C-ikiþ>cd Dersler

   C:\Users\Aras Güngöre\Desktop\C-ikiþ\Dersler>"Ders 32 - argc argv" arg1 arg2 arg3 ...		(direkt copy-paste yapabilirsin yani)

   son olarak oluþturduðumuz "Terminal ile çalýþtýr beni.c" (atýyorum) adlý C dosyasý için bir exe (executable) dosyasý oluþturmak istiyorsam
   terminale bu C dosyasýnýn bulunduðu directory'e girip þu komutu yazacaðým ==> gcc -o "exe dosyaný oluþturdum" "Terminal ile çalýþtýr beni".c
   terminal aracýlýðýyla oluþturduðumuz "exe dosyaný oluþturdum.exe" adlý dosyayý çalýþtýrmak için ise terminale oluþturduðum exe dosyasýnýn adýný yazmam yeterli olacaktýr ==> "exe dosyaný oluþturdum"
   ve voila, artýk terminal üzerinden input'larý girip output'larý görebilirsin


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
	printf("\nmain() : Çýkýþ yapýlýyor (Program Quit)\n");
	return 0;
} */

int main(int argc,char *argv[]) {
	int a,b,c;
	if(argc!=4) {
		printf("Sadece 4 arguman giriniz!   eg. \"dosya_adi (filename) arg1 arg2 arg3\"");
		return 0;
	}

	a=atoi(argv[1]);	//"atoi: ascii (string) to int" fonksiyonu string'leri int veri tipine dönüþtürmek için kullanýlýr
	b=atoi(argv[2]);
	c=atoi(argv[3]);

	if(a<0 || b<0 || c<0) {
		printf("Sadece pozitif arguman giriniz!");
		return 1;
	}

	if(!(a!=b && b!=c && a!=c)) {	//if(a==b || b==c || a==c) olarak da yazýlabilirdi		(de Morgan kuralý)
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
