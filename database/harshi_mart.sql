CREATE TABLE products (
    id INTEGER PRIMARY KEY,
    name TEXT,
    price REAL,
    stock INTEGER
);

INSERT INTO products VALUES
(1,'Laptop',57000,10),
(2,'Mouse',800,25),
(3,'Keyboard',1200,15),
(4,'Headphones',1800,20),
(5,'Smart Watch',2500,12);

UPDATE products
SET price = 55000
WHERE id = 1;

DELETE FROM products
WHERE id = 5;