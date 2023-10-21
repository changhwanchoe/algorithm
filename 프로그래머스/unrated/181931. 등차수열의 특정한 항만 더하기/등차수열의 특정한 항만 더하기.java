class Solution {
    public int solution(int a, int d, boolean[] included) {
        int answer = 0;
        int nowNum;
        for(int i=0;i<included.length;i++) {
            nowNum=a+d*i;
            if(included[i])
               answer+=nowNum; 
        }
        return answer;
    }
}