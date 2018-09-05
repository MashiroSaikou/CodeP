class Solutions {
	public String intToRoman(int num) {
		int[] Value = {1000, 900, 500, 400, 100,
					   90, 50, 40, 10, 9, 5, 4, 1};
		String[] Symbol = {"M", "CM", "D", "CD", "C",
						   "XC", "L", "XL", "X", "IX",
						   "V", "IV", "I"};

		StringBuilder result = new StringBuilder();
		for(int i = 0; i < Value.Length; i++) {
			while(num >= Value[i]) {
				result.append(Symbol[i]);
				num = num-Value[i];
			}

			if(num <= 0) {break;}
		}
		return result.toString();
	}
}