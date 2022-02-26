#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

/* Tic-tac-toe, nam-� di�er XOX oyununu �al��t�ran �ngilizce program

#define BOARD_SIZE 3
#define player1 "arasdasdas"
#define player2 "IBK"
#define mark1 'O'
#define mark2 'X'
void print_separator(char ch) {		//g�zel bir �zgara �izmek i�in ayra� olarak kullan�l�r
	int i;
	for(i=0;i<BOARD_SIZE;i++) {
		printf("%c%c%c",ch,ch,ch);
		if(i!=BOARD_SIZE-1)
			printf("|");			//ch='x' i�in mesela "xxx|xxx|xxx" yazd�r�r ve sat�r atlar
	}
	printf("\n");
}
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {	//b�y�k ve g�zel bir �zgara �izer
	printf("Player 1 (%s)  -  Player 2 (%s)\n\n",player1,player2);	//1. ve 2. oyuncunun isimlerini yukar� yazd�r�r
	int i,j;
	for(i=0;i<BOARD_SIZE;i++) {
		print_separator(' ');	//"   |   |   "
		for(j=0;j<BOARD_SIZE;j++) {
			printf(" %c ", board[i][j]==-1 ? ' ' : (board[i][j]==0 ? mark1 : mark2));	//-1: ' '   0: 'X'   1: 'O'
			if(j!=BOARD_SIZE-1)	//j=0, j=1 ve j=2 i�in   bo� ==> "   |   |   "  : dolu (mesela): "   | O |   "
				printf("|");
		}
		if(i!=BOARD_SIZE-1) {
			printf("\n");
			print_separator('_');	//i=0 ve i=1 i�in "___|___|___"
		}
	}
	printf("\n");
	print_separator(' ');	//son olarak "   |   |   "
}
int check_winner(int board[BOARD_SIZE][BOARD_SIZE]) {	//kimin kazand���na g�re bir rakam d�nd�r�r
	int i,j,row_sum=0,col_sum=0,left_diag_sum=0,right_diag_sum=0;	//-1: berabere ya da oyuna devam   0: 1. oyuncu   1: 2. oyuncu
	for(i=0;i<BOARD_SIZE;i++) {
		for(j=0;j<BOARD_SIZE;j++) {
			row_sum+= board[i][j]==-1 ? BOARD_SIZE+1 : board[i][j];
			col_sum+= board[j][i]==-1 ? BOARD_SIZE+1 : board[j][i];
		}	//BOARD_SIZE+1 artarsa zaten kafadan ilerideki if else if yap�s� �al��mayacak
		if(row_sum==BOARD_SIZE || col_sum==BOARD_SIZE)
			return 1;	//row_sum=1+1+1=3, row_sum=0+0+0=0, col_sum=1+1+1=3 ya da col_sum=0+0+0=0 ise biri kazanm�� demektir (toplam 3 ise 2. oyuncu, 0 ise 1. oyuncu)
		else if(row_sum==0 || col_sum==0)
			return 0;
		row_sum=0,col_sum=0;	//i d�ng�s� i�erisinde row_sum ve col_sum tekrar 0 oluyor bir sonraki sat�r ve s�tunlar� kontrol etmek i�in
		left_diag_sum+= board[i][i]==-1 ? BOARD_SIZE+1 : board[i][i];
		right_diag_sum+= board[i][BOARD_SIZE-i-1]==-1 ? BOARD_SIZE+1 : board[i][BOARD_SIZE-i-1];
	}	//BOARD_SIZE+1 artarsa zaten kafadan ilerideki if else if yap�s� �al��mayacak
	if(left_diag_sum==BOARD_SIZE || right_diag_sum==BOARD_SIZE)
		return 1;
	else if(left_diag_sum==0 || right_diag_sum==0)
		return 0;
	return -1;		//fonksiyon return etmemi�se bu sat�ra kadar demek ki oyun devam ediyor ya da berabere
}
int main() {
	int i,j,moves=0,choice,row,col,board[BOARD_SIZE][BOARD_SIZE],winner;
	for(i=0;i<BOARD_SIZE;i++)
		for(j=0;j<BOARD_SIZE;j++)
			board[i][j]=-1; //board adl� 2D array'in her eleman� -1 olarak initialize edilmi�
	print_board(board);		//�zgaray� �iz
	while(1) {		//oyun bitene kadar sonsuz d�ng�
		printf("Player %d's turn: ",moves%2+1);
		scanf("%d",&choice); //1, 2, 3, ..., BOARD_SIZE*BOARD_SIZE=3*3=9
		row=(choice-1)/BOARD_SIZE;
		col=(choice-1)%BOARD_SIZE;	//i�aret konulacak index no'lar� se�ildi
		while(choice>BOARD_SIZE*BOARD_SIZE || choice<1 || board[row][col]!=-1) {
			printf("Not valid! Make a valid move: ");
			scanf("%d",&choice);	//1<=choice<=9 de�ilse ya da oras� �nceden doldurulmu� ise ge�erli bir se�im yapana kadar d�ng�
			row=(choice-1)/BOARD_SIZE;
			col=(choice-1)%BOARD_SIZE;
		}
		board[row][col]=moves%2;	//s�rayla X, O, X, O, ... yazd�rmak i�in	-1: bo�   0: 'X'   1: 'O'
		printf("\n");
		print_board(board);
		moves++;
		winner=check_winner(board);		//acaba kim kazand�?
		if(winner==-1 && moves==BOARD_SIZE*BOARD_SIZE) {
			printf("It's a tie!");
			return 0;		//main fonksiyonu i�erisinde "return 0" "exit(0)" gibi program� sonland�r�yor biliyorsunuz
		}
		else if(winner==1) {			//program else if'lerle az�c�k daha h�zl� �al���yor
			printf("Player 2 won!");
			return 0;
		}
		else if(winner==0) {
			printf("Player 1 won!");
			return 0;
		}
	}
}

   Adam asmaca oyununu �al��t�ran �ngilizce program

#define GUESSES 7
#define WORD_COUNT 10
#define MAX_WORD_LEN 40
const char answers[WORD_COUNT][MAX_WORD_LEN]={"bandwagon","missisippi","jazz","scatman","mnemonic","xylophone","queue","vocabulary","skedaddle","floccinaucinihilipilification"};
int main() {
	unsigned short i,word_no=0,word_length,wrong_guesses=0,known_letters=0,flag=0;
	char buffer[MAX_WORD_LEN],alpha;
	word_length=strlen(answers[0]);
	printf("\n\n\t\t*********** HANGMAN ***********\n");
	printf("\n\t\t...............................\n\n\t\t\t");
	for(i=0;i<word_length;i++) {
		buffer[i]='_';
		printf("%c ",buffer[i]);
	}
	printf("\n\n\t\t...............................");
	printf("\n\n\t\t*******************************");
	while(wrong_guesses<GUESSES) {
		flag=0;
		printf("\n\n\n\n\t\tEnter a char: ");
		alpha=getche();							//"scanf("%c%*c",&alpha);"		scanf fonksiyonunda klavyeden de�er girmek i�in en son ENTER'a basman gerekiyorken
		for(i=0;i<word_length;i++)				//<conio.h> k�t�phanesindeki getche fonksiyonu ile ENTER'a basmadan klavyeden tu�a bast���n gibi de�eri direkt girebiliyorsun
			if(alpha==answers[word_no][i] && buffer[i]!=answers[word_no][i]) {
				buffer[i]=answers[word_no][i];
				flag=1;				//flag 1 ise do�ru tahmin, 0 ise yanl�� tahmin yapt�m demek
				known_letters++;
			}
		system("cls");
		printf("\n\n\t\t*********** HANGMAN ***********\n");
		printf("\n\t\t...............................\n\n\t\t\t");
		for(i=0;i<word_length;i++)
			printf("%c ",buffer[i]);
		printf("\n\n\t\t...............................");
		printf("\n\n\t\t*******************************");
		if(flag==0) {
			wrong_guesses++;
			printf("\n\n\t\t%c is a wrong guess",alpha);
			printf("\n\n\t\t(You have %d more guesses)",GUESSES-wrong_guesses);
		}
		else {
			printf("\n\n\t\tYou are correct!!");
			printf("\n\t\t(You have %d more letters to go)",word_length-known_letters);
		}
		if(known_letters==word_length) {
			word_no++;
			wrong_guesses=known_letters=0;
			if(word_no<WORD_COUNT) {
				word_length=strlen(answers[word_no]);
				for(i=0;i<word_length;i++)
					buffer[i]='_';
			}
			system("cls");
			printf("\n\n\t\t*********** HANGMAN ***********\n");
			printf("\n\t\t...............................\n\n\t\t\t");
			for(i=0;i<word_length;i++)
				printf("%c ",buffer[i]);
			printf("\n\n\t\t...............................");
			printf("\n\n\t\t*******************************");
			if(word_no<WORD_COUNT)
				printf("\n\n\t\tYou guessed it, your next word is...");
		}
		if(word_no==WORD_COUNT)
			break;
	}
	if(word_no==WORD_COUNT)
		printf("\n\n\n\t\tYou won!!!\n\n\t\t***** CONGRATZ  U R WINRAR *****");
	else if(wrong_guesses==GUESSES)
		printf("\n\n\n\t\tYou lose...\n\n\t\t****** SORRY  U R HANGED ******");
	return 0;
}

   Ta�-ka��t-makas oyununu �al��t�ran �ngilizce program

#define STOP 3
int main() {
	srand(time(NULL));
	int me,comp,score1=0,score2=0;
	char moves[3][10]={"rock","paper","scissors"};
	do {
		printf("Me (%d)  -  Computer (%d)\n1. Rock\n2. Paper\n3. Scissors\nChoose: ",score1,score2);
		scanf("%d",&me);
		while(me<1 || me>3) {
			printf("Please pick a valid move: ");
			scanf("%d",&me);
		}
		comp=rand()%3+1;
		printf("Me: %s  -  Computer: %s\n\n",moves[me-1],moves[comp-1]);
		if(me==comp)
			continue;
		if((me!=1 && me==comp+1) || (me==1 && me==comp-2))
			score1++;
		else
			score2++;
	} while(score1<STOP && score2<STOP);
	if(score1==STOP)
		printf("Congratulations! You are winrar!!!");
	else
		printf("Game over! Better luck next time...");
	return 0;
}

   Ekranda alt�nlar�n 'G', kahraman�n 'H', bo�luklar�n '-' olarak g�sterildi�i, kahraman�n bulundu�u s�tundaki b�t�n alt�nlar� toplay�p yere d��t��� ve
   kahraman�m�z onlar� toplamad��� s�rece havada as�l� duran alt�nlar�n yere d��t��� bilinen yer�ekimine dayal� bir oyunu �al��t�ran �ngilizce program

#define MAX_SIZE 20
int main() {
	int N,M,i,j,gold_count=0,gold_count2=0;
	char gridWorld[MAX_SIZE][MAX_SIZE];
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)
		for(j=0;j<M;j++)
			scanf(" %c",&gridWorld[i][j]);
	
	for(j=0;j<M;j++)
		for(i=0;i<N;i++)
			if(gridWorld[i][j]=='H') {
				gridWorld[i][j]='-';
				for(i=0;i<N;i++)
					if(gridWorld[i][j]=='G') {
						gridWorld[i][j]='-';
						gold_count++;
					}
				gridWorld[N-1][j]='H';
				break;
			}

	for(j=0;j<M;j++)
		for(i=0;i<N;i++) {
			if(gridWorld[N-1][j]=='H')
				break;
			if(gridWorld[i][j]=='G') {
				for(i=0;i<N;i++)
					if(gridWorld[i][j]=='G')
						gold_count2++;
				for(i=0;i<gold_count2;i++)
					gridWorld[N-i-1][j]='G';
				for(i=0;i<N-gold_count2;i++)
					gridWorld[i][j]='-';
				gold_count2=0;
				break;
			}
		}

	printf("\nGold count: %d\n",gold_count);
	for(i=0;i<N;i++) {
		for(j=0;j<M;j++)
			printf("%c ",gridWorld[i][j]);
		printf("\n");
	}
	return 0;
}

   Ekranda oyuncular�n 'C', bo�luklar�n '.' ve '-', hedefin 'o' olarak g�sterildi�i, N*M'lik iki tane tahtada kar��l�kl� oynayan iki ki�inin kendi
   turlar�nda zar at�p at�lan zar kadar yol katederek tahtan�n sonundaki hedefe ula�maya �al��t��� Pac-Man temal� oyunu �al��t�ran �ngilizce program

#define N 5
#define M 5
void print_maze(char maze[N][M]) {
	short i,j;
	for(i=0;i<N;i++) {
		for(j=0;j<M;j++)
			printf("%c ",maze[i][j]);
		printf("\n");
	}
}
void update_maze(short *x_coor, short *y_coor, short dice, char maze[N][M]) {
	if((*y_coor + (*x_coor + dice)/M) < N) {
		short i, x_coor_i, y_coor_i = *y_coor;
		for(i=0;i<=dice;i++) {
			y_coor_i += (*x_coor + i)/M;
			x_coor_i = (*x_coor + i)%M;
			maze[y_coor_i][x_coor_i] = i<dice ? '-' : 'C';
			y_coor_i = *y_coor;
		}
		*y_coor += (*x_coor + dice)/M;
		*x_coor = (*x_coor + dice)%M;
	}
	else
		printf("!!!You can't move your Pac-man, man!!!\n");
}
int main() {
	srand(time(NULL));
	char maze1[N][M] = {{'C','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','o'}};
	char maze2[N][M] = {{'C','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','.'},
						{'.','.','.','.','o'}};
	short x_coor_1=0, y_coor_1=0, x_coor_2=0, y_coor_2=0;
	bool user1_win=false, user2_win=false, flag=false;
	while(!(user1_win || user2_win)) {
		printf("\nUser 1:\n");
		print_maze(maze1);
		printf("\nUser 2:\n");
		print_maze(maze2);
		printf("\nUser %d's turn. Throw the dice (Press d):\n", flag+1);
		char dice=getch();
		while(dice!='d') {
			printf("Throw the dice (Press d):\n");
			dice=getch();
		}
		short rand_num = rand()%6+1;
		printf("The dice number for User %d is: %d\n", flag+1, rand_num);
		if(flag) {
			update_maze(&x_coor_2, &y_coor_2, rand_num, maze2);
			if(y_coor_2==N-1 && x_coor_2==M-1)
				user2_win=true;
		}
		else {
			update_maze(&x_coor_1, &y_coor_1, rand_num, maze1);
			if(y_coor_1==N-1 && x_coor_1==M-1)
				user1_win=true;
		}
		flag = !flag;
	}
	printf("\nUser 1:\n");
	print_maze(maze1);
	printf("\nUser 2:\n");
	print_maze(maze2);
	if(user1_win)
		printf("\n********User 1 wins!********\n");
	else if(user2_win)
		printf("\n********User 2 wins!********\n");
	return 0;
}

   Klavyeden ID'leri, ald�klar� 3 dersin kodlar�, kredileri ve bu derslerden ald�klar� notlar girilen en fazla 10 ��rencinin GPA'lerini (GNO: Genel Not Ortalamas�) hesaplay�p yazd�ran �ngilizce program

struct Course {
	int code;
	int credits;
	double grade;
};
struct Student {
	int ID;
	double GPA;
	struct Course courses[3];	//"Student" struct'� i�inde "courses" array'i ile "Course" struct'�na ait 3 tane nesne olu�turdum
};								//b�ylelikle "Course", "Student"�n sub-structure'� (alt yap�s�) oldu
int main() {
	struct Student students[10];	//"students" array'i ile "Student" struct'�na ait 10 tane nesne olu�turdum
	int i,j,number_of_students,total_credits;	//b�ylelikle 10 tane ��rencim, ��renci ba��na 3 tane olmak �zere toplam 30 tane dersim var
	double total_points;
	printf("Number of students: ");
	scanf("%d",&number_of_students);
	for(i=0;i<number_of_students;i++) {
		printf("Student ID: ");
		scanf("%d",&students[i].ID);
		for(j=0;j<3;j++) {
			printf("Course code, credits, and final grade: ");
			scanf("%d",&students[i].courses[j].code);	//derslerin kodlar� �nemsiz asl�nda, GPA'ya hi�bir katk�s� yok
			scanf("%d",&students[i].courses[j].credits);
			scanf("%lf",&students[i].courses[j].grade);
		}
	}
	for(i=0;i<number_of_students;i++) {
		total_points=0,total_credits=0;
		for(j=0;j<3;j++) {
			total_credits+=students[i].courses[j].credits;
			total_points+=students[i].courses[j].credits*students[i].courses[j].grade;
		}
		students[i].GPA=total_points/total_credits;
	}
	for(i=0;i<number_of_students;i++)
		printf("\nGPA of Student %d: %.4f",students[i].ID,students[i].GPA);
	exit(0);
}

   B�t�n sat�r, s�tun ve k��egenleri boyunca elemanlar�n toplam� sabit olan matrislere sihirli matris denmektedir. Buna g�re, klavyeden girilen 3x3'l�k bir matrisi 1'den 9'a kadar olan rakamlar�n birer kez ge�ti�i
   sihirli bir matrise �evirmek i�in elemanlar�n en az toplamda ne kadar artt�r�l�p azalt�lmas� gerekti�ini yazd�ran �ngilizce program

#define s_rows 3
#define s_columns 3
int formingMagicSquare(int s[s_rows][s_columns]) {
	int magic_mat[8][3][3]={			//3 boyutlu bir dizi, asl�nda nas�l matris 'diziler dizisi' ise bu da 'matrisler dizisi'
	{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
	{{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
	{{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
	{{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
	{{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
	{{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
	{{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
	{{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},	//3x3'l�k b�t�n sihirli matrisler, toplamda 8 tane g�r�ld��� �zere
	}, i,j,k,min_cost=81;
	for(k=0;k<8;k++) {
		int crt_cost=0;					//k iterasyonu girilen matrisi b�t�n olas� sihirli matrislerle k�yaslar
		for(i=0;i<s_rows;i++)
			for(j=0;j<s_columns;j++)
				crt_cost+=abs(s[i][j]-magic_mat[k][i][j]);
		if(crt_cost<min_cost)
			min_cost=crt_cost;
	}
	return min_cost;
}
int main() {
	int i,j,matrix[s_rows][s_columns];
	printf("Enter matrix (3x3): ");
	for(i=0;i<s_rows;i++)
		for(j=0;j<s_columns;j++)
			scanf("%d",&matrix[i][j]);
	int result=formingMagicSquare(matrix);
	printf("Minimum cost: %d",result);
}

   Rastgele sudoku problemleri �reten program */

