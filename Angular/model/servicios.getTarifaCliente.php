<?php
// Incluir la clase de base de datos
include_once("../model/class.Database.php");

// Retorna un json
header('Content-Type: application/json;');



// Verificar que venga el parametro
if (!isset($_GET["cliente"])) {
	echo json_encode( array('err' => true,'mensaje'=>"Falta el código") );
	die;
}

// Verificar que venga el parametro
if (!isset($_GET["servicio"])) {
	echo json_encode( array('err' => true,'mensaje'=>"Falta el código") );
	die;
}

// Desinfectar el parametro
$cliente = htmlentities($_GET["cliente"]);
$servicio = htmlentities($_GET["servicio"]);

	// Si existe, imprime el json
$sql = "SELECT Codigo,Codigoservicio IdServicio,NombreServicio,Monto 
			FROM V_TarifasPersonalizadas 
				WHERE Codigo = '".$cliente."' AND Codigoservicio = '".$servicio."'";		    
echo json_encode( Database::get_Row($sql) );		
?>