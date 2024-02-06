#include <stdio.h> 

int isPrime(int num) { 
    if (num < 2) return 0; 
    for (int i = 2; i < num; i++) { 
        if (num % i == 0) return 0; 
    } 
    
    return 1; 
    } 

int isPalindrome(int num) { 
    int original = num; 
    int reversed = 0; 
    
    while (num > 0) { 
        int digit = num % 10; 

        reversed = reversed * 10 + digit; num /= 10; 
    } 
    
    return reversed == original; 
    }

int nthPrimePalindrome(int n) { 
    int count = 0; 
    int num = 2; 
    
    while (count < n) { 
        if (isPrime(num) && isPalindrome(num)) { 
            count++; 
        } 
        num++; 
    } 
    
    return num - 1; 
    } 
    
int main() { 
    int n; 
    
    scanf("%d", &n); 
    
    int result=nthPrimePalindrome(n); 
    
    printf("%d\n", result); 
    
    return 0; 
}
