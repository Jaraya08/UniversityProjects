app.controller('tramiteCtrl', ['$route','$scope','$routeParams','$http', function($route,$scope,$routeParams,$http){
	
	$scope.setActive("mTramites");

	//#region --PARAMETROS--
	var idTramite = $routeParams.codigo;
	var idCliente = $routeParams.cliente;
	//#endregion 

	//#region --VARIABLES--
	$scope.actualizado = true;	
	$scope.creando  = true;

	$scope.mensajeflag = false;
	$scope.mensaje = "";

	$scope.mensajeflagServicio = false;
	$scope.mensajeServicio = "";
	$scope.tramites = {};
	//#endregion 

	//#region --SELECT:SLC_CLIENTE--
	
	$scope.clientes = {};
	$http.get('model/clientes.getListaClientes.php').success(function(data)
	{				
		$scope.clientes = data;
	})

	//#endregion
	
	//#region --SELECT:SLC_SERVICIOSCLIENTE--
	$scope.serviciosFG = {};
	$http.get('model/servicios.getListaServiciosCliente.php?c='+idCliente).success(function(data)
	{		
			$scope.serviciosFG = data;
	})
	//#endregion
	
	//#region --TABLE:TB_SERVICIOSTRAMITE
	$scope.serviciosTramite = {};
	$http.get('model/tramites.getServiciosTramite.php?c='+idTramite).success(function(data)
	{		
			$scope.serviciosTramite = data;
	})
	//#endregion
		
	//#region --GET TRAMITE--	
	if(idTramite == "nuevo")
	{	
	   $scope.actualizado = false;
	   $scope.creando = false;
	   		   
	}
	else	
	{
		$http.get('model/tramites.getTramite.php?c='+idTramite).success(function(data)
		{		
			if(data.err !== undefined){
				window.location = "#/tramites" 
				return;
			}
			$scope.tramites = data;
		});
	}
	//#endregion

	//#region --SET/UPDATE TRAMITE--
	$scope.guardarTramite = function(){
		if(!$scope.creando)
		{
			$http.post('model/tramites.setTramite.php',$scope.tramites).success(function(data){
				if(data.err == false){
					$scope.mensaje = "Registro Guardado";					
					$scope.mensajeflag = true;
					setTimeout(function() {
						$scope.mensajeflag = false;							
						window.location = "#/tramites";
						$scope.$apply();
					}, 1000);
				}
				console.log(data);
			});
		}
		else{

			$http.post('model/tramites.updateTramite.php',$scope.tramites).success(function(data){
				if(data.err == false){
					$scope.mensaje = "Registro Actualizado";
					$scope.mensajeflag = true;
					setTimeout(function() {
						$scope.mensajeflag =false;						
						window.location = "#/tramites";
						$scope.$apply();
					}, 1000);
				}								
			});
		}
	}

	//#endregion
	
	//#region --SET SERVICIO TRAMITE--
	$scope.setServicioTramite = function(idCliente,idTramite,idServicio)
	{
		$scope.tramiteServicio = new Array()
		$scope.tramiteServicio.push(idCliente);
		$scope.tramiteServicio.push(idTramite);
		$scope.tramiteServicio.push(idServicio);
		console.log($scope.tramiteServicio);
		$http.post('model/tramites.setServiciosTramite.php',$scope.tramiteServicio).success(function(data){			
			if(data.err == false)
			{
				$scope.mensajeServicio = "Servicio incluido correctamente";
				$scope.mensajeflagServicio = true;				
				setTimeout(function() {
					$scope.mensajeflagServicio =false;																
					$scope.$apply();
				}, 1500);					
				$route.reload();										
			}
			
		});	
									
	}
	//#endregion
		
	//#region --PAGINACIÓN / VOLVER--
	$scope.posicion = 7;

	$scope.Siguiente = function()
	{
		if($scope.tramites.length >$scope.posicion)
		{
			$scope.posicion +=7;
		};
	}	

	$scope.Anterior = function()
	{
		if($scope.posicion > 7)
		{
			$scope.posicion -=7;
		};
	}

	$scope.volver = function()
	{
		window.location = "#/tramites";
	}
	//#endregion

}]);