//version 1
class Solution {
public:
	int climbStairs(int n) {
		static int cnt = 0;
		if (n <= 0) cnt++;
		if (n < 0) return 0;
		else {
			climbStairs(n - 1);
			climbStairs(n - 2);
		}
		return cnt;
	}
};


//version 2
class Solution {
public:
	int climbStairs(int n) {
		if (depth == 0) cnt = 0;
		if (n == 0)
		{
			cnt++;
		}
		if (n < 0)
		{
			return 0;
		}
		else {
			depth++;
			climbStairs(n - 1);
			climbStairs(n - 2);
			depth--;
		}
		return cnt;
	}
	int cnt=0;
	int depth=0;
};

//version¡ª¡ªdl
class Solution {
public:
    int climbStairs(int n)
    {
        vector<long long> list(n + 1);
        list[0] = 1;
        list[1] = 1;
        for (size_t i = 2; i <= n; i++) {
            list[i] = list[i - 1] + list[i - 2];
        }
        return list[n];
    }
}; 
