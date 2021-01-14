use ducs;

drop table if exists departments, locations, students, projects, works_in;

create table departments
(
    id   int          not null auto_increment,
    name varchar(255) not null,
    primary key (id)
);

create table locations
(
    id       int          not null auto_increment,
    location varchar(255) not null,
    primary key (id)
);

create table students
(
    id   int          not null auto_increment,
    name varchar(255) not null,
    dept int,
    primary key (id),
    foreign key (dept) references departments (id)
);

create table projects
(
    id   int          not null auto_increment,
    name varchar(255) not null,
    dep  int,
    primary key (id),
    foreign key (dep) references departments (id)
);

create table works_in
(
    stud int,
    dept int,
    loc  int,
    proj int,
    hrs  float,
    primary key (stud, dept, loc, proj),
    foreign key (stud) references students (id),
    foreign key (dept) references departments (id),
    foreign key (loc) references locations (id),
    foreign key (proj) references projects (id)
);

desc departments;

desc locations;

desc students;

desc projects;

desc works_in;

insert into departments (name)
values ('Comp Sc');
insert into departments (name)
values ('Mathematics');

insert into locations (location)
values ('Campus Area 1');
insert into locations (location)
values ('Campus Area 2');

insert into students (name, dept)
values ('Sudipto', 1);
insert into students (name, dept)
values ('Anmol', 2);

insert into projects (name, dep)
values ('Project A', 1);
insert into projects (name, dep)
values ('Project B', 1);
insert into projects (name, dep)
values ('Project C', 2);
insert into projects (name, dep)
values ('Project D', 1);
insert into projects (name, dep)
values ('Project E', 2);

insert into works_in
values (2, 2, 2, 3, 0.5);
insert into works_in
values (2, 2, 1, 5, 1.5);
insert into works_in
values (1, 1, 2, 1, 1.3);
insert into works_in
values (1, 1, 2, 2, 1.1);
insert into works_in
values (1, 1, 2, 4, 0.7);

select *
from departments;

select *
from locations;

select *
from students;

select *
from projects;

select *
from works_in;

select students.name, departments.name as dept
from students,
     departments
where students.dept = departments.id;

select projects.name, departments.name as dept
from projects,
     departments
where projects.dep = departments.id
order by projects.name;

select students.name,
       departments.name as dept,
       locations.location,
       projects.name as proj,
       works_in.hrs
from works_in,
     projects,
     students,
     departments,
     locations
where works_in.stud = students.id
  and works_in.proj = projects.id
  and works_in.dept = departments.id
  and works_in.loc = locations.id
order by projects.name;

select students.name, sum(works_in.hrs) as total
from works_in,
     students,
     departments,
     locations
where works_in.stud = students.id
  and departments.id = works_in.dept
  and works_in.loc = locations.id
group by (students.name);
