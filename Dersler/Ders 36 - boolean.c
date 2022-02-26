#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

/* "boolean algebra: mant�ksal aritmetik"     "true: do�ru, 1"     "false: yanl��, 0"
   bilgisayar ve elektrik elektronikte do�ru/yanl�� yarg�lar� �retmek i�in kullan�lan ve 1'ler ile 0'lar ile ifade edilen aritmeti�e "boolean" ad� verilir
   �o�u programlama dilinde "bool" diye ayr� bir veri tipi olsada (string veri tipi gibi), C'de default olarak b�yle bir veri tipi yoktur     (asl�nda o kadar boktan yine de bir o kadar g��l� bir dil)
   bool yerine alternatif olarak ko�ul yarg�lar� int de�i�kenlerine atanabilir
   bu arada default olarak true=1, false=0 olsa da asl�nda 0 d���ndaki b�t�n tam say� de�erleri true olarak kabul edilir

int main() {
	setlocale(LC_ALL,"Turkish");															alternatif olarak:
	int a=2+2==2*2;									//do�ru  ==> 1
	int b=10+30==50;								//yanl�� ==> 0								int main() {
	int c=13<=31;									//do�ru  ==> 1									setlocale(LC_ALL,"Turkish");
	int d=strcmp("elma","armut")<0;					//yanl�� ==> 0									int a=2+2==2*2;
	int e=floor(3.456)==ceil(2.312);				//do�ru  ==> 1									int b=10+30==50;
	int f=((1 || 0) && (1 && 0)) || (1 && 0 && 1);	//yanl�� ==> 0									int c=13<=31;
																									int d=strcmp("elma","armut")<0;
	if(a)																							int e=floor(3.456)==ceil(2.312);
		printf("a yargisi do�ru  ==> a: %d\n",a);													int f=((1 || 0) && (1 && 0)) || (1 && 0 && 1);
	else																							int dizi[6]={a,b,c,d,e,f};		//dizi[6]={1,0,1,0,1,0}
		printf("a yargisi yanl�� ==> a: %d\n",a);													int i;
	if(b)																							char k='a';
		printf("b yargisi do�ru  ==> b: %d\n",b);													for(i=0;i<6;i++,k++)
	else																								if(dizi[i])
		printf("b yargisi yanl�� ==> b: %d\n",b);															printf("%c yargisi do�ru  ==> %c: %d\n",k,k,dizi[i]);
	if(c)																								else
		printf("c yargisi do�ru  ==> c: %d\n",c);															printf("%c yargisi yanl�� ==> %c: %d\n",k,k,dizi[i]);
	else																							return 0;
		printf("c yargisi yanl�� ==> c: %d\n",c);												}
	if(d)
		printf("d yargisi do�ru  ==> d: %d\n",d);
	else
		printf("d yargisi yanl�� ==> d: %d\n",d);
	if(e)
		printf("e yargisi do�ru  ==> e: %d\n",e);
	else
		printf("e yargisi yanl�� ==> e: %d\n",e);
	if(f)
		printf("f yargisi do�ru  ==> f: %d\n",f);
	else
		printf("f yargisi yanl�� ==> f: %d\n",f);
	return 0;
}

   int de�i�kenlerine direkt true (1) ve false (0) da atayabiliriz

int main() {
	int a=true,i=0,k=1;
	while(a) {
		printf("%d - r u coding son\n",k);	//i=0,1,2,...,10 i�in 11 defa "r u coding son" yazd�r�r
		if(i==10)
			a=false;	//break yazmak ile ayn� �ey bir nevi
		i++;
		k*=2;
	}
}

   asl�nda bool diye bir veri tipi var da, onun i�in <stdbool.h> k�t�phanesini import (include) etmek gerekiyor

int main() {
	bool a=true,b=false;
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	printf("!a=%d\n",!a);		//not operat�r�
	printf("!b=%d\n",!b);
	printf("a&&b=%d\n",a&&b);	//and operat�r�
	printf("a||b=%d\n",a||b);	//or operat�r�
}

   art�k recursion ve bool veri tipini de bildi�imize g�re, hadi N-Vezir probleminin (N-Queen) ��z�m�n� inceleyelim

#define N 8			//N-Vezir problemindeki "N"i ka� yapmak istersen buradan de�i�tirebilirsin bebe�im ;)

// Sonucu yazd�rmak i�in kullan�lan yard�mc� bir fonksiyon
void printSolution(int board[N][N]) {
	int i,j;
	for(i=0;i<N;i++) {
		for(j=0;j<N;j++)
			printf(" %d ",board[i][j]);
		printf("\n");
	}
}

// Bir vezirin board[row][col]'a yerle�tirilip yerle�tirilemeyece�ini �l�en yard�mc� bir fonksiyon. Bu fonksiyon 0 ila col-1
// s�tunlar� aras�na vezirler yerle�tirildi�inde �a��r�l�r, dolay�s�yla bizim sadece tahtan�n sol taraf�nda koyaca��m�z
// vezire sald�ran bir vezir var m� yok mu diye kontrol etmemiz laz�m
bool isSafe(int board[N][N], int row, int col) {
	int i,j;
	for(i=0;i<col;i++)			//bulundu�un sat�r�n sol taraf�n� kontrol et
		if(board[row][i])
			return false;
	for(i=row,j=col;i>=0 && j>=0;i--,j--)	//sol �st �apraz� kontrol et
		if(board[i][j])
			return false;
	for(i=row,j=col;j>=0 && i<N;i++,j--)	//sol alt �apraz� kontrol et
		if(board[i][j])
			return false;
	return true;
}

// N-Vezir problemini ��zmemiz i�in gereken recursive bir yard�mc� fonksiyon
bool solveNQUtil(int board[N][N], int col) {
	if(col>=N)
		return true;	//temel durum (base case): e�er b�t�n vezirler yerle�tirilmi�se true d�nd�r
	int i;
	for(i=0;i<N;i++) {				//"col" s�tunundaki b�t�n sat�rlara bir vezirin yerle�tirilip yerle�tirilemeyece�ini kontrol et
		if(isSafe(board,i,col)) {			//board[i][col]'a vezir yerle�tirilebilir mi kontrol et
			board[i][col]=1;				//veziri yerle�tir
			if(solveNQUtil(board,col+1))	//kalan vezirlere bak
				return true;
			board[i][col]=0;				//e�er veziri board[i][col]'a koymak bizi bir ��z�me g�t�rm�yorsa veziri oradan kald�r		(BACKTRACKING)
		}
	}
	return false;			//e�er vezir "col" s�tunundaki hi�bir sat�ra yerle�tirilemiyorsa false d�nd�r
}

// main() fonksiyonu N-Vezir problemini backtracking yaparak ��z�yor. Bu problemi ��zmek i�in as�l solveNQUtil() fonksiyonundan
// faydalan�yor. E�er vezirler tahtaya yerle�tirilemeyecekse ��z�m�n�n olmad���n�, yerle�tirilebilecekse de vezirler 1,
// bo� kareler 0 ile ifade edilecek �ekilde sonucu konsola yazd�r�yor. Unutmamak gerekir ki bu problemin birden fazla
// ��z�m� olabilir, bu fonksiyon bu olas� ��z�mlerden sadece birini yazd�r�yor.
int main() {
	setlocale(LC_ALL,"Turkish");
	int board[N][N]={{0}};	//b�t�n bu matrisin elemanlar� 0 olarak initialize edildi
//	int board[N][N]={ {0,0,0,0},
//					  {0,0,0,0},
//					  {0,0,0,0},
//					  {0,0,0,0} };		//mesela N=4 olsay� b�yle tan�mlanabilirdi
	if(!solveNQUtil(board,0)) {
		printf("%d-Vezir probleminin ��z�m� yok.",N);
		exit(1);
	}
	printSolution(board);
	exit(0);
}


   yukar�dakine benzer bir �ekilde, hadi yine backtracking y�ntemi, recursion ve bool d�nd�ren yard�mc� fonksiyonlarla labirent ��zelim */

