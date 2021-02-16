app.config( function($routeProvider){

	$routeProvider
		.when('/',{
			templateUrl: 'view/home.html',
			controller: 'homeCtrl'
		})
		.when('/clientes',{
			templateUrl: 'view/clientes.html',
			controller: 'clientesCtrl'
		})
		.when('/cliente/:codigo',{
			templateUrl: 'view/cliente.html',
			controller: 'clienteCtrl'
		})
		.when('/tarifas/:cliente/:codigo',{
			templateUrl: 'view/tarifas.html',
			controller: 'tarifasCtrl'
		})
		.when('/tramites',{
			templateUrl: 'view/tramites.html',
			controller: 'tramitesCtrl'
		})
		.when('/tramite/:cliente/:codigo',{
			templateUrl: 'view/tramite.html',
			controller: 'tramiteCtrl'
		})
		.when('/servicios',{
			templateUrl: 'view/servicios.html',
			controller: 'serviciosCtrl'
		})
		.when('/servicio/:codigo',{
			templateUrl: 'view/servicio.html',
			controller: 'servicioCtrl'
		})
		.when('/reportes',{
			templateUrl: 'view/reportes.html',
			controller: 'reportesCtrl'
		})
		.otherwise({
			redirectTo: '/'
		});
});