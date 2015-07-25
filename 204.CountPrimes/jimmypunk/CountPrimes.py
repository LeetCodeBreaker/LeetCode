from math import sqrt, floor


class Solution:
    # @param {integer} n
    # @return {integer}

    def countPrimes(self, n):
        is_prime = [True] * n

        if n <= 2:
            return 0

        is_prime[0] = is_prime[1] = False
        prime_cnt = 0
        limit = int(floor(sqrt(n))) + 1
        for i in xrange(2, limit):
            if is_prime[i]:
                prime_cnt += 1
                # cross out all multiple of i
                is_prime[i*i : : i] = [False] * ((n - 1 - i*i)/i +1)

        for i in xrange(limit, n):
            if is_prime[i]:
                prime_cnt += 1
        return prime_cnt