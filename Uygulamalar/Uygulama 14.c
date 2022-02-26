#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/* Bir dizinin bütün permütasyonlarýný backtracking yaparak yazdýran iterative-recursive program		Klavyeden girilen kullanýcý adlarýný veri tabanýna kaydeden ve veri tabanýnda önceden kayýtlý her kullanýcý adý
																										için "kullanici_adi1", "kullanici_adi2", "kullanici_adi3", ... biçiminde alternatifler sunan Ýngilizce program
void swap(int *a, int *b) {
	int temp=*a;																						int main() {
	*a=*b;																									int n,i,j;
	*b=temp;																								printf("Enter number of usernames: ");
}																											scanf("%d\n",&n);
void print_array(int *array, int n) {																		int *counter=(int*) malloc(n*sizeof(int));
	int i;																									for(i=0;i<n;i++) counter[i]=0;
	for(i=0;i<n;i++)																						char usernames[n][40], database[n][40];
		printf("%d ",array[i]);																				printf("Enter a username: ");
	printf("\n");																							strcpy(database[0], gets(usernames[0]));
}																											printf("This username is unique and OK.\n");
void permute(int *array, int l, int r) {	//Uygulama 4'te beteri var, kombinasyon O_o						for(i=1;i<n;i++) {
	int i;																										printf("Enter an username: ");
	if(l==r)																									strcpy(database[i], gets(usernames[i]));
		print_array(array,r+1);																					for(j=0;j<i;j++)
	else																											if(strcmp(database[j],database[i])==0) {
		for(i=l;i<=r;i++) {																								printf("This username is already taken, how about: %s%d\n", database[j], ++counter[j]);
			swap(array+l,array+i);		//&array[l] = &(*(array+l)) = array+l											i--, n--;
			permute(array,l+1,r);																						break;
			swap(array+l,array+i);		//backtracking																}
		}																											else if(j==i-1) printf("This username is unique and OK.\n");
}																											}
int main() {																							}
	srand(time(0));
	int some_numbers[5]={6,9,42,17,58};
	permute(some_numbers,0,4);
	printf("\n\n\n");
	int random_array_size=rand()%5+4,i;	//4-8		daha fazlasý çoook zaman alýr
	int *random_array=(int*) malloc(random_array_size*sizeof(int));
	for(i=0;i<random_array_size;i++)
		*(random_array+i)=rand()%300+1;	//1-300
	permute(random_array,0,random_array_size-1);
	return 0;
}

   Sunucunun mevcut doluluk oraný %50'nin üstüne çýkarsa bir uyarý mesajý, %80'in üstüne çýkarsa ayrý bir
   uyarý mesajý, %100'e ulaþýrsa sunucuyu boþaltýp ilgili mesajý yazdýran program

void CheckServerCapacity(unsigned short *server_occupancy) {
	static bool flag1=true, flag2=true, flag3=true;
	if(*server_occupancy==100) {
		if(flag1) {
			printf( "Server capacity is full."
					"\nUnloading server...");
			*server_occupancy=0;
			flag1=flag2=flag3=true;
		}
	}
	else if(*server_occupancy>80) {
		if(flag2) {
			printf( "!!!Warning!!!"
					"\nServer occupancy is over 80.");
			flag2=false;
			flag1=flag3=true;
		}
	}	
	else if(*server_occupancy>50) {
		if(flag3) {
			printf( "!!!Warning!!!"
					"\nServer occupancy is over 50.");
			flag3=false;
			flag1=flag2=true;
		}
	}
}
int main() {
	unsigned short current_server_occupancy;
	while(true) {
		printf("Enter server occupancy %%: ");
		scanf("%hu",&current_server_occupancy);
		if(current_server_occupancy>100)
			current_server_occupancy=100;
		CheckServerCapacity(&current_server_occupancy);
		printf("\n\n\n");
	}
}

   Klavyeden girilen polinomlarýn belirli integrallerini hesaplayan Ýngilizce program

