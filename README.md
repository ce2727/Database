# Database
### Database made for CSC173 at the University of Rochester
##### Created by Clay Emmel, Fall 2017

#### Data Stored:
* Names
* Student ID's
* Addresses
* Phone Numbers
* Courses
* Grades
* Course Rooms
* Course Dates
* Course Times
* Course Prerequisites

#### Relations (Columns/Tuples)
* StudentID-Name-Address-Phone
* Course-StudentID-Grade
* Course-Prerequisite
* Course-Day-Hour
* Course-Room

### How to Test and Build

#### Making Queries
The database handles two built in queries:
You can edit data input and queries in '**Client.c**'

* What grade did 'Name' get in 'Course'?
 (Notes: 
 To keep things simple, the query only takes in continuous names such as '_John_' or '_Peter_'.
 Putting in '_John Sullivan_' would throw off the very primitive parser as it's two tokens.)
 
 
* Where is 'Name' at 'Time' on 'Day'?
(Notes:
The same goes for the names, as stated above. 
For times, input in the format of "##am/pm". Ex: 7am, 12pm etc.
For the day, use single characters to represent days of the week such as M,T,W,R,F etc.)

**_Warning_** - Be careful with query syntax or the program may crash! O.o

#### Building the database
Complile the following files into an application
* Client.c
* Relations.c
* Database.c
* Query.c
* Algebra.c

**GCC Copy Paste**:     gcc Client.c Relations.c Database.c Query.c Algebra.c
