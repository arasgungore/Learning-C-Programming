#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* <string.h> k�t�phanesinde olan fonksiyonlardan ba�l�calar� �unlard�r: strlen, strcpy, strncpy, strcat, strcmp, strlwr, strupr, strchr, strstr, strtok,...

   "strlen: string length"     "strcpy: string copy"     "strcat: string concatenate"     "strcmp: string compare"
   "tolower: to lower case"     "toupper: to upper case"     "strlwr: string in lower case"     "strupr: string in upper case"
   "strchr: character in string"     "strstr: string in string"     "strtok: tokenize string"

   strlen(x): x katar�n�n ka� karakter uzunlu�unda oldu�unu hesaplar  (bo�luklar dahil)
   strcpy(x,y): y katar�n� x katar�na kopyalar, b�ylelikle x katar� y katar�na e�itlenmi� olur
   strncpy(x,y,n): y katar�n�n ilk n karakterlik k�sm�n� x katar�na kopyalar, x katar�n�n n. karakterden sonraki k�sm�na dokunmaz
   strcat(x,y): x katar�n�n sonuna y katar�n� ekler, x katar� x ve y katarlar�n�n birle�imine e�itlenmi� olur
   strcmp(x,y): x katar� ile y katar�n� k�yaslar, x ve y katarlar� birbirine e�it ise o zaman de�eri 0 olur
				leksikografik s�ralamaya g�re; x katar� y katar�ndan b�y�kse de�eri 0'dan b�y�k olur, x katar� y katar�ndan k���kse de�eri 0'dan k���k olur
				(yap�lan i�lem katarlar� olu�turan karakterlerin ASCII kodlar�n�n fark� ile alakal�)
   tolower(x): x karakterini b�y�k harf ise k���k harf yapar, k���k harf ve di�er karakterlere dokunmaz
   toupper(x): x karakterini k���k harf ise b�y�k harf yapar, b�y�k harf ve di�er karakterlere dokunmaz
			   asl�nda tolower(x) ve toupper(x) <string.h> k�t�phanesinde yok <ctype.h> k�t�phanesinde var
			   zaten string de�il karakter fonksiyonlar� ama ben yine de burada bunlara da de�inmek istedim :)
   strlwr(x): x katar�ndaki b�t�n b�y�k harfleri k���k harf yapar, k���k harf ve di�er karakterlere dokunmaz
   strupr(x): x katar�ndaki b�t�n k���k harfleri b�y�k harf yapar, b�y�k harf ve di�er karakterlere dokunmaz
   strchr(x,y): x katar�nda ilk defa y karakteri ge�ti�inde y dahil y'den SONRASINI pointer'a g�nderir
				pointer arac�l��� ile x katar�nda ka� defa y karakterinin ge�ti�ini bulmak i�in de kullan�labilir
   strstr(x,y): x katar�nda ilk defa y katar� ge�ti�inde y dahil y'den SONRASINI pointer'a g�nderir
				pointer arac�l��� ile x katar�nda ka� defa y katar�n�n ge�ti�ini bulmak i�in de kullan�labilir
   strtok(x,y): x katar�nda ilk defa y katar� ge�ti�inde y dahil y'den �NCES�N� pointer'a g�nderir
				genelde while d�ng�s� ile x katar�n� par�alara ay�rmak i�in kullan�l�r

int main() {
	char katar[100];
	printf("Cumle Yaziniz: ");
	gets(katar);				//scanf("%s",&katar) yazsayd�m bu sefer misal "Merhaba Dunya" yazd���mda ��kt�m "7" olacakt�, zira scanf bo�luktan sonras�n� belle�e (RAM'e) kaydetmiyor
	printf("Cumlenizdeki harf sayisi (bosluklar dahil): %d",strlen(katar));
}

int main() {
	char kaynak[30]="Merhaba Balikesir",kopya[30]="Merhaba Kayserilililililili-",kaynak2[30]="Hello Amsterdam";
	printf("Kaynak: %s\n",kaynak);	//��kt� "Merhaba Balikesir"
	strcpy(kopya,kaynak);
	printf("Kopya: %s\n",kopya);	//��kt� "Merhaba Balikesir", kaynak'�n kendisi
	strncpy(kopya,kaynak2,10);
	printf("2. Kopya: %s\n",kopya); //��kt� "Hello Amstlikesir"; ��nk� kaynak2'nin ilk 10 karakteri olan "Hello Amst", kopya="Merhaba Balikesir"in ilk 10 karakterinin yerini ald�
}

