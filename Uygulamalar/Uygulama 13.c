#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

/* Mandelbrot kümesini sadece for döngüsünden yararlanarak konsola çizdiren program

int main() {									//daha da kompakt bir þekilde:
	int index=0;								//int main(index) {
	float i,j,r,x,y;							//    float i,j,r,x,y;
	char string[16]=" .:-;!/>)|&IH%*#";			//    for(y=-16; y++<15; printf("\n"))
	for(y=-16;y<15;y++) {						//        for(x=0; x++<84; putchar(" .:-;!/>)|&IH%*#"[index&15]))
		for(x=0;x<84;x++) {						//            for(i=index=r=0; j=r*r-i*i-2+x/25, i=2*r*i+y/10, j*j+i*i<11 && index++<111; r=j);
			putchar(string[index&15]);			//}
			for(i=index=r=0; j=r*r-i*i-2+x/25, i=2*r*i+y/10, j*j+i*i<11 && index++<111;) {
				r=j;			//bu arada "&" bitsel operatör, örneðin:		"1001100110"
			}																//&	"1011001101"
		}																	//= "1001000100"
		printf("\n");														//bu ifadenin decimal'deki karþýlýðý: 614 & 717 = 580
	}		//çýktým 84x31 karakter ebatlarýnda bir Mandelbrot kümesi
}

   Sierspinki üçgenini sadece for döngüsünden yararlanarak konsola çizdiren program						Klavyeden girilen her n, a, b deðerleri için n uzunluðundaki her biri b tane farklý harf barýndýran
																										a uzunluðundaki alt katarlardan (substring) oluþan bir kelime yazdýran program
int main() {
	int tekrar;																							int main() {
	printf("Tekrar sayisini giriniz (6'dan kucuk olsun): ");												int t,n,a,b,i;
	scanf("%d",&tekrar);																					printf("Test senaryosu sayisini giriniz: ");
	int n=4*pow(2,tekrar-1),i,x,y;																			scanf("%d",&t);
	for(y=n-1;y>=0;y--) {																					while(t--) {
		for(i=0;i<y;i++)																						printf("Kelime uzunlugunu, alt katar uzunlugunu ve farkli harf sayisini sirayla giriniz (n,a,b): ");
			printf(" ");																						scanf("%d %d %d",&n,&a,&b);
		for(x=0;x+y<n;x++)																						printf("%d uzunlugundaki tum alt katarlari %d harf iceren %d uzunlugunda bir katar: ",a,b,n);
			printf(x&y ? "  " : "* ");																			for(i=0;i<n;i++)
		printf("\n");																								printf("%c",'a'+i%b);		//evet, cevap a'ya baðlý deðil, o yüzden a boþuna taranýyor
	}																											printf("\n");
}																											}
																										}

   Cantor kümesini matris kullanarak konsola çizdiren recursive program									Klavyeden girilen N çift pozitif tam sayý deðeri için ilk yarýsý tek, diðer yarýsý çift tam sayýlardan oluþan
																										ve ilk yarýsýndaki elemanlar toplamý diðer yarýsýndaki elemanlar toplamýna eþit olan bir dizi oluþturulup
#define WIDTH 81																						oluþturulamayacaðýný "EVET" ile "HAYIR" biçiminde cevaplayan, ve eðer oluþturulabiliyorsa o koþullarý saðlayan
#define HEIGHT 5																						örnek bir dizi yazdýran program
char lines[HEIGHT][WIDTH];
																										int main() {
void init_matrix() {																						int t;
	int i,j;																								printf("Test senaryosu sayisini giriniz: ");
	for(i=0;i<HEIGHT;i++)																					scanf("%d",&t);
		for(j=0;j<WIDTH;j++)																				while(t--) {
			lines[i][j]='*';																					int N;
}																												printf("Dizinin buyuklugunu giriniz: ");
void set_cantor(int start, int len, int index) {																scanf("%d",&N);
	int i,j,seg=len/3;																							if(N%4==0) {
	if(seg==0)																										printf("EVET\nDizi: ");
		return;																										int *dizi=(int*) malloc(N*sizeof(int)),i;
	for(i=index;i<HEIGHT;i++)																						for(i=0;i<N/2;i++)
        for(j=start+seg; j<start+seg*2; j++)																			dizi[i]=2*i+2;
			lines[i][j]=' ';																						for(;i<N-1;i++)
	set_cantor(start, seg, index+1);																					dizi[i]=2*i-N+1;
	set_cantor(start+seg*2, seg, index+1);																			dizi[i]=2*i-N/2+1;
}																													for(i=0;i<N;i++)
void print_matrix() {																									printf("%d ",dizi[i]);
	int i,j;																									}
	for(i=0;i<HEIGHT;i++) {																						else
		for(j=0;j<WIDTH;j++)																						printf("HAYIR");
			printf("%c",lines[i][j]);																			printf("\n");
		printf("\n");																						}
	}																									}
}
int main() {
	init_matrix();
	set_cantor(0,WIDTH,1);
	print_matrix();
	return 0;
}

   n tane öðrencinin yer aldýðý bir okulda matematiði iyi olan öðrenciler 1, programlamasý iyi olan öðrenciler 2, atletizmi iyi olan öðrenciler 3 numarasý ile
   iþaretlenmiþtir. Okulun geleneksel olimpiyat yarýþmasýna her bir numaradan bir öðrenci yer alacak þekilde 3 kiþilik takýmlar katýlacaðýna göre, bu olimpiyata
   maksimum kaç takýmýn katýlabileceðini ve bu takýmlarý takýmlardaki öðrencilerin klavyeden girilme index'leriyle yazdýran program

int min(int a,int b,int c) {return a>b ? (b>c ? c : b) : (a>c ? c : a);}
int main() {
	int n;
	printf("Okuldaki ogrenci sayisini giriniz: ");
	scanf("%d",&n);
	int dizi[n],dizi1[n],dizi2[n],dizi3[n],counter1=0,counter2=0,counter3=0,i;
	printf("Okuldaki ogrencilerin yetenek no'larini giriniz: ");
	for(i=0;i<n;i++) {
		scanf("%d",&dizi[i]);
		switch(dizi[i]) {
			case 1: dizi1[counter1++]=i+1; break;
			case 2: dizi2[counter2++]=i+1; break;
			case 3: dizi3[counter3++]=i+1;
		}
	}
	int w=min(counter1,counter2,counter3);
	printf("Olusturulabilecek maksimum takim sayisi: %d",w);
	for(i=0;i<w;i++)
		printf("\n%d. Takim: %d %d %d",i+1,dizi1[i],dizi2[i],dizi3[i]);
}

   String kütüphanesini kullanmadan, sadece pointer yardýmýyla klavyeden girilen kelimelerin palindrom olup olmadýðýný yazdýran ve 1000 tane rastgele palindrom üreten program

#define PALINDROM_SAYISI 1000
#define MIN_PALINDROM_UZUNLUGU 5
#define MAX_PALINDROM_UZUNLUGU 50		//ürettiðimiz palindromlarýn boyutu (harf sayýsý) 5-50 arasýnda deðiþiyor

int palindrom_mu(char *kelime) {
	char *duzadres, *tersadres;
	for(tersadres=kelime; *(tersadres+1)!='\0'; tersadres++);	//'\0' = NULL
	for(duzadres=kelime; duzadres<tersadres; duzadres++, tersadres--)
		if(*duzadres != *tersadres)
			return 0;
	return 1;			//1 = true , 0 = false
}
void palindrom_uret() {
	int i,j;
	for(i=1;i<=PALINDROM_SAYISI;i++) {
		int palindrom_boyutu = rand()%(MAX_PALINDROM_UZUNLUGU - MIN_PALINDROM_UZUNLUGU + 1) + MIN_PALINDROM_UZUNLUGU;
		char *palindrom = (char*) calloc(palindrom_boyutu+1, sizeof(char));		//her string '\0', yani NULL ile bittiði için palindrom boyutuna fazladan 1 ekledim
		for(j=0;j<=palindrom_boyutu/2;j++)
			*(palindrom + palindrom_boyutu - 1 - j) = *(palindrom + j) = rand()%('z'-'a'+1) + 'a';		//rand()%('z'-'a'+1) + 'a' = rand()%26 + 97
//		if(!palindrom_mu(palindrom)) {
//			printf("\n\n\n!!!ERROR!!!\nHatali palindrom uretildi.\nPalindrome Uncertainty Emergency Crash Protocol initiated...");
//			exit(1);
//		}
		printf("%d. palindrom: %s\n", i, palindrom);
		free(palindrom);
	}
}
int main() {
	srand((unsigned int)time(NULL));
	palindrom_uret();
	printf("\n\n\n\n");
	while(1) {
		char kelime[100];
		printf("Bir kelime giriniz: ");
		scanf("%s",kelime);
		printf(palindrom_mu(kelime) ? "\n\"%s\" bir palindromdur.\n\n\n" : "\n\"%s\" bir palindrom degildir.\n\n\n", kelime);
	}
}

   Katarlarýn kelime sayýlarýný, n. kelimelerini, n. kelimelerinin silinmiþ hallerini, en çok tekrar eden
   karakterlerini ve oluþtuðu kelimelerinin leksikografik olarak sýralanmýþ hallerini yazdýran Ýngilizce program */

