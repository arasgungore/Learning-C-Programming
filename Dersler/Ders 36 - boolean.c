#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

/* "boolean algebra: mantýksal aritmetik"     "true: doðru, 1"     "false: yanlýþ, 0"
   bilgisayar ve elektrik elektronikte doðru/yanlýþ yargýlarý üretmek için kullanýlan ve 1'ler ile 0'lar ile ifade edilen aritmetiðe "boolean" adý verilir
   çoðu programlama dilinde "bool" diye ayrý bir veri tipi olsada (string veri tipi gibi), C'de default olarak böyle bir veri tipi yoktur     (aslýnda o kadar boktan yine de bir o kadar güçlü bir dil)
   bool yerine alternatif olarak koþul yargýlarý int deðiþkenlerine atanabilir
   bu arada default olarak true=1, false=0 olsa da aslýnda 0 dýþýndaki bütün tam sayý deðerleri true olarak kabul edilir

int main() {
	setlocale(LC_ALL,"Turkish");															alternatif olarak:
	int a=2+2==2*2;									//doðru  ==> 1
	int b=10+30==50;								//yanlýþ ==> 0								int main() {
	int c=13<=31;									//doðru  ==> 1									setlocale(LC_ALL,"Turkish");
	int d=strcmp("elma","armut")<0;					//yanlýþ ==> 0									int a=2+2==2*2;
	int e=floor(3.456)==ceil(2.312);				//doðru  ==> 1									int b=10+30==50;
	int f=((1 || 0) && (1 && 0)) || (1 && 0 && 1);	//yanlýþ ==> 0									int c=13<=31;
																									int d=strcmp("elma","armut")<0;
	if(a)																							int e=floor(3.456)==ceil(2.312);
		printf("a yargisi doðru  ==> a: %d\n",a);													int f=((1 || 0) && (1 && 0)) || (1 && 0 && 1);
	else																							int dizi[6]={a,b,c,d,e,f};		//dizi[6]={1,0,1,0,1,0}
		printf("a yargisi yanlýþ ==> a: %d\n",a);													int i;
	if(b)																							char k='a';
		printf("b yargisi doðru  ==> b: %d\n",b);													for(i=0;i<6;i++,k++)
	else																								if(dizi[i])
		printf("b yargisi yanlýþ ==> b: %d\n",b);															printf("%c yargisi doðru  ==> %c: %d\n",k,k,dizi[i]);
	if(c)																								else
		printf("c yargisi doðru  ==> c: %d\n",c);															printf("%c yargisi yanlýþ ==> %c: %d\n",k,k,dizi[i]);
	else																							return 0;
		printf("c yargisi yanlýþ ==> c: %d\n",c);												}
	if(d)
		printf("d yargisi doðru  ==> d: %d\n",d);
	else
		printf("d yargisi yanlýþ ==> d: %d\n",d);
	if(e)
		printf("e yargisi doðru  ==> e: %d\n",e);
	else
		printf("e yargisi yanlýþ ==> e: %d\n",e);
	if(f)
		printf("f yargisi doðru  ==> f: %d\n",f);
	else
		printf("f yargisi yanlýþ ==> f: %d\n",f);
	return 0;
}

   int deðiþkenlerine direkt true (1) ve false (0) da atayabiliriz

int main() {
	int a=true,i=0,k=1;
	while(a) {
		printf("%d - r u coding son\n",k);	//i=0,1,2,...,10 için 11 defa "r u coding son" yazdýrýr
		if(i==10)
			a=false;	//break yazmak ile ayný þey bir nevi
		i++;
		k*=2;
	}
}

   aslýnda bool diye bir veri tipi var da, onun için <stdbool.h> kütüphanesini import (include) etmek gerekiyor

int main() {
	bool a=true,b=false;
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	printf("!a=%d\n",!a);		//not operatörü
	printf("!b=%d\n",!b);
	printf("a&&b=%d\n",a&&b);	//and operatörü
	printf("a||b=%d\n",a||b);	//or operatörü
}

   artýk recursion ve bool veri tipini de bildiðimize göre, hadi N-Vezir probleminin (N-Queen) çözümünü inceleyelim

#define N 8			//N-Vezir problemindeki "N"i kaç yapmak istersen buradan deðiþtirebilirsin bebeðim ;)

// Sonucu yazdýrmak için kullanýlan yardýmcý bir fonksiyon
void printSolution(int board[N][N]) {
	int i,j;
	for(i=0;i<N;i++) {
		for(j=0;j<N;j++)
			printf(" %d ",board[i][j]);
		printf("\n");
	}
}

// Bir vezirin board[row][col]'a yerleþtirilip yerleþtirilemeyeceðini ölçen yardýmcý bir fonksiyon. Bu fonksiyon 0 ila col-1
// sütunlarý arasýna vezirler yerleþtirildiðinde çaðýrýlýr, dolayýsýyla bizim sadece tahtanýn sol tarafýnda koyacaðýmýz
// vezire saldýran bir vezir var mý yok mu diye kontrol etmemiz lazým
bool isSafe(int board[N][N], int row, int col) {
	int i,j;
	for(i=0;i<col;i++)			//bulunduðun satýrýn sol tarafýný kontrol et
		if(board[row][i])
			return false;
	for(i=row,j=col;i>=0 && j>=0;i--,j--)	//sol üst çaprazý kontrol et
		if(board[i][j])
			return false;
	for(i=row,j=col;j>=0 && i<N;i++,j--)	//sol alt çaprazý kontrol et
		if(board[i][j])
			return false;
	return true;
}

// N-Vezir problemini çözmemiz için gereken recursive bir yardýmcý fonksiyon
bool solveNQUtil(int board[N][N], int col) {
	if(col>=N)
		return true;	//temel durum (base case): eðer bütün vezirler yerleþtirilmiþse true döndür
	int i;
	for(i=0;i<N;i++) {				//"col" sütunundaki bütün satýrlara bir vezirin yerleþtirilip yerleþtirilemeyeceðini kontrol et
		if(isSafe(board,i,col)) {			//board[i][col]'a vezir yerleþtirilebilir mi kontrol et
			board[i][col]=1;				//veziri yerleþtir
			if(solveNQUtil(board,col+1))	//kalan vezirlere bak
				return true;
			board[i][col]=0;				//eðer veziri board[i][col]'a koymak bizi bir çözüme götürmüyorsa veziri oradan kaldýr		(BACKTRACKING)
		}
	}
	return false;			//eðer vezir "col" sütunundaki hiçbir satýra yerleþtirilemiyorsa false döndür
}

// main() fonksiyonu N-Vezir problemini backtracking yaparak çözüyor. Bu problemi çözmek için asýl solveNQUtil() fonksiyonundan
// faydalanýyor. Eðer vezirler tahtaya yerleþtirilemeyecekse çözümünün olmadýðýný, yerleþtirilebilecekse de vezirler 1,
// boþ kareler 0 ile ifade edilecek þekilde sonucu konsola yazdýrýyor. Unutmamak gerekir ki bu problemin birden fazla
// çözümü olabilir, bu fonksiyon bu olasý çözümlerden sadece birini yazdýrýyor.
int main() {
	setlocale(LC_ALL,"Turkish");
	int board[N][N]={{0}};	//bütün bu matrisin elemanlarý 0 olarak initialize edildi
//	int board[N][N]={ {0,0,0,0},
//					  {0,0,0,0},
//					  {0,0,0,0},
//					  {0,0,0,0} };		//mesela N=4 olsayý böyle tanýmlanabilirdi
	if(!solveNQUtil(board,0)) {
		printf("%d-Vezir probleminin çözümü yok.",N);
		exit(1);
	}
	printSolution(board);
	exit(0);
}


   yukarýdakine benzer bir þekilde, hadi yine backtracking yöntemi, recursion ve bool döndüren yardýmcý fonksiyonlarla labirent çözelim */

