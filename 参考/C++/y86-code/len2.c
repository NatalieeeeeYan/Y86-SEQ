int len2(int a[]){
  int len = 0;
  while (*a++)
    len++;
  return len;
}
