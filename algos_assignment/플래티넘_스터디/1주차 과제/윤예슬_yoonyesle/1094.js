let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString();

console.log(Number(input).toString(2).match(/1/g).length);
