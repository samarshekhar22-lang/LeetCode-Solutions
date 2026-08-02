/**
 * @param {string[]} words1
 * @param {string[]} words2
 * @return {number}
 */
var countWords = function(words1, words2) {
    let freq1={};
    let freq2={};
    count=0;
    for(let i=0;i<words1.length;i++){
        let word=words1[i];
        if(freq1[word]){
            freq1[word]++;
        }else{
            freq1[word]=1;
        }

    }
    for(let i=0;i<words2.length;i++){
        let word=words2[i];
        if(freq2[word]){
            freq2[word]++;
        }else{
            freq2[word]=1;
        }
    }
    for(let i=0;i<words1.length;i++){
        let word=words1[i];
        if(freq1[word]==1 && freq2[word]==1){
            count++;
        }
    }
    return count;
};
