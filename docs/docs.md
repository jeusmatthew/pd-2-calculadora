
- Documentación (md) de las diferencias fundamentales de una implementación de OO vs Estructurada (ventajas o desventajas). **Es importante explicar las abstracciones y relaciones entre clases.** Mantener los principios de *modularidad*, _cohesión_ y responsabilidad única.


|Ventajas | Desventajas|
|----------|-----------|
||a|


# Algoritmo de la calc

## Entrada / Salidas

|Entrada | Salida |
|---|---|
|"6/2*(1+2)"|9|
|"1/2"|0.5|
|"(1+2)/0"| "Error: division entre 0"

## Proceso
1. Guarda la entrada del usuario en una cadena _expresión_
2. Verifica que la cadena _expresión_ sea válida, que no contenga errores lexicos o sintacticos, si los contiene que termine la ejecución del programa
3. Convertir la cadena _expresión_ a posfija y guardarla en una nueva cadena _expresionPosfija_
4. Analizar la cadena _expresionPosfija_ y retornar el resultado en flotante

De este proceso extraemos tres clases principales
- Verificador
- ConvertidorPosfija
- Analizador

``` mermaid
---
title: Diagrama UML
---

classDiagram
    class Verificador {
		+ esValido() bool
		- errorLexico() bool
		- errorSintax() bool
	}
	class Conversor{
		+ convertirPosfija(string) string
		- compararPresedencia(char, char) int
		- verificarJerarquia(char) int
		- esOperador(char) bool
		- esParentesis(char) bool
	}

	class Analizador{
		+ resolverPosfija(string) string
	}

    
```