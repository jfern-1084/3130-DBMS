create table dept(
dno int not null,
dname char(10),
primary key (dno));

insert into dept values(1, 'accounting');
insert into dept values(2, 'sales');
insert into dept values(3, 'management');
insert into dept values(4, 'shipping');
insert into dept values(5, 'testing');

create table emp(
eno int, 
ename char(10), 
dno int,
primary key (eno),
foreign key (dno) references dept(dno));

insert into emp values(101,'Smith',1);
insert into emp values(201,'Kevin',2);
insert into emp values(105,'Sally',1);
insert into emp values(102,'Matt',1);
insert into emp values(402,'Jeff',4);
insert into emp values(205,'Amy',2);
insert into emp values(401,'Tom',4);
insert into emp values(202,'Alex',2);
insert into emp values(103,'Sam',1);
insert into emp values(302,'Joe',3);
insert into emp values(304,'Sean',3);
insert into emp values(206,'Martin',2);
insert into emp values(203,'Simon',2);
insert into emp values(104,'Jane',1);
insert into emp values(501,'Max',5);
insert into emp values(303,'Mike',3);
insert into emp values(106,'Sarah',1);
insert into emp values(107,'Jack',1);
insert into emp values(204,'Jen',2);
insert into emp values(301,'John',3);

create table manages(
eno int,
dno int,
primary key (eno, dno),
foreign key (eno) references emp(eno),
foreign key (dno) references dept(dno));

insert into manages values(107, 1);
insert into manages values(203, 2);
insert into manages values(301, 3);
insert into manages values(304, 5);
insert into manages values(304, 4);