#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

/* Klavyeden girilen unsigned long long aralýðýndaki tüm doðal sayýlarýn Türkçe okunuþlarýný yazdýrabilen program

#define MAX_LEN 160
void yazilisa_ekle(const unsigned short basamak, char* yazilis) {
	switch(basamak/100) {
		case 1:	strcat(yazilis, "yüz ");		break;
		case 2:	strcat(yazilis, "iki yüz ");	break;
		case 3:	strcat(yazilis, "üç yüz ");		break;
		case 4:	strcat(yazilis, "dört yüz ");	break;
		case 5:	strcat(yazilis, "beþ yüz ");	break;
		case 6:	strcat(yazilis, "altý yüz ");	break;
		case 7:	strcat(yazilis, "yedi yüz ");	break;
		case 8:	strcat(yazilis, "sekiz yüz ");	break;
		case 9:	strcat(yazilis, "dokuz yüz ");
	}
	switch((basamak/10)%10) {
		case 1:	strcat(yazilis, "on ");			break;
		case 2:	strcat(yazilis, "yirmi ");		break;
		case 3:	strcat(yazilis, "otuz ");		break;
		case 4:	strcat(yazilis, "kýrk ");		break;
		case 5:	strcat(yazilis, "elli ");		break;
		case 6:	strcat(yazilis, "altmýþ ");		break;
		case 7:	strcat(yazilis, "yetmiþ ");		break;
		case 8:	strcat(yazilis, "seksen ");		break;
		case 9:	strcat(yazilis, "doksan ");
	}
	switch(basamak%10) {
		case 1:	strcat(yazilis, "bir ");		return;		//break de yazýlabilir, fark etmez
		case 2:	strcat(yazilis, "iki ");		return;
		case 3:	strcat(yazilis, "üç ");			return;
		case 4:	strcat(yazilis, "dört ");		return;
		case 5:	strcat(yazilis, "beþ ");		return;
		case 6:	strcat(yazilis, "altý ");		return;
		case 7:	strcat(yazilis, "yedi ");		return;
		case 8:	strcat(yazilis, "sekiz ");		return;
		case 9:	strcat(yazilis, "dokuz ");
	}
}
void basamak_kontrol(const unsigned short basamak, char* yazilis, const char* kelime) {
	if(basamak) {
		if(basamak!=1 || strcmp(kelime, "bin "))	yazilisa_ekle(basamak, yazilis);
		strcat(yazilis, kelime);
	}
}
void sayiyi_yazdir(const unsigned long long sayi) {
	if(sayi==0) {
		printf("0: sýfýr\n");
		return;
	}
	char yazilis[MAX_LEN]="";
	const unsigned short kentilyonlar=(sayi/1000000000000000000)%1000, katrilyonlar=(sayi/1000000000000000)%1000,
	trilyonlar=(sayi/1000000000000)%1000, milyarlar=(sayi/1000000000)%1000, milyonlar=(sayi/1000000)%1000, binler=(sayi/1000)%1000, birler=sayi%1000;
	basamak_kontrol(kentilyonlar, yazilis, "kentilyon ");
	basamak_kontrol(katrilyonlar, yazilis, "katrilyon ");
	basamak_kontrol(trilyonlar, yazilis, "trilyon ");
	basamak_kontrol(milyarlar, yazilis, "milyar ");
	basamak_kontrol(milyonlar, yazilis, "milyon ");
	basamak_kontrol(binler, yazilis, "bin ");
	yazilisa_ekle(birler, yazilis);
	__mingw_printf("%llu: %s\n", sayi, yazilis);		//"%llu" belirtecini kullanabilmem için MinGW uzantýsýný printf/scanf'in baþýna eklemem þart
}
int main() {
	setlocale(LC_ALL, "Turkish");
	unsigned long long sayi;
	for(sayi=0;sayi<=1000;sayi++)
		sayiyi_yazdir(sayi);
	printf("\nRastgele bir sayý giriniz: ");
	__mingw_scanf("%llu", &sayi);
	sayiyi_yazdir(sayi);
	return 0;
}

   Klavyeden köþe sayýsý ve koordinatlarý girilen bir çokgenin belli eksenlerce kaðýt gibi dikey olarak katlandýktan sonraki alanlarýný yazdýran program

#define UNINDEXED UINT_MAX						//index'ler "signed int" olsaydý UNINDEXED = -1 de olabilirdi
#define min(x, y) (((x) < (y)) ? (x) : (y))		//<windows.h>'ta min fonksiyonu var da komple o kütüphaneyi import etmeye deðmez
typedef struct {								//benzer þekilde <math.h>'teki fabs fonksiyonuna karþýlýk "#define abs(x) (((x) > 0) ? (x) : -(x))" yazýlabilir
	unsigned int h;
	double x, a, b;
} V;
void swap(double *const a, double *const b) {	double tmp = *a; *a = *b, *b = tmp;	}
double hit(const double x1, const double y1, const double x2, const double y2, const double y) {	return x1 + (x2-x1)*(y-y1)/(y2-y1);	}
void add(unsigned int *const m, V *vv, const double y1, const double y2,
const double xl1, const double xr1, const double xl2, const double xr2, const double c) {
	vv = (V*) realloc(vv, (*m+4) * sizeof(V));
	vv[(*m)++] = (V){UNINDEXED, xl1, 0, -y1*c};
	vv[(*m)++] = (V){UNINDEXED, xr1, 0, y1*c};
	vv[(*m)++] = (V){UNINDEXED, xl2, 0, y2*c};
	vv[(*m)++] = (V){UNINDEXED, xr2, 0, -y2*c};
	if(xl1!=xl2) {
		vv = (V*) realloc(vv, (*m+2) * sizeof(V));
		const double a = (y2-y1)/(xl2-xl1), b = y1 - xl1*a;
		vv[(*m)++] = (V){UNINDEXED, xl1, a*c, b*c};
		vv[(*m)++] = (V){UNINDEXED, xl2, -a*c, -b*c};
	}
	if(xr1!=xr2) {
		vv = (V*) realloc(vv, (*m+2) * sizeof(V));
		const double a = (y2-y1)/(xr2-xr1), b = y1 - xr1*a;
		vv[(*m)++] = (V){UNINDEXED, xr1, -a*c, -b*c};
		vv[(*m)++] = (V){UNINDEXED, xr2, a*c, b*c};
	}
}
int compare(const void *a, const void *b) {				//"const int *ptr" = "int const *ptr" => pointer to constant integer, "int *const ptr" => constant pointer
	const V const *u = (V*)a, *v = (V*)b;				//dolayýsýyla 1. const "pointer to constant", 2. const "constant pointer" demek
	return u->x==v->x ? 0 : (u->x < v->x ? -1 : 1);		//ilkinde pointer'ýn gösterdiði deðer deðiþemez, ikincisinde pointer'ýn deðeri (tuttuðu adres, hangi elemaný gösterdiði) deðiþemez
}
int main() {
	setlocale(LC_ALL, "Turkish");
	unsigned int m=0, n, q, i, j, i_=0;		//declaration'lar
	printf("Þeklin köþe sayýsýný ve istek sayýsýný giriniz: ");
	scanf("%u%u",&n,&q);					//þeklin köþe sayýsý ve istek sayýsý deðerlerini oku
	V *vv = (V*) malloc(sizeof(V)); double xx[n], yy[n], ans[q], y, a=0, b=0, c=0;		//declaration'larýn devamý
	puts("Þeklin köþe koordinatlarýný giriniz (x,y):");
	for(i=0;i<n;i++)	scanf("%lf%lf", &xx[i], &yy[i]);								//þeklin köþe koordinatlarýný oku
	for(i=0;i<n-1;i++)	c += (long long)xx[i]*yy[i+1] - (long long)xx[i+1]*yy[i];		//Shoelace metodu ile girilen þeklin alanýný hesapla
	c += (long long)xx[i]*yy[0] - (long long)xx[0]*yy[i];
	c = fabs(c) / 2;									//c deðeri þuan çokgenin ilk alanýna eþit
	for(i=1;i<n;i++)	if(yy[i_]>yy[i])	i_ = i;
	for(i = j = i_, y = yy[i_]; i==i_ || i!=j;) {		//i_, i ve j en küçük y koordinatýnýn index'ine, y en küçük y koordinatýnýn deðerine eþit
		const unsigned int i1 = i==0 ? n-1 : i-1, j1 = j+1==n ? 0 : j+1;		//i'yi 1 azalt, j'yi 1 arttýr
		double y_ = min(yy[i1], yy[j1]), xl = hit(xx[i], yy[i], xx[i1], yy[i1], y), xr = hit(xx[j], yy[j], xx[j1], yy[j1], y),
		xl_ = hit(xx[i], yy[i], xx[i1], yy[i1], y_), xr_ = hit(xx[j], yy[j], xx[j1], yy[j1], y_);
		if(xl>xr)		swap(&xl, &xr);
		if(xl_>xr_)		swap(&xl_, &xr_);
		add(&m, vv, y, y_, xl, xr, xl_, xr_, -1);
		add(&m, vv, y, y_, (xl+xr)/2, xr, (xl_+xr_)/2, xr_, 2);
		y = y_;
		if(yy[i1]==y_)	i = i1;
		if(yy[j1]==y_)	j = j1;
	}
	printf("Katlama eksenlerinin x deðerlerini giriniz: ");
	vv = (V*) realloc(vv, (m+q) * sizeof(V));
	for(i=0;i<q;i++) {
		scanf("%lf", &vv[m].x);				//istekleri yani katlama eksenlerinin x deðerlerini oku
		vv[m++].h = i;
	}
	qsort(vv, m, sizeof *vv, compare);		//x deðerlerine göre küçükten büyüðe sýrala
	for(i=0;i<m-1;i++) {
		vv[i].h==UNINDEXED ? (a += vv[i].a, b += vv[i].b) : (ans[vv[i].h] = c);
		c += (a / 2 * vv[i+1].x * vv[i+1].x + b * vv[i+1].x) - (a / 2 * vv[i].x * vv[i].x + b * vv[i].x);
	}
	if(vv[i].h!=UNINDEXED)	ans[vv[i].h] = c;
	for(i=0;i<q;i++)	printf("Þeklin %u. katlama ekseni boyunca katlandýktan sonraki alaný: %.10lf\n", i+1, ans[i]);
	free(vv);
	return 0;
}

   Klavyeden girilen satýr sayýsýna göre, sadece putchar fonksiyonu ve for döngülerinden faydalanarak ardýþýk
   ASCII deðerlerine sahip karakterlerden oluþan bir eþkenar dörtgen (harf baklavasý) çizdiren program

int main() {
	int i,j,n;	char ch;
	printf("Klavyeden baklavanin yari yuksekligini giriniz: ");		scanf("%d",&n);		printf("\n\n");
	for(i=0; i<n; putchar('\n'), i++) {
		for(j=0; j<n-i; putchar(' '), j++);
		for(j=0, ch=i+'a'; j<=i; putchar(ch++), j++);
		for(ch--; j>1; putchar(--ch), j--);
	}
	for(i-=2; i>=0; putchar('\n'), i--) {		//2. for'un içeriði yukarýdakinin birebir aynýsý
		for(j=0; j<n-i; putchar(' '), j++);		//for(0, 1, ..., n-2, n-1), for(n-2, n-1, ..., 1, 0)
		for(j=0, ch=i+'a'; j<=i; putchar(ch++), j++);
		for(ch--; j>1; putchar(--ch), j--);
	}
}

   Round robin turnuva programlama algoritmasý ile bir diziyi her seferinde farklý ikili kombinasyonlara ayýran program

#define TEAMS_LEN 10		//dizinin daima çift sayýda elemaný olacak
typedef struct {	int *data, size;	} List;
void AppendToList(List *to, const List *from, const int start, const int end) {
	int i;
	for(i=start;i<end;i++) {
		to->data[to->size++] = from->data[i];
		to->data = (int*) realloc(to->data, to->size * sizeof(int));
	}
}
int main() {
//	const List teams = (List){(int[]){1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10};
	List teams = (List){(int*) malloc(TEAMS_LEN * sizeof(int)), TEAMS_LEN};		//python kodu:
	int i;																			//teams = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
	for(i=0; i<teams.size; teams.data[i] = i+1, i++);								//n = int(len(teams) / 2)
	int stages[teams.size-1][teams.size/2][2], j;									//stages = []
	for(i=0;i<teams.size-1;i++) {													//for i in range(len(teams) - 1):
		List *t = (List[]){{(int*) malloc(0), 0}};									//    t = teams[:1] + teams[-i:] + teams[1:-i] if i else teams
		AppendToList(t, &teams, 0, 1);												//    stages.append(list(zip(t[:n], reversed(t[n:]))))
		AppendToList(t, &teams, teams.size - i, teams.size);						//print(stages)
		AppendToList(t, &teams, 1, teams.size - i);
		for(j=0;j<teams.size/2;j++)		stages[i][j][0] = t->data[j], stages[i][j][1] = t->data[teams.size - j - 1];
		free(t->data);
	}
	for(i=0;i<teams.size-1;i++) {
		printf("[");
		for(j=0;j<teams.size/2;j++)		printf("(%d, %d), ", stages[i][j][0], stages[i][j][1]);
		printf("\b\b]");
		if(i!=teams.size-2)		puts(",");
	}
	return 0;
}

   Rakam bulunan herhangi bir kareden baþlayarak; yatay, dikey ya da diyagonal bir biçimde, geri dönmemek koþuluyla
   komþu karelere uðrayýp aritmetiksel bir eþitlik elde etmeye dayanan bulmacayý backtracking ile çözen program */

