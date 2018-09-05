class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length = 0) return "";
        StringBuilder result = new StringBuilder(strs[0]);
        for(int i = 1; i < strs.length; i++) {
        	while(strs[i].indexOf(result.toString()) != 0) {
        		result = result.substring(0, result.length()-1);
        		if(result.length() = 0) return "";
        	}
        }
        return result.toString();
    }
}