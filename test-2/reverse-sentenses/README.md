# Description
You are given an integer N, followed by N lines of input (1 <= N <= 100). Each line of input contains one or several words separated with single spaces. Each word is a sequence of letters of English alphabet containing between 1 and 10 characters, inclusive. The total number of words in the input is between 1 and 100, inclusive.

Your task is to reverse the order of words in each line of input, while preserving the words themselves. The lines of your output should not have any trailing or leading spaces.

Example

input
3
Hello World
Bye World
Useless World

output
World Hello
World Bye
World Useless

# Solución
- Leo la primera linea del archivo para saber cuantos tests va a haber.
-  Por cada test, leo una linea entera del archivo y lo guardo.
-  Itero sobre toda la lista para guardar dónde aparecen los espacios y también saber el número de palabras y la longitud del input.
- hago malloc para reservar el espacio necesario para guardar el resultado, la misma longitud que el input.
- Por cada palabra que hay en el input:
  + Calculo el indice inicio (el final de la palabra anterior más uno) y el indice final de cada palabra.
  + Calculo en índice que debería tener esta palabra en el resultado (longitud de la palabra menos el indice final de la palabra menos uno).
  + Copio caracter por caracter desde el indice inicial de la palabra hasta el indice final y lo pego las posiciones que calculé del resultado.
  + El último caracter que copié al resultado lo remplazo por ' ', por si este resulta ser un '\0'
  + antes de devolver el resultado el último caracter de este lo reemplazo por '\0' para asegurarme que el string termina aquí.
  + Imprimir el resultado.
