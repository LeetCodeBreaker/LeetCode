/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
    if (!s || !t) return 0;
    const dp = new Array(s.length).fill().map(a => new Array(t.length));
    dp[0][0] = s[0] === t[0] ? 1 : 0;
    for (let i = 1; i < s.length; i++) dp[i][0] = dp[i - 1][0] + (s[i] === t[0] ? 1 : 0);
    for (let j = 1; j < t.length; j++) dp[0][j] = 0;
    for (let i = 1; i < s.length; i++) {
        for (let j = 1; j < t.length; j++) {
            if (s[i] !== t[j]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[s.length - 1][t.length - 1];
};
