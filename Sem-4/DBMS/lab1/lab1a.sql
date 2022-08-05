CREATE DATABASE IF NOT EXISTS lab_1;
USE lab_1;
CREATE TABLE IIITDM if not exists (
  Faculty_name varchar(255),
  Student_ID int NOT NULL UNIQUE,
  Building_Name varchar(255)
);
CREATE TABLE Faculty (
  Faculty_ID int NOT NULL UNIQUE,
  Faculty_name varchar(255),
  department varchar(255),
  Subject varchar(255)
);
CREATE TABLE Student (
  Student_ID int NOT NULL UNIQUE,
  Student_name varchar(255),
  department varchar(255),
  Course varchar(255)
);
CREATE TABLE Course (
  department varchar(255),
  subject varchar(255),
  course_ID varchar(255) NOT NULL UNIQUE
);
CREATE TABLE Building (
  Building_name varchar(255),
  Room_no int NOT NULL UNIQUE,
  Floor_no int
);
show TABLES;
select
  *
FROM
  Faculty;
select
  *
FROM
  Building;
select
  *
FROM
  IIITDM;
select
  *
from
  Student;
select
  *
FROM
  Course;
INSERT INTO
  IIITDM
VALUES
  ('Proffesor 1', 121144, 'Building 1');
INSERT INTO
  IIITDM
VALUES
  ('Proffesor 2', 254354, 'Building 2');
INSERT INTO
  IIITDM
VALUES
  ('Proffesor 3', 346363, 'Building 3');
INSERT INTO
  IIITDM
VALUES
  ('Proffesor 4', 453445, 'Building 4');
INSERT INTO
  IIITDM
VALUES
  ('Proffesor 5', 242534, 'Building 5');
INSERT INTO
  IIITDM
VALUES
  ('Proffesor 6', 324523, 'Building 6');
INSERT INTO
  IIITDM
VALUES
  ('Proffesor 7', 432545, 'Building 7');
INSERT INTO
  IIITDM
VALUES
  ('Proffesor 8', 324563, 'Building 8');
INSERT INTO
  IIITDM
VALUES
  ('Proffesor 9', 453455, 'Building 9');
INSERT INTO
  IIITDM
VALUES
  ('Proffesor 10', 325435, 'Building 10');
INSERT INTO
  Faculty
VALUES
  (4343524, 'Professor 1', 'CSE', 'DAA');
INSERT INTO
  Faculty
VALUES
  (353536, 'Professor 2', 'CSE', 'TOC');
INSERT INTO
  Faculty
VALUES
  (343544, 'Professor 3', 'ECE', 'COA');
INSERT INTO
  Faculty
VALUES
  (
    643756,
    'Professor 4',
    'CSE',
    'Probability'
  );
INSERT INTO
  Faculty
VALUES
  (643534, 'Professor 5', 'CSE', 'Calculus');
INSERT INTO
  Faculty
VALUES
  (
    6454354,
    'Professor 6',
    'CSE',
    'Differential'
  );
INSERT INTO
  Faculty
VALUES
  (
    635373,
    'Professor 7',
    'ECE',
    'Differential'
  );
INSERT INTO
  Faculty
VALUES
  (1783244, 'Professor 8', 'ECE', 'Calculus');
INSERT INTO
  Faculty
VALUES
  (1735354, 'Professor 9', 'MSM', 'Calculus');
INSERT INTO
  Faculty
VALUES
  (
    1252723,
    'Professor 10',
    'MSM',
    'Differential'
  );
INSERT INTO
  Building
VALUES
  ('Lab_block', 13, 1);
INSERT INTO
  Building
VALUES
  ('Lab_block', 24, 2);
INSERT INTO
  Building
VALUES
  ('Lab_block', 45, 4);
INSERT INTO
  Building
VALUES
  ('Lab_block', 65, 6);
INSERT INTO
  Building
VALUES
  ('Lab_block', 75, 7);
INSERT INTO
  Student ()
VALUES(1, "Student 1", "CSE", "COA");
INSERT INTO
  Student ()
VALUES(2, "Student 2", "CSE", "Probability");
INSERT INTO
  Student ()
VALUES(3, "Student 3", "CSE", "DBMS");
INSERT INTO
  Student ()
VALUES(4, "Student 4", "ECE", "COA");
INSERT INTO
  Student ()
VALUES(5, "Student 5", "MSM", "Probability");
INSERT INTO
  Student ()
VALUES(6, "Student 6", "ECE", "DBMS");