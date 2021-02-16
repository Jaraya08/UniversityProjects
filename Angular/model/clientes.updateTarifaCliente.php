<?php

// Incluir la clase de base de datos
include_once("../model/class.Database.php");

$postdata = file_get_contents("php://input");

$request = json_decode($postdata);

$request =  (array) $request;


$sql = "CALL SP_updateTarifaCliente('". $request[0] ."',
										'". $request[1] ."',
							  		    '". $request[2] ."')";

$Hecho = Database::ejecutar_idu($sql);

$Respuesta = "";

if ($Hecho == "1") {

	$Respuesta = json_encode( array('err' => false, 'mensaje'=>'Registro Actualizado.' ));

}else{
	
	$Respuesta = json_encode( array('err' => true, 'mensaje'=> $Hecho ));
}

echo $Respuesta;

?>