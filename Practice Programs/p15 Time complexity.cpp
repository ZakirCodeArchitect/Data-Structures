
//1. Time complexity : O(1)   or O(2*n-1)				-> n = input size

-> The code has a linear time complexity, meaning the runtime grows linearly with the size of n

sum=0;
for(i=1; i<=2*n;i++)
{
	sum = sum+1;
}


//2. Time complexity : O(n^2)   		->  because the loop iterates n*n times, which is directly proportional to n^2.

-> The code has a quadratic time complexity, meaning the runtime grows quadratically with the size of n.

sum=0;
for(i=1; i<=n*n;i++)
{
	sum = sum+1;
}


//3. Time complexity : O(n) 		-> loop executes n times , regardless of its size.

-> The code has a linear time complexity, meaning the runtime grows linearly with the size of n.

sum=0;
for(i=1; i<=n;i++)
{
	sum = sum+n;
}


//4. Time complexity : O(n^2) or O(n *( n + 1 ) / 2)


->	The code has a quadratic time complexity, meaning the runtime grows quadratically with the size of n.
->	Therefore, the overall time complexity of the provided code snippet is O(n * (n + 1) / 2), which simplifies to O(n^2) when considering the dominant term.
->	This is an arithmetic series, and its sum can be calculated using the formula for the sum of an arithmetic series: n * (n + 1) / 2.

sum=0;
for(i=1;i<=n;i++)
{
	for(j=1;j<=i;j++)
	{
		sum = sum + 1;
	}
}



//5. Time complexity : O(n) 

-> The code has a linear time complexity, meaning the runtime grows linearly with the size of n.

sum=0;
for(i=1;i<=100;i++)		// Since the outer loop executes a constant number of times (100), the time complexity of the outer loop is also O(1).
{
	for(j=1;j<=n;j++)	// Since the number of iterations of the inner loop is determined by n, the time complexity of the inner loop is O(n).
	{
		sum = sum + 1;
	}
}


//6.Time complexity: O(n*log(n))


->	Therefore, the time complexity of the provided code snippet is O(n * log(n)), where n is the input size.
->	The code has a complexity that is between linear (O(n)) and logarithmic (O(log(n))). It grows faster than linear but slower than quadratic.

sum=0;
for(i=1;i<=n;i++)	
{
	for(j=1;j<=n;j*=2)	// Therefore, the time complexity of the inner loop is O(log2(n)).
	{
		sum = sum + 1;
	}
}
