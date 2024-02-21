create table if not exists user (login, pass_hash);
create table if not exists transporters (id ,name, type);

insert into transporters(id,name, type) values (1,'RPG', 1);
insert into transporters(id,name, type) values (2,'Название', 2 );
insert into transporters(id,name, type) values (3,'Жанр',  2);
insert into transporters(id,name, type) values (4,'Действие', 2);
--login guest password hello
insert into user(login, pass_hash) values ('guest','$2a$10$6mf3CesQx9eRGB4B3sjr8e1eSr5cYO/zt87bwYVdA4O8rmjDMDdHO');
insert into user(login, pass_hash) values ('ewokasi','$2a$10$6mf3CesQx9eRGB4B3sjr8e1eSr5cYO/zt87bwYVdA4O8rmjDMDdHO');

