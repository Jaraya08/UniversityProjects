CREATE DATABASE CRM
--################################## SECTORES ########################################################
CREATE TABLE Sectores
(
	idSector INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
	NombreSector VARCHAR(64) NOT NULL,
	Estado bit default 1,
);
GO

CREATE PROCEDURE AgregarSector
	@NombreSector VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO Sectores (NombreSector) VALUES(@NombreSector);
		END	
GO
CREATE PROCEDURE EliminarSector
	@IdSector INT
	AS
	BEGIN 
		UPDATE 	Sectores SET Estado = 0 WHERE idSector = @IdSector
	END
GO
CREATE PROCEDURE ModificarSector
	@NombreSector VARCHAR(64),
	@IdSector int
	AS
	BEGIN 
		UPDATE 	Sectores SET NombreSector = @NombreSector WHERE idSector = @IdSector
	END
GO
--################################## ZONAS ##########################################################
CREATE TABLE Zonas
(
	IdZona INT PRIMARY KEY IDENTITY (1,1) NOT NULL,
	NombreZona VARCHAR(64) NOT NULL,
	Estado bit DEFAULT 1
);
GO
CREATE PROCEDURE AgregarZona
	@NombreZona VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO Zonas (NombreZona) VALUES(@NombreZona);
		END	
GO
CREATE PROCEDURE EliminarZona
	@IdZona INT
	AS
	BEGIN 
		UPDATE 	Zonas SET Estado=0 WHERE IdZona = @IdZona
	END
GO
CREATE PROCEDURE ModificarZona
	@NombreZona VARCHAR(64),
	@IdZona int
	AS
		BEGIN  
			UPDATE 	Zonas SET NombreZona = @NombreZona WHERE IdZona = @IdZona
		END	
GO
--################################## DIVISA ##########################################################
CREATE TABLE Divisa
(
	idDivisa INT IDENTITY(1,1) PRIMARY KEY,
	NombreDivisa VARCHAR(3) NOT NULL,
	Estado bit DEFAULT 1,
);
GO
CREATE PROCEDURE AgregarDivisa
	@NombreDivisa VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO Divisa (NombreDivisa) VALUES(@NombreDivisa);
		END	
GO
CREATE PROCEDURE EliminarDivisa
	@idDivisa INT
	AS
	BEGIN 
		UPDATE 	Divisa SET Estado=0 WHERE idDivisa = @idDivisa
	END
GO
CREATE PROCEDURE ModificarDivisa
	@NombreDivisa VARCHAR(64),
	@idDivisa int
	AS
		BEGIN  
			UPDATE 	Divisa SET NombreDivisa= @NombreDivisa WHERE idDivisa = @idDivisa
		END	
GO
--###########################TIPO CONTACTO ############################################################3
CREATE TABLE TipoContacto
(
	idTipo INT IDENTITY (1,1) PRIMARY KEY,
	NombreTipo VARCHAR(256) NOT NULL,
	Estado bit DEFAULT 1,

);
GO
CREATE PROCEDURE AgregarTipoContacto
	@NombreTipo VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO TipoContacto (NombreTipo) VALUES(@NombreTipo);
		END	
GO
CREATE PROCEDURE EliminarNombreTipo
	@idTipo INT
	AS
	BEGIN 
		UPDATE 	TipoContacto SET Estado=0 WHERE idTipo = @idTipo
	END
GO
CREATE PROCEDURE ModificarTipoContacto
	@NombreTipo VARCHAR(64),
	@idTipo int
	AS
		BEGIN  
			UPDATE 	TipoContacto SET NombreTipo = @NombreTipo WHERE idTipo = @idTipo
		END	
GO
--##################################ESTADO CONTACTO ####################################################
CREATE TABLE EstadoContacto
(
	idEstado int IDENTITY(1,1) PRIMARY KEY,
	NombreEstado VARCHAR(256) NOT NULL,
	Estado BIT DEFAULT 1,
);
GO
CREATE PROCEDURE AgregarEstadoContacto
	@NombreEstado VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO EstadoContacto (NombreEstado) VALUES(@NombreEstado);
		END	
GO
CREATE PROCEDURE EliminarEstadoContacto
	@idEstado INT
	AS
	BEGIN 
		UPDATE 	EstadoContacto SET Estado=0 WHERE idEstado = @idEstado
	END
GO
CREATE PROCEDURE ModificarEstadoContacto
	@NombreEstado VARCHAR(64),
	@idEstado int
	AS
		BEGIN  
			UPDATE 	EstadoContacto SET NombreEstado = @NombreEstado WHERE idEstado = @idEstado
		END	
GO
--####################################PROBABILIDAD#######################################################
CREATE TABLE Probabilidad 
(
	idProbabilidad INT IDENTITY(1,1) PRIMARY KEY,
	CantidadProbabilidad INT CHECK (CantidadProbabilidad>1) NOT NULL,
	Estado int DEFAULT 1,
);
GO
CREATE PROCEDURE AgregarProbabilidad
	@CantidadProbabilidad INT
	AS
		BEGIN  
			INSERT INTO Probabilidad (CantidadProbabilidad) VALUES(@CantidadProbabilidad);
		END	
GO
CREATE PROCEDURE EliminarProbabilidad
	@idProbabilidad INT
	AS
	BEGIN 
		UPDATE 	Probabilidad SET Estado=0 WHERE idProbabilidad = @idProbabilidad
	END
GO
CREATE PROCEDURE ModificarProbabilidad
	@CantidadProbabilidad INT,
	@idProbabilidad int
	AS
		BEGIN  
			UPDATE 	Probabilidad SET CantidadProbabilidad = @CantidadProbabilidad WHERE idProbabilidad = @idProbabilidad
		END	
GO
--####################################TIPO COTIZACION ##################################################

CREATE TABLE TipoCotizacion
(
	idTipo INT IDENTITY (1,1) PRIMARY KEY,
	NombreTipo VARCHAR(256) NOT NULL,
	Estado bit default 1
);
GO
CREATE PROCEDURE AgregarTipoCotizacion
	@NombreTipo VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO TipoCotizacion (NombreTipo) VALUES(@NombreTipo);
		END	
GO
CREATE PROCEDURE EliminarTipoCotizacion
	@idTipo INT
	AS
	BEGIN 
		UPDATE 	TipoCotizacion SET Estado=0 WHERE idTipo = @idTipo
	END
GO
CREATE PROCEDURE ModificarTipoCotizacion
	@idTipo INT,
	@NombreTipo varchar(64)
	AS
		BEGIN  
			UPDATE 	TipoCotizacion SET NombreTipo = @NombreTipo WHERE idTipo = @idTipo
		END	
GO

--#########################################################################################
CREATE TABLE Denegaciones 
(
	idDenegacion INT IDENTITY(1,1) PRIMARY KEY,
	Porque VARCHAR(500) NOT NULL,
	Estado bit default 1,
);
GO
CREATE PROCEDURE AgregarDenegaciones
	@Porque VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO Denegaciones (Porque) VALUES(@Porque);
		END	
GO
CREATE PROCEDURE EliminarDenegaciones
	@idDenegacion INT
	AS
	BEGIN 
		UPDATE 	Denegaciones SET Estado=0 WHERE idDenegacion = @idDenegacion
	END
GO
CREATE PROCEDURE ModificarDenegaciones
	@idDenegacion INT,
	@Porque varchar(64)
	AS
		BEGIN  
			UPDATE 	Denegaciones SET Porque = @Porque WHERE idDenegacion = @idDenegacion
		END	
GO
--###########################################################################
CREATE TABLE PerdidaCotizacion
(
	idCompetencia INT IDENTITY (1,1) PRIMARY KEY,
	NombreCompetencia VARCHAR(256) NOT NULL,
	Estado bit default 1,
);
GO
CREATE PROCEDURE AgregarPerdidaCotizacion
	@NombreCompetencia VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO PerdidaCotizacion (NombreCompetencia) VALUES(@NombreCompetencia);
		END	
GO
CREATE PROCEDURE EliminarPerdidaCotizacion
	@idCompetencia INT
	AS
	BEGIN 
		UPDATE 	PerdidaCotizacion SET Estado=0 WHERE idCompetencia = @idCompetencia
	END
GO
CREATE PROCEDURE ModificarPerdidaCotizacion
	@idCompetencia INT,
	@NombreCompetencia varchar(64)
	AS
		BEGIN  
			UPDATE 	PerdidaCotizacion SET NombreCompetencia = @NombreCompetencia WHERE idCompetencia = @idCompetencia
		END	
GO

--###############################################################################
CREATE TABLE OrigenCaso
(
	idOrigen INT IDENTITY (1,1) PRIMARY KEY,
	NombreCaso VARCHAR(256) NOT NULL,
	Estado bit DEFAULT 1,
);
GO
CREATE PROCEDURE AgregarOrigenCaso
	@NombreCaso VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO OrigenCaso (NombreCaso) VALUES(@NombreCaso);
		END	
GO
CREATE PROCEDURE EliminarOrigenCaso
	@idOrigen INT
	AS
	BEGIN 
		UPDATE 	OrigenCaso SET Estado=0 WHERE idOrigen = @idOrigen
	END
GO
CREATE PROCEDURE ModificarOrigenCaso
	@idOrigen INT,
	@NombreCaso varchar(64)
	AS
		BEGIN  
			UPDATE 	OrigenCaso SET NombreCaso = @NombreCaso WHERE idOrigen = @idOrigen
		END	
GO

