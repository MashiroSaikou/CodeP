class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length-2; i++) {
        	if(i == 0 || (i > 0 && nums[i] != nums[i-1]))
        	/* 此if条件找到重复数字段的第一个数字*/
        	{
        		int j = i+1, k = nums.length-1;
        		while(j < k) {
        			int sum = nums[j]+nums[k]+nums[i];
        			if(sum == 0) {
        				List<Integer> temp = Arrays.asList(nums[i],nums[j],nums[k]);
        				list.add(temp);
        				while(j < k && nums[j] == nums[j+1]) j++;
        				while(j < k && nums[k] == nums[k-1]) k--;
        				/*这两个while循环避免重复查找相同的结果*/
        			}
        			else if(sum < 0) k--;
        			else j++;
        		}
        	}
        }
        return list;
    }
}