char peek(char **expressionToParse) {	return **expressionToParse;	}
char get(char **expressionToParse) {	return *(*expressionToParse)++;	}
double parseExpression(char **expressionToParse);
double parseNumber(char **expressionToParse) {
	double result = get(expressionToParse) - '0';
	while(peek(expressionToParse)>='0' && peek(expressionToParse)<='9')
		result = 10*result + get(expressionToParse) - '0';
	return result;
}
double parseFactor(char **expressionToParse) {
	if(peek(expressionToParse)>='0' && peek(expressionToParse)<='9')	return parseNumber(expressionToParse);
	else if(peek(expressionToParse)=='(') {
		get(expressionToParse);		//'('
		double result = parseExpression(expressionToParse);
		get(expressionToParse);		//')'
		return result;
	}
	else if(peek(expressionToParse)=='-') {
		get(expressionToParse);
		return -parseFactor(expressionToParse);
	}
	return 0;		//error
}
double parseTerm(char **expressionToParse) {
	double result = parseFactor(expressionToParse);
	while(peek(expressionToParse)=='*' || peek(expressionToParse)=='/')
		get(expressionToParse)=='*' ? (result *= parseFactor(expressionToParse)) : (result /= parseFactor(expressionToParse));
	return result;
}
double parseExpression(char **expressionToParse) {
	double result = parseTerm(expressionToParse);
	while(peek(expressionToParse)=='+' || peek(expressionToParse)=='-')
		get(expressionToParse)=='+' ? (result += parseTerm(expressionToParse)) : (result -= parseTerm(expressionToParse));
	return result;
}
bool isOperator(const char ch) {
	static char operators[5] = {'+','-','*','/','='};
	unsigned short i;
	for(i=0;i<5;i++)	if(ch==operators[i])	return true;
	return false;
}
bool expressionIsValid(char const *expression) {
	if(isOperator(*expression))					return false;
	for(expression++;expression+1;expression++)
		if((*(expression+1)<'0' || *(expression+1)>'9') && *(expression+1)!='(') {		//rakam ve '(' deðilse
			if(isOperator(*expression))			return false;
			else if(*expression=='(')			return false;
		}
	return !isOperator(*expression);
}


