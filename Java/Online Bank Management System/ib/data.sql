delete from trans;
delete from users;
delete from accounts;

insert into accounts
 values(1,'Scott Mcnealy',100000,'c','11-sep-2001');

insert into accounts
 values(2,'Bill Gates',150000,'s','11-sep-2002');

insert into users 
values('scott','sun','scott@sun.com',
    1);

insert into users 
values('bill','ms','bill@microsoft.com',
    2);



insert into trans values(1,1,'d','12-nov-2003',20000,'Cash',null);
insert into trans values(2,1,'d','15-nov-2003',10000,'Cash',null);
insert into trans values(3,2,'w','16-nov-2003',10000,'To Intel',345668);
insert into trans values(4,2,'d','16-nov-2003',50000,'cheque',788822);
insert into trans values(5,2,'w','18-nov-2003',5000,'Cash',null);
insert into trans values(6,2,'d','26-nov-2003',15000,'Cash',null);
insert into trans values(7,1,'w','27-nov-2003',150000,'To Oracle',345669);







