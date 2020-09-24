struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i=0;i<nums.size()-1;i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                   return {i,j};
                }
            }
        }
        return {i,j};
    };
};

class Solution_by_bigwig1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;//����hash��������Ԫ��
        vector<int> b(2,-1);//��Ž��
        for(int i=0;i<nums.size();i++)
            a.insert(map<int,int>::value_type(nums[i],i));
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0&&(a[target-nums[i]]!=i))
            //�ж��Ƿ��ҵ�Ŀ��Ԫ����Ŀ��Ԫ�ز����Ǳ���
            {
                b[0]=i;
                b[1]=a[target-nums[i]];
                break;
            }
        }
        return b;
    };
};

class Solution_by_bigvig2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;//�ṩһ��һ��hash
        vector<int> b(2,-1);//�������ؽ������ʼ��һ����СΪ2��ֵΪ-1������b
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0)
            {
                b[0]=a[target-nums[i]];
                b[1]=i;
                break;
            }
            a[nums[i]]=i;//����������map�У�������ȡ����±�
        }
        return b;
    };
};


