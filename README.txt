CMSC140 Project 7 - Name Sorter

This project is built around practicing sorting algorithms and file input/output.

We're meant to use arrays for sorting, but as the project instructions say to plan to sort
"at least 20" names I opted to build this with vectors instead.

It's been a learning process, to say the least. Vectors behave totally differently from
arrays when passed between functions: arrays are automatically referenced, vectors need to 
have an & appended. Arrays are passed with [] in headers, but vectors do not (my first big 
bug was in passing `vector<string>names[]`, which broke the program by passing an array of
vectors! A big thanks to the StackOverflow community in demonstrating to me just how little I
understood when I opted to use vectors.