---
title: Database Management System for Interviews Part - 1
date: "2020-07-07
template: post
draft: false
slug: dbms
category: "DBMS"
tags:
  - "dbms"
  - "sql"
description: "A note on Organization of Records in Files, HAVING vs WHERE, Clustered and Non-clustered Index, Functional Dependency, Armstrong's Axioms, Normalization"
---

## Organization of Records in Files

### Heap File Organization

Any record can be placed anywhere in the file where there is space for the record.
There is no ordering of records. Typically, there is a single file for each relation.

### Sequential File Organization

Records are stored in sequential order, according to the value of a "search key"
of each record.

### Hashing File Organization

A hash function is computed on some attribute of each record. The result of the
hash function specifies in which block of the file the record should be placed.

## HAVING vs WHERE

HAVING works on row by row data, WHERE works on aggregate data.

```sql
SELECT
    Student, Score
FROM
    Marks
WHERE
    Score >=40
;
```

```sql
SELECT
    Student, SUM(score)
AS
    total
FROM
    Marks
GROUP BY
    Student
HAVING
    total > 70
;
```

## Clustered and Non-Clustered Index

Clustered indices are indices whose order of the rows in the database correspond
to the order of the rows in the index. Here, search key also defines the sequential
order of the file.

Non-clustered index is a separate structure from the data stored in a table used to
improve the performance of frequent queries. Here search key specifies an order
different from the sequential order of the file.

Clustering indices are also called primary indices whereas non-clustered indices
are called secondary indices.

## Clustered vs Non-clustered index

| Clustered Index | Non-clustered Index |
| ----------------|-------------------- |
|Clustered index modifies the way records are stored in a database based on the indexed column | Non-clustered index creates a separate structure within the table which references the original table|
|A table can have only a single clustered index | A table can have multiple non-clustered indices|
|Relatively slower | Relatively faster|

## Standard Rules of Functional Dependency (FD)

### Basic Rules over FDs/Armstrong's Axioms

1. **Reflexibility**: If $\alpha$ and $\beta$ are attributes in $R$ and $\beta \subset \alpha$, then $\alpha \rightarrow \beta$ holds.
2. **Augmentation**: If $\alpha \rightarrow \beta$ holds and $\gamma$ is another
   set of attributes, then $\alpha\gamma\rightarrow\beta\gamma$ holds.
3. **Transitivity**: If $\alpha\rightarrow\beta$ and $\beta\rightarrow\gamma$ hold,
   then $\alpha\rightarrow\gamma$ also holds.

### Derived Rules

1. **Union**: If $\alpha\rightarrow\beta$ and $\alpha\rightarrow\gamma$ hold, then
   $\alpha\rightarrow\beta\gamma$ holds.
2. **Decomposition**: If $\alpha\rightarrow\beta\gamma$ holds, then
   $\alpha\rightarrow\beta$ and $\alpha\rightarrow\gamma$ hold.
3. **Pseudotransitivity**: If $\alpha\rightarrow\beta$
   and $\beta\gamma\rightarrow\delta$ hold, then $\alpha\gamma\rightarrow\delta$
   holds.

## Normalization

### Reasons

1. To minimize redundancy.
2. To minimize insertion, deletion and update anomaly.

### Types

1. **First Normal Form (1NF)**: It does not allow multi-valued attributes.
2. **Second Normal Form (2NF)**: A relation is said to be in 2NF iff it is 1NF and
   every non-prime attribute is fully functional dependent on its primary key.
3. **Third Normal Form (3NF)**: A relation is said to be in 3NF iff it is 2NF and
   every non-prime attribute is non-transitively dependent on its primary key.
4. **Boyce-Codd Normal Form (BCNF)**: A relation is said to be in BCNF iff all
   the determinants are candidate keys.

## ACID Properties

A transaction is a single logical unit of work which accesses and possibly
modifies the contents of a database. Transactions access data using read and write
operations. In order to maintain consistency in a database, before and after the
transaction, certain properties are followed.

- **Atomicity (A)**: Either all or none transaction should take place.
- **Consistency (C)**: Before and after transaction, the data should be consistent.
- **Isolation (I)**: One transaction should be isolated from another.
- **Durability (D)**:  Once the transaction has completed execution, the updates
  and modifications to the database are transferred from MM to disk and they
  persist even if a system failure occurs.

