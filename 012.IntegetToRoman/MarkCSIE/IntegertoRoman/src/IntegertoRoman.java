public class IntegertoRoman {

    public static void main(String[] args) {
        IntegertoRoman test = new IntegertoRoman();
        System.out.println(test.intToRoman(1000));
    }
    
    // range from 1 to 3999.
    public String intToRoman(int num) {
        String answer = "";
        switch (num / 1000) {
            case 1:
                answer += "M";
                break;
            case 2:
                answer += "MM";
                break;
            case 3:
                answer += "MMM";
        }

        num = num % 1000;

        switch (num / 100) {
            case 1:
                answer += "C";
                break;
            case 2:
                answer += "CC";
                break;
            case 3:
                answer += "CCC";
                break;
            case 4:
                answer += "CD";
                break;
            case 5:
                answer += "D";
                break;
            case 6:
                answer += "DC";
                break;
            case 7:
                answer += "DCC";
                break;
            case 8:
                answer += "DCCC";
                break;
            case 9:
                answer += "CM";
                break;
        }
        num = num % 100;

        switch (num / 10) {
            case 1:
                answer += "X";
                break;
            case 2:
                answer += "XX";
                break;
            case 3:
                answer += "XXX";
                break;
            case 4:
                answer += "XL";
                break;
            case 5:
                answer += "L";
                break;
            case 6:
                answer += "LX";
                break;
            case 7:
                answer += "LXX";
                break;
            case 8:
                answer += "LXXX";
                break;
            case 9:
                answer += "XC";
                break;
        }
        num = num % 10;

        switch (num) {
            case 1:
                answer += "I";
                break;
            case 2:
                answer += "II";
                break;
            case 3:
                answer += "III";
                break;
            case 4:
                answer += "IV";
                break;
            case 5:
                answer += "V";
                break;
            case 6:
                answer += "VI";
                break;
            case 7:
                answer += "VII";
                break;
            case 8:
                answer += "VIII";
                break;
            case 9:
                answer += "IX";
                break;
        }

        return answer;
    }
}
