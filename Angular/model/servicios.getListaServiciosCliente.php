<?php

error_reporting(0);

// Incluir la clase de base de datos
include_once("../model/class.Database.php");

// Retorna un json
header('Content-Type: application/json');

$codigos = htmlentities($_GET['c']);

$sql = "CALL SP_getListadoServiciosCliente('".$codigos."')";

echo Database::get_json_rows($sql);

?>
