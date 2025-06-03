# Game of Thrones - Battle Simulator

Este es un juego de simulación de batallas basado en la serie **Game of Thrones**, donde deberás gestionar recursos y tropas para defender **Targaryen** de los **White Walkers**.

---

## Requisitos previos

- Compilador C++ (`g++` para Linux, `MinGW` para Windows)
- CMake (versión 3.10 o superior)
- IDE (Visual Studio Code o CodeBlocks)

---

## Estructura del proyecto

*(Agregar la estructura del proyecto si es necesario)*

---

## Instalación y Configuración

### En Visual Studio Code

#### Linux

1. Instalar las dependencias necesarias.
2. Instalar extensiones en VSCode:
   - C/C++
   - CMake Tools
   - CMake
3. Clonar o descargar el repositorio.
4. Compilar y ejecutar.

#### Windows

1. Instalar:
   - MinGW
   - CMake
2. Agregar MinGW y CMake al `PATH` del sistema.
3. Instalar las mismas extensiones de VSCode mencionadas arriba.
4. Abrir el proyecto y compilar:
   - Presionar `Ctrl+Shift+P`
   - Escribir `"CMake: Configure"`
   - Seleccionar `"MinGW Makefiles"`
   - Presionar `Ctrl+Shift+B` para compilar

### En CodeBlocks

#### Linux

1. Instalar CodeBlocks.
2. Abrir CodeBlocks y crear un nuevo proyecto:
   - `File → New → Project`
   - `Console Application` → `C++`
   - Nombrar el proyecto y elegir ubicación
3. Agregar los archivos existentes al proyecto:
   - Click derecho en el proyecto → `Add files`
   - Agregar todos los `.cpp` y `.h`
4. Configurar el proyecto:
   - `Project → Build options`
   - `Search directories → Compiler → Add`
   - Seleccionar la carpeta del proyecto

#### Windows

1. Descargar e instalar CodeBlocks con MinGW.
2. Seguir los mismos pasos que en Linux para crear y configurar el proyecto.

---

## Ejecución del juego

### En VSCode

- Presionar `Ctrl+Shift+B` para compilar
- En la terminal integrada, ejecutar el binario generado

### En CodeBlocks

- Presionar `F9` para compilar y ejecutar  
- O usar el botón `"Build and run"` (ícono de engranaje con triángulo verde)

---

## Controles del juego

- Usar números (1-4) para seleccionar opciones en los menús
- `Enter` para confirmar selecciones
- Seguir las instrucciones en pantalla

---

## Mecánicas del juego

- Gestiona oro para comprar:
  - Soldados (unidades de combate)
  - Comida (necesaria para mantener soldados)
  - Mejoras de probabilidad de victoria
- Sobrevive **5 batallas consecutivas**
- Evita acumular **4 derrotas**
- Cada batalla consta de **10 rondas**

---

## Notas adicionales

- El juego utiliza `system("cls")` para limpiar la pantalla (funciona en Windows)
- En Linux, puedes necesitar cambiar `cls` por `clear` en el código
- El archivo `constants.h` contiene valores configurables del juego

---

## Solución de problemas comunes

### ❌ Error de CMake no encontrado:

- Verificar la instalación de CMake
- Comprobar variables de entorno `PATH`

### ❌ Error de compilador no encontrado:

- Verificar instalación de `g++` o `MinGW`
- Comprobar variables de entorno `PATH`

### ❌ Errores de includes:

- Verificar estructura de carpetas
- Comprobar rutas relativas en includes

### ❌ Pantalla no se limpia en Linux:

- Cambiar `system("cls")` por `system("clear")`
