create database dblab4;


-- 1)

create table StudentAccount(id int(32), Person_Name varchar(20), Department varchar(10), birth Date, PRIMARY KEY (id));
INSERT INTO `dblab4`.`StudentAccount` (`id`, `Person_Name`, `Department`, `birth`) VALUES ('1', 'Ramesh', 'CS', '2001-01-12');
INSERT INTO `dblab4`.`StudentAccount` (`id`, `Person_Name`, `Department`, `birth`) VALUES ('2', 'suresh', 'IT', '2020-02-20');
INSERT INTO `dblab4`.`StudentAccount` (`id`, `Person_Name`, `Department`, `birth`) VALUES ('3', 'Jomin', 'CS', '1996-02-29');
INSERT INTO `dblab4`.`StudentAccount` (`id`, `Person_Name`, `Department`, `birth`) VALUES ('4', 'Shree', 'IT', '2012-12-18');
INSERT INTO `dblab4`.`StudentAccount` (`id`, `Person_Name`, `Department`, `birth`) VALUES ('5', 'Hemanth', 'CS', '2022-02-07');



-- 1 a)
-- Write a mysql to determine the age in years and month of each of the
-- person_Name working in department CS.
select id,Person_name, department, concat
        (  floor((timestampdiff(month, birth, curdate()) / 12)), ' Years ',
            mod(timestampdiff(month,birth, curdate()), 12) , ' months ') as age from studentaccount;
-- 1 b)
-- Write a mysql to retrieve name having alphabet 'S'.
select person_name from studentaccount where person_name like '%s%';
-- 1 c)
--  Write a mysql to get name of students containing exactly five characters.
select person_name from studentaccount where person_name like '_____';
-- 1 d)
-- Display the alternate rows from table.
select * from studentaccount group by id having mod(id, 2)=1;


-- 2)

create table Employees (Employee_id int(32), First_Name varchar(20), Last_Name varchar(20), salary int(255), Joining_date Date, Department varchar(20), Primary Key (Employee_id));
INSERT INTO `dblab4`.`Employees` (`Employee_id`, `First_Name`, `Last_Name`, `salary`, `Joining_date`, `Department`) VALUES ('1', 'Boby', 'Rathod', '1000000', '2020-12-20', 'Finance');
INSERT INTO `dblab4`.`Employees` (`Employee_id`, `First_Name`, `Last_Name`, `salary`, `Joining_date`, `Department`) VALUES ('2', 'Jasmin', 'Jose', '6000000', '2015-02-07', 'IT');
INSERT INTO `dblab4`.`Employees` (`Employee_id`, `First_Name`, `Last_Name`, `salary`, `Joining_date`, `Department`) VALUES ('3', 'Pratap', 'Mathew', '8900000', '2014-03-09', 'Banking');
INSERT INTO `dblab4`.`Employees` (`Employee_id`, `First_Name`, `Last_Name`, `salary`, `Joining_date`, `Department`) VALUES ('4', 'Jhon', 'Michel', '2000000', '1999-03-17', 'Insurance');
INSERT INTO `dblab4`.`Employees` (`Employee_id`, `First_Name`, `Last_Name`, `salary`, `Joining_date`, `Department`) VALUES ('5', 'Alex', 'Kinto', '2200000', '1987-02-25', 'Finance');
INSERT INTO `dblab4`.`Employees` (`Employee_id`, `First_Name`, `Last_Name`, `salary`, `Joining_date`) VALUES ('6', 'Jaswanth', 'Kumar', '1230000', '2021-07-23', 'IT');

-- 2 a)
-- a. Get all the details about employees with a salary between 2,000,000 and 5,000,000.
select * from employees where salary between 2000000 and 5000000;

-- 2 b)
-- Get the Last_name about employees with work experience more than
-- three years whose first_name contain the alphabet ‘a’.
select last_name, year(CURDATE()) - year(JOINING_DATE) as Work_Experience from employees where (floor(Datediff(current_date, Joining_date)/365.25))>3 and first_name like '%a%';
-- 2 c)
-- Display the joining_date of employees working in IT department having
-- salary more than average salary of company.
select joining_date from employees where department='It' and salary>(select avg(salary) from employees);
-- 2 d)
-- Find the details of employees working in Finance department having
-- salary less than average salary of IT department.
select * from employees where department='Finance' and salary<(select avg(salary) from employees where department='IT');