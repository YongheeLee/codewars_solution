//https://www.codewars.com/kata/526571aae218b8ee490006f4

unsigned int countBits(unsigned long long n){
  
  unsigned int ret = 0;
  while(true)
    {
    if(n%2==0)
      n/=2;
    else
      {
      n--;
      ret++;
    }
    
    if(n==0)
      break;
}
  
  return ret;
  //your code here
}
