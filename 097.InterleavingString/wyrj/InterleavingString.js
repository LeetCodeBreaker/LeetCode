/**
 * @param {string} s1
 * @param {string} s2
 * @param {string} s3
 * @return {boolean}
 */
var isInterleave = function(s1, s2, s3) {
    if (s1.length + s2.length !== s3.length) return false;
    if (s1 === '') return s2 === s3;
    if (s2 === '') return s1 === s3;
    
    const f = (s, i) => {
        const c = s.charAt(i);
        let count = 1;
        while (i < s.length && c === s.charAt(i + count)) count++;
        return count;
    }
    
    let index1 = 0;
    let index2 = 0;
    for (let index3 = 0; index3 < s3.length; index3++) {
        const ch1 = s1.charAt(index1);
        const ch2 = s2.charAt(index2);
        const ch3 = s3.charAt(index3);
        
        if (ch1 !== ch3 && ch2 !== ch3) return false;
        else if (ch1 !== ch3) index2++;
        else if (ch2 !== ch3) index1++;
        else {
            const count = [f(s1, index1), f(s2, index2), f(s3, index3)];
            if (count[0] + count[1] < count[2]) return false;
            if (count[0] + count[1] === count[2]) {
                index1 += count[0];
                index2 += count[1];
                index3 += count[2] - 1;
            } else {
                return isInterleave(s1.substr(index1 + count[0]), s2.substr(index2 + count[2] - count[0]), s3.substr(index3 + count[2])) || isInterleave(s1.substr(index1 + count[2] - count[1]), s2.substr(index2 + count[1]), s3.substr(index3 + count[2]));
            }
        }
    }
    return true;
};
