CREATE TABLE Title( Title_Code varchar(255) not null Primary Key,
                     Title_Discription varchar(255),
                     Salary Number(11));
                     
insert into Title values('T1','Accountant','10000');
insert into Title values('T2','Analyst','20000');
insert into Title values('T3','Programmer','30000');
insert into Title values('T4','DBA','40000');
insert into Title values('T5','Manager','50000');


CREATE TABLE Department( 
                     dep_Code Number(11) not null Primary Key,
                     dept_Name varchar(255),
                     loaction varchar(255),
                     Dept_Type varchar(255));
                     
insert into Department values('001','Computer Center','Boston','IT');
insert into Department values('002','Budget','New York','Business');
insert into Department values('003','Marketing','Boston','Marketing');
insert into Department values('004','Database Support','Cleveland','IT');
insert into Department values('005','Purchasing','New York','Business');



CREATE TABLE Employee( ID Number(11) not null Primary Key,
                     emp_Name varchar(255),
                     emp_Type varchar(255),
                     dept_Code Number(11) not null,
                     title_Code varchar(255) not null,
                     constraint fk_dep_Code
                     foreign key(dept_Code) references Department(dep_Code),
                     constraint fk_Title_Code
                     foreign key(title_Code) references Title(title_Code));
                     
insert into Employee values('1','John','Full-Time','002','T1');
insert into Employee values('2','Adam','Consultant','001','T3');
insert into Employee values('3','Mary','Part-Time','004','T4');
insert into Employee values('4','Peter','Full-Time','003','T2');
insert into Employee values('5','Scott','Consultant','002','T1');
insert into Employee values('6','Susan','Full-Time','005','T5');
insert into Employee values('7','Alex','Part-Time','004','T2');

/* DISTINCT */
select DISTINCT t.Title_Code, t.Title_Discription from Title t , Employee e where e.title_Code = t.Title_Code;

/* OUTER JOIN */
/* 1 */
select t.Title_Code, t.Title_Discription from Title t OUTER JOIN Employee e ON e.title_Code = t.Title_Code;

/* 2 */
select d.dep_Code, d.dept_Name from Department d JOIN Employee e ON e.dept_Code = d.dep_Code; 

/* 3 */
/* Task 6 of SQL Review is not mentioned */

UPDATE Employee e
SET 
   e.ID = NULL
where emp_Type = null;
select * from Employee;