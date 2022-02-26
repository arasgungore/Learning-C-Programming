#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* Merkez/k��e koordinatlar� 0 ila 10 aras�nda de�i�en bir �ember, bir dikd�rtgen ve bir ��geni komple i�ine alan en k���k daire ve dikd�rtgenin alan�n� ve bu �ekillerin 3'�n�n de birbirleriyle kesi�ip
   kesi�medi�ini kontrol edip hepsi birbiriyle kesi�ene kadar bu �ekilleri randomize ederek sonu�taki �ekillerin �zelliklerini yazd�ran linked list'lere dayal� �ngilizce program

#define min(a,b) a<b ? a : b
#define NO_OF_POINTS 1500		//LinkedListlerin boyutu

typedef struct {
	double x, y, r;											//�emberin merkezinin koordinatlar� ve yar��ap�
} Circle;

typedef struct {
	double xBottomLeft, yBottomLeft, xTopRight, yTopRight;	//dikd�rtgenin sol alt ve sa� �st k��elerinin koordinatlar�
} Rectangle;

typedef struct {
	double x1, y1, x2, y2, x3, y3;							//��genin k��elerinin koordinatlar�
} Triangle;

typedef struct Point {
	double x, y;
	struct Point *Pnext;		//noktalar/koordinatlar i�in bir LinkedList
} Point;

Circle RandomCircle() {			//merkez koordinatlar� ile merkezi 0 ila 10 aras�nda olan bir �ember d�nd�r�r
	Circle c;
	c.x = (double)rand()/RAND_MAX*10.0;
	c.y = (double)rand()/RAND_MAX*10.0;
	c.r = (double)rand()/RAND_MAX*10.0;
	return c;
}

Rectangle RandomRectangle() {	//sol alt k��e koordinatlar� 0 ila 10 aras�nda, sa� �st k��e koordinatlar� da sol alt k��eninki ila 10 aras�nda olan bir dikd�rtgen d�nd�r�r
	Rectangle r;
	r.xBottomLeft = (double)rand()/RAND_MAX*10.0;
	r.yBottomLeft = (double)rand()/RAND_MAX*10.0;
	r.xTopRight = (double)rand()/RAND_MAX*(10.0 - r.xBottomLeft) + r.xBottomLeft;
	r.yTopRight = (double)rand()/RAND_MAX*(10.0 - r.yBottomLeft) + r.yBottomLeft;
	return r;
}

Triangle RandomTriangle() {		//k��e koordinatlar� 0 ila 10 aras�nda olan bir ��gen d�nd�r�r
	Triangle t;
	t.x1 = (double)rand()/RAND_MAX*10.0;
	t.y1 = (double)rand()/RAND_MAX*10.0;
	t.x2 = (double)rand()/RAND_MAX*10.0;
	t.y2 = (double)rand()/RAND_MAX*10.0;
	t.x3 = (double)rand()/RAND_MAX*10.0;
	t.y3 = (double)rand()/RAND_MAX*10.0;
	return t;
}

void PushPointOnCircle(Point* head, Circle c, unsigned int times) {			//times b�y�kl���nde �ember �zerindeki noktalar� bar�nd�ran bir LinkedList olu�turur
	head->x = c.x + cos((double)rand() / RAND_MAX * 2 * M_PI) * c.r;		//x = Mx + r*cos(teta)
	head->y = c.y + sin((double)rand() / RAND_MAX * 2 * M_PI) * c.r;		//y = My + r*sin(teta)
	if(times>1)
		head->Pnext = (Point*)malloc(sizeof(Point));
	else {
		head->Pnext = NULL;
		return;
	}
	PushPointOnCircle(head->Pnext, c, times-1);
}

