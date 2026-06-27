# Texty

Uma linguagem compilada produzida durante a disciplina de Engenharia de Linguagem na UFRN.

## Instruções para execução

Instale:
- make (4.3)
- g++ (13.3.0)
- flex (2.6.4)
- bison (3.8.2)
- graphviz (2.43.0)

### Build e execução

Execute o comando na raíz do projeto:
```cmd
make
```

Depois, se estiver no linux precisará conceder permissão de execução:
```cmd
chmod +x texty
```

Por fim, basta executar o binário passando o caminho para o arquivo a ser compilado:
```cmd
./texty --file code.txy
```

A extensão do arquivo tem que ser `.txy`. 

### Gerando gráfico

Caso tenha instalado o `graphviz`, após o termino da execução você pode gerar a imagem da árvore sintática a partir do `.dot`gerado rodando o comando:
```cmd
dot -Tsvg code.dot -o code.svg
```

## Execução rápida de exemplos

Há uma pasta dedicada só para os exemplos localizada na raíz do projeto chamada `/examples`. Os exemplos também podem ser descritos como grupos de testes. Para compilar os grupos de teste você pode utilizar qualquer um dos seguintes comandos:

```cmd
make examples
make problems
make errors
```

Repare que cada um desses comandos é mapeado para uma das pastas dentro de `/examples`. O primeiro comando executa os exemplos básicos da linguagem (os primeiros a serem elaborados no processo de desenvolvimento do compilador). O segundo executa os exemplos que devem dar erros, sejam semânticos ou sintáticos (mas da linguagem). O terceiro é dedicado à solução dos problemas avaliativos. 

Para compilar e rodar um teste específico, ao invés de apenas compilar, você pode utilizar qualquer um dos seguintes comandos:

```cmd
make run-example 1
make run-problem 1
make run-error 1
```

Você pode substituir o `1` pelo número identificador de qualquer um dos testes dentro da respectiva pasta do grupo de testes.

# Limitações e recursos futuros

> Apenas para formalizar, então não espere por isso

* Atualmente o compilador está anexando todo o conteúdo da biblioteca padrão, mesmo o não utilizado. Futuramente a linguagem deve anexar (importar) somente o que é utilizado. Além disso, o ideal não seria uma anexação, mas uma separação em mais de um arquivo;
* A linguagem atualmente está permitindo variáveis constantes, mas elas não foram devidamente implementadas, sendo necessário terminar a implementação delas futuramente;
* A linguagem atualmente enfrenta uma escassez de operadores que devem ser implementados futuramente:
  * resize e push de array (atualmente é possível realizando concatenações);
  * round, min, max, e outros operadores numéricos;
  * etc.
* A linguagem atualmente não possuí implementação de características (traits) e implementações de características (impl), sendo um recurso muito desejado mas que infelizmente pode ser contemplado no momento. Sendo mais um recurso a ser implementado no futuro;
* Junto às características e implementações surgem outras pendências, como a do acesso estático à implementação não associada a uma estrutura de uma característica. A linguagem já não previa variáveis estáticas (uma decisão), mas previa acesso estático utilizando “::” às funções pertencentes a uma implementação como a descrita.

# Créditos

* ARTUR NOBRE DE QUEIROZ PEREIRA
* EUDES SILVA BEZERRA
* LUCAS MARCEL SILVA DE BRITO
* MARIA CLARA FERNANDES DE OLIVEIRA
* TIEGO RAFAEL BELO DA ROCHA
