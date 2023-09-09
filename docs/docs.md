# Calculadora 
Esta calculadora resuelve expresiones aritmeticas, los operadores aceptados son + - * / y (). Las expresiones consideran unicamente datos enteros positivos y negativos 

Entre las ventajas y desventajas de la resolución del problema Orientado a Objetos frente a Estructurada son:

|Ventajas | Desventajas|
|----------|-----------|
|Permite una mejor organización ya que en OO a una clase se le puede asignar métodos (funciones) y atributos (datos). De esta forma, a cada clase se le puede delegar una unica responsabilidad, lo cual permite mejorar la modularidad y cohesion del programa, permitiendo la reultilización de codigo a futuro, asi como una mejor mantenibilidad. |El proceso de abstración del problema normalmente es más complejo, ya que se debe entender el problema profundamente antes de crear cualquier clase, en caso contrario, la resolucion al problema será redundante o complicada, a comparación de Estructurada|


## Entrada / Salidas

|Entrada | Salida |
|---|---|
|`"6/2*(1+2)"`|9|
|`"1/2"`|0.5|
|`"(1+2)/0"`| "Error: division entre 0"|
|`"1++2"` |"Error: no se permite dos operadores seguidos ++"|
|`"1/(-2)+2"` |"Error: division entre 0"|
|`"-"` |"Error: no se puede iniciar con el operador -"|

## Proceso
1. Verifica que la cadena _expresión_ sea válida, que no contenga errores lexicos o sintacticos, si los contiene que termine la ejecución del programa
2. Convertir la cadena _expresión_ a posfija y guardarla en una nueva cadena _expresionPosfija_
3. Analizar la cadena _expresionPosfija_ y retornar el resultado en flotante

## Clases

Del proceso anterior extraemos tres clases principales:
- Verificador
- Conversor
- Analizador
- Postfix

``` mermaid
classDiagram
    class Verificador {
		+ esValido() bool $
		- errorLexico() bool$
		- errorSintax() bool$
	}
	class Conversor{
		+ convertirPosfija(string) deque(string)$
		- compararPresedencia(char, char) int$
		- verificarJerarquia(char) int$
		- esOperador(char) bool$
		- esParentesis(char) bool$
	}

	class Analizador{
		+ resolverPosfija(deque(string)) string$
	}

	class Postfix{
		-value : deque(string)
		+Postfix(string)
        +resolve() string
	}

Postfix  ..>  Conversor
Postfix  ..>  Analizador

```

### Verificador
Se encarga de verificar si la cadena contiene algun error léxico o sintactico


#### Métodos
|Tipo|Metodo y descr.|
|---|---|
|`static bool`|`esValido(string expresion)`<br>Devuelve si la cadena enviada es una expresion aritmética válida.|
|`static bool`|`errorLexico(string expresion)`<br>Detecta si la cadena enviada contiene algun error Léxico.|
|`static bool`|`errorSintax(string expresion)`<br>Verifica si la cadena contiene algún error sintáctico.|

### Conversor
Contiene utilerías necesarias para la conversión a postfija.

#### Métodos
|Tipo|Metodo y descr.|
|---|---|
|`static string`|`convertirPosfija(string expresion)`<br>Convierte la cadena aritmética de entrada a notación postfija en forma de deque.|
|`static int`|`compararPresedencia(char op1, char op2)`<br>Verifica la jerarquía aritmética del operador 1 con el operador 2, devuelve `>0` si c1 es mayor, `0` si son de igual jerarquía o `<0` si c1 es de menor jerarquía.|
|`static int`|`verificarJerarquia(char op)`<br>Devuelve la jerarquía aritmética del operador.|
|`static bool`|`esOperador(char c)`<br>Devuelve si el caracter enviado es un operador (`+ - * /`)|
|`static bool`|`esParentesis(char c)`<br>Devuelve si el carácter es un paréntesis `(` ó `)`|

### Analizador
Tiene utilerías para la conversión de postfija a su resultado concreto.

#### Métodos
|Tipo|Metodo y descr.|
|---|---|
|`static string`|`resolverPosfija(deque(string) expresion)`<br>Convierte el deque de entrada de notación postfija a el resultado aritmético que representa, devuelve una excepción en caso de encontrarse.|



### Postfix
Es un contenedor de la expresión postfija, la cual se puede inicializar y resolver con su método.

#### Atributos
* `deque(string) valor`<br>Es un deque que almacena los operadores y operandos de una expresión postfija en forma de cadenas. Ejemplo:<br>`(cadena original)"22+23" -> (deque(string))|"22"|"23"|+"|`

#### Métodos

|Tipo|Metodo y descr.|
|---|---|
|Constructor|`Postfix(string original)`<br>Inicializa la expresion postfija usando una expresion aritmetica.|
|`string`|`resolve()`<br>Devuele la expresion postfija resuelta o error si encuenta una división entre 0.|