void PushPointOnRectangle(Point* head, Rectangle r, unsigned int times) {	//4*times b�y�kl���nde dikd�rtgen �zerindeki noktalar� bar�nd�ran bir LinkedList olu�turur
	head->x = (double)rand() / RAND_MAX * (r.xTopRight - r.xBottomLeft) + r.xBottomLeft;						//alt kenarda bir nokta
	head->y = r.yBottomLeft;
	head->Pnext = (Point*)malloc(sizeof(Point));
	head->Pnext->x = (double)rand() / RAND_MAX * (r.xTopRight - r.xBottomLeft) + r.xBottomLeft;					//�st kenarda bir nokta
	head->Pnext->y = r.yTopRight;
	head->Pnext->Pnext = (Point*)malloc(sizeof(Point));
	head->Pnext->Pnext->x = r.xBottomLeft;
	head->Pnext->Pnext->y = (double)rand() / RAND_MAX * (r.yTopRight - r.yBottomLeft) + r.yBottomLeft;			//sol kenarda bir nokta
	head->Pnext->Pnext->Pnext = (Point*)malloc(sizeof(Point));
	head->Pnext->Pnext->Pnext->x = r.xTopRight;
	head->Pnext->Pnext->Pnext->y = (double)rand() / RAND_MAX * (r.yTopRight - r.yBottomLeft) + r.yBottomLeft;	//sa� kenarda bir nokta
	if(times>1)
		head->Pnext->Pnext->Pnext->Pnext = (Point*)malloc(sizeof(Point));
	else {
		head->Pnext->Pnext->Pnext->Pnext = NULL;
		return;
	}
	PushPointOnRectangle(head->Pnext->Pnext->Pnext->Pnext, r, times-1);
}

void PushPointOnTriangle(Point* head, Triangle t, unsigned int times) {		//3*times b�y�kl���nde ��gen �zerindeki noktalar� bar�nd�ran bir LinkedList olu�turur
	head->x = (double)rand() / RAND_MAX * fabs(t.x1 - t.x2) + min(t.x1,t.x2);					//1. kenar
	head->y = (double)rand() / RAND_MAX * fabs(t.y1 - t.y2) + min(t.y1,t.y2);
	head->Pnext = (Point*)malloc(sizeof(Point));
	head->Pnext->x = (double)rand() / RAND_MAX * fabs(t.x2 - t.x3) + min(t.x2,t.x3);			//2. kenar
	head->Pnext->y = (double)rand() / RAND_MAX * fabs(t.y2 - t.y3) + min(t.y2,t.y3);
	head->Pnext->Pnext = (Point*)malloc(sizeof(Point));
	head->Pnext->Pnext->x = (double)rand() / RAND_MAX * fabs(t.x1 - t.x3) + min(t.x1,t.x3);		//3. kenar
	head->Pnext->Pnext->y = (double)rand() / RAND_MAX * fabs(t.y1 - t.y3) + min(t.y1,t.y3);
	if(times>1)
		head->Pnext->Pnext->Pnext = (Point*)malloc(sizeof(Point));
	else {
		head->Pnext->Pnext->Pnext = NULL;
		return;
	}
	PushPointOnTriangle(head->Pnext->Pnext->Pnext, t, times-1);
}

double PointDistanceSquared(Point* p1, Point* p2) {				//iki nokta aras�ndaki uzakl��� d�nd�r�r
	return (p2->x - p1->x)*(p2->x - p1->x) + (p2->y - p1->y)*(p2->y - p1->y);
}

void FurthestPointPairUtil(Point* p1, Point* p2, Point* res, double* maxDist) {			//iki LinkedList aras�ndan birbirlerinden en uzakta bulunan nokta �iftini bulur
	Point *c1=p1, *c2=p2;
	for(c1=p1;c1!=NULL;c1=c1->Pnext)
		for(c2=p2;c2!=NULL;c2=c2->Pnext) {
			double dist = PointDistanceSquared(c1,c2);
			if(*maxDist<dist) {
				*maxDist = dist;
				res->x = c1->x, res->y = c1->y;
				res->Pnext->x = c2->x, res->Pnext->y = c2->y;
			}
		}
	free(c1);
	free(c2);
}

