<?php
include_once '../dbconfig.php';

$dbname = "ecommerce";
mysqli_select_db($conn, $dbname) or die('DB selection failed');

// Insert data into customers table
$customers = [
    [1, "John", "Doe", 31, "USA"],
    [2, "Robert", "Luna", 22, "USA"],
    [3, "David", "Robinson", 22, "UK"],
    [4, "John", "Reinhardt", 25, "UK"],
    [5, "Betty", "Doe", 28, "UAE"]
];

$stmt = $conn->prepare("INSERT INTO customers(id, first_name, last_name, age, country) VALUES (?, ?, ?, ?, ?)");
$stmt->bind_param("issis", $id, $first_name, $last_name, $age, $country);

$customers_success = true;
foreach ($customers as $customer) {
    list($id, $first_name, $last_name, $age, $country) = $customer;
    if (!$stmt->execute()) {
        $customers_success = false;
        echo "Error inserting customer: " . $stmt->error . "<br/>";
    }
}

// Insert data into orders table
$orders = [
    [1, "Paper", 500, 5],
    [2, "Pen", 10, 2],
    [3, "Marker", 120, 3],
    [4, "Books", 1000, 1],
    [5, "Erasers", 20, 4]
];

$stmt = $conn->prepare("INSERT INTO orders(order_id, product, total, customer_id) VALUES (?, ?, ?, ?)");
$stmt->bind_param("isii", $order_id, $product, $total, $customer_id);

$orders_success = true;
foreach ($orders as $order) {
    list($order_id, $product, $total, $customer_id) = $order;
    if (!$stmt->execute()) {
        $orders_success = false;
        echo "Error inserting order: " . $stmt->error . "<br/>";
    }
}

if ($customers_success && $orders_success) {
    echo "Data inserted successfully into customers and orders tables.";
    echo "<br/><a href='delete.php'>Click to delete data !</a>";
} else {
    echo "Error occurred during data insertion.";
}

$stmt->close();
$conn->close();
?>
