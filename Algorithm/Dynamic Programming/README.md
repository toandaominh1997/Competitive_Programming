# Dynamic Programming

## Table of Contents

### Intermediate Problems
21. [Maximum decimal value path in a binary matrix](#21-maximum-decimal-value-path-in-a-binary-matrix)
22. [Count Derangements (Permutation such that no element appears in its original position)](#22-count-derangements-permutation-such-that-no-element-appears-in-its-original-position)
23. [Dice Throw Problem](#23-Dice-throw-problem)

## Longest Increasing Subsequence
### Bài toán:
#### Chuỗi con tăng dài nhất
### Hướng dẫn:
Cho arr[0..n-1] và L(i) là độ dài của LIS kết thúc tại vị trí thứ i <br/>
•	L(i)=1+max(L(j)), 0 < j <  and ar[j]<ar[i] <br/>
•	L( i ) = 1 <br/>
Độ phức tạp: ***O(n^2)*** <br/>

## Longest Common subsequence
### Bài toán:
#### Chuỗi con chung dài nhất.
### Hương dẫn:
Cho X[0..m-1] and Y[0..n-1]. Gọi L( I , j ) là LCS của chuổi X từ 0 -> I và chuỗi Y từ 0 -> j <br/>
Nếu X[m-1]==Y[n-1] thì <br/>
L[ X[0..m-1], Y[0..n-1]) = 1 + L(X[0..m-2, Y[0..n-2) <br/>
Ngược lại thì <br/>
L ( X[0..m-1], Y[0..n-1] ) =max(L[X[0..m-2], y[0..n-1]), L(X[0..m-1], Y[0..n-2] ) <br/>

## Intermediate Problems
### 21. Maximum decimal value path in a binary matrix
Cho ma trận vuông nhị phân[n*n]. Tìm giá trị lớn nhất trong đường đi từ top left to bottom right.
We can move [i, j+1] or [i+1, j].

#### Hướng dẫn
```cpp
int MaximumDecimalValue(int mat[][N], int n){
  int dp[n][n];
  memset(dp, 0, sizeof(dp));
  if(mat[0][0]==1){
    dp[0][0]=1;
  }
  // Tính cột đầu tiên của ma trận và lưu kết quả trong dp[0][i]
  for(int i=1;i<n;i++){
    if(mat[0][i]==1){
      dp[0][i]= dp[0][i-1] + pow(2, i);
    }
    else
    dp[0][i]=dp[0][i-1];
  }
  // Tính hàng đầu tiên của ma trận và lưu kết quả vào dp[i][0]
  for(int i=1;i<n;i++){
    if(mat[i][0]==1){
      dp[i][0]=dp[i-1][0]+pow(2, i);
    }
    else
    dp[i][0]=dp[i-1][0];
  }
  
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      if(mat[i][j]==1){
        dp[i][j]=max(dp[i][j-1], dp[i-1][j])+pow(2, i+j);
      }
      else
      dp[i][j]=max(dp[i][j], dp[i][j]);
    }
  }
  return dp[n-1][n-1]; 
}
```
Time Complexity: O(n^2) <br/>
Auxiliary space: O(n^2)
### 22. Count Derangements (Permutation such that no element appears in its original position)
A Derangement là hoán vị của n phần tử, mà không có phần tử nào xuất hiện ở vị trí ban đầu.
Ví dụ, a derangement của {0, 1, 2, 3} là {2, 3, 1, 0}
Cho số n, tìm tổng số derangements của bộ n phần tử.
#### Hướng dẫn:
countDer(n) = (n-1)*[countDer(n-1) +  countDer(n-2)]
### 23. Dice Throw Problem
Cho n con xúc sắc có m mặt, đánh số từ 1 đến m, tìm số cách lấy ra tổng X. X là tổng giá trị trên mỗi mặt khi tất cả xúc sắc được tung.
#### Hướng dẫn
``` cpp
//'n' dice and 'm' with m faces 
int findWays(int m, int n, int x){
  int table[n+1][x+1];
  // Table entries for only one dice
  for(int i=1;j<=m and j<=x;j++){
    table[1][j]=1;
  }
  for(int i=2;i<=n;i++){
    for(int j=1;j<=x;j++){
      for(int k=1;k<=m and k<j;k++)
      table[i][j]+=table[i-1][j-k];
    }
  }
  return table[n][x]
}
```
