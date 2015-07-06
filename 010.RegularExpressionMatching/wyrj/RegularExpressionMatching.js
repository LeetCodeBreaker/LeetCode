/* 168ms */
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    var reg = [], i = 0, j;
    while(i < p.length) {
        if ('*' === p[i+1]) {
            reg.push({c: p[i], star: true});
            i += 2;
        } else {
            reg.push({c: p[i], star: false});
            i += 1;
        }
    }
    var table = [];
    table[0] = [];
    table[0][0] = true;
    for (i = 1; i <= reg.length; i++) {
        table[i] = [];
        table[i][0] = (reg[i-1].star) ? table[i-1][0] : false;
    }
    for (j = 1; j <= s.length; j++) {
       table[0][j] = false;
    }
    for (i = 1; i <= reg.length; i++) {
        for (j = 1; j <= s.length; j++) {
            if (false === reg[i-1].star) {
                if (reg[i-1].c === s[j-1] || '.' === reg[i-1].c) {
                    table[i][j] = table[i-1][j-1]
                } else {
                    table[i][j] = false;
                }
            } else {
                if (reg[i-1].c === s[j-1] || '.' === reg[i-1].c) {
                    table[i][j] = table[i-1][j-1] || table[i-1][j] || table[i][j-1];
                } else {
                    table[i][j] = table[i-1][j];
                }
            }
        }
    }
    return table[reg.length][s.length];
};