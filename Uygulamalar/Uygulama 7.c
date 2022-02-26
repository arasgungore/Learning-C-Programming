#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* Switch case'den ve void fonksiyonlardan yararlanarak maksimum 50 ki�i olabilen do�rusal bir kuyruk i�in klavyeden girilen
   i�leme g�re kuyru�a eleman ekleyen, kuyru�un en �n�ndeki eleman� silen veya kuyruktaki elemanlar� g�steren program

#define MAX 50
int kuyruk[MAX], arka=-1, on=-1;
void ekle() {
	int eleman;
	if(arka==MAX-1)
		printf("Kuyruk kapasitesi %d a��lamaz\n\n",MAX);
	else {
		if(on==-1)
			on=0;
		printf("Kuyru�a eklenecek eleman� giriniz: ");
		scanf("%d",&eleman);
		kuyruk[++arka]=eleman;
		printf("\n");
	}
}
void sil() {
	if(on==-1 || on>arka) {
		printf("Kuyrukta silinecek eleman yok (underflow)\n\n");
		return;
	}
	else
		printf("Kuyruktan silinen eleman: %d\n\n",kuyruk[on++]);
}
void goster() {
	int i;
	if(on==-1)
		printf("Kuyruk bo�\n\n");
	else {
		printf("Kuyruktaki elemanlar: ");
		for(i=on;i<=arka;i++)
			printf("%d ",kuyruk[i]);
		printf("\n\n");
	}
}
int main() {
	setlocale(LC_ALL,"Turkish");
	int secim;
	while(1) {		//infinite loop
		printf("1. Kuyru�a eleman ekle\n2. Kuyruktan �nden ilk eleman� sil\n3. Kuyruktaki b�t�n elemanlar� g�ster\n4. Program� sonland�r\n\nSe�iminizi giriniz: ");
		scanf("%d",&secim);
		switch(secim) {
			case 1: ekle(); break;
			case 2: sil(); break;
			case 3: goster(); break;
			case 4: printf("Program sonland�r�l�yor..."); exit(0);
			default: printf("Ge�ersiz se�im\n\n");
		}
	}
}

   Switch case'den ve void fonksiyonlardan yararlanarak maksimum 50 ki�i olabilen �embersel bir kuyruk i�in klavyeden girilen
   i�leme g�re kuyru�a eleman ekleyen, kuyru�un en �n�ndeki eleman� silen veya kuyruktaki elemanlar� g�steren program

#define MAX 50
int kuyruk[MAX], on=-1, arka=-1;
void ekle(int eleman) {
	if((on==0 && arka==MAX-1) || on==arka+1) {
		printf("Kuyruk kapasitesi %d a��lamaz (overflow)\n",MAX);
		return;
	}

	if(on==-1) {
		on=0;
		arka=0;
	}
	else {
		if(arka==MAX-1)
			arka=0;
		else
			arka++;
	}

	kuyruk[arka]=eleman;
}

void sil() {
	if(on==-1) {
		printf("Kuyrukta silinecek eleman yok (underflow)\n");
		return;
	}

	printf("Kuyruktan silinen eleman: %d\n",kuyruk[on]);

	if(on==arka) {
		on--;
		arka--;
	}
	else {
		if(on==MAX-1)
			on=0;
		else
			on++;
	}
}

void goster() {
	int on_poz=on, arka_poz=arka;
	if(on==-1) {
		printf("Kuyruk bo�\n");
		return;
	}

	printf("Kuyruktaki elemanlar: ");

	if(on_poz<=arka_poz)
		while(on_poz<=arka_poz) {
			printf("%d ",kuyruk[on_poz]);
			on_poz++;
		}
	else {
		while(on_poz<=MAX-1) {
			printf("%d ",kuyruk[on_poz]);
			on_poz++;
		}
		on_poz=0;
		while(on_poz<=arka_poz) {
			printf("%d ",kuyruk[on_poz]);
			on_poz++;
		}
	}
	printf("\n");
}

int main() {
	setlocale(LC_ALL,"Turkish");
	int secim,eleman;
	do {

		printf("1. Ekle\n2. Sil\n3. G�ster\n4. ��k\n\nSe�iminizi giriniz: ");
		scanf("%d",&secim);
		switch(secim) {
			case 1:
				printf("Kuyru�a eklenecek eleman� giriniz: ");
				scanf("%d",&eleman);
				ekle(eleman); break;
			case 2: sil(); break;
			case 3: goster(); break;
			case 4: break;
			default: printf("Ge�ersiz se�im\n");
		}

	} while(secim!=4);
	exit(0);
}

   Klavyeden girilen string'leri s�rayla leksikografik s�ralamaya g�re, leksikografik s�ralaman�n tersine g�re, uzunlu�a g�re ve string'lerin i�erdi�i farkl� karakter say�s�na g�re s�ralay�p yazd�ran program

int leksikografik_siralama(char* string1, char* string2) {
	return strcmp(string1,string2);
}
int ters_leksikografik_siralama(char* string1, char* string2) {
	return strcmp(string2,string1);
}
int uzunluga_gore_siralama(char* string1, char* string2) {
	int fark=strlen(string1)-strlen(string2);
	return (fark) ? fark : leksikografik_siralama(string1,string2);
}
int farkli_karakter_sayisi(char *string) {
	int sonuc=0;
	while(*string!='\0')
		if(!strchr(++string,*string))
			sonuc++;
	return sonuc;
}
int farkli_karakter_sayisina_gore_siralama(char* string1, char* string2) {
	int fark=farkli_karakter_sayisi(string1)-farkli_karakter_sayisi(string2);
	return (fark) ? fark : leksikografik_siralama(string1,string2);
}