#define WIDTH 5
#define HEIGHT 4		//labirentin en ve boyu, yani geniþlik ve yüksekliði
#define START_X 0
#define START_Y 1
#define FINISH_X 2
#define FINISH_Y 0		//labirentin baþlangýç ve bitiþ noktalarý

// sol[HEIGHT][WIDTH] matrisini konsola yazdýrmak için kullanýlan yardýmcý bir fonksiyon
void printSolution(int sol[HEIGHT][WIDTH]) {
	int i,j;
	for(i=0;i<HEIGHT;i++) {
		for(j=0;j<WIDTH;j++)
			printf(" %d ",sol[i][j]);
		printf("\n");
	}
}

// Labirent problemini çözmemiz için gereken recursive bir yardýmcý fonksiyon
bool solveMazeUtil(int maze[HEIGHT][WIDTH], int x, int y, int sol[HEIGHT][WIDTH]) {
	if(x==FINISH_X && y==FINISH_Y && maze[y][x]==0) {
		sol[y][x]=1;
		return true;	//hedefe eriþildiyse true döndür
	}	//mevcut noktanýn sýnýrlarý aþmadýðýný, açýk alanda olduðunu ve çözüm yoluna önceden dahil edilmediðini kontrol et
	else if(x>=0 && x<WIDTH && y>=0 && y<HEIGHT && maze[y][x]==0 && sol[y][x]==0) {
		sol[y][x]=1;	//çözüm yolunun bir parçasý olarak maze[y][x] noktasýný al ve iþaretle
		if(solveMazeUtil(maze,x,y+1,sol))		//bir nokta aþaðý git
			return true;
		else if(solveMazeUtil(maze,x+1,y,sol))	//bir aþaðýdaki nokta çözüm yoluna dahil deðilse, bir nokta saða git
			return true;
		else if(solveMazeUtil(maze,x,y-1,sol))	//bir saðdaki nokta çözüm yoluna dahil deðilse, bir nokta yukarý git
			return true;
		else if(solveMazeUtil(maze,x-1,y,sol))	//bir yukarýdaki nokta çözüm yoluna dahil deðilse, bir nokta sola git
			return true;
		sol[y][x]=0;	//eðer yukarýdaki hamlelerin hiçbiri iþe yaramazsa, backtracking yap ve maze[y][x] noktasýný çözüm yolundan sil
		return false;
	}
	return false;
}

