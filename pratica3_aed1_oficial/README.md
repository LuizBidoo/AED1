NOME: LUIZ FILIPE SILVEIRA BIDO

TURMA: M1

PROBLEMA 2335.

Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

TESTES FEITOS SUCEDIDOS: Input: root = [2,2,5,null,null,5,7] = 5 (bem sucedido)

Input: amount = [2,2,2] = -1 (bem sucedido)

Input: amount = [8,4,12,2,6,10,14] = 4 (bem sucedido)
