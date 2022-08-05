 create database IIITDM;

 create table Student(student_id varchar(10), first_name varchar(10), last_name varchar(10), parent_name varchar(10), Age int(30), PRIMARY KEY(student_id));
 create table Faculty(Faculty_id int(100), Name varchar(10), Age int(100), department varchar(15), Date_of_joining date, PRIMARY KEY(Faculty_id));

 create table Building(Building_name varchar(10), Building_id int(50), Capacity_of_student int(255), no_of_floors int(20), Date_of_inauguration date, PRIMARY KEY(Building_id));

INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CS20B1002', 'Mani', 'Srinivas', 'Pawan', '18');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CS20B1007', 'Jashwanth', 'Peddiset', 'Prabhas', '18');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CS20B1016', 'Nagasai', 'Vegur', 'Srinivas', '18');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CS20B1024', 'Praveen', 'Mukti', 'Ravi', '19');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CS20B1025', 'Vineeth', 'Chabala', 'Rana', '19');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('EC20B1001', 'Hemanth', 'Routh', 'RamCharan', '20');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('EC20B1002', 'Vikas', 'Rathode', 'NTR', '19');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('EC20B1016', 'Dhanush', 'Golla', 'Kalyanram', '19');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('ME20B1001', 'Praneeth', 'Nayakanti', 'SaiPallavi', '20');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('ME20B1016', 'Harshith', 'Krishna', 'Dhanush', '19');



INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('1', 'Sadagopan', '50', 'CSE', '2020-12-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('2', 'Masilamani', '52', 'CSE', '2020-12-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('3', 'RamPadhy', '30', 'CSE', '2020-12-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('4', 'Jagadesh', '28', 'CSE', '2020-12-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('5', 'Shalu', '28', 'ECE', '2020-12-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('6', 'Naveen', '50', 'ME', '2020-12-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('7', 'Nachiket', '40', 'ME', '2020-12-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('8', 'Karthik', '27', 'CSE', '2020-12-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('9', 'Sudhir', '60', 'ME', '2020-12-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('10', 'Bingi', '55', 'ECE', '2020-12-01');


INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Ashwatha', '1', '1000', '15', '2020-12-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Ashoka', '2', '1000', '15', '2020-12-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Jasmine', '3', '1000', '14', '2020-12-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Library', '4', '200', '4', '2020-12-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Admin', '5', '100', '4', '2020-12-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Academics', '6', '1000', '7', '2020-12-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Block-1', '7', '100', '1', '2020-12-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Block-2', '8', '100', '1', '2020-12-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Block-3', '9', '300', '2', '2020-12-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Arjuna', '10', '150', '3', '2020-12-01');


select * from Student;
select * from Faculty;
select * from Building;

INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `Date_of_joining`) VALUES ('11', 'Fac-1', '30', '2021-05-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `Date_of_joining`) VALUES ('12', 'Fac-2', '31', '2021-05-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `Date_of_joining`) VALUES ('13', 'Fac-3', '32', '2021-05-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `Date_of_joining`) VALUES ('14', 'Fac-4', '33', '2021-05-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `Date_of_joining`) VALUES ('15', 'Fac-5', '34', '2021-05-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `Date_of_joining`) VALUES ('16', 'Fac-6', '40', '2021-05-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `Date_of_joining`) VALUES ('17', 'Fac-7', '41', '2021-05-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `Date_of_joining`) VALUES ('18', 'Fac-8', '42', '2021-05-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `Date_of_joining`) VALUES ('19', 'Fac-9', '43', '2021-05-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `Date_of_joining`) VALUES ('20', 'Fac-10', '53', '2021-05-01');


INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CED21B101', 'Naveen', 'Gundluri', 'Daggubati', '21');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CED21B102', 'Sathwik', 'Esmapally', 'Chiranjivi', '20');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CED21B103', 'Chandan', 'Pawar', 'Nagarjun', '20');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('MEB21B101', 'Nanda', 'Sai', 'ANR', '22');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('MEB21B102', 'Murali', 'Krishna', 'Mohanbabu', '21');


INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Block-4', '11', '120', '1', '2021-05-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Block-5', '12', '250', '2', '2021-05-01');
INSERT INTO `IIITDM`.`Building` (`Building_name`, `Building_id`, `Capacity_of_student`, `no_of_floors`, `Date_of_inauguration`) VALUES ('Audit', '13', '400', '2', '2021-05-01');



select * from Student;
select * from Faculty;
select * from Building;


UPDATE `IIITDM`.`Faculty` SET `department` = 'CSE' WHERE (`Faculty_id` = '11');
UPDATE `IIITDM`.`Faculty` SET `department` = 'CSE' WHERE (`Faculty_id` = '12');
UPDATE `IIITDM`.`Faculty` SET `department` = 'CSE' WHERE (`Faculty_id` = '13');
UPDATE `IIITDM`.`Faculty` SET `department` = 'CSE' WHERE (`Faculty_id` = '14');
UPDATE `IIITDM`.`Faculty` SET `department` = 'CSE' WHERE (`Faculty_id` = '15');
UPDATE `IIITDM`.`Faculty` SET `department` = 'CSE' WHERE (`Faculty_id` = '16');
UPDATE `IIITDM`.`Faculty` SET `department` = 'ECE' WHERE (`Faculty_id` = '17');
UPDATE `IIITDM`.`Faculty` SET `department` = 'ECE' WHERE (`Faculty_id` = '18');
UPDATE `IIITDM`.`Faculty` SET `department` = 'ECE' WHERE (`Faculty_id` = '19');
UPDATE `IIITDM`.`Faculty` SET `department` = 'ECE' WHERE (`Faculty_id` = '20');


select * from Faculty;

UPDATE `IIITDM`.`Faculty` SET `department` = 'ME' WHERE (`Faculty_id` = '20');
UPDATE `IIITDM`.`Faculty` SET `department` = 'ME' WHERE (`Faculty_id` = '19');
UPDATE `IIITDM`.`Faculty` SET `department` = 'ME' WHERE (`Faculty_id` = '18');
UPDATE `IIITDM`.`Faculty` SET `department` = 'ME' WHERE (`Faculty_id` = '17');



select * from Student;
select * from Faculty;
select * from Building;


INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('21', 'New-1', '28', 'ECE', '2021-08-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('22', 'New-2', '29', 'ECE', '2021-08-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('23', 'New-3', '35', 'ECE', '2021-08-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('24', 'New-4', '38', 'ECE', '2021-08-01');
INSERT INTO `IIITDM`.`Faculty` (`Faculty_id`, `Name`, `Age`, `department`, `Date_of_joining`) VALUES ('25', 'New-5', '41', 'ECE', '2021-08-01');


DELETE FROM `IIITDM`.`Student` WHERE (`student_id` = 'MEB21B102');
DELETE FROM `IIITDM`.`Student` WHERE (`student_id` = 'MEB21B101');
DELETE FROM `IIITDM`.`Student` WHERE (`student_id` = 'EC20B1002');


DELETE FROM `IIITDM`.`Building` WHERE (`Building_id` = '12');



select * from Student;
select * from Faculty;
select * from Building;


INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CS22B1001', 'Stuf-1', 'Stul-1', 'Par-1', '20');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CS22B1002', 'Stuf-2', 'Stul-2', 'Par-2', '20');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CS22B1003', 'Stuf-3', 'Stul-3', 'Par-3', '20');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CS22B1004', 'Stuf-4', 'Stul-4', 'Par-4', '18');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('CS22B1005', 'Stuf-5', 'Stul-5', 'Par-5', '18');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('EC22B1001', 'Stuf-6', 'Stul-6', 'Par-6', '19');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('EC22B1002', 'Stuf-7', 'Stul-7', 'Par-7', '20');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('EC22B1003', 'Stuf-8', 'Stul-8', 'Par-8', '20');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('ME22B1001', 'Stuf-9', 'Stul-9', 'Par-9', '19');
INSERT INTO `IIITDM`.`Student` (`student_id`, `first_name`, `last_name`, `parent_name`, `Age`) VALUES ('ME22B1002', 'Stuf-10', 'Stul-10', 'Par-10', '19');



select * from Student;
select * from Faculty;
select * from Building;


alter table Building drop column Date_of_inauguration;
alter table Building add staff_id int(100);

UPDATE `IIITDM`.`Building` SET `staff_id` = '1' WHERE (`Building_id` = '1');
UPDATE `IIITDM`.`Building` SET `staff_id` = '2' WHERE (`Building_id` = '2');
UPDATE `IIITDM`.`Building` SET `staff_id` = '3' WHERE (`Building_id` = '3');
UPDATE `IIITDM`.`Building` SET `staff_id` = '4' WHERE (`Building_id` = '4');
UPDATE `IIITDM`.`Building` SET `staff_id` = '5' WHERE (`Building_id` = '5');
UPDATE `IIITDM`.`Building` SET `staff_id` = '6' WHERE (`Building_id` = '6');
UPDATE `IIITDM`.`Building` SET `staff_id` = '7' WHERE (`Building_id` = '7');
UPDATE `IIITDM`.`Building` SET `staff_id` = '8' WHERE (`Building_id` = '8');
UPDATE `IIITDM`.`Building` SET `staff_id` = '9' WHERE (`Building_id` = '9');
UPDATE `IIITDM`.`Building` SET `staff_id` = '10' WHERE (`Building_id` = '10');
UPDATE `IIITDM`.`Building` SET `staff_id` = '11' WHERE (`Building_id` = '11');
UPDATE `IIITDM`.`Building` SET `staff_id` = '12' WHERE (`Building_id` = '13');



select * from Student;
select * from Faculty;
select * from Building;