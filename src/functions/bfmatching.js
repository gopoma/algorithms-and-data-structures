function bfmatching(text, pattern) {
    for(let i = 0; i <= text.length - pattern.length; i++) {
        let j = i;
        let k = 0;
        while(text[j] === pattern[k] && k < pattern.length) {
            j++;
            k++;
        }
        if(k === pattern.length) {
            return true;
        }
    }
    return false;
}

module.exports = bfmatching;