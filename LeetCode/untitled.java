class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
       	/*finalResult初始化不能使用MAX_VALUE，因为可能造成abs()的越界*/
        int finalResult = nums[0]+nums[1]+nums[nums.length-1];
        for(int i = 0; i < nums.length-2; i++) {
        	int tempTarget;
        	if(i == 0 || (i>0 && nums[i] != nums[i-1])) {
        		int j = i+1, k = nums.length-1;
        		while(j < k) {
        			tempTarget = nums[i]+nums[j]+nums[k];
        			if(Math.abs(finalResult-target) > Math.abs(tempTarget-target)){
        				finalResult = tempTarget;
        			}
        			if(target == tempTarget) {
        				return finalResult;
        			}
        			else if(tempTarget < target) j++;
        			else k--;
        		}
        	}
        }
        return finalResult;
    }
}