--#######################################################
CREATE TABLE EstadoCaso
(
	idEstado INT IDENTITY (1,1) PRIMARY KEY,
	NombreEstado VARCHAR(500) NOT NULL,
	Estado bit default 1,
);
GO
CREATE PROCEDURE AgregarEstadoCaso
	@NombreEstado VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO EstadoCaso (NombreEstado) VALUES(@NombreEstado);
		END	
GO
CREATE PROCEDURE EliminarEstadoCaso
	@idEstado INT
	AS
	BEGIN 
		UPDATE 	EstadoCaso SET Estado=0 WHERE idEstado = @idEstado
	END
GO
CREATE PROCEDURE ModificarEstadoCaso
	@idEstado INT,
	@NombreEstado varchar(64)
	AS
		BEGIN  
			UPDATE 	EstadoCaso SET NombreEstado = @NombreEstado WHERE idEstado = @idEstado
		END	
GO
--#######################################################################
CREATE TABLE TipoCaso 
(
	idTipo INT IDENTITY (1,1) PRIMARY KEY,
	NombreTipo VARCHAR(256),
	Estado BIT DEFAULT 1,
);

GO
CREATE PROCEDURE AgregarTipoCaso
	@NombreTipo VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO TipoCaso (NombreTipo) VALUES(@NombreTipo);
		END	
GO
CREATE PROCEDURE EliminarTipoCaso
	@idTipo INT
	AS
	BEGIN 
		UPDATE 	TipoCaso SET Estado=0 WHERE idTipo = @idTipo
	END
GO
CREATE PROCEDURE ModificarTipoCaso
	@idTipo INT,
	@NombreTipo varchar(64)
	AS
		BEGIN  
			UPDATE 	TipoCaso SET NombreTipo = @NombreTipo WHERE idTipo = @idTipo
		END	
GO

--########################################################################
CREATE TABLE Prioridad
(
	idPrioridad INT IDENTITY(1,1) PRIMARY KEY,
	NombrePrioridad VARCHAR(256) NOT NULL,
	Estado bit default 1,
);
GO
CREATE PROCEDURE AgregarPrioridad
	@NombrePrioridad VARCHAR(64)
	AS
		BEGIN  
			INSERT INTO Prioridad (NombrePrioridad) VALUES(@NombrePrioridad);
		END	
GO
CREATE PROCEDURE EliminarPrioridad
	@idPrioridad INT
	AS
	BEGIN 
		UPDATE 	Prioridad SET Estado=0 WHERE idPrioridad = @idPrioridad
	END
GO
CREATE PROCEDURE ModificarPrioridad
	@idPrioridad INT,
	@NombrePrioridad varchar(64)
	AS
		BEGIN  
			UPDATE 	Prioridad SET NombrePrioridad = @NombrePrioridad WHERE idPrioridad = @idPrioridad
		END	
GO
--########################################################################
CREATE TABLE ComoSeEntero
(
	idComoSeEntero INT IDENTITY (1,1) PRIMARY KEY,
	Descripcion VARCHAR(256) not null,
	Estado int default 1,
);
GO
CREATE PROCEDURE AgregarComoSeEntero
	@Descripcion VARCHAR(256)
	AS
		BEGIN  
			INSERT INTO ComoSeEntero (Descripcion) VALUES(@Descripcion);
		END	
GO
CREATE PROCEDURE EliminarComoSeEntero
	@idComoSeEntero INT
	AS
	BEGIN 
		UPDATE 	ComoSeEntero SET Estado=0 WHERE idComoSeEntero = @idComoSeEntero
	END
GO
CREATE PROCEDURE ModificarComoSeEntero
	@idComoSeEntero INT,
	@Descripcion varchar(256)
	AS
		BEGIN  
			UPDATE 	ComoSeEntero SET Descripcion = @Descripcion WHERE idComoSeEntero = @idComoSeEntero
		END	
GO
--###############################################################################3
CREATE TABLE EtapaCotizacion
(
	idEtapa INT IDENTITY(0,1) PRIMARY KEY,
	NombreEtapa VARCHAR(256) NOT NULL,
	Estado bit Default 1,
);

GO
CREATE PROCEDURE AgregarEtapaCotizacion
	@NombreEtapa VARCHAR(256)
	AS
		BEGIN  
			INSERT INTO EtapaCotizacion (NombreEtapa) VALUES(@NombreEtapa);
		END	
GO
CREATE PROCEDURE EliminarEtapaCotizacion
	@idEtapa INT
	AS
	BEGIN 
		UPDATE 	EtapaCotizacion SET Estado=0 WHERE idEtapa = @idEtapa
	END
GO
CREATE PROCEDURE ModificarEtapaCotizacion
	@idEtapa INT,
	@NombreEtapa varchar(256)
	AS
		BEGIN  
			UPDATE 	EtapaCotizacion SET NombreEtapa = @NombreEtapa WHERE idEtapa = @idEtapa
		END	
GO
--#######################################################################################
------------------O-------------------------------------------O-----------------------------------------O---------------------------

--CREAR ROLES CON SUS RESPECTIVAS FUNCIONES EN LA BASE DE DATOS--
CREATE TABLE FuncionRol --C= Crear / E= Editar / M= Modificar / H= Habilitar / I = Inabilitar / D = Eliminar 
(
	idFuncion int IDENTITY (1,1) PRIMARY KEY,
	NombreRol VARCHAR(64) NOT NULL,
	Estado bit DEFAULT 1,
	CMHI_Usuario bit,
	CED_Roles bit,
	CED_FamiliaProductos bit,
	CED_Productos bit,
	CED_Sectores bit,
	CED_Clientes bit,
	CED_CotactosCliente bit,
	CED_ActividadesContactoCliete bit,
	CED_Cotizaciones bit,
	CED_ActividadesCotizaciones bit,
	CED_Ejecuciones bit,
	CED_TareaEjecuciones bit,
	CED_Casos bit,
	CED_TareaCasos bit,
);
GO

CREATE PROCEDURE AgregarFuncionRol
	@NombreRol VARCHAR(64),
	@CMHI_Usuario BIT,
	@CED_Roles BIT,
	@CED_FamiliaProductos BIT,
	@CED_Productos BIT,
	@CED_Sectores BIT,
	@CED_Clientes BIT,
	@CED_CotactosCliente BIT,
	@CED_ActividadesContactoCliete BIT,
	@CED_Cotizaciones BIT,
	@CED_ActividadesCotizaciones BIT,
	@CED_Ejecuciones BIT,
	@CED_TareaEjecuciones bit,
	@CED_Casos bit,
	@CED_TareaCasos bit
	AS
		BEGIN 
			INSERT INTO FuncionRol (NombreRol,CMHI_Usuario,CED_Roles,CED_FamiliaProductos,CED_Productos,CED_Sectores, CED_Clientes
									,CED_CotactosCliente,CED_ActividadesContactoCliete,CED_Cotizaciones,CED_ActividadesCotizaciones
									,CED_Ejecuciones,CED_TareaEjecuciones,CED_Casos,CED_TareaCasos)

							VALUES(@NombreRol,@CMHI_Usuario,@CED_Roles,@CED_FamiliaProductos,@CED_Productos,@CED_Sectores , @CED_Clientes
									,@CED_CotactosCliente,@CED_ActividadesContactoCliete,@CED_Cotizaciones,@CED_ActividadesCotizaciones
									,@CED_Ejecuciones,@CED_TareaEjecuciones,@CED_Casos,@CED_TareaCasos);
		END 
GO

CREATE PROCEDURE EliminarFuncionRol
	@idFuncion int
	AS
		BEGIN 
			UPDATE FuncionRol SET estado =0 where idFuncion = @idFuncion;
		END
GO
CREATE PROCEDURE ModificarFuncionRol
	@idFuncion INT,
	@NombreRol VARCHAR(64),
	@CED_Roles BIT,
	@CED_FamiliaProductos BIT,
	@CED_Productos BIT,
	@CED_Sectores BIT,
	@CED_Clientes BIT,
	@CED_CotactosCliente BIT,
	@CED_ActividadesContactoCliete BIT,
	@CED_Cotizaciones BIT,
	@CED_ActividadesCotizaciones BIT,
	@CED_Ejecuciones BIT,
	@CED_TareaEjecuciones bit,
	@CED_Casos bit,
	@CED_TareaCasos bit
	AS
		BEGIN 
			UPDATE FuncionRol SET   NombreRol=@NombreRol,
									CED_Roles=@CED_Roles,				 
									CED_FamiliaProductos=@CED_FamiliaProductos,
									CED_Productos=@CED_Productos,
									CED_Sectores=@CED_Sectores,
									CED_Clientes=@CED_Clientes,
									CED_CotactosCliente=@CED_CotactosCliente,
									CED_ActividadesContactoCliete=@CED_ActividadesContactoCliete,
									CED_Cotizaciones=@CED_Cotizaciones,
									CED_ActividadesCotizaciones=@CED_ActividadesCotizaciones,
									CED_Ejecuciones=@CED_Ejecuciones,
									CED_TareaEjecuciones=@CED_TareaEjecuciones,
									CED_Casos=@CED_Casos,
									CED_TareaCasos=@CED_TareaCasos
							  WHERE idFuncion=@idFuncion;
		 END
GO

--#############################################################################################################
CREATE TABLE Usuarios
(
	idUsuario INT PRIMARY KEY IDENTITY (1,1) NOT NULL,
	NombreUsuario VARCHAR(256) UNIQUE NOT NULL,
	Contrasenha VARCHAR(128) NOT NULL,
	Estado bit DEFAULT 1,
	Rol INT FOREIGN KEY REFERENCES FuncionRol(idFuncion)
);

