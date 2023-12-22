#define m 1000000007
int numDecodings(char* s) {
   int n = strlen(s); 
   long long* nana = (long long*) calloc((n+1),sizeof(long long));
   nana[0] = 1;
   for(int i = 1; i < n+1; i++) { 
      if(s[i] == '0') continue;
      nana[i] = nana[i-1];
      long long temp =0;
      if(s[i-1] == '*') nana[i] = (nana[i] * 9) %m;
      if(i > 1 && s[i-2] != '0' && (s[i-2] == '*' || s[i-2] < '3')  ) {
           temp = nana[i-2];
            if(s[i-1] == '*' && s[i-2] == '2') temp = (temp*6)%m;
           else if(s[i-1] == '*' && s[i-2] == '1') temp = (temp*9)%m;
           else if(s[i-1] =='*' &&  s[i-2] =='*') temp = (temp*15)%m;
           else if(s[i-2] =='*' && s[i-1] < '7') temp = (temp*2)%m;
           else if(s[i-2] == '*') temp = temp;
           else if(s[i-2] == '2' && s[i-1] > '6') temp = 0;
      }
      nana[i] = (nana[i] + temp) %m;
      printf("%d\n", nana[i]);
   }
   return  s[0] != '0' ? (long long)nana[n] : 0 ;
}