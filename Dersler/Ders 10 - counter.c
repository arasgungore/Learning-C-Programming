#include <stdio.h>
#include <stdlib.h>

/* "counter: saya�"				"sayac" ad�nda bir de�i�ken tan�mlay�p bunu for d�ng�s�n�n i�ine sokaca��z
																																																		//	i	saya�
int main() {																																															// N/A	0
																																																		//	1	1
	int sayac,i;																																														//	2	2
	sayac=0;																																															//	3	6
	for(i=1;i<=10;i++)																																													//	4	10
	{																																																	//	5	15
		sayac=sayac+i;         //Misal sayac=sayac+2 olsa "20" yazd�r�rd� ��nk� her bir i=1,2,3,...,10 de�eri i�in saya� 2 ile toplan�yor, ve 10 defa 2 ile toplanaca�� i�in sayac=0+10*2="20"			//	6	21
	}																																																	//	7	28
	printf("Sayac: %d",sayac); //S�rayla her bir i=1,2,3,...,10 de�eri i�in saya� de�i�keni i ile toplan�yor ve sayac�n de�eri tekrar atan�yor, dolay�s�yla sayac=0+1+2+3+4+...+10="55" yazd�racak		//	8	36
																																																		//	9	45
	return 0;																																															//	10	55
}
																//	i	fuck
int main() {													// N/A	 1
	int i,x;													//	1	 1
	int fuck=1;													//	2	 2
	printf("Faktoriyeli Al�nacak Sayiyi Giriniz: ");			//	3	 6
	scanf("%d",&x);												//	4	 24
	for(i=1;i<=x;i++) {											//	5	 120
		fuck=fuck*i;											//	6	 720
	}
	printf("\n%d sayisinin faktoriyeli %d'dir",x,fuck);			//0 i�in de do�ru sonucu veriyor, ��nk� for komutunu atl�yor ve fuck=1 olarak atand���ndan direkt onu giriyor
}

int main() {																		int main() {
	int a,i,x;																			int i,x,toplam;
	a=1;																				toplam=0;
	printf("1,5,9,...,(4n+1) dizisinin kacinci elemanini bulalim?: ");					printf("S=1+5+9+...+(4n+1) serisini kacinci elemanina kadar toplayalim?: ");
	scanf("%d",&x);																		scanf("%d",&x);
	for(i=1;i<=x-1;i++) {																for(i=0;i<=x-1;i++) {
	a=a+4;																					toplam=toplam+4*i+1;
	}																					}
	printf("Sonucunuz: %d",a);															printf("Seri toplami: %d",toplam);
}																					}

   Fibonacci dizisini de yazd�ral�m o zaman */

int main() {

	int a,b,c,i,x;																																												//	a	b	c
	a=b=1;																																														//	1	1	2
	printf("Fibonacci dizisinin ilk kac terimini gormek istersiniz?: ");																														//	1	2	3
	scanf("%d",&x);																																												//	2	3	5
	printf("%d\n%d\n",a,b);    //if yap�s�n� kullanmad���m i�in x=0 ve x=1 de�erleri i�in de ilk iki terimimiz olan a=1 ve b=1 daima yazd�r�lacak, di�er x de�erleri i�in s�k�nt� yok			//	3	5	8
	for(i=1;i<=x-2;i++) {																																										//	5	8	13
		c=a+b;																																													//	8	13	21
		a=b;
		b=c;
		printf("%d\n",c);
	}
	return 0;
}
