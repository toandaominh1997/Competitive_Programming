# Devide and Conquer
## Introduction
Như Greedy and Dynamicprogramming, Divide and Conquer là mô hình thuật toán. Thuật toán Divide and Conquer giải quyết vấn đề sử dụng 3 steps sau:
1. Divide: Giải quyết bài toán đó thành các bài toán con cùng loại.
2. Conquer: Đệ quy các bài toán con đó.
3. Combine: Kết hợp các câu trả lời lại với nhau
## Calculate pow(x, n)
### Bài toán
Cho hai số nguyên x và n, tính x^n.
``` cpp
int power(int x, int y){
  int temp;
  if(y==0)
    return 1;
  temp=power(x, y/2);
  if(y%2==0)
     return temp*temp;
   else
     return x*temp*temp;
}
```
Time Complexity of optimized solution: O(logx)
Mở rộng pow với số nguyên y và số thực x
``` cpp
double power(double x, int y){
  double temp;
  if(y==0)
    return 1;
  temp = power(x, y/2);
  if(y%2==0)
    return temp*temp;
  else{
    if(y>0)
      return x*temp*temp;
    else
      return (temp*temp)/x;
  }
}
Time Complexity: O(logx)
O(logy) function for pow(x, y)
``` cpp
int power(int x, int y){
  int res = 1;
  while(y>0){
    if(y & 1)
      res = res*x;
    y=y>>1;
    x=x*x;
  }
  return res;
}
```
### Modular Exponentiation (Power in Modular Arithmetic)
Cho x, y, và p, tính (x^y)%p.
``` cpp
int power(int x, int y, int p)
