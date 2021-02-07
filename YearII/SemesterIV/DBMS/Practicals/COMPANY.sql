DROP SCHEMA IF EXISTS COMPANY;

CREATE SCHEMA COMPANY;

USE COMPANY;

CREATE TABLE EMPLOYEE
(
    Eno           CHAR(3)     NOT NULL,
    Ename         VARCHAR(50) NOT NULL,
    Job_type      VARCHAR(50) NOT NULL,
    SupervisorENo CHAR(3),
    Hire_date     DATE        NOT NULL,
    Dno           INT,
    Commission    DEC(10, 2),
    Salary        DEC(7, 2)   NOT NULL,
    PRIMARY KEY (Eno)
);

CREATE TABLE DEPARTMENT
(
    Dno      INT NOT NULL,
    Dname    VARCHAR(50),
    Location VARCHAR(50) DEFAULT 'New Delhi',
    PRIMARY KEY (Dno)
);

ALTER TABLE EMPLOYEE
    ADD CONSTRAINT SupervisorConstraint
        FOREIGN KEY (SupervisorENo) REFERENCES EMPLOYEE (Eno);

ALTER TABLE EMPLOYEE
    ADD CONSTRAINT DepartmentConstraint
        FOREIGN KEY (Dno) REFERENCES DEPARTMENT (Dno);

INSERT INTO DEPARTMENT
VALUES (10, 'Headquarters', 'Mumbai'),
       (45, 'Legal', 'Mumbai'),
       (30, 'IT', 'Bengaluru'),
       (20, 'Outreach', 'Dallas'),
       (95, 'Purchase', 'Dallas');

INSERT INTO DEPARTMENT (Dno, Dname)
VALUES (90, 'Sales'),
       (40, 'Administration'),
       (50, 'Research');

INSERT INTO EMPLOYEE
VALUES ('778', 'John Smith', 'Managing Director', NULL, '1980-06-12', 10, NULL, 5800.23),
       ('153', 'Andy Beaford', 'VP Accounting', '778', '2000-09-08', 40, NULL, 502.30),
       ('23', 'Sudipto Ghosh', 'SDE Manager', '778', '1981-11-21', 30, NULL, 2465.92),
       ('25', 'Anmol Gupta', 'Accounts Manager', '778', '1981-09-11', 40, NULL, 2865.92),
       ('86', 'Tania Chauhan', 'Sales Manager', '778', '1983-08-14', 90, 235.90, 2921.37),
       ('89', 'Alicia Jones', 'Purchase Manager', '778', '1982-10-26', 95, NULL, 980.35),
       ('232', 'Isa Jaques', 'Legal Manager', '778', '1996-07-23', 45, NULL, 651.05),
       ('520', 'King Hethron', 'Sales Manager', '778', '2015-10-13', 90, NULL, 497.18),
       ('188', 'Sherline Harbord', 'Audit Manager', '778', '1995-08-05', 40, NULL, 926.42),
       ('146', 'Donielle Tuite', 'Sales Representative', '520', '2016-06-12', 90, NULL, 171.60),
       ('125', 'Gurpreet Singh', 'Intern', NULL, '2008-05-15', NULL, NULL, 521.37),
       ('243', 'Marie Brahms', 'Systems Engineer', '23', '1983-06-22', 40, NULL, 876.78),
       ('299', 'Mahala Burtwhistle', 'Compensation Analyst', '89', '1990-07-20', 95, NULL, 602.86),
       ('354', 'Bryna McKenny', 'Financial Advisor', '153', '2001-10-11', 90, NULL, 693.63),
       ('421', 'Ulberto Gosz', 'Office Assistant', NULL, '2017-02-07', 10, NULL, 381.64),
       ('442', 'Netti Dellenbrok', 'Graphic Designer', '23', '2014-05-14', 30, NULL, 790.82),
       ('492', 'Salmon Gough', 'Marketing Assistant', '86', '2008-12-13', 90, 148.80, 998.32),
       ('504', 'Berny Bonas', 'Executive Secretary', '778', '2008-05-24', 40, NULL, 779.34),
       ('516', 'Lowell Paule', 'Systems Administrator', '23', '2008-03-31', 30, 324.39, 969.66),
       ('518', 'Nicholas Comelini', 'Tax Accountant', '188', '1997-03-20', 90, 546.04, 882.53);

INSERT INTO EMPLOYEE
VALUES ('528', 'Laurence Grosvener', 'Sales Intern', '520', '2019-09-06', 90, 125.45, 244.37),
       ('611', 'Brandtr Wildbore', 'Software Test Engineer', '23', '2000-04-14', 30, NULL, 704.23),
       ('697', 'Druci Sixsmith', 'Help Desk Technician', NULL, '2005-07-27', 10, 530.53, 387.43),
       ('718', 'Oneida Hicklingbottom', 'Payment Coordinator', '89', '2006-03-25', 95, NULL, 789.82),
       ('732', 'Gannie Quantrell', 'Automation Engineer', '23', '2019-04-29', 30, NULL, 174.12),
       ('783', 'Fran Lening', 'Analyst Programmer', '23', '1981-05-27', 30, NULL, 471.17),
       ('79', 'Rahul Sahay', 'SDE Intern', '23', '2004-08-14', 30, NULL, 2921.37),
       ('811', 'Shay Restieaux', 'Lawyer', '232', '1999-04-16', 45, 574.68, 500.22),
       ('823', 'Marcille Occleshaw', 'Lawyer', '232', '2003-12-27', 45, 453.52, 507.10),
       ('832', 'Desiri Allott', 'Payment Coordinator', '89', '1997-11-04', 95, 239.84, 683.09),
       ('87', 'Blake Lewis', 'Sales Intern', '86', '2008-05-02', 90, 125.45, 244.37),
       ('908', 'Gustav Waring', 'Software Engineer', '23', '2002-12-23', 30, NULL, 141.05),
       ('960', 'Virge Swancott', 'Web Developer', '23', '1984-01-23', 30, NULL, 292.48),
       ('969', 'Lee Prattin', 'Backend Developer', '23', '1986-01-23', 30, NULL, 296.48),
       ('997', 'Mag Giacomo', 'GIS Technical Architect', '23', '2002-12-23', 30, NULL, 427.98),
       ('785', 'Chandal McBrier', 'Software Consultant', '23', '1998-02-10', 30, NULL, 697.68),
       ('659', 'Martha Annies', 'Web Developer', '23', '2008-11-03', 30, NULL, 200.80),
       ('932', 'Selestina Herries', 'Software Engineer', '23', '2013-05-23', 30, NULL, 239.27),
       ('837', 'Ashil Burney', 'Automation Engineer', '23', '1987-03-29', 30, NULL, 586.13);

INSERT INTO EMPLOYEE
VALUES ('763', 'Rodrick Haighton', 'Computer Systems Analyst', '23', '2000-05-08', 30, NULL, 627.74),
       ('981', 'Nina Fisby', 'Systems Administrator', '23', '2017-07-26', 30, 324.39, 920.84),
       ('498', 'Skell Woolerton', 'Software Test Engineer', '23', '2004-04-04', 30, NULL, 506.44),
       ('809', 'Cornie Munby', 'Software Consultant', '23', '1986-06-07', 30, NULL, 688.37),
       ('915', 'Layton Murrie', 'Graphic Designer', '23', '2006-06-24', 30, NULL, 640.31),
       ('842', 'Rivy Buzek', 'Help Desk Technician', NULL, '1982-05-25', 30, NULL, 295.31);
