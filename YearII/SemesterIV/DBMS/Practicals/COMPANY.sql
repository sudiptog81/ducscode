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
    ADD CONSTRAINT
        FOREIGN KEY (SupervisorENo) REFERENCES EMPLOYEE (Eno);
ALTER TABLE EMPLOYEE
    ADD CONSTRAINT
        FOREIGN KEY (Dno) REFERENCES DEPARTMENT (Dno);

INSERT INTO DEPARTMENT
VALUES (10, 'Headquarters', 'Mumbai'),
       (30, 'IT', 'Bengaluru'),
       (20, 'Outreach', 'Dallas');

INSERT INTO DEPARTMENT (Dno, Dname)
VALUES (90, 'Sales'),
       (40, 'Administration'),
       (50, 'Research');

INSERT INTO EMPLOYEE
VALUES ('778', 'John Smith', 'Managing Director', NULL, DATE('1980-06-12'), 10, NULL, 12800.23),
       ('23', 'Sudipto Ghosh', 'SDE Manager', '778', DATE('1981-11-21'), 30, NULL, 2465.92),
       ('25', 'Anmol Gupta', 'Accounts Manager', '778', DATE('1981-09-11'), 40, NULL, 2865.92),
       ('79', 'Rahul Sahay', 'SDE Intern', '23', DATE('2004-08-14'), 30, NULL, 2921.37),
       ('86', 'Tania Chauhan', 'Sales Manager', '778', DATE('1983-08-14'), 90, 235.90, 2921.37),
       ('87', 'Blake Lewis', 'Sales Intern', '86', DATE('2008-05-02'), 90, 125.45, 921.37),
       ('125', 'Gurpreet Singh', 'Intern', NULL, DATE('2008-05-15'), 20, NULL, 521.37);