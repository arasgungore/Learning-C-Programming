#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* "ASCII: American Standard Code for Information Interchange , Bilgi Deðiþimi Ýçin Amerikan Standart Kodlama Sistemi"
   pointer konusunu iþlerken char deðiþkenlerinin belleðe ASCII kodlarý biçiminde kaydedildiðinden bahsetmiþtik
   yazdýrýlabilir karakterlerin ASCII kodlarý aþaðýda verilmiþtir (32 ASCII kodlu karakter boþluk ([space]) bu arada):

   32: '   '	33: ' ! '	34:	' " '	35: ' # '	36:	' $ '	37: ' % '	38: ' & '	39: ' ' '	40: ' ( '	41: ' ) '	42: ' * '	43: ' + '	44:	' , '	45:	' - '	46: ' . '	47: ' / '
   48: ' 0 '	49: ' 1 '	50: ' 2	'	51: ' 3 '	52: ' 4 '	53: ' 5	'	54: ' 6 '	55: ' 7 '	56: ' 8 '	57: ' 9 '	58:	' : '	59:	' ; '	60: ' < '	61: ' = '	62: ' > '	63: ' ? '
   64: ' @ '	65: ' A '	66: ' B '	67: ' C '	68: ' D '	69: ' E '	70: ' F '	71: ' G '	72: ' H '	73: ' I '	74: ' J '	75: ' K '	76: ' L '	77: ' M '	78: ' N '	79: ' O '
   80: ' P '	81: ' Q '	82: ' R '	83: ' S '	84: ' T '	85: ' U '	86: ' V '	87: ' W '	88: ' X '	89: ' Y '	90: ' Z '	91: ' [ '	92: ' \ '	93: ' ] '	94: ' ^ '	95: ' _ '
   96: ' ` '	97: ' a '	98: ' b '	99: ' c '	100: ' d '	101: ' e '	102: ' f '	103: ' g '	104: ' h '	105: ' i '	106: ' j '	107: ' k '	108: ' l '	109: ' m '	110: ' n '	111: ' o '
   112: ' p '	113: ' q '	114: ' r '	115: ' s '	116: ' t '	117: ' u '	118: ' v '	119: ' w '	120: ' x '	121: ' y '	122: ' z '	123: ' { '	124: ' | '	125: ' } '	126: ' ~ '

   þu ana kadar " char degiskenadi='karakter' " syntax'ý ile char deðiþkenlerimizi tanýmlasak da alternatif olarak ASCII kodlarýna göre
   " char degiskenadi=ASCIIkodu " syntax'ý da kullanýlabilir

int main() {
	char karakter;
	printf("Karakter giriniz: ");
	scanf("%c",&karakter);
	printf("Girdiginiz karakter ve ASCII kodu: '%c' %d",karakter,karakter);
}

int main() {
	char harf1=65,harf2=71,harf3=105,karakter1=35,karakter2=43,rakam1=55,rakam2=49;		//tabloya göre: harf1='A', harf2='G', harf3='i', karakter1='#', karakter2='+', rakam1='7', rakam2='1'
	printf("%c %c %c %c %c %c %c",karakter1,karakter2,rakam1,rakam2,harf1,harf2,harf3);	//çýktým "# + 7 1 A G i"
	harf1+=4;	//harf1=65+4=69, 69 nolu ASCII koduna sahip karakter 'E' dolayýsýyla harf1='E'
	harf2-=7;	//harf2=71-7=64, 64 nolu ASCII koduna sahip karakter '@' dolayýsýyla harf1='@'
	printf("\n%c %c",harf1,harf2);	//çýktým "E @"
	char hmmmm1='a'+1,hmmmm2='T'-10;	//'a'=97 dolayýsýyla hmmmm1=97+1=98 ==> hmmmm1='b'; 'T'=84 dolayýsýyla hmmmm2=84-10=74 yani hmmmm2='J'
	printf("\n%c %c",hmmmm1,hmmmm2);	//çýktým "b J"
}

   o zaman hadi matris ve ASCII kodlarý yardýmýyla üstteki tabloyu kabaca yazdýralým

