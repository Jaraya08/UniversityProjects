<?php

error_reporting(0);

// Incluir la clase de base de datos
include_once("../model/class.Database.php");

// Retorna un json
header('Content-Type: application/json');

$sql = "SELECT 
			Codigo,
			TipoCliente,
			Nombre,
			Identificacion,
			Procedencia
			Telefono,
			Correo,
			Estado 
		FROM T_Clientes";

echo Database::get_json_rows($sql);

?>