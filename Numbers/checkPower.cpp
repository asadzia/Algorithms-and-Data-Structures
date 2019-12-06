/*

Check if a number can be represented as a power
E.g: 4-> 2^2
*/

int Solution::isPower(int A) {
    
    if (A == 1) {
        return 1;
    }
    
    for (int i = 2; i <= sqrt(A); ++i) {
        long long value = 1;
        
        while (true) {
            value = value * i;
            
            if (value == A) {
                return 1;
            }
            
            if (value > A) {
                break;
            }
        }
    }
    
    return 0;
}
