# Texty

Uma linguagem compilada produzida durante a disciplina de Engenharia de Linguagem na UFRN.

## Instruções para execução

Atualmente o ambiente de execução só foi testado amplamente para linux, mais especificamente o ZorinOS, derivada do Ubuntu (24.04). Entretanto, testes também foram realizados no Windows.

Instale:
- make (4.3)
- g++ (13.3.0)
- flex (2.6.4)
- bison (3.8.2)
- graphviz (2.43.0)

### Build e execução

Execute o comando:
```cmd
make
```

Depois, se estiver no linux:
```cmd
chmod +x texty
```

Por fim:
```cmd
./texty --file code.txy
```

A extensão do arquivo tem que ser `.txy`.

### Gerando gráfico

Caso tenha instalado o `graphviz`, após o termino da execução você pode gerar a imagem da árvore sintática a partir do `.dot`gerado rodando o comando:
```cmd
dot -Tsvg code.dot -o code.svg
```

A imagem se encontrará disponível na raíz do projeto com o nome de [`ast.png`](/ast.png).

## Execução rápida de exemplos

Há uma pasta dedicada só para os exemplos chamada `/examples`.

Para compilar os grupos de teste você pode utilizar os seguintes comandos:
```cmd
make examples
make problems
make errors
```

Para rodar um teste específico você pode utilizar os seguintes comandos:
```cmd
make run-example 1
make run-problem 1
make run-error 1
```

Você pode substituir o '1' pelo número identificador de qualquer um dos testes.
