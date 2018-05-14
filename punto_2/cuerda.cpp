#include <iostream>
using std::cout;
using std::endl;
int main()
{
	double x = 0;
	double t = 0;
	double dx = 10;
	double dt = 1;
	int L = 100;
	double t_min = 0;
	double t_max = 200;
	double T = 40;
	double p = 10;
	double r = T*dt*dt/(p*dx*dx);
	double fini = 1.25;
	double fini2 = 5.0;
	double lim = 0.8*L;
	int n = L/dx;
	int N = t_max/dt;
	double *un = new double[n], *uv = new double[n], *up = new double[n];
	for (int i = 0; i < n; i++)
	{ 
		if(x<=lim)
		{
			uv[i] = fini*x/L;
		}
		else
		{
			uv[i] = fini2*(1-(x/L));
		}
		x += dx;
		cout << uv[i] << " " ;
	}
	cout << endl;
	t += dt;
	x = 0;
	for (int i = 0; i < n; i++)
	{
		if (x!=0 && x!=L)
		{
			up[i] = r*(uv[i+1]-2*uv[i]+uv[i-1])/2 + uv[i];
		}
		else
		{
			up[i] = 0;
		}
		x += dx;
	}
	for (int j = 0; j < N; j++)
	{
		x = 0;
		for (int i =0; i < n; i++ )
		{
			if(x!=0 && x!=40)
			{
				un[i] = r*(up[i+1]+up[i-1]) + 2*(1-r)*up[i] - uv[i];
			}
			else 
			{
				un[i] = 0;
			}
			x = i*dx;
			cout <<uv[i] << " ";
		}
		for (int i = 0; i < n; i ++)
		{
			uv[i] = up[i];
			up[i] = un[i];
		}
		t += dt;
		cout<<endl;
	}

	return 0;
}
