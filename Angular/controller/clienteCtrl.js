app.controller('clienteCtrl', ['$scope', '$routeParams', '$http', function ($scope, $routeParams, $http) {

	$scope.setActive("mClientes");

	var codigo = $routeParams.codigo;

	$scope.cogidoGlo = codigo;

	$scope.actualizado = true;
	$scope.creando = true;

	$scope.mensajeflag = false;
	$scope.mensaje = "";


	$scope.cliente = {};

	//Obtener el listado de tarifas por cliente	
	$scope.listaServicios = {};


	if (codigo == "nuevo") {
		$scope.actualizado = false;
	}
	else {
		$scope.creando = false;
		$http.get('model/clientes.getCliente.php?c=' + codigo).success(function (data) {
			if (data.err !== undefined) {
				window.location = "#/clientes"
				return;
			}
			$scope.cliente = data;
		});
		$http.get('model/servicios.getListaTarifaCliente.php?c=' + codigo).success(function (data) {
			$scope.listaServicios = data;
			console.log(data);
		})
	}
	$scope.guardarCliente = function () {
		if ($scope.creando) {
			$http.post('model/clientes.setCliente.php', $scope.cliente).success(function (data) {
				if (data.err == false) {
					$scope.mensaje = "Registro Guardado";
					$scope.mensajeflag = true;
					setTimeout(function () {
						$scope.mensajeflag = false;
						window.location = "#/clientes";
						$scope.$apply();
					}, 1500);
				}
				console.log(data);
			});
		}
		else {
			$http.post('model/clientes.updateCliente.php', $scope.cliente).success(function (data) {
				if (data.err == false) {
					$scope.mensaje = "Registro Actualizado";
					$scope.mensajeflag = true;
					setTimeout(function () {
						$scope.mensajeflag = false;
						window.location = "#/clientes";
						$scope.$apply();
					}, 1500);
				}
				console.log(data);
			});
		}

	}
	$scope.volver = function () {
		window.location = "#/clientes";
	}



	$scope.paises = [
		{ id: "CRC", nombre: "COSTA RICA" },
		{ id: "HND", nombre: "HONDURAS" },
		{ id: "PAM", nombre: "PANAMA" },
		{ id: "COL", nombre: "COLOMBIA" },
		{ id: "HRV", nombre: "CROACIA" },
		{ id: "CUB", nombre: "CUBA" },
		{ id: "DNK", nombre: "DINAMARCA" },
		{ id: "DMA", nombre: "DOMINICA" },
		{ id: "DOM", nombre: "REPÚBLICA DOMINICANA" },
		{ id: "ECU", nombre: "ECUADOR" },
		{ id: "EGY", nombre: "EGIPTO" },
		{ id: "SLV", nombre: "EL SALVADOR" },
		{ id: "ARE", nombre: "EMIRATOS ÁRABES UNIDOS" },
		{ id: "ERI", nombre: "ERITREA" },
		{ id: "SVK", nombre: "ESLOVAQUIA" },
		{ id: "SVN", nombre: "ESLOVENIA" },
		{ id: "ESP", nombre: "ESPAÑA" },
		{ id: "USA", nombre: "ESTADOS UNIDOS" },
		{ id: "EST", nombre: "ESTONIA" }
	];
}]);