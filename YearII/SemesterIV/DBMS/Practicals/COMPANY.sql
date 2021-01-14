DROP SCHEMA IF EXISTS COMPANY;

CREATE SCHEMA COMPANY;

USE COMPANY;

CREATE TABLE EMPLOYEE
(
    Eno        CHAR(3)     NOT NULL,
    Ename      VARCHAR(50) NOT NULL,
    Job_type   VARCHAR(50) NOT NULL,
    Manager    CHAR(3),
    Hire_date  DATE        NOT NULL,
    Dno        INT,
    Commission DEC(10, 2),
    Salary     DEC(7, 2)   NOT NULL,
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
        FOREIGN KEY (Manager) REFERENCES EMPLOYEE (Eno);
ALTER TABLE EMPLOYEE
    ADD CONSTRAINT
        FOREIGN KEY (Dno) REFERENCES DEPARTMENT (Dno);
ALTER TABLE DEPARTMENT
    MODIFY Dname VARCHAR(50) NOT NULL;
ALTER TABLE DEPARTMENT
    MODIFY Location VARCHAR(50) NOT NULL DEFAULT 'New Delhi';


INSERT INTO DEPARTMENT
VALUES (10, 'Headquarters', 'Mumbai'),
       (30, 'IT', 'Bengaluru'),
       (20, 'Outreach', 'Dallas');
INSERT INTO DEPARTMENT (Dno, Dname)
VALUES (90, 'Sales'),
       (40, 'Administration'),
       (50, 'Research');

INSERT INTO EMPLOYEE
VALUES ('E01', 'John Smith', 'Managing Director', NULL, DATE('1980-06-12'), 10, 0, 12800.23),
       ('E02', 'Sudipto Ghosh', 'SDE Manager', 'E01', DATE('1981-11-21'), 30, 0, 2465.92),
       ('E03', 'Anmol Gupta', 'Accounts Manager', 'E01', DATE('1981-09-11'), 40, 0, 2865.92),
       ('E04', 'Nataline Peracco', 'SDE Manager', 'E01', DATE('2004-08-14'), 30, 0, 2921.37),
       ('E05', 'Tanya Chawla', 'Sales Manager', 'E01', DATE('1983-08-14'), 90, 235.90, 2921.37),
       ('E06', 'Blake Lewis', 'Sales Intern', 'E05', DATE('2008-05-02'), 90, 125.45, 921.37);