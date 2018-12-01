/**
 * @param {string} s
 * @param {string} t
 * @return {string}
 */
var minWindow = function(s, t) {
    const sMap = {}, dMap = {};
    let wCount = 0;
    for (let i = 0, len = t.length; i < len; i++) {
        let c = t.charAt(i);
        if (sMap.hasOwnProperty(c)) {
            sMap[c] += 1;
        } else {
            sMap[c] = 1;
            dMap[c] = 0;
            wCount += 1;
        }
    }
    let fit = 0;
    let index = {left: 0, right: -1};
    let ans = {string: "", length: s.length + 1};
    const updateAns = (l, r) => {
        const len = r - l + 1;
        if (len < ans.length) {
            ans.length = len;
            ans.string = s.substr(l, len)
        }
    };
    while (index.right < s.length) {
        if (fit < wCount) {
            index.right += 1;
            let c = s.charAt(index.right);
            if (!dMap.hasOwnProperty(c)) {
                continue;
            }
            dMap[c] += 1;
            if (dMap[c] === sMap[c]) {
                fit += 1;
            }
        } else {
            let c = s.charAt(index.left);
            if (dMap.hasOwnProperty(c)) {
                if (dMap[c] === sMap[c]) {
                    fit -= 1;
                    updateAns(index.left, index.right);
                }
                dMap[c] -= 1;
            }
            index.left += 1;
        }
    }
    return ans.string;
};
