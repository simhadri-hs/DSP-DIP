# include<stdio.h>
# include<math.h>	// Required if trigonometric or special math functions are used


void main( )
{
	int x[30],h[30],y[30];
	int i,j,m,n,k, x1;
	printf("Enter the length of the first sequence\n");
	scanf("%d",&m);
	printf("Enter the length of the second sequence\n");
	scanf("%d",&n);
	printf("Enter the first sequence\n");
	for(i=0;i<m;i++)
		scanf("%d",&x[i]);
	printf("Enter the second sequence\n");
	for(j=0;j<n;j++)
		scanf("%d",&h[j]);
	if(m-n!=0)	// checking condition for length of m & n
	{
		if(m>n)
		{
			for(i=n;i<m;i++)	//from nth element of 1st seq zero is padded in 2nd seq
				h[i]=0;	// zero padding in 2nd sequence
			n=m;
		}
		for (i=m; i<n; i++)//from mth ele of 2nd seq zero is padded in 1st seq (executed if n>m)
			x[i]=0;
		m=n;
	}
	for(i=0;i<m;i++)	//for all elements of 1st sequence
	{
		y[i]=0; 	// o/p array is initialized to ZERO
		for(j=0;j<m;j++) 	//Looping for entire length of sequence
		{
			k=(i-j)%m; 	//No. of shift (limiting no. of shifts within max length)
			if(k<0)
				k=k+m;	// Shift index is stored in k
				y[i]=y[i]+h[j]*x[k];	 //Calculating convoluted o/p
		}
		printf ("%d\t", y[i]);
	}
	printf("\nis circular convolution o/p");	//String display
}





