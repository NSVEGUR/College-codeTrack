USE lab_1;
CREATE TABLE Employees(
  employee_id int NOT NULL UNIQUE,
  first_name varchar(255),
  last_name varchar(255),
  email varchar(255),
  phone_number bigint,
  hire_date varchar(255),
  job_id varchar(255),
  salary int,
  manager_id int,
  department_id int
);

DROP TABLE Employees;
select
  *
FROM
  Employees;
INSERT INTO
  Employees(
    employee_id,
    first_name,
    last_name,
    email,
    phone_number,
    hire_date,
    job_id,
    salary,
    department_id
  )
VALUES
  (
    700,
    'Hanmukh',
    'Patel',
    'hp@gmail.com',
    7003216160,
    '15-aug-2020',
    'Hp003',
    7000,
    90
  );
INSERT INTO
  Employees
VALUES
  (
    800,
    'Kamlesh',
    'Paul',
    'kp@gmail.com',
    7003216170,
    '17-feb-2020',
    'Kp004',
    8000,
    506,
    90
  );
INSERT INTO
  Employees
VALUES
  (
    900,
    'Dinesh',
    'Gandhi',
    'dp@yahoo.com',
    9136278563,
    '19-march-2101',
    'Dg006',
    20000,
    508,
    80
  );
INSERT INTO
  Employees(
    employee_id,
    first_name,
    last_name,
    email,
    phone_number,
    hire_date,
    job_id,
    salary,
    department_id
  )
VALUES
  (
    701,
    'Suresh',
    'Modi',
    'sm@gmail.com',
    9187653294,
    '20-april-2015',
    'Sm009',
    15000,
    80
  );