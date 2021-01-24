USE COMPANY;

-- EMPLOYEE
DESC EMPLOYEE;

-- DEPARTMENT
DESC DEPARTMENT;

-- Q1
SELECT Eno,
       Ename,
       Job_type,
       Hire_date
FROM EMPLOYEE;

-- Q2
SELECT DISTINCT Job_type
FROM EMPLOYEE;

-- Q3
SELECT CONCAT(
               Ename, ',',
               Job_type
           ) AS Employee_Job
FROM EMPLOYEE;

-- Q4
SELECT CONCAT(
               Eno, ',',
               Ename, ',',
               Job_type, ',',
               IFNULL(SupervisorENo, ''), ',',
               Hire_date, ',',
               IFNULL(Dno, ''), ',',
               IFNULL(Commission, ''), ',',
               Salary
           ) AS THE_OUTPUT
FROM EMPLOYEE;

-- Q5
SELECT Ename,
       Salary
FROM EMPLOYEE
WHERE Salary > 2850;

-- Q6
SELECT Ename,
       Dno
FROM EMPLOYEE
WHERE Eno = '79';

-- Q7
SELECT Ename,
       Salary
FROM EMPLOYEE
WHERE Salary NOT BETWEEN 1500 AND 2850;

-- Q8
SELECT Ename,
       Dname
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT)
WHERE Dno IN (10, 30)
ORDER BY Ename;

-- Q9
SELECT Ename,
       Hire_date
FROM EMPLOYEE
WHERE Hire_date
          LIKE '1981______';

-- Q11
SELECT Ename,
       Salary,
       Commission
FROM EMPLOYEE
WHERE Commission IS NOT NULL;

-- Q13
SELECT Ename
FROM EMPLOYEE
WHERE Ename LIKE '__A%';

-- Q14
SELECT Ename
FROM EMPLOYEE
WHERE Ename LIKE '%R%R%'
   OR Ename LIKE '%A%A%'
   OR Dno = 30
   OR SupervisorENo = '778';

-- Q22
SELECT Ename,
       Dno,
       Dname
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT);

-- Q23
SELECT DISTINCT Job_type
FROM EMPLOYEE
WHERE Dno = 30;

-- Q24
SELECT Ename,
       Dname
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT)
WHERE Ename LIKE '%A%';

-- Q25
SELECT Ename,
       Job_type,
       Dno,
       Dname
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT)
WHERE Location = 'Dallas';

-- Q26
SELECT E.Ename,
       E.Eno,
       S.Ename,
       S.Eno
FROM EMPLOYEE AS E,
     EMPLOYEE AS S
WHERE E.SupervisorENo = S.Eno;


-- Q29
SELECT MAX(Salary),
       MIN(Salary),
       SUM(Salary),
       AVG(Salary)
FROM EMPLOYEE;

-- Q34
SELECT Ename,
       Salary
FROM EMPLOYEE
WHERE Salary > (
    SELECT AVG(Salary)
    FROM EMPLOYEE
);

-- Q37
SELECT Dno,
       Ename,
       Job_type
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT)
WHERE Dname = 'Sales';

-- Q39
SELECT Location,
       COUNT(*)
FROM DEPARTMENT
GROUP BY Location;

-- Extra
SELECT Dno,
       Dname,
       COUNT(*)
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT)
GROUP BY Dno;
