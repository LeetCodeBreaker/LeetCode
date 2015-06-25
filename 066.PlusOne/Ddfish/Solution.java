public class Solution {
    public int[] plusOne(int[] digits) {
        ArrayList<Integer> answersList = new ArrayList<>();
        boolean flag = false;
        int x = 1;
        
        for(int i = digits.length-1 ; i>=0 ;i--){
            x += digits[i];
            if(x == 10){
                answersList.add(0,0);
                x = 1;
            }else{
                answersList.add(0,x);
                x = 0;
            }
        }
        if(x == 1){
            answersList.add(0,1);
        }
        
        int[] answer = new int[answersList.size()];
        for(int i = 0 ;i < answer.length ; i++){
            answer[i] = (Integer)answersList.get(i);
        }
        return answer;
        
    }
}
