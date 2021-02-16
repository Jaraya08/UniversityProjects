app.controller('serviciosCtrl', ['$scope','$http', function($scope,$http){
	
	$scope.setActive("mServicios");
	$scope.servicios = {};
	$scope.posicion = 7;
	
	$http.get('model/servicios.getListaServicios.php').success(function(data){
		console.log(data);
		$scope.servicios = data;
	})

	$scope.siguientes = function()
	{
		if($scope.servicios.length >$scope.posicion)
		{
			$scope.posicion +=7;
		};
	}
	$scope.anteriores = function()
	{

		if($scope.posicion > 7)
		{
			$scope.posicion -=7;
		};
	}

}]);