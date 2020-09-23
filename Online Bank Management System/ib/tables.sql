drop table trans;
drop table users;
drop table accounts;
create table accounts
( acno  varchar2(12) primary key,
   customer  varchar2(20) not null,
   curbal     number(10,2),
   atype      char(1),
   doa         date
);
create table users
( uname   varchar2(10) primary key,
   pwd       varchar2(10) not null,
    email    varchar2(30)  unique,
   acno     varchar2(12)                       references accounts(acno)
);

create table trans
(   tno   number(10)  primary key,
     acno   varchar2(12)  references accounts(acno),
     ttype   char(1),
    tdate   date,
    tamt    number(10,2),
    tdesc   varchar2(50),
    cno      number(10)
);
 

create sequence sqtrans  start with 1000;
