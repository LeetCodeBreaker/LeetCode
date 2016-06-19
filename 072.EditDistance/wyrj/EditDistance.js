/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(word1, word2) {
    var table = [[0]], i, j;
    for (i = 1; i <= word1.length; i++) {
        table[i] = [i];
    }
    for (j = 1; j <= word2.length; j++) {
        table[0][j] = j;
    }
    for (i = 1; i <= word1.length; i++) {
        for (j = 1; j <= word2.length; j++) {
            if (word1[i - 1] === word2[j - 1]) {
                table[i][j] = table[i - 1][j - 1];
            } else {
                table[i][j] = Math.min(table[i - 1][j - 1], table[i - 1][j], table[i][j - 1]) + 1;
            }
        }
    }
    return table[word1.length][word2.length];
};