<?php
include_once 'dbconfig.php';

// Select a database
$dbname = "testdb";
mysqli_select_db($conn, $dbname) or die("DB selection failed");

$sql = "DELETE  FROM users WHERE id = 5 AND name = 'John'";

if ($conn->multi_query($sql) === TRUE) {
    echo "Record deleted successfully";
    echo "<br/><a href='select.php'>Click to select data !</a>";
} else {
    echo "Error deleting record: ";
    echo "<br/>";
    echo $conn->error;
}

$conn->close();
?>