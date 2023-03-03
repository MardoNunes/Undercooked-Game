# Undercooked-Game
Um jogo semelhante ao "overcooked" implementado em C.
 Nele, você deve controlar o chapeiro pegando os ingredientes de acordo com a fila de pedidos e montar tais pedidos.
 
### Sobre
- |@| -> é o lugar onde deve ser entrege o pedido depois de montado.
- o -> é o lixo. Ao enconsta-lo é destruido toda a refeição!
- Condições de GameOver: Se ter 3 fails (entregar o pedido errado) e 5 lixos (destruir 5 refeições)
- Condição para Win: Entregar 10 pedidos.
- Movimentação: A movimentação do chapeiro é feito apenas com as teclas W, A, S e D.

### Compilação
O repositório é acompanhado por um script Makefile. Para compilar é simples, basta dar o comando make no terminal no diretório em que se encontra o repositório!
```bash
    cd Undercooked-Game && make
```

#### Executando
Para executar o jogo:
```bash
    ./Undercooked
```
