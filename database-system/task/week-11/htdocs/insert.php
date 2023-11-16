<?php
include_once 'dbconfig.php';

// Select a database
$dbname = 'testdb';
mysqli_select_db($conn, $dbname) or die('DB selection failed');

// Insert a record
$sql = "INSERT INTO users(name, age, email)
        VALUES('KJH', 26, 'etyanue@chungbuk.ac.kr')";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
    echo "<br/><a href='multi-query.php'>Click to add three data !</a>";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>