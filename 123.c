int maxProfit(int* prices, int n) {
    int* sell2 = (int*) calloc((n+1),sizeof(int));
    int* sell1 = (int*) calloc((n+1),sizeof(int));
    int max = 0;
    for(int i =n-1; i >=0; i--) {
     max = prices[i] < max ? max: prices[i];
     sell2[i] = (max-prices[i]) > sell2[i+1] ? (max-prices[i]) :  sell2[i+1];
    }
    int min = 100001;
     for(int i =1; i <= n; i++) {
     min = prices[i-1] > min ? min: prices[i-1];
     sell1[i] = (prices[i-1]-min) + sell2[i-1] > sell1[i-1] ? (prices[i-1]-min) + sell2[i-1] :  sell1[i-1];
    }
    int ans = sell1[n];
    free(sell2);
    free(sell1);
  return ans;
}
