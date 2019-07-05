#include "tweetnacl.h"
#include <time.h>
#include <stdio.h>
int main()
{
    unsigned char pk[crypto_sign_PUBLICKEYBYTES];
    unsigned char sk[crypto_sign_SECRETKEYBYTES];
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    crypto_sign_keypair(pk,sk);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Key generation %f \n", cpu_time_used); 
    unsigned char m[5] = {'h','e','l','l','o'}; 
    unsigned long long mlen =5;
    unsigned char sm[crypto_sign_BYTES + 5]; 
    unsigned long long smlen;
    start = clock();
    crypto_sign(sm,&smlen,m,mlen,sk);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Signature creation %f \n", cpu_time_used);
    start = clock();
    crypto_sign_open(m,&mlen,sm,smlen,pk);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Signature verification %f \n", cpu_time_used); 
    
}
