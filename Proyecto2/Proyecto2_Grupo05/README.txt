Universidad Simón Bolívar
Inteligencia Artificial II 
Proyecto 2
GABIL

Juliana León		08-10608 
Stefano De Colli	09-10203	
Karen Troiano		09-10855
	    	         		          

Noviembre, 2014

Requerimientos:

	Se debe tener instalado:
		+ Python 2.6
		+ Liberia pyevolve-v0.5

Para compilar:

	python2.6 gabil.py [archivoEntrenamiento] [Seleccion] [Fitness] [TasaMutuacion] [TasaCruce] [archivoPrueba]
	 
	 Donde:
		Seleccion: 
			Si es 1 entonces selecciona el algoritmo de ruleta
			Si es 2 entonces selecciona el algotitmo que siempre elige al mejor de la poblacion.
		Fitness: 
			Si es 1 entonces selecciona el fitness estandar
			Si es 2 entonces selecciona el fitness que resntringe por tamano
		
		Valores validos para las tasas de cruce y mutacion:
			0.0 <= TasaMutuacion, TasaCruce <= 1.0


