
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class GroupAnagrams {

    public static void main(String[] args) {
        GroupAnagrams test = new GroupAnagrams();
        String[] testCase1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
        List<List<String>> testAnswer1 = test.groupAnagrams(testCase1);
        System.out.println(testAnswer1.toString());
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> answer = new ArrayList<>();
        HashMap<String, List<String>> groupMap = new HashMap<>();
        Arrays.sort(strs);
        for (String str : strs) {
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sortedStr = new String(chars);
            List<String> group = groupMap.get(sortedStr);
            if (group != null) {
                group.add(str);
            } else {
                group = new ArrayList<>();
                group.add(str);
                groupMap.put(sortedStr, group);
                answer.add(group);
            }
        }
        return answer;
    }
}
