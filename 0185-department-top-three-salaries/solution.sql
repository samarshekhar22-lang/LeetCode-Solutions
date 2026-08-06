SELECT 
    d.name AS Department, 
    e.name AS Employee, 
    e.salary AS Salary 
FROM Employee e 
JOIN Department d ON d.id = e.departmentId
WHERE (e.departmentId, e.salary) IN (
    select e1.departmentId, e1.salary from Employee e1
    where 3>(select count(distinct e2.salary) from Employee e2
    where(e1.departmentId=e2.departmentId and e2.salary>e1.salary)
    )
);
