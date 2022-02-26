#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdarg.h>
#include <assert.h>

/* <stdarg.h> kütüphanesinden yararlanarak oluþturulan ve sonsuz tane parametre alan sum(), min(), max() fonksiyonlarý içine yazýlan parametrelerin sýrasýyla toplamýný, en küçüðünü ve en büyüðünü döndüren kullanýcý tanýmlý
   fonksiyonlar olduðuna göre bu fonksiyonlarýn sorunsuz bir þekilde çalýþýp çalýþmadýðýný bu fonksiyonlara MIN_ELEMENT ve MAX_ELEMENT sabitleri arasýnda yer alan sýrasýyla 3, 5 ve 10 tane rastgele parametre atayarak yapýlan
   test implementasyonlarýyla kontrol eden Ýngilizce program

#define MIN_ELEMENT 0
#define MAX_ELEMENT 1000000
int i;
int sum(int count, ...) {
	int sum=0;
	va_list values;
	va_start(values,count);
	for(i=0;i<count;i++)
		sum+=va_arg(values,int);
	va_end(values);
	return sum;
}
int min(int count, ...) {
	int min=MAX_ELEMENT,test;
	va_list values;
	va_start(values,count);
	for(i=0;i<count;i++) {
		test=va_arg(values,int);
		if(min>test)
			min=test;
	}
	va_end(values);
	return min;
}
int max(int count, ...) {
	int max=MIN_ELEMENT,test;
	va_list values;
	va_start(values,count);
	for(i=0;i<count;i++) {
		test=va_arg(values,int);
		if(max<test)
			max=test;
	}
	va_end(values);
	return max;
}
int test_implementations_by_sending_three_elements() {
	srand(time(NULL));
	int elements[3];
	for(i=0;i<3;i++)
		elements[i]=rand()%(MAX_ELEMENT-MIN_ELEMENT+1)+MIN_ELEMENT;
	fprintf(stderr, "Sending following three elements:\n");
	for(i=0;i<3;i++)
		fprintf(stderr, "%d\n", elements[i]);
	int elements_sum=sum(3, elements[0], elements[1], elements[2]);
	int minimum_element=min(3, elements[0], elements[1], elements[2]);
	int maximum_element=max(3, elements[0], elements[1], elements[2]);
	fprintf(stderr, "Elements sum is %d\nMinimum element is %d\nMaximum element is %d\n\n", elements_sum, minimum_element, maximum_element);
	if(check(3, elements, elements_sum, minimum_element, maximum_element))
		return 1;
	else
		return 0;
}
int test_implementations_by_sending_five_elements() {
	srand(time(NULL));
	int elements[5];
	for(i=0;i<5;i++)
		elements[i]=rand()%(MAX_ELEMENT-MIN_ELEMENT+1)+MIN_ELEMENT;
	fprintf(stderr, "Sending following five elements:\n");
	for(i=0;i<5;i++)
		fprintf(stderr, "%d\n", elements[i]);
	int elements_sum=sum(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
	int minimum_element=min(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
	int maximum_element=max(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
	fprintf(stderr, "Elements sum is %d\nMinimum element is %d\nMaximum element is %d\n\n", elements_sum, minimum_element, maximum_element);
	if(check(5, elements, elements_sum, minimum_element, maximum_element))
		return 1;
	else
		return 0;
}
int test_implementations_by_sending_ten_elements() {
	srand(time(NULL));
	int elements[10];
	for(i=0;i<10;i++)
		elements[i]=rand()%(MAX_ELEMENT-MIN_ELEMENT+1)+MIN_ELEMENT;
	fprintf(stderr, "Sending following ten elements:\n");
	for(i=0;i<10;i++)
		fprintf(stderr, "%d\n", elements[i]);
	int elements_sum=sum(10, elements[0], elements[1], elements[2], elements[3], elements[4], elements[5], elements[6], elements[7], elements[8], elements[9]);
	int minimum_element=min(10, elements[0], elements[1], elements[2], elements[3], elements[4], elements[5], elements[6], elements[7], elements[8], elements[9]);
	int maximum_element=max(10, elements[0], elements[1], elements[2], elements[3], elements[4], elements[5], elements[6], elements[7], elements[8], elements[9]);
	fprintf(stderr, "Elements sum is %d\nMinimum element is %d\nMaximum element is %d\n\n", elements_sum, minimum_element, maximum_element);
	if(check(10, elements, elements_sum, minimum_element, maximum_element))
		return 1;
	else
		return 0;
}
int check(int number_of_elements, int* elements, int sum, int min, int max) {
	int expected_elements_sum=0;
	for(i=0;i<number_of_elements;i++) {
		if(elements[i]<min)
			return 0;
		if(elements[i]>max)
			return 0;   
		expected_elements_sum+=elements[i];
	}
	return sum==expected_elements_sum;
}
int main() {
	int number_of_test_cases;
	printf("Enter the number of test implementations you want to run: ");
	scanf("%d", &number_of_test_cases);
	while(number_of_test_cases-- && test_implementations_by_sending_three_elements() && test_implementations_by_sending_five_elements() && test_implementations_by_sending_ten_elements());
	return 0;
}

   Enter tuþuna basýlana kadar klavyeden girilen bir double dizisinin elemanlarý toplamýný, ortalamasýný, minimum terimini, maksimum terimini, açýklýðýný, modunu ve medyanýný yazdýran program

double toplagel(double* dizi, int n) {
	int i;
	double toplam=0.0;
	for(i=0;i<n;i++)
		toplam+=dizi[i];
	return toplam;
}
double ortbul(double* dizi, int n) {
	return toplagel(dizi,n)/n;
}
double minmaxbul(char* kelime, double* dizi, int n) {
	double dummy=dizi[0]; int i;
	for(i=0;i<n;i++) {
		if(strcmp(kelime,"min")==0) {
			if(dummy>dizi[i])
				dummy=dizi[i];
		}
		else if(strcmp(kelime,"max")==0) {
			if(dummy<dizi[i])
				dummy=dizi[i];
		}
	}
	return dummy;
}
double aciklik(double* dizi, int n) {
	return minmaxbul("max",dizi,n)-minmaxbul("min",dizi,n);
}
double modbul(double* dizi, int n) {
	double mod=dizi[0]; int sayac,max=1,i,j;
	for(i=0;i<n;i++) {
		sayac=0;
		for(j=0;j<n;j++)
			if(dizi[i]==dizi[j])
				sayac++;
		if(sayac>max || (sayac==max && dizi[i]<mod)) {
			max=sayac;
			mod=dizi[i];
		}
	}
	return mod;
}
double medyan(double* dizi, int n) {
	double ortanca;
	if(n%2==1)
		ortanca=dizi[n/2];
	else
		ortanca=(dizi[n/2-1]+dizi[n/2])/2.0;
	return ortanca;
}
int main() {
	double *a=(double*) calloc(1000,sizeof(double)); char k; int n=0;
	printf("Diziyi giriniz: ");
	while(k!='\n')
		scanf("%lf%c",&a[n++],&k);
	a=(double*) realloc(a,n*sizeof(double));
	printf("\n\nGirilen dizinin elemanlari toplami: %.4f",toplagel(a,n));
	printf("\nGirilen dizinin ortalamasi: %.4f",ortbul(a,n));
	printf("\nGirilen dizinin max terimi: %.4f",minmaxbul("max",a,n));
	printf("\nGirilen dizinin min terimi: %.4f",minmaxbul("min",a,n));
	printf("\nGirilen dizinin acikligi: %.4f",aciklik(a,n));
	printf("\nGirilen dizinin modu: %.4f",modbul(a,n));
	printf("\nGirilen dizinin medyani: %.4f",medyan(a,n));
	exit(0);
}

   Kelime bulmaca (word search) oyunu için anahtar kelimelerin içine gömülü olduðu rastgele tahta kombinasyonlarý üreten Ýngilizce program

#define GRID_SIZE 40
#define WORD_COUNT 20
const char words[WORD_COUNT][GRID_SIZE]={"SAITAMA","GENOS","SPEEDOSOUNDSONIC","FUBUKI","AWAKENEDGAROU","TATSUMAKI","ATOMICSANDBAG","BOROS","DEEPSEAKING","CHARANKO",
											"MUMENRIDER","BLAST","MOSQUITO","PIGGOD","PSYKOROCHI","MONACO","BONES","DRIVEKNIGHT","GOUKETSU","ZENKO"};
char grid[GRID_SIZE][GRID_SIZE];
short i,j;			//int (4 byte, min -2.147.483.648, max 2.147.483.647) yerine bu sefer short (2 byte, min -32.768, max 32.767) kullandým, çünkü neden olmasýn
typedef enum {
	Right, Left, Down, Up, DownRight, UpRight, DownLeft, UpLeft
} directions;

void printGrid() {
	printf("\n\n\t\t\t******** Word Search Generator ********\n\n\n");
	for(i=0;i<GRID_SIZE;i++) {
		printf("\n\t\t\t");
		for(j=0;j<GRID_SIZE;j++)
			printf("%c ",grid[i][j]);
	}
	printf("\n\n\t\t\tWords are: ");
	for(i=0;i<WORD_COUNT;i++)
		printf(i==WORD_COUNT-1 ? "%s" : "%s, ", words[i]);
}
void setEmptyGrid() {
	for(i=0;i<GRID_SIZE;i++)
		for(j=0;j<GRID_SIZE;j++)
			grid[i][j]='_';
}
void setRandomGrid() {
	for(i=0;i<GRID_SIZE;i++)
		for(j=0;j<GRID_SIZE;j++)
			if(grid[i][j]=='_')
				grid[i][j] = 'A' + rand()%26;
}
int main() {
	srand((unsigned int)time(NULL));
	setEmptyGrid();
	for(i=0;i<WORD_COUNT;i++) {			//words adlý string array'indeki bütün kelimeleri tahtaya (grid) yerleþtir
		short word_length=strlen(words[i]);
		bool word_is_placed=false;
		do {
			short direction=rand()%8, x_step, y_step;
			switch(direction) {
				case Right:
					x_step=1;
					y_step=0;
					break;
				case Left:
					x_step=-1;
					y_step=0;
					break;
				case Down:
					x_step=0;
					y_step=1;
					break;
				case Up:
					x_step=0;
					y_step=-1;
					break;
				case DownRight:
					x_step=1;
					y_step=1;
					break;
				case UpRight:
					x_step=1;
					y_step=-1;
					break;
				case DownLeft:
					x_step=-1;
					y_step=1;
					break;
				case UpLeft:
					x_step=-1;
					y_step=-1;
			}
			short x_position=rand()%GRID_SIZE, y_position=rand()%GRID_SIZE;
			short x_ending = x_position + word_length*x_step, y_ending = y_position + word_length*y_step;
			if(x_ending<0 || x_ending>=GRID_SIZE || y_ending<0 || y_ending>=GRID_SIZE)
				continue;				//kelimenin tahtaya sýðdýðýndan emin olmak için, yoksa sýfýrdan kelime yerleþtirecek bölge aramam lazým
			bool failed_to_place=false;
			for(j=0;j<word_length;j++) {
				short x_new_position = x_position + j*x_step, y_new_position = y_position + j*y_step;
				if(grid[x_new_position][y_new_position]!='_') {
					if(grid[x_new_position][y_new_position]==words[i][j])
						continue;		//eðer harf yerleþtireceðim yer önceden yerleþtirdiðim bir kelimenin harfi ile aynýysa np, deðilse sýkýntý
					else {
						failed_to_place=true;	//bu yere harf yerleþtiremem, sýfýrdan kelime yerleþtirecek bölge aramam lazým
						break;
					}
				}
			}
			if(failed_to_place)
				continue;
			else {
				for(j=0;j<word_length;j++) {
					short x_new_position = x_position + j*x_step, y_new_position = y_position + j*y_step;
					grid[x_new_position][y_new_position] = words[i][j];
				}
				word_is_placed=true;	//kelime yerleþtirildi
			}
		} while(!word_is_placed);
	}
	setRandomGrid();		//bu satýrý yoruma alarak programýn doðru çalýþýp çalýþmadýðýný ve kelimelerin nereye yerleþtirildiðini görebilirim ;)
	printGrid();
	exit(0);
}

   Paragraf paragraf bir metin belgesi olarak girilen dokümanýn istenilen paragraf/cümle/kelimesini yazdýran, 4 boyutlu char array'lerinden faydalanan Ýngilizce program

//Bir kelime char* ile ifade edilir.
//Bir cümle char** ile ifade edilir. Cümledeki kelimeler bir boþluk (" ") ile ayrýlýr. Son cümle boþluk (" ") ile bitmez.
//Bir paragraf char*** ile ifade edilir. Paragraftaki cümleler bir nokta (".") ile ayrýlýr.
//Bir doküman char**** ile ifade edilir. Dokümandaki paragraflar bir satýr sonu ("\n") ile ayrýlýr. Son paragraf satýr sonu ("\n") ile bitmez.
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {	//n. paragrafýn m. cümlesinin k. kelimesini döndürür
	return document[n-1][m-1][k-1];
}
char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {						//m. paragrafýn k. cümlesini döndürür
	return document[m-1][k-1];
}
char*** kth_paragraph(char**** document, int k) {											//k. paragrafý döndürür
	return document[k-1];
}
char** split_string(char* text, char delim) {		//text string'ini delim'lerin olduðu yerden substring'lere ayýrýr ve bu substring'leri döndürür
	assert(text!=NULL);		//assert fonksiyonu içindeki condition true ise bir þey yapmaz, false ise programý sonlandýrýr (panic!(), try...catch gibi)
	char** result = malloc(1*sizeof(char*));
	char* temp = strtok(text,&delim);
	*result = temp;
	int size;
	for(size=2;temp!=NULL;size++) {
		result = realloc(result,size*sizeof(char*));
		temp = strtok(NULL,&delim);
		result[size-1] = temp;
	}
	return result;
}
char**** get_document(char* text) {		//char**** ile ifade edilen dokümaný döndürür
	assert(text!=NULL);					//dokümaný newline'lar ('\n') ile ayýr ve paragraf sayýsýný bul
	char** paragraphs = split_string(text,'\n');
	int npar,i;
	for(npar=0;paragraphs[npar]!=NULL;npar++);
	char**** doc = malloc((npar+1)*sizeof(char***));
	doc[npar]=NULL;						//dizinin son elemanýný NULL yaparak dizinin sonunu belirt
	for(i=0;paragraphs[i]!=NULL;i++) {	//paragraflarý noktalar ('.') ile ayýr ve cümle sayýsýný bul
		char** sentences = split_string(paragraphs[i],'.');
		int nsen,j;
		for(nsen=0;sentences[nsen]!=NULL;nsen++);
		doc[i] = malloc((nsen+1)*sizeof(char**));
		doc[i][nsen] = NULL;			//dizinin son elemanýný NULL yaparak dizinin sonunu belirt
		for(j=0;sentences[j]!=NULL;j++)	//cümleleri boþluklar (' ') ile ayýr
			doc[i][j] = split_string(sentences[j],' ');
	}
	return doc;
}
char* get_input_text() {	//metindeki paragraflarý sýrayla alýr ve hepsini newline'lar ile paragraflarýn ayrýldýðý tek bir string'e aktarýp bu string'i döndürür
	printf("Enter number of paragraphs: ");
	int paragraph_count,i;
	scanf("%d",&paragraph_count);
	char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
	memset(doc,0,sizeof(doc));
	getchar();
	for(i=0;i<paragraph_count-1;i++) {
		printf("\nEnter the %d. paragraph:\n\n\t",i+1);
		gets(p[i]);
		strcat(doc,p[i]);
		strcat(doc,"\n");
	}
	printf("\nEnter the %d. paragraph:\n\n\t",i+1);
	gets(p[i]);
	strcat(doc,p[i]);
	char* returnDoc = (char*) malloc((strlen(doc)+1)*sizeof(char));
	strcpy(returnDoc,doc);		//boþ karakterleri dokümandan atmak için
	return returnDoc;
}
void print_sentence(char** sentence) {
	printf("Enter number of words: ");
	int word_count,i;
	scanf("%d",&word_count);
	for(i=0;i<word_count-1;i++)
		printf("%s ",sentence[i]);
	printf("%s",sentence[i]);
}
void print_paragraph(char*** paragraph) {
	printf("Enter number of sentences: ");
	int sentence_count,i;
	scanf("%d",&sentence_count);
	for(i=0;i<sentence_count-1;i++) {
		print_sentence(*(paragraph+i));
		printf(".\n");
	}
	print_sentence(*(paragraph+i));
	printf(".");
}
int main() {
	char* text = get_input_text();
	char**** document = get_document(text);
	printf("\nEnter number of queries: ");
	int q;
	scanf("%d",&q);
	while(q--) {
		printf("Enter query number: ");
		int type;
		scanf("%d",&type);
		switch(type) {
			case 1: {		//redeclaration hatalarý yüzünden scope kullandým
				printf("Enter paragraph no: ");
				int k;
				scanf("%d",&k);
				char*** paragraph = kth_paragraph(document,k);
				print_paragraph(paragraph);
				break;
			}
			case 2: {
				printf("Enter paragraph and sentence no: ");
				int k,m;
				scanf("%d %d",&k,&m);
				char** sentence = kth_sentence_in_mth_paragraph(document,k,m);
				print_sentence(sentence);
				break;
			}
			case 3: {
				printf("Enter paragraph, sentence, and word no: ");
				int k,m,n;
				scanf("%d %d %d",&k,&m,&n);
				char* word = kth_word_in_mth_sentence_of_nth_paragraph(document,k,m,n);
				printf("%s",word);
				break;
			}
			default:
				printf("Invalid query number. Please try again.");
		}
		printf("\n\n");
	}
	exit(0);
}

   Paragraf paragraf bir metin belgesi olarak girilen dokümanýn istenilen paragraf/cümle/kelimesini yazdýran, nested structure'lardan faydalanan alternatif Ýngilizce program */

