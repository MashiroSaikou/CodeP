class Solution{
	public boolean isMatch(String s, String p){
		boolean[][] dp = new boolean[s.length()+1][p.length()+1];
		dp[s.length()][p.length()] = true;
		for(int j = p.length()-1; j >= 0; j --){
			if(p.charAt(j) != '*') break;
			else dp[s.length()][j] = dp[j][s.length()] = true;
		}
		for (int i = s.length()-1; i >= 0; i --){
			for (int j = p.length()-1; j >= 0; j --){
				if(s.charAt(i) == p.charAt(j) || p.charAt(j) == '?'){
					dp[i][j] = dp[i+1][j+1];
				}
				else if(p.charAt(j) == '*'){
					dp[i][j] = dp[i+1][j] || dp[i][j+1];
				}
			}
		}
		return dp[0][0];
	}
}