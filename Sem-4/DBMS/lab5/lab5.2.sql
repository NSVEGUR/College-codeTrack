show databases;
use dblab5;
show tables;

create table Salesman(
salesman_id varchar(10) not null unique,
name varchar(10) not null,
city varchar(10) not null,
comission varchar(5) not null,
Primary key(salesman_id)
);

insert into Salesman(salesman_id,name,city,comission)
Values('si123@06','Lakshmi','Kolkata','.5'),
('si123@09','Ganesh','London','.6'),
('si123@90','Dinesh','London','.3'),
('si123@10','Joseph','Chennai','.6'),
('si123@19','Mahesh','Hyderabad','.65'),
('si123@26','Paul Adam','London','.1'),
('si123@67','Rahul','Delhi','.4');

select* from Salesman;

create table Orders(
ord_no int not null,
purch_amt int not null,
ord_date varchar(15) not null,
customer_id varchar(8) not null,
salesman_id varchar(10) not null,
foreign key(salesman_id) references Salesman(salesman_id)
);

insert into Orders(ord_no, purch_amt, ord_date, customer_id, salesman_id )
values(123,600,'20-aug-2010','003cd','si123@19'),
(576,750,'20-feb-2018','004cd','si123@19'),
(579,800,'20-may-2012','004cd','si123@26'),
(600,60000,'20-jan-2021','006cd','si123@10'),
(700,745,'26-jan-2021','007cd','si123@09'),
(800,860,'29-jan-2019','007cd','si123@26');

select* from orders;

-- ## a. Display all the orders from the orders table issued by the salesman 'Paul Adam'.

select* from orders where salesman_id = (select salesman_id from salesman where name = 'Paul Adam');

-- ## b. Display all the orders for the salesman who belongs to the city London

select* from orders where salesman_id in (select salesman_id from salesman where city = 'London');


