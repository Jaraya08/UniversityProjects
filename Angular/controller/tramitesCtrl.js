app.controller('tramitesCtrl', ['$scope', '$http','filterFilter', function ($scope, $http,filterFilter) {

	$scope.setActive("mTramites");
	$scope.tramites = {};
	$scope.posicion = 7;
	 
	$http.get('model/tramites.getListaTramites.php').success(function (data) {
		console.log(data);
		$scope.tramites = data;		
	})

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

}]);