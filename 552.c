#define m 1000000007

int checkRecord(int n) {
    int* zero = (int*) calloc((n+1),sizeof(int));
    int* ans = (int*) calloc((n+1),sizeof(int));
    zero[0] =1,ans[0] =1;
    for(int i = 1; i < n+1; i++) {
    zero[i] = (((2*zero[i-1])%m) - (i < 4 ? i == 3 ? 1 : 0 : zero[i-4])) % m;
    zero[i] =  zero[i]<0 ? m+zero[i] : zero[i];
    }
    for(int i =1;i<=n;i++) {
        ans[i] = (((((ans[i-1]+zero[i-1])%m)+ans[i-1])%m) - (i < 4 ? i == 3 ? 1:0 : ((ans[i-4] +zero[i-4])%m)))%m;
        ans[i] =  ans[i]<0 ? m+ans[i] : ans[i];
    }
    return  ans[n];
}