#define MAX_WORD_SIZE 50
#define MAX_STRING_SIZE 1000

unsigned int word_count(char* str) {
	unsigned int i=0,counter=1;
	for(;str[i]!='\0';i++)
		if(str[i]==' ')
			counter++;
	return counter;
}
char* nth_word(char* str, unsigned int n) {
	char* nth_word=(char*) malloc(MAX_WORD_SIZE * sizeof(char));
	unsigned int i=0,j=0,counter=1;
	if(n==1) {
		for(;str[i]!='\0' && str[i]!=' ';i++)
			nth_word[i]=str[i];
		nth_word[i]='\0';
		return nth_word;
	}
	else if(n>word_count(str)) {	//try-catch
		printf("\n!!!There is only %u words in \"%s\", not %u!!!",word_count(str),str,n);
		exit(1);
	}
	for(;str[i]!='\0';i++)
		if(str[i]==' ')
			if(++counter==n) {		//her iterasyonda kontrol etmesin diye bu if'in içine alýp "nested if" yaptým
				for(i++;str[i]!='\0' && str[i]!=' ';i++,j++)
					nth_word[j]=str[i];
				nth_word[j]='\0';
				break;
			}
	return nth_word;
}
char* erase_nth_word(char* str, unsigned int n) {
	char* new_str=(char*) malloc(MAX_STRING_SIZE * sizeof(char));
	unsigned int i=0,j=0,counter=1;
	if(n==1) {
		for(;str[i]!='\0' && str[i]!=' ';i++);
		for(i++;str[i]!='\0';i++,j++)
			new_str[j]=str[i];
		new_str[j]='\0';
		return new_str;
	}
	else if(n>word_count(str)) {
		printf("\n!!!There is only %u words in \"%s\", not %u!!!",word_count(str),str,n);
		exit(1);
	}
	for(;str[i]!='\0';i++,j++) {
		if(str[i]==' ')
			if(++counter==n) {
				if(n!=word_count(str))		//son kelimeyse fazladan boþluk koyma
					new_str[j++]=' ';
				for(i++;str[i]!='\0' && str[i]!=' ';i++);
				for(i++;str[i]!='\0';i++,j++)
					new_str[j]=str[i];
				new_str[j]='\0';
				break;
			}
		new_str[j]=str[i];
	}
	return new_str;
}
char* max_occuring_chars(char* str) {
	char* max_chars=(char*) malloc(256*sizeof(char));
	unsigned int ASCII_count[256]={0},i=0,j=0,k,max_count=0;
	for(;str[i]!='\0';i++)
		if(++ASCII_count[(unsigned int)str[i]]>max_count) {
			for(k=0;k<=j;k++)
				max_chars[k]='\0';
			max_count = ASCII_count[(unsigned int)str[i]];
			max_chars[j=0] = str[i];
		}
		else if(ASCII_count[(unsigned int)str[i]]==max_count)
			max_chars[++j]=str[i];
	max_chars[++j]='\0';
	return max_chars;
}
char* lexicographical_string(char* str) {			//bir tek burada <string.h> kütüphanesini kullandým, kabul
	unsigned int i=1,j, number_of_words=word_count(str);
	char words_in_str[number_of_words][MAX_WORD_SIZE], *token,
	*new_str=(char*) malloc((strlen(str)+1) * sizeof(char)), *str_copy=(char*) malloc((strlen(str)+1) * sizeof(char));
	strcpy(str_copy,str);
	strcpy(words_in_str[0], token=strtok(str_copy," "));
	for(;i<number_of_words;i++)
		strcpy(words_in_str[i], token=strtok(NULL," "));
	for(i=0;i<number_of_words-1;i++)
		for(j=0;j<number_of_words-i-1;j++)
			if(strcmp(words_in_str[j],words_in_str[j+1])>0) {
				char temp[MAX_WORD_SIZE];
				strcpy(temp,words_in_str[j]);
				strcpy(words_in_str[j],words_in_str[j+1]);
				strcpy(words_in_str[j+1],temp);
			}
	strcpy(new_str,words_in_str[0]);
	for(i=1;i<number_of_words;i++) {
		strcat(new_str," ");
		strcat(new_str,words_in_str[i]);
	}
	return new_str;
}
int main() {
	char string[30]="just a normal fucking string", string2[40]="aa3aabbbccccddde3eeeffghijklm3no123",
	string3[150]="armut uzum elma mandalina seftali erik fistik ayva havuc findik balkabagi domates enginar patates sogan portakal";
	unsigned int i;
	printf("Number of words in \"%s\": %u\n\n\n", string, word_count(string));
	for(i=1;i<=word_count(string);i++)
		printf("%uth word in \"%s\": \"%s\"\n", i, string, nth_word(string,i));
	printf("\n\n");
	for(i=1;i<=word_count(string);i++)
		printf("Erased %uth word in \"%s\": \"%s\"\n", i, string, erase_nth_word(string,i));
	printf("\n\nMaximum occuring character(s) in \"%s\": '%s'\n\n\n", string, max_occuring_chars(string));
	printf("Lexicographically ordered \"%s\": \"%s\"\n\n\n", string, lexicographical_string(string));

	printf("Number of words in \"%s\": %u\n", string2, word_count(string2));
	printf("Maximum occuring character(s) in \"%s\": '%s'\n\n\n", string2, max_occuring_chars(string2));

	printf("Number of words in \"%s\": %u\n", string3, word_count(string3));
	for(i=1;i<=word_count(string3);i++)
		printf("%uth word in \"%s\": \"%s\"\n", i, string3, nth_word(string3,i));
	for(i=1;i<=word_count(string3);i++)
		printf("Erased %uth word in \"%s\": \"%s\"\n", i, string3, erase_nth_word(string3,i));
	printf("Maximum occuring character(s) in \"%s\": '%s'\n", string3, max_occuring_chars(string3));
	printf("Lexicographically ordered \"%s\": \"%s\"\n\n\n", string3, lexicographical_string(string3));
	return 0;
}