#define WIDTH 5
#define HEIGHT 4		//labirentin en ve boyu, yani geni�lik ve y�ksekli�i
#define START_X 0
#define START_Y 1
#define FINISH_X 2
#define FINISH_Y 0		//labirentin ba�lang�� ve biti� noktalar�

// sol[HEIGHT][WIDTH] matrisini konsola yazd�rmak i�in kullan�lan yard�mc� bir fonksiyon
void printSolution(int sol[HEIGHT][WIDTH]) {
	int i,j;
	for(i=0;i<HEIGHT;i++) {
		for(j=0;j<WIDTH;j++)
			printf(" %d ",sol[i][j]);
		printf("\n");
	}
}

// Labirent problemini ��zmemiz i�in gereken recursive bir yard�mc� fonksiyon
bool solveMazeUtil(int maze[HEIGHT][WIDTH], int x, int y, int sol[HEIGHT][WIDTH]) {
	if(x==FINISH_X && y==FINISH_Y && maze[y][x]==0) {
		sol[y][x]=1;
		return true;	//hedefe eri�ildiyse true d�nd�r
	}	//mevcut noktan�n s�n�rlar� a�mad���n�, a��k alanda oldu�unu ve ��z�m yoluna �nceden dahil edilmedi�ini kontrol et
	else if(x>=0 && x<WIDTH && y>=0 && y<HEIGHT && maze[y][x]==0 && sol[y][x]==0) {
		sol[y][x]=1;	//��z�m yolunun bir par�as� olarak maze[y][x] noktas�n� al ve i�aretle
		if(solveMazeUtil(maze,x,y+1,sol))		//bir nokta a�a�� git
			return true;
		else if(solveMazeUtil(maze,x+1,y,sol))	//bir a�a��daki nokta ��z�m yoluna dahil de�ilse, bir nokta sa�a git
			return true;
		else if(solveMazeUtil(maze,x,y-1,sol))	//bir sa�daki nokta ��z�m yoluna dahil de�ilse, bir nokta yukar� git
			return true;
		else if(solveMazeUtil(maze,x-1,y,sol))	//bir yukar�daki nokta ��z�m yoluna dahil de�ilse, bir nokta sola git
			return true;
		sol[y][x]=0;	//e�er yukar�daki hamlelerin hi�biri i�e yaramazsa, backtracking yap ve maze[y][x] noktas�n� ��z�m yolundan sil
		return false;
	}
	return false;
}