GO
CREATE PROCEDURE AgregarUsuarios
	@NombreUsuario VARCHAR(256),
	@Contrasenha VARCHAR(128),
	@Rol INT
	AS 
		BEGIN 
			INSERT INTO Usuarios (NombreUsuario,Contrasenha,Rol) VALUES(@NombreUsuario,@Contrasenha,@Rol);
		END
GO
CREATE PROCEDURE EliminarUsuarios
	@idUsuario INT
	AS
		BEGIN 
			UPDATE Usuarios SET Estado = 0 WHERE idUsuario=@idUsuario ;
		END
GO
CREATE PROCEDURE ModificarUsuarios
	@idUsuario INT,
	@NombreUsuario VARCHAR(256),
	@Contrasenha VARCHAR(128),
	@Rol INT
	AS
		BEGIN 
			UPDATE Usuarios SET NombreUsuario=@NombreUsuario,
								Contrasenha=@Contrasenha,
								Rol=@Rol
							WHERE idUsuario=@idUsuario;
		END
GO
--####departamentos
CREATE TABLE Departamentos
(
	IdDepartamentos INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
	NombreDepartamento VARCHAR(128),
	Estado bit default 1
);
GO
CREATE PROCEDURE AgregarDepartamentos
	@NombreDepartamento VARCHAR(128)
	AS
		BEGIN 
			INSERT INTO Departamentos (NombreDepartamento) VALUES(@NombreDepartamento);
		END
GO
CREATE PROCEDURE EliminarDepartamentos
	@IdDepartamentos int
	AS 
		BEGIN 
			UPDATE Departamentos SET Estado = 0 WHERE IdDepartamentos=@IdDepartamentos;
		END
GO
CREATE PROCEDURE ModificarDepartamentos
	@IdDepartamentos int,
	@NombreDepartamento VARCHAR(128)
	AS 
		BEGIN 
			UPDATE Departamentos SET NombreDepartamento=@NombreDepartamento WHERE IdDepartamentos=@IdDepartamentos;
		END
GO
--## fin depar
CREATE FUNCTION VerificarUsuario (@Contrasenha varchar(156),@idUsuario int)
	
	RETURNS INT
	AS
		BEGIN 
			DECLARE @verificacion int
			IF(Select Contrasenha FROM Usuarios where idUsuario=@idUsuario) = @Contrasenha 
				set @verificacion= 1
			else 
				set @verificacion =0
			return @verificacion
		end
go 

--#########################################################################################################
CREATE TABLE FamiliaProducto
(
	idFamilia INT IDENTITY(1,1) PRIMARY KEY,
	NombreFamilia VARCHAR(256) NOT NULL,
	Descripcion VARCHAR(512) NOT NULL,
	Estado bit DEFAULT 1
);
GO
CREATE PROCEDURE AgregarFamiliaProducto
	@NombreFamilia VARCHAR(256),
	@Descripcion VARCHAR(512)
	AS
		BEGIN 
			INSERT INTO FamiliaProducto (NombreFamilia,Descripcion) VALUES(@NombreFamilia,@Descripcion);
		END
GO
CREATE PROCEDURE EliminarFamiliaProducto
	@idFamilia INT
	AS 
		BEGIN 
			UPDATE FamiliaProducto SET Estado = 0 WHERE idFamilia=@idFamilia;
		END
GO

CREATE PROCEDURE ModificarFamiliaProducto
	@idFamilia int,
	@NombreFamilia VARCHAR(256),
	@Descripcion VARCHAR(512)
	AS
		BEGIN 
			UPDATE FamiliaProducto SET NombreFamilia = @NombreFamilia,
									   Descripcion = @Descripcion

									WHERE idFamilia = @idFamilia;
		END
GO
									   
CREATE TABLE Productos
(
	idProducto INT IDENTITY (1,1) PRIMARY KEY,
	NombreProducto VARCHAR(256) NOT NULL,
	FamiliaPRoducto INT FOREIGN KEY REFERENCES FamiliaProducto(idFamilia),
	Precio decimal(10,2) NOT NULL,
	Descripcion VARCHAR (512) NOT NULL,
	Estado bit DEFAULT 1,
);
GO
CREATE PROCEDURE AgregarProductos
	@NombreProducto VARCHAR(256),
	@FamiliaPRoducto INT,
	@Precio decimal(10,2),
	@Descripcion VARCHAR (512)
	AS
		BEGIN 
			INSERT INTO Productos (NombreProducto,FamiliaPRoducto,Precio,Descripcion) VALUES(@NombreProducto,@FamiliaPRoducto
																							 ,@Precio,@Descripcion);
		END
GO
CREATE PROCEDURE EliminarProductos
	@idProducto int
	AS
		BEGIN 
			UPDATE Productos SET Estado =0 WHERE idProducto=@idProducto;
		END
GO

CREATE PROCEDURE ModificarProductos
	@idProducto int,
	@NombreProducto VARCHAR(256),
	@FamiliaPRoducto INT,
	@Precio decimal(10,2),
	@Descripcion VARCHAR (512)
	AS
		BEGIN 
			UPDATE Productos SET NombreProducto=@NombreProducto,
								 FamiliaPRoducto=@FamiliaPRoducto,
								 Precio=@Precio,
								 Descripcion=@Descripcion
							 WHERE idProducto=@idProducto;
		END
GO


--################################################################################################################################
								 

CREATE TABLE Clientes 
(
	CodigoCliente INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
	NombreCuenta VARCHAR(256) NOT NULL,
	CorreoCliente VARCHAR(128) NOT NULL,
	ContactoPrincipal VARCHAR(128) NOT NULL,
	DivisaCuenta INT FOREIGN KEY REFERENCES Divisa(idDivisa),
	TelefonoCliente VARCHAR(16) DEFAULT 'S/N',
	CelularCliente VARCHAR(16) DEFAULT 'S/N',
	WebCliente VARCHAR(128) DEFAULT 'N/A',
	InformacionAdicional VARCHAR(512) NOT NULL,
	AsesorCliente INT FOREIGN KEY REFERENCES Usuarios(idUsuario) NOT NULL, 
	Zona INT FOREIGN KEY REFERENCES Zonas(IdZona) NOT NULL,
	Sector INT FOREIGN KEY REFERENCES Sectores(idSector) NOT NULL,
	Estado bit default 1,
);
GO
CREATE PROCEDURE AgregarClientes
	@NombreCuenta VARCHAR(256),
	@CorreoCliente VARCHAR(128),
	@ContactoPrincipal VARCHAR(128),
	@DivisaCuenta INT,
	@TelefonoCliente VARCHAR(16),
	@CelularCliente VARCHAR(16),
	@WebCliente VARCHAR(128),
	@InformacionAdicional VARCHAR(512),
	@AsesorCliente INT, -- usuario -- 
	@Zona INT,
	@Sector INT
	AS
		BEGIN 
			INSERT INTO Clientes(NombreCuenta,CorreoCliente,ContactoPrincipal,DivisaCuenta,TelefonoCliente,CelularCliente
								 ,WebCliente,InformacionAdicional,AsesorCliente,Zona,Sector)
				        VALUES(@NombreCuenta,@CorreoCliente,@ContactoPrincipal,@DivisaCuenta,@TelefonoCliente,@CelularCliente,
								 @WebCliente,@InformacionAdicional,@AsesorCliente,@Zona,@Sector);
		END
GO
CREATE PROCEDURE EliminarClientes
	@CodigoCliente int
	AS
		BEGIN 
			UPDATE Clientes SET Estado = 0 WHERE CodigoCliente=@CodigoCliente;
		END
GO
CREATE PROCEDURE ModificarClientes
	@CodigoCliente int,
	@NombreCuenta VARCHAR(256),
	@CorreoCliente VARCHAR(128),
	@ContactoPrincipal VARCHAR(128),
	@DivisaCuenta INT,
	@TelefonoCliente VARCHAR(16),
	@CelularCliente VARCHAR(16),
	@WebCliente VARCHAR(128),
	@InformacionAdicional VARCHAR(512),
	@Zona INT,
	@Sector INT
	AS
		BEGIN 
			UPDATE Clientes SET NombreCuenta=@NombreCuenta,
								CorreoCliente=@CorreoCliente,
								ContactoPrincipal=@ContactoPrincipal,
								DivisaCuenta=@DivisaCuenta,
								TelefonoCliente=@TelefonoCliente,
								CelularCliente=@CelularCliente,
								WebCliente=@WebCliente,
								InformacionAdicional=@InformacionAdicional,
								Zona=@Zona,
								Sector=@Sector
							WHERE CodigoCliente=@CodigoCliente;
		END
GO
--##################################################################################################
--FIN MODULO CLIENTE--

