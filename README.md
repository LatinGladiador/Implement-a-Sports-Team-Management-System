# Soccer Team Management System

![Licencia MIT](https://img.shields.io/badge/licencia-MIT-blue.svg)
![Estado del Proyecto](https://img.shields.io/badge/estado-finalizado-green.svg)
![Versión](https://img.shields.io/badge/versión-1.0.0-brightgreen.svg)

Este es un proyecto en C para gestionar la información de un equipo de fútbol. El sistema permite agregar, eliminar, actualizar, buscar y mostrar jugadores del equipo. Los datos de los jugadores se gestionan a través de un archivo de entrada y los resultados se escriben en un archivo de salida.

## 📋 Descripción

El **Soccer Team Management System** maneja la información de los jugadores de un equipo de fútbol, incluyendo su identificación, nombre, posición, edad y goles. Utiliza funciones para validar datos, agregar y eliminar jugadores, actualizar información y buscar jugadores por ID.

## 🛠️ Tecnologías Utilizadas

- **C**: Lenguaje de programación utilizado para implementar la lógica del sistema.
- **Estructuras**: Para representar y gestionar la información de los jugadores.
- **Archivos**: Para la entrada y salida de datos.

## 🏗️ Instalación

Para ejecutar este proyecto en tu máquina local, sigue estos pasos:

1. **Clona el repositorio**:
   ```bash
   git clone https://github.com/LatinGladiador/Implement-a-Sports-Team-Management-System.git
   ```

2. **Navega al directorio del proyecto**:
   ```bash
   cd Implement-a-Sports-Team-Management-System
   ```

3. **Compila el archivo C**:
   ```bash
   gcc -o Implement-a-Sports-Team-Management-System Main.c
   ```

4. **Ejecuta el programa**:
   ```bash
   ./Implement-a-Sports-Team-Management-System
   ```

   Asegúrate de tener los archivos `input.txt` y `output.txt` en el directorio donde ejecutas el programa.

## 🖥️ Uso

1. **Prepara el archivo de entrada** `input.txt` con las operaciones deseadas (Add, Delete, Display, Search, Update) y sus parámetros.
2. **Ejecuta el programa**.
3. **Consulta el archivo de salida** `output.txt` para ver los resultados de las operaciones.

   Ejemplo de `input.txt`:
   ```
   Add 1 John Forward 25 10
   Display
   Search 1
   Update 1 John Midfielder 26 15
   Delete 1
   ```

   Ejemplo de `output.txt`:
   ```
   ID: 1, Name: John, Position: Forward, Age: 25, Goals: 10
   Found
   ```

## 🤝 Contribuciones

Las contribuciones son bienvenidas. Si deseas contribuir, sigue estos pasos:

1. **Haz un fork del repositorio**.
2. **Crea una nueva rama** para tus cambios:
   ```bash
   git checkout -b feature/nueva-caracteristica
   ```
3. **Realiza tus cambios y haz commit**:
   ```bash
   git commit -m "Añadida nueva característica"
   ```
4. **Empuja tu rama**:
   ```bash
   git push origin feature/nueva-caracteristica
   ```
5. **Abre un Pull Request** en GitHub.

## 👤 Autor

Este proyecto fue creado y es mantenido por [LatinGladiador](https://github.com/LatinGladiador).


## 📜 Licencia

Este proyecto está licenciado bajo la [Licencia MIT](LICENSE).

---

[![MIT License](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
