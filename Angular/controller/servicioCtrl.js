app.controller('servicioCtrl', ['$scope','$routeParams','$http', function($scope,$routeParams,$http){
	
	$scope.setActive("mServicios");

	var codigo = $routeParams.codigo;
	
	$scope.actualizado = true;	
	$scope.creando  =true;

	$scope.mensajeflag = false;
	$scope.mensaje = "";

	$scope.servicio = {};

	if(codigo == "nuevo")
	{	
	   $scope.actualizado = false;	
	}
	else	
	{
		$scope.creando = false;
		$http.get('model/servicios.getServicio.php?c='+codigo).success(function(data)
		{		
			if(data.err !== undefined){
				window.location = "#/servicios" 
				return;
			}
			$scope.servicio = data;
		});
	}
	$scope.guardarServicio = function(){
		if($scope.creando)
		{
			$http.post('model/servicios.setServicio.php',$scope.servicio).success(function(data){
				if(data.err == false){
					$scope.mensaje = "Registro Guardado";					
					$scope.mensajeflag = true;
					setTimeout(function() {
						$scope.mensajeflag = false;							
						window.location = "#/servicios";
						$scope.$apply();
					}, 1500);
				}
				console.log(data);
			});
		}
		else{
			$http.post('model/servicios.updateServicio.php',$scope.servicio).success(function(data){
				if(data.err == false){
					$scope.mensaje = "Registro Actualizado";
					$scope.mensajeflag = true;
					setTimeout(function() {
						$scope.mensajeflag =false;						
						window.location = "#/servicios";
						$scope.$apply();
					}, 1500);
				}				
				console.log(data);
			});
		}
	}

}]);