int main() {
	char kitapad[30],yazar[30],kitapyazar[60]="";
	printf("Kitap Adi ve Yazari Girin: ");
	scanf("%s%s",kitapad,yazar);	//mesela "SucVeCeza" ve "Dostoyevski" yazsayd�m
	strcat(kitapyazar,kitapad);
	strcat(kitapyazar," <--> ");
	strcat(kitapyazar,yazar);
	printf("\n%s",kitapyazar);		//��kt�m "SucVeCeza <--> Dostoyevski" olurdu
}

int main() {																		int main() {
	char katar1[200],katar2[200];														char tahmin[10],cevap[2]="69";
	int sonuc;																			puts("Sizce bir Rus kadin en cok kac cocuk dogurabilir? (rakam ile yaziniz): ");
	printf("Birinci katari giriniz: ");													gets(tahmin);
	gets(katar1);																		while(strcmp(tahmin,cevap)!=0) {
	printf("Ikinci katari giriniz: ");														puts("Yanlis cevap, tekrar dusunun: ");
	gets(katar2);																			gets(tahmin);
	sonuc=strcmp(katar1,katar2);														}
	if(sonuc>0)																			puts("Ding ding ding, dogru cevap");
		printf("%s > %s",katar1,katar2);											}
	else if(sonuc<0)
		printf("%s < %s",katar1,katar2);
	else
		printf("%s = %s",katar1,katar2);
}

int main() {
	char cumle[1000];
	int i;
	gets(cumle);
	for(i=0;i<strlen(kelime);i++)
		printf("%c", i==0 ? toupper(cumle[i]) : cumle[i]);	//girilen c�mlenin (kelime de olabilir) sadece ba� harfini b�y�k yapar, gerisine dokunmaz
}

