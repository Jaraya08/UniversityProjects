<?php
// Incluir la clase de base de datos
include_once("../model/class.Database.php");

$postdata = file_get_contents("php://input");

$request = json_decode($postdata);

$request =  (array) $request;


$request['Nombre'] = strtoupper($request['Nombre']);
$request['Codigo'] = strtoupper($request['Codigo']);

//call SP_AgregarCliente('FG00/686','Físico','Jordan Araya Leiva','702130379','CRC','86223950','jordan.kn08@gmail.com')

$sql = "CALL SP_setCliente('". $request['Codigo'] ."'
							  ,'". $request['TipoCliente'] ."',
							  '". $request['Nombre'] ."',
							  '". $request['Identificacion'] ."',
							  '". $request['Procedencia'] ."',
							  '". $request['Telefono'] ."',
							  '". $request['Correo'] ."')";

$Hecho = Database::ejecutar_idu($sql);

$Respuesta = "";

if ($Hecho == "1") {
	$Respuesta = json_encode( array('err' => false, 'mensaje'=>'Registro Insertado.' ));
}else{
	$Respuesta = json_encode( array('err' => true, 'mensaje'=> $Hecho ));
}

echo $Respuesta;

?>