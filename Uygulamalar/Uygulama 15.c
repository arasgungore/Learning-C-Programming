#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/* Ýskambil kaðýtlarýnda 4 tane simge {D,C,S,H} ve 13 tane sayý {2,3,4,5,6,7,8,9,T,J,Q,K,A}
   vardýr. Bir iskambil oyununda masada bir tane kaðýt ve elinde de 5 tane kaðýt bulunmaktadýr.
   Kiþi masadaki kaðýtla ayný simgeye veya sayýya sahipse elini oynayabildiðine ve klavyeden
   char ikilisi olarak simge-sayý biçiminde kaðýtlar girildiðine göre kiþinin elini oynayýp
   oynayamadýðýný yazdýran Ýngilizce program

typedef struct {
	char rank,suit;
} card;
int main() {
	card c1,c2[5];
	printf("Enter the card on the deck: ");
	scanf("%c%c",&c1.rank,&c1.suit);
	printf("Enter the cards on your hand: ");
	int i;
	for(i=0;i<5;i++) {		//boþluk býrakýldýðýnda c2[i].rank'e kaydetmeyip unutmasý için
		scanf("%*c%c%c",&c2[i].rank,&c2[i].suit);
		if(c1.rank==c2[i].rank || c1.suit==c2[i].suit) {
			printf("You can play the card %c%c from your hand.",c2[i].rank,c2[i].suit);
			return 0;
		}
	}
	printf("You cannot play any card, tough luck.");
	return 0;
}

   x ve y koordinatlarý klavyeden girilen N tane noktadan birbirinden en uzak iki noktayý bulup
   bu noktalarý ve aralarýndaki uzaklýðý yazdýran Ýngilizce program

