#include<stdio.h>

void conv(int x[], int h[], int m, int n, int y[])
{
	int i, j, k;
	
	if(m - n != 0){
		if(m > n){
			for(i = n;i < m;i++)
				h[i]=0;
			n = m;
		}
		for(i = m; i < n; i++)
			x[i] = 0;
		m = n;
	}
	for(i = 0;i < m;i++){
		y[i] = 0;
		for(j = 0;j < m;j++){
			k = (i - j) % m;
			if(k < 0)
				k = k + m;
				y[i] += h[j]*x[k];
		}
	}
}

void main()
{
	int x[30], x_i[30][30], h[30], y[30][30];
	int i, j, k, Nx, L, M, N;
	
	printf("Enter the length of the first sequence Nx:\n");
	scanf("%d", &Nx);
	
	printf("Enter the length of the second sequence M:\n");
	scanf("%d", &M);
	
	printf("Enter block length L:\n");
	scanf("%d", &L);
	
	printf("Enter the first sequence x(n):\n");
	for(i = 0;i < Nx;i++)
		scanf("%d", &x[i]);

	printf("Enter the second sequence h(n):\n");
	for(j = 0;j < M;j++)
		scanf("%d", &h[j]);
	
	while(Nx % L != 0)
		x[Nx++] = 0;
	for( i = 0; i < Nx; i++)
		printf("%d ", x[i]);
	printf("\n");
	N = L + M - 1;
	k = 0;
	for(i = 0;i < Nx / L;i++){
		for(j = 0;j < N;j++){
			if(j < L)
				x_i[i][j] = x[k++];
			else
				x_i[i][j] = 0;
			printf("%d\t", x_i[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	for(i = 0;i < Nx / L;i++)
		conv(x_i[i], h, N, M, y[i]);
	for(i = 0;i < Nx / L;i++){
		for(j = 0;j < N;j++)
			printf("%d\t", y[i][j]);
		printf("\n");
	}
	for(i = 0;i < Nx / L;i++)
		for(j = 0;j < M - 1;j++)
			y[i+1][j] += y[i][L + j];
	printf("\n");
	for(i = 0;i < Nx / L;i++){
		for(j = 0;j < N;j++){
			if (i != (Nx / L - 1) && (j == L))
				break;
			else
				printf("%d\t", y[i][j]);
		}
	}
}


