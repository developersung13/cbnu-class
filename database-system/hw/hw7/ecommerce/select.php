<?php
include_once '../dbconfig.php';

$dbname = "ecommerce";
mysqli_select_db($conn, $dbname) or die("DB selection failed");

$sql = "SELECT orders.order_id, orders.product, orders.total, customers.first_name, customers.last_name, customers.age, customers.country 
        FROM orders 
        JOIN customers ON orders.customer_id = customers.id";

$result = $conn->query($sql);

echo "<h2>Customer Orders</h2>";

if ($result->num_rows > 0) {
    echo "<table border='1'>
            <tr>
                <th>Order ID</th>
                <th>Product</th>
                <th>Total</th>
                <th>Customer First Name</th>
                <th>Customer Last Name</th>
                <th>Customer Age</th>
                <th>Customer Country</th>
            </tr>";

    while($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>".$row["order_id"]."</td>
                <td>".$row["product"]."</td>
                <td>".$row["total"]."</td>
                <td>".$row["first_name"]."</td>
                <td>".$row["last_name"]."</td>
                <td>".$row["age"]."</td>
                <td>".$row["country"]."</td>
              </tr>";
    }

    echo "</table>";
} else {
    echo "0 results found";
}

$conn->close();
?>
