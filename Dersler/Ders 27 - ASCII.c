#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* "ASCII: American Standard Code for Information Interchange , Bilgi De�i�imi ��in Amerikan Standart Kodlama Sistemi"
   pointer konusunu i�lerken char de�i�kenlerinin belle�e ASCII kodlar� bi�iminde kaydedildi�inden bahsetmi�tik
   yazd�r�labilir karakterlerin ASCII kodlar� a�a��da verilmi�tir (32 ASCII kodlu karakter bo�luk ([space]) bu arada):

   32: '   '	33: ' ! '	34:	' " '	35: ' # '	36:	' $ '	37: ' % '	38: ' & '	39: ' ' '	40: ' ( '	41: ' ) '	42: ' * '	43: ' + '	44:	' , '	45:	' - '	46: ' . '	47: ' / '
   48: ' 0 '	49: ' 1 '	50: ' 2	'	51: ' 3 '	52: ' 4 '	53: ' 5	'	54: ' 6 '	55: ' 7 '	56: ' 8 '	57: ' 9 '	58:	' : '	59:	' ; '	60: ' < '	61: ' = '	62: ' > '	63: ' ? '
   64: ' @ '	65: ' A '	66: ' B '	67: ' C '	68: ' D '	69: ' E '	70: ' F '	71: ' G '	72: ' H '	73: ' I '	74: ' J '	75: ' K '	76: ' L '	77: ' M '	78: ' N '	79: ' O '
   80: ' P '	81: ' Q '	82: ' R '	83: ' S '	84: ' T '	85: ' U '	86: ' V '	87: ' W '	88: ' X '	89: ' Y '	90: ' Z '	91: ' [ '	92: ' \ '	93: ' ] '	94: ' ^ '	95: ' _ '
   96: ' ` '	97: ' a '	98: ' b '	99: ' c '	100: ' d '	101: ' e '	102: ' f '	103: ' g '	104: ' h '	105: ' i '	106: ' j '	107: ' k '	108: ' l '	109: ' m '	110: ' n '	111: ' o '
   112: ' p '	113: ' q '	114: ' r '	115: ' s '	116: ' t '	117: ' u '	118: ' v '	119: ' w '	120: ' x '	121: ' y '	122: ' z '	123: ' { '	124: ' | '	125: ' } '	126: ' ~ '

   �u ana kadar " char degiskenadi='karakter' " syntax'� ile char de�i�kenlerimizi tan�mlasak da alternatif olarak ASCII kodlar�na g�re
   " char degiskenadi=ASCIIkodu " syntax'� da kullan�labilir

int main() {
	char karakter;
	printf("Karakter giriniz: ");
	scanf("%c",&karakter);
	printf("Girdiginiz karakter ve ASCII kodu: '%c' %d",karakter,karakter);
}

int main() {
	char harf1=65,harf2=71,harf3=105,karakter1=35,karakter2=43,rakam1=55,rakam2=49;		//tabloya g�re: harf1='A', harf2='G', harf3='i', karakter1='#', karakter2='+', rakam1='7', rakam2='1'
	printf("%c %c %c %c %c %c %c",karakter1,karakter2,rakam1,rakam2,harf1,harf2,harf3);	//��kt�m "# + 7 1 A G i"
	harf1+=4;	//harf1=65+4=69, 69 nolu ASCII koduna sahip karakter 'E' dolay�s�yla harf1='E'
	harf2-=7;	//harf2=71-7=64, 64 nolu ASCII koduna sahip karakter '@' dolay�s�yla harf1='@'
	printf("\n%c %c",harf1,harf2);	//��kt�m "E @"
	char hmmmm1='a'+1,hmmmm2='T'-10;	//'a'=97 dolay�s�yla hmmmm1=97+1=98 ==> hmmmm1='b'; 'T'=84 dolay�s�yla hmmmm2=84-10=74 yani hmmmm2='J'
	printf("\n%c %c",hmmmm1,hmmmm2);	//��kt�m "b J"
}

   o zaman hadi matris ve ASCII kodlar� yard�m�yla �stteki tabloyu kabaca yazd�ral�m

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
		kalan=sayi%16;		//en sa� basama�a konacak say�y� al
		if(kalan<10)
			hex_arr[++i]=48+kalan;	//��nk� 0,1,2,...,9 rakamlar� s�ras�yla 48,49,50,...,57 ASCII kodlar�na sahip
		else		//i'yi �nce 1 artt�r, sonra gir
			hex_arr[++i]=55+kalan;	//��nk� 10,11,12,13,14,15'in hexadecimal'deki kar��l��� olan A,B,C,D,E,F "rakam"lar� s�ras�yla 65,66,67,68,69,70 ASCII kodlar�na sahip
		sayi/=16;	//b�l�m� al		(alternatif olarak a,b,c,d,e,f kullan�lacaksa "hex_arr[++i]=87+kalan" statement'� kullan�l�r, ��nk� bunlar s�rayla 97,98,99,100,101,102 ASCII kodlar�na sahip)
	}
	printf("On alti tabanindaki (hexadecimal) karsiligi: ");
	for(j=i;j>=0;j--)		//hex_arr string'ini tersten yazd�r, zaten i de�eri hex_arr katar�ndaki en sondaki eleman�n index'ine e�it
		printf("%c",hex_arr[j]);
}

   klavyeden girilen bir katar� say�ya d�n��t�r�p de yazd�rabiliriz ;)

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

   son olarak b�y�k harfleri k���k, k���k harfleri b�y�k yazd�ral�m  (swapcase) */

char* swapcase(char *string) {		//��kt�m char dizisi (string) oldu�undan fonksiyonumu char* diye ba�latt�m
	int i;							//"unsigned int i" yap�nca warning vermiyo zira strlen fonksiyonu "unsigned int" d�nd�r�yor
	for(i=0;i<strlen(string);i++) {
		if(65<=string[i] && string[i]<=90)		//'a'-'A'=32 oldu�undan 'a'-'A' yerine direkt 32 de�erini yazabilirim, e�er unutursam da 'a'-'A','b'-'B',...,'z'-'Z' ifadelerinden istedi�imi kullanabilirim
			string[i]+=32;		//alternatif olarak burada tolower(string[i])
		else if(97<=string[i] && string[i]<=122)
			string[i]-=32;		//burada ise toupper(string[i]) fonksiyonu (<ctype.h> sa�olsun) kullan�labilir
	}
	return string;
}
int main() {
	char *cumle;
	printf("Cumleyi giriniz: ");
	cumle=(char*) malloc(sizeof(char)*1000);	//"cumle" katar�m i�in 1000 karakterlik bir bellek tahsisi yapt�m
	gets(cumle);
	cumle=(char*) realloc(cumle,strlen(cumle)+1);	//yeniden bellek tahsisi yapt�m
	printf("Caseleri swaplanmis cumle: %s",swapcase(cumle));
	exit(0);
}
