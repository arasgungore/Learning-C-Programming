#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* <string.h> kütüphanesinde olan fonksiyonlardan baþlýcalarý þunlardýr: strlen, strcpy, strncpy, strcat, strcmp, strlwr, strupr, strchr, strstr, strtok,...

   "strlen: string length"     "strcpy: string copy"     "strcat: string concatenate"     "strcmp: string compare"
   "tolower: to lower case"     "toupper: to upper case"     "strlwr: string in lower case"     "strupr: string in upper case"
   "strchr: character in string"     "strstr: string in string"     "strtok: tokenize string"

   strlen(x): x katarýnýn kaç karakter uzunluðunda olduðunu hesaplar  (boþluklar dahil)
   strcpy(x,y): y katarýný x katarýna kopyalar, böylelikle x katarý y katarýna eþitlenmiþ olur
   strncpy(x,y,n): y katarýnýn ilk n karakterlik kýsmýný x katarýna kopyalar, x katarýnýn n. karakterden sonraki kýsmýna dokunmaz
   strcat(x,y): x katarýnýn sonuna y katarýný ekler, x katarý x ve y katarlarýnýn birleþimine eþitlenmiþ olur
   strcmp(x,y): x katarý ile y katarýný kýyaslar, x ve y katarlarý birbirine eþit ise o zaman deðeri 0 olur
				leksikografik sýralamaya göre; x katarý y katarýndan büyükse deðeri 0'dan büyük olur, x katarý y katarýndan küçükse deðeri 0'dan küçük olur
				(yapýlan iþlem katarlarý oluþturan karakterlerin ASCII kodlarýnýn farký ile alakalý)
   tolower(x): x karakterini büyük harf ise küçük harf yapar, küçük harf ve diðer karakterlere dokunmaz
   toupper(x): x karakterini küçük harf ise büyük harf yapar, büyük harf ve diðer karakterlere dokunmaz
			   aslýnda tolower(x) ve toupper(x) <string.h> kütüphanesinde yok <ctype.h> kütüphanesinde var
			   zaten string deðil karakter fonksiyonlarý ama ben yine de burada bunlara da deðinmek istedim :)
   strlwr(x): x katarýndaki bütün büyük harfleri küçük harf yapar, küçük harf ve diðer karakterlere dokunmaz
   strupr(x): x katarýndaki bütün küçük harfleri büyük harf yapar, büyük harf ve diðer karakterlere dokunmaz
   strchr(x,y): x katarýnda ilk defa y karakteri geçtiðinde y dahil y'den SONRASINI pointer'a gönderir
				pointer aracýlýðý ile x katarýnda kaç defa y karakterinin geçtiðini bulmak için de kullanýlabilir
   strstr(x,y): x katarýnda ilk defa y katarý geçtiðinde y dahil y'den SONRASINI pointer'a gönderir
				pointer aracýlýðý ile x katarýnda kaç defa y katarýnýn geçtiðini bulmak için de kullanýlabilir
   strtok(x,y): x katarýnda ilk defa y katarý geçtiðinde y dahil y'den ÖNCESÝNÝ pointer'a gönderir
				genelde while döngüsü ile x katarýný parçalara ayýrmak için kullanýlýr

int main() {
	char katar[100];
	printf("Cumle Yaziniz: ");
	gets(katar);				//scanf("%s",&katar) yazsaydým bu sefer misal "Merhaba Dunya" yazdýðýmda çýktým "7" olacaktý, zira scanf boþluktan sonrasýný belleðe (RAM'e) kaydetmiyor
	printf("Cumlenizdeki harf sayisi (bosluklar dahil): %d",strlen(katar));
}

int main() {
	char kaynak[30]="Merhaba Balikesir",kopya[30]="Merhaba Kayserilililililili-",kaynak2[30]="Hello Amsterdam";
	printf("Kaynak: %s\n",kaynak);	//çýktý "Merhaba Balikesir"
	strcpy(kopya,kaynak);
	printf("Kopya: %s\n",kopya);	//çýktý "Merhaba Balikesir", kaynak'ýn kendisi
	strncpy(kopya,kaynak2,10);
	printf("2. Kopya: %s\n",kopya); //çýktý "Hello Amstlikesir"; çünkü kaynak2'nin ilk 10 karakteri olan "Hello Amst", kopya="Merhaba Balikesir"in ilk 10 karakterinin yerini aldý
}