// main() fonksiyonu labirent problemini backtracking yaparak ��z�yor. Bu problemi ��zmek i�in as�l solveMazeUtil() fonksiyonundan
// faydalan�yor. E�er labirent ��z�lemeyecekse ��z�m�n olmad���n�, ��z�lebilecekse ��z�m yolu 1'ler, di�er noktalar 0 ile ifade
// edilecek �ekilde sonucu konsola yazd�r�yor. Unutmamak gerekir ki bu problemin birden fazla ��z�m� olabilir, bu fonksiyon
// bu olas� ��z�mlerden sadece birini yazd�r�yor.
int main() {
	setlocale(LC_ALL,"Turkish");
	int maze[HEIGHT][WIDTH]={ {1,1,0,0,1},		//0'lar a��k alan, 1'ler duvar
							  {0,0,1,0,0},
							  {1,0,1,1,0},
							  {0,0,0,0,0} };
	int sol[HEIGHT][WIDTH]={{0}};
//	int sol[HEIGHT][WIDTH]={ {0,0,0,0,0},
//							 {0,0,0,0,0},
//							 {0,0,0,0,0},
//							 {0,0,0,0,0} };		//mesela WIDTH=5, HEIGHT=4 olsay� b�yle tan�mlanabilirdi
	if(!solveMazeUtil(maze,START_X,START_Y,sol)) {
		printf("Bu labirentin ��z�m� yok.");
		exit(1);
	}
	printSolution(sol);
	exit(0);
}
