create database dblab1;
use dblab1;
create table Student(
	RollNo char(8),
	SName varchar(20),
	Gender char(1),
	City varchar(20),
	PRIMARY KEY (RollNo)
);

create table Course(
	CCode char(5),
	CName varchar(20),
	Credit smallint,
	PRIMARY KEY (CCode)
);

create table Enrolled(
	RollNo char(8),
	CCode char(5),
	YoE int,
	FOREIGN KEY (RollNo) REFERENCES Student(RollNo),
	FOREIGN KEY (CCode) REFERENCES Course(CCode)
);

alter table Course add CType varchar(20);

alter table Student add Email varchar(30);

INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('CS001', 'Programing', '4', 'Core');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('CS002', 'Daa', '4', 'Core');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('CS003', 'Dsa', '5', 'Core');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('MA001', 'Calculus', '3', 'Open Elective');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('MA002', 'DE', '4', 'Open Elective');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('MA003', 'LA', '5', 'Open Elective');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('EC001', 'ECircuits', '4', 'Elective');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('EC002', 'Waves', '4', 'Elective');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('ME001', 'Materials', '4', 'Elective');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('ME002', 'EGraphics', '3', 'Elective');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('CS501', 'Oops', '5', 'Core');
INSERT INTO `dblab1`.`Course` (`CCode`, `CName`, `Credit`, `CType`) VALUES ('CS502', 'DScience', '5', 'Core');



INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('CS20B1', 'Mani', 'M', 'Hyd', 'mani@gmail.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('CS20B2', 'Jashwant', 'M', 'Hyd', 'jash@gmail.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('CS20B3', 'Lahari', 'F', 'Khammam', 'lah@gmail.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('CS20B4', 'Jaga', 'M', 'Chennai', 'jag@linux.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('CS20B5', 'Nagasai', 'M', 'Bnglr', 'nsv@yahoo.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('EC20B1', 'Hemanth', 'M', 'Vjr', 'hm@gmail.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('EC20B2', 'Hema', 'F', 'Vzg', 'h@.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('EC20B3', 'Vikas', 'M', 'Delhi', 'vks@gmail.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('ME20B1', 'Sriram', 'M', 'Hyd', 'Srram@gmail.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('ME20B2', 'Srileela', 'F', 'Bnglr', 'leela@gmail.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('1901CS99', 'Srileela', 'F', 'Bnglr', 'leela@gmail.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('CS20B6', 'Fema-1', 'F', 'Delhi', 'fem1@gmail.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('CS20B7', 'Fema-2', 'F', 'Delhi', 'fem2@gmail.com');
INSERT INTO `dblab1`.`Student` (`RollNo`, `SName`, `Gender`, `City`, `Email`) VALUES ('CS20B8', 'Fema-3', 'F', 'Delhi', 'fem@yahoo.com');


INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B1', 'CS001', '2017');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B2', 'CS002', '2018');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B3', 'CS003', '2019');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B4', 'MA001', '2020');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B5', 'MA002', '2018');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('EC20B1', 'MA003', '2020');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('EC20B2', 'EC001', '2021');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('EC20B3', 'EC002', '2017');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('ME20B1', 'ME001', '2018');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('ME20B2', 'ME002', '2020');



INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B1', 'CS002', '2018');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B1', 'CS003', '2017');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B1', 'MA001', '2019');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B1', 'MA002', '2020');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('1901CS99', 'EC002', '2018');

INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B6', 'CS003', '2017');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B7', 'CS003', '2019');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B8', 'CS001', '2020');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B8', 'CS002', '2020');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B8', 'CS003', '2020');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B8', 'MA001', '2020');
INSERT INTO `dblab1`.`Enrolled` (`RollNo`, `CCode`, `YoE`) VALUES ('CS20B8', 'MA002', '2020');

-- B) Find the name of all the courses which start with “CS” code.
SELECT CName from Course where CCode like 'CS%';

-- C) Find the name of the male students who have at least two “a”s in their names.
SELECT SName from Student where SName like '%a%a%' and gender="M";

-- D) Find the students who have not enrolled in between 2018 and 2019.
Select RollNo from enrolled where YoE not between 2018 and 2019;

-- E) Find the course with least credit.
SELECT min(Credit) from Course;


-- F) Find the name of the Course which is not enrolled by any students in the year 2020.
Select distinct Course.CName from Course INNER JOIN Enrolled On Course.CCode = Enrolled.CCode where Enrolled.YoE!=2020;

-- G) Find the total number of students city wise.
SELECT count(RollNo) from Student group by city;

-- H) Find the rollno of the students who have enrolled to 5 number of courses.
select RollNo from enrolled group by RollNo having count(RollNo)=5;

-- I) Find the total number of courses enrolled by student with roll no “1901CS99”.
SELECT count(CCode) from Enrolled where RollNo = '1901CS99';

-- J) Find all the 5 level courses (the digits parts of the course code should start with 5).
SELECT * from Course where CCode like '__5%';

-- K) Count the number of students containing “CS” as part of the RollNo.
SELECT count(RollNo) from Student where RollNo like 'CS%';

-- L) Find the roll no of students who have enrolled in more than 4 courses in the year 2020.
select RollNo from enrolled where YoE=2020 group by RollNo having count(RollNo)>4;

-- M) Find the course code which is taken by most number of female students who are from Delhi
-- city.
select CCode, count(CCode) from Enrolled where RollNo in(select RollNo from Student where City="Delhi" and Gender="F") group by CCode order by count(CCode) desc limit 1;


-- N) Find the name of all the students whose email ids have “gmail.com” or “yahoo.com” as the
-- domain name.
SELECT SName from Student where Email like '%gmail.com' or Email like '%yahoo.com';
