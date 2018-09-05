/**
 * mashiro:
 * 暴力求解可以，但肯定不是最好的方法
 * 想用动态规划，但发现不存在最优子结构
 * 容器容量相同的情况下，不同挡板的选择可能影响后面
 * 最后想到两点从最外侧逼近，每次移动两个挡板中最低的一个
 */
class Solution{
	public int maxArea(int[] height) {
		int i = 0, j = height.length-1;
		int result = 0;
		while(i < j){
			int temp = Math.min(height[i], height[j])*(j-i);
			if(temp > result) {temp = result};

			if(height[i] > height[j]) {j--};
			else {i++};
		}
		return result;
}