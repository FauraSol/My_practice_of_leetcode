//����sort
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (auto i = nums.begin(); i < nums.end(); i+=2) {
			auto j = i + 1;
			if (j >= nums.end())return *i;
			if (*i != *j) return *i;
		}
	}
	
};
//���ù�ϣ��
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		map<int, int>a;
		for (auto& i : nums) {
			a[i] ++ ;
		}
		for (auto i = a.begin(); i != a.end(); i++) {
			if ((*i).second == 1)return (*i).first;
		}
		return 0;
	}
};
//���еĴ���
class Solution {
    public int singleNumber(int[] nums) {
        int single = 0;
        for (int num : nums) {
            single ^= num;
        }
        return single;
    }
} 
