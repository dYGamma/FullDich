create table if not exists user (login, pass_hash);
create table if not exists transporters (id ,name, type);
create table if not exists Times (id integer ,name varchar(50), type integer);

insert into transporters(id,name, type) values (1,'Самарин Дмитрий', 1);
insert into transporters(id,name, type) values (2,'Кухня', 2 );
insert into transporters(id,name, type) values (3,'Гостинная',  2);
insert into transporters(id,name, type) values (4,'АВАБ', 3);
insert into transporters(id,name, type) values (5,'БАВАБ', 3);
insert into transporters(id,name, type) values (6,'ГАВАБ', 3);


insert into Times(id,name, type) values (1,'Самарин Дмитрий', 1);
insert into Times(id,name, type) values (2,'АВА АБА', 2);
insert into Times(id,name, type) values (3,'ГРА АРГ', 2);

--login guest password hello
insert into user(login, pass_hash) values ('guest','$2a$10$6mf3CesQx9eRGB4B3sjr8e1eSr5cYO/zt87bwYVdA4O8rmjDMDdHO');
insert into user(login, pass_hash) values ('ewokasi','$2a$10$6mf3CesQx9eRGB4B3sjr8e1eSr5cYO/zt87bwYVdA4O8rmjDMDdHO');

