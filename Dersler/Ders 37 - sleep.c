#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* programýn belli bir süreliðine çalýþmasýný durdurmak için <unistd.h> kütüphanesindeki sleep ve usleep fonksiyonlarý kullanýlýr
   "sleep" fonksiyonu inputu saniye olarak alýrken "usleep" fonksiyonu inputu mikrosaniye (saniyenin milyonda biri) olarak alýr
   ya da bunlara alternatif olarak <windows.h> kütüphanesinde bulunan ve inputu milisaniye olarak alan "Sleep" fonksiyonu da kullanýlabilir

int main() {
	printf("3 saniye bekle\n");
	sleep(3);
	printf("3 saniye daha bekle\n");
	sleep(3);
	printf("Programi sonlandirmadan once 5 saniye bekle");
	sleep(5);
}

   o zaman en basitinden bir sayaç yaparak baþlayalým

int main() {
	int i;
	char x[2];
	printf("Sayac: ");
	for(i=10;i>=0;i--) {
		printf("%s",itoa(i,x,10));
		if(i==0)
			break;
		sleep(1);
		printf( i==10 ? "\b \b\b \b" : "\b \b");	//"\b" destructive backspace olmayýp sadece pointer gibi cursor'u bir geri götürürken
	}												//"\b \b" destructive backspace görevi görür
	printf("\nSure dolmustur");
	exit(0);
}

   programýn baþlatýlma zamanýný 00:00:00 olarak alýp zamaný hh:mm:ss olarak gösteren dijital saat

int main() {
	int saat=0,dakika=0,saniye=0;
	while(1) {
		printf("%02d:%02d:%02d\n",saat,dakika,saniye);
		saniye++;
		if(saniye%60==0) {
			dakika++;
			saniye=0;
		}
		if(dakika%60==0 && dakika!=0) {
			saat++;
			dakika=0;
		}
		if(saat%24==0) {
			saat=0;
		}
		sleep(1);		//her saati yazdýrmadan önce 1 saniye bekle
	}
}

   10 defa uzayýp kýsalan yýlan

int main() {
	int i,j;
	for(i=0;i<10;i++) {		//while(1) döngüsüyle bu "animasyon" sonsuz defa çalýþtýrýlabilir
		for(j=0;j<20;j++) {
			printf("*");
			usleep(10000);	//10000 us (mikrosaniye) = 10 ms (milisaniye) = 1 cs (santisaniye) = 0.01 saniye
		}
		for(j=0;j<20;j++) {
			printf("\b \b");
			usleep(10000);
		}
	}
	return 0;
}

   system("COLOR x") fonksiyonu ile konsolun rengi hexadecimal olarak girilen x rakamýnýn deðeri (0,1,2,...,9,A,...,E,F) hangi renge karþýlýk geliyorsa o renge deðiþtirilebilir */

int main() {
	int i;
	printf("Disco time baby!!\nWOOOOOOOHOOOO!!!!");
	for(i=0;i<10;i++) {
		system("COLOR 0");		//black , siyah
		usleep(20000);
		system("COLOR 1");		//blue , mavi
		usleep(20000);
		system("COLOR 2");		//green , yeþil
		usleep(20000);
		system("COLOR 3");		//aqua , su mavisi
		usleep(20000);
		system("COLOR 4");		//red , kýrmýzý
		usleep(20000);
		system("COLOR 5");		//purple , mor
		usleep(20000);
		system("COLOR 6");		//yellow , sarý
		usleep(20000);
		system("COLOR 7");		//white , beyaz
		usleep(20000);
		system("COLOR 8");		//gray , gri
		usleep(20000);
		system("COLOR 9");		//light blue , açýk mavi
		usleep(20000);
		system("COLOR A");		//light green , açýk yeþil
		usleep(20000);
		system("COLOR B");		//light aqua , açýk su mavisi
		usleep(20000);
		system("COLOR C");		//light red , açýk kýrmýzý
		usleep(20000);
		system("COLOR D");		//light purple , açýk mor
		usleep(20000);
		system("COLOR E");		//light yellow , açýk sarý
		usleep(20000);
		system("COLOR F");		//bright white , parlak beyaz
		usleep(20000);
	}
	exit(0);
}
