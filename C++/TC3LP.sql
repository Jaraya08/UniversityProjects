CREATE SCHEMA IF NOT EXISTS TC3LP;

USE TC3LP;

CREATE TABLE T_Local
(
	Cedula VARCHAR(64) PRIMARY KEY NOT NULL,
    Nombre VARCHAR(256) NOT NULL,
    Horario VARCHAR(256) NOT NULL,
    Slogan VARCHAR(128) NOT NULL,
    Direccion VARCHAR(512) NOT NULL
)ENGINE=INNODB;

INSERT INTO T_Local(Cedula,Nombre,Horario,Slogan,Direccion)
	VALUES("J3101230123","Fereterria","Lunes a Sabado 8 am - 6 pm",
    "Los mejores Repuestos a tu alzance","Limon Centro, Limon-Costa Rica");
    
CREATE TABLE T_Categorias
(
	IdCategoria INT PRIMARY KEY AUTO_INCREMENT,
    Nombre VARCHAR(256) UNIQUE NOT NULL,
    TipoCategoria VARCHAR(128) NOT NULL,
    Impuesto INT DEFAULT 0

)ENGINE=INNODB;

 

CREATE TABLE T_Productos
(
	IdProducto INT PRIMARY KEY AUTO_INCREMENT,
    Nombre VARCHAR(256) UNIQUE NOT NULL,
    Categoria INT,
    FOREIGN KEY (Categoria) REFERENCES T_Categorias(IdCategoria) ON UPDATE CASCADE 
																 ON DELETE RESTRICT,
    Precio DOUBLE(10,2)
)ENGINE=INNODB;


CREATE TABLE T_Cliente
(
	Cedula VARCHAR(64) PRIMARY KEY NOT NULL,
    Nombre VARCHAR(128) NOT NULL,
    Apellido VARCHAR(128) NOT NULL,
    Telefono VARCHAR(128) NOT NULL
)ENGINE=INNODB;



CREATE TABLE T_Facturas
(
	NumeroFactura INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    CedulaCliente VARCHAR(64),
    CedulaLocal VARCHAR(64),
    FechaRegistro TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    SubTotal DOUBLE(10,2),
    Impuestos DOUBLE(10,2),
    Total DOUBLE(10,2),
    FOREIGN KEY (CedulaCliente) REFERENCES T_Cliente(Cedula) ON UPDATE CASCADE 
																	 ON DELETE RESTRICT,
    FOREIGN KEY (CedulaLocal) REFERENCES T_Local(Cedula) ON UPDATE CASCADE 
														 ON DELETE RESTRICT
)ENGINE=INNODB;


CREATE TABLE T_ProductosPorFactura
(
	IdProductos INT,
    IdFactura INT,
    Cantidad INT,
    FOREIGN KEY (IdProductos) REFERENCES T_Productos(IdProducto) ON UPDATE CASCADE 
																 ON DELETE RESTRICT,
    FOREIGN KEY (IdFactura) REFERENCES T_Facturas(NumeroFactura) ON UPDATE CASCADE 
																 ON DELETE RESTRICT
)ENGINE=INNODB;

							########## VISTAS ##########

CREATE VIEW V_Productos
  AS
	SELECT P.IdProducto,P.Nombre Producto ,C.Nombre Categoria,P.Precio Precio
	FROM T_Productos AS P INNER JOIN T_Categorias AS C ON P.Categoria = C.IdCategoria ;


CREATE VIEW V_detalleFactura
  AS
		SELECT PF.IdFactura,P.IdProducto,P.Nombre Producto,C.Nombre Categoria,PF.Cantidad,P.Precio Precio,
			(P.precio*PF.Cantidad) as SubTotal,
			CASE WHEN C.Impuesto =0 THEN 'No Aplica' ELSE C.impuesto END Impuesto,
            ROUND((((P.precio*PF.Cantidad) * C.Impuesto)/100),1) Impuestos,
            ROUND(((P.precio*PF.Cantidad)+(((P.precio*PF.Cantidad) * C.Impuesto)/100)),1) AS Total
		FROM T_Facturas AS F 
        INNER JOIN T_ProductosPorFactura AS PF ON F.NumeroFactura = PF.IdFactura 
        INNER JOIN T_Productos AS P ON PF.IdProductos = P.IdProducto
        INNER JOIN T_Categorias AS C ON C.IdCategoria = P.Categoria;


