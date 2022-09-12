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

(() => {
    console.log(bfmatching("A good framework", "good")); // true
    console.log(bfmatching("A good framework", "god")); // false
    console.log(bfmatching("Programming with C++ is like shooting oneself", "++")); // true
    console.log(bfmatching("Programming with C++ is like shooting oneself", "F++")); // false
    console.log(bfmatching("Something", "ing")); // true
    console.log(bfmatching("Something", "ingx")); // false
})()