unsigned int findFirstOccurence(const char *str, char charToFind) {
	unsigned int i;
	for(i=0;str[i];i++)		if(str[i]==charToFind)	return i;
	return i;
}
char* getSubstring(char* str, const unsigned int beginPos, const unsigned int endPos) {
	char* subStr = (char*)malloc(endPos-beginPos+1);
	memcpy(subStr, &str[beginPos], endPos-beginPos);
	subStr[endPos-beginPos] = '\0';
	return subStr;
}


void printPuzzle(const unsigned short width, const unsigned short height, char puzzle[width][height]) {
	unsigned short x, y;
	for(y=0;y<height;y++) {
		for(x=0;x<width;x++)	putchar(puzzle[y][x] ? puzzle[y][x] : 178);
		puts("");
	}
	puts("");
}
bool checkBoard(const unsigned short width, const unsigned short height, char puzzle[width][height]) {
	unsigned short x, y, counter=0;
	for(x=0;x<width;x++)
		for(y=0;y<height;y++)
			if(puzzle[y][x] && (puzzle[y][x]<'a' || puzzle[y][x]>'z'))	counter++;
	return counter==1;
}
bool solvePuzzleUtil(const unsigned short *width, const unsigned short *height, char puzzle[*width][*height], short *x, short *y, char *expressionToParse, unsigned short *pos) {
	static char ch='a';
	if(checkBoard(*width, *height, puzzle) && puzzle[*y][*x] && (puzzle[*y][*x]<'a' || puzzle[*y][*x]>'z')) {
		expressionToParse[*pos] = puzzle[*y][*x];
		unsigned int equation_split = findFirstOccurence(expressionToParse, '=');
		if(expressionToParse[equation_split] && expressionToParse[equation_split+1]) {
			char *expr1 = getSubstring(expressionToParse, 0, equation_split),
			*expr2 = getSubstring(expressionToParse, equation_split+1, strlen(expressionToParse));
			if(!(isOperator(expr1[strlen(expr1)-1]) || isOperator(expr2[strlen(expr2)-1])))
				if(parseExpression(&expr1) == parseExpression(&expr2)) {
					puzzle[*y][*x] = ch;
					printf("Solution: %s\n", expressionToParse);
					printPuzzle(*width, *height, puzzle);
					ch = 'a';
					puzzle[*y][*x] = expressionToParse[*pos];
					return true;
				}
		}
	}
	else if(*x>=0 && *x<(short)*width && *y>=0 && *y<(short)*height && puzzle[*y][*x] && (puzzle[*y][*x]<'a' || puzzle[*y][*x]>'z')) {
		if(isOperator(expressionToParse[*pos-1]) && isOperator(puzzle[*y][*x]))		return false;
		expressionToParse[(*pos)++] = puzzle[*y][*x], puzzle[(*y)--][*x] = ch++;
		if(solvePuzzleUtil(width, height, puzzle, x, y, expressionToParse, pos)) {
			puzzle[++(*y)][*x] = expressionToParse[*pos], expressionToParse[(*pos)--] = '\0';
			return true;
		}
		(*y)+=2;
		if(solvePuzzleUtil(width, height, puzzle, x, y, expressionToParse, pos)) {
			puzzle[--(*y)][*x] = expressionToParse[*pos], expressionToParse[(*pos)--] = '\0';
			return true;
		}
		(*x)--, (*y)--;
		if(solvePuzzleUtil(width, height, puzzle, x, y, expressionToParse, pos)) {
			puzzle[*y][++(*x)] = expressionToParse[*pos], expressionToParse[(*pos)--] = '\0';
			return true;
		}
		(*x)+=2;
		if(solvePuzzleUtil(width, height, puzzle, x, y, expressionToParse, pos)) {
			puzzle[*y][--(*x)] = expressionToParse[*pos], expressionToParse[(*pos)--] = '\0';
			return true;
		}
		(*x)-=2, (*y)--;
		if(solvePuzzleUtil(width, height, puzzle, x, y, expressionToParse, pos)) {
			puzzle[++(*y)][++(*x)] = expressionToParse[*pos], expressionToParse[(*pos)--] = '\0';
			return true;
		}
		(*y)+=2;
		if(solvePuzzleUtil(width, height, puzzle, x, y, expressionToParse, pos)) {
			puzzle[--(*y)][++(*x)] = expressionToParse[*pos], expressionToParse[(*pos)--] = '\0';
			return true;
		}
		(*x)+=2;
		if(solvePuzzleUtil(width, height, puzzle, x, y, expressionToParse, pos)) {
			puzzle[--(*y)][--(*x)] = expressionToParse[*pos], expressionToParse[(*pos)--] = '\0';
			return true;
		}
		(*y)-=2;
		if(solvePuzzleUtil(width, height, puzzle, x, y, expressionToParse, pos)) {
			puzzle[++(*y)][--(*x)] = expressionToParse[*pos], expressionToParse[(*pos)--] = '\0';
			return true;
		}
		puzzle[++(*y)][--(*x)] = expressionToParse[--(*pos)], expressionToParse[*pos] = '\0', ch--;
		return false;
	}
	return false;
}
void solvePuzzle(const unsigned short width, const unsigned short height, char puzzle[width][height]) {
	short x, y;	unsigned short pos=0;	char *expressionToParse = (char*)malloc(width*height+1);
	for(x=0;x<width;x++)
		for(y=0;y<height;y++)
			if(puzzle[y][x]>='0' && puzzle[y][x]<='9')		solvePuzzleUtil(&width, &height, puzzle, &x, &y, expressionToParse, &pos);
	puts("\n");
	free(expressionToParse);
}

int main() {
	char puzzle1[5][5]={{'\0', '*', '6', '=', '3'},
						{'5', '5', '\0', '+', '4'},
						{'\0', '2', '-', '\0', '6'},
						{'/', '2', '\0', '3', '\0'},
						{'\0', '6', '\0', '\0', '\0'}},
		 puzzle2[5][5]={{'5', '-', '\0', '8', '*'},
						{'\0', '5', '=', '1', '6'},
						{'4', '\0', '5', '/', '1'},
						{'\0', '+', '4', '\0', '\0'},
						{'\0', '\0', '\0', '\0', '\0'}};
	printPuzzle(5, 5, puzzle1);
	solvePuzzle(5, 5, puzzle1);
	printPuzzle(5, 5, puzzle2);
	solvePuzzle(5, 5, puzzle2);
	return 0;
}
