# Texty — Analisador Léxico

Versão simplificada do analisador léxico da linguagem proposta.

## Instruções para execução

Atualmente o ambiente de execução só foi testado para linux, mais especificamente o ZorinOS, derivada do Ubuntu (24.04).

Instale:
- make (4.3)
- g++ (13.3.0)
- flex (2.6.4)

> Atenção: você pode precisar dar permissão de execução para o arquivo binário gerado.

Ao executar o comando abaixo a compilação será realizada e o binário será executado:
```cmd
make run
```

Se só quiser compilar:
```cmd
make
```

Foi deixado um arquivo `input.txy` cujo conteúdo pode ser usado como exemplo.

> Um exemplo de caractere que dá erro é o $.