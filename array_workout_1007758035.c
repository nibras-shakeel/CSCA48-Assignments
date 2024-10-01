///////////////////////////////////////////////////////
// CSC A48 - Winter 2022 Exercise 3 starter
//
// (c) F. Estrada, Jan 2022
//
// Read carefully the comments in this starter file and
// complete the required sections
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// DO NOT INCLUDE ANY OTHER LIBRARIES FOR THIS EXERCISE
#include<stdio.h>
#include<stdlib.h>
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// GLOBAL data!
// In practice, we would rarely use global variables in our
// program except for very specialized cases. However, we
// haven't yet learned how to move arrays from one function
// to another (that's next week!) - so for this week, we will
// use a couple global arrays to do our work.
//
// Remember, global variables (as seen in Unit 2) live outside
// any of the functions in our program in terms of memory 
// model, and can be accessed/changed by any function in our
// code.
int the_primes[100];
int the_integers[100];
int the_factors[100];
//
// END of global data declarations
////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// Functions to be completed, read the description carefully
/////////////////////////////////////////////////////////
void factorize(int idx)
{
int n = the_integers[idx];
int i;
int j = 0;
for (i = 2; i <= n / i; i++) {
while (n % i == 0) {
the_factors[j] = i;
j++;
n /= i;
}
}
if (n > 1) {
the_factors[j] = n;
j++;
}
the_factors[j] = -1;
}
////////////////////////////////////////////////////////
 // This function receives the index of an entry in
 // the array of integers 'the_integers'. It takes
 // whatever entry is in the array, and produces a list
 // of prime factors which are then stored in the
 // array called the_factors[].
 //
 // Example, suppose idx=1
 //          the_integers[1]=50  // This is just an example,
 //                              // it could be ANY number
 //
 // The prime factors of 50 are:
 //  2, 5, 5  (50 = 2*5*5, where 2, and 5 are prime numbers)
 //
 // So this function would store these prime factors in order
 // in the 'the_factors' array:
 //
 // the_factors[0]=2
 // the_factors[1]=5
 // the_factors[2]=5
 // the_factors[3]=-1
 //
 // Notice that the function stored a '-1' at the end of the
 // list of prime factors. This is so we know we reached the
 // end of the list of prime factors because different numbers
 // will fewer or more prime factors.
 //
 // If you're still unsure what's going on here, it may be a
 // good idea to spend a bit of time reviewing primes and
 // prime factors online.
 ///////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////////////////////////
int is_prime(int x)
{
    //////////////////////////////////////////////////////////
 // This function tests x and returns 1 if x is prime, and
 // 0 if x is not prime.
 //
 // You're NOT allowed to use functions from the math
 // library here.
 //
 // x can be any arbitrary integer number.
 /////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////
 // TO DO: Complete this function
 /////////////////////////////////////////////////////////
if (x <= 1)
return 0;
for (int i = 2; i <= x / i; i++) {
if (x % i == 0)
return 0;
}
return 1;
}

void primitive()
{
    ///////////////////////////////////////////////////////////
 //
 // This function finds and stores the first 100 prime numbers
 // in the 'the_primes' array. It must make use of the
 // is_prime() function.
 //
 // 1 is NOT a prime (despite arguments to the contrary)
 //
 // There are no input arguments, and no return value.
 //
 ////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////////////////////////
int i = 0;
int j = 2;
while (i < 100) {
if (is_prime(j)) {
the_primes[i] = j;
i++;
}
j++;
}
}

#ifndef __TESTING
int main()
{
for (int i = 0; i < 100; i++) {
the_factors[i] = 0;
the_primes[i] = 0;
}
for (int i = 0; i < 100; i++)
the_integers[i] = i + 2;
primitive();
printf("The first 100 primes are: ");
for (int i = 0; i < 100; i++)
printf("%d, ", the_primes[i]);
printf("\n");
printf("**** Printing out factorizations now:\n");
for (int i = 0; i < 100; i++) {
factorize(i);
printf("x=%d, factors: ", the_integers[i]);
for (int j = 0; j < 100; j++) {
if (the_factors[j] == -1)
break;
printf("%d, ", the_factors[j]);
}
printf("\n");
}
return 0;
}
#endif
