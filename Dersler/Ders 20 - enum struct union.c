#include <stdio.h>
#include <stdlib.h>

/* "enum: enumerations , numaraland�rmalar"
   numaraland�rmalar kod karma�as�n� �nlemek ve kod okunurlu�unu art�rmak i�in bir s�r� int de�i�keninin bir araya gelmesiyle olu�turulmu� bir yap�d�r
   �u ana kadarki di�er fonksiyon ve yap�lar�n aksine enum yap�s� "int main() { }" kal�b�n�n d���na yaz�l�r
   genel syntax'� enum enum_ad� a� s�sl� parantez de�erler kapa s�sl� parantez ==> enum enum_adi { degiskenadi1,degiskenadi2,degiskenadi3 };   (if,else,while,for,switch case,... aksine sonuna ";" konmal�)
   enum i�erisine yaz�lan de�erler default olarak int de�i�keni kabul edilir
   enum i�erisindeki de�i�kenlere de�er verilmezse, de�erler default olarak 0'dan ba�lar ve bir bir artar   (nas�l "int a"da a'ya de�er atamazsan, bilgisayar onu default olarak 0 al�r)

enum sehirler
{
	hatali,Adana,Adiyaman,Afyon,Agri,Aksaray,Amasya,Ankara,Antalya,Ardahan,Artvin,Aydin,Balikesir,Bartin,Batman
};

int main() {
	enum sehirler il1,il2,il3;
	il1=Ankara;
	il2=Ardahan;
	il3=Batman;
	printf("Ankara alfabetik siralamada %d. il\n",il1);
	printf("Ardahan alfabetik siralamada %d. il\n",il2);
	printf("Batman alfabetik siralamada %d. il\n",il3);
}


   "struct: structure , yap�"
   t�pk� enum gibi birden �ok de�i�kenin bir araya getirilmesiyle olu�turulan yeni birime "structure" (yap�) ad� verilir
   yap�lar ayn� enum gibi "int main() { }" kal�b�n�n d���na yaz�l�r ve genel syntax'� ise a�a��daki gibidir:
   struct struct_adi {
   degiskenturu1 degiskenadi1;
   degiskenturu2 degiskenadi2;
   degiskenturu3 degiskenadi3;
   };							enum'un aksine de�i�kenler int olmak zorunda de�ildir, b�t�n de�i�ken t�rleri struct'�n i�ine yaz�labilir

struct kitapbilgi
{
	char kitapad[20],yazar[20];
	int fiyat;
	float puan;
};

int main() {
	struct kitapbilgi kb={"Seker Portakali","Vasconcelos",10,7.25};		//kitapbilgi adl� struct'a ait kb adl� bir nesne olu�turdum
	printf("Kitap Adi: %s\n",kb.kitapad);
	printf("Yazar: %s\n",kb.yazar);
	printf("Fiyat: %d TL\n",kb.fiyat);
	printf("Puan: %.2f/10",kb.puan);
}


struct kayit {
	char ad[50];
	int no,sinif;
	float ort;
};

int main() {
	struct kayit ogr;
	printf("Ad Soyad: ");
	gets(ogr.ad);
	printf("Ogrenci No: ");
	scanf("%d",&ogr.no);
	printf("Sinifi: ");
	scanf("%d",&ogr.sinif);
	printf("Donem Sonu Ortalamasi: ");
	scanf("%f",&ogr.ort);
	printf("\n\n%s\n%d\n%d\n%.4f",ogr.ad,ogr.no,ogr.sinif,ogr.ort);
	return 0;
}

   nested structure'lar� (i� i�e yap�) da bir inceleyelim
   nas�l �ok boyutlu dizilerde bir boyut i�eri girmek i�in yeni s�sl� parantez a��l�yorsa i� i�e yap�larda da bir i�erideki yap�ya eri�mek i�in yeni s�sl� parantez a��l�r

struct Adres {
	char sehir[20];
	char semt[20];
	int kapiNo;
};
struct Employee {
	int id;
	int maas;
	char isim[30];
	char departman[30];
	struct Adres adresim;
};
void showInfo(struct Employee emp) {
	printf("***** %s *****\nID: %d\nMaas: %d TL\nDepartman: %s\nSehir: %s\nSemt: %s\nKapi No: %d\n\n", emp.isim, emp.id, emp.maas, emp.departman, emp.adresim.sehir, emp.adresim.semt, emp.adresim.kapiNo);
}
int main() {
	struct Employee Ertugrul={3169,2500,"Ertugrul Tatli","temizlik isleri",{"Istanbul","Bebek",16}};
	struct Employee Aras={1337,100000,"Prof. Dr. Aras Gungore","CEO",{"Los Angeles","Hollywood",2}};
	showInfo(Ertugrul);
	showInfo(Aras);
}

   "union: bile�im"
   union'lar, struct ve enum'dan farks�z olarak main fonksiyonunun d���nda tan�mlan�rlar ve genel syntax'lar� struct'�nki ile ayn�d�r:
   union union_adi {
   degiskenturu1 degiskenadi1;
   degiskenturu2 degiskenadi2;
   degiskenturu3 degiskenadi3;
   };
   union'lar ayn� i�lem sat�rlar�nda bahsi ge�en de�i�kenler d���nda kalan de�erleri istendi�i �ekilde ekrana yazmaz
   ��nk� ayn� bile�im i�inde yer alan de�i�kenlerden ayn� anda sadece bir tanesi ayr�lan bellek b�lgesini kullanabilir

union yunyon1 {
	int id1;
	double dd1;
	char cd1;
} ud1;		//yunyon1 adl� union'a ait ud1 diye bir nesne olu�turdum

int main() {
	ud1.id1=21;
	ud1.cd1='A';
	printf("%d %c\n", ud1.id1, ud1.cd1);	//sadece 'A' karakterini iki belirte�te de g�stermeye �al���r,   "65 A"
	ud1.id1=120;
	printf("%d %c\n", ud1.id1, ud1.cd1);	//sadece 120 de�erini iki belirte�te de g�stermeye �al���r,   "120 x"
	ud1.dd1=34.75;
	printf("%d %.2f", ud1.id1, ud1.dd1);	//sadece 34.75 de�erini iki belirte�te de g�stermeye �al���r,   "0 34.75"
}

   "data alignment: verileri s�ralamak"     "padding: doldurma"
   yap� i�inde yer alan her bir eleman yap� boyutuna kendi boyutu kadar (veya daha fazla) ekleme yaparken bile�im i�indeki elemanlar bile�im boyutuna ekleme yapmaz
   bile�imin boyutu, bile�im i�inde yer alan en b�y�k boyuta sahip eleman�n boyutuna e�ittir
   ilaveten, yap�m�z farkl� veri t�rlerinden olu�uyorsa yap�m�z�n boyutu genellikle verilerin boyutlar� toplam�ndan daha fazlad�r
   ��nk� compiler yap�daki verileri belle�e kaydederken bu verileri s�ralamak (data alignment) i�in bellek adresleri aras�na bo� g�zler (byte) koyar, bu olaya padding (doldurma) ad� verilir */

struct yap1 {
	int id1;
	int id2;
	int id3;	//sizeof(int)=4			id1,id2:	 xxxx,xxxx,
	double dd1;	//sizeof(double)=8		id3: 		 xxxx,0000,		4 byte doldurma
	char cd1;	//sizeof(char)=1		dd1:		 xxxxxxxx,
	char cd2;	//						cd1,cd2,cd3: x,x,x,00000	5 byte doldurma
	char cd3;
} yd1;	//Yap� boyutu=8+8+8+8="32"

union bir1 {
	int id1;
	int id2;
	int id3;
	double dd1;
	char cd1;
	char cd2;
	char cd3;
} bd1;	//Bile�im boyutu: sizeof(double)="8"

int main() {
	printf("Yapi boyutu: %d\nBilesim boyutu: %d",sizeof(yd1),sizeof(bd1));
	return 0;	//sizeof(struct yap1) ve sizeof(union bir1) de yaz�labilirdi
}
