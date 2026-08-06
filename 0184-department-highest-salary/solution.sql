# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary from  Employee e join department d on
d.id=e.departmentId where(e.departmentId,e.salary) in(
    select e.departmentId,max(e.salary) from  Employee e
    group by departmentId
);