long double IntegralCalculator(char* equation, double a, double b) {
	long double upperIntegral=0,lowerIntegral=0;
	int factor = ('0'<=*equation && *equation<='9') || ((*equation=='+' || *equation=='-') && *(equation+1)!='x') ? atoi(equation) : (*equation=='x' || *equation=='+' ? 1 : -1);
	while(*equation!='\0') {
		while(*(equation-1)!='^' && *equation!='+' && *equation!='-' && *equation!='\0')
			equation++;
		if(*(equation-1)=='^' || *(equation-1)=='x') {
			int exponent = *(equation-1)=='^' ? atoi(equation)+1 : 2;
			lowerIntegral += exponent==0 ? factor*log(fabs(a)) : factor*pow(a,exponent)/exponent;
			upperIntegral += exponent==0 ? factor*log(fabs(b)) : factor*pow(b,exponent)/exponent;
			if(*equation=='-')
				equation++;
			while(*equation!='+' && *equation!='-' && *equation!='\0')
				equation++;
		}
		else {
			lowerIntegral += factor*a;
			upperIntegral += factor*b;
		}
		factor = *(equation+1)!='x' ? atoi(equation) : (*equation=='+' ? 1 : -1);
		if(*equation=='+' || *equation=='-')
			equation++;
	}
	return upperIntegral - lowerIntegral;
}
int main() {
	while(1) {
		char equation[1000];
		double a,b;
		printf("Enter an equation: ");
		scanf("%s",equation);
		printf("Enter the lower and upper bounds (from ... to ...): ");
		scanf("%lf %lf",&a,&b);
		printf("\n*****Definite integral*****");
		long double definiteIntegral=IntegralCalculator(equation,a,b);
//		printf("Integral: %.15f\n\n\n",(double)IntegralCalculator(equation,a,b));		"long double"ý print'lemek için printf fonksiyonunun MinGW implementasyonu lazým
		__mingw_printf("\nFull value: %Lf",definiteIntegral);			//"#define printf __mingw_printf" ön iþlemci komutuyla da kodda default olarak MinGW'nin printf fonksiyonu kullanýlabilir
		__mingw_printf("\nApproximation: %Le\n\n\n\n",definiteIntegral);
	}
}

   Bir kere bile küçüktür/büyüktür operatörlerini kullanmadan küçüktür/büyüktür operatörlerinin RAM'de binary olarak
   saklanan sayýlara yaptýðý bitsel iþlemlerden hareketle klavyeden girilen sayýlarý kýyaslayan Ýngilizce program

void take2scomplement(char* binary) {
	int i;
	for(i=0;i!=32;i++)
		binary[i] = binary[i]=='0' ? '1' : '0';
	for(i=i-1;binary[i]=='1';i--)
		binary[i]='0';
	binary[i]='1';
}
char* convertDecimalToBinary(int num) {
	char *binary=(char*) malloc(32*sizeof(char));
	int i,original_num=num;
	for(i=0;i!=32;i++)
		binary[i]='0';
	for(i=i-1;num;i--) {
		binary[i]=num%2+'0';
		num/=2;
	}
	if(original_num!=abs(original_num))
		take2scomplement(binary);
	return binary;
}
int convertBinaryToDecimal(char* binary) {
	int num=0,i;
	for(i=0;i!=32;i++)
		num+=(binary[i]-'0')*pow(2,31-i);
	return num;
}
void compare(char* binary1, char* binary2) {
	int i=0;
	for(i=0;binary1[i]==binary2[i];i++);
	printf( binary1[0]==binary2[0] ?

			( i<32 ?
			( (binary1[i]-'0') && !(binary2[i]-'0') ? "%d is greater than %d.  (%d>%d)" : "%d is less than %d.  (%d<%d)")
			: "%d is equal to %d.  (%d=%d)")

			: ( binary1[0]-'0' ? "%d is less than %d.  (%d<%d)" : "%d is greater than %d.  (%d>%d)")

			, convertBinaryToDecimal(binary1), convertBinaryToDecimal(binary2), convertBinaryToDecimal(binary1), convertBinaryToDecimal(binary2) );
}
int main() {
	while(1) {
		int x,y;
		printf("Enter two numbers: "),
		scanf("%d%d",&x,&y);
		char *binaryX=convertDecimalToBinary(x), *binaryY=convertDecimalToBinary(y);
		printf("%d in Binary: %s\n%d in Binary: %s\n",x,binaryX,y,binaryY);
		compare(binaryX,binaryY);
		printf("\n\n\n");
	}
}

   Klavyeden 9*9'luk matris olarak girilen bir sudoku tablosunun doðru olup olmadýðýný kontrol eden Ýngilizce program

