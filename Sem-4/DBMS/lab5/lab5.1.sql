show databases;
use dblab5;
show tables;

create table Agent(
Agent_code varchar(5) NOT NULL UNIQUE, 
Agent_name varchar(15), 
Working_area varchar(15), 
comission varchar(3), 
Phone_no VARCHAR(10) UNIQUE, 
Country varchar(15), 
PRIMARY KEY(Agent_code)
);


insert into Agent(Agent_code,Agent_name,Working_area,comission,Phone_no,Country) 
values('Ac001','Ramesh','Bangalore','.15','0331234567','India');
insert into Agent(Agent_code,Agent_name,Working_area,comission,Phone_no,Country) 
values('Ac002','Dinesh','Bangalore','.25','0331234568',null);
insert into Agent(Agent_code,Agent_name,Working_area,comission,Phone_no,Country) 
values('Ac003','Suresh','Mumbai','.35','0331234569','London');
insert into Agent(Agent_code,Agent_name,Working_area,comission,Phone_no,Country) 
values('Ac004','Kamlesh','New Jersey','.68','0331234564',null);
insert into Agent(Agent_code,Agent_name,Working_area,comission,Phone_no,Country) 
values('Ac005','Kartik','Chennai','.73','0331234563','India');

select* from Agent;

create table Orders1(
Ord_num varchar(5) NOT NULL UNIQUE, 
Ord_amount int, 
Advance_amount int, 
Ord_date varchar(15), 
Cust_code varchar(10), 
Agent_code varchar(15), 
Description varchar(25), 
PRIMARY KEY(Ord_num)
);

insert into Orders1(Ord_num,Ord_amount,Advance_amount,Ord_date,Cust_code,Agent_code,Description) 
values('004','200','3000','15-aug-2020','C004','Ac001','Masala kulcha');
insert into Orders1(Ord_num,Ord_amount,Advance_amount,Ord_date,Cust_code,Agent_code,Description) 
values('007','600','5000','17-sept-2020','C006','Ac003','Biryani');
insert into Orders1(Ord_num,Ord_amount,Advance_amount,Ord_date,Cust_code,Agent_code,Description) 
values('008','700','100','19-feb-2019','C007','Ac005',null);
insert into Orders1(Ord_num,Ord_amount,Advance_amount,Ord_date,Cust_code,Agent_code,Description) 
values('009','10000','600','21-march--2020','C009','Ac008','Masala dosa');
insert into Orders1(Ord_num,Ord_amount,Advance_amount,Ord_date,Cust_code,Agent_code,Description) 
values('010','20','600','21-april-2012','C006','Ac005',null);

select* from Orders1;

-- ## a. Find ord_num, ord_amount, ord_date, cust_code and agent_code from the table Orders working_area of Agent table must be Bangalore.

select Ord_num,Ord_amount,Cust_code,Agent_code from Orders1 where Agent_code in (select Agent_code from Agent where Working_area = 'Bangalore');

-- ## b. Retrive ord_num, ord_amount, cust_code and agent_code from the table orders where the agent_code of orders table must be the same agent_code of agents table and agent_name of agents table must be Ramesh.

select Ord_num, Ord_amount, Cust_code, Agent_code from Orders1 where Agent_code = (select Agent_code from agent where Agent_name='Ramesh');