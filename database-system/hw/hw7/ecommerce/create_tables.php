<?php
include_once '../dbconfig.php';

$dbname = "ecommerce";
mysqli_select_db($conn, $dbname) or die('DB selection failed');

// Create customers table
$sql1 = "CREATE TABLE customers(
    id INT(4) UNSIGNED AUTO_INCREMENT,
    first_name VARCHAR(20) NOT NULL,
    last_name VARCHAR(20) NOT NULL,
    age INT(3) NOT NULL,
    country VARCHAR(3) NOT NULL,
    PRIMARY KEY(id)
)";

// Execute first query
if ($conn->query($sql1) !== TRUE) {
    echo "Error creating customers table: " . $conn->error;
    echo "<br/>";
}

// Create orders table
$sql2 = "CREATE TABLE orders(
    order_id INT(4) UNSIGNED AUTO_INCREMENT,
    product VARCHAR(30) NOT NULL,
    total INT(15),
    customer_id INT(4) UNSIGNED,
    PRIMARY KEY(order_id),
    FOREIGN KEY(customer_id) REFERENCES customers(id)
)";

// Execute second query
if ($conn->query($sql2) === TRUE) {
    echo "Table customers, orders created successfully";
    echo "<br/><a href='insert.php'>Click to add data !</a>";
} else {
    echo "Error creating orders table: " . $conn->error;
    echo "<br/>";
}

$conn->close();
?>