void getSudokuTable(unsigned short table[9][9]) {
	puts("Please enter your sudoku table below:");
	unsigned short i,j;
	for(i=0;i<9;i++)
		for(j=0;j<9;j++) {
			printf("Enter the %hu. row: ",i+1);
			scanf("%hu",&table[i][j]);
		}
}
bool checkSubgrid(unsigned short table[9][9], unsigned short row, unsigned short col) {
	unsigned short i,j, counter[9]={0};
	for(i=row;i<row+3;i++)
		for(j=col;j<col+3;j++)
			if(++counter[table[i][j]-1]>1)
				return false;
	return true;
}
bool sudokuChecker(unsigned short table[9][9]) {
	unsigned short i,j;
	for(i=0;i<9;i++) {		//satýrlarý kontrol et
		unsigned short counter[9]={0};		//eðer aþýrýya gidip 1-9 aralýðý yerine bütün sayýlar için kýyaslamak istesem dizi boyutunu USHRT_MAX yapabilirim
		for(j=0;j<9;j++)
			if(++counter[table[i][j]-1]>1) {
				printf("The %hu. row doesn't match.\n",i+1);
				return false;
			}
	}
	for(j=0;j<9;j++) {		//sütunlarý kontrol et
		unsigned short counter[9]={0};
		for(i=0;i<9;i++)
			if(++counter[table[i][j]-1]>1) {
				printf("The %hu. column doesn't match.\n",j+1);
				return false;
			}
	}
	for(i=0;i<9;i+=3)		//3*3'lük ýzgaralarý kontrol et
		for(j=0;j<9;j+=3)
			if(!checkSubgrid(table,i,j)) {
				printf("The %hu. subgrid doesn't match.\n",i+j/3+1);
				return false;
			}
	return true;
}
int main() {
	unsigned short s[9][9];
	getSudokuTable(s);
	puts(sudokuChecker(s) ? "This sudoku table is valid." : "This sudoku table is invalid.");
	return 0;
}

   Klavyeden 8*8'lik bir sayý matrisi olarak girilen satranç tablosunda sadece bir beyaz þah ve rastgele sayýda siyah filler yer alacaktýr.
   Beyaz þah 1, siyah filler 7 rakamýyla gösterileceðine göre, bu durumda þahýn mat olup olmadýðýný yazdýran Ýngilizce program

#define KING 1
#define BISHOP 7
#define TABLE_SIZE 8
void get_table(short table[TABLE_SIZE][TABLE_SIZE]) {
	puts("Enter the table below:\n");
	short i,j;
	for(i=0;i<TABLE_SIZE;i++)
		for(j=0;j<TABLE_SIZE;j++)
			scanf("%hi",&table[i][j]);
}
void find_king(short table[TABLE_SIZE][TABLE_SIZE], short *kingR, short *kingC) {
	short i,j;
	for(i=0;i<TABLE_SIZE;i++)
		for(j=0;j<TABLE_SIZE;j++)
			if(table[i][j]==KING) {
				*kingR=i, *kingC=j;
				return;
			}
	puts("\n\nThere is no king.");
	exit(1);
}
bool is_location_valid(const short r, const short c) {
	return (r>=0 && r<=TABLE_SIZE-1 && c>=0 && c<=TABLE_SIZE-1);
}
bool is_bishop_attack(short table[TABLE_SIZE][TABLE_SIZE], const short r, const short c) {
	short i,j;
	for(i=r-1, j=c+1; i>=0 && j<=TABLE_SIZE-1; i--, j++)
		if(table[i][j]==BISHOP)
			return true;
	for(i=r+1, j=c-1; i<=TABLE_SIZE-1 && j>=0; i++, j--)
		if(table[i][j]==BISHOP)
			return true;
	for(i=r+1, j=c+1; i<=TABLE_SIZE-1 && j<=TABLE_SIZE-1; i++, j++)
		if(table[i][j]==BISHOP)
			return true;
	for(i=r-1, j=c-1; i>=0 && j>=0; i--, j--)
		if(table[i][j]==BISHOP)
			return true;
	return false;
}
void is_checkmate(short table[TABLE_SIZE][TABLE_SIZE], const short kingR, const short kingC) {
	short i,j;
	for(i=-1;i<=1;i++)
		for(j=-1;j<=1;j++) {
			short r=kingR+i, c=kingC+j;
			if(is_location_valid(r,c))
				if(!is_bishop_attack(table,r,c)) {
					puts("\n\nNo Checkmate.");
					return;
				}
		}
	puts("\n\nCheckmate!");
}
int main() {
	short table[TABLE_SIZE][TABLE_SIZE], kingR, kingC;
	get_table(table);
	find_king(table,&kingR,&kingC);
	is_checkmate(table,kingR,kingC);
	exit(0);
}

   Tek, ikili ve üçlü belirli integrallerin sonucunu sayýsal entegrasyon (numerical integration) metoduyla hesaplayan Ýngilizce program */

