#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Recursion ile virgülden sonraki 10 basamaða kadar doðru n. dereceden kök ve logaritma hesaplayan program

#define abs(x) ((x)<0 ? -(x) : (x))
#define EPS 1e-10
double power(double base, int exp) {
	if(exp == 0)		return 1.0;
	double temp = power(base, exp/2);
	if(exp%2) {
		if(exp>0)		return base * temp * temp;
		return temp * temp / base;
	}
	return temp * temp;
}
double nthRoot(double num, int n, double l, double r) {
	double avg = (l+r)/2.0, pow_avg = power(avg, n);
	if(abs(pow_avg - num) < EPS)	return avg;
	else if(pow_avg > num)			return nthRoot(num, n, l, avg);
	return nthRoot(num, n, avg, r);
}
double logarithm(double num, int n, double l, double r) {
	double avg = (l+r)/2.0, pow_avg = pow(n, avg);
	if(abs(pow_avg - num) < EPS)	return avg;
	else if(pow_avg > num)			return logarithm(num, n, l, avg);
	return logarithm(num, n, avg, r);
}

int main() {
	double i;
	for(i=1;i<=100;i++) {
		printf("Square root of %g:\t\t%.11g\n", i, nthRoot(i, 2, 0, i+1));
		printf("Cubic root of %g:\t\t%.11g\n", i, nthRoot(i, 3, 0, i+1));
		printf("Logarithm base 10 of %g:\t%.11g\n\n", i, logarithm(i, 10, 0, i+1));
	}
	return 0;
}

   CDF (Cumulative Distribution Function) ile herhangi bir ortalama MC speedrunner'ýn ender pearl ve blaze rod drop'larýnýn gerçekleþme olasýlýðýný hesaplayan program

long double factorial(unsigned int num) {
	long double prod = 1.0;
	for(;num>1;prod*=num, --num);
	return prod;
}
long double permutation(const unsigned int n, const unsigned int r) {	return factorial(n) / factorial(n-r);	}
//	unsigned int i;		long double prod = 1.0;
//	for(i=1;i<=r;prod*=n, --n, ++i);
//	return prod;
//}
long double combination(const unsigned int n, const unsigned int r) {	return permutation(n, r) / factorial(r);	}
//	unsigned int i;		long double prod = 1.0;
//	for(i=1;i<=r;prod*=n, prod/=i, --n, ++i);
//	return prod;
//}
long double binomialDistribution(const unsigned int k, const unsigned int n, const double p) {	return combination(n, k) * pow(p, k) * pow(1.0 - p, n - k);	}
long double cumulativeDistribution(const unsigned int k, const unsigned int n, const double p) {
	unsigned int i;		long double sum = 0.0;
	for(i=k;i<=n;sum+=binomialDistribution(i++, n, p));
	return sum;
}
//long double cumulativeCumulativeDistribution(const unsigned int k, const unsigned int n, const double p) {
//	unsigned int i;		long double sum = 0.0;
//	for(i=k;i<=n;sum+=cumulativeDistribution(k, i++, p));
//	return sum;
//}
int main() {
	const unsigned int pearl_drops = 2,		total_trades = 4;			const double pearl_drop_rate = 0.0473;		// 42/262 ender pearl trades with %4.73 chance each
	const unsigned int blazerod_drops = 8,	total_blaze_kills = 10;		const double blazerod_drop_rate = 0.5;		// 211/305 blaze rod drops with %50 chance each
	const long double pearls_P = cumulativeDistribution(pearl_drops, total_trades, pearl_drop_rate),
					  rods_P = cumulativeDistribution(blazerod_drops, total_blaze_kills, blazerod_drop_rate), overall_P = pearls_P * rods_P;
	__mingw_printf("P(pearls: %u out of %u)\t=\t%.6Lg\t(aka 1 in a %llu)\n", pearl_drops, total_trades, pearls_P, (unsigned long long)round(1.0/pearls_P));
	__mingw_printf("P(rods: %u out of %u)\t=\t%.6Lg\t(aka 1 in a %llu)\n", blazerod_drops, total_blaze_kills, rods_P, (unsigned long long)round(1.0/rods_P));
	__mingw_printf("P(pearls>=%u && rods>=%u)\t=\t%.8Lg\t(aka 1 in a %.3Lg)\n", pearl_drops, blazerod_drops, overall_P, 1.0/overall_P);
	return 0;
}

   Özel üçgenleri, baþka bir deyiþle bütün kenarlarý tam sayý olan dik üçgenleri yazdýran program */

