USE COMPANY;

# Q1
SELECT Eno       AS 'Employee Number',
       Ename     AS 'Employee Name',
       Job_type  AS 'Job',
       Hire_date AS 'Hire Date'
FROM EMPLOYEE;

# Q2
SELECT DISTINCT Job_type AS 'Jobs'
FROM EMPLOYEE;

# Q3
SELECT CONCAT(Ename, ',', Job_type) AS 'Employee,Job'
FROM EMPLOYEE;

# Q4
SELECT CONCAT(
               Eno, ',',
               Ename, ',',
               Job_type, ',',
               Manager, ',',
               Hire_date, ',',
               Dno, ',',
               Commission, ',',
               Salary
           )
           AS THE_OUTPUT
FROM EMPLOYEE;

# Q5
SELECT Ename AS 'Employee Name',
       Salary
FROM EMPLOYEE
WHERE Salary > 2850;

# Q6
SELECT Ename AS 'Employee Name',
       Dno AS 'Department Number'
FROM EMPLOYEE
WHERE Eno = 'E05';