/**
 * @param {string} paragraph
 * @param {string[]} banned
 * @return {string}
 */
var mostCommonWord = function(paragraph, banned) {
    let freq={};
    let result="";
    let maxCount=0;
    let bannedWord= new Set(banned);
    let word=paragraph.toLowerCase().split(/[^a-z]+/);
    for(let i=0;i<word.length;i++){
        words=word[i]
        if(words[i]==""){
            continue;
        }else if(!bannedWord.has(words)){
            freq[words]=(freq[words]||0)+1;
        }
        if(freq[words]>maxCount){
            maxCount=freq[words];
            result=words;
        }
    }
    return result;
};