typedef struct {
	double x,y;
} Point_t;
double distance(Point_t p1, Point_t p2) {
	return sqrt( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
int main() {
	int i,j,N;
	printf("Enter the number of points: ");
	scanf("%d",&N);
	Point_t *pArr = (Point_t*) malloc(N * sizeof(Point_t));
	for(i=0;i<N;i++) {
		printf("Point %d: ",i+1);
		scanf("%lf %lf", &pArr[i].x, &pArr[i].y);
	}
	Point_t p1=pArr[0], p2=pArr[1];
	double max_dist=distance(p1,p2);
	for(i=0;i<N-1;i++)
		for(j=i+1;j<N;j++)
			if(distance(pArr[i],pArr[j]) > max_dist) {
				max_dist=distance(pArr[i],pArr[j]);
				p1=pArr[i];
				p2=pArr[j];
			}
	printf("Point 1: %lf %lf\nPoint 2: %lf %lf\nDistance between these two: %lf"
	, p1.x, p1.y, p2.x, p2.y, max_dist);
}

   Klavyeden sol alt köþesi ve sað alt köþesinin koordinatlarý girilen dikdörtgeni x ve y
   eksenlerine göre ötelersek bu dikdörtgenin tüm köþelerinin yeni koordinatlarýný nested
   structure kullanarak yazdýran Ýngilizce program

typedef struct {
	double x,y;
} Point_t;
typedef struct {
	Point_t LowerLeft,UpperRight;
} Rect_t;
void moveRectangle(Rect_t *r, double moveX, double moveY) {	//call by reference
	r->LowerLeft.x+=moveX, r->LowerLeft.y+=moveY;			//"(*r). ..." = "r-> ..."
	r->UpperRight.x+=moveX, r->UpperRight.y+=moveY;
}
int main() {
	Rect_t rec;
	printf("Enter the lower left and upper right point of the rectangle (x1, y1, x2, y2): ");
	scanf("%lf %lf %lf %lf", &rec.LowerLeft.x, &rec.LowerLeft.y, &rec.UpperRight.x, &rec.UpperRight.y);
	double moveX, moveY;
	printf("Enter how much you want to move the rectangle in the x and y axes: ");
	scanf("%lf %lf", &moveX, &moveY);
	moveRectangle(&rec,moveX,moveY);
	printf("Resulting Rectangle:\nLower Left Point: %lf %lf\nLower Right Point: %lf %lf"
	"\nUpper Left Point: %lf %lf\nUpper Right Point: %lf %lf"
	, rec.LowerLeft.x, rec.LowerLeft.y, rec.UpperRight.x, rec.LowerLeft.y
	, rec.LowerLeft.x, rec.UpperRight.y, rec.UpperRight.x, rec.UpperRight.y);
}

   Klavyeden uçuþ numarasý, kalkýþ yeri, iniþ yeri, kalkýþ saati ve iniþ saati rastgele
   sýralamada girilen uçuþlarý kalkýþ saatleri ve kalktýðý havaalaný kodlarýna göre
   organize edip yazdýran Ýngilizce program

typedef struct {
	int flight_no;
	float start,arrival;
	char org[4],dst[4];
} Flight_t;
bool compare_flights(Flight_t f1, Flight_t f2) {
	if(f1.start > f2.start) return true;				//if (f1>f2) => return true
	else if(f1.start < f2.start) return false;			//if (f1==f2 || f1<f2) => return false
	else if(strcmp(f1.org,f2.org) > 0) return true;
	return false;
}
int main() {
	int i,j,N;
	printf("Enter the number of flights: ");
	scanf("%d",&N);
	Flight_t *flights = (Flight_t*) malloc(N * sizeof(Flight_t));
	for(i=0;i<N;i++) {
		printf("Enter the %d. flight (Flight number, Originating airport code (three characters),"
		"Destination airport code (three characters), Starting time, Arrival time): ",i+1);
		scanf("%d %s %s %f %f", &flights[i].flight_no, flights[i].org
		, flights[i].dst, &flights[i].start, &flights[i].arrival);
	}
	for(i=0;i<N;i++)
		for(j=0;j<N-1-i;j++)					//bubble sort
			if(compare_flights(flights[j], flights[j+1])) {
				Flight_t temp=flights[j];		//klasik swap
				flights[j]=flights[j+1];
				flights[j+1]=temp;
			}
	printf("\n\n\nOrganized flight sequence:\n");
	for(i=0;i<N;i++)
		printf("Flight %d : %d %s %s %.2f %.2f\n", i+1, flights[i].flight_no, flights[i].org
		, flights[i].dst, flights[i].start, flights[i].arrival);
	return 0;
}

   Maksimum 9 kiþinin yer aldýðý 3 aile arasýndan en fakir ailenin en çok kazanan
   ferdinin yaþýný yazdýran Ýngilizce program

#define MAX 1000000
struct Person {
	int age,salary;
};
struct Family {
	struct Person members[9];	//ailelerin her biri maksimum 9 bireyden oluþuyor
	int memberCount;			//ailede gerçekte kaç kiþi bulunduðu	(memberCount<9)
};
int richest_in_poorest(struct Family f[], int size) {
	int i,j, leastTotalSalary=MAX, poorestFamilyIndex, richestSalary=-1, richestMemberIndex;
	for(i=0;i<size;i++) {
		int familyTotalSalary=0;
		for(j=0;j<f[i].memberCount;j++)
			familyTotalSalary += f[i].members[j].salary;
		if(familyTotalSalary < leastTotalSalary) {		//en fakir aileyi bul
			leastTotalSalary=familyTotalSalary;
			poorestFamilyIndex=i;		//en fakir ailenin index'i belli
		}
	}
	for(i=0;i<f[poorestFamilyIndex].memberCount;i++)	//en fakir ailedeki en yaðlý kiþiyi bul
		if(f[poorestFamilyIndex].members[i].salary > richestSalary) {
			richestSalary=f[poorestFamilyIndex].members[i].salary;
			richestMemberIndex=i;		//en kodaman kiþinin index'i belli
		}
	return f[poorestFamilyIndex].members[richestMemberIndex].age;
}
int main() {
	struct Family families[3];
	int i,j;
	for(i=0;i<3;i++) {
		printf("Enter the number of people in family %d: ",i+1);
		scanf("%d",&families[i].memberCount);
		for(j=0;j<families[i].memberCount;j++) {
			printf("Enter the age and salary of the person %d in family %d:",i+1,j+1);
			scanf("%d%d", &families[i].members[j].age, &families[i].members[j].salary);
		}
	}
	printf("\n\nRichest person in the poorest family is %d years old."
	, richest_in_poorest(families,3));
	return 0;
}

   Klavyeden girilen menü ve bu menüden sipariþ eden müþterinin toplam ne kadar hesap ödeyeceðini
   yazdýran, menüde bulunmayan sipariþler içinse 5-20 arasýnda rastgele fiyatlar atayan Ýngilizce program

#define SIZE 20
#define MENU_SIZE 5

typedef struct Beverage {
	char name[SIZE];
	double price;
} beverage;

typedef struct Order {
	beverage beverage_orders[SIZE];
	double total_price;
	int nr_of_beverages;
} order;

double random_price_generator(int x, int y) {
	return ((y-x) * rand() / (double)RAND_MAX) + x;		//x ve y arasýnda rastgele bir ondalýk sayý döndürür
}

void print_beverage(beverage b) {
	printf("%s : %.2lf\n", b.name, b.price);
}

void print_order(order o) {
	int i;
	for(i=0;i<o.nr_of_beverages;i++)
		print_beverage(o.beverage_orders[i]);
	printf("_____________________\n");
	printf("Total Price = %.2lf\n", o.total_price);
}

void record_prices_to_order(beverage menu[], order *order) {
	int i,j;
	bool flag=false;
	double sum=0;
	for(i=0;i<order->nr_of_beverages;i++)
		for(j=0;j<MENU_SIZE;j++)
			if(strcmp(menu[j].name, order->beverage_orders[i].name)==0) {
				sum += order->beverage_orders[i].price = menu[j].price;
				break;
			}
			else if(j==MENU_SIZE-1) {
				printf("%s isn't on the menu...\n", order->beverage_orders[i].name);
				printf("But I can get it for you for a low price of %lf.\n"
				, order->beverage_orders[i].price = random_price_generator(5,20));
				flag=true;
			}
	order->total_price = sum;
	if(flag)
		printf("\n\n");
}

int main() {
	srand(time(NULL));
	beverage cafe_menu[SIZE];
	char buf[100];
	int i;

	printf("_____Record Cafe Menu_____\n");
	for(i=0;i<MENU_SIZE;i++) {
		fgets(buf,100,stdin);
		sscanf(buf,"%s %lf", cafe_menu[i].name, &cafe_menu[i].price);
	}
	printf("\n\n");

	printf("_____Take order from the customer_____\n");
	printf("Enter the total number of beverages: ");
	order customer;
	scanf("%d", &customer.nr_of_beverages);
	printf("Enter the names of these beverages: ");
	for(i=0;i<customer.nr_of_beverages;i++)
		scanf("%s", customer.beverage_orders[i].name);
	printf("\n\n");

	record_prices_to_order(cafe_menu, &customer);
	print_order(customer);
	return 0;
}

   4 kiþilik bir aileden rastgele bir kiþinin ismi seçilip o kiþinin kendi/annesinin/babasýnýn/kýz kardeþinin/erkek kardeþinin/kýz çocuðunun/erkek çocuðunun yaþý/ismi sorgulanacaktýr.
   Bu aile üyelerinin her birinin kendi ve yakýn akrabalarýnýn kimlik no'larý ve yaþlarý veri tabanýnda kayýtlý olduðuna göre, yukarýdaki sorgulamalarý cevaplayan Ýngilizce program

#define FAM_SIZE 4
struct family_member {
	int id, age, mother_id, father_id, brother_id, sister_id, daughter_id, son_id;
	char name[20];
};
int main() {
	int i,j;
//	struct family_member mem1={1, 56, 0, 0, 0, 0, 4, 3, "Hande"};					//member.id = index+1
//	struct family_member mem2={2, 55, 0, 0, 0, 0, 4, 3, "Rifat"};
//	struct family_member mem3={3, 17, 1, 2, 0, 4, 0, 0, "Ahmet"};
//	struct family_member mem4={4, 22, 1, 2, 3, 0, 0, 0, "Elif"};
//	struct family_member family[FAM_SIZE]={mem1, mem2, mem3, mem4};
	struct family_member family[FAM_SIZE]={ {1, 56, 0, 0, 0, 0, 4, 3, "Hande"},
											{2, 55, 0, 0, 0, 0, 4, 3, "Rifat"},
											{3, 17, 1, 2, 0, 4, 0, 0, "Ahmet"},
											{4, 22, 1, 2, 3, 0, 0, 0, "Elif"} };
	printf( "The family database is created.\n\n"
			"We have %d members in the family:\n",FAM_SIZE);
	for(i=0;i<FAM_SIZE;i++)
		printf("%s\n",family[i].name);
	printf( "\nYou can form a question about a family member from the following keywords:\n"
			" age _   _  self\n"
			"      | |_  mother\n"
			"      | |_  father\n"
			"      | |_  sister\n"
			"       &\n"
			"      | |_  brother\n"
			"      | |_  daughter\n"
			"name _| |_  son\n"
			"\ne.g. \"age&self\", \"name&sister\", \"age&son\", ...\n"
			"\nYou can also type \"quit\" to quit instead.");
	char name[20];
	while(true) {
		printf("\n\nType the name of the family member you want to ask questions about: ");
		scanf("%s",name);
		for(i=0; i<FAM_SIZE && strcmp(name,family[i].name)!=0; i++);
		if(i==FAM_SIZE) {
			if(strcmp(name,"quit")!=0) {
				printf("There is no one in this family named %s.",name);
				continue;
			}
			else {
				printf("Ciao!");
				exit(0);
			}
		}
		char question[20], q1[10], q2[10];
		printf("Type your question here: ");
		scanf("%s",question);
		for(j=0;question[j]!='&' && question[j]!='\0';j++)
			q1[j]=question[j];
		q1[j]='\0';
		for(j++;question[j]!='\0';j++)
			q2[j-strlen(q1)-1]=question[j];
		q2[j-strlen(q1)-1]='\0';
		if(strcmp(q1,"age")==0) {
			if(strcmp(q2,"self")==0)
				printf("Age of %s is %d.", family[i].name, family[i].age);
			else if(strcmp(q2,"mother")==0)
				printf(family[i].mother_id!=0 ? "Age of %s's mother is %d." : "Information does not exist in the database.", family[i].name, family[family[i].mother_id-1].age);
			else if(strcmp(q2,"father")==0)
				printf(family[i].father_id!=0 ? "Age of %s's father is %d." : "Information does not exist in the database.", family[i].name, family[family[i].father_id-1].age);
			else if(strcmp(q2,"sister")==0)
				printf(family[i].sister_id!=0 ? "Age of %s's sister is %d." : "Information does not exist in the database.", family[i].name, family[family[i].sister_id-1].age);
			else if(strcmp(q2,"brother")==0)
				printf(family[i].brother_id!=0 ? "Age of %s's brother is %d." : "Information does not exist in the database.", family[i].name, family[family[i].brother_id-1].age);
			else if(strcmp(q2,"daughter")==0)
				printf(family[i].daughter_id!=0 ? "Age of %s's daughter is %d." : "Information does not exist in the database.", family[i].name, family[family[i].daughter_id-1].age);
			else if(strcmp(q2,"son")==0)
				printf(family[i].son_id!=0 ? "Age of %s's son is %d." : "Information does not exist in the database.", family[i].name, family[family[i].son_id-1].age);
			else
				printf("Invalid question.");
		}
		else if(strcmp(q1,"name")==0) {
			if(strcmp(q2,"self")==0)
				printf("Name of %s is %s. (duh)", family[i].name, family[i].name);
			else if(strcmp(q2,"mother")==0)
				printf(family[i].mother_id!=0 ? "Name of %s's mother is %s." : "Information does not exist in the database.", family[i].name, family[family[i].mother_id-1].name);
			else if(strcmp(q2,"father")==0)
				printf(family[i].father_id!=0 ? "Name of %s's father is %s." : "Information does not exist in the database.", family[i].name, family[family[i].father_id-1].name);
			else if(strcmp(q2,"sister")==0)
				printf(family[i].sister_id!=0 ? "Name of %s's sister is %s." : "Information does not exist in the database.", family[i].name, family[family[i].sister_id-1].name);
			else if(strcmp(q2,"brother")==0)
				printf(family[i].brother_id!=0 ? "Name of %s's brother is %s." : "Information does not exist in the database.", family[i].name, family[family[i].brother_id-1].name);
			else if(strcmp(q2,"daughter")==0)
				printf(family[i].daughter_id!=0 ? "Name of %s's daughter is %s." : "Information does not exist in the database.", family[i].name, family[family[i].daughter_id-1].name);
			else if(strcmp(q2,"son")==0)
				printf(family[i].son_id!=0 ? "Name of %s's son is %s." : "Information does not exist in the database.", family[i].name, family[family[i].son_id-1].name);
			else
				printf("Invalid question.");
		}
		else
			printf("Invalid question.");
	}
}

   Klavyeden girilen þehirler, bu þehirlere ait postaneler ve bu postanelere ait paketler için postaneler arasý paket transferi yapabilen ve en çok paketi olan postaneyi
   ve ismi verilen þehrin postane-paket þemasýný yazdýran, nested structure'lardan faydalanan Ýngilizce program */

#define MAX_STRING_LENGTH 20

typedef struct {
	char* id;
	unsigned int weight;
} Package;

typedef struct {
	unsigned int min_weight, max_weight, packages_count;
	Package* packages;
} Post_Office;

typedef struct {
	char* name;
	Post_Office* offices;
	unsigned int offices_count;
} Town;

void print_all_packages(Town t) {
	printf("%s:\n", t.name);
	unsigned int i,j;
	for(i=0;i<t.offices_count;i++) {
		printf("\t%u:\n",i+1);
		for(j=0;j<t.offices[i].packages_count;j++)
			printf("\t\t%s\n", t.offices[i].packages[j].id);
	}	//bir þehrin postanelerindeki paketlerin ID'lerini þema halinde yazdýrýr
}
bool is_movable(Post_Office po, unsigned int w) {
	return (w>=po.min_weight && w<=po.max_weight);
}	//paket aðýrlýðý ait olduðu postanenin aðýrlýk limitleri arasýnda mý diye kontrol ediyor
void send_all_acceptable_packages(Town *s, unsigned int si, Town *t, unsigned int ti) {	//si: source index, ti: target index
	unsigned int i,j;
	si--,ti--;	//asýl bilgisayar index'leri bir eksik, ondan düþürüyorum
	for(i=0;i<s->offices[si].packages_count;)	//kaynak postanenin bütün paketlerini tarar
		if(is_movable(t->offices[ti], s->offices[si].packages[i].weight)) {	//gönderilecek paketin hedef postanenin aðýrlýk limitleri arasýnda olup olmadýðýný kontrol eder
			unsigned int *tp = &t->offices[ti].packages_count, *sp = &s->offices[si].packages_count;		//isimler çok uzun, tekrar yazmamak için pointer kullanýp ifade ettim o yüzden
			t->offices[ti].packages = (Package*) realloc(t->offices[ti].packages, (++(*tp)) * sizeof(Package));	//postaneye yeni paket eklendiði için realloc zamaný, paket kapasitesi bir arttýrýldý
			t->offices[ti].packages[*tp-1] = s->offices[si].packages[i];	//ve paket son index'in olduðu yere eklendi
			(*sp)--;	//öte yandan kaynak postanenin paket kapasitesi bir azaltýldý
			for(j=i;j<*sp;j++)
				s->offices[si].packages[j] = s->offices[si].packages[j+1];	//left shift yapýp paketleri bir sola kaydýrýyor
			s->offices[si].packages = (Package*) realloc(s->offices[si].packages, (*sp) * sizeof(Package));	//tabii postaneden bir paket eksildiði için yeniden realloc zamaný
		}		//kýsaca package_count deðiþkeni deðiþtiði sürece realloc yapmak RAM'i gereksiz yere iþgal etmemi engeller
		else
			i++;	//eðer gönderilecek paket hedef postanenin aðýrlýk limitleri arasýnda deðilse, bir sonraki pakete geç ve onu göndermeyi dene
}
Town town_with_most_packages(Town *towns, unsigned int towns_count) {
	unsigned int max=0,r=0,i,j;
	for(i=0;i<towns_count;i++) {
		unsigned int packages_count=0;
		for(j=0;j<towns[i].offices_count;j++)
			packages_count += towns[i].offices[j].packages_count;
		if(packages_count>max) {
			max=packages_count;
			r=i;
		}
	}
	return towns[r];
}
/*
Town *find_town(Town *towns, unsigned int towns_count, char *name) {
	unsigned int i;
	for(i=0;i<towns_count;i++)
		if(!strcmp(name,towns[i].name))
			return &towns[i];	//linear search, þehir isminden hareketle þehir struct'ýný döndürüyor
	printf("Town not found!\n");
	return NULL;
}
*/
Town *find_town(Town *towns, unsigned int l, unsigned int r, char *name) {
	if(r>=l) {
		unsigned int mid = l + (r-l)/2;
		if(strcmp(towns[mid].name,name)==0)
			return &towns[mid];
		else if(strcmp(towns[mid].name,name)>0)
			return find_town(towns, l, mid-1, name);
		return find_town(towns, mid+1, r, name);
	}		//binary search, yukarýda yoruma alýnan fonksiyonla ayný iþlevi yapýyor ama daha etkili ;)
	printf("Town not found!\n");
	return NULL;
}
int main() {
	unsigned int towns_count,i,j,k,queries;
	printf("Enter the number of towns in the country: ");
	scanf("%u", &towns_count);
	Town* towns = malloc(towns_count * sizeof(Town));
	for(i=0;i<towns_count;i++) {
		towns[i].name = malloc(MAX_STRING_LENGTH*sizeof(char));
		printf("Enter the %u. town's name and post office count: ", i+1);
		scanf("%s %u", towns[i].name, &towns[i].offices_count);
		towns[i].offices = malloc(towns[i].offices_count * sizeof(Post_Office));
		for(j=0;j<towns[i].offices_count;j++) {
			printf("Enter the %u. post office's package count, min and max weight limits in %u. town: ", j+1, i+1);
			scanf("%u %u %u", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(towns[i].offices[j].packages_count * sizeof(Package));
			for(k=0;k<towns[i].offices[j].packages_count;k++) {
				towns[i].offices[j].packages[k].id = malloc(MAX_STRING_LENGTH*sizeof(char));
				printf("Enter the %u. package id and weight in %u. post office of %u. town: ", k+1, j+1, i+1);
				scanf("%s %u", towns[i].offices[j].packages[k].id, &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	printf("Enter number of queries: ");
	scanf("%u", &queries);
	char town_name[MAX_STRING_LENGTH];
	while(queries--) {
		unsigned int type;
		printf("Enter query type (1=>find town, 2=>send package, 3=>most packages): ");
		scanf("%u", &type);
		switch(type) {
			case 1: {
				printf("Enter town name: ");
				scanf("%s", town_name);
//				Town* t = find_town(towns,towns_count,town_name);
				Town* t = find_town(towns,0,towns_count-1,town_name);
				print_all_packages(*t);
				break;
			}
			case 2: {
				unsigned int source_index, target_index;
				printf("Enter source town name and post office index: ");
				scanf("%s %u", town_name, &source_index);
//				Town* source = find_town(towns,towns_count,town_name);
				Town* source = find_town(towns,0,towns_count-1,town_name);
				printf("Enter target town name and post office index: ");
				scanf("%s %u", town_name, &target_index);
//				Town* target = find_town(towns,towns_count,town_name);
				Town* target = find_town(towns,0,towns_count-1,town_name);
				send_all_acceptable_packages(source,source_index,target,target_index);
				break;
			}
			case 3:
				printf("Town with the most number of packages is %s.\n", town_with_most_packages(towns,towns_count).name);
		}
	}
	return 0;
}
