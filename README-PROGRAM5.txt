{\rtf1\ansi\ansicpg1252\cocoartf2578
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww14060\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 Name: Richard Cerrato\
ID: 933 448 473\
Program 5\
\
This program creates a linked list. It has various ways of modifying it (insert, push_back, push_front). It also sorts in two different ways, either in ascending order or descending order. On top of that, it checks the list for prime numbers (excluding negative numbers).\
\
To start the program: \
\'97\'97\'97\'97\'97\'97\'97\
\
make\
./project\
\
\'97\'97\'97\'97\'97\'97\'97\
\
Some note worthy things for testing different functions in my program:\
\
- Line 30 vs Line 31 on driver.cpp within main() contain the call for using push_front() or push_back(). \
	-	If you wish to test push_front, make sure that Line 30 is commented out and that Line 31 is un-commented\
	-	If you wish to test push_back, make sure that Line 31 is commented out and that Line 30 is un-commented\
\
- Line 40 on driver.cpp within main() contains the function call for insert()\
	-	If you wish to test the insert() function, uncomment this line.\
	-	You can change the parameters for the insert() function, the first parameter is the int value (val), the second parameter is the index\
	-	IMPORTANT: I set the index to start at \'97\'97> 1 <\'97\'97 (I did this because it helps me think less). So if you wish to insert a value at the first index, pass in insert(value, 1) NOT insert(value, 0). The same goes for any values after.}