--MODULO CONTACTAR CLIENTE--
CREATE TABLE ContactoCliente
(
	CodigoContacto INT PRIMARY KEY IDENTITY (1,1) NOT NULL,
	NombreContacto VARCHAR(128) NOT NULL,
	ApellidoContacto VARCHAR(128) NOT NULL,
	NombreCompanhia VARCHAR(256) NOT NULL,
	ComoSeEntero INT FOREIGN KEY REFERENCES	ComoSeEntero(IdComoSeEntero),
	Sector INT  FOREIGN KEY REFERENCES Sectores(idSector) NOT NULL,
	Telefono VARCHAR(16) DEFAULT 'S/N',
	Celular VARCHAR(16) DEFAULT 'S/N',
	Correo VARCHAR(64) DEFAULT 'S/N',
	EstadoCandidato INT FOREIGN KEY REFERENCES EstadoContacto(idEstado) ,
	Direccion VARCHAR(256) DEFAULT 'Limon',
	Zona INT FOREIGN KEY REFERENCES Zonas(idZona) NOT NULL,
	Asesor INT FOREIGN KEY REFERENCES Usuarios(idUsuario) NOT NULL, 
	Descripcion VARCHAR(512) DEFAULT 'Ninguna',
	Estado bit default 1
);
GO
CREATE PROCEDURE AgregarContactoCliente
	@NombreContacto VARCHAR(128),
	@ApellidoContacto VARCHAR(128),
	@NombreCompanhia VARCHAR(256),
	@ComoSeEntero int,
	@Sector INT,
	@Telefono VARCHAR(16),
	@Celular VARCHAR(16),
	@Correo VARCHAR(64),
	@EstadoCandidato INT,
	@Direccion VARCHAR(256),
	@Zona INT,
	@Asesor INT,
	@Descripcion VARCHAR(512)
	AS
		BEGIN 
			INSERT INTO ContactoCliente (NombreContacto,ApellidoContacto,NombreCompanhia,ComoSeEntero,Sector,Telefono,Celular
										 ,Correo,EstadoCandidato,Direccion,Zona,Asesor,Descripcion)
								VALUES (@NombreContacto,@ApellidoContacto,@NombreCompanhia,@ComoSeEntero,@Sector,@Telefono,@Celular,@Correo
										,@EstadoCandidato,@Direccion,@Zona,@Asesor,@Descripcion);
		END
GO

CREATE PROCEDURE EliminarContactoCliente
	@CodigoContacto int
	AS
		BEGIN 
			UPDATE ContactoCliente SET Estado =0 WHERE CodigoContacto=@CodigoContacto
		END
GO
CREATE PROCEDURE ModificarContactoCliente
	@CodigoContacto INT,
	@NombreContacto VARCHAR(128),
	@ApellidoContacto VARCHAR(128),
	@NombreCompanhia VARCHAR(256),
	@ComoSeEntero int,
	@Sector INT,
	@Telefono VARCHAR(16),
	@Celular VARCHAR(16),
	@Correo VARCHAR(64),
	@EstadoCandidato INT,
	@Direccion VARCHAR(256),
	@Zona INT,
	@Descripcion VARCHAR(512)
	AS
		BEGIN 
			UPDATE ContactoCliente SET NombreContacto = @NombreContacto,
									   ApellidoContacto=@ApellidoContacto,
									   NombreCompanhia=@NombreCompanhia,
									   ComoSeEntero=@ComoSeEntero,
									   Sector=@Sector,
									   Telefono=@Telefono,
									   Celular=@Celular,
									   Correo=@Correo,
									   EstadoCandidato=@EstadoCandidato,
									   Direccion=@Direccion,
									   Zona=@Zona,
									   Descripcion=@Descripcion
									WHERE CodigoContacto=@CodigoContacto;
		END
GO

CREATE TABLE AsignarTareaCliente
(
	idTarea int identity (1,1) primary key,
	idUsuario INT FOREIGN KEY REFERENCES Usuarios (idUsuario) NOT NULL,
	idCliente INT FOREIGN KEY REFERENCES Clientes (CodigoCliente) NOT NULL,
	DescripcionTarea VARCHAR(512) NOT NULL,
	Estado bit default 1,
	FechaTarea datetime default getdate()
);
GO
CREATE PROCEDURE AgregarAsignarTareaCliente
	@idUsuario INT,
	@idCliente INT,
	@DescripcionTarea VARCHAR(512)
	AS 
		BEGIN 
			INSERT INTO AsignarTareaCliente (idUsuario,idCliente,DescripcionTarea) VALUES(@idUsuario,@idCliente,@DescripcionTarea);
		END
GO 

CREATE PROCEDURE EliminarAsignarTareaCliente
	@idTarea int
	AS
		BEGIN	
			UPDATE AsignarTareaCliente SET Estado = 0 WHERE idTarea=@idTarea;
		END
GO
CREATE PROCEDURE ModificarAsignarTareaCliente
	@idTarea int,
	@DescripcionTarea VARCHAR(512)
	AS
		BEGIN 
			UPDATE AsignarTareaCliente SET DescripcionTarea=@DescripcionTarea  WHERE idTarea=@idTarea;
		END
GO

CREATE TABLE AsignarActividadCliente
(
	idActividad int IDENTITY(1,1) PRIMARY KEY,
	idUsuario INT FOREIGN KEY REFERENCES Usuarios (idUsuario) NOT NULL,
	idCliente INT FOREIGN KEY REFERENCES Clientes (CodigoCliente) NOT NULL,
	DescripcionActividad VARCHAR(512),	
	Estado bit default 1,
);
GO
CREATE PROCEDURE AgregarAsignarActividadCliente
	@idUsuario INT,
	@idCliente INT,
	@DescripcionActividad VARCHAR(512)
	AS 
		BEGIN 
			INSERT INTO AsignarActividadCliente (idUsuario,idCliente,DescripcionActividad) VALUES(@idUsuario,@idCliente,@DescripcionActividad);
		END
GO 

CREATE PROCEDURE EliminarAsignarActividadCliente
	@idActividad int
	AS
		BEGIN	
			UPDATE AsignarActividadCliente SET Estado = 0 WHERE idActividad=@idActividad;
		END
GO
CREATE PROCEDURE ModificarAsignarActividadCliente
	@idActividad int,
	@DescripcionActividad VARCHAR(512)
	AS
		BEGIN 
			UPDATE AsignarActividadCliente SET DescripcionActividad=@DescripcionActividad  WHERE idActividad=@idActividad;
		END
GO

-- FIN MODULO CONTACTO CLIENTE-- 

--MODULO COTIZACIONES--
CREATE TABLE Cotizaciones
(
	NumeroCotizacion INT PRIMARY KEY IDENTITY(1,1) NOT NULL,
	Departamento int foreign key references departamentos (idDepartamentos),
	NombreOportunidad VARCHAR(128) NOT NULL, -- nombre proyecto--
	FechaCotizacion DATETIME DEFAULT GETDATE(),
	idCuenta INT FOREIGN KEY REFERENCES Clientes(CodigoCliente) NOT NULL, 
	Asesor INT FOREIGN KEY REFERENCES Usuarios(idUsuario) NOT NULL, -- USUARIO QUE HACE LA COTIZACION--
	FechaCierre DATETIME CHECK(FechaCierre>=getdate()) NOT NULL,
	Etapa INT FOREIGN KEY REFERENCES EtapaCotizacion(idetapa),
	DivisaOportunidad INT FOREIGN KEY REFERENCES Divisa(idDivisa),
	Probabilidad INT FOREIGN KEY REFERENCES Probabilidad(IdProbabilidad),
	OrdenDeCompra VARCHAR(100) DEFAULT 'None',
	TipoCotizacion int FOREIGN KEY REFERENCES TipoCotizacion(idTipo),
	Descripcion VARCHAR(512) DEFAULT 'Ninguna',
	Zona INT FOREIGN KEY REFERENCES Zonas(idZona),
	Sector INT FOREIGN KEY REFERENCES sectores(idSector),
	Contacto VARCHAR (128), -- CONTACTO CLIENTE -- 
	NumeroFactura VARCHAR (64) DEFAULT 'None',
	Denegacion INT FOREIGN KEY REFERENCES Denegaciones(idDenegacion),
	ContraQuien INT FOREIGN KEY REFERENCES PerdidaCotizacion(idCompetencia),
	Estado bit default 1,
);

GO 
CREATE PROCEDURE AgregarCotizaciones
	@NombreOportunidad VARCHAR(128),
	@idCuenta INT,
	@Asesor INT,
	@FechaCierre DATETIME,
	@Etapa INT,
	@DivisaOportunidad INT,
	@Probabilidad INT,
	@OrdenDeCompra VARCHAR(100),
	@TipoCotizacion int,
	@Descripcion VARCHAR(512),
	@Zona INT,
	@Sector INT,
	@Contacto VARCHAR (128),
	@NumeroFactura VARCHAR (64),
	@Denegacion INT,
	@ContraQuien INT
	AS
		BEGIN 
			INSERT INTO Cotizaciones (NombreOportunidad,idCuenta,Asesor,FechaCierre,Etapa,DivisaOportunidad
									  ,Probabilidad,OrdenDeCompra,TipoCotizacion,Descripcion,Zona,Sector,Contacto,NumeroFactura
									  ,Denegacion,ContraQuien)
								VALUES(@NombreOportunidad,@idCuenta,@Asesor,@FechaCierre,@Etapa,@DivisaOportunidad
									  ,@Probabilidad,@OrdenDeCompra,@TipoCotizacion,@Descripcion,@Zona,@Sector,@Contacto,@NumeroFactura
									  ,@Denegacion,@ContraQuien);
		END
GO
CREATE PROCEDURE EliminarCotizaciones
	@NumeroCotizacion int
	AS
		BEGIN 
			UPDATE Cotizaciones SET Estado = 0 WHERE NumeroCotizacion=@NumeroCotizacion;
		END 