double fun(double x) {
	return 5*pow(x,3)+7*x-9*log(2*x+1)-3;		//integrali alýnacak f(x) fonksiyonu
}
double gun(double x, double y) {
	return pow(y,5)*pow(x,3)-atan(x*y);			//integrali alýnacak g(x,y) fonksiyonu
}
double sumIntegral(double lowerBound, unsigned long long n, double dx, double (*foo)(double x)) {
	double cumSum=0, xi=lowerBound;
	unsigned long long i;
	for(i=0;i<n;i++, xi+=dx)			//a: lowerBound, b: upperBound
		cumSum+=foo(xi);				//dx=(b-a)/n, xi=a+i*dx ==>  integral = f(x0)*dx + f(x1)*dx + f(x2)*dx + ... + f(x(n-1))*dx = (f(x0) + f(x1) + f(x2) + ... + f(x(n-1)))*dx = sigma(f(xi))*dx
	return cumSum*dx;					//Riemann toplamý iþte
}
double sumDoubleIntegral(double lowerBound1, double lowerBound2, unsigned long long n, double dy, double (*foo)(double x)) {
	double cumBigSum=0, xi=lowerBound2, dx=(lowerBound1-lowerBound2)/n;
	unsigned long long i,j;
	for(i=0;i<n;i++, xi=lowerBound2, dx+=dy/n) {
		double cumSmallSum=0;			//y1: lowerBound1, y2: upperBound1, x1: lowerBound2, y: upperBound2
		for(j=0;j<n;j++, xi+=dx)		//dy=(y2-y1)/n, yi=y1+i*dy, dxi=(yi-x1)/n ==>  integral = (f(x0) + f(x1) + f(x2) + ... + f(x(n-1)))0*dx0*dy +
			cumSmallSum+=foo(xi);																//(f(x0) + f(x1) + f(x2) + ... + f(x(n-1)))1*dx1*dy +
		cumBigSum+=cumSmallSum*dx;														//...  +  (f(x0) + f(x1) + f(x2) + ... + f(x(n-1)))(n-1)*dx(n-1)*dy =
	}																							//sigma(f(xi))*sigma(dxi)*dy
	return cumBigSum*dy;				//yi=lowerBound1, repeat(dx=(yi-lowerBound2)/n, yi+=dy)  ==>  dx=(lowerBound1-lowerBound2)/n, repeat(dx+=dy/n)
}
double sumTripleIntegral(double lowerBound1, double lowerBound2, double lowerBound3, unsigned long long n, double dz, double (*foo)(double x, double y)) {
	double cumTotalSum=0, yi=lowerBound2, xi=lowerBound3, dy=(lowerBound1-lowerBound2)/n, dx=(lowerBound2-lowerBound3)/n;
	unsigned long long i,j,k;
	for(i=0;i<n;i++, yi=lowerBound2, dy+=dz/n) {	//dz=(z2-z1)/n, zi=z1+i*dz, dyi=(zi-y1)/n, yi=y1+i*dyi, dxi=(yi-x1)/n, xi=x1+i*dxi
		double cumBigSum=0;
		for(j=0;j<n;j++, yi+=dy, xi=lowerBound3, dx+=dy/n) {
			double cumSmallSum=0;
			for(k=0;k<n;k++, xi+=dx)
				cumSmallSum+=foo(xi,yi);
			cumBigSum+=cumSmallSum*dx;
		}
		cumTotalSum+=cumBigSum*dy;
		dx-=dy;			//"dx=(lowerBound2-lowerBound3)/n;" ile ayný
	}
	return cumTotalSum*dz;
}
int main() {
	double lowerBound=4.23, upperBound=11.5;
	unsigned long long n, nMax=pow(2,25);
	printf("y=f(x)=5*x^3+7*x-9*ln(2*x+1)-3\n\nIntegral of f(x)dx from x=%g to x=%g is...\n\n",lowerBound,upperBound);
	for(n=1;n<=nMax;n*=2) {
		double dx=(upperBound-lowerBound)/n;
		printf("%.11f for n=%I64u\n",sumIntegral(lowerBound,n,dx,fun),n);		//zamanla accuracy (kesinlik) artýyor ama her adýmdan sonra iþlem 2 kat daha uzun sürüyor
	}
	nMax=pow(2,13);
	double lowerBound1=2.3, upperBound1=5.1, lowerBound2=9.89;
	printf("\n\nIntegral of f(x)dxdy from y=%g to y=%g, x=%g to x=y is...\n\n",lowerBound1,upperBound1,lowerBound2);
	for(n=1;n<=nMax;n*=2) {
		double dy=(upperBound1-lowerBound1)/n;
		printf("%.11f for n=%I64u\n",sumDoubleIntegral(lowerBound1,lowerBound2,n,dy,fun),n);	//zamanla accuracy (kesinlik) artýyor ama her adýmdan sonra iþlem 4 kat daha uzun sürüyor
	}
	double a=-69.420,b=M_PI,c=sqrt(2),d=sqrt(3);
	nMax=pow(2,9);
	printf("\n\nz=g(x,y)=y^5*x^3-arctan(x*y)\n\nIntegral of g(x,y)dxdydz from z=%g to z=%g, y=%g to y=z, x=%g to x=y is...\n\n",a,b,c,d);
	for(n=1;n<=nMax;n*=2) {
		double dz=(b-a)/n;
		printf("%.11f for n=%I64u\n",sumTripleIntegral(a,c,d,n,dz,gun),n);		//zamanla accuracy (kesinlik) artýyor ama her adýmdan sonra iþlem 8 kat daha uzun sürüyor
	}
	return 0;
}
