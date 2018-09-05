class Solution {
    public int romanToInt(String s) {
        int result = 0;
        int preNum = 0;

        for(int i = s.length()-1; i >= 0; i--){
        	switch (s.charAt(i)) {
        		case 'M' :
        			result += 1000;
        			preNum = 1000;
        			break;
        		case 'D' :
        			result += 500;
        			preNum = 500;
        			break;
        		case 'C' :
        			result += (preNum == 500||preNum == 1000 ? -100:100);
        			preNum = 100;
        			break;
        		case 'L' :
        			result += 50;
        			preNum = 50;
        			break;
        		case 'X' :
        			result += (preNum == 50||preNum == 100 ? -10:10);
        			preNum = 10;
        			break;
        		case 'V' :
        			result += 5;
        			preNum = 5;
        			break;
        		case 'I' :
        			result += (preNum == 5||preNum == 10 ? -1:1);
        			preNum = 1;
        			break;
        	}
        }
        return result;
	}
}