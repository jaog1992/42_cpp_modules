# CPP05 - Repetition and Exceptions

- Este directorio contiene las soluciones de los ejercicios del Módulo 05 (C++98): `ex00`..`ex03`.
- Todas las implementaciones siguen las restricciones del enunciado (`subject.md`): compilación con `-Wall -Wextra -Werror -std=c++98`, manejo de excepciones derivadas de `std::exception`, y diseño canónico cuando procede.

Contenido de los ejercicios:

- `ex00` - Bureaucrat
  - Implementa la clase `Bureaucrat` con un `name` constante y un `grade` entre 1 (máximo) y 150 (mínimo).
  - El constructor y las operaciones `incrementGrade`/`decrementGrade` lanzan `Bureaucrat::GradeTooHighException` o `Bureaucrat::GradeTooLowException` si el `grade` está fuera de rango.
  - Incluye `getName()`, `getGrade()` y la sobrecarga de `operator<<`.

- `ex01` - Form
  - Implementa la clase `Form` (no abstracta) con `name`, `signed` (bool), `signGrade` y `execGrade`.
  - Implementa `beSigned(Bureaucrat const &)` que firma el formulario si el `Bureaucrat` tiene el grade suficiente.
  - Define excepciones específicas para grades fuera de rango.

- `ex02` - AForm y formularios concretos
  - `AForm` es la clase abstracta base para formularios que añade la lógica de `execute(Bureaucrat const &)` y la verificación de firma/grade.
  - Implementa 3 formularios concretos:
    - `ShrubberyCreationForm` (sign 145 / exec 137): escribe un archivo `<target>_shrubbery` con ASCII-trees.
    - `RobotomyRequestForm` (sign 72 / exec 45): simula una robotización con éxito 50%.
    - `PresidentialPardonForm` (sign 25 / exec 5): imprime un mensaje de indulto.
  - `Bureaucrat` tiene helper `executeForm(AForm const &)` para intentar ejecutar formularios y manejar errores.

- `ex03` - Intern
  - Implementa `Intern` con `makeForm(name, target)` que crea dinámicamente un formulario concreto según `name` y devuelve un `AForm*`.
  - Usa un despachador (tabla de strings + punteros a funciones) para evitar if/else encadenados.
  - El llamador es responsable de `delete` del formulario devuelto.

Cómo compilar

- Cada ejercicio contiene su propio `Makefile` con las reglas estándar `all`, `clean`, `fclean` y `re`.
- Para compilar un ejercicio (por ejemplo `ex00`), abre una terminal en `cpp05/ex00` y ejecuta:

```sh
make
```

- Los `Makefile` están configurados para compilar con las banderas exigidas por el enunciado:

```
c++ -Wall -Wextra -Werror -std=c++98
```


Sobre `incs/`

- El directorio `incs/` contiene headers compartidos e inclusiones auxiliares (p. ej. `Colors.hpp`) usadas por los `main.cpp` para añadir color y formato a la salida durante tests.
- `incs/` no añade dependencias externas; es solo para organización de encabezados comunes.
