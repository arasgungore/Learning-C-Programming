#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* program�n belli bir s�reli�ine �al��mas�n� durdurmak i�in <unistd.h> k�t�phanesindeki sleep ve usleep fonksiyonlar� kullan�l�r
   "sleep" fonksiyonu inputu saniye olarak al�rken "usleep" fonksiyonu inputu mikrosaniye (saniyenin milyonda biri) olarak al�r
   ya da bunlara alternatif olarak <windows.h> k�t�phanesinde bulunan ve inputu milisaniye olarak alan "Sleep" fonksiyonu da kullan�labilir

int main() {
	printf("3 saniye bekle\n");
	sleep(3);
	printf("3 saniye daha bekle\n");
	sleep(3);
	printf("Programi sonlandirmadan once 5 saniye bekle");
	sleep(5);
}

   o zaman en basitinden bir saya� yaparak ba�layal�m

int main() {
	int i;
	char x[2];
	printf("Sayac: ");
	for(i=10;i>=0;i--) {
		printf("%s",itoa(i,x,10));
		if(i==0)
			break;
		sleep(1);
		printf( i==10 ? "\b \b\b \b" : "\b \b");	//"\b" destructive backspace olmay�p sadece pointer gibi cursor'u bir geri g�t�r�rken
	}												//"\b \b" destructive backspace g�revi g�r�r
	printf("\nSure dolmustur");
	exit(0);
}

   program�n ba�lat�lma zaman�n� 00:00:00 olarak al�p zaman� hh:mm:ss olarak g�steren dijital saat

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
		sleep(1);		//her saati yazd�rmadan �nce 1 saniye bekle
	}
}

   10 defa uzay�p k�salan y�lan

int main() {
	int i,j;
	for(i=0;i<10;i++) {		//while(1) d�ng�s�yle bu "animasyon" sonsuz defa �al��t�r�labilir
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

   system("COLOR x") fonksiyonu ile konsolun rengi hexadecimal olarak girilen x rakam�n�n de�eri (0,1,2,...,9,A,...,E,F) hangi renge kar��l�k geliyorsa o renge de�i�tirilebilir */

int main() {
	int i;
	printf("Disco time baby!!\nWOOOOOOOHOOOO!!!!");
	for(i=0;i<10;i++) {
		system("COLOR 0");		//black , siyah
		usleep(20000);
		system("COLOR 1");		//blue , mavi
		usleep(20000);
		system("COLOR 2");		//green , ye�il
		usleep(20000);
		system("COLOR 3");		//aqua , su mavisi
		usleep(20000);
		system("COLOR 4");		//red , k�rm�z�
		usleep(20000);
		system("COLOR 5");		//purple , mor
		usleep(20000);
		system("COLOR 6");		//yellow , sar�
		usleep(20000);
		system("COLOR 7");		//white , beyaz
		usleep(20000);
		system("COLOR 8");		//gray , gri
		usleep(20000);
		system("COLOR 9");		//light blue , a��k mavi
		usleep(20000);
		system("COLOR A");		//light green , a��k ye�il
		usleep(20000);
		system("COLOR B");		//light aqua , a��k su mavisi
		usleep(20000);
		system("COLOR C");		//light red , a��k k�rm�z�
		usleep(20000);
		system("COLOR D");		//light purple , a��k mor
		usleep(20000);
		system("COLOR E");		//light yellow , a��k sar�
		usleep(20000);
		system("COLOR F");		//bright white , parlak beyaz
		usleep(20000);
	}
	exit(0);
}