GO
CREATE PROCEDURE ModificarCotizaciones
	@NumeroCotizacion int,
	@NombreOportunidad VARCHAR(128),
	@idCuenta INT,
	@FechaCierre DATETIME,
	@Etapa INT,
	@DivisaOportunidad INT,
	@Probabilidad INT,
	@OrdenDeCompra VARCHAR(100),
	@TipoCotizacion int,
	@Descripcion VARCHAR(512),
	@Zona INT,
	@Sector INT,
	@Contacto VARCHAR (128),
	@NumeroFactura VARCHAR (64),
	@Denegacion INT,
	@ContraQuien INT
	AS	
		BEGIN 
			UPDATE Cotizaciones SET NombreOportunidad=@NombreOportunidad,
									idCuenta=@idCuenta,
									FechaCierre=@FechaCierre,
									Etapa=@Etapa,
									DivisaOportunidad=@DivisaOportunidad,
									Probabilidad=@Probabilidad,
									OrdenDeCompra=@OrdenDeCompra,
									TipoCotizacion=@TipoCotizacion,
									Descripcion=@Descripcion,
									Zona=@Zona,
									Sector=@Sector,
									Contacto=@Contacto,
									NumeroFactura=@NumeroFactura,
									Denegacion=@Denegacion,
									ContraQuien=@ContraQuien
								WHERE NumeroCotizacion=@NumeroCotizacion;
		 END
GO

CREATE TABLE AsignarTareaCotizacion
(
	idTarea int identity (1,1)primary key,
	idUsuario INT FOREIGN KEY REFERENCES Usuarios (idUsuario) NOT NULL,
	IdCotizacion INT FOREIGN KEY REFERENCES Cotizaciones (NumeroCotizacion) NOT NULL,
	DescripcionTarea VARCHAR(512) NOT NULL, 
	Estado bit DEFAULT 1,
	FechaTarea datetime default getdate()

);
GO
CREATE PROCEDURE AgregarAsignarTareaCotizacion
	@idUsuario INT,
	@IdCotizacion INT,
	@DescripcionTarea VARCHAR(512)
	AS 
		BEGIN 
			INSERT INTO AsignarTareaCotizacion (idUsuario,IdCotizacion,DescripcionTarea) VALUES(@idUsuario,@IdCotizacion,@DescripcionTarea);
		END
GO 

CREATE PROCEDURE EliminarAsignarTareaCotizacion
	@idTarea int
	AS
		BEGIN	
			UPDATE AsignarTareaCotizacion SET Estado = 0 WHERE idTarea=@idTarea;
		END
GO
CREATE PROCEDURE ModificarAsignarTareaCotizacion
	@idTarea int,
	@DescripcionTarea VARCHAR(512)
	AS
		BEGIN 
			UPDATE AsignarTareaCotizacion SET DescripcionTarea=@DescripcionTarea  WHERE idTarea=@idTarea;
		END
GO

CREATE TABLE AsignarActividadCotizacion
(
	IdActividad int IDENTITY (1,1) PRIMARY KEY,
	idUsuario INT FOREIGN KEY REFERENCES Usuarios (idUsuario) NOT NULL,
	IdCotizacion INT FOREIGN KEY REFERENCES Cotizaciones (NumeroCotizacion) NOT NULL,
	DescripcionActividad VARCHAR(512) NOT NULL,
	Estado bit DEFAULT 1,
);
GO
CREATE PROCEDURE AgregarAsignarActividadCotizacion
	@idUsuario INT,
	@IdCotizacion INT,
	@DescripcionActividad VARCHAR(512)
	AS 
		BEGIN 
			INSERT INTO AsignarActividadCotizacion (idUsuario,IdCotizacion,DescripcionActividad) VALUES(@idUsuario,@IdCotizacion,@DescripcionActividad);
		END
GO 

CREATE PROCEDURE EliminarAsignarActividadCotizacion
	@idActividad int
	AS
		BEGIN	
			UPDATE AsignarActividadCotizacion SET Estado = 0 WHERE idActividad=@idActividad;
		END
GO
CREATE PROCEDURE ModificarAsignarActividadCotizacion
	@idActividad int,
	@DescripcionActividad VARCHAR(512)
	AS
		BEGIN 
			UPDATE AsignarActividadCotizacion SET DescripcionActividad=@DescripcionActividad  WHERE idActividad=@idActividad;
		END
GO

CREATE TABLE ProductosPorCotizacion
(
	idCotizacion int FOREIGN KEY REFERENCES COTIZACIONES(NumeroCotizacion),
	IdProducto INT FOREIGN KEY REFERENCES Productos (idProducto),
	Cantidad int NOT NULL
);
--FIN MODULO COTIZACIONES--

--MODULO DE EJECUCION DE PROCESOS-- 


CREATE TABLE ProcesoEjecucion
(
	idProceso INT PRIMARY KEY IDENTITY (1,1) NOT NULL,
	Departamento INT FOREIGN KEY REFERENCES Departamentos(IdDepartamentos) ,
	NumeroCotizacion INT FOREIGN KEY REFERENCES Cotizaciones(NumeroCotizacion),  
	Propiedad VARCHAR(128) NOT NULL,
	Nombre VARCHAR(128) NOT NULL,
	Fecha DATETIME DEFAULT GETDATE(),
	IdCuenta INT FOREIGN KEY REFERENCES Clientes(CodigoCliente)NOT NULL,
	Asesor INT FOREIGN KEY REFERENCES Usuarios(IdUsuario),
	FechaCierre DATETIME CHECK (FechaCierre>=getdate()),
	Estado BIT DEFAULT 1

);
GO
CREATE PROCEDURE AgregarProcesoEjecucion
	@Departamento INT,
	@NumeroCotizacion INT,
	@Propiedad VARCHAR(128),
	@Nombre VARCHAR(128),
	@IdCuenta INT,
	@Asesor INT,
	@FechaCierre DATETIME
	AS 
		BEGIN 
			INSERT INTO  ProcesoEjecucion (Departamento,NumeroCotizacion,Propiedad,Nombre,IdCuenta,Asesor,FechaCierre)
								    VALUES(@Departamento,@NumeroCotizacion,@Propiedad,@Nombre,@IdCuenta,@Asesor,@FechaCierre);
		END
GO

CREATE PROCEDURE EliminarProcesoEjecucion
	@idProceso int
	AS
		BEGIN 
			UPDATE ProcesoEjecucion SET Estado=0 WHERE idProceso=@idProceso;
		END
GO
CREATE PROCEDURE ModificarProcesoEjecucion
	@idProceso int,
	@Departamento INT,
	@NumeroCotizacion INT,
	@Propiedad VARCHAR(128),
	@Nombre VARCHAR(128),
	@IdCuenta INT,
	@FechaCierre DATETIME
	AS
		BEGIN 
			UPDATE ProcesoEjecucion SET Departamento=@Departamento,
										NumeroCotizacion=@NumeroCotizacion,
										Propiedad=@Propiedad,
										Nombre=@Nombre,
										IdCuenta=@IdCuenta,
										FechaCierre=@FechaCierre
									WHERE idProceso=@idProceso;
		END
GO
CREATE TABLE AsignarTareaProceso
(
	idTarea int identity (1,1) primary key,
	idUsuario INT FOREIGN KEY REFERENCES Usuarios (idUsuario) NOT NULL,
	idProceso INT FOREIGN KEY REFERENCES ProcesoEjecucion(idProceso) NOT NULL,
	DescripcionTarea VARCHAR(512) NOT NULL,	
	Estado bit default 1,
	FechaTarea datetime default getdate()

);
GO
CREATE PROCEDURE AgregarAsignarTareaProceso
	@idUsuario INT,
	@idProceso INT,
	@DescripcionTarea VARCHAR(512)
	AS 
		BEGIN 
			INSERT INTO AsignarTareaProceso (idUsuario,idProceso,DescripcionTarea) VALUES(@idUsuario,@idProceso,@DescripcionTarea);
		END
GO 

CREATE PROCEDURE EliminarAsignarTareaProceso
	@idTarea int
	AS
		BEGIN	
			UPDATE AsignarTareaProceso SET Estado = 0 WHERE idTarea=@idTarea;
		END
GO
CREATE PROCEDURE ModificarAsignarTareaProceso
	@idTarea int,
	@DescripcionTarea VARCHAR(512)
	AS
		BEGIN 
			UPDATE AsignarTareaProceso SET DescripcionTarea=@DescripcionTarea  WHERE idTarea=@idTarea;
		END
GO

CREATE TABLE AsignarActividadProceso
(
	idActividad int identity(1,1)primary key,
	idUsuario INT FOREIGN KEY REFERENCES Usuarios (idUsuario) NOT NULL,
	idCliente INT FOREIGN KEY REFERENCES ProcesoEjecucion(idProceso) NOT NULL,
	DescripcionActividad VARCHAR(512) NOT NULL,	
	Estado bit default 1
);
go
CREATE PROCEDURE AgregarAsignarActividadProceso
	@idUsuario INT,
	@idCliente INT,
	@DescripcionActividad VARCHAR(512)
	AS 
		BEGIN 
			INSERT INTO AsignarActividadProceso (idUsuario,idCliente,DescripcionActividad) VALUES(@idUsuario,@idCliente,@DescripcionActividad);
		END
GO 

CREATE PROCEDURE EliminarAsignarActividadProceso
	@idActividad int
	AS
		BEGIN	
			UPDATE AsignarActividadProceso SET Estado = 0 WHERE idActividad=@idActividad;
		END
GO
CREATE PROCEDURE ModificarAsignarActividadProceso
	@idActividad int,
	@DescripcionActividad VARCHAR(512)
	AS
		BEGIN 
			UPDATE AsignarActividadProceso SET DescripcionActividad=@DescripcionActividad  WHERE idActividad=@idActividad;
		END
GO
--FIN MODULO DE EJECUCION DE PROCESOS-- 

