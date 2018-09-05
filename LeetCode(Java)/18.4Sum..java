class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        
        for(int d = nums.length-1; d >= 0 ; d--){
        	/*比最大数×4大，一定不满足条件*/
        	if(nums[d]*4 < target) break;
        	if(d == nums.length-1 || (d < nums.length-1 && nums[d] != nums[d+1])){
        		for(int a = 0; a < d; a++){
        			/*比最小数×4小，一定不满足条件*/
        			if(nums[a]*4 > target) break;
        			if(a == 0 || (a > 0 && nums[a] != nums[a-1])) {
        				int b = a+1, c = d-1;
			        	int tempSum;
			        	while(b < c) {
			        		tempSum = nums[a]+nums[b]+nums[c]+nums[d];
			        		if(tempSum == target) {
			        			list.add(Arrays.asList(nums[a], nums[b],nums[c], nums[d]));
			        			/*移动避免重复结果*/
			        			while(b < c && nums[b] == nums[b+1]) b++;
			        			while(b < c && nums[c] == nums[c-1]) c--;
			        			b++;
			        			c--;
			        		}
			        		else if(tempSum < target) b++;
			        		else c--;
			        	}
        			}
		        }
        	}
        }
        return list;
    }
}