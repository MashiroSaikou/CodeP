class Solution {
    public List<String> letterCombinations(String digits) {
        String[] charContain = {"", "", "abc", "def", "ghi",
    							"jkl", "mno", "pqrs", "tuv", "wxyz"};
    	String[] result = new String[];
    	result.add("");
    	for(int i = 0; i < digits.length(); i++) {
    		int index = digits.charAt(i) - '0';
    		char[] letters = charContain[index].toCharArray();
    		String[] temp = result.clone();
    		result = null;
    		for(int j = 0 ; j < letters.length; j++) {
    			for(int k = 0; k < temp.length; k++){
    				result.add(temp[k]+letters[j]);
    			}
    		}
    	}
    	return result.asList();
    }
}