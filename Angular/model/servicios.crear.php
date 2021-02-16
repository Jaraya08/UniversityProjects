<?php
// Incluir la clase de base de datos
include_once("../model/class.Database.php");

$postdata = file_get_contents("php://input");

$request = json_decode($postdata);

$request =  (array) $request;

$request['NombreServicio'] = strtoupper($request['NombreServicio']);

$sql = "CALL SP_AgregarServicioFG('". $request['NombreServicio'] ."')";

$Hecho = Database::ejecutar_idu($sql);

$Respuesta = "";

if ($Hecho == "1") 
{
	$Respuesta = json_encode( array('err' => false, 'mensaje'=>'Registro Insertado.' ));
}

else
{
	$Respuesta = json_encode( array('err' => true, 'mensaje'=> $Hecho ));
}

echo $Respuesta;

?>