int main() {
	char kitapad[30],yazar[30],kitapyazar[60]="";
	printf("Kitap Adi ve Yazari Girin: ");
	scanf("%s%s",kitapad,yazar);	//mesela "SucVeCeza" ve "Dostoyevski" yazsaydým
	strcat(kitapyazar,kitapad);
	strcat(kitapyazar," <--> ");
	strcat(kitapyazar,yazar);
	printf("\n%s",kitapyazar);		//çýktým "SucVeCeza <--> Dostoyevski" olurdu
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
		printf("%c", i==0 ? toupper(cumle[i]) : cumle[i]);	//girilen cümlenin (kelime de olabilir) sadece baþ harfini büyük yapar, gerisine dokunmaz
}

int main() {														int main() {
	char t[15]="Hey Barney hey!";										char s1[]="Saint Petersburg";
	puts(t);						//"Hey Barney hey!"					char c='P';
	puts(strlwr(t));				//"HEY BARNEY HEY!"					char *pt;
	puts(strupr(t));				//"hey barney hey!"					pt=strchr(s1,c);
}																		printf("%s",pt);		//çýktým "Petersburg", çünkü "Saint Petersburg"da 'P' karakterinin ilk geçtiði kýsým "Petersburg"

int main() {
	char *p,*t="sikime:bak:hele:ya";
	p=t;							   //"sikime:bak:hele:ya
	puts(p);							//bak:hele:ya
	while((p=strchr(p,':'))!=NULL)		//hele:ya
		puts(++p);						//ya"
}										//++p yerine p++ kullanýlsaydý 2.,3.,4. satýrlarýn baþýnda fazladan ":" olurdu
										//çünkü pointer'ý bir arttýrdýðýmda pointer karakter dizisinin bir sonraki elemanýný gösteriyor ve o elemandan itibaren olan karakter dizisini alýyor
int main() {
	char s1[]="Hey,123,sesim geliyor mu?";
	char *p;
	p=strtok(s1,",");				   //"Hey
	while(p!=NULL) {					//123
		printf("%s\n",p);				//sesim geliyor mu?"
		p=strtok(NULL,",");
	}
}
   bir katarda hangi rakamdan kaç tane bulunduðuna bakalým

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
		sifir=strchr(sifir+1,'0');	//mesela string adlý katar için "agd0asd210aas2830a01" yazdýðýmý varsayalým, kodun 4. satýrýnda sifir pointer'ý "0asd210aas2830a01" adlý diziyi (katarý) gösteriyor olacak
		a++;						//while döngüsünün içinde pointer 1 arttýrýlýnca pointer'ýn gösterdiði katar "asd210aas2830a01" olacak ve strchr fonksiyonu ile sifir pointer'ý artýk "0aas2830a01" katarýný gösterecek
	}								//pointer NULL ("") olana kadar döngüdeki bu iþlem devam edecek ve katardan atýlan her bir '0' karakteri için a sayacý 1 arttýrýlacak
	while(bir!=NULL) {				//böylelikle a sayacý string adlý katarýmda geçen '0' sayýsýna eþit olacak
		bir=strchr(bir+1,'1');
		b++;
	}								//o yüzden bir katarda hangi karakterin kaç defa geçtiðini bulmak için "pt=strchr(kataradi,'karakter');  while(pt!=NULL) { pt=strchr(pt+1,'karakter'); sayac; }" komutu kullanýlýr
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

   bir de bunu diziler ve for döngüsü yardýmýyla Ýngiliz alfabesindeki harfler için yapalým

