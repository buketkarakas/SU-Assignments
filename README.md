# SU-Assignments

# CS 300 - Data Structures Homeworks

[SKYLINE PROBLEM](https://github.com/buketkarakas/SU-Assignments/tree/master/CS300%20Data%20Structures/SkylineProblem)

The İstanbul skyline problem, often mistakenly called the New York skyline problem, is the problem of drawing the skyline of a city given a set of buildings of that city. In this homework you will write a program whose input is a list of the locations and sizes of buildings, and whose output is a description of the visible skyline, that is, how the city looks as an outline, when viewed from a distance. For a real-life version of this problem, go to Vaniköy on the Asian side of the Bosphorus, and, as you sip your tea, contemplate on how the skyline will look as the sun sets over the European side.

To make things simple, the buildings will be given using just two dimensions, x and y, rather than three, ignoring the depth value. (Think of x as horizontal and y as vertical.) Each building will be a rectangle with its base on the x-axis. Thus, a building can be completely described by giving the x-coordinates of its left and right sides, and the y coordinate (or height) of its top side. The input will be read from standard input. The first line of the input indicates how many buildings there are in the city, and each succeeding line will indicate the x-coordinate of the left side of a building followed by the ycoordinate of the top side of the building, followed by the x-coordinate of the right side of the building.

[SEARCH ENGINE](https://github.com/buketkarakas/SU-Assignments/tree/master/CS300%20Data%20Structures/SearchEngine)

In this homework, we are going to learn about how search engines such as Google do their searches really fast. These search engines search hundreds of millions web pages to see if they have the words that you have typed, and they can do this for thousands of users at a given time. In order to do these searches really fast, search engines such as Google do a lot of what we call preprocessing of the pages they search; that is, they transform the contents of a web page (which for the purposes of this homework, we will assume to consist of only strings) into a structure that can be searched very fast. Here is the basic idea: • Let us assume we have millions of documents, D1, D2, . . . D19234678, . . ., each consisting of hundreds or thousands of words. We identify each document by its number, e.g., 1, 2, . . . 19234678, . . . .

• Since almost all the time these documents contain material in a human language, many words (such as the, or geliyor ) most likely appear in many of the documents in a given language. Some words such as the or bir appear in perhaps all documents in a given language, while words such as Llanfairpwllgwyngyllgogerychwyrndrobwllllantysiliogogogoch1 or esneyemeyense2 appear in relatively few documents.

• For each unique word, we construct a linked list of document numbers representing the set of documents that word appears in. We ignore details such as how many times a word appears in that document or where in the document it appears in, etc. For instance if the word Sabanci appears in documents D2, D4, D6, we associate the list (2, 4, 6) with the string Sabanci. So, preprocessing involves finding ALL unique words AND creating a list of ALL documents numbers for the documents that contain that word somewhere.

• Once we finish preprocessing, we are ready to answer queries. Suppose we want to find all documents that contain the words Sabanci and University. We first identify the list of documents containing Sabanci and then identify the list of documents containing University and then intersect these, to get the list of documents containing both strings, and return the documents corresponding to these results as the answer. Of course, if you have more keywords, you keep on intersecting the result of the first intersection with the list for the third keyword, etc. Here is how we expect you to attack this problem:

• Our main database of strings will be implemented as a list.3 Each object we store in that list will be a pair of strings and their associated document lists. If in addition, University appears in documents D3, D6, D9, D12, and bilgisayar appears in documents D6, D9, D17, D21, our database will conceptually look like Figure 1.

• You should see that we use lists for two purposes: we use lists to store the list of documents associated with each string and we use lists to store the string-document list pairs. You may want to make sure that that list sorted based on the string values. It is also important that the list containing the document numbers associated with a string, is sorted in ascending order of the documents numbers.

• When you are given a query - a series of words - you search the database to locate the list nodes containing the words, and then retrieve their associated document lists and then intersect them.

[DATA COMPRESSION LZW](https://github.com/buketkarakas/SU-Assignments/tree/master/CS300%20Data%20Structures/DataCompressionLZW)

Credits to Sabancı University 300 DataStructure Course

In this assignment you will implement an algorithm for data compression. The purpose of data compression is to take a file A and, within a reasonable amount of time, transform it into another file B in such a way that: (i) B is smaller than A, and (ii) it is possible to reconstruct A from B. A program that converts A into B is called a compressor, and one that undoes this operation is called an uncompressor. Popular programs such as WinZip perform this function, among others. Compressing data enables us to store data more efficiently on our storage devices or transmit data faster using communication facilities since fewer bits are needed to represent the actual data.

Of course, a compressor cannot guarantee that the file B will always be smaller than A. It is easy to see why: if this were possible, then imagine what would happen if you just kept iterating the method, compressing the output of the compressor. In fact, with a little bit of thinking, you should be able to convince yourself that any compressor that compresses some files must also actually enlarge some files. (Understand why this should be the case!) Nevertheless, compressors tend to work pretty well on the kinds of files that are typically found on computers, and they are widely used in practice.
