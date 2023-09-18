Nome: Luiz Filipe Silveira Bido
Turma: M1

PROBLEMA 56

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Testes feitos: 
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]] BEM SUCEDIDO 

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]] BEM SUCEDIDO 

Input: intervals = [[1, 4], [0, 2], [3, 5], [6, 8]];
não funcionou

Complexidade:

Tempo: O(n^2) // se fosse com quick ou merge seria O(n log n)
Espaço: O(n)