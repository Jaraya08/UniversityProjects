var app = angular.module('WebSiteFG',['ngResource','ngRoute','ui.mask','jcs-autoValidate','ui.bootstrap']);


angular.module('jcs-autoValidate').run([
	'defaultErrorMessageResolver',
	function (defaultErrorMessageResolver) {
		// To change the root resource file path
		
		defaultErrorMessageResolver.setI18nFileRootPath('js/lib');
		defaultErrorMessageResolver.setCulture('es-CO');
		defaultErrorMessageResolver.getErrorMessages().then(function (errorMessages) {
		errorMessages['edadMinima'] = 'Debe de ser mayor a {0} años de edad.';
		errorMessages['edadMaxima'] = 'Debe de ser menor a {0} años de edad.';		
		});
	}
]);

app.controller('mainCtrl', ['$scope','$http', function($scope,$http){
  
	$scope.menuSuperior = 'view/menu.html';
	
	$scope.telefonoMask = "9999-9999";

	$scope.setActive = function(Opcion){

		$scope.mInicio     = "";
		$scope.mTramites = "";
		$scope.mClientes    = "";
		$scope.mReportes = "";		
		$scope.mServicios = "";		
		$scope[Opcion] = "active";
	}

}]);

