NOME: LUIZ FILIPE SILVEIRA BIDO

TURMA: M1

PROBLEMA 748. 

Shortest Completing Word

Given a string licensePlate and an array of strings words, find the shortest completing word in words.

A completing word is a word that contains all the letters in licensePlate. Ignore numbers and spaces in licensePlate, and treat letters as case insensitive. If a letter appears more than once in licensePlate, then it must appear in the word the same number of times or more.

For example, if licensePlate = "aBc 12c", then it contains letters 'a', 'b' (ignoring case), and 'c' twice. Possible completing words are "abccdef", "caaacab", and "cbca".

Return the shortest completing word in words. It is guaranteed an answer exists. If there are multiple shortest completing words, return the first one that occurs in words.

Tradução:

Palavra de conclusão mais curta

Dada uma string licensePlate e um array de strings words, encontre a menor palavra completa em words.

Uma palavra de conclusão é uma palavra que contém todas as letras em licensePlate. Ignore números e espaços em licensePlate e trate letras como maiúsculas e minúsculas. Se uma letra aparecer mais de uma vez em licensePlate, ela deverá aparecer na palavra o mesmo número de vezes ou mais.

Por exemplo, se licensePlate = "aBc 12c", ele contém as letras 'a', 'b' (ignorando maiúsculas e minúsculas) e 'c' duas vezes. As palavras possíveis para completar são "abccdef", "caaacab" e "cbca". ccba

Retorna a palavra completa mais curta em palavras. É garantido que existe uma resposta. Se houver várias palavras de conclusão mais curtas, retorne a primeira que ocorrer em palavras.

TESTES FEITOS SUCEDIDOS: 
Input: licensePlate = "aBc 12c", words = ["abccdef","caaacab","cbca"]

Input: licensePlate = "1s3 PSt", words = ["step","steps","stripe","stepple"]

Input: licensePlate = "1s3 456", words = ["looks","pest","stew","show"]
