<?php
include_once 'dbconfig.php';

// Select a database
$dbname = "testdb";
mysqli_select_db($conn, $dbname) or die("DB selection failed");

$stmt = $conn->prepare("INSERT INTO users(name, age, email) VALUES(?, ?, ?)");
$stmt->bind_param("sis", $name, $age, $email); // 여기를 수정했습니다.

// Set parameters and execute
$name = "John";
$age = 20;
$email = "john@chungbuk.ac.kr";

if ($stmt->execute() === TRUE) { // 여기를 수정했습니다.
    echo "New record created successfully";
    echo "<br/><a href='delete.php'>Click to delete data !</a>";
} else {
    echo "Error occurred !";
}

$stmt->close();
$conn->close();
?>