<!--

## Create a Table in SQL

```sql
CREATE TABLE Student_info
(
ROLL_NO int(10) primary key,
NAME varchar(20),
DEPARTMENT varchar(20),
);
insert into Student_info values(1410110405, 'H Agarwal', 'CSE') 
insert into Student_info values(1410110404, 'S Samadder', 'CSE')
insert into Student_info values(1410110403, 'MD Irfan', 'CSE') 

SELECT * FROM Student_info

## What is a Cursor? How to use a Cursor?
A database cursor is a control structure that allows for traversal of records in
a database. Cursors, in addition, facilitates processing after traversal, such
as retrieval, addition and deletion of database records. They can be viewed as a
pointer to one row in a set of rows. 

### Working with SQL Cursor
`DECLARE` a cursor after any variable declaration. The cursor declaration must
always be associated with a `SELECT` Statement.
Open cursor to initialize the result set. The OPEN statement must be called before fetching rows from the result set.
FETCH statement to retrieve and move to the next row in the result set.
Call the CLOSE statement to deactivate the cursor.
Finally use the DEALLOCATE statement to delete the cursor definition and release the associated resources.
```sql   
DECLARE @name VARCHAR(50)      /* Declare All Required Variables */

DECLARE db_cursor CURSOR FOR      /* Declare Cursor Name*/
SELECT name
FROM myDB.students
WHERE parent_name IN ('Sara', 'Ansh')

OPEN db_cursor      /* Open cursor and Fetch data into @name */ 
FETCH next
FROM db_cursor
INTO @name

CLOSE db_cursor      /* Close the cursor and deallocate the resources */
DEALLOCATE db_cursor
```

## What is Collation? What are the different types of Collation Sensitivity?
Collation refers to a set of rules that determine how data is sorted and compared.
Rules defining the correct character sequence are used to sort the character data.
It incorporates options for specifying case-sensitivity, accent marks, kana character
types and character width. Below are the different types of collation sensitivity: 

- **Case** sensitivity: A and a are treated differently.

- **Accent** sensitivity: a and á are treated differently.

- **Kana** sensitivity: Japanese kana characters Hiragana and Katakana are treated differently.

- **Width** sensitivity: Same character represented in single-byte (half-width)
and double-byte (full-width) are treated differently.

## What is a Stored Procedure?
A stored procedure is a subroutine available to applications that access a
relational database management system (RDBMS). Such procedures are stored in the
database data dictionary. The sole disadvantage of stored procedure is that it
can be executed nowhere except in the database and occupies more memory in the
database server. It also provides a sense of security and functionality as users
who can't access the data directly can be granted access via stored procedures.

```sql
DELIMITER $$
CREATE PROCEDURE FetchAllStudents()
BEGIN
SELECT *  FROM myDB.students;
END $$
DELIMITER
```

## What is a Recursive Stored Procedure?
A stored procedure which calls itself until a boundary condition is reached, is
called a recursive stored procedure. This recursive function helps the programmers
to deploy the same set of code several times as and when required. Some SQL programming
languages limit the recursion depth to prevent an infinite loop of procedure calls
from causing a stack overflow, which slows down the system and may lead to system crashes.

```sql 
DELIMITER $$              /* Set a new delimiter => $$ */
CREATE PROCEDURE calctotal(    /* Create the procedure */
    IN number INT,            /* Set Input and Ouput variables */
    OUT total INT
) BEGIN
DECLARE score INT DEFAULT NULL;      /* Set the default value => "score" */
SELECT awards FROM achievements      /* Update "score" via SELECT query */
WHERE id = number INTO score;
IF score IS NULL THEN SET total = 0;      /* Termination condition */
ELSE
CALL calctotal(number+1);      /* Recursive call */
SET total = total + score;      /* Action after recursion */
END IF;
END $$              /* End of procedure */
DELIMITER ;              /* Reset the delimiter */
``` -->

## References

Portions of this note is taken from geeksforgeeks and from Database System
Concepts by Silberschatz, Kroth and Srinivasan, 6th edition book.
