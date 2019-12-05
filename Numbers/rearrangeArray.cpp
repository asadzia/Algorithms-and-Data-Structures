/*
Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.

Example:

Input : [1, 0]
Return : [0, 1]
 Lets say N = size of the array. Then, following holds true :
All elements in the array are in the range [0, N-1]
N * N does not overflow for a signed integer
*/

void arrange(vector<int> &A) {
   
   /*
   1) (A[A[i]]%n) *n is divisible by n and A[i] is not divisible by n because it is smaller than n. This means that moding the sum by n will always produce A[i] because A[i] is the remainder. When we think about what a remainder is this becomes apparent. A remainder is a number smaller than the divisor that when added by a number that is a multiple of the divisor becomes the dividend. If we have a remainder r the we can write. r + an = x. where n is the divisor and x is the dividend. We can see that the above equation used to encrypt our data fits this format.
   2) Now for the other half of the solution. A[i][i] is produced by dividing the initial equation by N. Now if we go back to our remainder formula r +an = x and divide by n we can represent this as r/n +an/n = x/n. We know that because of how integer division work that r/n will be a fraction and thus irrelevant and an/n = a. If we say that r was A[i] and a was A[A[i]] we see it still works and we get our solution.
   3) As mentioned previously in a comment the initial mod of A[A[i]] is pretty irrelevant because any smaller number being modded by a larger number will always produce the smaller number and all the values in the array are smaller than n by definition.
   */
 
    /*
    If you had extra space to do it, the problem will be very easy.
Store a copy of Arr in B.

And then for every element, do Arr[i] = B[B[i]]

Lets restate what we just said for extra space :

If we could somehow store 2 numbers in every index ( that is, Arr[i] can contain the old value and the new value somehow ), then the problem becomes very easy.
NewValue of Arr[i] = OldValue of Arr[OldValue of Arr[i]]

Now, we will do a slight trick to encode 2 numbers in one index.
This trick assumes that N * N does not overflow.

1) Increase every Array element Arr[i] by (Arr[Arr[i]] % n)*n.
2) Divide every element by N.
Given a number as

   A = B + C * N   if ( B, C < N )
   A % N = B
   A / N = C
We use this fact to encode 2 numbers into each element of Arr.
*/
   
   int n = A.size();
    
    for (int i = 0; i < A.size(); ++i) {
        A[i] += n * (A[A[i]]%n);
    }
    
    for (int i = 0; i < A.size(); ++i) {
        A[i] = A[i]/n;
    }
}
