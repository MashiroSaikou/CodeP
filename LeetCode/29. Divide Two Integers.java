/**
 * 大致思路是用减法依次减去divisor
 * 增加速度可以指数增长得去减
 * 并且，对于特殊情况的减枝 以及 成倍的运算使用移位符可以大大减少运算时间
 */
class Solution {
    public int divide(int dividend, int divisor) {
    	if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
    	long absdividend = Math.abs((long) dividend);
    	long absdivisor = Math.abs((long) divisor);
    	int isNeg = (dividend>>31)^(divisor>>31);

    	long quotient = 0;
    	long times = 1;
    	long tempdivisor = absdivisor;
    	while(absdividend >= absdivisor) {
    		absdividend -= tempdivisor;
    		if(absdividend < 0) {
    			absdividend += tempdivisor;
    			tempdivisor = absdivisor;
    			times = 1;
    			continue;
    		}
    		tempdivisor <<= 1;
    		quotient += times;
    		times <<= 1;
    	}
    	quotient = isNeg == 0?quotient : -quotient;
    	return quotient > (long)Integer.MAX_VALUE?
    			Integer.MAX_VALUE : (int)quotient;
    }
}