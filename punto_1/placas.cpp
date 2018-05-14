#include <iostream>
using std::cout;
using std::endl;

int main ()
{
	double h = 5/512;
	double v0 = 100;
	double L = 5;
	int ran = L/h;
	int N = 2*ran*ran;
	float p[ran][ran];
	float pv[ran][ran];
	float E1[ran][ran];
	float E2[ran][ran];
	double l = 2;	
	double d = 1;
	double x = 0;
	double y = 0;
	for (int i = 0; i < ran; i++)
	{
		pv[i][ran-1] = 0.0;
		p[0][i] = 0.0;
		pv[0][i] = 0.0;
		p[i][ran-1] = 0.0;
		pv[ran-1][i] = 0.0;
		p[ran-1][i] = 0.0;
		p[i][0] = 0.0;
		pv[i][0] = 0.0;
	}


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
			y += h;
		}
		x += h;
	}

	for (int k = 0; k < 1000; k++)
	{

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
					p[i][j] = pv[i][j] + 0.5*(pv[i+1][j] + p[i-1][j] + pv[i][j+1] + p[i][j-1]-pv[i][j]);
				}
				y+=h;
			}
			x+=h;
		}

		for (int i = 0; i < ran; i++)
		{
			for (int j = 0; j < ran; j ++)
			{
				pv[i][j] = p[i][j];
			}
		}
	}


	for(int i = 0; i < ran; i++)
	{
		for (int j = 0; j < ran; j ++)
		{
			E1[i][j] = -(p[i+1][j]-p[i][j])/h;
			E2[i][j] = -(p[i][j+1]-p[i][j])/h;
		}

	}

	for (int i = 0; i < ran; i ++)
	{
		for(int j = 0; j < ran; j++)
		{
			cout << p[i][j] << " " << E2[i][j] << " " << E1[i][j] << endl;
		}
	}
	return 0;
} 

