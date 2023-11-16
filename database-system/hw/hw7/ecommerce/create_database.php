<?php
include_once '../dbconfig.php';

// Create database
$sql = "CREATE DATABASE ecommerce";

if ($conn->query($sql) === TRUE) {
    echo "Database ecommerce created successfully";
    echo "<br/><a href='create_tables.php'>Click to create a tables !</a>";
} else {
    echo "Error creating database: ";
    echo "<br/>";
    echo $conn->error;
}

$conn->close();
?>