-- MODULO REGISTRO DE CASOS
CREATE TABLE RegistroCasos 
(
	IdCaso INT PRIMARY KEY IDENTITY (1,1) NOT NULL,
	PropietarioCaso INT FOREIGN KEY REFERENCES Usuarios (idUsuario) NOT NULL, --USUARIO QUE LO CREO-- 
	OrigenCaso INT FOREIGN KEY REFERENCES OrigenCaso(idOrigen),
	IdCueta INT FOREIGN KEY REFERENCES Clientes(CodigoCliente) NOT NULL,
	Asunto VARCHAR(256) NOT NULL,
	Direccion VARCHAR(256) DEFAULT 'Limon',
	Descripcion VARCHAR(256) DEFAULT 'Ninguna',
	Estado INT FOREIGN KEY REFERENCES EstadoCaso(IdEstado),
	TipoCaso INT FOREIGN KEY REFERENCES TipoCaso(idTipo),
	Prioridad INT FOREIGN KEY REFERENCES Prioridad(IdPrioridad), 
	Activo BIT DEFAULT 1,
	FechaCaso datetime default getdate()
);
GO

CREATE PROCEDURE AgregarRegistroCasos
	@PropietarioCaso INT,
	@OrigenCaso INT,
	@IdCueta INT,
	@Asunto VARCHAR(256),
	@Direccion VARCHAR(256),
	@Descripcion VARCHAR(256),
	@TipoCaso INT,
	@Prioridad INT
	AS
		BEGIN 
			INSERT INTO RegistroCasos (PropietarioCaso,OrigenCaso,IdCueta,Asunto,Direccion,Descripcion,TipoCaso
										,Prioridad)
								VALUES(@PropietarioCaso,@OrigenCaso,@IdCueta,@Asunto,@Direccion,@Descripcion,@TipoCaso
										,@Prioridad)
		END
GO
CREATE PROCEDURE EliminarRegistroCasos
	@IdCaso int
	AS
		BEGIN 
			UPDATE RegistroCasos SET Activo=0 WHERE IdCaso=@IdCaso ;
		END
GO
CREATE PROCEDURE ModificarRegistroCasos
	@IdCaso INT,
	@PropietarioCaso INT,
	@OrigenCaso INT,
	@IdCueta INT,
	@Asunto VARCHAR(256),
	@Direccion VARCHAR(256),
	@Descripcion VARCHAR(256),
	@TipoCaso INT,
	@Prioridad INT
	AS	
		BEGIN 
			UPDATE RegistroCasos SET PropietarioCaso=@PropietarioCaso,
									 OrigenCaso=@OrigenCaso,
									 IdCueta=@IdCueta,
									 Asunto=@Asunto,
									 Direccion=@Direccion,
									 TipoCaso=@TipoCaso,
									 Prioridad=@Prioridad
								WHERE IdCaso=@IdCaso;
		END 
GO


CREATE TABLE AsignarTareaCaso 
(
	idTarea int identity(1,1) primary key,
	idUsuario INT FOREIGN KEY REFERENCES Usuarios (idUsuario) NOT NULL,
	idCliente INT FOREIGN KEY REFERENCES RegistroCasos(idCaso) NOT NULL,
	DescripcionTarea VARCHAR(512) NOT NULL,	
	Estado bit default 1,
	FechaTarea datetime default getdate()
);
go
CREATE PROCEDURE AgregarAsignarTareaCaso
	@idUsuario INT,
	@idCaso INT,
	@DescripcionTarea VARCHAR(512)
	AS 
		BEGIN 
			INSERT INTO AsignarTareaCaso (idUsuario,idCaso,DescripcionTarea) VALUES(@idUsuario,@idCaso,@DescripcionTarea);
		END
GO 

CREATE PROCEDURE EliminarAsignarTareaCaso
	@idTarea int
	AS
		BEGIN	
			UPDATE AsignarTareaCaso SET Estado = 0 WHERE idTarea=@idTarea;
		END
GO
CREATE PROCEDURE ModificarAsignarTareaCaso
	@idTarea int,
	@DescripcionTarea VARCHAR(512)
	AS
		BEGIN 
			UPDATE AsignarTareaCaso SET DescripcionTarea=@DescripcionTarea  WHERE idTarea=@idTarea;
		END
GO

CREATE TABLE AsignarActividadCaso
(
	idActividad int identity(1,1) PRIMARY KEY,
	idUsuario INT FOREIGN KEY REFERENCES Usuarios (idUsuario) NOT NULL,
	idCliente INT FOREIGN KEY REFERENCES RegistroCasos(idCaso) NOT NULL,
	DescripcionActividad VARCHAR(512) NOT NULL,	
	Estado bit default 1,
);
GO
CREATE PROCEDURE AgregarAsignarActividadCaso
	@idUsuario INT,
	@idCliente INT,
	@DescripcionActividad VARCHAR(512)
	AS 
		BEGIN 
			INSERT INTO AsignarActividadCaso (idUsuario,idCliente,DescripcionActividad) VALUES(@idUsuario,@idCliente,@DescripcionActividad);
		END
GO 

CREATE PROCEDURE EliminarAsignarActividadCaso
	@idActividad int
	AS
		BEGIN	
			UPDATE AsignarActividadCaso SET Estado = 0 WHERE idActividad=@idActividad;
		END
GO
CREATE PROCEDURE ModificarAsignarActividadCaso
	@idActividad int,
	@DescripcionActividad VARCHAR(512)
	AS
		BEGIN 
			UPDATE AsignarActividadCaso SET DescripcionActividad=@DescripcionActividad  WHERE idActividad=@idActividad;
		END
GO









--###########################Vistas , Procedimientos, Consultas, Funciones (Tercera Parte CRM) #########################






CREATE VIEW FamiliaMasVendida --(1) NO REQUIERE GRAFICO -- ORDER BY DESC Y ASC
AS
	SELECT F.NombreFamilia AS [Nombre de la Familia],sum(P.Precio*PC.Cantidad) as [Monto Vendido]
	FROM Cotizaciones as C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion =C.NumeroCotizacion
		INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto 
		INNER JOIN FamiliaProducto AS F ON F.idFamilia = P.FamiliaPRoducto
		WHERE C.Etapa =0 AND C.Estado=1 AND F.Estado=1
		GROUP BY NombreFamilia
GO



CREATE VIEW ProductosMasVendidos --(2) NO REQUIERE GRAFICO -- ORDER BY DESC Y ASC
AS	
	SELECT TOP 10 P.NombreProducto as [Nombre de Producto],SUM(P.Precio*PC.Cantidad) AS [Monto Vendido]  
	FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion = C.NumeroCotizacion
		INNER JOIN Productos AS P ON PC.IdProducto = P.idProducto
		WHERE C.Etapa =0 AND C.Estado=1 AND P.Estado=1
		GROUP BY NombreProducto
GO



CREATE VIEW ProductosMasCotizados --(3) NO REQUIERE GRAFICO -- ORDER BY DESC Y ASC
AS
	SELECT TOP 10 P.NombreProducto as [Nombre del Producto],SUM(P.Precio*PC.Cantidad) AS [Monto Cotizado]  
	FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion = C.NumeroCotizacion
		INNER JOIN Productos AS P ON PC.IdProducto = P.idProducto
		WHERE C.Estado =1 AND P.Estado=1
		GROUP BY NombreProducto
GO




CREATE VIEW VentasPorSector --(4) REQUIERE GRAFICO Y DOS FUNCIONES PARA LOS FILTROS
AS
	SELECT S.NombreSector AS [Nombre del Sector],SUM(P.Precio*PC.Cantidad) AS [Monto Vendido]
	FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON C.NumeroCotizacion = PC.idCotizacion
		INNER JOIN Sectores AS S ON S.idSector = C.Sector 
		INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
		WHERE C.Etapa =0 AND C.Estado=1 AND C.Estado=1
		GROUP BY NombreSector
GO

CREATE FUNCTION FUN_VentasPorSectorMes (@año int,@mes int)
RETURNS TABLE
	RETURN ( SELECT S.NombreSector AS [Nombre del Sector],SUM(P.Precio*PC.Cantidad) AS [Monto Vendido]
			 FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON C.NumeroCotizacion = PC.idCotizacion
			 INNER JOIN Sectores AS S ON S.idSector = C.Sector 
			 INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
			 WHERE C.Etapa =0 AND c.Estado=1 AND S.Estado=1
			 AND YEAR(C.FechaCotizacion) = @año AND MONTH(C.FechaCotizacion)=@MES
			 GROUP BY NombreSector)		
GO


CREATE FUNCTION FUN_VentasPorSectorRango (@Fecha1 datetime,@Fecha2 datetime)
RETURNS TABLE
	RETURN ( SELECT S.NombreSector AS [Nombre del Sector],SUM(P.Precio*PC.Cantidad) AS [Monto Vendido]
			 FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON C.NumeroCotizacion = PC.idCotizacion
			 INNER JOIN Sectores AS S ON S.idSector = C.Sector 
			 INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
			 WHERE C.Etapa =0 and c.Estado=1 AND S.Estado=1
			 AND c.FechaCotizacion between @Fecha1 and @Fecha2
			 GROUP BY NombreSector)	
GO





CREATE VIEW VentasPorZona --(5) REQUIERE GRAFICO Y DOS FUNCIONES PARA LOS FILTROS
AS
	SELECT Z.NombreZona AS [Nombre de la Zona], SUM(P.Precio*PC.CANTIDAD) AS [Monto Vendido]
	FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion = C.NumeroCotizacion
		INNER JOIN Zonas AS Z ON Z.IdZona = C.Zona
		INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto 
		WHERE C.Etapa =0 and c.Estado=1 and Z.Estado=1
		GROUP BY NombreZona
GO

