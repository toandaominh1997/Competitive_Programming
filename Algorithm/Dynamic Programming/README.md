# Dynamic Programming

## Table of Contents
- [What is it?](#what-is-it)






## What is it?

This is my multi-month study plan for going from web developer (self-taught, no CS degree) to software engineer for a large company.

![Coding at the whiteboard - from HBO's Silicon Valley](https://dng5l3qzreal6.cloudfront.net/2016/Aug/coding_board_small-1470866369118.jpg)

This is meant for **new software engineers** or those switching from
software/web development to software engineering (where computer science knowledge is required). If you have
many years of experience and are claiming many years of software engineering experience, expect a harder interview.

If you have many years of software/web development experience, note that large software companies like Google, Amazon,
Facebook and Microsoft view software engineering as different from software/web development, and they require computer science knowledge.

If you want to be a reliability engineer or operations engineer, study more from the optional list (networking, security).
### Intermediate Problems
21. [Maximum decimal value path in a binary matrix](#21. Maximum decimal value path in a binary matrix)

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

