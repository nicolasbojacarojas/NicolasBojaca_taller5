#include <iostream>
using std::cout;
using std::endl;

void frontera(float p, float pv, int N, int ran);
void inicial(float p, float pv, int N, int ran, double h, double v0);
void cambio (float p, float pv, int ran);
void actualiza(float p, float pv, int ran);

int main ()
{
	double L = 0;
	double l = 2;
	double d = 1;
	double h = 5/512;
	double v0 = 100;
	int ran = L/h;
	int N = 2*ran*(ran);
	float p[ran][ran];
	float pv[ran][ran];
	float E1[ran][ran];
	double x = 0;
	double y = 0;
	frontera(p, pv, N, ran);
	inicial(p, pv, N, ran, h, v0);
	for (int i = 0; i < N; i ++)
	{
		cambio(p, pv, ran);
		actualiza(p, pv, ran);
	}
	return 0;
} 

void frontera(float p, float pv, int N, int ran)
{
	for (int i = 0; i < ran; i++)
	{
		pv[0][i] = 0.0;
		pv[ran-1][i] = 0.0;
		pv[i][0] = 0.0;
		pv[i][ran-1] = 0.0;
		p[0][i] = 0.0;
		p[ran-1][i] = 0.0;
		p[i][0] = 0.0;
		p[i][ran-1] = 0.0;
	}
}
void inicial(float p, float pv, int N, int ran, double h, double v0)
{
	double x = 0;
	double y = 0;
	for (int i = 0; i < ran; i ++)
	{
		for (int j = 0; j < ran; j++)
		{
			if (x>=1.5 && x <= 3.5 && y > (3.0-h) && y < (3.0+h))
			{
				pv[i][j] = v0/2;
			}
			else if (x>=1.5 && x<=3.5 && y>(2.0-h) && y<(2.0+h))
			{
				pv[i][j] = -v0/2;
			}
			y+=h;
		}
		x+=h;
	}
}
void cambio (float p, float pv, int ran)
{
	for (int i = 0; i < ran; i++)
	{
		for (int j = 0; j < ran; j ++)
		{
			pv[i][j] = p[i][j];
		}
	}
}
void actualiza(float p, float pv, int ran)
{
	double x = 0;
	double y = 0;
	for (int i = 0; i < ran; i ++)
	{
		for (int j = 0; j < ran; j++)
		{
			if (x>=1.5 && x <= 3.5 && y > (3.0-h) && y < (3.0+h))
			{
				p[i][j] = v0/2;
			}
			else if (x>=1.5 && x<=3.5 && y>(2.0-h) && y<(2.0+h))
			{
				p[i][j] = -v0/2;
			}
			else
			{
				p[i][j] = pv[i][j] + 0.5*(pv[i+1][j] + p[i-1][j] + pv[i][j+1] + p[i][j-1]-pv[i][j])
			}
			y+=h;
		}
		x+=h;
	}
}
