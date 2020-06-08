# Letter Frequency

It is program that reads a text file and outputs to the display a table
showing the number of times each letter occurs in the file, sorted from the
most frequently occuring letter to the least frequesntly occuring letter.

Sample Example:

Sample Input file:

aAaa
Cc
rRRrrr
z

Sample Output:

r 6
a 4
c 2
z 1

Program Requirements:

1. Allows the user to provide file name of the text file. If an error occurs
   while opening the file, display a message to the user and ensure that the
   program terminates right away.
2. Treat all upper case letter as lower case letter. Furthermore display only
   for the letters that has appeared at least once on the input file.
3. Use a two dimensional array to keep track of the letter counts: One column
   is for the letter and another is for the corresponding counts.
4. Implemant at least following three funcitons:
    
    (a) Write a function that takes the input file stream object and a 2d array as
    parameters and reads all the characters in the input file stream, incrementing
    the count in the 2d array for each letter found. One precondition for this
    function is that the input file stream was successfully opened.
    (b) write a function that reverse sorts the 2d array based on letter
    frequency (a reverse sort will have the largest number first, then the
    next largest, and so on). Implement bubble sort algorithm for your 2d
    array. DO NOT use any library sort functions.
    (c) Write a function to display the final sorted table of letter
    frequencies. This function should only display a letter if its count is
    greater than zero.