#define NO_OF_ATTEMPTS 5
short counter=1, numberList[9]={1,2,3,4,5,6,7,8,9};
short truncateToTimes3(const short x) {	return floor(x/3)*3;	}
void shuffleArray(short *array, const short size) {
	short i;
	for(i=0;i<size-1;i++) {
		short j=i+rand()/(RAND_MAX/(size-i)+1),temp=array[j];
		array[j]=array[i];
		array[i]=temp;
	}
}
void printGrid(short grid[9][9]) {
	short row,col;
	for(row=0;row<9;row++) {
		for(col=0;col<9;col++) {
			printf("%hi",grid[row][col]);
			printf(col%3==2 ? " " : "|");
		}
		printf("\n");
		if(row%3!=2)
			for(col=0;col<9;col++) {
				printf("--");
				if(col%3==2)
					printf("\b ");
			}
		printf("\n");
	}
	printf("\n\n");
}
bool checkGrid(short grid[9][9]) {
	short row,col;
	for(row=0;row<9;row++)
		for(col=0;col<9;col++)
			if(grid[row][col]==0)
				return false;
	return true;
}
bool checkRow(short grid[9][9], const short value, const short row) {
	short col;
	for(col=0;col<9;col++)
		if(grid[row][col]==value)
			return false;
	return true;
}
bool checkColumn(short grid[9][9], const short value, const short col) {
	short row;
	for(row=0;row<9;row++)
		if(grid[row][col]==value)
			return false;
	return true;
}
bool checkSquare(const short value, short square[3][3]) {
	short row,col;
	for(row=0;row<3;row++)
		for(col=0;col<3;col++)
			if(square[row][col]==value)
				return false;
	return true;
}
bool solveGrid(short grid[9][9]) {	//bir ��z�m bulunana kadar �al��an backtracking'li recursive fonksiyon
	short i,row,col;
	for(i=0;i<81;i++) {				//sonraki bo� kutuyu bul
		row=i/9,col=i%9;
		if(grid[row][col]==0) {
			short value;
			for(value=1;value<10;value++)
				if(checkRow(grid,value,row))			//value de�erinin bu sat�rda kullan�l�p kullan�lmad���n� kontrol eder
					if(checkColumn(grid,value,col)) {	//value de�erinin bu s�tunda kullan�l�p kullan�lmad���n� kontrol eder
						short square[3][3],R=truncateToTimes3(row),C=truncateToTimes3(col),r,c;		//row ve col koordinatlar�n�n tahtada hangi kareye denk geldi�ini tespit eder
						for(r=R;r<R+3;r++)
							for(c=C;c<C+3;c++)
								square[r-R][c-C]=grid[r][c];
						if(checkSquare(value,square)) {			//value de�erinin bu karede kullan�l�p kullan�lmad���n� kontrol eder
							grid[row][col]=value;
							if(checkGrid(grid)) {
								counter++;
								break;
							}
							else {
								if(solveGrid(grid))
									return true;
							}
						}
					}
			break;
		}
	}
	grid[row][col]=0;
	return false;
}
bool fillGrid(short grid[9][9]) {
	short i,row,col;
	for(i=0;i<81;i++) {
		row=i/9,col=i%9;
		if(grid[row][col]==0) {
			shuffleArray(numberList,9);
			short index;
			for(index=0;index<9;index++) {
				short value=numberList[index];
				if(checkRow(grid,value,row))
					if(checkColumn(grid,value,col)) {
						short square[3][3],R=truncateToTimes3(row),C=truncateToTimes3(col),r,c;
						for(r=R;r<R+3;r++)
							for(c=C;c<C+3;c++)
								square[r-R][c-C]=grid[r][c];
						if(checkSquare(value,square)) {
							grid[row][col]=value;
							if(checkGrid(grid))
								return true;
							else {
								if(fillGrid(grid))
									return true;
							}
						}
					}
			}
			break;
		}
	}
	grid[row][col]=0;
	return false;
}
int main() {
	srand((unsigned int)time(NULL));
	short Grid[9][9]={{0}},attempts=NO_OF_ATTEMPTS;
	fillGrid(Grid);			//tamamen ��z�lm�� bir sudoku d�nd�r�r
	printGrid(Grid);				//tek tek rakamlar� kald�r�r
	while(attempts>0) {				//daha fazla deneme daha fazla rakam� tahtadan siler ve ��z�lmesi daha zor bir sudoku �retir
		short row,col;				//Potentially resulting in more difficiult grids to solve!
		do {				//bo� olmayan rastgele bir kutu se�
			row=rand()%9, col=rand()%9;
		} while(Grid[row][col]==0);
		short backup=Grid[row][col];	//bu kutunun de�erini daha sonra geri koyaca��m�z i�in akl�nda tut
		Grid[row][col]=0;
		short copyGrid[9][9],r,c;		//tahtay� komple kopyala
		for(r=0;r<9;r++)
			for(c=0;c<9;c++)
				copyGrid[r][c]=Grid[r][c];
		counter=0;			//bu tahtan�n ka� tane ��z�m� oldu�unu say
		solveGrid(copyGrid);
		if(counter!=1) {	//e�er ��z�mlerin say�s� 1'den farkl�ysa kutunun eski de�erini geri koy ve de�i�imi iptal et
			Grid[row][col]=backup;
			attempts--;		//burada durabiliriz, ama daha fazla rakam kald�rmak i�in daha fazla denemede de bulunabiliriz
		}
		else
			printGrid(Grid);
	}
	return 0;
}
