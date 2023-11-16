<?php
include_once '../dbconfig.php';

$dbname = "ecommerce";
mysqli_select_db($conn, $dbname) or die("DB selection failed");

// SQL to delete a record
$sql = "DELETE FROM orders WHERE order_id = 4 AND product = 'Books' AND total = 1000 AND customer_id = 1";

if ($conn->query($sql) === TRUE) {
    echo "Record deleted successfully";
    echo "<br/><a href='select.php'>Click to select data !</a>";
} else {
    echo "Error deleting record: " . $conn->error;
}

$conn->close();
?>