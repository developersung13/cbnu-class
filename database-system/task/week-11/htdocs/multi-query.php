<?php
include_once 'dbconfig.php';

// Select a database
$dbname = "testdb";
mysqli_select_db($conn, $dbname) or die("DB selection failed");

$sql = "INSERT INTO users(name, age, email)
        VALUES('CJH', 29, 'leopard@chungbuk.ac.kr');";

$sql .= "INSERT INTO users(name, age, email)
        VALUES('Mary', 31, 'mary@chungbuk.ac.kr');";

$sql .= "INSERT INTO users(name, age, email)
        VALUES('Julie', 24, 'julie@chungbuk.ac.kr');";

if ($conn->multi_query($sql) === TRUE) {
    echo "New records created successfully";
    echo "<br/><a href='prepare.php'>Click to use prepared query !</a>";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>