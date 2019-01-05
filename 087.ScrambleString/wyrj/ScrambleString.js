/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var isScramble = function(s1, s2) {
    if (s1 === s2) return true;
    if (s1.length !== s2.length) return false;
    if (s1.length <= 2) return (s1 === s2.split('').reverse().join(''));
    
    const f = (r) => {
        let leftLength = 0;
        let map = {};
        let start = r ? s1.length - 1 : 0;
        let end = r ? 0 : s1.length - 1;
        let delta = r ? -1 : 1;
        for (let i = start, len = 1; i !== end; i += delta, len++) {
            const ch = s1.charAt(i);
            const index= map.hasOwnProperty(ch) ? s2.substr(map[ch] + 1).indexOf(ch) + map[ch] + 1 : s2.indexOf(ch);
            if (index === -1) return false;
            map[ch] = index;
            leftLength = Math.max(leftLength, index + 1);
            if (leftLength === len) {
                const lp = r ? s1.substr(i) : s1.substr(0, i + 1);
                const rp = r ? s1.substr(0, i) : s1.substr(i + 1);
                return isScramble(lp, s2.substr(0, len)) && isScramble(rp, s2.substr(len));
            }
        }
        return false;
    };
    
    return f(true) || f(false);
};
