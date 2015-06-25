public class Solution {
    public boolean isIsomorphic(String s, String t) {
        char[] sArray = s.toCharArray();
        char[] tArray = t.toCharArray();
        HashMap<Character,Character> map = new HashMap<>();
        for (int i = 0 ; i < sArray.length ; i++){
            if( !map.containsKey(sArray[i]) && !map.containsValue(tArray[i])){
                map.put(sArray[i],tArray[i]);
            }else{
                
                if(map.get(sArray[i]) == null || tArray[i] != map.get(sArray[i])){
                    return false;
                }
                    
            }
        }
        return true;
    }
}
