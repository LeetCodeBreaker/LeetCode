class Solution:
    # @param {string} s
    # @return {integer}

    def numDecodings(self, s):
        self.numDecoding_table = [-1] * (len(s) + 1)
        return self.numDecodingsDP(s, len(s))

    def numDecodingsDP(self, s, length):
        # if the value is filled, then return the val
        if self.numDecoding_table[length] != -1:
            return self.numDecoding_table[length]

        # terminate condition
        if length <= 2:
            self.numDecoding_table[length] = self.numShortDecoding(s, length)
            return self.numDecoding_table[length]

        else:  # > 2
            last_two_digit = s[length - 2: length]
            num = int(last_two_digit)
            sum = 0
            if num >= 10 and num <= 26:
                sum += self.numDecodingsDP(s, length - 2)

            num = int(s[length - 1])
            if num > 0:
                sum += self.numDecodingsDP(s, length - 1)

            self.numDecoding_table[length] = sum
            return sum

    def numShortDecoding(self, s, length):
        res = 0
        if length == 2:
            num = int(s[:2])
            if num >= 10 and num <= 26:
                res += 1
            if int(s[0]) > 0 and int(s[1]) > 0:
                res += 1
        elif length == 1:
            num = int(s[0])
            if num > 0:
                res = 1

        return res

