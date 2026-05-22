//--17 .1--
/*setTimeout(doSomething,2000);

function doSomething(){
    console.log("Demonstrating the callbacks");
}
console.log("The application is started");*/

//--17 .2--
/*setTimeout(function(){
    console.log("Demonstrating the callbacks");
},2000);

console.log("The application is started");*/

//--17 .3--
/*const doSomething = () => {
    console.log("Demonstrating the callbacks");
};

setTimeout(doSomething, 2000);
console.log("The application is started");*/



//--18--

//--1--
/*const bookArray = [
    { id_book: 1, name: "Everything You Ever Wanted to Know", author: "Upton", isbn: "082305649x" },
    { id_book: 2, name: "Photography", author: "Vilppu", isbn: "205711499" },
    { id_book: 3, name: "Drawing Manual Vilppu", author: "Zelanshi", isbn: "1892053039" },
    { id_book: 4, name: "TBA", author: "Zelanshi", isbn: "0534613932" },
    { id_book: 5, name: "Shaping Space", author: "Speight", isbn: "0534613934" },
    { id_book: 6, name: "Art Since 1940", author: "Speight", isbn: "0131839780" },
    { id_book: 7, name: "Make it in Clay", author: "Stokstad", isbn: "0076417011" },
    { id_book: 8, name: "Art History Vol II & ala carte lab", author: "Stokstad", isbn: "205795617" },
    { id_book: 9, name: "Accounting Concepts", author: "Albrecht", isbn: "1111287856" },
    { id_book: 10, name: "Intermediate Accounting", author: "Stice", isbn: "0538479736" },
    { id_book: 11, name: "Management Info Systems", author: "Marakas", isbn: "9780073376813" },
    { id_book: 12, name: "Management", author: "Williams", isbn: "9780757524028" },
    { id_book: 13, name: "Leadership Wisdom of Jesus", author: "Manz", isbn: "9781609940041" },
    { id_book: 14, name: "Business Law Today", author: "Miller", isbn: "9780324786156" },
    { id_book: 15, name: "Management Info Systems", author: "Marakas", isbn: "9780073376813" }
];

//--2--
console.log(typeof bookArray);

//--3--
for(let x = 1; x <= 15; x++){
    const book = bookArray.find(b => b.id_book === x);
    console.log(book.id_book, "Name:", book.name, "Author:", book.author, "isbn:", book.isbn);
}

//--4--
console.log(bookArray[0]);

//--5--
const book = bookArray.find(b => b.id_book === 1);
console.log(book.name);

//--6--
const len = bookArray.length;
console.log(len);

//--7--
for(let x = 1; x <= 15; x++){
    const book = bookArray.find(b => b.id_book === x);
    console.log("Name:", book.name);
}*/



//--19--
//Tein erilailla entä tehtävän annossa mutta kaikki toimii kuin pitäisi, vaikka huonommin toimisikin.

/*const book = {
   1: { name: "Everything You Ever Wanted to Know", author: "Upton", isbn: "082305649x" },
   2: { name: "Photography", author: "Vilppu", isbn: "205711499" },
   3: { name: "Drawing Manual Vilppu", author: "Zelanshi", isbn: "1892053039" },
   4: { name: "TBA", author: "Zelanshi", isbn: "0534613932" },
   5: { name: "Shaping Space", author: "Speight", isbn: "0534613934" },
   6: { name: "Art Since 1940", author: "Speight", isbn: "0131839780" },
   7: { name: "Make it in Clay", author: "Stokstad", isbn: "0076417011" },
   8: { name: "Art History Vol II & ala carte lab", author: "Stokstad", isbn: "205795617" },
   9: { name: "Accounting Concepts", author: "Albrecht", isbn: "1111287856" },
   10: { name: "Intermediate Accounting", author: "Stice", isbn: "0538479736" },
   11: { name: "Management Info Systems", author: "Marakas", isbn: "9780073376813" },
   12: { name: "Management", author: "Williams", isbn: "9780757524028" },
   13: { name: "Leadership Wisdom of Jesus", author: "Manz", isbn: "9781609940041" },
   14: { name: "Business Law Today", author: "Miller", isbn: "9780324786156" },
   15: { name: "Management Info Systems", author: "Marakas", isbn: "9780073376813" },

   getAllBooks: function()
   {
        for(let x = 1; x <= 100; x++){
            if(this[x]){
                console.log(this[x]);
            }
        }
   },

   getOneBook: function(x)
   {
        console.log(book[x]);
   },

   addBook: function(id_book, name, author, isbn)
   {
        this[id_book] = {name, author, isbn};
   }
}

book.addBook(16, "newBook", "Huhtala", "123123123");
book.getAllBooks();*/



//--20--
//--A--
/*let userValue;
let userValue2;

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.input('Give a number:', userInput => {
    userValue = userInput;
    readline.close();
});

readline.question('Give another number:', userInput => {
    userValue2 = userInput;
    readline.close();
});

if(userValue < userValue2){
    console.log(userValue2, "Number 2 was bigger");
}else if(userValue == userValue2){
    console.log("Numbers are even");
}else{
    console.log(userValue, "Number 1 was bigger");
}*/

//--B--
/*let userWord = "";
let reversedWord;

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

//Im not really sure if the userinput works as intended, i didnt get to test it fully.
readline.question('Input a word:', userInput => {
    userWord = userInput;
    readline.close();
});

reversedWord = userWord.split("").reverse().join("");
if(reversedWord == userWord){
    console.log(userWord, "is a palindrome");
}else{
    console.log(userWord, "is not a palindrome");
}*/



//--21--
//Did not get this working