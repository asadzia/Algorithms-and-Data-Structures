/*

Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011
so the function should return 3.

*/

int Solution::numSetBits(unsigned int A) {
    
    int count = 0;
    
    while (A != 0) {
        // this unsets the last SET bit
        // We will unset all the set bits and count the instances
        A = A & (A - 1);
        count++;
    }
    
    return count;
}
