public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> answers = new ArrayList<>();
        answers.add(new ArrayList<Integer>());
        
        Arrays.sort(nums);
        for( int i = 0 ;i < nums.length ; i ++){
            ArrayList<ArrayList<Integer>> temp  = new ArrayList<>();
            for(List<Integer> l : answers){
                temp.addAll(innerSubsets((ArrayList<Integer>)l,nums[i]));   
            }
            answers = new ArrayList<>();
            for(List<Integer> k : temp){
                answers.add(k);
            }
           
            
        }
        return answers;
        
    }
  
    private ArrayList<ArrayList<Integer>> innerSubsets(ArrayList<Integer> num,int i){
        ArrayList<ArrayList<Integer>> answers = new ArrayList<>();
        answers.add(num);
        ArrayList<Integer> newNum = (ArrayList<Integer>)((ArrayList) num).clone();
        newNum.add(i);
        answers.add(newNum);
        return answers;    
    }
  
}
