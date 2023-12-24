int countTriplets(int* nums, int n) {
    int* duplets = (int*) calloc(65536,sizeof(int));
    for(int i =0;i<n;i++)  for(int j = 0; j < n; j++) duplets[nums[i] & nums[j]]++; 
    long long ans = 0;
    for(int i = 0; i < 10; i++) printf("%d - %d ", i, duplets[i]);
    for(int i =0; i < n; i++) for(int j = 0; j < 65536; j++) if(!(nums[i] & j)) ans += duplets[j];   
    return ans;
}