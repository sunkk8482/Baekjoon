#include <iostream>

using namespace std;

int dp[10002][4];

int main() {
	int t;
	cin >> t;
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		for (int i = 4; i <= n; i++) {
			dp[i][1] = 1;
			dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
		}

		cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
	}
}

/*
1 2 3 4 5


1일때 1개 0개 0개
1 1 
2 
3 

2일때 1개 1개 0개
1 1+1 
2 2 
3 

3일때 1개 1개 1개
1 1+1+1
2 2+1
3 3

4일때 1개 2개 1개
1 1+1+1+1
2 1+1+2, 2+2
3 1+3

5일때 1개 2개 2개
1 1+1+1+1+1
2 1+1+1+2 , 1+2+2
3 1+1+3 3+2 

6일때 1개 3개 3개
1 1+1+1+1+1+1
2 1+1+1+1+2, 1+1+2+2, 2+2+2
3 1+1+1+3, 3+3 1+2+3

7일때 1개 3개 4개
1 1+1+1+1+1+1+1
2 1+1+1+1+1+2 1+1+1+2+2 1+2+2+2
3 1+1+1+1+3 1+3+3 1+1+2+3 2+2+3

8일때 1개 4개 5개
1 1+1+1+1+1+1+1+1
2 1+1+1+1+1+1+2 1+1+1+1+2+2 1+1+2+2+2 2+2+2+2
3 1+1+1+1+1+3 1+1+3+3 1+1+1+2+3 2+3+3 1+2+2+3 

*/