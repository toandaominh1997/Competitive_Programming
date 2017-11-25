# Dynamic Programming
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
