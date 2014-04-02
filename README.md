CS165P1
=======

Private project repo for john lin and christ schlacta to solve the following problem:

Implement a subroutine doalg( n, k ) to do the following
	Initialize a private array of n random distinctly-valued elements (indexed from 1 to n) by invoking COMPARE( 0, n )
	Compare the two array elements at indices x and y by invoking COMPARE( x, y )
	Find the indices of the array elements that have the k largest values, in descending value order, by using a sequence of COMPARE() instructions, and store the k indices in an integer array Best[]
		For example, for n=7 and k=3,  if the private array (indexed from 1 to 7) contains the values: 3,5,4,7,2,6,1  then the integer array Best[] (indexed from 1 to 3) should hold: 4,6,2
	NOTE: This requires a careful design of an efficient algorithm.
	Check that Best[] does indeed contain the largest k array element indices in the correct order by invoking COMPARE( -1, k, Best[] ) which returns the number of element comparisons performed (the number of previous COMPARE invocations) if Best[] is correct or returns a negative value if there were any errors
	Your doalg() routine should be capable of handling values of n up to 10,000 and values of k up to 500
Implement a main routine with the following characteristics
	Call the doalg( n, k ) routine for the following values of ⟨n,k⟩ :
		n = 15, k = 3
		n = 100, k = 10
		n = 1000, k = 20
		n = 10000, k = 40
	Each ⟨n,k⟩ pair should be run at least 1,000 times
	Output the worst case and average number of element comparisons (to three decimal places) performed for each ⟨n,k⟩ pair
On the basis of algorithmic theory, state the worst case number of element comparisons (upper bound) performed by your doalg( n, k ) routine as a function of n and k, including all constants.
	Do not use O-notation
	Justify your statement
	Compare your theoretical upper bound with your empirical observations and explain any discrepancies