int main() {
	char *Ingiliz_alfabesi="abcdefghijklmnopqrstuvwxyz",string[1500],*pointer[26];
	int sayac[26],i;	//26 tane harf için 26 tane pointer, 26 tane de sayacýmýz var
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

   aslýnda her katarýn sonunda fazladan görünmez bir karakter vardýr: NULL	('\0')
   mesela: "Bogazici Universitesi"	=	{'B','o','g','a','z','i','c','i',' ','U','n','i','v','e','r','s','i','t','e','s','i','\0'}
   <string.h> kütüphanesinin fonksiyonlarý genelde her katarýn sonunun '\0' karakteri ile bitmesi þartýna baðlý çalýþtýðý için çok güvenli bir kütüphane deðildir
   hadi o zaman buna göre göstericileri (aka pointer) çok fazla karýþtýrmadan kendi string kütüphanemizi implement edelim */

unsigned int string_length(const char* str) {	//katarýn uzunluðunu döndürür	(NULL karakteri hariç)
	unsigned int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}

int string_compare(const char* str1, const char* str2) {	//leksikografik sýralamada; 1. katar 2. katardan önce geliyorsa 1, sonra geliyorsa -1, 2 katar da aynýysa 0 döndürür
	unsigned int i;
	for(i=0;str1[i]==str2[i];i++)
		if(str1[i]=='\0')
			return 0;
//	return str1[i]-str2[i];
	return str1[i]<str2[i] ? -1 : 1;
}

char* string_copy(char* str1, const char* str2) {			//2. katarý 1. katara kopyalar ve 1. katarýn yeni deðerini döndürür, "str1=str2;" assignment statement'ý gibi düþünülebilir
	unsigned int i;
	for(i=0;str2[i]!='\0';i++)
		str1[i]=str2[i];
	str1[i]='\0';
	return str1;
}

char* string_concatenate(char* str1, const char* str2) {	//2. katarý 1. katarýn ucuna ekler ve 1. katarýn yeni deðerini döndürür, "str1=str1+str2;" assignment statement'ý gibi düþünülebilir
	unsigned int i,j;
	for(i=string_length(str1), j=0; str2[j]!='\0'; i++, j++)
		str1[i]=str2[j];
	str1[i]='\0';
	return str1;
}

char* string_uppercase(char* str) {				//katarýn küçük harf olan bütün harflerini büyük harf yapar
	unsigned int i;
	for(i=0;str[i]!='\0';i++)
		if('a'<=str[i] && str[i]<='z')
			str[i]-=32;		//'a'-'A' = 97-65 = 32
	return str;
}

char* string_lowercase(char* str) {				//katarýn büyük harf olan bütün harflerini küçük harf yapar
	unsigned int i;
	for(i=0;str[i]!='\0';i++)
		if('A'<=str[i] && str[i]<='Z')
			str[i]+=32;
	return str;
}

char* string_tokenize(char* str1, const char* str2, short reset) {	//1. katarda eðer 2. katardaki harflerin biri geçiyorsa o harfin yerine NULL koyar ve 1. katarýn NULL iþareti konmadan önceki o parçasýný döndürür
	static unsigned int k=0, prev_k;	//fonksiyon bir daha çaðrýldýðýnda 1. katara en son NULL konulan yerden itibaren katarý taramaya ve 1. katarýn 2. katarýn harflerinin geçtiði yerlerine NULL koymaya devam eder
	if(reset) {							//tabii orijinal implementasyonu bu olmadýðý için k'yý reset'lemek adýna 3. bir parametre ekledim
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
	} while(buffer+string_length(buffer) != str1+str1_len);		//buffer'ýn NULL karakterinin adresi str1'in NULL karakterinin adresine eþitse, döngüden çýk

	string_copy(str1,"Hey,123,kes lan amcik!!!");
	printf("\n\nstr1 = \"%s\"", buffer=str1);
	str1_len=string_length(str1);
	string_tokenize(NULL,NULL,1);		//reset'ledim, k=0 artýk

	do {
		printf("\nstrtok(str1,str2) = \"%s\"", buffer=string_tokenize(str1," .,-",0));
		printf("\nstr1 = \"");
		for(i=0;i<str1_len;i++)
			printf(str1[i]!='\0' ? "%c" : "'\\0'", str1[i]);
		printf("\"\n");
	} while(buffer+string_length(buffer) != str1+str1_len);

	return 0;
}
