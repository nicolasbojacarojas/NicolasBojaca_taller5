#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

double fp1punto(double q1, double q2, double epsilon);
double fp2punto(double q1, double q2, double epsilon);
void imprimir(double *q2, double *p2, int n);

int main()
{
	double t_total = 3000;
	double dt  = 0.006;
	double a = 1/(2.0*pow(2.0, 0.5));
	double epsilon = pow(10.0, -3.0);
	int n = t_total/dt;
	double *q1 = new double[n],* q2 = new double[n], *p1 = new double[n], *p2 = new double[n], *t = new double[n];

	double k11, k12, k13, k14, k21, k22, k23, k24, k31, k32, k33, k34, k41, k42, k43, k44;

	q1[0] = a;
	q2[0] = -a;
	p1[0] = 0;
	p2[0] = 0;

	for (int i = 0; i < (n-1); i++)
	{
		k11 = p1[i]*dt;
		k12 = fp1punto(q1[i], q2[i], epsilon)*dt;
		k13 = p2[i]*dt;
		k14 = fp2punto(q1[i], q2[i], epsilon)*dt;

		k21 = (p1[i] + k12/2)*dt;
		k22 = fp1punto(q1[i] + k11/2, q2[i] + k13/2, epsilon)*dt;
		k23 = (p2[i] + k14/2)*dt;
		k24 = fp2punto(q1[i] + k11/2, q2[i] + k13/2, epsilon)*dt;
		
		k31 = (p1[i] + k22/2)*dt;
		k32 = fp1punto(q1[i] + k21/2, q2[i] + k23/2, epsilon)*dt;
		k33 = (p2[i] + k24/2)*dt;
		k34 = fp2punto(q1[i] + k21/2, q2[i] + k23/2, epsilon)*dt;
	
		k41 = (p1[i] + k32/2)*dt;
		k42 = fp1punto(q1[i] + k31/2, q2[i] + k33/2, epsilon)*dt;
		k43 = (p2[i] + k34/2)*dt;
		k44 = fp2punto(q1[i] + k31/2, q2[i] + k33/2, epsilon)*dt;
		
		q1[i + 1] = (k11 + (2*k21) + (2*k31) + k41)/6;
		q2[i + 1] = (k13 + (2*k23) + (2*k33) + k43)/6;
		p1[i + 1] = (k12 + (2*k22) + (2*k32) + k42)/6;
		p2[i + 1] = (k14 + (2*k24) + (2*k34) + k44)/6; 
	}

	imprimir(q2, p2, n);

	return 0;
}

double fp1punto(double q1, double q2, double epsilon)
{
	double num = -2*q1;
	double den = pow(4*pow(q1,2.0) + (epsilon*epsilon),1.5);
	return num/den;
}

double fp2punto(double q1, double q2, double epsilon)
{
	double num = q1-q2;
	double den = pow(pow(num,2) + ((epsilon*epsilon)/4),1.5);
	double num2 = q1+q2;
	double den2 = pow(pow(num2,2) + ((epsilon*epsilon)/4),1.5);
	return ((num/den) - (num2/den2));
}
void imprimir(double *q2, double *p2, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << q2[i] << " " << p2[i] << endl;
	}
}
