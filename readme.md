# Texty

Uma linguagem compilada produzida durante a disciplina de Engenharia de Linguagem na UFRN.

## Instruções para execução

Atualmente o ambiente de execução só foi testado para linux, mais especificamente o ZorinOS, derivada do Ubuntu (24.04).

Instale:
- make (4.3)
- g++ (13.3.0)
- flex (2.6.4)
- bison (3.8.2)

Opcionalmente:
- graphviz (2.43.0)

### Build

Execute o comando:
```cmd
make
```

Depois:
```cmd
make run
```

### Gerando gráfico

Caso tenha instalado o `graphviz`, após o termino da execução você pode gerar a imagem da árvore sintática rodando o comando:
```cmd
make ast
```

A imagem se encontrará disponível na raíz do projeto com o nome de [`ast.png`](/ast.png).