int main() {														int main() {
	char t[15]="Hey Barney hey!";										char s1[]="Saint Petersburg";
	puts(t);						//"Hey Barney hey!"					char c='P';
	puts(strlwr(t));				//"HEY BARNEY HEY!"					char *pt;
	puts(strupr(t));				//"hey barney hey!"					pt=strchr(s1,c);
}																		printf("%s",pt);		//��kt�m "Petersburg", ��nk� "Saint Petersburg"da 'P' karakterinin ilk ge�ti�i k�s�m "Petersburg"

int main() {
	char *p,*t="sikime:bak:hele:ya";
	p=t;							   //"sikime:bak:hele:ya
	puts(p);							//bak:hele:ya
	while((p=strchr(p,':'))!=NULL)		//hele:ya
		puts(++p);						//ya"
}										//++p yerine p++ kullan�lsayd� 2.,3.,4. sat�rlar�n ba��nda fazladan ":" olurdu
										//��nk� pointer'� bir artt�rd���mda pointer karakter dizisinin bir sonraki eleman�n� g�steriyor ve o elemandan itibaren olan karakter dizisini al�yor
int main() {
	char s1[]="Hey,123,sesim geliyor mu?";
	char *p;
	p=strtok(s1,",");				   //"Hey
	while(p!=NULL) {					//123
		printf("%s\n",p);				//sesim geliyor mu?"
		p=strtok(NULL,",");
	}
}
   bir katarda hangi rakamdan ka� tane bulundu�una bakal�m

int main() {
	char string[1000],*sifir,*bir,*iki,*uc,*dort,*bes,*alti,*yedi,*sekiz,*dokuz;
	gets(string);
	sifir=strchr(string,'0');
	bir=strchr(string,'1');
	iki=strchr(string,'2');
	uc=strchr(string,'3');
	dort=strchr(string,'4');
	bes=strchr(string,'5');
	alti=strchr(string,'6');
	yedi=strchr(string,'7');
	sekiz=strchr(string,'8');
	dokuz=strchr(string,'9');
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0;
	while(sifir!=NULL) {
		sifir=strchr(sifir+1,'0');	//mesela string adl� katar i�in "agd0asd210aas2830a01" yazd���m� varsayal�m, kodun 4. sat�r�nda sifir pointer'� "0asd210aas2830a01" adl� diziyi (katar�) g�steriyor olacak
		a++;						//while d�ng�s�n�n i�inde pointer 1 artt�r�l�nca pointer'�n g�sterdi�i katar "asd210aas2830a01" olacak ve strchr fonksiyonu ile sifir pointer'� art�k "0aas2830a01" katar�n� g�sterecek
	}								//pointer NULL ("") olana kadar d�ng�deki bu i�lem devam edecek ve katardan at�lan her bir '0' karakteri i�in a sayac� 1 artt�r�lacak
	while(bir!=NULL) {				//b�ylelikle a sayac� string adl� katar�mda ge�en '0' say�s�na e�it olacak
		bir=strchr(bir+1,'1');
		b++;
	}								//o y�zden bir katarda hangi karakterin ka� defa ge�ti�ini bulmak i�in "pt=strchr(kataradi,'karakter');  while(pt!=NULL) { pt=strchr(pt+1,'karakter'); sayac; }" komutu kullan�l�r
	while(iki!=NULL) {
		iki=strchr(iki+1,'2');
		c++;
	}
	while(uc!=NULL) {
		uc=strchr(uc+1,'3');
		d++;
	}
	while(dort!=NULL) {
		dort=strchr(dort+1,'4');
		e++;
	}
	while(bes!=NULL) {
		bes=strchr(bes+1,'5');
		f++;
	}
	while(alti!=NULL) {
		alti=strchr(alti+1,'6');
		g++;
	}
	while(yedi!=NULL) {
		yedi=strchr(yedi+1,'7');
		h++;
	}
	while(sekiz!=NULL) {
		sekiz=strchr(sekiz+1,'8');
		i++;
	}
	while(dokuz!=NULL) {
		dokuz=strchr(dokuz+1,'9');
		j++;
	}
	printf("\n0 1 2 3 4 5 6 7 8 9\n*******************\n");
	printf("%d %d %d %d %d %d %d %d %d %d",a,b,c,d,e,f,g,h,i,j);
}

   bir de bunu diziler ve for d�ng�s� yard�m�yla �ngiliz alfabesindeki harfler i�in yapal�m

int main() {
	char *Ingiliz_alfabesi="abcdefghijklmnopqrstuvwxyz",string[1500],*pointer[26];
	int sayac[26],i;	//26 tane harf i�in 26 tane pointer, 26 tane de sayac�m�z var
	gets(string);
	printf("\n");
	for(i=0;i<26;i++) {
		sayac[i]=0;
		pointer[i]=strchr(string,Ingiliz_alfabesi[i]);
		while(pointer[i]!=NULL) {
			pointer[i]=strchr(pointer[i]+1,Ingiliz_alfabesi[i]);
			sayac[i]++;
		}
		printf("%c: %d\n",Ingiliz_alfabesi[i],sayac[i]);
	}
}

   asl�nda her katar�n sonunda fazladan g�r�nmez bir karakter vard�r: NULL	('\0')
   mesela: "Bogazici Universitesi"	=	{'B','o','g','a','z','i','c','i',' ','U','n','i','v','e','r','s','i','t','e','s','i','\0'}
   <string.h> k�t�phanesinin fonksiyonlar� genelde her katar�n sonunun '\0' karakteri ile bitmesi �art�na ba�l� �al��t��� i�in �ok g�venli bir k�t�phane de�ildir
   hadi o zaman buna g�re g�stericileri (aka pointer) �ok fazla kar��t�rmadan kendi string k�t�phanemizi implement edelim */

unsigned int string_length(const char* str) {	//katar�n uzunlu�unu d�nd�r�r	(NULL karakteri hari�)
	unsigned int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}

int string_compare(const char* str1, const char* str2) {	//leksikografik s�ralamada; 1. katar 2. katardan �nce geliyorsa 1, sonra geliyorsa -1, 2 katar da ayn�ysa 0 d�nd�r�r
	unsigned int i;
	for(i=0;str1[i]==str2[i];i++)
		if(str1[i]=='\0')
			return 0;
//	return str1[i]-str2[i];
	return str1[i]<str2[i] ? -1 : 1;
}

char* string_copy(char* str1, const char* str2) {			//2. katar� 1. katara kopyalar ve 1. katar�n yeni de�erini d�nd�r�r, "str1=str2;" assignment statement'� gibi d���n�lebilir
	unsigned int i;
	for(i=0;str2[i]!='\0';i++)
		str1[i]=str2[i];
	str1[i]='\0';
	return str1;
}

char* string_concatenate(char* str1, const char* str2) {	//2. katar� 1. katar�n ucuna ekler ve 1. katar�n yeni de�erini d�nd�r�r, "str1=str1+str2;" assignment statement'� gibi d���n�lebilir
	unsigned int i,j;
	for(i=string_length(str1), j=0; str2[j]!='\0'; i++, j++)
		str1[i]=str2[j];
	str1[i]='\0';
	return str1;
}

char* string_uppercase(char* str) {				//katar�n k���k harf olan b�t�n harflerini b�y�k harf yapar
	unsigned int i;
	for(i=0;str[i]!='\0';i++)
		if('a'<=str[i] && str[i]<='z')
			str[i]-=32;		//'a'-'A' = 97-65 = 32
	return str;
}

char* string_lowercase(char* str) {				//katar�n b�y�k harf olan b�t�n harflerini k���k harf yapar
	unsigned int i;
	for(i=0;str[i]!='\0';i++)
		if('A'<=str[i] && str[i]<='Z')
			str[i]+=32;
	return str;
}

char* string_tokenize(char* str1, const char* str2, short reset) {	//1. katarda e�er 2. katardaki harflerin biri ge�iyorsa o harfin yerine NULL koyar ve 1. katar�n NULL i�areti konmadan �nceki o par�as�n� d�nd�r�r
	static unsigned int k=0, prev_k;	//fonksiyon bir daha �a�r�ld���nda 1. katara en son NULL konulan yerden itibaren katar� taramaya ve 1. katar�n 2. katar�n harflerinin ge�ti�i yerlerine NULL koymaya devam eder
	if(reset) {							//tabii orijinal implementasyonu bu olmad��� i�in k'y� reset'lemek ad�na 3. bir parametre ekledim
		k=0;
		return str1;
	}
	unsigned int i,j;
	for(i=prev_k=k; str1[i]!='\0'; i++)
		for(j=0;str2[j]!='\0';j++)
			if(str1[i]==str2[j]) {
				k=i+1;
				str1[i--]='\0';
				break;
			}
	return str1+prev_k;
}

int main() {
	char str1[100]="Ademcik elmasi", str2[100]="Nuh gemisi";
	printf("str1 = \"%s\"\tstr2 = \"%s\"",str1,str2);

	printf("\n\nstrlen(str1) = %u\tstrlen(str2) = %u", string_length(str1), string_length(str2));
	printf("\nstrlen(\"Cekoslavakyalilastiramadiklarimizdan misiniz\") = %u", string_length("Cekoslavakyalilastiramadiklarimizdan misiniz"));

	printf("\n\nstrcmp(str1,str2) = %d", string_compare(str1,str2));
	printf("\nstrcmp(\"elma\",\"armut\") = %d", string_compare("elma","armut"));
	printf("\nstrcmp(\"sdjkhsdfaad\",\"sdjkhsdfaad\") = %d", string_compare("sdjkhsdfaad","sdjkhsdfaad"));

	printf("\n\nstrcpy(str1,str2) = \"%s\"", string_copy(str1,str2));

	printf("\n\nstr1 = \"%s\"",str1);
	string_copy(str1,"Ademcik elmasi");
	printf("\nstr1 = \"%s\"",str1);

	printf("\n\nstrcat(str1,str2) = \"%s\"", string_concatenate(str1,str2));
	printf("\nstr1 = \"%s\"",str1);
	string_copy(str1,"Ademcik elmasi");
	printf("\nstr1 = \"%s\"",str1);

	printf("\n\nstrupr(str1) = \"%s\"", string_uppercase(str1));
	string_copy(str1,"AdEmCiK ElMAsi");
	printf("\nstr1 = \"%s\"",str1);
	printf("\nstrlwr(str1) = \"%s\"", string_lowercase(str1));

	string_copy(str1,"Bu bir Ademcik elmasi -maskulen tiroit cikintisinin afili adi, eh?-, Nuh gemisi degil.");
	printf("\n\nstr1 = \"%s\"",str1);
	unsigned int str1_len=string_length(str1), i;
	char* buffer;

	do {
		printf("\nstrtok(str1,str2) = \"%s\"", buffer=string_tokenize(str1," .,-",0));
		printf("\nstr1 = \"");
		for(i=0;i<str1_len;i++)
			printf(str1[i]!='\0' ? "%c" : "'\\0'", str1[i]);
		printf("\"\n");
	} while(buffer+string_length(buffer) != str1+str1_len);		//buffer'�n NULL karakterinin adresi str1'in NULL karakterinin adresine e�itse, d�ng�den ��k

	string_copy(str1,"Hey,123,kes lan amcik!!!");
	printf("\n\nstr1 = \"%s\"", buffer=str1);
	str1_len=string_length(str1);
	string_tokenize(NULL,NULL,1);		//reset'ledim, k=0 art�k

	do {
		printf("\nstrtok(str1,str2) = \"%s\"", buffer=string_tokenize(str1," .,-",0));
		printf("\nstr1 = \"");
		for(i=0;i<str1_len;i++)
			printf(str1[i]!='\0' ? "%c" : "'\\0'", str1[i]);
		printf("\"\n");
	} while(buffer+string_length(buffer) != str1+str1_len);

	return 0;
}
