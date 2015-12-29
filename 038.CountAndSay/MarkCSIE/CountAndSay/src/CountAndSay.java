
public class CountAndSay {

    public static void main(String[] args) {
        CountAndSay test = new CountAndSay();
        System.out.println(test.countAndSay(5));
    }

    public String countAndSay(int n) {
        String answer = "1";
        StringBuilder temp = new StringBuilder();
        for (int i = 1; i < n; i++) {
            int count = 1;
            int length = answer.length();
            for (int j = 1; j < length; j++) {
                char currC = answer.charAt(j);
                char prevC = answer.charAt(j - 1);
                if (currC != prevC) {
                    temp.append(count);
                    temp.append(prevC);
                    count = 1;
                } else {
                    count++;
                }
            }
            temp.append(count);
            temp.append(answer.charAt(length - 1));

            answer = temp.toString();
            temp.setLength(0);
//            System.out.println(answer);
        }
        return answer;
    }
}