CREATE VIEW V_DatosFactura
AS
	SELECT F.NumeroFactura Factura,F.FechaRegistro Fecha,C.Cedula Cedula,
		concat_ws(' ',C.Nombre,C.Apellido) Nombre,L.Cedula CedLocal,L.Nombre Locall,
		F.SubTotal,F.Impuestos,F.Total,SUM(PF.Cantidad) Cantidad
    FROM T_Facturas F 
		INNER JOIN T_Cliente C ON C.Cedula = F.cedulaCLiente
        INNER JOIN T_Local L ON L.Cedula =F.CedulaLocal
        INNER JOIN T_ProductosPorFactura PF ON PF.IdFactura = F.NumeroFactura
		GROUP BY NumeroFactura;


CREATE VIEW V_Subtotal
AS
	SELECT  PF.IdFactura,(P.Precio*PF.Cantidad) AS Subtotal
			FROM T_Productos AS P 
				INNER JOIN T_ProductosPorFactura AS PF ON P.IdProducto= PF.IdProductos;
			

CREATE VIEW V_Impuestos
AS
	SELECT PF.IdFactura,((P.Precio*PF.Cantidad)*(C.Impuesto/100)) AS Impuesto
			FROM T_Productos AS P 
				INNER JOIN T_ProductosPorFactura AS PF ON P.IdProducto= PF.IdProductos
                INNER JOIN T_Categorias AS C ON C.IdCategoria = P.Categoria;                
   
CREATE VIEW V_ClientesFacturados
AS
	SELECT F.CedulaCliente Cliente,C.Nombre Nombre,COUNT(F.NumeroFactura) Cantidad,SUM(F.Total) Total
	FROM T_Facturas F 	 
		INNER JOIN  T_Cliente C ON F.CedulaCliente = C.Cedula
		GROUP BY CedulaCliente;
                      ########## PROCEDIMIENTOS ALMACENADOS ##########


CREATE VIEW V_ItemFacturados
AS
	SELECT P.IdProducto, P.Nombre,SUM(PF.Cantidad) Cantidad
		FROM T_Productos P 
        INNER JOIN T_ProductosPorFactura PF ON PF.IdProductos = P.IdProducto
        GROUP BY IdProducto
        ORDER BY Cantidad DESC;
		
DELIMITER $
CREATE PROCEDURE ST_ProductosPorFactura (IN PidProducto INT,
										 IN PidFactura INT,
										 IN Pcantidad INT)
	BEGIN 
		 
			IF EXISTS(SELECT IdProductos FROM T_ProductosPorFactura 
				WHERE IdFactura=PidFactura AND IdProductos = PIdproducto)
			THEN  
				UPDATE T_ProductosPorFactura  SET Cantidad= (Cantidad+PCantidad) 
				WHERE IdProductos=PidProducto AND IdFactura= PidFactura;
			ELSE 
				INSERT INTO T_ProductosPorFactura (IdProductos,IdFactura,Cantidad) 
					VALUES (PidProducto,PidFactura,Pcantidad);
			END IF;
END$


DELIMITER $
CREATE  PROCEDURE ST_CrearFactura (IN PcedulaCliente VARCHAR(128), IN PidFactura INT)
BEGIN
		UPDATE T_Facturas
			SET CedulaCliente = PcedulaCliente,
				CedulaLocal = (SELECT Cedula FROM T_Local),
                SubTotal = (SELECT SUM(Subtotal) FROM V_Subtotal WHERE IdFactura = PidFactura),
                Impuestos = (SELECT SUM(Impuesto) FROM V_Impuestos WHERE IdFactura = PidFactura),
                Total = (SubTotal+Impuestos)
			WHERE NumeroFactura = PidFactura;
END$