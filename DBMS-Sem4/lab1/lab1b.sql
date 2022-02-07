USE lab_1;
CREATE TABLE Agent(
  Agent_code varchar(255),
  Agent_name varchar(255),
  Working_area varchar(255),
  Commision DECIMAL(3,2),
  Phone_number int,
  Country varchar(255)
);
DROP TABLE Orders;
DROP TABLE Agent;
SHOW TABLE;
select
  *
FROM
  Orders;
select
  *
FROM
  Agent;
CREATE TABLE Orders(
    Order_num INT,
    Order_amount INT,
    Advance_amount INT,
    Order_date varchar(255),
    Cust_code varchar(4),
    Agent_code varchar(5),
    Description_ varchar(255)
  );
INSERT INTO
  Orders
VALUES
  (
    004,
    200,
    3000,
    '15-aug-2020',
    'C004',
    'Ac001',
    'Masalakulcha'
  );
INSERT INTO
  Orders
VALUES
  (
    007,
    600,
    5300,
    '17-sept-2020',
    'C006',
    'Ac003',
    'Briyani'
  );
INSERT INTO
  Orders
VALUES
  (
    008,
    700,
    100,
    '19-feb-2019',
    'C007',
    'Ac005',
    'Briyani'
  );
INSERT INTO
  Orders
VALUES
  (
    009,
    10000,
    600,
    '21-march-2019',
    'C009',
    'Ac002',
    'Masala dosa'
  );
INSERT INTO
  Orders
VALUES
  (
    010,
    20,
    600,
    '21-april-2012',
    'C006',
    'Ac005',
    'Chicken Tikka'
  );
INSERT INTO
  Agent
VALUES(
    'Ac001',
    'Ramesh',
    'Bangalore',
    0.15,
    0331234567,
    'India'
  );
INSERT INTO
  Agent(
    Agent_code,
    Agent_name,
    Working_area,
    Commision,
    Phone_number
  )
VALUES(
    'Ac003',
    'Dinesh',
    'Bangalore',
    0.25,
    0331234568
  );
INSERT INTO
  Agent
VALUES(
    'Ac003',
    'Suresh',
    'Mumbai',
    0.35,
    0331234569,
    'London'
  );
INSERT INTO
  Agent(
    Agent_code,
    Agent_name,
    Working_area,
    Commision,
    Phone_number
  )
VALUES(
    'Ac004',
    'Kamlesh',
    'New Jersey',
    0.68,
    0331234564
  );
INSERT INTO
  Agent
VALUES(
    'Ac005',
    'Kartik',
    'Chennai',
    0.73,
    0331234563,
    'India'
  );