CREATE FUNCTION FUN_VentasPorZonaMes (@año int,@mes int)
RETURNS TABLE
	RETURN (SELECT Z.NombreZona AS [Nombre de la Zona], SUM(P.Precio*PC.CANTIDAD) AS [Monto Vendido]
			FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion = C.NumeroCotizacion
			INNER JOIN Zonas AS Z ON Z.IdZona = C.Zona
			INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto 
			WHERE C.Etapa =0 AND C.Estado=1 AND Z.Estado=1
			AND YEAR(C.FechaCotizacion) = @año AND MONTH(C.FechaCotizacion)=@mes
			GROUP BY NombreZona)
GO

CREATE FUNCTION FUN_VentasPorZonaRango (@Fecha1 datetime,@Fecha2 datetime)
RETURNS TABLE
	RETURN (SELECT Z.NombreZona AS [Nombre de la Zona], SUM(P.Precio*PC.CANTIDAD) AS [Monto Vendido]
			FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion = C.NumeroCotizacion
			INNER JOIN Zonas AS Z ON Z.IdZona = C.Zona
			INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto 
			WHERE C.Etapa =0 AND C.Estado=1 AND Z.Estado=1
			AND C.FechaCotizacion BETWEEN @Fecha1 AND @Fecha2
			GROUP BY NombreZona)
GO




CREATE VIEW ContizacionesYVentasPorDep --(6) --REQUIERE GRAFICO Y FILTRO POR MES Y RANGOS DE FECHAS
AS
	SELECT D.NombreDepartamento AS [Nombre del Departamento],
		(SELECT coalesce(SUM(P.Precio*Pc.cantidad),0) FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion=C.NumeroCotizacion
			INNER JOIN Departamentos AS DEP ON D.IdDepartamentos = C.Departamento
			INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
			WHERE DEP.IdDepartamentos = D.IdDepartamentos and c.Etapa=0 and c.Estado=1 ) as [Ventas Por Departamentos],
		(SELECT coalesce(SUM(P.Precio*Pc.cantidad),0) FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion=C.NumeroCotizacion
			INNER JOIN Departamentos AS DEP ON D.IdDepartamentos = C.Departamento
			INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
			WHERE DEP.IdDepartamentos = D.IdDepartamentos AND C.Estado=1) AS [Cotizaciones Por Departamento]
	FROM Departamentos AS D
	WHERE D.Estado=1
GO


CREATE FUNCTION FUN_ContizacionesYVentasPorDepMes (@año int,@mes int)
RETURNS TABLE
	AS
		RETURN (SELECT D.NombreDepartamento AS [Nombre del Departamento],
			(SELECT coalesce(SUM(P.Precio*Pc.cantidad),0) FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion=C.NumeroCotizacion
				INNER JOIN Departamentos AS DEP ON D.IdDepartamentos = C.Departamento
				INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
				WHERE DEP.IdDepartamentos = D.IdDepartamentos and c.Etapa=0 AND C.Estado=1
				AND YEAR(C.FechaCotizacion)=@año AND MONTH(C.FechaCotizacion) =@mes) as [Ventas Por Departamentos],
			(SELECT coalesce(SUM(P.Precio*Pc.cantidad),0) FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion=C.NumeroCotizacion
				INNER JOIN Departamentos AS DEP ON D.IdDepartamentos = C.Departamento
				INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
				WHERE DEP.IdDepartamentos = D.IdDepartamentos AND C.Estado=1 
				AND YEAR(C.FechaCotizacion)=@año AND MONTH(C.FechaCotizacion) =@mes ) AS [Cotizaciones Por Departamento]
			FROM Departamentos AS D
			WHERE D.Estado=1 )

GO

CREATE FUNCTION FUN_ContizacionesYVentasPorDepRango (@Fecha1 datetime,@Fecha2 datetime)
RETURNS TABLE
	AS
		RETURN (SELECT D.NombreDepartamento AS [Nombre del Departamento],
			(SELECT coalesce(SUM(P.Precio*Pc.cantidad),0) FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion=C.NumeroCotizacion
				INNER JOIN Departamentos AS DEP ON D.IdDepartamentos = C.Departamento
				INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
				WHERE DEP.IdDepartamentos = D.IdDepartamentos and c.Etapa=0 AND C.Estado=1
				AND C.FechaCotizacion BETWEEN @Fecha1 AND @Fecha2 ) as [Ventas Por Departamentos],
			(SELECT coalesce(SUM(P.Precio*Pc.cantidad),0) FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion=C.NumeroCotizacion
				INNER JOIN Departamentos AS DEP ON D.IdDepartamentos = C.Departamento
				INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
				WHERE DEP.IdDepartamentos = D.IdDepartamentos AND C.Estado=1
				AND C.FechaCotizacion  BETWEEN  @Fecha1 AND @Fecha2) AS [Cotizaciones Por Departamento]
			FROM Departamentos AS D
			WHERE D.Estado=1 )
GO



CREATE VIEW VentasPorDepartamento --(Porcentual) (7) REQUIERE FILTROS DE MES Y DE RANGOS DE FECHAS
	AS
		SELECT D.NombreDepartamento AS [Nombre del Departamento],
		COUNT(C.NumeroCotizacion)*100/(SELECT COUNT(C.NumeroCotizacion) FROM Cotizaciones AS C WHERE C.Etapa=0) AS [Porcentaje de Ventas Sobre 100]
		FROM Cotizaciones AS C INNER JOIN Departamentos AS D ON D.IdDepartamentos= C.Departamento
		WHERE C.Etapa =0 AND C.Estado=1 AND D.Estado=1
		GROUP BY NombreDepartamento 
GO

CREATE FUNCTION FUN_VentasPorDepartamentoMes (@año int,@mes int)
RETURNS TABLE
	RETURN (SELECT D.NombreDepartamento AS [Nombre del Departamento],
			COUNT(C.NumeroCotizacion)*100/(SELECT COUNT(C.NumeroCotizacion) FROM Cotizaciones AS C WHERE C.Etapa=0
			 AND YEAR(C.FechaCotizacion) = @año AND MONTH(C.FechaCotizacion)=@mes) AS [Porcentaje de Ventas Sobre 100]
			FROM Cotizaciones AS C INNER JOIN Departamentos AS D ON D.IdDepartamentos= C.Departamento
			WHERE C.Etapa =0 AND C.Estado=1 AND D.Estado=1
			AND YEAR(C.FechaCotizacion) = @año AND MONTH(C.FechaCotizacion)=@mes 
			GROUP BY NombreDepartamento )
GO


CREATE FUNCTION FUN_VentasPorDepartamentoRango (@Fecha1 datetime,@Fecha2 datetime)
RETURNS TABLE
	RETURN (SELECT D.NombreDepartamento AS [Nombre del Departamento],
			COUNT(C.NumeroCotizacion)*100/(SELECT COUNT(C.NumeroCotizacion) FROM Cotizaciones AS C WHERE C.Etapa=0
			AND C.FechaCotizacion BETWEEN @Fecha1 AND @Fecha2) AS [Porcentaje de Ventas Sobre 100]
			FROM Cotizaciones AS C INNER JOIN Departamentos AS D ON D.IdDepartamentos= C.Departamento
			WHERE C.Etapa =0 AND C.Estado=1 AND D.Estado=1
			AND C.FechaCotizacion BETWEEN @Fecha1 AND @Fecha2 
			GROUP BY NombreDepartamento )
GO




CREATE VIEW VentasCotizaciones --(8) NO REQUIERE FILTRO 
	AS
		SELECT CAST(YEAR(C.FechaCotizacion) AS varchar(20)) AS [Año],
		(SELECT SUM(P.Precio*PC.Cantidad) FROM Cotizaciones AS CT INNER JOIN ProductosPorCotizacion AS PC
				ON PC.idCotizacion = CT.NumeroCotizacion INNER JOIN Productos AS P ON P.idProducto=PC.IdProducto 
				WHERE YEAR(C.FechaCotizacion)=YEAR(CT.FechaCotizacion) AND CT.Estado=1) AS [Cotización Anual],
		(SELECT SUM(P.Precio*PC.Cantidad) FROM Cotizaciones AS CT INNER JOIN ProductosPorCotizacion AS PC
				ON PC.idCotizacion = CT.NumeroCotizacion INNER JOIN Productos AS P ON P.idProducto=PC.IdProducto 
				WHERE CT.Etapa=0 AND CT.Estado=1 AND YEAR(C.FechaCotizacion)=YEAR(CT.FechaCotizacion)) AS [Venta Anual]	
		FROM Cotizaciones AS C
		GROUP BY year(FechaCotizacion)
GO




CREATE VIEW ClientesConMayorVenta --(9) NO REQUIERE GRAFICO ORDER BY DESC ASC
AS
	SELECT TOP 10  CL.NombreCuenta AS[Nombre del Cliente],SUM(P.Precio*Pc.Cantidad) AS [Monto Comprado]
	FROM Clientes AS CL INNER JOIN Cotizaciones AS C ON C.idCuenta = CL.CodigoCliente 
		INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion =C.NumeroCotizacion
		INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
		WHERE C.Etapa =0 AND C.Estado=1 AND CL.Estado=1
	GROUP BY NombreCuenta
GO




CREATE VIEW CantidadContactosPorUsuario --(10) NO REQUIERE GRAFICO ORDER BY DESC ASC
AS
	SELECT U.NombreUsuario [Nombre del Usuario], COUNT(CC.NombreContacto) AS [Cantidad Contactos]
	FROM Usuarios AS U INNER JOIN ContactoCliente AS CC ON CC.Asesor = U.idUsuario
	WHERE CC.Estado=1 AND U.Estado=1
	GROUP BY NombreUsuario
	
