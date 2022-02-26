#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* Switch case'den ve void fonksiyonlardan yararlanarak maksimum 50 kiþi olabilen doðrusal bir kuyruk için klavyeden girilen
   iþleme göre kuyruða eleman ekleyen, kuyruðun en önündeki elemaný silen veya kuyruktaki elemanlarý gösteren program

#define MAX 50
int kuyruk[MAX], arka=-1, on=-1;
void ekle() {
	int eleman;
	if(arka==MAX-1)
		printf("Kuyruk kapasitesi %d aþýlamaz\n\n",MAX);
	else {
		if(on==-1)
			on=0;
		printf("Kuyruða eklenecek elemaný giriniz: ");
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
		printf("Kuyruk boþ\n\n");
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
		printf("1. Kuyruða eleman ekle\n2. Kuyruktan önden ilk elemaný sil\n3. Kuyruktaki bütün elemanlarý göster\n4. Programý sonlandýr\n\nSeçiminizi giriniz: ");
		scanf("%d",&secim);
		switch(secim) {
			case 1: ekle(); break;
			case 2: sil(); break;
			case 3: goster(); break;
			case 4: printf("Program sonlandýrýlýyor..."); exit(0);
			default: printf("Geçersiz seçim\n\n");
		}
	}
}

   Switch case'den ve void fonksiyonlardan yararlanarak maksimum 50 kiþi olabilen çembersel bir kuyruk için klavyeden girilen
   iþleme göre kuyruða eleman ekleyen, kuyruðun en önündeki elemaný silen veya kuyruktaki elemanlarý gösteren program

#define MAX 50
int kuyruk[MAX], on=-1, arka=-1;
void ekle(int eleman) {
	if((on==0 && arka==MAX-1) || on==arka+1) {
		printf("Kuyruk kapasitesi %d aþýlamaz (overflow)\n",MAX);
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
		printf("Kuyruk boþ\n");
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

		printf("1. Ekle\n2. Sil\n3. Göster\n4. Çýk\n\nSeçiminizi giriniz: ");
		scanf("%d",&secim);
		switch(secim) {
			case 1:
				printf("Kuyruða eklenecek elemaný giriniz: ");
				scanf("%d",&eleman);
				ekle(eleman); break;
			case 2: sil(); break;
			case 3: goster(); break;
			case 4: break;
			default: printf("Geçersiz seçim\n");
		}

	} while(secim!=4);
	exit(0);
}

   Klavyeden girilen string'leri sýrayla leksikografik sýralamaya göre, leksikografik sýralamanýn tersine göre, uzunluða göre ve string'lerin içerdiði farklý karakter sayýsýna göre sýralayýp yazdýran program

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
				char *gecici=string_dizim[j];		//karsilastir adlý fonksiyondan gelen bilgiye göre bubble sort
				string_dizim[j]=string_dizim[j+1];	//misal leksikografik_siralama ve ters_leksikografik_siralama için basit ==> strcmp(string1,string2)>0 ve strcmp(string1,string2)>0
				string_dizim[j+1]=gecici;			//uzunluga_gore_siralama için string uzunluklarý farký 0 deðilse ==> fark>0  :  fark 0 ise, yani strlen'ler eþitse ==> strcmp(string1,string2)>0
			}	//farkli_karakter_sayisina_gore_siralama için string'lerdeki farklý karakter sayýlarý farký 0 deðilse ==> fark>0  :  fark 0 ise, yani string'ler ayný sayýda farklý karaktere sahipse ==> strcmp(string1,string2)>0
}

int main() {
	setlocale(LC_ALL,"Turkish");
	int string_sayisi,i;
	printf("String sayýsýný giriniz: ");
	scanf("%d",&string_sayisi);
	char** string_dizisi;
	string_dizisi=(char**) malloc(string_sayisi*sizeof(char*));

	printf("String'leri giriniz: ");
	for(i=0;i<string_sayisi;i++) {
		*(string_dizisi+i)=(char*) malloc(1024*sizeof(char));
		scanf("%s",*(string_dizisi+i));
		*(string_dizisi+i)=realloc(*(string_dizisi+i), strlen(*(string_dizisi+i))+1);
	}

	printf("\nLeksikografik Sýralama\n");
	string_siralama(string_dizisi, string_sayisi, leksikografik_siralama);
	for(i=0;i<string_sayisi;i++)
		puts(string_dizisi[i]);

	printf("\nTers Leksikografik Sýralama\n");
	string_siralama(string_dizisi, string_sayisi, ters_leksikografik_siralama);
	for(i=0;i<string_sayisi;i++)
		puts(string_dizisi[i]);

	printf("\nUzunluða Göre Sýralama\n");
	string_siralama(string_dizisi, string_sayisi, uzunluga_gore_siralama);
	for(i=0;i<string_sayisi;i++)
		puts(string_dizisi[i]); 

	printf("\nFarklý Karakter Sayýsýna Göre Sýralama\n");
	string_siralama(string_dizisi, string_sayisi, farkli_karakter_sayisina_gore_siralama);
	for(i=0;i<string_sayisi;i++)
		puts(string_dizisi[i]); 
	exit(0);
}

   Öðrencilerin çoktan seçmeli bir sýnavda çözdüðü sorularýn baþarý yüzdelerini hesaplayýp sorularý kolaydan zora sýralayan program */

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

	for(i=0;i<OGRENCILER;i++)	//her bir sorunun toplam doðru yapýlma sayýsýný bulur
		for(j=0;j<SORULAR;j++)
			if(yanitlar[i][j]==cevap_anahtari[j])
				basariOranlari[j]++;

	for(i=0;i<SORULAR;i++)		//doðru yapýlma sayýsýný baþarý oranýna dönüþtürür ve yazdýrýr
		printf("%d. sorunun baþarý oraný: %%%.2lf\n", soruNolari[i]=i+1, basariOranlari[i]=(basariOranlari[i]/OGRENCILER)*100);

	for(i=0;i<SORULAR-1;i++)	//bubble sort ile sorularý baþarý oranlarýna göre büyükten küçüðe doðru sýralar
		for(j=0;j<SORULAR-i-1;j++)
			if(basariOranlari[j]<basariOranlari[j+1]) {
				double gecici=basariOranlari[j];
				basariOranlari[j]=basariOranlari[j+1];
				basariOranlari[j+1]=gecici;
				int gecici2=soruNolari[j];
				soruNolari[j]=soruNolari[j+1];
				soruNolari[j+1]=gecici2;
			}

	printf("\n\nKolaydan zora doðru sýralanmýþ sorular:\n");
	for(i=0;i<SORULAR;i++)	//ve sorularý kolaydan zora (baþarý oraný bakýmýndan büyükten küçüðe) sýralý bir þekilde yazdýrýr
		printf("%d. Soru: %%%.2lf baþarý oraný\n", soruNolari[i], basariOranlari[i]);
	printf("\n\nBöylelikle en zor soru %d. soru, en kolay soru ise %d. soru olmuþ oluyor.", soruNolari[SORULAR-1], soruNolari[0]);
	return 0;
}