int main() {																					int main() {
	char karakter[6][16];																			char k;
	int i,j,a=32;																					printf("Karakter giriniz: ");
	for(i=0;i<6;i++) {																				scanf("%c",&k);
		for(j=0;j<16;j++) {																			if('a'<=k && k<='z')
			karakter[i][j]=a;																			printf("%c kucuk bir harftir",k);
			if(karakter[i][j]!=127)																	else if('A'<=k && k<='Z')
				printf("%d: ' %c '  ",a,karakter[i][j]);												printf("%c buyuk bir harftir",k);
			a++;																					else if('0'<=k && k<='9')
		}																								printf("%c bir rakamdir",k);
		printf("\n");																				else
	}																									printf("Gecersiz giris");
}																								}

int main() {
	int sayi,i=-1,j,kalan;
	char hex_arr[50];
	printf("On tabaninda (decimal) bir sayi giriniz: ");
	scanf("%d",&sayi);
	while(sayi!=0) {
		kalan=sayi%16;		//en sað basamaða konacak sayýyý al
		if(kalan<10)
			hex_arr[++i]=48+kalan;	//çünkü 0,1,2,...,9 rakamlarý sýrasýyla 48,49,50,...,57 ASCII kodlarýna sahip
		else		//i'yi önce 1 arttýr, sonra gir
			hex_arr[++i]=55+kalan;	//çünkü 10,11,12,13,14,15'in hexadecimal'deki karþýlýðý olan A,B,C,D,E,F "rakam"larý sýrasýyla 65,66,67,68,69,70 ASCII kodlarýna sahip
		sayi/=16;	//bölümü al		(alternatif olarak a,b,c,d,e,f kullanýlacaksa "hex_arr[++i]=87+kalan" statement'ý kullanýlýr, çünkü bunlar sýrayla 97,98,99,100,101,102 ASCII kodlarýna sahip)
	}
	printf("On alti tabanindaki (hexadecimal) karsiligi: ");
	for(j=i;j>=0;j--)		//hex_arr string'ini tersten yazdýr, zaten i deðeri hex_arr katarýndaki en sondaki elemanýn index'ine eþit
		printf("%c",hex_arr[j]);
}

   klavyeden girilen bir katarý sayýya dönüþtürüp de yazdýrabiliriz ;)

int main() {
	char string[40];
	unsigned long long sayi=0;
	unsigned int i=0,k;
	printf("Katari yaziniz: ");
	gets(string);
	k=strlen(string);
	while(k--)
		sayi+=(string[i++]-'0')*pow(10,k);
	printf("Katarin sayiya donusturulmus hali: %llu",sayi);
}

   son olarak büyük harfleri küçük, küçük harfleri büyük yazdýralým  (swapcase) */

char* swapcase(char *string) {		//çýktým char dizisi (string) olduðundan fonksiyonumu char* diye baþlattým
	int i;							//"unsigned int i" yapýnca warning vermiyo zira strlen fonksiyonu "unsigned int" döndürüyor
	for(i=0;i<strlen(string);i++) {
		if(65<=string[i] && string[i]<=90)		//'a'-'A'=32 olduðundan 'a'-'A' yerine direkt 32 deðerini yazabilirim, eðer unutursam da 'a'-'A','b'-'B',...,'z'-'Z' ifadelerinden istediðimi kullanabilirim
			string[i]+=32;		//alternatif olarak burada tolower(string[i])
		else if(97<=string[i] && string[i]<=122)
			string[i]-=32;		//burada ise toupper(string[i]) fonksiyonu (<ctype.h> saðolsun) kullanýlabilir
	}
	return string;
}
int main() {
	char *cumle;
	printf("Cumleyi giriniz: ");
	cumle=(char*) malloc(sizeof(char)*1000);	//"cumle" katarým için 1000 karakterlik bir bellek tahsisi yaptým
	gets(cumle);
	cumle=(char*) realloc(cumle,strlen(cumle)+1);	//yeniden bellek tahsisi yaptým
	printf("Caseleri swaplanmis cumle: %s",swapcase(cumle));
	exit(0);
}
