// This is a file meant to test and document various C functionalities

#include <stdio.h> // This is called a directive
#define ESC '\x1b' // This is how you "define" things; in this case, the ASCII escape character. This is a "macro".
typedef int IntInDisguise; // the compiler will now recognize "IntInDisguise" as an int type

int print2DArray(int n, int m, const int arr[n][m]);
int *returnArray(int c);

int main(void) {
    int myInt, myOtherInt;
    float myFloat, myOtherFloat;
    float pi = 3.14159f; // the "f" ensures that the number is a float (rather than, say, a double)
    
    // input-output help stuff
    ///////////////////////////////////////////////
    
    printf("Enter an integer (or 0/1/2/3 to skip)\n");
    scanf("%d", &myInt);
    if (myInt == 0) goto SkipToZero;
    if (myInt == 1) goto SkipToOne;
    if (myInt == 2) goto SkipToTwo;
    if (myInt == 3) goto SkipToThree;
    printf("Now a floating point number\n");
    scanf("%f", &myFloat);
    printf("printing int: %d\nprinting float: %f\n", myInt, myFloat);
    // formatting rule: %m.pX or %-m.pX
    // m = minimum field width
    // p = precision
    // X = identifier (d = int, f = float, e = float in scientific notation, g = either e or f basically, etc.)
    printf("Formatted int:\n%8.4d\nFormatted float:\n%8.3f\n", myInt, myFloat);
    // scanning multiple inputs at a time
    printf("now give an int and a float\n");
    scanf("%d%f", &myOtherInt, &myOtherFloat);
    printf("Other int:\n%.5d\nOther float:\n%.2f\n", myOtherInt, myOtherFloat);
    
    ///////////////////////////////////////////////
    
SkipToZero: {}
    
    // this is how you declare variables
    int i;
    int j;
    
    // these are expressions with side effects
    i = 2; i++; ++i;
    
    // this is an expression without a side effect. It is commented out because the compiler gives a warning
    // 5 + 7;
    
    // Accessing the value of i while modifying it in the same expression cause undefined behavior. That is bad.
    // while (i < N)
    //     a[i] = b[i++];
    
    // this assigns the value of (i == 4) to j. Since i does equal 4, the value of (i == 4) is 1,
    // if it were false, the value would be 0.
    j = (i == 4);
    
    // i = 4, j = 1
    printf("\n\ni = %d, j = %d\n", i, j);
    
    // evaluates "=" right associative. Expression j = 0 has value 0, with side effect of setting j = 0.
    // i is then set to the value of (j = 0), which is 0.
    i = j = 0;
    printf("SET BOTH TO ZERO\n");
    
    // ++X adds before "fetching" expressions value, X++ adds after the fetch
    printf("i++ = %d, ++j = %d\n", i++, ++j);
    printf("i = %d, j = %d\n", i, j);
    j += 2; // this comes in handy later...
    
    ////////////////////////////////////////////////
    
    // boolean values are essentially just ints. False is 0, everything else is true.
    if (-7) printf("\n\n-7 is true.\n");
    if (0)
        printf("0 is true???\n");
    else
        printf("0 is false.\n");
    
    // this is cool. Read as "if (i > j) then (i) else (j)".
    printf("what is the value of the largest value out of i and j?: %d\n", i > j ? i : j);
    
    switch (j) {
        case 0:
            printf("j = 0\n");
            break;
        case 1:
            printf("j = 1\n");
            break;
        case 2:
            printf("j = 2\n");
            break;
        case 3:
            printf("j = 3\n");
            break;
        default:
            printf("j < 0 || j > 3\n");
            break;
    }
    
    printf("5 BEEPS!\n");
    int t = 5;
    while (1) {
        printf("\a");
        if (t <= 0) break;
        t--;
    }
    
    ////////////////////////////////////////////////
    
SkipToOne: {}
    
    // some different types of ints. Bits sizes are particular to my machine.
    
    unsigned int ui; // 32 bits
    short int si; // 16 bits
    unsigned long long int ulli; // 64 bits. long int also uses 64. long long types only in C99 (not C89)
    
    printf("input a number in decimal (must not begin with 0)\n");
    scanf("%u", &ui);
    printf("input a number in octal (must begin with 0)\n");
    scanf("%hd", &si);
    printf("input a number in hexidecimal (must begin with 0x)\n");
    scanf("%llx", &ulli);
    printf("sum in decimal: %lld\n", ui + si + ulli);
    printf("sum in octal: %llo\n", ui + si + ulli);
    printf("sum in hexidecimal: %llx\n", ui + si + ulli);
    // these sums were calculated via implicit conversion done by the compiler.
    // machines typically can't perform arithmetic on different types, such as a short with a long for example.
    
    ////////////////////////////////////////////////
    
SkipToTwo: {}
    
    char ch;
    char gotChar;
    
    printf("type a character\n");
    // notice the space before %c in scanf. This skips all white space
    scanf(" %c", &ch); // scanf leaves the new line character to be read by the next call reading input
    printf("type another character\n");
    
    // nice way to skip to the next line
    while (getchar() != '\n')
        ;
    
    gotChar = getchar(); // it would seem that getchar actually leaves \n for the next input read also...
    printf("the characters you typed were: |%c|, and |%c|\n", ch, gotChar);
    
    printf("bytes of a char: %lu\n", sizeof(char));
    
    /////////////////////////////////////////////////
    
SkipToThree: {}
    
    // lotsa ways to declare an array
    
    int a[10]; // declares an int array named "a" of size 10
    int b[8] = {1, 2, 3, 4, 5}; // only first 5 elements are as specified. The rest are 0.
    int c[] = {1, 2, 3}; // this works too.
    int d[15] = {[1] = 1, [14] = 4, [4] = 30}; // the other elements will be 0.
    int e[] = {[4] = 1, [9] = 3}; // makes array size as small as it can, in this case, of size 10.
    int f[10] = {1, 2, [3] = 4, 5, [9] = 10}; // {1, 2, 0, 4, 5, 0, 0, 0, 0, 10}
    
#define N 10
    
    int z[N]; // deifning macros works too
    
    // idiom for getting amount of elements of an array
    printf("Amount of elements in array a: %d\n", (int) (sizeof(a) / (sizeof(a[0]))));
    
    int numRows, numCols;
    
    printf("Enter number of rows\n");
    scanf("%d", &numRows);
    printf("Enter number of columns\n");
    scanf("%d", &numCols);
    
    // notice how twoD is declared to be a length not known until execution of the program. This is called a VLA
    // (variable length array) and it is only available in C99. The array length is determined during execution
    // rather than during compile time
    int row, col, twoD[numRows][numCols]; // declares an array (along with two ints)
    double dubDubs[3][2] = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}}; // declares and initializes
    
    for (row = 0; row < numRows; row++)
        for (col = 0; col < numCols; col++)
            twoD[row][col] = row * col;
    
    // prints array (in kind of a sneaky way, taking advantage of the way arrays store its elements)
    for (i = 0; i < numRows * numCols; i++) {
        
        printf("|%2d|", twoD[0][i]);
        if ((i + 1) % numCols == 0)
            printf("\n");
    }
    
    //////////////////////////////////////////////////
    
    int character = returnArray('A')[0];
    int lowerCharacter = returnArray('A')[1];
    printf("character: ");
    putchar((char) character);
    printf("\nlowerCharacter: ");
    putchar((char) lowerCharacter);
    printf("\n");
    
    return 0;
}

/*--------------------FUNCTIONS------------------------*/

int print2DArray(int n, int m, const int arr[n][m]) {
    
    int i;
    
    for (i = 0; i  < n * m; i++) {
        
        printf("|%2d|", arr[n][m]);
        
    }
    
    return 1;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - */

int *returnArray(int c)
{
    int a[2];
    
    a[0] = c;
    a[1] = c + 32;
    
    return &a[0];
}
