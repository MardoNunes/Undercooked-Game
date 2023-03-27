# Undercooked-Game
![UndercookedGIF](https://user-images.githubusercontent.com/106790959/227815403-9f217838-4329-4eb9-b0ed-f0ac731e5beb.gif)
Um jogo semelhante ao "overcooked" implementado em C.
 Nele, você deve controlar o chapeiro pegando os ingredientes de acordo com a fila de pedidos e montar tais pedidos.
 
### Sobre
- |@| -> é o lugar onde deve ser entrege o pedido depois de montado.
- o -> é o lixo. Ao enconsta-lo é destruido toda a refeição!
- Condições de GameOver: Se ter 3 fails (entregar o pedido errado) e 5 lixos (destruir 5 refeições)
- Condição para Win: Entregar 10 pedidos.
- Movimentação: A movimentação do chapeiro é feito apenas com as teclas W, A, S e D.

### Clone o repositório
Será preciso ter previamente na máquina o GCC e o MAKE (normalmente encontrado nas distruibuições Linux)
```bash
    git clone https://github.com/MardoNunes/Undercooked-Game.git
```

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
