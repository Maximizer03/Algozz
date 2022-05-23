// There are N ranks and M students in a class. Each student has a happiness value for the rank he gets. 
// The ith student gets happiness[i][j]  on getting the rank j. Its ok not to keep all students in the ranks
// they get 0 happiness.Atmost one student can be assigned to a rank.
// The total happiness of the assignment can be calculated as the sum of happiness of each student. 
// Find the best way to calculate the maximum happiness attainable.Atmost
// N<=15, M<=50   , 0<= happiness[i][j]<=1e5


int n, m, happiness[55][16], dp[55][(1 << 16)];

int calc(int i, int mask) {
	if (i == m) { //base case
		return 0;
	}
	if (dp[i][mask] != -1) {
		return dp[i][mask];
	}
	int ans = calc(i + 1, mask);
	// dont match this student
	for (int j = 0; j < n; j++) {
		int  bit = (1 << j)&mask;
		if (bit == 0) {
			// if the rank is not already alloted
			ans = max(ans, happiness[i][j] + calc(i + 1, mask | (1 << j)));
			// match the ith student to jth rank
		}
	}
	return dp[i][mask] = ans;
}
// answer is calc(0,0)

// time complexity => O(M*N* 2^N)
// space complexity => O(2^N*M)
