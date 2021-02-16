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


// Verificar si existe
// Verificar si existe
$sql = "SELECT count(Codigo) as Existe 
		FROM T_Clientes WHERE Codigo = '".$codigos."'";

$existe = Database::get_valor_query($sql,"Existe");


if ($existe == 1) {
	// Si existe, imprime el json
	$sql = "CALL SP_getCliente('".$codigos ."')";	
	echo json_encode( Database::get_Row($sql) );		
}
else
{
	echo json_encode( array('err'=>true, 'mensaje'=>'Código no existe') );
}

?>