void string_siralama(char** string_dizim, int sayi, int (*karsilastir)(char* string1, char* string2)) {
	int i,j;
	for(i=0;i<sayi-1;i++)
		for(j=0;j<sayi-1;j++)
			if(karsilastir(string_dizim[j],string_dizim[j+1])>0) {
				char *gecici=string_dizim[j];		//karsilastir adl� fonksiyondan gelen bilgiye g�re bubble sort
				string_dizim[j]=string_dizim[j+1];	//misal leksikografik_siralama ve ters_leksikografik_siralama i�in basit ==> strcmp(string1,string2)>0 ve strcmp(string1,string2)>0
				string_dizim[j+1]=gecici;			//uzunluga_gore_siralama i�in string uzunluklar� fark� 0 de�ilse ==> fark>0  :  fark 0 ise, yani strlen'ler e�itse ==> strcmp(string1,string2)>0
			}	//farkli_karakter_sayisina_gore_siralama i�in string'lerdeki farkl� karakter say�lar� fark� 0 de�ilse ==> fark>0  :  fark 0 ise, yani string'ler ayn� say�da farkl� karaktere sahipse ==> strcmp(string1,string2)>0
}

int main() {
	setlocale(LC_ALL,"Turkish");
	int string_sayisi,i;
	printf("String say�s�n� giriniz: ");
	scanf("%d",&string_sayisi);
	char** string_dizisi;
	string_dizisi=(char**) malloc(string_sayisi*sizeof(char*));

	printf("String'leri giriniz: ");
	for(i=0;i<string_sayisi;i++) {
		*(string_dizisi+i)=(char*) malloc(1024*sizeof(char));
		scanf("%s",*(string_dizisi+i));
		*(string_dizisi+i)=realloc(*(string_dizisi+i), strlen(*(string_dizisi+i))+1);
	}

	printf("\nLeksikografik S�ralama\n");
	string_siralama(string_dizisi, string_sayisi, leksikografik_siralama);
	for(i=0;i<string_sayisi;i++)
		puts(string_dizisi[i]);

	printf("\nTers Leksikografik S�ralama\n");
	string_siralama(string_dizisi, string_sayisi, ters_leksikografik_siralama);
	for(i=0;i<string_sayisi;i++)
		puts(string_dizisi[i]);

	printf("\nUzunlu�a G�re S�ralama\n");
	string_siralama(string_dizisi, string_sayisi, uzunluga_gore_siralama);
	for(i=0;i<string_sayisi;i++)
		puts(string_dizisi[i]); 

	printf("\nFarkl� Karakter Say�s�na G�re S�ralama\n");
	string_siralama(string_dizisi, string_sayisi, farkli_karakter_sayisina_gore_siralama);
	for(i=0;i<string_sayisi;i++)
		puts(string_dizisi[i]); 
	exit(0);
}

   ��rencilerin �oktan se�meli bir s�navda ��zd��� sorular�n ba�ar� y�zdelerini hesaplay�p sorular� kolaydan zora s�ralayan program */

#define OGRENCILER 8
#define SORULAR 10
int main() {
	setlocale(LC_ALL,"Turkish");
	char yanitlar[OGRENCILER][SORULAR] = {
					{'A','B','A','C','C','D','E','E','A','D'},
					{'D','B','A','B','C','A','E','E','A','D'},
					{'E','D','D','A','C','B','E','E','A','D'},
					{'C','B','A','E','D','C','E','C','A','D'},
					{'A','B','D','C','C','D','E','E','A','D'},
					{'B','B','E','C','C','D','E','A','A','D'},
					{'B','B','A','C','C','D','E','E','B','D'},
					{'E','B','E','C','C','D','E','E','A','D'}};
	char cevap_anahtari[SORULAR] = {'D','B','D','C','C','D','A','E','A','D'};
	int i,j, soruNolari[SORULAR];
	double basariOranlari[SORULAR] = {0};

	for(i=0;i<OGRENCILER;i++)	//her bir sorunun toplam do�ru yap�lma say�s�n� bulur
		for(j=0;j<SORULAR;j++)
			if(yanitlar[i][j]==cevap_anahtari[j])
				basariOranlari[j]++;

	for(i=0;i<SORULAR;i++)		//do�ru yap�lma say�s�n� ba�ar� oran�na d�n��t�r�r ve yazd�r�r
		printf("%d. sorunun ba�ar� oran�: %%%.2lf\n", soruNolari[i]=i+1, basariOranlari[i]=(basariOranlari[i]/OGRENCILER)*100);

	for(i=0;i<SORULAR-1;i++)	//bubble sort ile sorular� ba�ar� oranlar�na g�re b�y�kten k����e do�ru s�ralar
		for(j=0;j<SORULAR-i-1;j++)
			if(basariOranlari[j]<basariOranlari[j+1]) {
				double gecici=basariOranlari[j];
				basariOranlari[j]=basariOranlari[j+1];
				basariOranlari[j+1]=gecici;
				int gecici2=soruNolari[j];
				soruNolari[j]=soruNolari[j+1];
				soruNolari[j+1]=gecici2;
			}

	printf("\n\nKolaydan zora do�ru s�ralanm�� sorular:\n");
	for(i=0;i<SORULAR;i++)	//ve sorular� kolaydan zora (ba�ar� oran� bak�m�ndan b�y�kten k����e) s�ral� bir �ekilde yazd�r�r
		printf("%d. Soru: %%%.2lf ba�ar� oran�\n", soruNolari[i], basariOranlari[i]);
	printf("\n\nB�ylelikle en zor soru %d. soru, en kolay soru ise %d. soru olmu� oluyor.", soruNolari[SORULAR-1], soruNolari[0]);
	return 0;
}
