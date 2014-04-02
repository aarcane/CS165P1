double dshrandom( long input ) {
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
/*	Random Number Generator					*/
/*		first called with seed				*/
/*		thereafter called with 0			*/
/*	Based on code appearing in				*/
/*	"Random number generators: good ones are hard to find"	*/
/*		by Stephen Park and Keith Miller		*/
/*		CACM 31 (Oct 1988) 1192-1201.			*/
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  */
	static long seed = 3125;
	static long a = 16807;
	static long m = 2147483647;
	static long q = 127773;      /* m div a */
	static long r = 2836;        /* m mod a */
	long lo, hi, test;

	if (input>0) seed = input;
	hi = seed/q;
	lo = seed - (hi*q);
	test = a*lo - r*hi;
	if (test>0) seed = test;
	else        seed = test+m;
				/* seed equally in range 0...2^31 -1  */
	return( ((double)seed)/(double)m );
}