Point* FurthestPointPair(Point* pc, Point* pr, Point* pt) {		//aralar�ndaki mesafe maksimum olan nokta �iftini bar�nd�ran bir LinkedList d�nd�r�r
	double maxDist=0;
	Point *res = NULL;
	res = (Point*)malloc(sizeof(Point));
	res->Pnext = (Point*)malloc(sizeof(Point));
	res->Pnext->Pnext = NULL;
	FurthestPointPairUtil(pc, pr, res, &maxDist);
	FurthestPointPairUtil(pc, pt, res, &maxDist);
	FurthestPointPairUtil(pr, pt, res, &maxDist);
	return res;
}

double AreaOfSmallestCircleContainingAllShapes(Point* pc, Point* pr, Point* pt) {		//b�t�n noktalar� i�inde bar�nd�ran �emberin alan�n� d�nd�r�r
	Point *p = FurthestPointPair(pc,pr,pt);
	return M_PI * PointDistanceSquared(p, p->Pnext) / 4.0;					//pi*r^2 = pi*(2r)^2/4
}

void MinMaxPointPairUtil(Point* p, Point* res) {
	Point *current = p;
	for(current=p;current!=NULL;current=current->Pnext) {
		if(res->x < current->x)				res->x = current->x;			//en sa�daki x
		else if(res->Pnext->x > current->x)	res->Pnext->x = current->x;		//en soldaki x
		if(res->y < current->y)				res->y = current->y;			//en �stteki y
		else if(res->Pnext->y > current->y)	res->Pnext->y = current->y;		//en alttaki y
	}
	free(current);
}

Point* MinMaxPointPair(Point* pc, Point* pr, Point* pt) {		//en sa�daki, en soldaki, en �stteki ve en alttaki koordinatlar� bar�nd�ran bir LinkedList d�nd�r�r
	Point *res = NULL;
	res = (Point*)malloc(sizeof(Point));
	res->Pnext = (Point*)malloc(sizeof(Point));
	res->Pnext->Pnext = NULL;
	res = pc;
	res->Pnext = pr;
	MinMaxPointPairUtil(pc, res);
	MinMaxPointPairUtil(pr, res);
	MinMaxPointPairUtil(pt, res);
	return res;						//{Xmax, Ymax, {Xmin, Ymin, NULL}}
}

double AreaOfSmallestRectangleContainingAllShapes(Point* pc, Point* pr, Point* pt) {	//b�t�n noktalar� i�inde bar�nd�ran dikd�rtgenin alan�n� d�nd�r�r
	Point *p = MinMaxPointPair(pc,pr,pt);
	return (p->x - p->Pnext->x) * (p->y - p->Pnext->y);
}

bool IsPointInCircle(Circle c, Point* p) {						//nokta �emberin i�indeyse true, de�ilse false d�nd�r�r
	Point cp = {c.x, c.y, NULL};
	return PointDistanceSquared(p, &cp) <= c.r*c.r;
}

bool IsPointInRectangle(Rectangle r, Point* p) {				//nokta dikd�rtgenin i�indeyse true, de�ilse false d�nd�r�r
	if(r.xBottomLeft <= p->x)
		if(r.yBottomLeft <= p->y)
			if(p->x <= r.xTopRight)
				if(p->y <= r.yTopRight)
					return true;
	return false;
}

double IsPointInTriangleUtil(Point* p1, Point p2, Point p3) {	//determinant metoduyla 3 noktan�n olu�turdu�u ��genin alan�n� d�nd�r�r, ama as�l �nemli olan d�nd�rd��� say�n�n i�areti
	return (p1->x - p3.x)*(p2.y - p3.y) - (p2.x - p3.x)*(p1->y - p3.y);
}

