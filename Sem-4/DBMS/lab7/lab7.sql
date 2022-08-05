drop database dblab7;
create database dblab7;
-- show databases; 
use dblab7;

CREATE TABLE `dblab7`.`Bank` (
  `Bank_name` VARCHAR(12) NOT NULL,
  `State` VARCHAR(45) NOT NULL);

	insert into Bank(Bank_name, State) values ('SBI', 'AndhraPradesh');
	insert into Bank(Bank_name, State) values ('SBI', 'TamilNadu');
	insert into Bank(Bank_name, State) values ('SBI', 'Karnataka');
	insert into Bank(Bank_name, State) values ('ICICI', 'TamilNadu');
	insert into Bank(Bank_name, State) values ('ICICI', 'Karnataka');

	create table Account_holder (Account_name VARCHAR(20), Bank_Name VARCHAR(12), State_Name VARCHAR(20));

	insert into Account_holder(Account_name, Bank_Name, State_Name) values ('Ramesh', 'ICICI', 'TamilNadu');
	insert into Account_holder(Account_name, Bank_Name, State_Name) values ('Dinesh', 'SBI', 'AndhraPradesh');

insert into Account_holder(Account_name, Bank_Name, State_Name) values ('Robert', 'SBI', 'TamilNadu');
insert into Account_holder(Account_name, Bank_Name, State_Name) values ('Robert', 'ICICI', 'Karnataka');
insert into Account_holder(Account_name, Bank_Name, State_Name) values ('Robert', 'SBI', 'AndhraPradesh');
 insert into Account_holder(Account_name, Bank_Name, State_Name) values ('Karthik', 'SBI', 'AndhraPradesh');



--  /-------------------question 1---------------/
-- /step 1/
create table all_holders as 
select distinct account_name from account_holder;

create table all_banks as 
select distinct bank_name from bank ;

-- /step 2/
create table bank_and_holder as 
select all_holders.account_name , all_banks.bank_name from all_holders,all_banks;

-- /step 3/
create table bank_and_not_holder as 
select * from bank_and_holder where not exists
 (select * from account_holder where 
 bank_and_holder.account_name=account_holder.account_name 
 and bank_and_holder.bank_name=account_holder.bank_name
);
-- /*step 4 */
create table not_holder as 
select distinct account_name from bank_and_not_holder ;

-- /step 5/
create table holder as 
select * from all_holders where not exists (select * from not_holder where not_holder.account_name = all_holders.account_name);





/--------------------------------question 2--------------------------------/
-- /step 1/
create table all_states as 
select distinct state from bank;

-- /step 2/
create table bank_and_state as 
select all_states.state , all_banks.bank_name from all_states,all_banks;

-- /step 3/
create table bank_and_not_state as 
select * from bank_and_state where not exists
 (
select * from bank where
 bank_and_State.bank_name = bank.bank_name and 
 bank.state=bank_and_State.state
 );
 

 
--  /step 4/
 create table not_in_all_state as
 select distinct bank_name from bank_and_not_state ;
 
 
--  /step 5/
 create table in_all_State as
 select * from all_banks where not exists 
 (select * from not_in_All_state where not_in_All_state.bank_name = all_banks.bank_name);
 
 select * from in_all_State;
 
 /---------------------------question3--------------------/
 
 select * from not_in_all_State;
 
--  /---------------------------question4--------------------/
/*step 2*/
 create table holder_And_State as
 select all_holders.account_name , all_States.state from 
 all_holders,all_States;
 
 /*step 3*/
 create table holder_and_not_state as 
select * from holder_and_state where not exists
 (
select * from account_holder where
 account_holder.account_name = holder_and_state.account_name and  
 account_holder.state_name=holder_and_State.state
 );
 
 
 /*step 4*/
 create table holder_not_in_All_States as
 select distinct account_name from holder_and_not_State ;
 
 /*step 5*/
 create table holder_in_all_States as
 select * from all_holders where not exists 
 (select * from holder_not_in_all_States where all_holders.account_name = holder_not_in_all_States.account_name);