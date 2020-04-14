<?php

// Here first we have to declare our database connection configurations
//Here we declared hostname, username password name and the database which we will get backup.
$hostname = "localhost";
$username = "vlitheco_theC0d3";
$password = 'nR;F=v@~?z+k'; 
$database_name = 'vlitheco_thec0d3Brk'; 

// And then create MySql connection with connection configurations
$connection = mysqli_connect($hostname, $username, $password, $database_name);
// And then we set the charset as UTF8 of the connection
$connection->set_charset("utf8");

//Until here our connection configurations are ready. After here we are going to get all datas inside the tables in specified database.

//To do this first we have to get all database tables And add them into an array variable to hold the database table list.
$tables = array();
$query_tables = mysqli_query($connection, "SHOW TABLES");

while ($rows = mysqli_fetch_row($query_tables)) {
    $tables[] = $rows[0];
}

//And here we are going to declare a string variable to load all mysql datas into it.
$sqlQuery = "";
// We will get all of table contents and load into this variable.
foreach ($tables as $table) {
    
    // first we have to create the table. This query will create the query string.
    $query = "SHOW CREATE TABLE " . $table;
    $result = mysqli_query($connection, $query);
    $row = mysqli_fetch_row($result);
    
    $sqlQuery .= "\n" . $row[1] . ";\n";
    
    //Get all datas of these tables in here
    $query = "SELECT * FROM " . $table;
    $result = mysqli_query($connection, $query);
    //and also get all columns to use it in for loop to synchronise for all columns.
    $columns = mysqli_num_fields($result);
    
    // We are going to get and append all rows and columns data in here with INSERT INTO command. This command will work and add all of datas inside the table.
    for ($i = 0; $i < $columns; $i ++) {
        while ($row = mysqli_fetch_row($result)) {
            $sqlQuery .= "INSERT INTO $table VALUES(";
            for ($j = 0; $j < $columns; $j ++) {
                $row[$j] = $row[$j];
                
                if (isset($row[$j])) {
                    $sqlQuery .= '"' . $row[$j] . '"';
                } else {
                    $sqlQuery .= '""';
                }
                if ($j < ($columns - 1)) {
                    $sqlQuery .= ',';
                }
            }
            $sqlQuery .= ");\n";
        }
    }
    
    $sqlQuery .= "\n"; 
}

//And lastly if the sql query string is not empty it will create the sql file.
if($sqlQuery != "")
{
    // We will create the it with database name and the date as sql file
    $backup_file_name = "backup_" . $database_name . '_' . date() . '.sql';
    $fileHandler = fopen($backup_file_name, 'w+');
    $number_of_lines = fwrite($fileHandler, $sqlQuery);
    fclose($fileHandler); 

    // Lastly download the sql file.
    header('Content-Description: File Transfer');
    header('Content-Type: application/octet-stream');
    header('Content-Disposition: attachment; filename=' . basename($backup_file_name));
    header('Content-Transfer-Encoding: binary');
    header('Expires: 0');
    header('Cache-Control: must-revalidate');
    header('Pragma: public');
    header('Content-Length: ' . filesize($backup_file_name));
    ob_clean();
    flush();
    readfile($backup_file_name);
    exec('rm ' . $backup_file_name); 
}
?>