bool IsPointInTriangle(Triangle t, Point* p) {					//nokta ��genin i�indeyse true, de�ilse false d�nd�r�r
	Point v1 = {t.x1, t.y1, NULL}, v2 = {t.x2, t.y2, NULL}, v3 = {t.x3, t.y3, NULL};
	double d1 = IsPointInTriangleUtil(p, v1, v2), d2 = IsPointInTriangleUtil(p, v2, v3), d3 = IsPointInTriangleUtil(p, v3, v1);
	bool has_neg = (d1<0) || (d2<0) || (d3<0), has_pos = (d1>0) || (d2>0) || (d3>0);
	return !(has_neg && has_pos);
}

bool DoAllShapesIntersectWithEachOther(Circle c, Rectangle r, Triangle t, Point* pc, Point* pr, Point* pt) {	//e�er 3 �ekil de birbiriyle kesi�iyorsa true, kesi�miyorsa false d�nd�r�r
	Point *c1=pc, *c2=pr, *c3=pt;
	for(c1=pc;c1!=NULL;c1=c1->Pnext)
		if(IsPointInRectangle(r,c1) && IsPointInTriangle(t,c1)) {
			free(c1);
			free(c2);
			free(c3);
			return true;
		}
	for(c2=pr;c2!=NULL;c2=c2->Pnext)
		if(IsPointInCircle(c,c2) && IsPointInTriangle(t,c2)) {
			free(c1);
			free(c2);
			free(c3);
			return true;
		}
	for(c3=pt;c3!=NULL;c3=c3->Pnext)
		if(IsPointInCircle(c,c3) && IsPointInRectangle(r,c3)) {
			free(c1);
			free(c2);
			free(c3);
			return true;
		}
	free(c1);
	free(c2);
	free(c3);
	return false;
}

void PrintAllShapes(Circle c, Rectangle r, Triangle t) {		//mevcut �ekillerin �zelliklerini yazd�r�r
	printf("\t\tx\ty\tr\n");
	printf("Circle:\t\t%.4lf\t%.4lf\t%.4lf\n", c.x, c.y, c.r);
	printf("\n\n\t\tBLx\tBLy\tTRx\tTRy\n");
	printf("Rectangle:\t%.4lf\t%.4lf\t%.4lf\t%.4lf\n", r.xBottomLeft, r.yBottomLeft, r.xTopRight, r.yTopRight);
	printf("\n\n\t\tx1\ty1\tx2\ty2\tx3\ty3\n");
	printf("Triangle:\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\t%.4lf\n", t.x1, t.y1, t.x2, t.y2, t.x3, t.y3);
}

int main() {
	srand(time(NULL));
	Circle c = RandomCircle();
	Rectangle r = RandomRectangle();
	Triangle t = RandomTriangle();
	PrintAllShapes(c,r,t);
	Point pc, pr, pt;
	PushPointOnCircle(&pc, c, NO_OF_POINTS);
	PushPointOnRectangle(&pr, r, NO_OF_POINTS/4);
	PushPointOnTriangle(&pt, t, NO_OF_POINTS/3);
	printf("\n\n\nArea of Smallest Circle Containing All Shapes: %lf", AreaOfSmallestCircleContainingAllShapes(&pc,&pr,&pt));
	printf("\n\n\nArea of Smallest Rectangle Containing All Shapes: %lf", AreaOfSmallestRectangleContainingAllShapes(&pc,&pr,&pt));
	unsigned int counter;
	for(counter=0;!DoAllShapesIntersectWithEachOther(c,r,t,&pc,&pr,&pt);counter++) {
		c = RandomCircle();
		r = RandomRectangle();
		t = RandomTriangle();
	}
	printf("\n\n\n\n\nShapes That All Intersect With Each Other:\n\n");
	printf("Number of randomization tests: %u\n\n", counter);
	PrintAllShapes(c,r,t);
	return 0;
}

   Enigma makinesi olarak �al���p klavyeden girilen metinleri �ifreleyen/de�ifre eden �ngilizce program */