GO




CREATE VIEW VendedoresConMayorVenta --(11) NO REQUIERE GRAFICO ORDER BY DESC ASC
AS
	SELECT TOP 10 U.NombreUsuario AS [Nombre del Vendedor],SUM(P.Precio*pc.Cantidad) AS [Monto Vendido]
	FROM Cotizaciones as C INNER JOIN Usuarios AS U ON U.idUsuario = C.Asesor 
		INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion = C.NumeroCotizacion
		INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
	WHERE U.Estado=1 AND C.Estado=1 AND C.Etapa=0
	GROUP BY U.NombreUsuario
GO






CREATE VIEW EjecucionesPorCierreDeMes --(12) REQUIERE FILTRO AÑO UNA FUNCION 
AS
	 SELECT  MONTH(PE.FechaCierre) AS [Numero Mes],DATENAME(MONTH,PE.FechaCierre) AS [Mes de Cierre], 
	 YEAR(PE.FechaCierre) as [Año Cierre],COUNT(PE.idProceso) as [Cantidad De Procesos]
	 FROM ProcesoEjecucion AS PE
	 WHERE YEAR(PE.FechaCierre) =2017 AND PE.Estado=1 
	 GROUP BY MONTH(PE.FechaCierre), DATENAME(MONTH,PE.FechaCierre),YEAR(PE.FechaCierre)
GO

CREATE FUNCTION FUN_EjecucionesPorCierreDeMesAño (@año int)
RETURNs TABLE
	RETURN (SELECT  MONTH(PE.FechaCierre) AS [Numero Mes],DATENAME(MONTH,PE.FechaCierre) AS [Mes de Cierre], 
	 YEAR(PE.FechaCierre) as [Año Cierre],COUNT(PE.idProceso) as [Cantidad De Procesos]
	 FROM ProcesoEjecucion AS PE
	 WHERE YEAR(PE.FechaCierre) =@año AND PE.Estado=1
	 GROUP BY MONTH(PE.FechaCierre), DATENAME(MONTH,PE.FechaCierre),YEAR(PE.FechaCierre))

GO




CREATE VIEW CasosPorEstado --(13) REQUIERE GRAFICO Y DOS FUNCIONES PARA LOS FILTROS MES(AÑO) Y RANGO
AS
	SELECT  EC.NombreEstado AS [Nombre de Estado],COUNT(RC.Asunto) AS [Cantidad de Estados]
  	FROM RegistroCasos AS RC INNER JOIN  EstadoCaso AS EC ON RC.Estado = EC.idEstado
	WHERE RC.Activo=1 AND EC.Estado=1
	GROUP BY EC.NombreEstado 

GO

 CREATE FUNCTION FUN_CasosPorEstadoMes (@año int,@mes int)
 RETURNS TABLE
	RETURN (
		SELECT  EC.NombreEstado AS [Nombre de Estado],COUNT(RC.Asunto) AS [Cantidad de Estados]
  		FROM RegistroCasos AS RC INNER JOIN  EstadoCaso AS EC ON RC.Estado = EC.idEstado
		WHERE year(FechaCaso) = @año and MONTH(FechaCaso) = @mes AND RC.Activo=1 AND EC.Estado=1
		GROUP BY EC.NombreEstado 
	)
GO


CREATE FUNCTION FUN_CasosPorEstadoRango(@fecha1 datetime,@fecha2 datetime)
RETURNS TABLE 
	RETURN 
	(
		SELECT  EC.NombreEstado AS [Nombre de Estado],COUNT(RC.Asunto) AS [Cantidad de Estados]
  		FROM RegistroCasos AS RC INNER JOIN  EstadoCaso AS EC ON RC.Estado = EC.idEstado
		WHERE FechaCaso BETWEEN @fecha1 AND @fecha2 AND RC.Activo=1 AND EC.Estado=1
		GROUP BY EC.NombreEstado
	)
GO



CREATE VIEW CotizacionesActividadYTareas --NO REQUIERE FILTRO ORDER BY ASC DESC 
AS
	SELECT CT.NumeroCotizacion AS [Numero Cotizacion] ,((SELECT COUNT(C.NumeroCotizacion) FROM Cotizaciones AS C INNER JOIN AsignarActividadCotizacion AS AAC
			ON AAC.IdCotizacion=C.NumeroCotizacion
			WHERE C.NumeroCotizacion = CT.NumeroCotizacion
			AND C.Estado=1 AND AAC.Estado=1)+(SELECT COUNT(C.NumeroCotizacion) FROM Cotizaciones AS C INNER JOIN AsignarTareaCotizacion AS ATC
			ON ATC.IdCotizacion=C.NumeroCotizacion
			WHERE C.NumeroCotizacion = CT.NumeroCotizacion
			AND C.Estado=1 AND ATC.Estado=1) ) AS [Suma Actividades y Tareas Registradas]
	FROM Cotizaciones AS CT
	WHERE CT.Estado=1
	GROUP BY CT.NumeroCotizacion

GO


CREATE VIEW ClientesYVentasPorZona --(15) NO REQUIERE GRAFICO ORDER BY DESC ASC
AS
	SELECT Z.NombreZona AS [Nombre de la Zona],(SELECT COUNT(C.NombreCuenta) 
		FROM Clientes AS C INNER JOIN Zonas AS ZN ON ZN.IdZona = C.Zona WHERE ZN.IdZona=Z.IdZona 
		AND C.Estado=1) AS [Cantidad Clientes Por Zona],
		(SELECT SUM(P.Precio*PC.Cantidad) FROM Cotizaciones AS C INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion=C.NumeroCotizacion
				INNER JOIN Productos AS P ON P.idProducto= PC.IdProducto
				INNER JOIN Zonas AS ZN ON Z.IdZona = C.Zona
				WHERE ZN.IdZona=Z.IdZona
				AND C.Estado=1 AND C.Etapa=0) AS [Monto Vendido Zona]
	FROM Zonas AS Z
	WHERE Z.Estado=1
	GROUP BY NombreZona,IdZona
GO 




--##PUNTOS OPCIONALES ##

CREATE VIEW CasosPorTipo -- REQUIERE GRAFICO Y DOS FUNCIONES PARA LOS FILTROS
AS
	SELECT TC.NombreTipo AS [Nombre de Tipo],COUNT(R.IdCaso) AS [Cantidad de Casos]
	FROM RegistroCasos AS R INNER JOIN TipoCaso AS TC ON TC.idTipo = R.TipoCaso
	WHERE TC.Estado=1 AND R.Activo=1
	GROUP BY NombreTipo
GO


CREATE FUNCTION FUN_CasosPorTipoMes (@año int, @mes int)
RETURNS TABLE
	RETURN 
	(
		SELECT TC.NombreTipo AS [Nombre de Tipo],COUNT(R.IdCaso) AS [Cantidad de Casos]
		FROM RegistroCasos AS R INNER JOIN TipoCaso AS TC ON TC.idTipo = R.TipoCaso
		WHERE YEAR(R.FechaCaso) = @año AND MONTH(R.FechaCaso)=@mes AND TC.Estado=1 AND R.Activo=1
		GROUP BY NombreTipo	
	)
GO


CREATE FUNCTION FUN_CasosPorTiporRango (@Fecha1 datetime,@fecha2 datetime)
RETURNS TABLE
RETURN 
	(
		SELECT TC.NombreTipo AS [Nombre de Tipo],COUNT(R.IdCaso) AS [Cantidad de Casos]
		FROM RegistroCasos AS R INNER JOIN TipoCaso AS TC ON TC.idTipo = R.TipoCaso
		WHERE R.FechaCaso BETWEEN @Fecha1 AND @fecha2 AND TC.Estado=1 AND R.Activo=1
		GROUP BY NombreTipo	
	)
GO


CREATE VIEW VentasPorSectorPorDepartamento
AS
	SELECT D.NombreDepartamento,S.NombreSector, SUM(P.Precio*PC.Cantidad) AS [Monto Ventido]
		FROM Cotizaciones AS C INNER JOIN Sectores AS S ON S.idSector = C.Sector 
		INNER JOIN Departamentos AS  D ON D.IdDepartamentos = C.Departamento 
		INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion = C.NumeroCotizacion
		INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
		WHERE C.Estado=1 AND C.Etapa=0 AND D.Estado=1 AND S.Estado=1
	GROUP BY D.NombreDepartamento,NombreSector
GO

CREATE VIEW VentasPorZonaPorDepartamento
AS
	SELECT D.NombreDepartamento,Z.NombreZona, SUM(P.Precio*PC.Cantidad) AS [Monto Ventido]
		FROM Cotizaciones AS C INNER JOIN Zonas AS Z ON Z.IdZona = C.Sector 
		INNER JOIN Departamentos AS  D ON D.IdDepartamentos = C.Departamento 
		INNER JOIN ProductosPorCotizacion AS PC ON PC.idCotizacion = C.NumeroCotizacion
		INNER JOIN Productos AS P ON P.idProducto = PC.IdProducto
		WHERE C.Estado=1 AND C.Etapa=1 AND D.Estado=1 AND Z.Estado=1
	GROUP BY D.NombreDepartamento,NombreZona

GO

CREATE VIEW CantidadEjecucionesUsuario
AS
SELECT U.NombreUsuario AS [Nombre de Usuario], COUNT(PE.idProceso) AS [Cantidad de Ejecuciones]
	FROM ProcesoEjecucion AS PE INNER JOIN Usuarios AS U ON U.idUsuario=PE.Asesor
	WHERE PE.Estado=1 AND U.Estado=1	
	GROUP BY NombreUsuario

GO


