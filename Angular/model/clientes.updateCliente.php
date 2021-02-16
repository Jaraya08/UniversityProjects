<?php
// Incluir la clase de base de datos
include_once("../model/class.Database.php");

$postdata = file_get_contents("php://input");

$request = json_decode($postdata);

$request =  (array) $request;


$request['Nombre'] = strtoupper($request['Nombre']);


$sql = "CALL SP_updateCliente('". $request['Codigo'] ."','". $request['TipoCliente'] ."',
								'". $request['Nombre'] ."','". $request['Identificacion'] ."',
								'". $request['Procedencia'] ."','". $request['Telefono'] ."',
								'". $request['Correo'] ."')";

$Hecho = Database::ejecutar_idu($sql);

$Respuesta = "";

if ($Hecho == "1") {

	$Respuesta = json_encode( array('err' => false, 'mensaje'=>'Registro Actualizado.' ));

}else{
	
	$Respuesta = json_encode( array('err' => true, 'mensaje'=> $Hecho ));
}

echo $Respuesta;

?>