// main() fonksiyonu labirent problemini backtracking yaparak çözüyor. Bu problemi çözmek için asýl solveMazeUtil() fonksiyonundan
// faydalanýyor. Eðer labirent çözülemeyecekse çözümün olmadýðýný, çözülebilecekse çözüm yolu 1'ler, diðer noktalar 0 ile ifade
// edilecek þekilde sonucu konsola yazdýrýyor. Unutmamak gerekir ki bu problemin birden fazla çözümü olabilir, bu fonksiyon
// bu olasý çözümlerden sadece birini yazdýrýyor.
int main() {
	setlocale(LC_ALL,"Turkish");
	int maze[HEIGHT][WIDTH]={ {1,1,0,0,1},		//0'lar açýk alan, 1'ler duvar
							  {0,0,1,0,0},
							  {1,0,1,1,0},
							  {0,0,0,0,0} };
	int sol[HEIGHT][WIDTH]={{0}};
//	int sol[HEIGHT][WIDTH]={ {0,0,0,0,0},
//							 {0,0,0,0,0},
//							 {0,0,0,0,0},
//							 {0,0,0,0,0} };		//mesela WIDTH=5, HEIGHT=4 olsayý böyle tanýmlanabilirdi
	if(!solveMazeUtil(maze,START_X,START_Y,sol)) {
		printf("Bu labirentin çözümü yok.");
		exit(1);
	}
	printSolution(sol);
	exit(0);
}
