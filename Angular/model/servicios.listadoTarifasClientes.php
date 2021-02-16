<?php
// Incluir la clase de base de datos
include_once("../model/class.Database.php");

// Retorna un json
header('Content-Type: application/json;');

// Verificar que venga el parametro
if (!isset($_GET['c'])) {
	echo json_encode( array('err' => true,'mensaje'=>"Falta el código") );
	die;
}

// Desinfectar el parametro
$codigos = htmlentities($_GET['c']);

	// Si existe, imprime el json
$sql = "SELECT Codigo,Codigoservicio IdServicio,NombreServicio,Monto 
				FROM V_TarifasPersonalizadas WHERE Codigo = '".$codigos."'";
		
echo Database::get_json_rows($sql);


?>
