--ROLES

INSERT INTO FuncionRol  values('Administrador',1,1,1,1,1,1,1,1,1,1,1,1,1,1,1)
INSERT INTO FuncionRol  values('Gerente',1,0,1,0,1,0,1,1,1,1,1,1,1,1,1)
INSERT INTO FuncionRol  values('Usuarios',1,1,0,1,0,1,1,1,1,1,1,1,0,1,0)

--USUARIOS 

INSERT INTO Usuarios VALUES('Jordan',1234,1,1)
INSERT INTO Usuarios VALUES('Allan',1234,1,2)
INSERT INTO Usuarios VALUES('Luis',1234,1,3)
INSERT INTO Usuarios VALUES('Emanuel',1234,1,3)
INSERT INTO Usuarios VALUES('Alonso',1234,1,3)
INSERT INTO Usuarios VALUES('Juan',1234,1,3)
INSERT INTO Usuarios VALUES('Cris',1234,1,3)
INSERT INTO Usuarios VALUES('Abrahan',1234,1,3)
INSERT INTO Usuarios VALUES('Herwin',1234,1,3)
INSERT INTO Usuarios VALUES('Darian',1234,1,3)
INSERT INTO Usuarios VALUES('Alfredo',1234,1,3)
INSERT INTO Usuarios VALUES('Andrey',1234,1,3)
INSERT INTO Usuarios VALUES('Kendrick',1234,1,3)
INSERT INTO Usuarios VALUES('Esteban',1234,1,3)
INSERT INTO Usuarios VALUES('Heiner',1234,1,3)
INSERT INTO Usuarios VALUES('Kevin',1234,1,3)
INSERT INTO Usuarios VALUES('Byron',1234,1,3)
INSERT INTO Usuarios VALUES('Johanna',1234,1,3)
INSERT INTO Usuarios VALUES('Vannesa',1234,1,3)
INSERT INTO Usuarios VALUES('Ivanka',1234,1,3) --(20)

--DEPARTAMENTOS

INSERT INTO Departamentos VALUES('Administracion',1)
INSERT INTO Departamentos VALUES('Compras',1)
INSERT INTO Departamentos VALUES('Recursos Humanos',1)
INSERT INTO Departamentos VALUES('Produccion',1)
INSERT INTO Departamentos VALUES('Control de gestion',1)
INSERT INTO Departamentos VALUES('Marketing',1)

--MONEDAS

INSERT INTO Divisa VALUES('CRC',1)
INSERT INTO Divisa VALUES('USD',1)
INSERT INTO Divisa VALUES('EUR',1)

--ESTAPAS COTIZACION

INSERT INTO EtapaCotizacion VALUES('Final',1)
INSERT INTO EtapaCotizacion VALUES('Inicial',1)
INSERT INTO EtapaCotizacion VALUES('Aceptada',1)

--ZONAS 
INSERT INTO ZONAS VALUES('Region Norte',1)
INSERT INTO ZONAS VALUES('Valle Central',1)
INSERT INTO ZONAS VALUES('Vertiente del Caribe',1)

--SECTORES
INSERT INTO Sectores VALUES('San Jose',1)
INSERT INTO Sectores VALUES('Curridabat',1)
INSERT INTO Sectores VALUES('Alajuela',1)
INSERT INTO Sectores VALUES('Limon',1)
INSERT INTO Sectores VALUES('Guapiles',1)
INSERT INTO Sectores VALUES('Heredia',1)
INSERT INTO Sectores VALUES('Guanacaste',1)

-- TIPO COTIZACION

INSERT INTO TipoCotizacion VALUES('Cotizacion',1)
INSERT INTO TipoCotizacion VALUES('Auxiliares',1)
INSERT INTO TipoCotizacion VALUES('Ayudantes',1)

--PROBABLIDAD 
INSERT INTO Probabilidad VALUES(25,1)
INSERT INTO Probabilidad VALUES(50,1)
INSERT INTO Probabilidad VALUES(75,1)
INSERT INTO Probabilidad VALUES(90,1)

--DENEGACIONES
INSERT INTO Denegaciones VALUES('Ninguna',1)
INSERT INTO Denegaciones VALUES('No Cumple',1)
INSERT INTO Denegaciones VALUES('No es Valido',1)


-- CONTRA QUIEN 
INSERT INTO PerdidaCotizacion values('Competencia 1',1)
INSERT INTO PerdidaCotizacion values('Competencia 2',1)
INSERT INTO PerdidaCotizacion values('Competencia 3',1)

--CLIENTES
INSERT INTO Clientes VALUES('Cliente 1','Correo1@gmail.com','Contacto 1',1,'86223950','702130379','N/A','N/A',1,1,1,1)
INSERT INTO Clientes VALUES('Cliente 2','Correo2@gmail.com','Contacto 2',1,'86223950','702130379','N/A','N/A',2,2,2,1)
INSERT INTO Clientes VALUES('Cliente 3','Correo3@gmail.com','Contacto 3',1,'86223950','702130379','N/A','N/A',3,3,3,1)
INSERT INTO Clientes VALUES('Cliente 4','Correo4@gmail.com','Contacto 4',1,'86223950','702130379','N/A','N/A',4,3,4,1)
INSERT INTO Clientes VALUES('Cliente 5','Correo5@gmail.com','Contacto 5',1,'86223950','702130379','N/A','N/A',5,1,5,1)
INSERT INTO Clientes VALUES('Cliente 6','Correo6@gmail.com','Contacto 6',1,'86223950','702130379','N/A','N/A',6,1,6,1)
INSERT INTO Clientes VALUES('Cliente 7','Correo7@gmail.com','Contacto 7',1,'86223950','702130379','N/A','N/A',7,2,7,1)
INSERT INTO Clientes VALUES('Cliente 8','Correo8@gmail.com','Contacto 8',1,'86223950','702130379','N/A','N/A',7,1,5,1)
INSERT INTO Clientes VALUES('Cliente 9','Correo9@gmail.com','Contacto 9',1,'86223950','702130379','N/A','N/A',7,3,4,1)
INSERT INTO Clientes VALUES('Cliente 10','Correo10@gmail.com','Contacto 10',1,'86223950','702130379','N/A','N/A',9,2,3,1)
INSERT INTO Clientes VALUES('Cliente 11','Correo11@gmail.com','Contacto 11',1,'86223950','702130379','N/A','N/A',10,2,3,1)
INSERT INTO Clientes VALUES('Cliente 12','Correo12@gmail.com','Contacto 12',1,'86223950','702130379','N/A','N/A',11,1,3,1)
INSERT INTO Clientes VALUES('Cliente 13','Correo13@gmail.com','Contacto 13',1,'86223950','702130379','N/A','N/A',12,1,2,1)
INSERT INTO Clientes VALUES('Cliente 14','Correo14@gmail.com','Contacto 14',1,'86223950','702130379','N/A','N/A',13,1,5,1)
INSERT INTO Clientes VALUES('Cliente 15','Correo15@gmail.com','Contacto 15',1,'86223950','702130379','N/A','N/A',12,2,6,1)
INSERT INTO Clientes VALUES('Cliente 16','Correo16@gmail.com','Contacto 16',1,'86223950','702130379','N/A','N/A',11,3,7,1)
INSERT INTO Clientes VALUES('Cliente 17','Correo17@gmail.com','Contacto 17',1,'86223950','702130379','N/A','N/A',1,1,2,1)
INSERT INTO Clientes VALUES('Cliente 18','Correo18@gmail.com','Contacto 18',1,'86223950','702130379','N/A','N/A',5,2,2,1)
INSERT INTO Clientes VALUES('Cliente 19','Correo19@gmail.com','Contacto 19',1,'86223950','702130379','N/A','N/A',8,2,3,1)
INSERT INTO Clientes VALUES('Cliente 20','Correo20@gmail.com','Contacto 20',1,'86223950','702130379','N/A','N/A',9,2,4,1)
INSERT INTO Clientes VALUES('Cliente 21','Correo21@gmail.com','Contacto 21',1,'86223950','702130379','N/A','N/A',12,3,5,1)
INSERT INTO Clientes VALUES('Cliente 22','Correo22@gmail.com','Contacto 22',1,'86223950','702130379','N/A','N/A',10,3,6,1)
INSERT INTO Clientes VALUES('Cliente 23','Correo23@gmail.com','Contacto 23',1,'86223950','702130379','N/A','N/A',4,3,7,1)
INSERT INTO Clientes VALUES('Cliente 24','Correo24@gmail.com','Contacto 24',1,'86223950','702130379','N/A','N/A',7,3,3,1)
INSERT INTO Clientes VALUES('Cliente 25','Correo25@gmail.com','Contacto 25',1,'86223950','702130379','N/A','N/A',15,2,3,1)

--COTIZACIONES 
INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
	   VALUES(1,'Oportunidad 1',1,1,'2017-06-12',1,1,3,'NA',2,N'NA',1,2,'Contacto 1','NA',3,1,1)

INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(2,'Oportunidad 2',2,2,'2017-09-12',0,1,3,'NA',2,N'NA',2,1,'Contacto 2','NA',3,1,1)

INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(3,'Oportunidad 3',3,4,'2017-08-12',0,1,2,'NA',2,N'NA',3,4,'Contacto 3','NA',3,1,1)

INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(4,'Oportunidad 4',5,7,'2017-07-12',1,1,3,'NA',2,N'NA',3,6,'Contacto 4','NA',3,1,1)

INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(5,'Oportunidad 5',5,4,'2017-07-12',0,1,3,'NA',2,N'NA',3,6,'Contacto 4','NA',2,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(6,'Oportunidad 5',7,12,'2017-06-12',1,1,3,'NA',2,N'NA',2,5,'Contacto 5','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(3,'Oportunidad 6',20,13,'2017-08-12',1,1,3,'NA',2,N'NA',1,2,'Contacto 6','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(2,'Oportunidad 7',12,10,'2017-08-12',1,1,3,'NA',2,N'NA',3,1,'Contacto 7','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(4,'Oportunidad 8',1,3,'2017-06-12',1,1,3,'NA',2,N'NA',2,6,'Contacto 8','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(2,'Oportunidad 9',5,6,'2017-06-12',0,1,3,'NA',2,N'NA',2,2,'Contacto 9','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(3,'Oportunidad 10',24,3,'2017-09-12',0,1,3,'NA',1,N'NA',1,1,'Contacto 10','NA',3,1,1)

INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(5,'Oportunidad 11',17,11,'2017-10-12',0,1,3,'NA',1,N'NA',3,3,'Contacto 11','NA',1,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(1,'Oportunidad 12',18,6,'2017-11-12',0,1,3,'NA',1,N'NA',1,2,'Contacto 12','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(5,'Oportunidad 13',3,7,'2017-12-12',1,1,3,'NA',2,N'NA',1,5,'Contacto 13','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(3,'Oportunidad 14',12,12,'2017-06-12',0,1,3,'NA',1,N'NA',2,3,'Contacto 14','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(5,'Oportunidad 15',11,1,'2017-07-12',0,1,3,'NA',1,N'NA',1,4,'Contacto 15','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(3,'Oportunidad 16',1,4,'2017-08-12',0,1,3,'NA',2,N'NA',1,2,'Contacto 16','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(4,'Oportunidad 17',1,1,'2017-06-12',1,1,3,'NA',2,N'NA',1,2,'Contacto 17','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(5,'Oportunidad 18',12,11,'2017-09-12',0,1,3,'NA',1,N'NA',1,2,'Contacto 18','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(6,'Oportunidad 19',13,5,'2017-09-22',1,1,3,'NA',1,N'NA',1,2,'Contacto 19','NA',1,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(3,'Oportunidad 20',12,3,'2017-10-12',0,1,3,'NA',1,N'NA',1,4,'Contacto 20','NA',2,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(3,'Oportunidad 21',12,13,'2017-06-12',0,1,4,'NA',1,N'NA',3,4,'Contacto 21','NA',2,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(4,'Oportunidad 22',11,7,'2017-08-23',0,1,3,'NA',2,N'NA',1,2,'Contacto 22','NA',2,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(2,'Oportunidad 23',12,4,'2017-11-22',1,1,1,'NA',1,N'NA',3,1,'Contacto 23','NA',1,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(1,'Oportunidad 24',12,7,'2017-07-18',0,1,2,'NA',2,N'NA',2,2,'Contacto 24','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(4,'Oportunidad 25',2,5,'2017-09-12',1,1,3,'NA',1,N'NA',2,6,'Contacto 25','NA',3,1,1)

--
INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(1,'Oportunidad 26',9,3,'2017-07-12',0,1,3,'NA',1,N'NA',1,1,'Contacto 26','NA',2,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(4,'Oportunidad 27',5,7,'2017-08-12',0,1,2,'NA',1,N'NA',3,5,'Contacto 27','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(2,'Oportunidad 28',6,8,'2017-09-12',0,1,1,'NA',1,N'NA',1,2,'Contacto 28','NA',2,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(3,'Oportunidad 29',1,1,'2017-10-12',1,1,3,'NA',1,N'NA',2,4,'Contacto 29','NA',1,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(1,'Oportunidad 30',13,13,'2017-07-12',0,1,2,'NA',2,N'NA',1,2,'Contacto 30','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(1,'Oportunidad 31',11,3,'2017-11-12',0,1,3,'NA',2,N'NA',3,1,'Contacto 31','NA',1,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(1,'Oportunidad 32',7,8,'2017-08-12',0,1,3,'NA',1,N'NA',3,2,'Contacto 32','NA',1,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(3,'Oportunidad 33',5,6,'2017-09-12',0,1,3,'NA',2,N'NA',1,2,'Contacto 1','NA',3,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(4,'Oportunidad 34',5,7,'2017-09-12',0,1,3,'NA',1,N'NA',1,2,'Contacto 34','NA',2,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(4,'Oportunidad 35',6,8,'2017-10-12',1,1,3,'NA',1,N'NA',2,5,'Contacto 35','NA',1,1,1)


INSERT INTO Cotizaciones (Departamento,NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad,Probabilidad,
						  OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura,Denegacion,ContraQuien,
						   Estado) 
VALUES(3,'Oportunidad 36',6,1,'2017-06-12',1,1,2,'NA',1,N'NA',1,1,'Contacto 1','NA',3,1,1)


--FAMILIAS DE PRODUTOS 

insert into familiaProducto values('Perecederos','Productos que se dañan si no se consumen a tiempo se dañan',1)
insert into familiaProducto values('No Perecederos','Productos que aguantan estar guardados',1)
insert into familiaProducto values('Polvos','Polvos para la contruccion de edificaciones',1)
insert into familiaProducto values('Aceros','Aceros para la contruccion de edificaciones',1)
insert into familiaProducto values('Productos de Limpieza','Productos para la limpieza de viviendas',1)
insert into familiaProducto  values('Productos de Aseo Personal','Productos exlusivos para aseo personal humano',1)
insert into familiaProducto values('Pinturas','Pinturas para casa y vehiculos',1)

--PRODUCTOS 
INSERT INTO productos values('Carnes de res',1,3400,'Kilo',1)
INSERT INTO productos values('Atunes',2,2000,'Grande',1)
INSERT INTO productos values('Cemento',3,5000,'Saco 50 Kg',1)
INSERT INTO productos values('Varilla de Acero',4,3400,' 2 pulgadas',1)
INSERT INTO productos values('Cloro',5,1200,'Bolsa de 250 Ml',1)
INSERT INTO productos values('Shampoo',6,3400,'Head And shoulders For men 3 en 1',1)
INSERT INTO productos values('Jabon de Piel',6,1200,'Paquete de 3',1)
INSERT INTO productos values('Pasta de Dientes',6,1000,'Cilindro de 200 Ml',1)
INSERT INTO productos values('Manzana',1,560,'Kilo',1)
INSERT INTO productos values('Cerveza',2,1300,'Pilsen 1 L',1)
INSERT INTO productos values('Arroz',2,1400,'Kilo Sabanero',1)
INSERT INTO productos values('Frijoles',2,2300,'Kilo Tio Pelon',1)
INSERT INTO productos values('Salchicon',1,1400,'Kilo',1)
INSERT INTO productos values('Mortadela',1,1200,'Kilo',1)
INSERT INTO productos values('Sal ',2,3400,'Kilo',1)
INSERT INTO productos values('Azucar',2,900,'Kilo',1)
INSERT INTO productos values('Café',1,5400,'Kilo 1820',1)
INSERT INTO productos values('Vinos',2,23400,'Litro ',1)
INSERT INTO productos values('Galletas',2,1400,'Galletas Mantequilla Paquete de 12 unidades',1)
INSERT INTO productos values('Cepillo de Dientes',2,1400,'Cepillo Conlgate Unidad',1)
INSERT INTO productos values('Malla de Acero',4,83400,'8 Metros de malla de acero',1)
INSERT INTO productos values('Mantequilla',1,5400,'Kilo',1)
INSERT INTO productos values('Pintura',7,13400,'Galon ',1)
INSERT INTO productos values('Martillo',4,7400,'unidad Martillo de Acero',1)
INSERT INTO productos values('Cuchillo',4,7400,'Cuchillo de cocina',1)

--PRODUCTOS POR COTIZACION
--COT(1)
INSERT INTO ProductosPorCotizacion VALUES(1,1,3)
INSERT INTO ProductosPorCotizacion VALUES(1,2,3)
INSERT INTO ProductosPorCotizacion VALUES(1,3,5)
INSERT INTO ProductosPorCotizacion VALUES(1,4,7)
INSERT INTO ProductosPorCotizacion VALUES(1,5,1)
INSERT INTO ProductosPorCotizacion VALUES(1,6,2)
INSERT INTO ProductosPorCotizacion VALUES(1,7,3)
INSERT INTO ProductosPorCotizacion VALUES(1,8,5)
INSERT INTO ProductosPorCotizacion VALUES(1,9,2)

--COT(2)
INSERT INTO ProductosPorCotizacion VALUES(2,11,3)
INSERT INTO ProductosPorCotizacion VALUES(2,22,3)
INSERT INTO ProductosPorCotizacion VALUES(2,23,5)
INSERT INTO ProductosPorCotizacion VALUES(2,4,7)
INSERT INTO ProductosPorCotizacion VALUES(2,6,1)
INSERT INTO ProductosPorCotizacion VALUES(2,16,2)
INSERT INTO ProductosPorCotizacion VALUES(2,17,3)

--COT(3)
INSERT INTO ProductosPorCotizacion VALUES(3,11,3)
INSERT INTO ProductosPorCotizacion VALUES(3,22,3)
INSERT INTO ProductosPorCotizacion VALUES(3,23,5)
INSERT INTO ProductosPorCotizacion VALUES(3,4,7)
INSERT INTO ProductosPorCotizacion VALUES(3,6,1)
INSERT INTO ProductosPorCotizacion VALUES(3,16,2)
INSERT INTO ProductosPorCotizacion VALUES(3,17,3)
INSERT INTO ProductosPorCotizacion VALUES(3,7,3)
INSERT INTO ProductosPorCotizacion VALUES(3,5,3)
INSERT INTO ProductosPorCotizacion VALUES(3,1,5)
INSERT INTO ProductosPorCotizacion VALUES(3,12,7)
INSERT INTO ProductosPorCotizacion VALUES(3,2,1)
INSERT INTO ProductosPorCotizacion VALUES(3,13,2)
INSERT INTO ProductosPorCotizacion VALUES(3,24,3)

--COT (4)
INSERT INTO ProductosPorCotizacion VALUES(4,11,3)
INSERT INTO ProductosPorCotizacion VALUES(4,22,3)
INSERT INTO ProductosPorCotizacion VALUES(4,23,5)
INSERT INTO ProductosPorCotizacion VALUES(4,4,7)
INSERT INTO ProductosPorCotizacion VALUES(4,6,1)
INSERT INTO ProductosPorCotizacion VALUES(4,16,2)
INSERT INTO ProductosPorCotizacion VALUES(4,17,3)
--COT(5)
INSERT INTO ProductosPorCotizacion VALUES(5,1,3)
INSERT INTO ProductosPorCotizacion VALUES(5,2,1)
INSERT INTO ProductosPorCotizacion VALUES(5,3,2)
INSERT INTO ProductosPorCotizacion VALUES(5,4,2)
INSERT INTO ProductosPorCotizacion VALUES(5,5,1)
INSERT INTO ProductosPorCotizacion VALUES(5,11,5)
INSERT INTO ProductosPorCotizacion VALUES(5,12,2)
INSERT INTO ProductosPorCotizacion VALUES(5,13,6)
INSERT INTO ProductosPorCotizacion VALUES(5,20,1)
INSERT INTO ProductosPorCotizacion VALUES(5,21,5)

--COT(6)
INSERT INTO ProductosPorCotizacion VALUES(6,21,3)
INSERT INTO ProductosPorCotizacion VALUES(6,22,1)
INSERT INTO ProductosPorCotizacion VALUES(6,23,2)
INSERT INTO ProductosPorCotizacion VALUES(6,4,2)
INSERT INTO ProductosPorCotizacion VALUES(6,5,1)
INSERT INTO ProductosPorCotizacion VALUES(6,1,5)
INSERT INTO ProductosPorCotizacion VALUES(6,2,2)
INSERT INTO ProductosPorCotizacion VALUES(6,16,6)
INSERT INTO ProductosPorCotizacion VALUES(6,7,1)
--COT(7)
INSERT INTO ProductosPorCotizacion VALUES(7,3,3)
INSERT INTO ProductosPorCotizacion VALUES(7,4,1)
INSERT INTO ProductosPorCotizacion VALUES(7,6,2)
INSERT INTO ProductosPorCotizacion VALUES(7,7,2)
INSERT INTO ProductosPorCotizacion VALUES(7,2,1)
INSERT INTO ProductosPorCotizacion VALUES(7,1,5)
INSERT INTO ProductosPorCotizacion VALUES(7,8,2)
--COT(8)
INSERT INTO ProductosPorCotizacion VALUES(8,25,2)
INSERT INTO ProductosPorCotizacion VALUES(8,14,6)
INSERT INTO ProductosPorCotizacion VALUES(8,16,4)
INSERT INTO ProductosPorCotizacion VALUES(8,12,5)

--COT(9)
INSERT INTO ProductosPorCotizacion VALUES(9,5,3)
INSERT INTO ProductosPorCotizacion VALUES(9,6,1)
INSERT INTO ProductosPorCotizacion VALUES(9,2,2)
INSERT INTO ProductosPorCotizacion VALUES(9,23,2)
INSERT INTO ProductosPorCotizacion VALUES(9,12,1)
INSERT INTO ProductosPorCotizacion VALUES(9,7,5)
--COT(10)
INSERT INTO ProductosPorCotizacion VALUES(10,2,3)
INSERT INTO ProductosPorCotizacion VALUES(10,5,1)
INSERT INTO ProductosPorCotizacion VALUES(10,6,2)
INSERT INTO ProductosPorCotizacion VALUES(10,7,2)
INSERT INTO ProductosPorCotizacion VALUES(10,23,1)
INSERT INTO ProductosPorCotizacion VALUES(10,8,5)
INSERT INTO ProductosPorCotizacion VALUES(10,9,3)
INSERT INTO ProductosPorCotizacion VALUES(10,12,1)
INSERT INTO ProductosPorCotizacion VALUES(10,21,2)

--COT(11)
INSERT INTO ProductosPorCotizacion VALUES(11,4,3)
INSERT INTO ProductosPorCotizacion VALUES(11,6,1)
INSERT INTO ProductosPorCotizacion VALUES(11,3,2)
INSERT INTO ProductosPorCotizacion VALUES(11,12,2)
INSERT INTO ProductosPorCotizacion VALUES(11,25,1)
INSERT INTO ProductosPorCotizacion VALUES(11,21,5)
--COT(12)
INSERT INTO ProductosPorCotizacion VALUES(12,4,3)
INSERT INTO ProductosPorCotizacion VALUES(12,7,1)
INSERT INTO ProductosPorCotizacion VALUES(12,11,2)
INSERT INTO ProductosPorCotizacion VALUES(12,17,2)
INSERT INTO ProductosPorCotizacion VALUES(12,23,1)
INSERT INTO ProductosPorCotizacion VALUES(12,8,5)
INSERT INTO ProductosPorCotizacion VALUES(12,9,3)
INSERT INTO ProductosPorCotizacion VALUES(12,12,1)

--cot(13)
INSERT INTO ProductosPorCotizacion VALUES(13,1,4)
INSERT INTO ProductosPorCotizacion VALUES(13,7,2)
INSERT INTO ProductosPorCotizacion VALUES(13,12,4)
INSERT INTO ProductosPorCotizacion VALUES(13,17,1)
INSERT INTO ProductosPorCotizacion VALUES(13,13,6)
INSERT INTO ProductosPorCotizacion VALUES(13,8,3)
INSERT INTO ProductosPorCotizacion VALUES(13,9,3)

--cot(14)
INSERT INTO ProductosPorCotizacion VALUES(14,11,4)
INSERT INTO ProductosPorCotizacion VALUES(14,17,2)
INSERT INTO ProductosPorCotizacion VALUES(14,21,4)
INSERT INTO ProductosPorCotizacion VALUES(14,25,1)
INSERT INTO ProductosPorCotizacion VALUES(14,13,6)
INSERT INTO ProductosPorCotizacion VALUES(14,2,3)
INSERT INTO ProductosPorCotizacion VALUES(14,1,3)

--COT(15)
INSERT INTO ProductosPorCotizacion VALUES(15,23,4)
INSERT INTO ProductosPorCotizacion VALUES(15,13,2)
INSERT INTO ProductosPorCotizacion VALUES(15,3,4)
INSERT INTO ProductosPorCotizacion VALUES(15,22,1)

--COT(16)
INSERT INTO ProductosPorCotizacion VALUES(16,1,3)
INSERT INTO ProductosPorCotizacion VALUES(16,2,1)
INSERT INTO ProductosPorCotizacion VALUES(16,3,2)
INSERT INTO ProductosPorCotizacion VALUES(16,4,2)
INSERT INTO ProductosPorCotizacion VALUES(16,5,1)
INSERT INTO ProductosPorCotizacion VALUES(16,6,5)
INSERT INTO ProductosPorCotizacion VALUES(16,7,3)
INSERT INTO ProductosPorCotizacion VALUES(16,8,1)

--COT(17)
INSERT INTO ProductosPorCotizacion VALUES(17,23,2)
INSERT INTO ProductosPorCotizacion VALUES(17,13,5)
INSERT INTO ProductosPorCotizacion VALUES(17,3,3)

--COT(18)
INSERT INTO ProductosPorCotizacion VALUES(18,11,3)
INSERT INTO ProductosPorCotizacion VALUES(18,22,1)
INSERT INTO ProductosPorCotizacion VALUES(18,23,2)
INSERT INTO ProductosPorCotizacion VALUES(18,14,2)
INSERT INTO ProductosPorCotizacion VALUES(18,25,1)
INSERT INTO ProductosPorCotizacion VALUES(18,16,5)
INSERT INTO ProductosPorCotizacion VALUES(18,13,3)

--COT(19)
INSERT INTO ProductosPorCotizacion VALUES(19,11,3)
INSERT INTO ProductosPorCotizacion VALUES(19,22,1)
INSERT INTO ProductosPorCotizacion VALUES(19,23,2)
INSERT INTO ProductosPorCotizacion VALUES(19,14,2)
INSERT INTO ProductosPorCotizacion VALUES(19,25,1)

--COT(20)
INSERT INTO ProductosPorCotizacion VALUES(20,11,10)
INSERT INTO ProductosPorCotizacion VALUES(20,22,12)

--COT(21)
INSERT INTO ProductosPorCotizacion VALUES(21,2,3)
INSERT INTO ProductosPorCotizacion VALUES(21,3,6)
INSERT INTO ProductosPorCotizacion VALUES(21,4,3)
INSERT INTO ProductosPorCotizacion VALUES(21,6,2)
INSERT INTO ProductosPorCotizacion VALUES(21,9,3)
INSERT INTO ProductosPorCotizacion VALUES(21,16,5)

--cot(22)
INSERT INTO ProductosPorCotizacion VALUES(22,1,3)
INSERT INTO ProductosPorCotizacion VALUES(22,2,6)
INSERT INTO ProductosPorCotizacion VALUES(22,3,3)
INSERT INTO ProductosPorCotizacion VALUES(22,4,2)
INSERT INTO ProductosPorCotizacion VALUES(22,5,3)
INSERT INTO ProductosPorCotizacion VALUES(22,6,5)
INSERT INTO ProductosPorCotizacion VALUES(22,7,3)
INSERT INTO ProductosPorCotizacion VALUES(22,8,6)
INSERT INTO ProductosPorCotizacion VALUES(22,9,3)
INSERT INTO ProductosPorCotizacion VALUES(22,10,2)
INSERT INTO ProductosPorCotizacion VALUES(22,19,3)
INSERT INTO ProductosPorCotizacion VALUES(22,16,5)

--cot(23)
INSERT INTO ProductosPorCotizacion VALUES(23,18,3)
INSERT INTO ProductosPorCotizacion VALUES(23,12,6)
INSERT INTO ProductosPorCotizacion VALUES(23,23,3)
INSERT INTO ProductosPorCotizacion VALUES(23,24,2)
INSERT INTO ProductosPorCotizacion VALUES(23,15,3)
INSERT INTO ProductosPorCotizacion VALUES(23,16,5)
INSERT INTO ProductosPorCotizacion VALUES(23,17,3)
INSERT INTO ProductosPorCotizacion VALUES(23,2,6)
INSERT INTO ProductosPorCotizacion VALUES(23,4,3)

--COT(24)
INSERT INTO ProductosPorCotizacion VALUES(24,18,3)
INSERT INTO ProductosPorCotizacion VALUES(24,12,2)
INSERT INTO ProductosPorCotizacion VALUES(24,7,1)
INSERT INTO ProductosPorCotizacion VALUES(24,2,12)
INSERT INTO ProductosPorCotizacion VALUES(24,3,3)

--COT(25)
INSERT INTO ProductosPorCotizacion VALUES(25,8,3)
INSERT INTO ProductosPorCotizacion VALUES(25,12,5)
INSERT INTO ProductosPorCotizacion VALUES(25,2,6)
INSERT INTO ProductosPorCotizacion VALUES(25,24,2)
INSERT INTO ProductosPorCotizacion VALUES(25,5,3)
INSERT INTO ProductosPorCotizacion VALUES(25,6,2)
INSERT INTO ProductosPorCotizacion VALUES(25,7,3)
INSERT INTO ProductosPorCotizacion VALUES(25,21,7)
INSERT INTO ProductosPorCotizacion VALUES(25,4,1)

--COT(26)
INSERT INTO ProductosPorCotizacion VALUES(26,3,3)
INSERT INTO ProductosPorCotizacion VALUES(26,12,6)
INSERT INTO ProductosPorCotizacion VALUES(26,25,1)
INSERT INTO ProductosPorCotizacion VALUES(26,13,2)
INSERT INTO ProductosPorCotizacion VALUES(26,15,3)
INSERT INTO ProductosPorCotizacion VALUES(26,6,1)
INSERT INTO ProductosPorCotizacion VALUES(26,7,3)

--cot(27)
INSERT INTO ProductosPorCotizacion VALUES(27,18,4)
INSERT INTO ProductosPorCotizacion VALUES(27,12,1)
INSERT INTO ProductosPorCotizacion VALUES(27,22,2)
INSERT INTO ProductosPorCotizacion VALUES(27,24,3)
INSERT INTO ProductosPorCotizacion VALUES(27,15,1)
INSERT INTO ProductosPorCotizacion VALUES(27,6,2)
INSERT INTO ProductosPorCotizacion VALUES(27,17,3)
INSERT INTO ProductosPorCotizacion VALUES(27,21,1)
INSERT INTO ProductosPorCotizacion VALUES(27,14,3)

--cot(28)
INSERT INTO ProductosPorCotizacion VALUES(28,8,4)
INSERT INTO ProductosPorCotizacion VALUES(28,1,1)
INSERT INTO ProductosPorCotizacion VALUES(28,12,2)
INSERT INTO ProductosPorCotizacion VALUES(28,25,3)
INSERT INTO ProductosPorCotizacion VALUES(28,15,1)
INSERT INTO ProductosPorCotizacion VALUES(28,6,2)

--COT(29)
INSERT INTO ProductosPorCotizacion VALUES(29,7,14)
INSERT INTO ProductosPorCotizacion VALUES(29,16,10)
INSERT INTO ProductosPorCotizacion VALUES(29,21,12)

--COT(30)
INSERT INTO ProductosPorCotizacion VALUES(30,2,6)
INSERT INTO ProductosPorCotizacion VALUES(30,12,2)
INSERT INTO ProductosPorCotizacion VALUES(30,4,3)
INSERT INTO ProductosPorCotizacion VALUES(30,15,5)
INSERT INTO ProductosPorCotizacion VALUES(30,16,2)
INSERT INTO ProductosPorCotizacion VALUES(30,7,4)
INSERT INTO ProductosPorCotizacion VALUES(30,21,1)
INSERT INTO ProductosPorCotizacion VALUES(30,14,3)

--COT(31)
INSERT INTO ProductosPorCotizacion VALUES(31,21,1)
INSERT INTO ProductosPorCotizacion VALUES(31,12,6)
INSERT INTO ProductosPorCotizacion VALUES(31,14,7)
INSERT INTO ProductosPorCotizacion VALUES(31,15,7)
INSERT INTO ProductosPorCotizacion VALUES(31,16,2)
INSERT INTO ProductosPorCotizacion VALUES(31,17,8)
INSERT INTO ProductosPorCotizacion VALUES(31,24,1)
INSERT INTO ProductosPorCotizacion VALUES(31,14,3)

--COT(32)
INSERT INTO ProductosPorCotizacion VALUES(32,3,1)
INSERT INTO ProductosPorCotizacion VALUES(32,2,6)
INSERT INTO ProductosPorCotizacion VALUES(32,7,7)
INSERT INTO ProductosPorCotizacion VALUES(32,9,7)
INSERT INTO ProductosPorCotizacion VALUES(32,16,2)
INSERT INTO ProductosPorCotizacion VALUES(32,17,2)

--COT(33)
INSERT INTO ProductosPorCotizacion VALUES(33,13,1)
INSERT INTO ProductosPorCotizacion VALUES(33,12,6)
INSERT INTO ProductosPorCotizacion VALUES(33,17,7)
INSERT INTO ProductosPorCotizacion VALUES(33,19,7)

--COT(34)
INSERT INTO ProductosPorCotizacion VALUES(34,21,6)
INSERT INTO ProductosPorCotizacion VALUES(34,15,2)
INSERT INTO ProductosPorCotizacion VALUES(34,12,4)
INSERT INTO ProductosPorCotizacion VALUES(34,11,2)
INSERT INTO ProductosPorCotizacion VALUES(34,7,3)
INSERT INTO ProductosPorCotizacion VALUES(34,2,2)
INSERT INTO ProductosPorCotizacion VALUES(34,4,5)

--COT(35)
INSERT INTO ProductosPorCotizacion VALUES(35,1,3)
INSERT INTO ProductosPorCotizacion VALUES(35,5,12)
INSERT INTO ProductosPorCotizacion VALUES(35,2,4)
INSERT INTO ProductosPorCotizacion VALUES(35,7,2)
INSERT INTO ProductosPorCotizacion VALUES(35,6,3)

--COT(36)
INSERT INTO ProductosPorCotizacion VALUES(36,12,1)
INSERT INTO ProductosPorCotizacion VALUES(36,5,2)
INSERT INTO ProductosPorCotizacion VALUES(36,2,5)
INSERT INTO ProductosPorCotizacion VALUES(36,8,12)
INSERT INTO ProductosPorCotizacion VALUES(36,6,6)
INSERT INTO ProductosPorCotizacion VALUES(36,1,7)

--COT(37)
INSERT INTO ProductosPorCotizacion VALUES(37,3,1)
INSERT INTO ProductosPorCotizacion VALUES(37,6,2)
INSERT INTO ProductosPorCotizacion VALUES(37,12,5)
INSERT INTO ProductosPorCotizacion VALUES(37,21,2)

-- COMO SE ENTERO

INSERT INTO ComoSeEntero values('Llamada',1)

--ESTADO CANDIDATO
INSERT INTO EstadoContacto VALUES('Elegible',1)


--CONTACTO CLIENTE

INSERT INTO ContactoCliente VALUES('Jordan','Araya','Empresa 1',1,1,'NA','86223950','Correo1@gmail.com',1,'Limon',1,1,'NA',1)
INSERT INTO ContactoCliente VALUES('Alfredo','Duran','Empresa 2',1,2,'NA','86223950','Correo2@gmail.com',1,'Limon',2,3,'NA',1)
INSERT INTO ContactoCliente VALUES('Darian','Horna','Empresa 3',1,3,'NA','86223950','Correo3@gmail.com',1,'Limon',3,13,'NA',1)
INSERT INTO ContactoCliente VALUES('Gabriel','Horna','Empresa 4',1,4,'NA','86223950','Correo4@gmail.com',1,'Limon',1,3,'NA',1)
INSERT INTO ContactoCliente VALUES('Jorge','Rodriguez','Empresa 5',1,3,'NA','86223950','Correo5@gmail.com',1,'Limon',1,3,'NA',1)
INSERT INTO ContactoCliente VALUES('Ernie','Rodriguez','Empresa 6',1,2,'NA','86223950','Correo6@gmail.com',1,'Limon',1,4,'NA',1)
INSERT INTO ContactoCliente VALUES('Aaron','Rubi','Empresa 7',1,4,'NA','86223950','Correo7@gmail.com',1,'Limon',1,12,'NA',1)
INSERT INTO ContactoCliente VALUES('Bryan','Rubi','Empresa 8',1,5,'NA','86223950','Correo8@gmail.com',1,'Limon',1,11,'NA',1)
INSERT INTO ContactoCliente VALUES('Josue','Rubi','Empresa 9',1,6,'NA','86223950','Correo9@gmail.com',1,'Limon',1,10,'NA',1)
INSERT INTO ContactoCliente VALUES('Andrey','Horna','Empresa 10',1,3,'NA','86223950','Correo10@gmail.com',1,'Limon',1,9,'NA',1)
INSERT INTO ContactoCliente VALUES('Luis','Araya','Empresa 11',1,4,'NA','86223950','Correo11@gmail.com',1,'Limon',1,9,'NA',1)
INSERT INTO ContactoCliente VALUES('Heiner','Salvatierra','Empresa 12',1,3,'NA','86223950','Correo12@gmail.com',1,'Limon',1,7,'NA',1)
INSERT INTO ContactoCliente VALUES('Allan','Barquero','Empresa 13',1,2,'NA','86223950','Correo13@gmail.com',1,'Limon',1,6,'NA',1)
INSERT INTO ContactoCliente VALUES('Herwin','Smith','Empresa 14',1,4,'NA','86223950','Correo14@gmail.com',1,'Limon',1,5,'NA',1)
INSERT INTO ContactoCliente VALUES('Allan','Rodriguez','Empresa 15',1,5,'NA','86223950','Correo15@gmail.com',1,'Limon',1,4,'NA',1)
INSERT INTO ContactoCliente VALUES('Rita','Aguilar','Empresa 16',1,6,'NA','86223950','Correo16@gmail.com',1,'Limon',1,3,'NA',1)
INSERT INTO ContactoCliente VALUES('Ivanka','Aguilar','Empresa 17',1,3,'NA','86223950','Correo17@gmail.com',1,'Limon',1,3,'NA',1)
INSERT INTO ContactoCliente VALUES('Iann','Castellon','Empresa 18',1,3,'NA','86223950','Correo18@gmail.com',1,'Limon',1,5,'NA',1)
INSERT INTO ContactoCliente VALUES('Angie','Copper','Empresa 19',1,3,'NA','86223950','Correo19@gmail.com',1,'Limon',1,7,'NA',1)
INSERT INTO ContactoCliente VALUES('Camila','Mayorga','Empresa 20',1,2,'NA','86223950','Correo20@gmail.com',1,'Limon',1,8,'NA',1)
INSERT INTO ContactoCliente VALUES('Mellisa','Karina','Empresa 21',1,1,'NA','86223950','Correo1@gmail.com',1,'Limon',1,12,'NA',1)
INSERT INTO ContactoCliente VALUES('Michelle','Leiton','Empresa 22',1,5,'NA','86223950','Correo1@gmail.com',1,'Limon',1,11,'NA',1)
INSERT INTO ContactoCliente VALUES('Monica','Alvarado','Empresa 23',1,6,'NA','86223950','Correo1@gmail.com',1,'Limon',1,10,'NA',1)
INSERT INTO ContactoCliente VALUES('Dani','Marchena','Empresa 24',1,4,'NA','86223950','Correo1@gmail.com',1,'Limon',1,2,'NA',1)
INSERT INTO ContactoCliente VALUES('Fernanda','Lopez','Empresa 25',1,5,'NA','86223950','Correo1@gmail.com',1,'Limon',1,4,'NA',1)
INSERT INTO ContactoCliente VALUES('Yolanda','Selva','Empresa 26',1,2,'NA','86223950','Correo1@gmail.com',1,'Limon',1,5,'NA',1)
INSERT INTO ContactoCliente VALUES('Jonathan','Corea','Empresa 27',1,5,'NA','86223950','Correo1@gmail.com',1,'Limon',1,6,'NA',1)
INSERT INTO ContactoCliente VALUES('ivet','Selva','Empresa 28',1,1,'NA','86223950','Correo1@gmail.com',1,'Limon',1,2,'NA',1)
INSERT INTO ContactoCliente VALUES('Carlos','Selva','Empresa 29',1,2,'NA','86223950','Correo1@gmail.com',1,'Limon',1,4,'NA',1)


-- PROCESO DE EJECUCION 37

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(1,1,'Propietario 1','Nombre 1',1,1,'2017-06-12',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(2,2,'Propietario 2','Nombre 2',2,2,'2017-08-22',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(3,3,'Propietario 2','Nombre 2',3,4,'2017-08-22',1)


INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(4,4,'Propietario 2','Nombre 2',5,7,'2017-10-22',1)


INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(5,5,'Propietario 5','Nombre 5',5,4,'2018-01-01',1)


INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(6,6,'Propietario 6','Nombre 6',7,12,'2017-09-01',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(3,7,'Propietario 7','Nombre 7',20,13,'2017-09-22',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(2,8,'Propietario 8','Nombre 8',12,10,'2017-11-22',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(4,9,'Propietario 9','Nombre 9',1,3,'2017-07-22',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(2,10,'Propietario 10','Nombre 10',5,6,'2017-08-08',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(3,11,'Propietario 11','Nombre 11',24,3,'2017-10-08',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(5,12,'Propietario 12','Nombre 12',17,11,'2017-11-08',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(1,13,'Propietario 12','Nombre 12',18,6,'2017-12-08',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(5,14,'Propietario 14','Nombre 14',3,7,'2017-08-12',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(3,15,'Propietario 15','Nombre 15',12,12,'2017-09-22',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(5,16,'Propietario 16','Nombre 16',11,1,'2017-09-01',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(3,17,'Propietario 17','Nombre 17',1,4,'2017-10-20',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(4,18,'Propietario 18','Nombre 18',1,1,'2017-11-20',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(5,19,'Propietario 19','Nombre 19',12,11,'2017-12-20',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(6,20,'Propietario 20','Nombre 20',13,5,'2017-07-20',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(3,21,'Propietario 21','Nombre 21',12,3,'2017-08-30',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(3,22,'Propietario 22','Nombre 22',12,13,'2017-10-30',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(4,23,'Propietario 23','Nombre 23',11,7,'2017-11-30',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(2,24,'Propietario 24','Nombre 24',12,4,'2017-10-06',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(1,25,'Propietario 25','Nombre 25',12,7,'2017-09-06',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(4,26,'Propietario 26','Nombre 26',2,5,'2017-08-18',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(1,27,'Propietario 27','Nombre 27',9,3,'2017-09-10',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(4,28,'Propietario 28','Nombre 28',5,7,'2017-11-01',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(2,29,'Propietario 29','Nombre 29',6,8,'2018-02-01',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(3,30,'Propietario 30','Nombre 30',1,1,'2018-03-01',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(1,31,'Propietario 31','Nombre 31',13,13,'2018-04-01',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(1,32,'Propietario 32','Nombre 32',11,3,'2017-06-20',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(1,33,'Propietario 33','Nombre 33',7,8,'2017-10-14',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(3,34,'Propietario 34','Nombre 34',5,6,'2017-11-14',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(4,35,'Propietario 35','Nombre 35',5,7,'2017-12-24',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(4,36,'Propietario 36','Nombre 36',6,8,'2017-12-21',1)

INSERT INTO ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre,Estado) 
	VALUES(3,37,'Propietario 37','Nombre 37',6,1,'2017-10-21',1)

--Origen de casos
INSERT INTO OrigenCaso values('Caso 1',1)
INSERT INTO OrigenCaso values('Caso 2',1)
INSERT INTO OrigenCaso values('Caso 3',1)
INSERT INTO OrigenCaso values('Caso 4',1)
INSERT INTO OrigenCaso values('Caso 5',1)

--Tipos de Casos
INSERT INTO TipoCaso VALUES('Tipo 1',1)
INSERT INTO TipoCaso VALUES('Tipo 2',1)
INSERT INTO TipoCaso VALUES('Tipo 3',1)
INSERT INTO TipoCaso VALUES('Tipo 4',1)
INSERT INTO TipoCaso VALUES('Tipo 5',1)

--PRIORIDAD 

INSERT INTO Prioridad VALUES('Baja',1)
INSERT INTO Prioridad VALUES('Media',1)
INSERT INTO Prioridad VALUES('Alta',1)

--ESTADO CASO 

INSERT INTO EstadoCaso VALUES('Estado 1',1)
INSERT INTO EstadoCaso VALUES('Estado 2',1)
INSERT INTO EstadoCaso VALUES('Estado 3',1)

--REGISTRO CASOS

INSERT INTO RegistroCasos VALUES(1,1,1,'Asunto 1','Direccion 1','Descripcion 1',1,1,1,1)
INSERT INTO RegistroCasos VALUES(4,5,23,'Asunto 2','Direccion 2','Descripcion 2',2,3,2,1)
INSERT INTO RegistroCasos VALUES(12,2,4,'Asunto 3','Direccion 3','Descripcion 3',3,2,1,1)
INSERT INTO RegistroCasos VALUES(3,2,21,'Asunto 4','Direccion 4','Descripcion 4',1,2,3,1)
INSERT INTO RegistroCasos VALUES(6,3,17,'Asunto 5','Direccion 5','Descripcion 5',2,3,1,1)
INSERT INTO RegistroCasos VALUES(7,2,11,'Asunto 6','Direccion 6','Descripcion 6',2,5,3,1)
INSERT INTO RegistroCasos VALUES(8,3,1,'Asunto 7','Direccion 7','Descripcion 7',2,4,2,1)
INSERT INTO RegistroCasos VALUES(5,2,9,'Asunto 8','Direccion 8','Descripcion 8',1,3,1,1)
INSERT INTO RegistroCasos VALUES(11,2,5,'Asunto 9','Direccion 9','Descripcion 9',3,2,1,1)
INSERT INTO RegistroCasos VALUES(10,1,24,'Asunto 10','Direccion 10','Descripcion 10',1,1,1,1)
INSERT INTO RegistroCasos VALUES(2,1,2,'Asunto,11','Direccion 11','Descripcion 11',2,3,2,1)
INSERT INTO RegistroCasos VALUES(8,4,20,'Asunto 12','Direccion 12','Descripcion 12',1,5,2,1)
INSERT INTO RegistroCasos VALUES(13,1,19,'Asunto 13','Direccion 13','Descripcion 13',3,4,3,1)
INSERT INTO RegistroCasos VALUES(1,2,18,'Asunto 14','Direccion 14','Descripcion 14',2,5,2,1)
INSERT INTO RegistroCasos VALUES(9,3,12,'Asunto 15','Direccion 15','Descripcion 15',3,1,2,1)
INSERT INTO RegistroCasos VALUES(7,2,5,'Asunto 16','Direccion 16','Descripcion 16',1,3,1,1)
INSERT INTO RegistroCasos VALUES(5,3,21,'Asunto 17','Direccion 17','Descripcion 17',2,4,3,1)
INSERT INTO RegistroCasos VALUES(3,2,15,'Asunto 18','Direccion 18','Descripcion 18',1,2,1,1)
INSERT INTO RegistroCasos VALUES(8,1,3,'Asunto 19','Direccion 19','Descripcion 19',1,1,1,1)
INSERT INTO RegistroCasos VALUES(7,2,22,'Asunto 20','Direccion 20','Descripcion 20',2,3,2,1)
INSERT INTO RegistroCasos VALUES(3,2,16,'Asunto 21','Direccion 21','Descripcion 21',1,2,1,1)
INSERT INTO RegistroCasos VALUES(7,1,9,'Asunto 22','Direccion 22','Descripcion 22',3,1,3,1)
INSERT INTO RegistroCasos VALUES(10,3,19,'Asunto 23','Direccion 23','Descripcion 23',2,5,3,1)
INSERT INTO RegistroCasos VALUES(1,1,1,'Asunto 24','Direccion 24','Descripcion 24',1,1,1,1)
INSERT INTO RegistroCasos VALUES(2,2,16,'Asunto 25','Direccion 25','Descripcion 25',2,4,1,1)
INSERT INTO RegistroCasos VALUES(3,1,17,'Asunto 26','Direccion 26','Descripcion 26',3,4,2,1)
INSERT INTO RegistroCasos VALUES(11,3,14,'Asunto 27','Direccion 27','Descripcion 27',1,2,3,1)
INSERT INTO RegistroCasos VALUES(10,2,10,'Asunto 28','Direccion 28','Descripcion 28',2,4,2,1)
INSERT INTO RegistroCasos VALUES(1,2,7,'Asunto 29','Direccion 29','Descripcion 29',2,3,2,1)
INSERT INTO RegistroCasos VALUES(7,2,17,'Asunto 30','Direccion 30','Descripcion 30',1,1,1,1)


--ASIGNAR TAREA A COTIZACION
INSERT INTO AsignarActividadCotizacion VALUES(1,1,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,1,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,1,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,1,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,1,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,1,'Activiadad 6',1)
INSERT INTO AsignarActividadCotizacion VALUES(12,1,'Activiadad 7',1)
INSERT INTO AsignarActividadCotizacion VALUES(13,1,'Activiadad 8',1)
INSERT INTO AsignarActividadCotizacion VALUES(10,1,'Activiadad 9',1)
INSERT INTO AsignarActividadCotizacion VALUES(11,1,'Activiadad 10',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,2,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,2,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,2,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,2,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,2,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,2,'Activiadad 6',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,3,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,3,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,3,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,3,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,3,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,3,'Activiadad 6',1)
INSERT INTO AsignarActividadCotizacion VALUES(12,3,'Activiadad 7',1)
INSERT INTO AsignarActividadCotizacion VALUES(13,3,'Activiadad 8',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,4,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,4,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,4,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,4,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,5,'Activiadad 1',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,6,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,6,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,6,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,6,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,6,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,6,'Activiadad 6',1)
INSERT INTO AsignarActividadCotizacion VALUES(12,6,'Activiadad 7',1)
INSERT INTO AsignarActividadCotizacion VALUES(13,6,'Activiadad 8',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,7,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,7,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,7,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,7,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,7,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,7,'Activiadad 6',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,8,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,8,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,8,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,8,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,8,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,8,'Activiadad 6',1)
INSERT INTO AsignarActividadCotizacion VALUES(12,8,'Activiadad 7',1)
INSERT INTO AsignarActividadCotizacion VALUES(13,8,'Activiadad 8',1)
INSERT INTO AsignarActividadCotizacion VALUES(1,8,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,8,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,8,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,8,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,8,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,8,'Activiadad 6',1)
INSERT INTO AsignarActividadCotizacion VALUES(12,8,'Activiadad 7',1)
INSERT INTO AsignarActividadCotizacion VALUES(13,8,'Activiadad 8',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,9,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,9,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,9,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,9,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,9,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,9,'Activiadad 6',1)
INSERT INTO AsignarActividadCotizacion VALUES(12,9,'Activiadad 7',1)
INSERT INTO AsignarActividadCotizacion VALUES(13,9,'Activiadad 8',1)
INSERT INTO AsignarActividadCotizacion VALUES(1,9,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,9,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,9,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,9,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,9,'Activiadad 5',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,10,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,10,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,10,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,10,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,10,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,10,'Activiadad 6',1)
INSERT INTO AsignarActividadCotizacion VALUES(12,10,'Activiadad 7',1)
INSERT INTO AsignarActividadCotizacion VALUES(13,10,'Activiadad 8',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,11,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,11,'Activiadad 2',1)


INSERT INTO AsignarActividadCotizacion VALUES(1,12,'Activiadad 1',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,13,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,13,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,13,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,13,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,13,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,13,'Activiadad 6',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,14,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,14,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,14,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,14,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,15,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,15,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,15,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,15,'Activiadad 4',1)
INSERT INTO AsignarActividadCotizacion VALUES(7,15,'Activiadad 5',1)
INSERT INTO AsignarActividadCotizacion VALUES(2,15,'Activiadad 6',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,16,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,16,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,16,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,16,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(5,17,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(5,18,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(5,19,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(5,20,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(5,21,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(5,22,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,23,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,23,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,23,'Activiadad 3',1)

INSERT INTO AsignarActividadCotizacion VALUES(5,24,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,25,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,25,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,25,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,25,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,26,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,26,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,26,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,26,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,27,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,27,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,27,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,27,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,28,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,28,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,28,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,28,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,29,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,29,'Activiadad 2',1)
INSERT INTO AsignarActividadCotizacion VALUES(4,29,'Activiadad 3',1)
INSERT INTO AsignarActividadCotizacion VALUES(5,29,'Activiadad 4',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,30,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,30,'Activiadad 2',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,31,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,31,'Activiadad 2',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,32,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,32,'Activiadad 2',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,33,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,33,'Activiadad 2',1)

INSERT INTO AsignarActividadCotizacion VALUES(1,34,'Activiadad 1',1)
INSERT INTO AsignarActividadCotizacion VALUES(3,34,'Activiadad 2',1)

INSERT INTO AsignarActividadCotizacion VALUES(3,35,'Activiadad 2',1)

INSERT INTO AsignarActividadCotizacion VALUES(3,36,'Activiadad 2',1)

INSERT INTO AsignarActividadCotizacion VALUES(3,37,'Activiadad 2',1)

--ASIGNAR TAREA A COTIZACIONES 

INSERT INTO AsignarTareaCotizacion VALUES(1,1,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,1,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,1,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,1,'Activiadad 4',1)
INSERT INTO AsignarTareaCotizacion VALUES(7,1,'Activiadad 5',1)
INSERT INTO AsignarTareaCotizacion VALUES(13,1,'Activiadad 8',1)
INSERT INTO AsignarTareaCotizacion VALUES(10,1,'Activiadad 9',1)
INSERT INTO AsignarTareaCotizacion VALUES(11,1,'Activiadad 10',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,2,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,2,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,2,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(7,2,'Activiadad 5',1)
INSERT INTO AsignarTareaCotizacion VALUES(2,2,'Activiadad 6',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,3,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,3,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,3,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,3,'Activiadad 4',1)
INSERT INTO AsignarTareaCotizacion VALUES(13,3,'Activiadad 8',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,4,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,4,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,4,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,4,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,5,'Activiadad 1',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,6,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,6,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,6,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,6,'Activiadad 4',1)
INSERT INTO AsignarTareaCotizacion VALUES(7,6,'Activiadad 5',1)
INSERT INTO AsignarTareaCotizacion VALUES(13,6,'Activiadad 8',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,7,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,7,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(2,7,'Activiadad 6',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,8,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,8,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,8,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,8,'Activiadad 4',1)
INSERT INTO AsignarTareaCotizacion VALUES(7,8,'Activiadad 5',1)
INSERT INTO AsignarTareaCotizacion VALUES(2,8,'Activiadad 6',1)
INSERT INTO AsignarTareaCotizacion VALUES(12,8,'Activiadad 7',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,8,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,8,'Activiadad 4',1)


INSERT INTO AsignarTareaCotizacion VALUES(1,9,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,9,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,9,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,9,'Activiadad 4',1)
INSERT INTO AsignarTareaCotizacion VALUES(7,9,'Activiadad 5',1)
INSERT INTO AsignarTareaCotizacion VALUES(2,9,'Activiadad 6',1)
INSERT INTO AsignarTareaCotizacion VALUES(12,9,'Activiadad 7',1)



INSERT INTO AsignarTareaCotizacion VALUES(1,10,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,10,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,10,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,10,'Activiadad 4',1)
INSERT INTO AsignarTareaCotizacion VALUES(7,10,'Activiadad 5',1)


INSERT INTO AsignarTareaCotizacion VALUES(1,11,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,11,'Activiadad 2',1)


INSERT INTO AsignarTareaCotizacion VALUES(1,12,'Activiadad 1',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,13,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,13,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,13,'Activiadad 3',1)


INSERT INTO AsignarTareaCotizacion VALUES(1,14,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,14,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,14,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,14,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,15,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,15,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,15,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,15,'Activiadad 4',1)
INSERT INTO AsignarTareaCotizacion VALUES(7,15,'Activiadad 5',1)
INSERT INTO AsignarTareaCotizacion VALUES(2,15,'Activiadad 6',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,16,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,16,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,16,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,16,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(5,17,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(5,18,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(5,19,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(5,20,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(5,21,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(5,22,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,23,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,23,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,23,'Activiadad 3',1)

INSERT INTO AsignarTareaCotizacion VALUES(5,24,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,25,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,25,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,25,'Activiadad 3',1)


INSERT INTO AsignarTareaCotizacion VALUES(1,26,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,26,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,26,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,26,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,27,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,27,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,27,'Activiadad 3',1)


INSERT INTO AsignarTareaCotizacion VALUES(1,28,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,28,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,28,'Activiadad 3',1)


INSERT INTO AsignarTareaCotizacion VALUES(1,29,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,29,'Activiadad 2',1)
INSERT INTO AsignarTareaCotizacion VALUES(4,29,'Activiadad 3',1)
INSERT INTO AsignarTareaCotizacion VALUES(5,29,'Activiadad 4',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,30,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,30,'Activiadad 2',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,31,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,31,'Activiadad 2',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,32,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,32,'Activiadad 2',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,33,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,33,'Activiadad 2',1)

INSERT INTO AsignarTareaCotizacion VALUES(1,34,'Activiadad 1',1)
INSERT INTO AsignarTareaCotizacion VALUES(3,34,'Activiadad 2',1)

INSERT INTO AsignarTareaCotizacion VALUES(3,35,'Activiadad 2',1)

INSERT INTO AsignarTareaCotizacion VALUES(3,36,'Activiadad 2',1)

INSERT INTO AsignarTareaCotizacion VALUES(3,37,'Activiadad 2',1)

--asignar tarea a proceso 

INSERT INTO AsignarTareaProceso VALUES(1,1,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,1,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,1,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,1,'Activiadad 4',1)
INSERT INTO AsignarTareaProceso VALUES(7,1,'Activiadad 5',1)


INSERT INTO AsignarTareaProceso VALUES(1,2,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,2,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,2,'Activiadad 3',1)


INSERT INTO AsignarTareaProceso VALUES(1,3,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,3,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,3,'Activiadad 3',1)
 

INSERT INTO AsignarTareaProceso VALUES(1,4,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,4,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,4,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,4,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(1,5,'Activiadad 1',1)

INSERT INTO AsignarTareaProceso VALUES(1,6,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,6,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,6,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,6,'Activiadad 4',1)


INSERT INTO AsignarTareaProceso VALUES(1,7,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,7,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(2,7,'Activiadad 6',1)

INSERT INTO AsignarTareaProceso VALUES(1,8,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,8,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,8,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,8,'Activiadad 4',1)



INSERT INTO AsignarTareaProceso VALUES(1,9,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,9,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,9,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,9,'Activiadad 4',1)
INSERT INTO AsignarTareaProceso VALUES(7,9,'Activiadad 5',1)
INSERT INTO AsignarTareaProceso VALUES(2,9,'Activiadad 6',1)
INSERT INTO AsignarTareaProceso VALUES(12,9,'Activiadad 7',1)



INSERT INTO AsignarTareaProceso VALUES(1,10,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,10,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,10,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,10,'Activiadad 4',1)
INSERT INTO AsignarTareaProceso VALUES(7,10,'Activiadad 5',1)


INSERT INTO AsignarTareaProceso VALUES(1,11,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,11,'Activiadad 2',1)


INSERT INTO AsignarTareaProceso VALUES(1,12,'Activiadad 1',1)

INSERT INTO AsignarTareaProceso VALUES(1,13,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,13,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,13,'Activiadad 3',1)


INSERT INTO AsignarTareaProceso VALUES(1,14,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,14,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,14,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,14,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(1,15,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,15,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,15,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,15,'Activiadad 4',1)
INSERT INTO AsignarTareaProceso VALUES(7,15,'Activiadad 5',1)
INSERT INTO AsignarTareaProceso VALUES(2,15,'Activiadad 6',1)

INSERT INTO AsignarTareaProceso VALUES(1,16,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,16,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,16,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,16,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(5,17,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(5,18,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(5,19,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(5,20,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(5,21,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(5,22,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(1,23,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,23,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,23,'Activiadad 3',1)

INSERT INTO AsignarTareaProceso VALUES(5,24,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(1,25,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,25,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,25,'Activiadad 3',1)


INSERT INTO AsignarTareaProceso VALUES(1,26,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,26,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,26,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,26,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(1,27,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,27,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,27,'Activiadad 3',1)


INSERT INTO AsignarTareaProceso VALUES(1,28,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,28,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,28,'Activiadad 3',1)


INSERT INTO AsignarTareaProceso VALUES(1,29,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,29,'Activiadad 2',1)
INSERT INTO AsignarTareaProceso VALUES(4,29,'Activiadad 3',1)
INSERT INTO AsignarTareaProceso VALUES(5,29,'Activiadad 4',1)

INSERT INTO AsignarTareaProceso VALUES(1,30,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,30,'Activiadad 2',1)

INSERT INTO AsignarTareaProceso VALUES(1,31,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,31,'Activiadad 2',1)

INSERT INTO AsignarTareaProceso VALUES(1,32,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,32,'Activiadad 2',1)

INSERT INTO AsignarTareaProceso VALUES(1,33,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,33,'Activiadad 2',1)

INSERT INTO AsignarTareaProceso VALUES(1,34,'Activiadad 1',1)
INSERT INTO AsignarTareaProceso VALUES(3,34,'Activiadad 2',1)

INSERT INTO AsignarTareaProceso VALUES(3,35,'Activiadad 2',1)

INSERT INTO AsignarTareaProceso VALUES(3,36,'Activiadad 2',1)

INSERT INTO AsignarTareaProceso VALUES(3,37,'Activiadad 2',1)

--ASIGNAR TAREA A CLIENTE

INSERT INTO AsignarTareaCliente VALUES(1,1,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,1,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,1,'Activiadad 3',1)
INSERT INTO AsignarTareaCliente VALUES(5,1,'Activiadad 4',1)
INSERT INTO AsignarTareaCliente VALUES(7,1,'Activiadad 5',1)


INSERT INTO AsignarTareaCliente VALUES(1,2,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,2,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,2,'Activiadad 3',1)


INSERT INTO AsignarTareaCliente VALUES(1,3,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,3,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,3,'Activiadad 3',1)
 

INSERT INTO AsignarTareaCliente VALUES(1,4,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,4,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,4,'Activiadad 3',1)
INSERT INTO AsignarTareaCliente VALUES(5,4,'Activiadad 4',1)

INSERT INTO AsignarTareaCliente VALUES(1,5,'Activiadad 1',1)

INSERT INTO AsignarTareaCliente VALUES(1,6,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,6,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,6,'Activiadad 3',1)
INSERT INTO AsignarTareaCliente VALUES(5,6,'Activiadad 4',1)


INSERT INTO AsignarTareaCliente VALUES(1,7,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,7,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(2,7,'Activiadad 6',1)

INSERT INTO AsignarTareaCliente VALUES(1,8,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,8,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,8,'Activiadad 3',1)
INSERT INTO AsignarTareaCliente VALUES(5,8,'Activiadad 4',1)



INSERT INTO AsignarTareaCliente VALUES(1,9,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,9,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,9,'Activiadad 3',1)
INSERT INTO AsignarTareaCliente VALUES(5,9,'Activiadad 4',1)
INSERT INTO AsignarTareaCliente VALUES(7,9,'Activiadad 5',1)
INSERT INTO AsignarTareaCliente VALUES(2,9,'Activiadad 6',1)
INSERT INTO AsignarTareaCliente VALUES(12,9,'Activiadad 7',1)



INSERT INTO AsignarTareaCliente VALUES(1,10,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,10,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,10,'Activiadad 3',1)
INSERT INTO AsignarTareaCliente VALUES(5,10,'Activiadad 4',1)
INSERT INTO AsignarTareaCliente VALUES(7,10,'Activiadad 5',1)


INSERT INTO AsignarTareaCliente VALUES(1,11,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,11,'Activiadad 2',1)


INSERT INTO AsignarTareaCliente VALUES(1,12,'Activiadad 1',1)

INSERT INTO AsignarTareaCliente VALUES(1,13,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,13,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,13,'Activiadad 3',1)


INSERT INTO AsignarTareaCliente VALUES(1,14,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,14,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,14,'Activiadad 3',1)
INSERT INTO AsignarTareaCliente VALUES(5,14,'Activiadad 4',1)

INSERT INTO AsignarTareaCliente VALUES(1,15,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,15,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,15,'Activiadad 3',1)
INSERT INTO AsignarTareaCliente VALUES(5,15,'Activiadad 4',1)
INSERT INTO AsignarTareaCliente VALUES(7,15,'Activiadad 5',1)
INSERT INTO AsignarTareaCliente VALUES(2,15,'Activiadad 6',1)

INSERT INTO AsignarTareaCliente VALUES(1,16,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,16,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,16,'Activiadad 3',1)
INSERT INTO AsignarTareaCliente VALUES(5,16,'Activiadad 4',1)

INSERT INTO AsignarTareaCliente VALUES(5,17,'Activiadad 4',1)

INSERT INTO AsignarTareaCliente VALUES(5,18,'Activiadad 4',1)

INSERT INTO AsignarTareaCliente VALUES(5,19,'Activiadad 4',1)

INSERT INTO AsignarTareaCliente VALUES(5,20,'Activiadad 4',1)

INSERT INTO AsignarTareaCliente VALUES(5,21,'Activiadad 4',1)

INSERT INTO AsignarTareaCliente VALUES(5,22,'Activiadad 4',1)

INSERT INTO AsignarTareaCliente VALUES(1,23,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,23,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,23,'Activiadad 3',1)

INSERT INTO AsignarTareaCliente VALUES(5,24,'Activiadad 4',1)

INSERT INTO AsignarTareaCliente VALUES(1,25,'Activiadad 1',1)
INSERT INTO AsignarTareaCliente VALUES(3,25,'Activiadad 2',1)
INSERT INTO AsignarTareaCliente VALUES(4,25,'Activiadad 3',1)


--ASIGNATAR TAREA A A CASOS

INSERT INTO AsignarTareaCaso VALUES(1,1,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,1,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,1,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,1,'Activiadad 4',1)
INSERT INTO AsignarTareaCaso VALUES(7,1,'Activiadad 5',1)


INSERT INTO AsignarTareaCaso VALUES(1,2,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,2,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,2,'Activiadad 3',1)


INSERT INTO AsignarTareaCaso VALUES(1,3,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,3,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,3,'Activiadad 3',1)
 

INSERT INTO AsignarTareaCaso VALUES(1,4,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,4,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,4,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,4,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(1,5,'Activiadad 1',1)

INSERT INTO AsignarTareaCaso VALUES(1,6,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,6,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,6,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,6,'Activiadad 4',1)


INSERT INTO AsignarTareaCaso VALUES(1,7,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,7,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(2,7,'Activiadad 6',1)

INSERT INTO AsignarTareaCaso VALUES(1,8,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,8,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,8,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,8,'Activiadad 4',1)



INSERT INTO AsignarTareaCaso VALUES(1,9,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,9,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,9,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,9,'Activiadad 4',1)
INSERT INTO AsignarTareaCaso VALUES(7,9,'Activiadad 5',1)
INSERT INTO AsignarTareaCaso VALUES(2,9,'Activiadad 6',1)
INSERT INTO AsignarTareaCaso VALUES(12,9,'Activiadad 7',1)



INSERT INTO AsignarTareaCaso VALUES(1,10,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,10,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,10,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,10,'Activiadad 4',1)
INSERT INTO AsignarTareaCaso VALUES(7,10,'Activiadad 5',1)


INSERT INTO AsignarTareaCaso VALUES(1,11,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,11,'Activiadad 2',1)


INSERT INTO AsignarTareaCaso VALUES(1,12,'Activiadad 1',1)

INSERT INTO AsignarTareaCaso VALUES(1,13,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,13,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,13,'Activiadad 3',1)


INSERT INTO AsignarTareaCaso VALUES(1,14,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,14,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,14,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,14,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(1,15,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,15,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,15,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,15,'Activiadad 4',1)
INSERT INTO AsignarTareaCaso VALUES(7,15,'Activiadad 5',1)
INSERT INTO AsignarTareaCaso VALUES(2,15,'Activiadad 6',1)

INSERT INTO AsignarTareaCaso VALUES(1,16,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,16,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,16,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,16,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(5,17,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(5,18,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(5,19,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(5,20,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(5,21,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(5,22,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(1,23,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,23,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,23,'Activiadad 3',1)

INSERT INTO AsignarTareaCaso VALUES(5,24,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(1,25,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,25,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,25,'Activiadad 3',1)


INSERT INTO AsignarTareaCaso VALUES(1,26,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,26,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,26,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,26,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(1,27,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,27,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,27,'Activiadad 3',1)


INSERT INTO AsignarTareaCaso VALUES(1,28,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,28,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,28,'Activiadad 3',1)


INSERT INTO AsignarTareaCaso VALUES(1,29,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,29,'Activiadad 2',1)
INSERT INTO AsignarTareaCaso VALUES(4,29,'Activiadad 3',1)
INSERT INTO AsignarTareaCaso VALUES(5,29,'Activiadad 4',1)

INSERT INTO AsignarTareaCaso VALUES(1,30,'Activiadad 1',1)
INSERT INTO AsignarTareaCaso VALUES(3,30,'Activiadad 2',1)