<?php
include_once 'dbconfig.php';

// Select a database
$dbname = "testdb";
mysqli_select_db($conn, $dbname) or die("DB selection failed");

$sql = "SELECT * FROM users";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Output data of each row
    while ($row = $result->fetch_assoc()) {
        echo "id: " . $row["id"]. ",    Name: " . $row["name"]
            . ",    Email: " . $row["email"] . ",   Register Date: " . $row["reg_date"] . "<br>";
    }
} else {
    echo "0 results";
}

$conn->close();
?>