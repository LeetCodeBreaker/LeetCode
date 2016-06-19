/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function(words, maxWidth) {
    var result = [], i, line = [], lineLen = 0;
    var justifyLine = function(l, len, blLast) {
        var just = '', i, j, spaceLen;
        for (i = 0; i < l.length; i++) {
            just += l[i];
            if (blLast) {
                if (i === l.length - 1) {
                    spaceLen = maxWidth - just.length;
                } else {
                    spaceLen = 1;
                }
            } else {
                if (1 === l.length) {
                    spaceLen = maxWidth - just.length;
                } else if (i === l.length - 1) {
                    spaceLen = 0;
                } else {
                    spaceLen = Math.floor((maxWidth - len) / (l.length - 1));
                    if (i < ((maxWidth - len) % (l.length - 1))) {
                        spaceLen += 1;
                    }
                }
            }
            for (j = 0; j < spaceLen; j++) {
                just += ' ';
            }
        }
        return just;
    };
    for (i = 0; i < words.length; i++) {
        if (lineLen + words[i].length + line.length > maxWidth) {
            result.push(justifyLine(line, lineLen, false));
            line = [];
            lineLen = 0;
        }
        line.push(words[i]);
        lineLen += words[i].length;
    }
    if (line.length) {
        result.push(justifyLine(line, lineLen, true));
    }
    return result;
};