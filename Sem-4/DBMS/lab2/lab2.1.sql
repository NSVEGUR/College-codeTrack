create database dblab;
create table Student(Rollno varchar(10), SName varchar(10), City varchar(10), PRIMARY KEY(Rollno));
create table Course(CID varchar(10), CName varchar(10), Credit int(100), PRIMARY KEY(CID));

INSERT INTO `dblab`.`Course` (`CID`, `CName`, `Credit`) VALUES ('1', 'PSP', '4');
INSERT INTO `dblab`.`Course` (`CID`, `CName`, `Credit`) VALUES ('2', 'DSA', '4');
INSERT INTO `dblab`.`Course` (`CID`, `CName`, `Credit`) VALUES ('3', 'DAA', '4');
INSERT INTO `dblab`.`Course` (`CID`, `CName`, `Credit`) VALUES ('4', 'DBMS', '4');
INSERT INTO `dblab`.`Course` (`CID`, `CName`, `Credit`) VALUES ('5', 'Calculus', '3');
INSERT INTO `dblab`.`Course` (`CID`, `CName`, `Credit`) VALUES ('6', 'Waves', '3');
INSERT INTO `dblab`.`Course` (`CID`, `CName`, `Credit`) VALUES ('7', 'ENV', '2');
INSERT INTO `dblab`.`Course` (`CID`, `CName`, `Credit`) VALUES ('8', 'CONS', '2');
INSERT INTO `dblab`.`Course` (`CID`, `CName`, `Credit`) VALUES ('9', 'Materials', '4');
INSERT INTO `dblab`.`Course` (`CID`, `CName`, `Credit`) VALUES ('10', 'Graphics', '4');


INSERT INTO `dblab`.`Student` (`Rollno`, `SName`, `City`) VALUES ('CS20B1016', 'Nagasai', 'Bnglr');
INSERT INTO `dblab`.`Student` (`Rollno`, `SName`, `City`) VALUES ('CS20B1002', 'Mani', 'Hyd');
INSERT INTO `dblab`.`Student` (`Rollno`, `SName`, `City`) VALUES ('CS20B1007', 'Jashwanth', 'Hyd');
INSERT INTO `dblab`.`Student` (`Rollno`, `SName`, `City`) VALUES ('CS20B1024', 'Praveen', 'Khammam');
INSERT INTO `dblab`.`Student` (`Rollno`, `SName`, `City`) VALUES ('CS20B1025', 'Vineeth', 'Kadapa');
INSERT INTO `dblab`.`Student` (`Rollno`, `SName`, `City`) VALUES ('EC20B1001', 'Hemanth', 'Hyd');
INSERT INTO `dblab`.`Student` (`Rollno`, `SName`, `City`) VALUES ('EC20B1016', 'Sriram', 'Hyd');
INSERT INTO `dblab`.`Student` (`Rollno`, `SName`, `City`) VALUES ('EC20B1025', 'Dhanush', 'Rjy');
INSERT INTO `dblab`.`Student` (`Rollno`, `SName`, `City`) VALUES ('ME20B1001', 'Vikas', 'Vizag');
INSERT INTO `dblab`.`Student` (`Rollno`, `SName`, `City`) VALUES ('ME20B1016', 'Anil', 'Tpt');


select * from Course;
select * from Student;

alter table Student add department varchar(15);
alter table Student add marks int(100);


UPDATE `dblab`.`Student` SET `department` = 'cse', `marks` = '80' WHERE (`Rollno` = 'CS20B1002');
UPDATE `dblab`.`Student` SET `department` = 'cse', `marks` = '90' WHERE (`Rollno` = 'CS20B1007');
UPDATE `dblab`.`Student` SET `department` = 'cse', `marks` = '80' WHERE (`Rollno` = 'CS20B1016');
UPDATE `dblab`.`Student` SET `department` = 'cse', `marks` = '80' WHERE (`Rollno` = 'CS20B1024');
UPDATE `dblab`.`Student` SET `department` = 'cse', `marks` = '70' WHERE (`Rollno` = 'CS20B1025');
UPDATE `dblab`.`Student` SET `department` = 'ece', `marks` = '70' WHERE (`Rollno` = 'EC20B1001');
UPDATE `dblab`.`Student` SET `department` = 'ece', `marks` = '80' WHERE (`Rollno` = 'EC20B1016');
UPDATE `dblab`.`Student` SET `department` = 'ece', `marks` = '90' WHERE (`Rollno` = 'EC20B1025');
UPDATE `dblab`.`Student` SET `department` = 'Mechanical', `marks` = '100' WHERE (`Rollno` = 'ME20B1001');
UPDATE `dblab`.`Student` SET `department` = 'Mechanical', `marks` = '60' WHERE (`Rollno` = 'ME20B1016');





update Student set marks=70 where (department='Mechanical');

alter table Course modify column Credit varchar(5);

alter table Course add courseAdmissionDate DATE;

UPDATE `dblab`.`Course` SET `courseAdmissionDate` = '2020-12-02' WHERE (`CID` = '1');
UPDATE `dblab`.`Course` SET `courseAdmissionDate` = '2021-03-28' WHERE (`CID` = '10');
UPDATE `dblab`.`Course` SET `courseAdmissionDate` = '2021-03-28' WHERE (`CID` = '2');
UPDATE `dblab`.`Course` SET `courseAdmissionDate` = '2021-08-01' WHERE (`CID` = '3');
UPDATE `dblab`.`Course` SET `courseAdmissionDate` = '2022-01-03' WHERE (`CID` = '4');
UPDATE `dblab`.`Course` SET `courseAdmissionDate` = '2020-12-02' WHERE (`CID` = '5');
UPDATE `dblab`.`Course` SET `courseAdmissionDate` = '2021-03-28' WHERE (`CID` = '6');
UPDATE `dblab`.`Course` SET `courseAdmissionDate` = '2021-03-28' WHERE (`CID` = '7');
UPDATE `dblab`.`Course` SET `courseAdmissionDate` = '2021-08-01' WHERE (`CID` = '8');
UPDATE `dblab`.`Course` SET `courseAdmissionDate` = '2020-12-02' WHERE (`CID` = '9');


