create schema bd_tallermecanico
## TABLA CLIENTE ##

use bd_tallermecanico

CREATE TABLE clientes
 (
  CedulaCliente varchar(64) NOT NULL,
  NombreCliente varchar(64) NOT NULL,
  Apellido1Cliente varchar(64) NOT NULL,
  Apellido2Cliente varchar(64) NOT NULL,
  DireccionCliente varchar(512) NOT NULL,
  TelefonoCliente varchar(16) NOT NULL,
  PRIMARY KEY (CedulaCliente)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf16;

## TABLA VEHICULOS ##

CREATE TABLE vehiculo 
 (
  MatriculaVehiculo varchar(16) NOT NULL,
  MarcaVehiculo varchar(64) not null,
  ModeloVehiculo varchar(64) NOT NULL,
  ColorVehiculo varchar(64) NOT NULL,
  FechaEntrada timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  CedulaCliente varchar(64) NOT NULL,
  PRIMARY KEY (MatriculaVehiculo),
  FOREIGN KEY (CedulaCliente) REFERENCES clientes (CedulaCliente) ON DELETE RESTRICT ON UPDATE CASCADE
  ) ENGINE=InnoDB DEFAULT CHARSET=utf16;

#TABLA MECANICOS #

CREATE TABLE mecanicos
 (
  CedulaMecanico varchar(16) NOT NULL,
  NombreMecanico varchar(128) NOT NULL,
  PRIMARY KEY (CedulaMecanico)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf16;

## TABLA REPUESTOS ##

CREATE TABLE repuestos
 (
  IdRepuesto INT AUTO_INCREMENT NOT NULL,
  NombreRepuesto varchar(128) NOT NULL,
  PrecioRepuesto decimal(10,1) NOT NULL,
  PRIMARY KEY (IdRepuesto)
  ) ENGINE=InnoDB DEFAULT CHARSET=utf16;

##TABLA REPARACIONES ##

CREATE TABLE reparacion
 (
  idReparacion int AUTO_INCREMENT NOT NULL,
  CedulaMecanico varchar(16) DEFAULT NULL,
  Matricula varchar(12) NOT NULL,
  FechaEntrega timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  EstadoReparacion bit(1) NOT NULL,
  PRIMARY KEY (idReparacion),
  FOREIGN KEY (Matricula) REFERENCES vehiculo (MatriculaVehiculo) ON DELETE RESTRICT ON UPDATE CASCADE,
  FOREIGN KEY (CedulaMecanico) REFERENCES mecanicos (CedulaMecanico) ON DELETE RESTRICT ON UPDATE CASCADE
  ) ENGINE=InnoDB DEFAULT CHARSET=utf16;

## TABLA REPUESTOS POR REPARACION#

CREATE TABLE repuestosreparacion
 (
  IdReparacion int NOT NULL,
  idRepuestos int NOT NULL,
  Cantidad int NOT NULL,
  ManoObra decimal(10,1) NOT NULL,
  FOREIGN KEY (IdReparacion) REFERENCES reparacion (idReparacion) ON DELETE RESTRICT ON UPDATE CASCADE,
  FOREIGN KEY (idRepuestos) REFERENCES repuestos (IdRepuesto) ON DELETE RESTRICT ON UPDATE CASCADE
  ) ENGINE=InnoDB DEFAULT CHARSET=utf16;

CREATE TABLE mecanicoreparacion
 (
   IdMecanico varchar(16) NOT NULL,
   idReparacion int NOT NULL,
   FOREIGN KEY (IdMecanico) REFERENCES mecanicos (CedulaMecanico) ON DELETE RESTRICT ON UPDATE CASCADE,
   FOREIGN KEY (idReparacion) REFERENCES reparacion (idReparacion) ON DELETE RESTRICT ON UPDATE CASCADE,
   PRIMARY KEY(idReparacion,IdMecanico)
   ) ENGINE=InnoDB DEFAULT CHARSET=utf16;

CREATE TABLE facturas
 (
  NumeroFactura int AUTO_INCREMENT NOT NULL,
  FechaFactura timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  IdReparacion int NOT NULL,
  CedulaCliente varchar(16) NOT NULL,
  Moneda varchar(3) NOT NULL,
  TipoCambio decimal(10,1) NOT NULL,
  SubTotal decimal(10,1) NOT NULL,
  Impuesto int NOT NULL DEFAULT 13,
  Descuento int(11) NOT NULL,
  Total decimal(10,1) NOT NULL,
  PRIMARY KEY (NumeroFactura),
  FOREIGN KEY (IdReparacion) REFERENCES reparacion (idReparacion) ON DELETE RESTRICT ON UPDATE CASCADE,
  FOREIGN KEY (CedulaCliente) REFERENCES clientes (CedulaCliente) ON DELETE RESTRICT ON UPDATE CASCADE
  ) ENGINE=InnoDB DEFAULT CHARSET=utf16;



### PROCEDIMIENTO ALMACENADO = P.A ###

##P.A PARA AGREGAR UN CLIENTE#

DELIMITER $
CREATE PROCEDURE AgregarCliente(in ced VARCHAR(128),in nom varchar(128),
								in ape1 varchar(128),in ape2 varchar(128),
								in dir varchar(512),in tel varchar(64))
BEGIN
	INSERT INTO clientes (CedulaCliente,NombreCliente,Apellido1Cliente,Apellido2Cliente,
						  DireccionCliente,TelefonoCliente)
		   VALUES(ced,nom,ape1,ape2,dir,tel);
END$

#P.A PARA AGREGAR UN VEHICULO #

DELIMITER $
CREATE PROCEDURE AgregarVehiculo(in placa varchar(63),in marca varchar(64),in modelo varchar(64),
									in color varchar(64), in ced varchar(64))
									
BEGIN
	INSERT INTO vehiculo (MatriculaVehiculo,MarcaVehiculo,ModeloVehiculo,ColorVehiculo,CedulaCliente)
		   VALUES (placa,marca,modelo,color,ced);
END $

#P.A PARA AGREGAR REPUESTOS #

DELIMITER $
CREATE PROCEDURE  AgregarRepuesto(in NomRep varchar(128),in precio decimal(10,1))
BEGIN
	INSERT INTO repuestos (NombreRepuesto,PrecioRepuesto) 
		    VALUES (NomRep,precio);
            
END $
#P.A PARA AGREGAR UNA REPARACION #

DELIMITER $
CREATE PROCEDURE AgregarReparacion(in CedMc varchar(64), in placa varchar(64),in estado bit)
BEGIN
	INSERT INTO reparacion (CedulaMecanico,Matricula,EstadoReparacion)
		   VALUES(CedMc,placa,estado);
END $

#P.A PARA AGREGAR UN MECANICO#
DELIMITER $
CREATE PROCEDURE AgregarMecanico(in CedMc varchar(64),in NomMc varchar(128))
BEGIN
	INSERT INTO mecanicos (CedulaMecanico,Nombremecanico)
			VALUES(CedMc,NomMc);
END $

#P.A PARA AGREGAR MECANICOS A UNA REPARACION 

DELIMITER $
CREATE PROCEDURE MecanicosEnReparaciones(in IDMec varchar(64),in IDRep int )
BEGIN
	INSERT INTO mecanicoreparacion (IdMecanico,idReparacion)
		   VALUES (IDMec,IDRep);
END $

#P.A PARA AGREGAR UNA FACTURA# 

DELIMITER $
CREATE PROCEDURE AgregarFactura (in IDRep int, in divisa varchar(64),in TC decimal(10,1),in rebajo int)

begin 
	INSERT INTO facturas (IdReparacion,CedulaCliente,Moneda,TipoCambio,SubTotal,Impuesto,Descuento,total)
		VALUES(IDRep,(SELECT Cedula FROM vercedulacliente where idReparacion = IDRep),divisa,TC,
		        (SELECT TotalFinal FROM TotalFactura where idreparacion = IDRep),
                13,rebajo,SubTotal+(SubTotal*0.13)-((SubTotal+(SubTotal*0.13))*(Descuento/100)));
end $



#VISTA PARA SACAR LA CEDULA DEL CLIENTE POR MEDIO DE LA REPARACION#

CREATE VIEW VerCedulaCliente
	AS
		SELECT C.cedulaCliente as Cedula, R.idReparacion FROM reparacion as R 
			inner join vehiculo as V on R.Matricula =V.MatriculaVehiculo 
			inner join clientes as C on V.CedulaCliente = C.CedulaCliente

#VISTA PARA SACAR EL TOTAL DE UNA FACTURA EN CRC#

CREATE VIEW TotalFactura
	AS
		SELECT SUM((R.PrecioRepuesto *Re.Cantidad)+RE.ManoObra) as TotalFinal, RE.IdReparacion FROM repuestos as R 
			inner join repuestosreparacion as RE on R.IdRepuesto = RE.idRepuestos
            group by RE.idreparacion;

## VISTA PARA VER EL NOMBRE COMPLETO DE UN CLIENTE##

CREATE VIEW informacioncliente
 AS 
  select concat_ws(' ',NombreCliente,Apellido1Cliente,Apellido2Cliente) AS Dueño,CedulaCliente,
		TelefonoCliente,DireccionCliente 
		from clientes ;
        
##VISTA PARA VER TODOS LOS VEHICULOS QUE HAN SIDO REPARADOS ##
        
CREATE VIEW datosVehiculo
	as
		SELECT V.MatriculaVehiculo,V.MarcaVehiculo,V.ModeloVehiculo,I.Dueño FROM vehiculo AS V 
			INNER JOIN informacioncliente AS I ON V.CedulaCliente = I.CedulaCliente
			INNER JOIN reparacion AS R ON R.Matricula = V.MatriculaVehiculo;
            
##VISTA PARA VER LOS REPUESTOS QUE HAN SIDO USANDOS Y CUANTAS VECES ## 
  
CREATE VIEW RepuestosUtilizados
	as
		SELECT IdRepuesto, NombreRepuesto, PrecioRepuesto, cantidadUsado
        FROM (SELECT R.IdRepuesto,R.NombreRepuesto,R.PrecioRepuesto, 
					 (SELECT SUM(RR.cantidad) 
					  FROM repuestosreparacion as RR 
					  WHERE RR.idRepuestos =R.IdRepuesto) AS cantidadUsado
			   FROM repuestos AS R) AS TEMP
		WHERE cantidadUsado>=1 

#VISTA PARA VER LOS MECANICOS EN REPARACIONES

CREATE VIEW MecanicosEnReparaciones

AS
	SELECT MR.idReparacion,M.CedulaMecanico, M.NombreMecanico,R.EstadoReparacion
    FROM mecanicoreparacion as MR INNER JOIN mecanicos as M on MR.IdMecanico = M.CedulaMecanico 
    INNER JOIN reparacion AS R ON R.idreparacion = MR.idReparacion

#VISTA PARA VER LOS REPUESTOS POR REPARACION # 

CREATE VIEW RepuestosEnReparaciones

AS
	SELECT RE.IdReparacion,R.IdRepuesto,R.NombreRepuesto,R.PrecioRepuesto 
		FROM repuestos as R INNER JOIN repuestosreparacion AS RR on RR.IdRepuestos = R.IdRepuesto 
        INNER JOIN reparacion AS RE on RR.IdReparacion = RE.IdReparacion
    

#VISTA PARA VER TODOS LOS DATOS DE UNA FACTURA 

CREATE VIEW Facturacion
	AS
		SELECT
			F.NumeroFactura AS FcNumero,
			F.FechaFactura AS FcFecha,
			F.IdReparacion AS FcIDReparacion,
            M.NombreMecanico as MeNombre,
            M.CedulaMecanico as MeCedula,
			F.CedulaCliente AS FcCedulaCliente,
			I.Dueño AS IfNombreCompleto,
            V.MatriculaVehiculo AS VeMatricula,
            V.MarcaVehiculo as VeMarca,
            V.ModeloVehiculo AS VeModelo,
			RE.IdRepuesto AS ReID,
			RE.NombreRepuesto AS ReNomnre,
			RR.Cantidad AS RrCantidad,
            F.Moneda AS FcMoneda,
            F.TipoCambio AS FcTC,
			CASE WHEN F.Moneda='USD' THEN CAST(RE.PrecioRepuesto/f.TipoCambio AS DECIMAL(10,2)) 
				ELSE Re.PrecioRepuesto END AS RePrecio,
			CASE WHEN F.Moneda='USD' THEN CAST(RR.ManoObra/f.TipoCambio AS DECIMAL(10,2)) 
				ELSE RR.ManoObra END AS RrManoObra,
            CASE WHEN F.Moneda ='USD' THEN CAST(F.SubTotal*(F.Impuesto/100) AS DECIMAL(10,1)) 
				ELSE CAST((F.SubTotal*(F.Impuesto/100)) AS DECIMAL(10,1))  END  AS ImpuestoCRC,
            CASE WHEN F.Moneda = 'CRC' THEN CAST((F.SubTotal*(F.Impuesto/100))/F.TipoCambio AS DECIMAL(10,1)) 
				ELSE CAST((F.SubTotal*(F.Impuesto/100))/F.TipoCambio AS DECIMAL(10,1))   END AS ImpuestoUSD,
            
            CASE WHEN F.Moneda ='USD' THEN CAST(((SubTotal+(SubTotal*0.13))*(F.Descuento/100)) AS DECIMAL(10,1))
				ELSE CAST(((SubTotal+(SubTotal*0.13))*(F.Descuento/100)) AS DECIMAL(10,1))  END AS DescuendoCRC,
            
            CASE WHEN F.Moneda = 'CRC' THEN CAST(((SubTotal+(SubTotal*0.13))*(F.Descuento/100))/F.TipoCambio AS DECIMAL(10,1))  
				ELSE  CAST( ((SubTotal+(SubTotal*0.13))*(F.Descuento/100))/F.TipoCambio AS DECIMAL(10,1))  END AS DescuentoUSD,
            
            CASE WHEN F.Moneda ='USD' THEN F.SubTotal 
				ELSE F.SubTotal END AS SubTotalColones,
			CASE WHEN F.Moneda ='CRC' THEN cast((F.SubTotal/F.TipoCambio) as decimal(10,2)) 
				ELSE cast((F.SubTotal/F.TipoCambio) as decimal(10,2)) END AS SubTotalDolares,
			CASE WHEN F.Moneda ='USD' THEN F.Total  
				ELSE F.Total END AS TotalColones,
			CASE WHEN F.Moneda ='CRC' THEN CAST(F.Total/f.TipoCambio AS DECIMAL(10,2)) 
				ELSE CAST(F.Total/f.TipoCambio AS DECIMAL(10,2)) END  AS TotalDolares
        FROM facturas AS F 
			INNER JOIN InformacionCliente AS I on F.CedulaCliente = I.CedulaCliente 
			INNER JOIN repuestosreparacion as RR on F.IdReparacion = RR.IdReparacion 
			INNER JOIN repuestos AS RE ON RE.IdRepuesto = RR.idRepuestos
			INNER JOIN reparacion as R on R.idReparacion = RR.IdReparacion
            INNER JOIN mecanicos as M ON M.CedulaMecanico =R.CedulaMecanico 
            INNER JOIN vehiculo as V on V.MatriculaVehiculo = R.Matricula;
################################################## FIN SCRIPT ######################################################
