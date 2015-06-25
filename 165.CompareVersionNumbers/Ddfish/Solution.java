public class Solution {
    public int compareVersion(String version1, String version2) {
        
        version1 = version1.replace('.',' ');
        version2 = version2.replace('.',' ');
        
        String[] s1 = version1.split(" ");
        String[] s2 = version2.split(" ");
        int l1 = s1.length;
        int l2 = s2.length;
       if(l1>l2){
           String[] temp = s2;
           s2 = new String[l1];
           for(int i = 0 ; i < l1 ; i++){
               if(i < temp.length){
                   s2[i] = temp[i];
               }else{
                   s2[i] = "0";
               }
           }
       }else if(l2>l1){
           String[] temp = s1;
           s1 = new String[l2];
           for(int i = 0 ; i < l2 ; i++){
               if(i < temp.length){
                   s1[i] = temp[i];
               }else{
                   s1[i] = "0";
               }
           }
           
       }
       for(int i = 0 ; i < s1.length ; i++){
           if(Integer.valueOf(s1[i])>Integer.valueOf(s2[i])){
               return 1;
           }
            if(Integer.valueOf(s1[i])<Integer.valueOf(s2[i])){
               return -1;
           }
           
       }
       return 0;
     
        
          
    }
}
