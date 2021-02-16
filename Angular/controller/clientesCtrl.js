app.controller('clientesCtrl', ['$scope','$http', function($scope,$http){
	
	$scope.setActive("mClientes");
	$scope.clientes = {};
	$scope.posicion = 7;
	
	$http.get('model/clientes.getListaClientes.php').success(function(data){
		console.log(data);
		$scope.clientes = data;
	})

	$scope.siguientes = function()
	{
		if($scope.clientes.length >$scope.posicion)
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