#define MSG_LEN 2049
#define DIV_LEN 5
#define LAST_CHAR 'F'
#define CHECK_ROTORS 5
#define CHECK_REFS 3

const char rotor[8][26] = { "EKMFLGDQVZNTOWYHXUSPAIBRCJ",			//I
							"AJDKSIRUXBLHWTMCQGZNPYFVOE",			//II
							"BDFHJLCPRTXVZNYEIWGAKMUSQO",			//III
							"ESOVPZJAYQUIRHXLNFTGKDCMWB",			//IV
							"VZBRGITYUPSDNHLXAWMJQOFECK",			//V
							"JPGVOUMFYQBENHZRDKASXLICTW",			//VI
							"NZJHGRCXMYSWBOUFAIVLPEKQDT",			//VII
							"FKQHTLXOCBJSPDZRAMEWNIUYGV"},			//VIII
notch[8][2] = {"Q0", "E0", "V0", "J0", "Z0", "ZM", "ZM", "ZM"},		//I: Q-R, II: E-F, III: V-W, IV: J-K, V: Z-A, (VI, VII, VII): (Z-A & M-N)
reflector[5][26] = {"EJMZALYXVBWFCRQUONTSPIKHGD",		//UKW-A
					"YRUHQSLDPXNGOKMIEBFZCWVJAT",		//UKW-B
					"FVPJIAOYEDRZXWGCTKUQSBNMHL",		//UKW-C
					"LEYJVCNIXWPBQMDRTAKZGFUHOS",		//Beta
					"FSOKANUERHMBTIYCWLQPZXVGJD"},		//Gamma
defaultPlug[27] = "BQCRDIEJKWMTOSPXUZGH";				//B<->Q, C<->R, D<->I, ..., U<->Z, G<->H

typedef enum {I, II, III, IV, V, VI, VII, VIII} Rotors;
typedef enum {UKW_A, UKW_B, UKW_C, Beta, Gamma} Reflectors;
typedef enum {CYPHER='1', DECYPHER, TEST} Choices;
typedef struct P {
	unsigned short order[3], ref;
	char pos[3], rings[3], *plug;
} Params;
//enigma makinesinin konfig�rasyon parametreleri: kullan�lan rotor index'leri, reflekt�r rotorun index'i, rotorlar�n ba�lang�� pozisyonlar�, rotorlar�n ring de�erleri, plugboard'daki ba�lant�l� harf �iftleri

void stepUpRotor(char *rotorPos) {						//rotoru bir harf d�nd�r�r
	if((++(*rotorPos)) > 'Z')		*rotorPos = 'A';
}

void passPlugboard(char *c, const char *plugBoard) {	//harfi plugboard'dan ge�irir
	unsigned short i;
	for(i=0;plugBoard[i];i+=2)
		if(*c == plugBoard[i]) {
			*c = plugBoard[i+1];
			return;
		}
		else if(*c == plugBoard[i+1]) {
			*c = plugBoard[i];
			return;
		}
}

void inRotor(char *c, const Params *p, const unsigned short *i) {		//rotora gir
	*c += p->pos[*i]-'A';
	if(*c > 'Z')		*c -= 26;
	*c -= p->rings[*i]-'A';
	if(*c < 'A')		*c += 26;
}

void outRotor(char *c, const Params *p, const unsigned short *i) {		//rotordan ��k
	if(*c > 'Z')		*c -= 26;
	*c -= p->pos[*i]-'A';
	if(*c < 'A')		*c += 26;
}

char nextChar(const char *c) {	return *c=='Z' ? 'A' : *c+1;	}

