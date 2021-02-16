app.controller('tarifasCtrl', ['$scope','$routeParams','$http', function($scope,$routeParams,$http){
	
	$scope.setActive("mClientes");

	var Codcliente = $routeParams.cliente;
	var codigo = $routeParams.codigo;	
	
	$scope.actualizado = true;	
	$scope.creando  =true;

	$scope.mensajeServicioFlag = false;
	$scope.mensajeServicio = "";
	
	//Obtener el listado de los servicios
	$scope.serviciosFG = {};
	$http.get('model/servicios.getListaServicios.php').success(function(data)
	{				
			$scope.serviciosFG = data;
	})

	$scope.servicio = {};

	//Obtener el listado de los servicios
	$scope.clientes = {};
	$http.get('model/clientes.getCliente.php?c='+Codcliente).success(function(data)
	{				
		$scope.clientes = data;
	})

	if(codigo == "nuevo")
	{	
		
	   $scope.actualizado = false;	
	}
	else	
	{
	    $scope.creando = false;				
		$http.get('model/servicios.getTarifaCliente.php',{params: {cliente: Codcliente,servicio: codigo}}).success(function(data)
		{		
			if(data.err !== undefined)
			{
				window.location = "#/cliente/"+Codcliente; 
				return;
			}		
			$scope.servicio = data;
			
		});
	}

	$scope.guardarServicio = function(){

		$scope.datosServicio = new Array();
		$scope.datosServicio.push(Codcliente);
		$scope.datosServicio.push($scope.servicio.IdServicio);
		$scope.datosServicio.push($scope.servicio.Monto);
		if($scope.creando)
		{
			$http.post('model/clientes.setTarifaCliente.php',$scope.datosServicio).success(function(data)
			{
				if(data.err == false)
				{					
					$scope.mensajeServicio = "Tarifa guardada";					
					$scope.mensajeServicioFlag = true;
					setTimeout(function() 
					{
						$scope.mensajeServicioFlag = false;							
						window.location = "#/cliente/"+Codcliente;
						$scope.$apply();
					}, 2500);
				}
				console.log(data);
			});			
		}
		else
		{
			$http.post('model/clientes.updateTarifaCliente.php',$scope.datosServicio).success(function(data)
			{				
				if(data.err == false)
				{					
					$scope.mensajeServicio = "Tarifa actualizada";
					$scope.mensajeServicioFlag = true;
					setTimeout(function() 
					{
						$scope.mensajeServicioFlag =false;						
						window.location = "#/cliente/"+Codcliente;
						$scope.$apply();
					}, 2500);
				}				
				console.log(data);
			});
		}
	}	
	$scope.volver = function()
	{
		window.location = "#/cliente/"+Codcliente;
	}
	
}]);