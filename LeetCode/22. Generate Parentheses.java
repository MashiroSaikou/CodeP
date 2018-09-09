class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<String>();
        String s = new String();
        addOneChar(result, s, 0, 0, n);
        return result;
    }

    public void addOneChar(List<String> result, String s, 
    					   int openP, int closeP, int n) {
    	if(openP == n&&closeP == n) {
    		/*结束尝试*/
    		result.add(s);
    	}
    	else if(openP >= closeP) {
    		if(openP != n)
    			addOneChar(result, new String(s+'('), openP+1, closeP, n);
    		if(closeP != n)
    			addOneChar(result, new String(s+')'), openP, closeP+1, n);
    	}

    }
}