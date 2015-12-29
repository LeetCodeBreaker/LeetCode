
public class CountPrimes {

    public static void main(String[] args) {
        CountPrimes test = new CountPrimes();
        System.out.println(test.countPrimes(499979));
    }

    public int countPrimes(int n) {
//        List<Integer> primeList = new ArrayList<>();
//        for (int i = 2; i < n; i++) {
//            boolean isPrime = true;
//            for (Integer prime : primeList) {
//                if (i % prime == 0) {
//                    isPrime = false;
//                    break;
//                } else if (prime * prime > i) {
//                    break;
//                }
//            }
//            if (isPrime) {
//                primeList.add(i);
//            }
//        }
//        return primeList.size();

        boolean[] isPrime = new boolean[n];
        for (int i = 2; i < n; i++) {
            isPrime[i] = true;
        }

        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i]) {
                continue;
            }
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }

}
