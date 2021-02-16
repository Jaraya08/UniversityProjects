<?php
// Incluir la clase de base de datos
include_once("../model/class.Database.php");

$postdata = file_get_contents("php://input");

$request = json_decode($postdata);

$request =  (array) $request;


$request['DuasViajes'] = strtoupper($request['DuasViajes']);
$request['CodigoCliente'] = strtoupper($request['CodigoCliente']);
$request['Referencias'] = strtoupper($request['Referencias']);

$sql = "CALL SP_setTramite('". $request['CodigoCliente'] ."','". $request['DuasViajes'] ."','". $request['Referencias'] ."')";

$Hecho = Database::ejecutar_idu($sql);

$Respuesta = "";

if ($Hecho == "1") {
	$Respuesta = json_encode( array('err' => false, 'mensaje'=>'Registro Insertado.' ));
}else{
	$Respuesta = json_encode( array('err' => true, 'mensaje'=> $Hecho ));
}

echo $Respuesta;

?>