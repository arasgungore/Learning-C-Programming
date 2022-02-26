#include <stdio.h>
#include <stdlib.h>

/* "enum: enumerations , numaralandýrmalar"
   numaralandýrmalar kod karmaþasýný önlemek ve kod okunurluðunu artýrmak için bir sürü int deðiþkeninin bir araya gelmesiyle oluþturulmuþ bir yapýdýr
   þu ana kadarki diðer fonksiyon ve yapýlarýn aksine enum yapýsý "int main() { }" kalýbýnýn dýþýna yazýlýr
   genel syntax'ý enum enum_adý aç süslü parantez deðerler kapa süslü parantez ==> enum enum_adi { degiskenadi1,degiskenadi2,degiskenadi3 };   (if,else,while,for,switch case,... aksine sonuna ";" konmalý)
   enum içerisine yazýlan deðerler default olarak int deðiþkeni kabul edilir
   enum içerisindeki deðiþkenlere deðer verilmezse, deðerler default olarak 0'dan baþlar ve bir bir artar   (nasýl "int a"da a'ya deðer atamazsan, bilgisayar onu default olarak 0 alýr)

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


   "struct: structure , yapý"
   týpký enum gibi birden çok deðiþkenin bir araya getirilmesiyle oluþturulan yeni birime "structure" (yapý) adý verilir
   yapýlar ayný enum gibi "int main() { }" kalýbýnýn dýþýna yazýlýr ve genel syntax'ý ise aþaðýdaki gibidir:
   struct struct_adi {
   degiskenturu1 degiskenadi1;
   degiskenturu2 degiskenadi2;
   degiskenturu3 degiskenadi3;
   };							enum'un aksine deðiþkenler int olmak zorunda deðildir, bütün deðiþken türleri struct'ýn içine yazýlabilir

struct kitapbilgi
{
	char kitapad[20],yazar[20];
	int fiyat;
	float puan;
};

int main() {
	struct kitapbilgi kb={"Seker Portakali","Vasconcelos",10,7.25};		//kitapbilgi adlý struct'a ait kb adlý bir nesne oluþturdum
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

   nested structure'larý (iç içe yapý) da bir inceleyelim
   nasýl çok boyutlu dizilerde bir boyut içeri girmek için yeni süslü parantez açýlýyorsa iç içe yapýlarda da bir içerideki yapýya eriþmek için yeni süslü parantez açýlýr

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

   "union: bileþim"
   union'lar, struct ve enum'dan farksýz olarak main fonksiyonunun dýþýnda tanýmlanýrlar ve genel syntax'larý struct'ýnki ile aynýdýr:
   union union_adi {
   degiskenturu1 degiskenadi1;
   degiskenturu2 degiskenadi2;
   degiskenturu3 degiskenadi3;
   };
   union'lar ayný iþlem satýrlarýnda bahsi geçen deðiþkenler dýþýnda kalan deðerleri istendiði þekilde ekrana yazmaz
   çünkü ayný bileþim içinde yer alan deðiþkenlerden ayný anda sadece bir tanesi ayrýlan bellek bölgesini kullanabilir

union yunyon1 {
	int id1;
	double dd1;
	char cd1;
} ud1;		//yunyon1 adlý union'a ait ud1 diye bir nesne oluþturdum

int main() {
	ud1.id1=21;
	ud1.cd1='A';
	printf("%d %c\n", ud1.id1, ud1.cd1);	//sadece 'A' karakterini iki belirteçte de göstermeye çalýþýr,   "65 A"
	ud1.id1=120;
	printf("%d %c\n", ud1.id1, ud1.cd1);	//sadece 120 deðerini iki belirteçte de göstermeye çalýþýr,   "120 x"
	ud1.dd1=34.75;
	printf("%d %.2f", ud1.id1, ud1.dd1);	//sadece 34.75 deðerini iki belirteçte de göstermeye çalýþýr,   "0 34.75"
}

   "data alignment: verileri sýralamak"     "padding: doldurma"
   yapý içinde yer alan her bir eleman yapý boyutuna kendi boyutu kadar (veya daha fazla) ekleme yaparken bileþim içindeki elemanlar bileþim boyutuna ekleme yapmaz
   bileþimin boyutu, bileþim içinde yer alan en büyük boyuta sahip elemanýn boyutuna eþittir
   ilaveten, yapýmýz farklý veri türlerinden oluþuyorsa yapýmýzýn boyutu genellikle verilerin boyutlarý toplamýndan daha fazladýr
   çünkü compiler yapýdaki verileri belleðe kaydederken bu verileri sýralamak (data alignment) için bellek adresleri arasýna boþ gözler (byte) koyar, bu olaya padding (doldurma) adý verilir */

struct yap1 {
	int id1;
	int id2;
	int id3;	//sizeof(int)=4			id1,id2:	 xxxx,xxxx,
	double dd1;	//sizeof(double)=8		id3: 		 xxxx,0000,		4 byte doldurma
	char cd1;	//sizeof(char)=1		dd1:		 xxxxxxxx,
	char cd2;	//						cd1,cd2,cd3: x,x,x,00000	5 byte doldurma
	char cd3;
} yd1;	//Yapý boyutu=8+8+8+8="32"

union bir1 {
	int id1;
	int id2;
	int id3;
	double dd1;
	char cd1;
	char cd2;
	char cd3;
} bd1;	//Bileþim boyutu: sizeof(double)="8"

int main() {
	printf("Yapi boyutu: %d\nBilesim boyutu: %d",sizeof(yd1),sizeof(bd1));
	return 0;	//sizeof(struct yap1) ve sizeof(union bir1) de yazýlabilirdi
}