#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
typedef struct {
	char* data;
} word;

typedef struct {
	word* data;
	unsigned int word_count;
} sentence;

typedef struct {
	sentence* data;
	unsigned int sentence_count;
} paragraph;

typedef struct {
	paragraph* data;
	unsigned int paragraph_count;
} document;

void add_char(word* _word, char character) {
	static unsigned int size;
	if(_word->data == NULL) {
		_word->data = (char*)malloc(0);
		size = 1;
	}
	_word->data = (char*)realloc(_word->data, (++size) * sizeof(char));
	_word->data[size-2] = character;
	_word->data[size-1] = '\0';
}
void add_word(sentence* _sentence, word* _word) {
	if(_sentence->data == NULL) {
		_sentence->data = (word*)malloc(0);
		_sentence->word_count = 0;
	}
	_sentence->data = (word*)realloc(_sentence->data, (++_sentence->word_count) * sizeof(word));
	_sentence->data[_sentence->word_count - 1] = *_word;
	_word->data = NULL;
}
void add_sentence(paragraph* _paragraph, sentence* _sentence) {
	if(_paragraph->data == NULL) {
		_paragraph->data = (sentence*)malloc(0);
		_paragraph->sentence_count = 0;
	}
	_paragraph->data = (sentence*)realloc(_paragraph->data, (++_paragraph->sentence_count) * sizeof(sentence));
	_paragraph->data[_paragraph->sentence_count - 1] = *_sentence;
	_sentence->data = NULL;
}
void add_paragraph(document* _document, paragraph* _paragraph) {
	if(_document->data == NULL) {
		_document->data = (paragraph*)malloc(0);
		_document->paragraph_count = 0;
	}
	_document->data = (paragraph*)realloc(_document->data, (++_document->paragraph_count) * sizeof(paragraph));
	_document->data[_document->paragraph_count - 1] = *_paragraph;
	_paragraph->data = NULL;
}
word get_kth_word_in_mth_sentence_of_nth_paragraph(document Doc, unsigned int k, unsigned int m, unsigned int n) {
	return Doc.data[n-1].data[m-1].data[k-1];
}
sentence get_kth_sentence_in_mth_paragraph(document Doc, unsigned int k, unsigned int m) {
	return Doc.data[m-1].data[k-1];
}
paragraph get_kth_paragraph(document Doc, unsigned int k) {
	return Doc.data[k-1];
}
document get_document(char* text) {
	document _document;
	paragraph _paragraph;
	sentence _sentence;
	word _word;
	_document.data = NULL;
	_paragraph.data = NULL;
	_sentence.data = NULL;
	_word.data = NULL;
	unsigned int i;
	for(i=0;i<=strlen(text);i++)
		switch(text[i]) {
			case ' ':
				add_word(&_sentence, &_word);
				break;
			case '.':
				add_word(&_sentence, &_word);
				add_sentence(&_paragraph, &_sentence);
				break;
			case '\n':
			case '\0':
				add_paragraph(&_document, &_paragraph);
				break;
			default:
				add_char(&_word, text[i]);
		}
	return _document;
}
char* get_input_text() {
	printf("Enter number of paragraphs: ");
	unsigned int paragraph_count,i;
	scanf("%u",&paragraph_count);
	char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
	memset(doc,0,sizeof(doc));
	getchar();
	for(i=0;i<paragraph_count-1;i++) {
		printf("\nEnter the %u. paragraph:\n\n\t",i+1);
		gets(p[i]);
		strcat(doc,p[i]);
		strcat(doc,"\n");
	}
	printf("\nEnter the %u. paragraph:\n\n\t",i+1);
	gets(p[i]);
	strcat(doc,p[i]);
	char* returnDoc = (char*) malloc((strlen(doc)+1)*sizeof(char));
	strcpy(returnDoc,doc);
	return returnDoc;
}
void print_sentence(sentence sen) {
	unsigned int i;
	for(i=0;i<sen.word_count-1;i++)
		printf("%s ",sen.data[i].data);
	printf("%s",sen.data[i].data);
}
void print_paragraph(paragraph para) {
	unsigned int i;
	for(i=0;i<para.sentence_count;i++) {
		print_sentence(para.data[i]);
		printf(".");
	}
}
void print_document(document doc) {
	unsigned int i;
	for(i=0;i<doc.paragraph_count-1;i++) {
		print_paragraph(doc.data[i]);
		printf("\n");
	}
	print_paragraph(doc.data[i]);
}
int main() {
	char* text = get_input_text();
	document Doc = get_document(text);
	printf("\nEnter number of queries: ");
	unsigned int q;
	scanf("%u",&q);
	while(q--) {
		printf("Enter query number: ");
		unsigned int type;
		scanf("%u",&type);
		switch(type) {
			case 1: {
				unsigned int k;
				printf("Enter paragraph no: ");
				scanf("%u",&k);
				paragraph para = get_kth_paragraph(Doc,k);
				print_paragraph(para);
				break;
			}
			case 2: {
				unsigned int k,m;
				printf("Enter paragraph and sentence no: ");
				scanf("%u %u",&k,&m);
				sentence sen = get_kth_sentence_in_mth_paragraph(Doc,k,m);
				print_sentence(sen);
				break;
			}
			case 3: {
				unsigned int k,m,n;
				printf("Enter paragraph, sentence, and word no: ");
				scanf("%u %u %u",&k,&m,&n);
				word w = get_kth_word_in_mth_sentence_of_nth_paragraph(Doc,k,m,n);
				printf("%s",w.data);
				break;
			}
			default:
				printf("Invalid query number. Please try again.");
		}
		printf("\n\n");
	}
	exit(0);
}
