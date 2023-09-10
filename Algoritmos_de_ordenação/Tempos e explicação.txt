n = 10, n = 100, n = 1000, n = 10 000, n = 100 000, n = 1 000 000 

Tempo medido em segundos.

n = 10
[Inserção: 0.000 ; Seleção: 0.000 ; Quick: 0.000 ; Merge: 0.000]

n = 100
[Inserção: 0.000 ; Seleção: 0.000 ; Quick: 0.000 ; Merge: 0.000]

n = 1000
[Inserção: 0.000 ; Seleção: 0.000 ; Quick: 0.000 ; Merge: 0.000]

n = 10000
[Inserção: 0.051 ; Seleção: 0.098 ; Quick: 0.000 ; Merge: 0.002]

n = 100000
[Inserção: 4.987 ; Seleção: 9.331 ; Quick: 0.007 ; Merge: 0.017]

n = 1000000
[Inserção: 537.537; Seleção: 1027.811 ; Quick: 0.112; Merge: 0.119]

Usei a biblioteca time com a função clock para calcular o tempo em segundos usando os clocks da CPU.
Deixei apenas o vscode rodando e fiz todos com a mesma quantidade. Tentei deixar o uso da CPU limitado apenas ao programa, fiz isso finalizando todas as tarefas que eu podia fechar.