# Registro de testes | Operação Código Vermelho

## Equipe

Integrantes:
- Miguel Gomes dos Santos
- Matheus de Assis Faria
- Thiago Gontijo Mazotti

## Missão 01 | A cena do bug

| Trecho suspeito | Hipótese antes de executar | Alteração realizada | Evidência do teste |
|---|---|---|---|
| 1 | Atualização de string incorreta | Uso da função `strcpy` | `Titulo: Nebula: Edicao Final` |
| 2 | Alocação de valor em índice inválido | Troca do índice alocado | `Terceira avaliacao: 9.0` |
| 3 | Chamada incorreta de um atributo da struct `Jogo` | Troca de `jogo.id` para `jogo.codigo` | `Codigo: 201` |
| 4 | `jogo.avaliacoes[2]` está chamando a terceira avaliação | Alteração para `jogo.avaliacoes[1]` | `Segunda avaliacao: 9.5` |

## Missão 02 | Reconstrução

| Requisito | Teste executado | Resultado observado | Passou? |
|---|---|---|---|
| Listar 3 jogos | Uso de um `for` com limite até o índice 2 do vetor `catalogo` percorrendo todos os atributos requisitados | Apresentação de todos os atributos chamados | Sim |
| Atualizar Cripta | `catalogo[1].avaliacoes[1] = 9.5f;` e logo após, `printf("Segunda avaliação: %.1f\n", catalogo[1].avaliacoes[1]);` | A segunda avaliação apresentou o valor inserido corretamente, sem interferir em outros índices | Sim |
| Média de Nebula | `for(int cont = 0; cont < 3; cont++) {mediaNebula += catalogo[0].avaliacoes[cont];}` e depois `printf("=> Media de Nebula: %.1f\n\n", (mediaNebula/3));` | Saída de média de Nebula como 8 | Sim |

## Missão 03 | Código sabotado

| Defeito identificado | Por que prejudicava a lógica? | Teste usado para confirmar |
|---|---|---|
| `return 0;` em função `buscaPorCodigo`, faz busca de por código 999 resultar em 0 | Retorna um valor diferente pelo necessário para as verificações do caso, o correto seria -1 | Troca de `return 0;` por `return -1;` |
| Atualização da função `atualizarSegundaAvaliacao` é descartado em `main` | A função executa e retorna um valor, mas ao retornar à `main` o valor não é atribuído a nenhuma variável | Adição de `catalogo[posicao] =` para receber o valor atualizado |
| Operador relacional incorreto (`>`) para a capacidade do vetor `catalogo` | A condição só considera o vetor como cheio quando há 41 jogos ou mais inseridos, ignorando o caso de ter 40 jogos (vetor cheio) | Troca do operador relacional `>` por `>=` |
| Intervalo de busca da função `buscaPorCodigo` no laço `for` | A condição `i <= quantidade` faz com que o laço percorra índices não preenchidos do vetor | Alteração de `i <= quantidade` para `i < quantidade` |
| Troca de valores em índice incorreto na função `atualizarSegundaAvaliacao` | O uso de `jogo.avaliacoes[0]` para a atribuição da nova nota altera a primeira avaliação, não a segunda | Troca de índice para `jogo.avaliacoes[1]` |

## Encerramento

Durante o exercício, o terceiro caso abordado mostrou-se mais complexo e de difícil análise, justamente devido à erros que mascaravam uns aos outros, onde para solução dos mesmo, foram necessárias mudanças pontuais para a identificação e correção dos mesmos.