unsigned int getMin(const unsigned int *num1, const unsigned int *num2) {	return *num1 < *num2 ? *num1 : *num2;	}
unsigned int getGCD(unsigned int num1, unsigned int num2) {		//(const unsigned int *num1, const unsigned int *num2) ... aka EBOB
//	unsigned int i;
//	for(i = getMin(num1, num2);i;--i)	if(!(*num1 % i || *num2 % i))	return i;

//	while(num1 != num2) {
//		if(num1 > num2)	num1 -= num2;
//		else			num2 -= num1;
//	}
//	return num1;

	if(!num1)	return num2;
	if(!num2)	return num1;
	const unsigned short shift = __builtin_ctz(num1 | num2);
	num1 >>= __builtin_ctz(num1);
	do {
		num2 >>= __builtin_ctz(num2);
		if(num1 > num2) {
			unsigned int temp = num2;
			num2 = num1;
			num1 = temp;
		}
		num2 -= num1;
	} while(num2);
	return num1 << shift;
}
unsigned short isPrime(const unsigned int *num) {
	unsigned int i;	const unsigned int sqrt_num = sqrt(*num);
	for(i=2;i<=sqrt_num;++i)	if(!(*num % i))		return 0;
	return 1;
}
unsigned short areCoprime(const unsigned int *num1, const unsigned int *num2) {	return getGCD(*num1, *num2) == 1;	}	//aka aralarýnda asal
double getTimeTakenInSeconds(void (*fun)(const unsigned int*), const unsigned int *param) {
	clock_t t = clock();
	(*fun)(param);
	t = clock() - t;
	return (double)t / CLOCKS_PER_SEC;
}
void PythagoreanTriplesAras(const unsigned int *limit) {
	unsigned int a, b, c;
	for(c=2;c<*limit;++c)
		for(b=1;b<c;++b) {			//a^2 + b^2 = c^2, a^2 = c^2 - b^2 = (c - b)*(c + b)
			const double k1 = c-b, k2 = c+b, k3 = sqrt(k1*k2);
			a = k3;
			if(a > b)				continue;
			if(!areCoprime(&a, &b))	continue;
			if(fabs((double)a - k3) < 1e-3)		printf("a = %u, b = %u, c = %u\n", a, b, c);
		}
}
void PythagoreanTriplesGeeks(const unsigned int *limit) {
	unsigned int a, b, c, m, n, m_sqr, n_sqr;
	for(m=2;c<*limit;++m) {
		m_sqr = m*m;
		for(n=1;n<m;++n) {
			n_sqr = n*n;
			a = m_sqr - n_sqr;		//a = m*m - n*n
			b = 2*m*n;
			c = m_sqr + n_sqr;		//c = m*m + n*n
			if(c > *limit)			break;
			if(!areCoprime(&a, &b))	continue;
			if(a > b)	printf("a = %u, b = %u, c = %u\n", b, a, c);
			else		printf("a = %u, b = %u, c = %u\n", a, b, c);
		}
	}
}
int main() {
	unsigned int limit1 = 8000, limit2 = 50000;		double time_taken;
	time_taken = getTimeTakenInSeconds(&PythagoreanTriplesAras, &limit1);
	printf("My solution took %.3f seconds to execute...\n\n", time_taken);
	puts("--------------------------\n");
	time_taken = getTimeTakenInSeconds(&PythagoreanTriplesGeeks, &limit2);
	printf("GeeksForGeeks solution took %.3f seconds to execute...\n", time_taken);
	return 0;
}