char scramble(char c, Params *p) {			//gelen karakteri �ifreler
	if(c < 'A' || c > 'Z')		return c;
	static bool flag = false;
	stepUpRotor(&p->pos[0]);				//1. rotoru d�nd�r
	if(flag) {								//flag true ise 2. ve 3. rotoru d�nd�r
		stepUpRotor(&p->pos[1]);
		stepUpRotor(&p->pos[2]);
		flag = false;
	}
	else if(p->pos[0] == nextChar(&notch[p->order[0]][0]) || p->pos[0] == nextChar(&notch[p->order[0]][1])) {		//1. rotor tam tur atm��sa 2. rotoru d�nd�r
		stepUpRotor(&p->pos[1]);
		flag = (p->pos[1] == notch[p->order[1]][0] || p->pos[1] == notch[p->order[1]][1]);
	}
	passPlugboard(&c, p->plug);				//harfi plugboard'dan ge�ir
	unsigned short i, j;
	for(i=0;i<3;i++) {						//harfi rotorlardan ge�ir
		inRotor(&c, p, &i);
		c = rotor[p->order[i]][c-'A'] + p->rings[i] - 'A';
		outRotor(&c, p, &i);
	}
	c = reflector[p->ref][c-'A'];			//harfi reflekt�r rotordan ge�ir
	for(i=2;i!=USHRT_MAX;i--) {				//harfi rotorlardan ��kar
		inRotor(&c, p, &i);
		for(j=0;j<26;j++)
			if(c == rotor[p->order[i]][j])
				break;
		c = j + p->rings[i];
		outRotor(&c, p, &i);
	}
	passPlugboard(&c, p->plug);				//harfi tekrar plugboard'dan ge�ir
	return c;
}

char* enigma(const char *in, Params *p) {						//gelen mesaj�n enigma'daki kar��l���n� d�nd�r�r
	char *out = (char*) malloc(MSG_LEN * sizeof(char));
	unsigned int i;
	for(i=0;in[i];i++)
		out[i] = scramble(in[i], p);
	out[i] = '\0';
	out = (char*) realloc(out, (i+1) * sizeof(char));
	return out;
}

void readMessage(char *message, const unsigned int maxLen) {	//klavyeden girilen mesaj�/katar� okur
	fgets(message, maxLen, stdin);
	unsigned int len = strcspn(message, "\n");
	message[len] = '\0';
	message = (char*) realloc(message, (len+1) * sizeof(char));
	strupr(message);
}

unsigned int removeNonCapitalChars(char *message) {				//b�y�k harf olmayan t�m harfleri mesajdan siler
	unsigned int i, j;
	for(i=0;message[i];i++)
		while((message[i] < 'A' || message[i] > 'Z') && message[i])
			for(j=i;message[j];j++)
				message[j] = message[j+1];
	message = (char*) realloc(message, (i+1) * sizeof(char));
	return i;
}

void cypher(Params p, const bool ignoreForeignChars) {			//klavyeden girilen mesaj� okur ve �ifrelenmi�/de�ifre edilmi� halini yazd�r�r
	printf("%sypher the following message:\n\n\t", ignoreForeignChars ? "C" : "Dec");
	char *message = (char*) malloc(MSG_LEN * sizeof(char));
	readMessage(message, MSG_LEN);
	char* encoded = enigma(message, &p);
	free(message);
	if(ignoreForeignChars) {
		printf("\nEncoded message:\n\n\t");
		unsigned int i, j, len = removeNonCapitalChars(encoded);
		for(i=0; i+DIV_LEN<len; i+=DIV_LEN) {
			for(j=0;j<DIV_LEN;j++)
				printf("%c", encoded[i+j]);
			printf(" ");
		}
		for(j=0;i+j<len;j++)
			printf("%c", encoded[i+j]);
		puts("");
	}
	else		printf("\nDecoded message:\n\n\t%s\n", encoded);
	free(encoded);
}

char* getStringRotor(const unsigned short *r) {
	switch(*r) {
		case I:			return "I";
		case II:		return "II";
		case III:		return "III";
		case IV:		return "IV";
		case V:			return "V";
		case VI:		return "VI";
		case VII:		return "VII";
		case VIII:		return "VIII";
		default:		exit(1);
	}
}

