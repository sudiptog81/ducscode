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

-- Q10
SELECT Ename,
       Job_type
FROM EMPLOYEE
WHERE SupervisorENo IS NULL;

-- Q11
SELECT Ename,
       Salary,
       Commission
FROM EMPLOYEE
WHERE Commission IS NOT NULL;

-- Q12
SELECT *
FROM EMPLOYEE
ORDER BY Salary DESC,
         Commission DESC;

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

-- Q15
SELECT Ename,
       Salary,
       Commission
FROM EMPLOYEE
WHERE Commission > 1.05 * Salary;

-- Q16
SELECT DATE(NOW()),
       DAYNAME(NOW());

-- Q17
WITH RECORDS(Ename, Hire_date, Six_after) AS (
    SELECT Ename,
           Hire_date,
           DATE_ADD(Hire_date, INTERVAL 6 MONTH)
               AS Six_after
    FROM EMPLOYEE
)
SELECT RECORDS.Ename,
       RECORDS.Hire_date,
       DATE_ADD(
               RECORDS.Six_after,
               INTERVAL
               IF(
                       0 = WEEKDAY(RECORDS.Six_after),
                       0 - WEEKDAY(RECORDS.Six_after),
                       7 - WEEKDAY(RECORDS.Six_after) + 0
                   )
               DAY
           ) AS Salary_review_date
FROM RECORDS;

-- Q18
SELECT Ename,
       TIMESTAMPDIFF(MONTH, Hire_date, NOW())
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT)
WHERE Dname = 'Purchase';

-- Q19
SELECT CONCAT(
               Ename, ' earns $',
               Salary, ' monthly ',
               'but wants $', 3 * Salary
           )
           AS "Dream Salary"
FROM EMPLOYEE;

-- Q20
SELECT CONCAT(
               UPPER(SUBSTR(Ename, 1, 1)),
               LOWER(SUBSTR(Ename, 2))
           )
           AS "Name",
       LENGTH(Ename)
FROM EMPLOYEE
WHERE Ename LIKE 'J%'
   OR Ename LIKE 'A%'
   OR Ename LIKE 'M%';

-- Q21
SELECT Ename,
       Hire_date,
       DAYNAME(Hire_date)
FROM EMPLOYEE;

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
       S.Ename AS SupervisorName,
       S.Eno   AS SupervisorEno
FROM EMPLOYEE AS E
         LEFT OUTER JOIN EMPLOYEE AS S
                         ON E.SupervisorENo = S.Eno;

-- Q27
SELECT L.Ename,
       L.Dno,
       L.Salary
FROM EMPLOYEE AS L,
     EMPLOYEE AS R
WHERE L.Dno = R.Dno
  AND L.Salary = R.Salary
  AND L.Eno <> R.Eno
  AND R.Commission IS NOT NULL;

-- Q28
SELECT Ename,
       RPAD('*', Salary / 100, '*') AS Salary_Star
FROM EMPLOYEE;

-- Q29
SELECT MAX(Salary),
       MIN(Salary),
       SUM(Salary),
       AVG(Salary)
FROM EMPLOYEE;

-- Q30
SELECT Job_type,
       COUNT(DISTINCT Eno)
FROM EMPLOYEE
GROUP BY Job_type;

-- Q31
SELECT COUNT(DISTINCT SupervisorENo)
FROM EMPLOYEE;

-- Q32
SELECT Dname,
       Location,
       COUNT(*)              AS NumberOfEmployees,
       ROUND(AVG(Salary), 2) AS AvgSalary
FROM EMPLOYEE
         NATURAL JOIN DEPARTMENT
GROUP BY EMPLOYEE.Dno;

-- Q33
SELECT Ename,
       Hire_date
FROM EMPLOYEE
WHERE Dno IN (
    SELECT Dno
    FROM EMPLOYEE
    WHERE Ename LIKE 'Blake%'
);

-- Q34
SELECT Ename,
       Salary
FROM EMPLOYEE
WHERE Salary > (
    SELECT AVG(Salary)
    FROM EMPLOYEE
);

-- Q35
SELECT Eno,
       Ename
FROM EMPLOYEE
WHERE Dno IN
      (
          SELECT Dno
          FROM EMPLOYEE
          WHERE Ename LIKE '%T%'
      );

-- Q36
SELECT Ename,
       Salary
FROM EMPLOYEE
WHERE SupervisorENo IN (
    SELECT Eno
    FROM EMPLOYEE
    WHERE Ename LIKE 'King%'
);

-- Q37
SELECT Dno,
       Ename,
       Job_type
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT)
WHERE Dname = 'Sales';

-- Q38
SELECT Ename,
       Dname
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT)
WHERE TIMESTAMPDIFF
          (
              YEAR,
              Hire_date,
              NOW()
          ) > 20;

-- Q39
SELECT Location,
       COUNT(*)
FROM DEPARTMENT
GROUP BY Location;

-- Q40
SELECT Dname
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT)
GROUP BY Dno
HAVING COUNT(*) > 20;

-- Q41
(
    SELECT Ename
    FROM EMPLOYEE
    WHERE Eno NOT IN (
        SELECT DISTINCT SupervisorENo
        FROM EMPLOYEE
        WHERE SupervisorENo IS NOT NULL
    )
)
UNION
(
    SELECT Ename
    FROM EMPLOYEE
    WHERE Eno IN (
        SELECT SupervisorENo
        FROM EMPLOYEE
        WHERE SupervisorENo IS NOT NULL
        GROUP BY SupervisorENo
        HAVING COUNT(*) > 5
    )
);

-- Q42
WITH JOBCOUNT AS (
    SELECT COUNT(*) AS ECount
    FROM EMPLOYEE
    GROUP BY Job_type
)
SELECT Job_type,
       COUNT(*)
FROM EMPLOYEE
GROUP BY Job_type
HAVING COUNT(*) IN (
    (
        SELECT MAX(ECount)
        FROM JOBCOUNT
    )
    UNION
    (
        SELECT MIN(ECount)
        FROM JOBCOUNT
    )
);

-- Extra
SELECT Dno,
       Dname,
       COUNT(*)
FROM (EMPLOYEE
         NATURAL JOIN DEPARTMENT)
GROUP BY Dno;
