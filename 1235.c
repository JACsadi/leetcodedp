 void merge(int* arr,int*brr, int*crr, int l, int m, int r) {
    if(l != r) {
        int L[m - l + 1], R[r - m];
        int LL[m - l + 1], RR[r - m];
        int LLL[m - l + 1], RRR[r - m];
        for(int i = l; i <= m; i++) {
            L[i-l] = arr[i];
            LL[i-l] = brr[i];
            LLL[i-l] = crr[i];
        }
        for(int i = m + 1; i <= r; i++) {
            R[i - m - 1] = arr[i];
             RR[i - m - 1] = brr[i];
              RRR[i - m - 1] = crr[i];
        }
        int i = 0 , j = 0;
        while(i + j < r - l + 1) {
            if(j == r - m) {
                 arr[l+i+j] = L[i];
                  brr[l+i+j] = LL[i];
                   crr[l+i+j] = LLL[i];
                 i++;
            } else if(i == m - l + 1) {
                 arr[l+i+j] = R[j];
                 brr[l+i+j] = RR[j];
                 crr[l+i+j] = RRR[j];
                 j++;
            } else if(L[i] < R[j]){
                arr[l+i+j] = L[i];
                  brr[l+i+j] = LL[i];
                   crr[l+i+j] = LLL[i];
                 i++;
            } else {
                arr[l+i+j] = R[j];
                 brr[l+i+j] = RR[j];
                 crr[l+i+j] = RRR[j];
                 j++;
            }
        } 
    }
}
void sortttt(int* arr,int*brr, int*crr, int l,int r) {
    int mid = (l+r)/2;
    if(r > l) {
        sortttt(arr,brr,crr, l ,mid);
        sortttt(arr,brr,crr, mid + 1, r);
    }
    merge(arr,brr,crr,l,mid,r);
}
int bs(int*arr, int n, int tar) {
    int l = 0, r = n-1, ans = n;
    while(l <= r) {
        int m = (l+r)/2;
        if(arr[m] < tar) l = m +1;
        else {
            ans = m;
            r = m-1;
        }
    }
    return ans;
}
int jobScheduling(int* s, int n, int* e, int ett, int* p, int pSize) {
    sortttt(s,e,p,0,n-1);
       int* dp = (int*) calloc(n+1,sizeof(int));
       long long max = 0;
       for(int i = n-1; i >=0; i--) {
          dp[i] = (p[i]+dp[bs(s,n, e[i])]) < dp[i+1] ? dp[i+1] : (p[i]+dp[bs(s,n, e[i])]);
       }
       return dp[0];
}