char* getStringReflector(const unsigned short *ref) {
	switch(*ref) {
		case UKW_A:			return "UKW-A";
		case UKW_B:			return "UKW-B";
		case UKW_C:			return "UKW-C";
		case Beta:			return "Beta";
		case Gamma:			return "Gamma";
		default:			exit(1);
	}
}

void printParams(const Params *p) {								//enigma makinesinin konfig�rasyon parametrelerini yazd�r�r
	printf("Rotors: %s %s %s  Reflector: %s  Start: %c %c %c  Rings: %c %c %c  Stecker: \"%s\"\n",
		getStringRotor(&p->order[0]), getStringRotor(&p->order[1]), getStringRotor(&p->order[2]),
		getStringReflector(&p->ref), p->pos[0], p->pos[1], p->pos[2], p->rings[0], p->rings[1], p->rings[2], p->plug);
}

void rotate(const unsigned short *a, const unsigned short *b, const unsigned short *c, const char *cyph, const char *crib, const char *plug, unsigned int *ct) {
	Params p = (Params){{*a,*b,*c}, UKW_B, "AAA", "AAA", (char*) malloc(27 * sizeof(char))};	//verilen �ifreli metin ve �evirisinden hareketle rotorlar�n ba�lang�� pozisyonlar�n� bulur
	strcpy(p.plug, plug);
	p.plug = (char*) realloc(p.plug, (strlen(p.plug)+1) * sizeof(char));
	unsigned short i;
	for(i=0;i<CHECK_REFS;i++) {
		p.ref = i;
		for(p.pos[0]='A'; p.pos[0]<='Z'; p.pos[0]++)			//brute force	(26^3 iterasyon)
			for(p.pos[1]='A'; p.pos[1]<='Z'; p.pos[1]++)
				for(p.pos[2]='A'; p.pos[2]<='Z'; p.pos[2]++) {
					Params cp = p;
					unsigned int j;
					for(j=0;crib[j];j++)
						if(cyph[j] != scramble(crib[j], &cp))
							break;
					if(!crib[j]) {
						(*ct)++;
						printParams(&p);
						cp = p;
						printf("\"%s\" decoded --> \"%s\"\n", cyph, enigma(cyph, &cp));
					}
				}
	}
	free(p.plug);
}

void test(const unsigned short *a, const unsigned short *b, const unsigned short *c, const char *cyph, const char *crib, unsigned int *ct) {
	char A, B, C, D, plug[5]="";								//maksimum 2 harf �iftine kadar olan, 'A' ile LAST_CHAR harfleri aras�ndaki t�m plugboard konfig�rasyonlar�n� test eder
	unsigned short i;
	printf("Checking rotors %s %s %s...\n", getStringRotor(a), getStringRotor(b), getStringRotor(c)); 
	for(i=0;i<3;i++)
		if(i>0)
			for(A='A';A<=LAST_CHAR;A++)
				for(B=A+1;B<=LAST_CHAR;B++) {
					strcpy(plug, (char[]){A,B,'\0'});
					if(i>1)
						for(C=A+1;C<=LAST_CHAR;C++) {
							if(C==B)		continue;
							for(D=C+1;D<=LAST_CHAR;D++) {
								if(D==A || D==B)		continue;
								strcpy(plug+2, (char[]){C,D,'\0'});
								rotate(a, b, c, cyph, crib, plug, ct);
							}
						}
					else		rotate(a, b, c, cyph, crib, plug, ct);
				}
		else		rotate(a, b, c, cyph, crib, plug, ct);
}

void permute(const unsigned short *a, const unsigned short *b, const unsigned short *c, const char *cyph, const char *crib, unsigned int *ct) {
	test(a, b, c, cyph, crib, ct);								//a, b ve c rotorlar�n�n t�m perm�tasyonlar�n� kontrol eder
	test(a, c, b, cyph, crib, ct);
	test(b, a, c, cyph, crib, ct);
	test(b, c, a, cyph, crib, ct);
	test(c, a, b, cyph, crib, ct);
	test(c, b, a, cyph, crib, ct);
}

void permuteAll(const char *cyph, const char *crib) {			//5 rotorun t�m 3'l� kombinasyonlar�n� kontrol eder
	unsigned int ct=0;
	unsigned short i, j, k;
	for(i=0;i<CHECK_ROTORS-2;i++)
		for(j=i+1;j<CHECK_ROTORS-1;j++)
			for(k=j+1;k<CHECK_ROTORS;k++)
				permute(&i, &j, &k, cyph, crib, &ct);
	printf("\nFound %u solution%s.\n", ct, ct==1 ? "" : "s");
}

void getParams(Params *p) {					//kullan�c�dan enigma parametrelerini al�r
	unsigned short i;
	for(i=0;i<3;i++) {
		printf("Rotor %hu: ", i+1);
		scanf("%hu", &p->order[i]);
		p->order[i]--;
	}
	printf("Reflector: ");
	scanf("%hu", &p->ref);
	p->ref--;
	for(i=0;i<3;i++) {
		printf("Start %hu: ", i+1);
		scanf("%*c%c", &p->pos[i]);
		p->pos[i] = toupper(p->pos[i]);
	}
	for(i=0;i<3;i++) {
		printf("Ring %hu: ", i+1);
		scanf("%*c%c", &p->rings[i]);
		p->rings[i] = toupper(p->rings[i]);
	}
	printf("Stecker: ");
	scanf("%*c");
	p->plug = (char*) malloc(27 * sizeof(char));
	readMessage(p->plug, 27);
}

void initParams(Params *p) {				//default veya kullan�c�dan al�nan parametrelerine g�re enigma parametrelerini initialize eder
	printf("\nd)efault or u)ser: ");
	char c;
	scanf("%c%*c", &c);
	switch(c) {
		case 'u':
		case 'U':
			getParams(p);
			break;
		default:
			*p = (Params){{III,II,I}, UKW_B, "LQA", "AAA", (char*) malloc(27 * sizeof(char))};
			strcpy(p->plug, defaultPlug);
			p->plug = (char*) realloc(p->plug, (strlen(p->plug)+1) * sizeof(char));
	}
	printParams(p);
}

int main() {
	printf( "Press '%c' to cypher a message.\n"
			"Press '%c' to decypher a message.\n"
			"Press '%c' to find rotor and plugboard (up to 2 pairs) configurations.\n"
			"Press a key to continue: ", CYPHER, DECYPHER, TEST);
	while(true) {
		char c;
		scanf("%c%*c", &c);
		switch(c) {
			case CYPHER: {			//mesaj gir ve �ifrele
				Params p;
				initParams(&p);
				cypher(p, true);
				free(p.plug);
				break;
			}
			case DECYPHER: {		//�ifreli mesaj gir ve de�ifre et (�ifreleme ile ayn� i�lem)
				puts("");
				Params p;
				getParams(&p);
				printParams(&p);
				cypher(p, false);
				free(p.plug);
				break;
			}
			case TEST: {			//�ifreli mesaj ve �evirisini gir, bunlardan hareketle enigma makinesinin konfig�rasyonlar�n� bul		(bombe makinesi)
				char *cyph = (char*) malloc(MSG_LEN * sizeof(char)), *crib = (char*) malloc(MSG_LEN * sizeof(char));
				printf("\nEnter encrypted message:\n\n\t");
				readMessage(cyph, MSG_LEN);
				printf("\nEnter translation:\n\n\t");
				readMessage(crib, MSG_LEN);
				puts("");
				permuteAll(cyph, crib);
				free(cyph);
				free(crib);
				break;
			}
			default:
				printf("Please try another key: ");
				continue;
		}
		break;
	}
	exit(0);
}
